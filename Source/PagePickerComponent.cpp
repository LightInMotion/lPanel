/*
    PagePickerComponent.cpp
 
    A simple page picker of TextButtons
*/

#include "PagePickerComponent.h"

//==============================================================================
PagePickerComponent::PagePickerComponent (int page_)
    : page (page_)
{
    for (int n=0 ; n < 24 ; n++)
    {
        TextButton* button = new TextButton();
        addAndMakeVisible (button);
        button->setButtonText (String (n + 1));
        button->setWantsKeyboardFocus (false);
        
        if (n == page)
        {
            button->setColour (TextButton::buttonColourId, Colours::lightblue);
        }
        else
        {
            button->setColour (TextButton::buttonColourId, Colours::blue);
            button->setColour (TextButton::textColourOffId, Colours::white);
        }
        button->addListener (this);
        buttons.add(button);
    }
}

PagePickerComponent::~PagePickerComponent()
{
}

//==============================================================================
void PagePickerComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0x50000000));
}

void PagePickerComponent::resized()
{
    int w = getWidth();
    int h = getHeight();
    
    // 3x8 or 6x4?
    int bwidth, bheight, cols;
    int hfudge, wfudge;

    if (w < h)
    {
        bwidth = (w - 16) / 3;
        bheight = (h - 16) / 8;
        cols = 3;
        
        wfudge = w - (bwidth * 3) - 16;
        wfudge >>= 1;
        
        hfudge = h - (bheight * 8) - 16;
        hfudge >>= 1;
    }
    else
    {
        bwidth = (w - 16) / 6;
        bheight = (h - 16) / 4;
        cols = 6;

        wfudge = w - (bwidth * 6) - 16;
        wfudge >>= 1;
        
        hfudge = h - (bheight * 4) - 16;
        hfudge >>= 1;
    }
    
    wfudge += 8;
    hfudge += 8;
    
    for (int n=0 ; n < 24 ; n++)
    {
        int row = n / cols;
        int col = n % cols;
        
        (buttons[n])->setBounds (col * bwidth + wfudge,
                                 row * bheight + hfudge,
                                 bwidth, bheight);
    }
}

//==============================================================================
void PagePickerComponent::buttonClicked (Button* buttonThatWasClicked)
{
    page = buttons.indexOf (dynamic_cast<TextButton*> (buttonThatWasClicked));
//    for (int n=0 ; n < 24 ; n++)
//        (buttons[n])->setEnabled (false);
    
    Component* parent = getParentComponent();
    parent->postCommandMessage (0x1234);
}

//==============================================================================
int PagePickerComponent::getPage()
{
    return page;
}

