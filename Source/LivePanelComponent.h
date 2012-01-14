/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  13 Jan 2012 6:22:16pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_LIVEPANELCOMPONENT_LIVEPANELCOMPONENT_FC2C7CFA__
#define __JUCER_HEADER_LIVEPANELCOMPONENT_LIVEPANELCOMPONENT_FC2C7CFA__

//[Headers]     -- You can add your own extra header files here --
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
                            public ButtonListener
{
public:
    //==============================================================================
    LivePanelComponent ();
    ~LivePanelComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
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


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
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


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    LivePanelComponent (const LivePanelComponent&);
    const LivePanelComponent& operator= (const LivePanelComponent&);
};


#endif   // __JUCER_HEADER_LIVEPANELCOMPONENT_LIVEPANELCOMPONENT_FC2C7CFA__
