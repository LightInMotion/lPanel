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
    // Status
    bool isConnected();
    
    // Grand Master
    bool setGM (int value);
    bool fadeGM (int speed);
    
    // Direction
    bool activeForward();
    bool activeReverse();
    bool activeBally();
    bool activeStop();
    bool activeStep();
    bool activeTap();
    
    bool doRecall (int recall);
    
    //==============================================================================
    void run();
    
private:
    //==============================================================================    
    bool sendCommand (uint8 cmd, uint16 val=0, uint16 param=0);
    int lookupTime (int speed);

    //==============================================================================    
    CriticalSection criticalSection;    // To protect what follows
    ScopedPointer<IpAddress> serverAddress;
    uint16 serverPort;
    ScopedPointer<StreamingSocket> serverSocket;
};

#endif  // __LPNET_H_A420911B__
