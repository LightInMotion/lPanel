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
      serverSocket (0)
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
    if (serverSocket != nullptr)
        return true;
    return false;
}

void LpNet::disconnect()
{
    const ScopedLock lock (criticalSection);
    serverSocket = nullptr;
}


//==============================================================================
bool LpNet::getByte (uint8* b)
{
    const ScopedLock lock (criticalSection);
    if (serverSocket == nullptr)
        return false;
    
    if (! serverSocket->waitUntilReady (true, 1000) ||
        serverSocket->read (b, 1, true) != 1)
    {
        serverSocket = nullptr;
        startThread();
        return false;
    }
    
    return true;
}

bool LpNet::getShort (uint16* s)
{
    uint8 b;
    uint16 u;
    
    if (! getByte (&b))
        return false;
    u = b;
    u <<= 8;
    
    if (! getByte (&b))
        return false;
    u += b;
    *s = u;
    return true;
}

bool LpNet::sendCommand (uint8 cmd, uint16 val, uint16 param)
{
    const ScopedLock lock (criticalSection);
    if (serverSocket == nullptr)
        return false;
        
    U8 packet[6];
    packet[0] = 0xFF;
    packet[1] = cmd;
    packet[2] = (uint8)((val >> 7) & 0x7F);
    packet[3] = (uint8)(val & 0x7F);
    packet[4] = (uint8)((param >> 7) & 0x7F);
    packet[5] = (uint8)(param & 0x7F);
    
    if (serverSocket->write (packet, sizeof (packet)) < 0)
    {
        serverSocket = nullptr;
        startThread();
        return false;
    }
    
    return true;
}

int LpNet::lookupTime (int speed)
{
    int tm;
    
    switch (abs (speed))
    {
        case 1:
            tm = LP_1SEC;
            break;
        case 2:
            tm = LP_2SEC;
            break;
        default:
            tm = LP_3SEC;
            break;
    };
    
    if (speed < 0)
        tm = 0 - tm;
        
    return tm;
}

//==============================================================================
// GM
bool LpNet::setGM (int value)
{
    return sendCommand (LPCMD_GM, value);
}

bool LpNet::fadeGM (int speed)
{
    return sendCommand (LPCMD_GM_FADE, lookupTime (speed));
}

//==============================================================================
// Direction
bool LpNet::activeForward()
{
    return sendCommand (LPCMD_DIR, LP_CHASER_ACTIVE, LP_FORWARD);
}

bool LpNet::activeReverse()
{
    return sendCommand (LPCMD_DIR, LP_CHASER_ACTIVE, LP_REVERSE);    
}

bool LpNet::activeBally()
{
    return sendCommand (LPCMD_DIR, LP_CHASER_ACTIVE, LP_BALLY);    
}

bool LpNet::activeStop()
{
    return sendCommand (LPCMD_DIR, LP_CHASER_ACTIVE, LP_STOP);        
}

bool LpNet::activeStep()
{
    return sendCommand (LPCMD_DIR, LP_CHASER_ACTIVE, LP_STEP);    
}

//==============================================================================
// Tap
bool LpNet::activeTap()
{
    return sendCommand (LPCMD_TAP, LP_CHASER_ACTIVE);        
}

//==============================================================================
// Recall
bool LpNet::doRecall (int recall)
{
    return sendCommand (LPCMD_RECALL, recall);
}

bool LpNet::getRecall (int recall, RecallInfo& info)
{
    if (! sendCommand (LPCMD_RECALL_GET, recall))
        return false;
    
    uint8 b;
    
    if (! getByte (&b))
        return false;
    
    if (b != LPCMD_RECALL_GET)
    {
        // We're out of sync, drop the connection
        disconnect();
        return false;
    }

    if (! getByte (&b))
        return false;
    
    if (b)
        info.isActive = true;
    else
        info.isActive = false;
    
    if (info.name.length())
        info.name = String::empty;
    
    while (1)
    {
        if (! getByte (&b))
            return false;
        
        if (! b)
            break;
        
        info.name << (char)b;
    }
    
    return true;    
}

//==============================================================================
// Page
bool LpNet::setPage (int page)
{
    return sendCommand (LPCMD_PAGE, page);
}

bool LpNet::getPage (int* page)
{
    if (! sendCommand (LPCMD_PAGE_GET))
        return false;
    
    uint8 b;
    if (! getByte (&b))
        return false;
    
    if (b != LPCMD_PAGE_GET)
    {
        // Out of sync!
        disconnect();
        return false;
    }
    
    uint16 u;
    if (! getShort (&u))
        return false;
    
    *page = u;
    return true;
}

//==============================================================================
// Discovery Thread
void LpNet::run()
{
    while (! threadShouldExit())
    {
        sleep (500);

        Array<IpAddress> ips;        
        IpAddress::findAllIpAddresses (ips);
        
        for (int n=0 ; n<ips.size() ; n++)
        {
            if (threadShouldExit())
                return;
            
            DatagramSocket s (Socket::anyPort, true, true, ips[n]);
            if (s.connect (IpAddress::broadcast, LPNET_DISCOVERY))
            {
                LPNET_POLL outblock;
                memset (&outblock, 0, sizeof (outblock));
                strcpy ((char *)outblock.ProtoID, LPNET_PROTO_ID);
                outblock.OpCode = Socket::HostToNetworkUint16 (LPNET_OPCODE_POLL);
                outblock.VersionL = LPNET_VERSION;
                
#if JUCE_IOS
                // The iOS stack doen't properly bind without sending to ourselves
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
                                        if (! (Socket::HostToNetworkUint16 (reply->Flags) &
                                               LPNET_FLAG_INUSE))
                                        {
                                            const ScopedLock lock (criticalSection);
                                            serverAddress = new IpAddress 
                                                (Socket::NetworkToHostUint32 (reply->Address));
                                            serverPort = Socket::NetworkToHostUint16 (reply->Port);
                                            serverSocket = new StreamingSocket();
                                            if (serverSocket->connect (serverAddress->toString(), 
                                                                   serverPort))
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