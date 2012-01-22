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
    void disconnect();
    
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
    
    typedef struct {
        bool isActive;
        String name;
    } RecallInfo;
    
    bool doRecall (int recall);
    bool getRecall (int recall, RecallInfo& info);
    
    // Page
    bool setPage (int page);
    bool getPage (int* page);
    
    //==============================================================================
    void run();
    
private:
    //==============================================================================    
    bool sendCommand (uint8 cmd, uint16 val=0, uint16 param=0);
    int lookupTime (int speed);
    bool getByte (uint8* b);
    bool getShort (uint16* s);

    //==============================================================================    
    CriticalSection criticalSection;    // To protect what follows
    ScopedPointer<IpAddress> serverAddress;
    uint16 serverPort;
    ScopedPointer<StreamingSocket> serverSocket;
};

#endif  // __LPNET_H_A420911B__
