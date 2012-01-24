/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic outline for a simple desktop window.

  ==============================================================================
*/

#include "lp-net.h"
#include "LivePanelComponent.h"
#include "MainWindow.h"


//==============================================================================
class ContentComp : public Component
{
public:
    
    ContentComp()
    {
        LivePanelComponent* view = new LivePanelComponent (&lpNet);
        showView (view);
    }
    
    ~ContentComp()
    {
    }
    
    void suspend()
    {
        lpNet.disconnect();
    }
    
    void resume()
    {
        lpNet.connect();
    }
    
    //==============================================================================
    void resized()
    {
        currentView->setBounds (0, 0, getWidth(), getHeight());
    }
    
    //==============================================================================
    void showView (Component* viewComp)
    {
        currentView = viewComp;
        addAndMakeVisible (currentView);
        resized();
    }

private:
    ScopedPointer<Component> currentView;
    LpNet lpNet;
};

//==============================================================================
MainAppWindow::MainAppWindow()
    : DocumentWindow (JUCEApplication::getInstance()->getApplicationName(),
                      Colours::black,
                      DocumentWindow::allButtons)
{    
    #if JUCE_ANDROID || JUCE_IOS
        setTitleBarHeight (0);
        setFullScreen (true);
    #else 
        setResizable (true, false); // resizability is a property of ResizableWindow
        setResizeLimits (100, 100, 8192, 8192);
        centreWithSize (320, 480);
    #endif

    ContentComp* contentComp = new ContentComp();
    setContentOwned(contentComp, false);
    
    setVisible (true);
}

MainAppWindow::~MainAppWindow()
{
    clearContentComponent();
}

void MainAppWindow::suspend()
{
    ContentComp* contentComp = dynamic_cast<ContentComp*> (getContentComponent());
    contentComp->suspend();
}

void MainAppWindow::resume()
{
    ContentComp* contentComp = dynamic_cast<ContentComp*> (getContentComponent());
    contentComp->resume();    
}

void MainAppWindow::closeButtonPressed()
{
    JUCEApplication::getInstance()->systemRequestedQuit();
}
