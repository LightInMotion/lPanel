/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic outline for a simple desktop window.

  ==============================================================================
*/

#include "LivePanelComponent.h"
#include "LivePanelHComponent.h"
#include "MainWindow.h"


//==============================================================================
class ContentComp : public Component
{
public:
    
    ContentComp()
        : orientation (-1)
    {
    }
    
    ~ContentComp()
    {
    }
    
    //==============================================================================
    void resized()
    {
        if (getWidth() > getHeight())
        {
            if (orientation != 2)
            {
                orientation = 2;
                currentView = new LivePanelHComponent();
                addAndMakeVisible (currentView);
            }
        }
        else
        {
            if (orientation != 1)
            {
                orientation = 1;
                currentView = new LivePanelComponent();
                addAndMakeVisible (currentView);
            }
        }
        
        if (currentView != 0)
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
    int orientation;
    ScopedPointer<Component> currentView;
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

void MainAppWindow::closeButtonPressed()
{
    JUCEApplication::getInstance()->systemRequestedQuit();
}
