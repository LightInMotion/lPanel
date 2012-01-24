/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  23 Jan 2012 12:54:38pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_ABOUTCOMPONENT_ABOUTCOMPONENT_EB6D18A__
#define __JUCER_HEADER_ABOUTCOMPONENT_ABOUTCOMPONENT_EB6D18A__

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
class AboutComponent  : public Component,
                        public ButtonListener
{
public:
    //==============================================================================
    AboutComponent ();
    ~AboutComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);

    // Binary resources:
    static const char* logosmall_2x_png;
    static const int logosmall_2x_pngSize;


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    Label* nameLabel;
    Label* infoLabel;
    TextButton* textButton;
    HyperlinkButton* hyperlinkButton;
    Image cachedImage_logosmall_2x_png;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    AboutComponent (const AboutComponent&);
    const AboutComponent& operator= (const AboutComponent&);
};


#endif   // __JUCER_HEADER_ABOUTCOMPONENT_ABOUTCOMPONENT_EB6D18A__
