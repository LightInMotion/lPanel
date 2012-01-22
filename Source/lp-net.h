/*
    lp-net.h
 
    Simple class for interacting with LivePanel API
*/

#ifndef __LPNET_H_A420911B__
#define __LPNET_H_A420911B__

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
class LpNet : public Thread
{
public:
    //==============================================================================
    LpNet();
    ~LpNet();

    //==============================================================================
    bool isConnected();
    
    //==============================================================================
    void run();
    
private:
    CriticalSection criticalSection;    // To protect what follows
    ScopedPointer<IpAddress> serverAddress;
    uint16 serverPort;
    ScopedPointer<StreamingSocket> serverSocket;
    bool connected;
};

#endif  // __LPNET_H_A420911B__
