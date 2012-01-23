/*
    PagePickerComponent.h

    A simple page picker of TextButtons
*/

#ifndef __PAGEPICKERCOMPONENT_H_DDFF6E2D__
#define __PAGEPICKERCOMPONENT_H_DDFF6E2D__

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
class PagePickerComponent : public Component,
                            public ButtonListener
{
public:
    //==============================================================================
    PagePickerComponent (int page);
    ~PagePickerComponent();
    
    //==============================================================================
    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);

    //==============================================================================
    int getPage();
    
private:
    //==============================================================================
    int page;
    OwnedArray<TextButton> buttons;
};



#endif  // __PAGEPICKERCOMPONENT_H_DDFF6E2D__
