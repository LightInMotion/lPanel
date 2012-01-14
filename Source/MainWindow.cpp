/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic outline for a simple desktop window.

  ==============================================================================
*/

#include "LivePanelComponent.h"
#include "MainWindow.h"


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

    LivePanelComponent* livePanelComponent = new LivePanelComponent();
    setContentOwned(livePanelComponent, false);
    
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
