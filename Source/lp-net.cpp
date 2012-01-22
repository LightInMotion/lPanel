/*
    lp-net.cpp
 
    Simple class for interacting with LivePanel API
*/

#include "LPNet.h"
#include "lp-net.h"

//==============================================================================
LpNet::LpNet()
    : Thread ("LP Net Thread"),
      serverAddress (0),
      serverSocket (0),
      connected (false)
{
    startThread();
}

LpNet::~LpNet()
{
    stopThread (-1);
}


//==============================================================================
bool LpNet::isConnected()
{
    const ScopedLock lock (criticalSection);
    return connected;
}

//==============================================================================
void LpNet::run()
{
    while (!threadShouldExit())
    {
        Array<IpAddress> ips;        
        IpAddress::findAllIpAddresses (ips);
        
        for (int n=0 ; n<ips.size() ; n++)
        {
            DatagramSocket s (Socket::anyPort, true, true, ips[n]);
            if (s.connect (IpAddress::broadcast, LPNET_DISCOVERY))
            {
                LPNET_POLL outblock;
                memset (&outblock, 0, sizeof (outblock));
                strcpy ((char *)outblock.ProtoID, LPNET_PROTO_ID);
                outblock.OpCode = Socket::HostToNetworkUint16 (LPNET_OPCODE_POLL);
                outblock.VersionL = LPNET_VERSION;
                
#if JUCE_IOS
                s.connect (ips[n], LPNET_DISCOVERY);
                s.write (&outblock, sizeof (LPNET_POLL));
                s.connect (IpAddress::broadcast, LPNET_DISCOVERY);
#endif
                if (s.write (&outblock, sizeof (LPNET_POLL)) > 0)
                {
                    while (s.waitUntilReady (true, 250))
                    {
                        char inbuf[1024];
                        
                        int n = s.read (&inbuf, sizeof (inbuf), false);
                        if (n > 0)
                        {
                            LPNET_POLLREPLY *reply;
                            reply = (LPNET_POLLREPLY *)inbuf;
                            if (!strcmp((char *)reply->ProtoID, LPNET_PROTO_ID))
                            {
                                if (reply->OpCode == Socket::HostToNetworkUint16(LPNET_OPCODE_POLLREPLY))
                                {                                        
                                    if (reply->VersionL == LPNET_VERSION)
                                    {
                                        if (! (reply->Flags & LPNET_FLAG_INUSE))
                                        {
                                            const ScopedLock lock (criticalSection);
                                            serverAddress = new IpAddress 
                                                (Socket::NetworkToHostUint32 (reply->Address));
                                            serverPort = Socket::NetworkToHostUint16 (reply->Port);
                                            serverSocket = new StreamingSocket();
                                            if (serverSocket->connect (serverAddress->toString(), 
                                                                   serverPort))
                                            {
                                                connected = true;
                                                return;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}