/*
    Combined from two jucer files, V and H
    Don't edit this combined view file directly with the Jucer!
*/

#ifndef __JUCER_HEADER_LIVEPANELCOMPONENT_LIVEPANELCOMPONENT_D00C81FE__
#define __JUCER_HEADER_LIVEPANELCOMPONENT_LIVEPANELCOMPONENT_D00C81FE__

//[Headers]     -- You can add your own extra header files here --
#include "lp-net.h"
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class LivePanelComponent  : public Component,
                            public ButtonListener,
                            public Timer
{
public:
    //==============================================================================
    LivePanelComponent ();
    ~LivePanelComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void updatePage();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void handleCommandMessage (int commandId);

    // Binary resources:
    static const char* stop_2x_png;
    static const int stop_2x_pngSize;
    static const char* tap_2x_png;
    static const int tap_2x_pngSize;
    static const char* step_2x_png;
    static const int step_2x_pngSize;
    static const char* forward_2x_png;
    static const int forward_2x_pngSize;
    static const char* reverse_2x_png;
    static const int reverse_2x_pngSize;
    static const char* bally_2x_png;
    static const int bally_2x_pngSize;
    static const char* gmfullOn_2x_png;
    static const int gmfullOn_2x_pngSize;
    static const char* gmfadeOn_2x_png;
    static const int gmfadeOn_2x_pngSize;
    static const char* gmfadeOff_2x_png;
    static const int gmfadeOff_2x_pngSize;
    static const char* gmfullOff_2x_png;
    static const int gmfullOff_2x_pngSize;
    static const char* sequence_inactive_png;
    static const int sequence_inactive_pngSize;
    static const char* smallButton_2x_png;
    static const int smallButton_2x_pngSize;
    static const char* sequence_inactive_2x_png;
    static const int sequence_inactive_2x_pngSize;
    static const char* info_2x_png;
    static const int info_2x_pngSize;

    //==============================================================================
    void timerCallback();
    
    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    LpNet lpNet;        // A network helper
    bool lastState;     // For connection update
    int pageOffset;       // What part of the page are we showing?

    Array<ImageButton*> buttons;    // Easier to deal with recall buts as array
    OwnedArray<Label> labels;       // We'll allocate labels and move to match
    //[/UserVariables]

    //==============================================================================
    ImageButton* stopButton;
    ImageButton* tapButton;
    ImageButton* stepButton;
    ImageButton* forwardButton;
    ImageButton* reverseButton;
    ImageButton* ballyButton;
    ImageButton* gmFullOnButton;
    ImageButton* gmFadeOnButton;
    ImageButton* gmFadeOffButton;
    ImageButton* gmFullOffButton;
    Label* gmLabel;
    ImageButton* recallButton1;
    ImageButton* recallButton2;
    ImageButton* recallButton3;
    ImageButton* recallButton4;
    ImageButton* recallButton5;
    ImageButton* recallButton6;
    ImageButton* recallButton7;
    ImageButton* recallButton8;
    ImageButton* recallButton9;
    ImageButton* recallButton10;
    ImageButton* recallButton11;
    ImageButton* recallButton12;
    ImageButton* funcButton;
    Label* funcLabel;
    Label* connectLabel;
    ImageButton* pageButton;
    Label* pageLabel;
    ImageButton* infoButton;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    LivePanelComponent (const LivePanelComponent&);
    const LivePanelComponent& operator= (const LivePanelComponent&);
};


#endif   // __JUCER_HEADER_LIVEPANELCOMPONENT_LIVEPANELCOMPONENT_D00C81FE__
