/*
    Our View
 
    Combined from H and V jucer files
    Don't edit this file directly in the jucer
*/

#include "lp-net.h"
#include "PagePickerComponent.h"
#include "AboutComponent.h"
#include "LivePanelComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
LivePanelComponent::LivePanelComponent (LpNet *lpNet_)
    : lpNet (lpNet_),
      lastState (false),
      pageOffset (0),
      lastPage (-1),
      timerDivider (0),
      bigDisplay (false),
      overlay (0),
      stopButton (0),
      tapButton (0),
      stepButton (0),
      forwardButton (0),
      reverseButton (0),
      ballyButton (0),
      gmFullOnButton (0),
      gmFadeOnButton (0),
      gmFadeOffButton (0),
      gmFullOffButton (0),
      gmLabel (0),
      recallButton1 (0),
      recallButton2 (0),
      recallButton3 (0),
      recallButton4 (0),
      recallButton5 (0),
      recallButton6 (0),
      recallButton7 (0),
      recallButton8 (0),
      recallButton9 (0),
      recallButton10 (0),
      recallButton11 (0),
      recallButton12 (0),
      recallButton13 (0),
      recallButton14 (0),
      recallButton15 (0),
      recallButton16 (0),
      recallButton17 (0),
      recallButton18 (0),
      recallButton19 (0),
      recallButton20 (0),
      recallButton21 (0),
      recallButton22 (0),
      recallButton23 (0),
      recallButton24 (0),
      recallButton25 (0),
      recallButton26 (0),
      recallButton27 (0),
      recallButton28 (0),
      recallButton29 (0),
      recallButton30 (0),
      recallButton31 (0),
      recallButton32 (0),
      recallButton33 (0),
      recallButton34 (0),
      recallButton35 (0),
      recallButton36 (0),
      recallButton37 (0),
      recallButton38 (0),
      recallButton39 (0),
      recallButton40 (0),
      recallButton41 (0),
      recallButton42 (0),
      recallButton43 (0),
      recallButton44 (0),
      recallButton45 (0),
      recallButton46 (0),
      recallButton47 (0),
      recallButton48 (0),
      funcButton (0),
      funcLabel (0),
      connectLabel (0),
      pageButton (0),
      pageLabel (0),
      infoButton (0),
      cachedImage_smallLogo_png (0)
{
    addAndMakeVisible (stopButton = new ImageButton (L"stop button"));
    stopButton->setButtonText (L"new button");
    stopButton->addListener (this);

    stopButton->setImages (false, true, false,
                           ImageCache::getFromMemory (stop_2x_png, stop_2x_pngSize), 1.0000f, Colour (0x0),
                           Image(), 1.0000f, Colour (0x0),
                           Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (tapButton = new ImageButton (L"tap button"));
    tapButton->setButtonText (L"new button");
    tapButton->addListener (this);

    tapButton->setImages (false, true, false,
                          ImageCache::getFromMemory (tap_2x_png, tap_2x_pngSize), 1.0000f, Colour (0x0),
                          Image(), 1.0000f, Colour (0x0),
                          Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (stepButton = new ImageButton (L"step button"));
    stepButton->setButtonText (L"new button");
    stepButton->addListener (this);

    stepButton->setImages (false, true, false,
                           ImageCache::getFromMemory (step_2x_png, step_2x_pngSize), 1.0000f, Colour (0x0),
                           Image(), 1.0000f, Colour (0x0),
                           Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (forwardButton = new ImageButton (L"forward button"));
    forwardButton->setButtonText (L"new button");
    forwardButton->addListener (this);

    forwardButton->setImages (false, true, false,
                              ImageCache::getFromMemory (forward_2x_png, forward_2x_pngSize), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (reverseButton = new ImageButton (L"reverse button"));
    reverseButton->setButtonText (L"new button");
    reverseButton->addListener (this);

    reverseButton->setImages (false, true, false,
                              ImageCache::getFromMemory (reverse_2x_png, reverse_2x_pngSize), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (ballyButton = new ImageButton (L"bally button"));
    ballyButton->setButtonText (L"new button");
    ballyButton->addListener (this);

    ballyButton->setImages (false, true, false,
                            ImageCache::getFromMemory (bally_2x_png, bally_2x_pngSize), 1.0000f, Colour (0x0),
                            Image(), 1.0000f, Colour (0x0),
                            Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (gmFullOnButton = new ImageButton (L"gm full on"));
    gmFullOnButton->setButtonText (L"new button");
    gmFullOnButton->addListener (this);

    gmFullOnButton->setImages (false, true, false,
                               ImageCache::getFromMemory (gmfullOn_2x_png, gmfullOn_2x_pngSize), 1.000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (gmFadeOnButton = new ImageButton (L"gm fade on"));
    gmFadeOnButton->setButtonText (L"new button");
    gmFadeOnButton->addListener (this);

    gmFadeOnButton->setImages (false, true, false,
                               ImageCache::getFromMemory (gmfadeOn_2x_png, gmfadeOn_2x_pngSize), 1.000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (gmFadeOffButton = new ImageButton (L"gm fade off"));
    gmFadeOffButton->setButtonText (L"new button");
    gmFadeOffButton->addListener (this);

    gmFadeOffButton->setImages (false, true, false,
                                ImageCache::getFromMemory (gmfadeOff_2x_png, gmfadeOff_2x_pngSize), 1.000f, Colour (0x0),
                                Image(), 1.0000f, Colour (0x0),
                                Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (gmFullOffButton = new ImageButton (L"gm full off"));
    gmFullOffButton->setButtonText (L"new button");
    gmFullOffButton->addListener (this);

    gmFullOffButton->setImages (false, true, false,
                                ImageCache::getFromMemory (gmfullOff_2x_png, gmfullOff_2x_pngSize), 1.000f, Colour (0x0),
                                Image(), 1.0000f, Colour (0x0),
                                Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (gmLabel = new Label (L"gm label",
                                            L"GM"));
    gmLabel->setFont (Font (16.0000f, Font::plain));
    gmLabel->setJustificationType (Justification::centred);
    gmLabel->setEditable (false, false, false);
    gmLabel->setColour (Label::textColourId, Colours::white);
    gmLabel->setColour (TextEditor::textColourId, Colours::black);
    gmLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (recallButton1 = new ImageButton (L"recall button 1"));
    recallButton1->setButtonText (L"new button");
    recallButton1->addListener (this);

    recallButton1->setImages (false, true, true,
                              ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (recallButton2 = new ImageButton (L"recall button 1"));
    recallButton2->setButtonText (L"new button");
    recallButton2->addListener (this);

    recallButton2->setImages (false, true, true,
                              ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (recallButton3 = new ImageButton (L"recall button 1"));
    recallButton3->setButtonText (L"new button");
    recallButton3->addListener (this);

    recallButton3->setImages (false, true, true,
                              ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (recallButton4 = new ImageButton (L"recall button 1"));
    recallButton4->setButtonText (L"new button");
    recallButton4->addListener (this);

    recallButton4->setImages (false, true, true,
                              ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (recallButton5 = new ImageButton (L"recall button 1"));
    recallButton5->setButtonText (L"new button");
    recallButton5->addListener (this);

    recallButton5->setImages (false, true, true,
                              ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (recallButton6 = new ImageButton (L"recall button 1"));
    recallButton6->setButtonText (L"new button");
    recallButton6->addListener (this);

    recallButton6->setImages (false, true, true,
                              ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (recallButton7 = new ImageButton (L"recall button 1"));
    recallButton7->setButtonText (L"new button");
    recallButton7->addListener (this);

    recallButton7->setImages (false, true, true,
                              ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (recallButton8 = new ImageButton (L"recall button 1"));
    recallButton8->setButtonText (L"new button");
    recallButton8->addListener (this);

    recallButton8->setImages (false, true, true,
                              ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (recallButton9 = new ImageButton (L"recall button 1"));
    recallButton9->setButtonText (L"new button");
    recallButton9->addListener (this);

    recallButton9->setImages (false, true, true,
                              ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x0),
                              Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (recallButton10 = new ImageButton (L"recall button 1"));
    recallButton10->setButtonText (L"new button");
    recallButton10->addListener (this);

    recallButton10->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (recallButton11 = new ImageButton (L"recall button 1"));
    recallButton11->setButtonText (L"new button");
    recallButton11->addListener (this);

    recallButton11->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (recallButton12 = new ImageButton (L"recall button 1"));
    recallButton12->setButtonText (L"new button");
    recallButton12->addListener (this);

    recallButton12->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));

    addChildComponent (recallButton13 = new ImageButton (L"recall button 1"));
    recallButton13->addListener (this);
    
    recallButton13->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));

    addChildComponent (recallButton14 = new ImageButton (L"recall button 1"));
    recallButton14->addListener (this);
    
    recallButton14->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));

    addChildComponent (recallButton15 = new ImageButton (L"recall button 1"));
    recallButton15->addListener (this);
    
    recallButton15->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton16 = new ImageButton (L"recall button 1"));
    recallButton16->addListener (this);
    
    recallButton16->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton17 = new ImageButton (L"recall button 1"));
    recallButton17->addListener (this);
    
    recallButton17->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton18 = new ImageButton (L"recall button 1"));
    recallButton18->addListener (this);
    
    recallButton18->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton19 = new ImageButton (L"recall button 1"));
    recallButton19->addListener (this);
    
    recallButton19->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton20 = new ImageButton (L"recall button 1"));
    recallButton20->addListener (this);
    
    recallButton20->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton21 = new ImageButton (L"recall button 1"));
    recallButton21->addListener (this);
    
    recallButton21->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton22 = new ImageButton (L"recall button 1"));
    recallButton22->addListener (this);
    
    recallButton22->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton23 = new ImageButton (L"recall button 1"));
    recallButton23->addListener (this);
    
    recallButton23->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton24 = new ImageButton (L"recall button 1"));
    recallButton24->addListener (this);
    
    recallButton24->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton25 = new ImageButton (L"recall button 1"));
    recallButton25->addListener (this);
    
    recallButton25->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton26 = new ImageButton (L"recall button 1"));
    recallButton26->addListener (this);
    
    recallButton26->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton27 = new ImageButton (L"recall button 1"));
    recallButton27->addListener (this);
    
    recallButton27->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton28 = new ImageButton (L"recall button 1"));
    recallButton28->addListener (this);
    
    recallButton28->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton29 = new ImageButton (L"recall button 1"));
    recallButton29->addListener (this);
    
    recallButton29->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton30 = new ImageButton (L"recall button 1"));
    recallButton30->addListener (this);
    
    recallButton30->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton31 = new ImageButton (L"recall button 1"));
    recallButton31->addListener (this);
    
    recallButton31->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton32 = new ImageButton (L"recall button 1"));
    recallButton32->addListener (this);
    
    recallButton32->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton33 = new ImageButton (L"recall button 1"));
    recallButton33->addListener (this);
    
    recallButton33->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton34 = new ImageButton (L"recall button 1"));
    recallButton34->addListener (this);
    
    recallButton34->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton35 = new ImageButton (L"recall button 1"));
    recallButton35->addListener (this);
    
    recallButton35->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton36 = new ImageButton (L"recall button 1"));
    recallButton36->addListener (this);
    
    recallButton36->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton37 = new ImageButton (L"recall button 1"));
    recallButton37->addListener (this);
    
    recallButton37->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton38 = new ImageButton (L"recall button 1"));
    recallButton38->addListener (this);
    
    recallButton38->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton39 = new ImageButton (L"recall button 1"));
    recallButton39->addListener (this);
    
    recallButton39->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton40 = new ImageButton (L"recall button 1"));
    recallButton40->addListener (this);
    
    recallButton40->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton41 = new ImageButton (L"recall button 1"));
    recallButton41->addListener (this);
    
    recallButton41->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton42 = new ImageButton (L"recall button 1"));
    recallButton42->addListener (this);
    
    recallButton42->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton43 = new ImageButton (L"recall button 1"));
    recallButton43->addListener (this);
    
    recallButton43->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton44 = new ImageButton (L"recall button 1"));
    recallButton44->addListener (this);
    
    recallButton44->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton45 = new ImageButton (L"recall button 1"));
    recallButton45->addListener (this);
    
    recallButton45->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton46 = new ImageButton (L"recall button 1"));
    recallButton46->addListener (this);
    
    recallButton46->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton47 = new ImageButton (L"recall button 1"));
    recallButton47->addListener (this);
    
    recallButton47->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));
    addChildComponent (recallButton48 = new ImageButton (L"recall button 1"));
    recallButton48->addListener (this);
    
    recallButton48->setImages (false, true, true,
                               ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x0),
                               Image(), 1.0000f, Colour (0x20000000));

    addAndMakeVisible (funcButton = new ImageButton (L"function button"));
    funcButton->setButtonText (L"new button");
    funcButton->addListener (this);

    funcButton->setImages (false, true, true,
                           ImageCache::getFromMemory (smallButton_2x_png, smallButton_2x_pngSize), 1.000f, Colour (0x0),
                           Image(), 1.0000f, Colour (0x0),
                           Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (funcLabel = new Label (L"function label",
                                              L"Func"));
    funcLabel->setFont (Font (16.0000f, Font::plain));
    funcLabel->setJustificationType (Justification::centredRight);
    funcLabel->setEditable (false, false, false);
    funcLabel->setColour (Label::textColourId, Colours::white);
    funcLabel->setColour (TextEditor::textColourId, Colours::black);
    funcLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (connectLabel = new Label (L"connect label",
                                                 L"Searching..."));
    connectLabel->setFont (Font (16.0000f, Font::plain));
    connectLabel->setJustificationType (Justification::centred);
    connectLabel->setEditable (false, false, false);
    connectLabel->setColour (Label::textColourId, Colours::white);
    connectLabel->setColour (TextEditor::textColourId, Colours::black);
    connectLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (pageButton = new ImageButton (L"page button"));
    pageButton->setButtonText (L"new button");
    pageButton->addListener (this);

    pageButton->setImages (false, true, true,
                           ImageCache::getFromMemory (smallButton_2x_png, smallButton_2x_pngSize), 1.000f, Colour (0x0),
                           Image(), 1.0000f, Colour (0x0),
                           Image(), 1.0000f, Colour (0x20000000));
    addAndMakeVisible (pageLabel = new Label (L"page label",
                                              L"Page ?"));
    pageLabel->setFont (Font (12.0000f, Font::plain));
    pageLabel->setJustificationType (Justification::centredLeft);
    pageLabel->setEditable (false, false, false);
    pageLabel->setColour (Label::textColourId, Colours::white);
    pageLabel->setColour (TextEditor::textColourId, Colours::black);
    pageLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (infoButton = new ImageButton (L"page button"));
    infoButton->setButtonText (L"new button");
    infoButton->addListener (this);

    infoButton->setImages (false, true, true,
                           ImageCache::getFromMemory (BinaryData::info_png, BinaryData::info_pngSize), 1.0000f, Colour (0x0),
                           Image(), 1.0000f, Colour (0x0),
                           Image(), 1.0000f, Colour (0x20000000));

    cachedImage_smallLogo_png = ImageCache::getFromMemory (smallLogo_png, smallLogo_pngSize);
    
    //[UserPreSize]
    gmLabel->setMinimumHorizontalScale (.2f);
    funcLabel->setMinimumHorizontalScale (.2f);
    connectLabel->setMinimumHorizontalScale (.2f);
    pageLabel->setMinimumHorizontalScale (.2f);

    buttons.add (recallButton1);
    buttons.add (recallButton2);
    buttons.add (recallButton3);
    buttons.add (recallButton4);
    buttons.add (recallButton5);
    buttons.add (recallButton6);
    buttons.add (recallButton7);
    buttons.add (recallButton8);
    buttons.add (recallButton9);
    buttons.add (recallButton10);
    buttons.add (recallButton11);
    buttons.add (recallButton12);
    buttons.add (recallButton13);
    buttons.add (recallButton14);
    buttons.add (recallButton15);
    buttons.add (recallButton16);
    buttons.add (recallButton17);
    buttons.add (recallButton18);
    buttons.add (recallButton19);
    buttons.add (recallButton20);
    buttons.add (recallButton21);
    buttons.add (recallButton22);
    buttons.add (recallButton23);
    buttons.add (recallButton24);
    buttons.add (recallButton25);
    buttons.add (recallButton26);
    buttons.add (recallButton27);
    buttons.add (recallButton28);
    buttons.add (recallButton29);
    buttons.add (recallButton30);
    buttons.add (recallButton31);
    buttons.add (recallButton32);
    buttons.add (recallButton33);
    buttons.add (recallButton34);
    buttons.add (recallButton35);
    buttons.add (recallButton36);
    buttons.add (recallButton37);
    buttons.add (recallButton38);
    buttons.add (recallButton39);
    buttons.add (recallButton40);
    buttons.add (recallButton41);
    buttons.add (recallButton42);
    buttons.add (recallButton43);
    buttons.add (recallButton44);
    buttons.add (recallButton45);
    buttons.add (recallButton46);
    buttons.add (recallButton47);
    buttons.add (recallButton48);
    
    // We need labels for the buttons
    for (int n=0 ; n < 48 ; n++)
    {
        Label* label = new Label();
        
        if (n < 12)
            addAndMakeVisible (label);
        else
            addChildComponent (label);
        
        label->setFont (Font (12.0000f, Font::plain));
        label->setJustificationType (Justification::centred);
        label->setEditable (false, false, false);
        label->setColour (Label::textColourId, Colours::white);
        label->setColour (TextEditor::textColourId, Colours::black);
        label->setColour (TextEditor::backgroundColourId, Colour (0x0));
        label->setMinimumHorizontalScale (.2f);
        label->setInterceptsMouseClicks (false, false);
        labels.add (label);
    }
    
    //[/UserPreSize]

    setSize (320, 480);

    //[Constructor] You can add your own custom stuff here..    
    // Build an array for easy access
    startTimer (500);    
    //[/Constructor]
}

LivePanelComponent::~LivePanelComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    buttons.clear();
    //[/Destructor_pre]

    deleteAndZero (stopButton);
    deleteAndZero (tapButton);
    deleteAndZero (stepButton);
    deleteAndZero (forwardButton);
    deleteAndZero (reverseButton);
    deleteAndZero (ballyButton);
    deleteAndZero (gmFullOnButton);
    deleteAndZero (gmFadeOnButton);
    deleteAndZero (gmFadeOffButton);
    deleteAndZero (gmFullOffButton);
    deleteAndZero (gmLabel);
    deleteAndZero (recallButton1);
    deleteAndZero (recallButton2);
    deleteAndZero (recallButton3);
    deleteAndZero (recallButton4);
    deleteAndZero (recallButton5);
    deleteAndZero (recallButton6);
    deleteAndZero (recallButton7);
    deleteAndZero (recallButton8);
    deleteAndZero (recallButton9);
    deleteAndZero (recallButton10);
    deleteAndZero (recallButton11);
    deleteAndZero (recallButton12);
    deleteAndZero (recallButton13);
    deleteAndZero (recallButton14);
    deleteAndZero (recallButton15);
    deleteAndZero (recallButton16);
    deleteAndZero (recallButton17);
    deleteAndZero (recallButton18);
    deleteAndZero (recallButton19);
    deleteAndZero (recallButton20);
    deleteAndZero (recallButton21);
    deleteAndZero (recallButton22);
    deleteAndZero (recallButton23);
    deleteAndZero (recallButton24);
    deleteAndZero (recallButton25);
    deleteAndZero (recallButton26);
    deleteAndZero (recallButton27);
    deleteAndZero (recallButton28);
    deleteAndZero (recallButton29);
    deleteAndZero (recallButton30);
    deleteAndZero (recallButton31);
    deleteAndZero (recallButton32);
    deleteAndZero (recallButton33);
    deleteAndZero (recallButton34);
    deleteAndZero (recallButton35);
    deleteAndZero (recallButton36);
    deleteAndZero (recallButton37);
    deleteAndZero (recallButton38);
    deleteAndZero (recallButton39);
    deleteAndZero (recallButton40);
    deleteAndZero (recallButton41);
    deleteAndZero (recallButton42);
    deleteAndZero (recallButton43);
    deleteAndZero (recallButton44);
    deleteAndZero (recallButton45);
    deleteAndZero (recallButton46);
    deleteAndZero (recallButton47);
    deleteAndZero (recallButton48);
    deleteAndZero (funcButton);
    deleteAndZero (funcLabel);
    deleteAndZero (connectLabel);
    deleteAndZero (pageButton);
    deleteAndZero (pageLabel);
    deleteAndZero (infoButton);


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void LivePanelComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff233845));

    g.setColour (Colour (0xff182d3a));
    if (getWidth() < getHeight())
    {
        g.fillRect (proportionOfWidth (0.0000f), proportionOfHeight (0.0714f), proportionOfWidth (1.0000f), proportionOfHeight (0.4464f));
    }
    else
    {
        if (getWidth() < 1000)
            g.fillRect (proportionOfWidth (0.0178f), proportionOfHeight (0.1121f), proportionOfWidth (0.4444f), proportionOfHeight (0.7601f));
        else
        {
            g.fillRect (proportionOfWidth (0.0101f), proportionOfHeight (0.0851f), proportionOfWidth (0.9785f), proportionOfHeight (0.4874f));

            g.setColour (Colours::black);
            g.drawImageWithin (cachedImage_smallLogo_png,
                               proportionOfWidth (0.8000f), proportionOfHeight (0.8820f), proportionOfWidth (0.1671f), proportionOfHeight (0.0851f),
                               RectanglePlacement::centred | RectanglePlacement::onlyReduceInSize,
                               false);            
        }
    }
    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void LivePanelComponent::resized()
{
    if (getWidth() < getHeight())
    {
        for (int n=12 ; n < 48 ; n++)
        {
            buttons[n]->setVisible (false);
            labels[n]->setVisible (false);
        }
        funcLabel->setVisible (true);
        funcButton->setVisible (true);
        bigDisplay = false;
        
        stopButton->setBounds (proportionOfWidth (0.4600f), proportionOfHeight (0.7321f), proportionOfWidth (0.3111f), proportionOfHeight (0.1121f));
        tapButton->setBounds (proportionOfWidth (0.2733f), proportionOfHeight (0.8567f), proportionOfWidth (0.3111f), proportionOfHeight (0.1121f));
        stepButton->setBounds (proportionOfWidth (0.6489f), proportionOfHeight (0.8567f), proportionOfWidth (0.3111f), proportionOfHeight (0.1121f));
        forwardButton->setBounds (proportionOfWidth (0.7844f), proportionOfHeight (0.6791f), proportionOfWidth (0.1867f), proportionOfHeight (0.1776f));
        reverseButton->setBounds (proportionOfWidth (0.2622f), proportionOfHeight (0.6791f), proportionOfWidth (0.1867f), proportionOfHeight (0.1776f));
        ballyButton->setBounds (proportionOfWidth (0.4600f), proportionOfHeight (0.5888f), proportionOfWidth (0.3111f), proportionOfHeight (0.1340f));
        gmFullOnButton->setBounds (proportionOfWidth (0.0489f), proportionOfHeight (0.6075f), proportionOfWidth (0.1556f), proportionOfHeight (0.0654f));
        gmFadeOnButton->setBounds (proportionOfWidth (0.0489f), proportionOfHeight (0.7041f), proportionOfWidth (0.1556f), proportionOfHeight (0.0654f));
        gmFadeOffButton->setBounds (proportionOfWidth (0.0489f), proportionOfHeight (0.8131f), proportionOfWidth (0.1556f), proportionOfHeight (0.0654f));
        gmFullOffButton->setBounds (proportionOfWidth (0.0489f), proportionOfHeight (0.9097f), proportionOfWidth (0.1556f), proportionOfHeight (0.0654f));
        gmLabel->setBounds (proportionOfWidth (0.0244f), proportionOfHeight (0.5452f), proportionOfWidth (0.2111f), proportionOfHeight (0.0343f));
        recallButton1->setBounds (proportionOfWidth (0.0489f), proportionOfHeight (0.0997f), proportionOfWidth (0.1911f), proportionOfHeight (0.1246f));
        recallButton2->setBounds (proportionOfWidth (0.2867f), proportionOfHeight (0.0997f), proportionOfWidth (0.1911f), proportionOfHeight (0.1246f));
        recallButton3->setBounds (proportionOfWidth (0.5244f), proportionOfHeight (0.0997f), proportionOfWidth (0.1911f), proportionOfHeight (0.1246f));
        recallButton4->setBounds (proportionOfWidth (0.7600f), proportionOfHeight (0.0997f), proportionOfWidth (0.1911f), proportionOfHeight (0.1246f));
        recallButton5->setBounds (proportionOfWidth (0.0489f), proportionOfHeight (0.2336f), proportionOfWidth (0.1911f), proportionOfHeight (0.1246f));
        recallButton6->setBounds (proportionOfWidth (0.2867f), proportionOfHeight (0.2336f), proportionOfWidth (0.1911f), proportionOfHeight (0.1246f));
        recallButton7->setBounds (proportionOfWidth (0.5244f), proportionOfHeight (0.2336f), proportionOfWidth (0.1911f), proportionOfHeight (0.1246f));
        recallButton8->setBounds (proportionOfWidth (0.7600f), proportionOfHeight (0.2336f), proportionOfWidth (0.1911f), proportionOfHeight (0.1246f));
        recallButton9->setBounds (proportionOfWidth (0.0489f), proportionOfHeight (0.3676f), proportionOfWidth (0.1911f), proportionOfHeight (0.1246f));
        recallButton10->setBounds (proportionOfWidth (0.2867f), proportionOfHeight (0.3676f), proportionOfWidth (0.1911f), proportionOfHeight (0.1246f));
        recallButton11->setBounds (proportionOfWidth (0.5244f), proportionOfHeight (0.3676f), proportionOfWidth (0.1911f), proportionOfHeight (0.1246f));
        recallButton12->setBounds (proportionOfWidth (0.7600f), proportionOfHeight (0.3676f), proportionOfWidth (0.1911f), proportionOfHeight (0.1246f));
        funcButton->setBounds (proportionOfWidth (0.8733f), proportionOfHeight (0.5358f), proportionOfWidth (0.0933f), proportionOfHeight (0.0654f));
        funcLabel->setBounds (proportionOfWidth (0.5733f), proportionOfHeight (0.5452f), proportionOfWidth (0.2867f), proportionOfHeight (0.0343f));
        connectLabel->setBounds (proportionOfWidth (0.2489f), proportionOfHeight (0.0187f), proportionOfWidth (0.5111f), proportionOfHeight (0.0343f));
        pageButton->setBounds (proportionOfWidth (0.0378f), proportionOfHeight (0.0031f), proportionOfWidth (0.0933f), proportionOfHeight (0.0654f));
        pageLabel->setBounds (proportionOfWidth (0.1311f), proportionOfHeight (0.0218f), proportionOfWidth (0.2267f), proportionOfHeight (0.0280f));
        infoButton->setBounds (proportionOfWidth (0.8910f), proportionOfHeight (0.007f), proportionOfWidth (0.0781f), proportionOfHeight (0.0521f));
    }
    else
    {
        if (getWidth() < 1000)
        {
            for (int n=12 ; n < 48 ; n++)
            {
                buttons[n]->setVisible (false);
                labels[n]->setVisible (false);
            }
            funcLabel->setVisible (true);
            funcButton->setVisible (true);
            bigDisplay = false;
            
            gmLabel->setBounds (proportionOfWidth (0.6667f), proportionOfHeight (0.8100f), proportionOfWidth (0.1511f), proportionOfHeight (0.0498f));
            recallButton6->setBounds (proportionOfWidth (0.3111f), proportionOfHeight (0.3115f), proportionOfWidth (0.1356f), proportionOfHeight (0.1744f));
            recallButton9->setBounds (proportionOfWidth (0.3111f), proportionOfHeight (0.4984f), proportionOfWidth (0.1356f), proportionOfHeight (0.1744f));
            recallButton8->setBounds (proportionOfWidth (0.1689f), proportionOfHeight (0.4984f), proportionOfWidth (0.1356f), proportionOfHeight (0.1744f));
            stopButton->setBounds (proportionOfWidth (0.6222f), proportionOfHeight (0.2991f), proportionOfWidth (0.2222f), proportionOfHeight (0.1558f));
            tapButton->setBounds (proportionOfWidth (0.4978f), proportionOfHeight (0.4984f), proportionOfWidth (0.2222f), proportionOfHeight (0.1558f));
            stepButton->setBounds (proportionOfWidth (0.7556f), proportionOfHeight (0.4984f), proportionOfWidth (0.2222f), proportionOfHeight (0.1558f));
            forwardButton->setBounds (proportionOfWidth (0.8533f), proportionOfHeight (0.2243f), proportionOfWidth (0.1333f), proportionOfHeight (0.2492f));
            reverseButton->setBounds (proportionOfWidth (0.4800f), proportionOfHeight (0.2243f), proportionOfWidth (0.1333f), proportionOfHeight (0.2492f));
            ballyButton->setBounds (proportionOfWidth (0.6222f), proportionOfHeight (0.0872f), proportionOfWidth (0.2222f), proportionOfHeight (0.1869f));
            gmFullOnButton->setBounds (proportionOfWidth (0.5778f), proportionOfHeight (0.7227f), proportionOfWidth (0.1111f), proportionOfHeight (0.0935f));
            gmFadeOnButton->setBounds (proportionOfWidth (0.5778f), proportionOfHeight (0.8598f), proportionOfWidth (0.1111f), proportionOfHeight (0.0935f));
            gmFadeOffButton->setBounds (proportionOfWidth (0.8000f), proportionOfHeight (0.8723f), proportionOfWidth (0.1111f), proportionOfHeight (0.0935f));
            gmFullOffButton->setBounds (proportionOfWidth (0.8000f), proportionOfHeight (0.7352f), proportionOfWidth (0.1111f), proportionOfHeight (0.0935f));
            recallButton1->setBounds (proportionOfWidth (0.0267f), proportionOfHeight (0.1246f), proportionOfWidth (0.1356f), proportionOfHeight (0.1744f));
            recallButton2->setBounds (proportionOfWidth (0.1689f), proportionOfHeight (0.1246f), proportionOfWidth (0.1356f), proportionOfHeight (0.1744f));
            recallButton3->setBounds (proportionOfWidth (0.3111f), proportionOfHeight (0.1246f), proportionOfWidth (0.1356f), proportionOfHeight (0.1744f));
            recallButton4->setBounds (proportionOfWidth (0.0267f), proportionOfHeight (0.3115f), proportionOfWidth (0.1356f), proportionOfHeight (0.1744f));
            recallButton5->setBounds (proportionOfWidth (0.1689f), proportionOfHeight (0.3115f), proportionOfWidth (0.1356f), proportionOfHeight (0.1744f));
            recallButton7->setBounds (proportionOfWidth (0.0267f), proportionOfHeight (0.4984f), proportionOfWidth (0.1356f), proportionOfHeight (0.1744f));
            recallButton10->setBounds (proportionOfWidth (0.0267f), proportionOfHeight (0.6854f), proportionOfWidth (0.1356f), proportionOfHeight (0.1744f));
            recallButton11->setBounds (proportionOfWidth (0.1689f), proportionOfHeight (0.6854f), proportionOfWidth (0.1356f), proportionOfHeight (0.1744f));
            recallButton12->setBounds (proportionOfWidth (0.3111f), proportionOfHeight (0.6854f), proportionOfWidth (0.1356f), proportionOfHeight (0.1744f));
            funcButton->setBounds (proportionOfWidth (0.3964f), proportionOfHeight (0.8972f), proportionOfWidth (0.0668f), proportionOfHeight (0.0935f));
            funcLabel->setBounds (proportionOfWidth (0.1826f), proportionOfHeight (0.9221f), proportionOfWidth (0.2049f), proportionOfHeight (0.0498f));
            connectLabel->setBounds (proportionOfWidth (0.3378f), proportionOfHeight (0.0187f), proportionOfWidth (0.3644f), proportionOfHeight (0.0498f));
            pageButton->setBounds (proportionOfWidth (0.0200f), proportionOfHeight (0.9003f), proportionOfWidth (0.0668f), proportionOfHeight (0.0935f));
            pageLabel->setBounds (proportionOfWidth (0.0891f), proportionOfHeight (0.9221f), proportionOfWidth (0.1626f), proportionOfHeight (0.0498f));
            infoButton->setBounds (proportionOfWidth (0.9154f), proportionOfHeight (.004f), proportionOfWidth (0.0521f), proportionOfHeight (0.0781f));
        }
        else
        {
            for (int n=12 ; n < 48 ; n++)
            {
                buttons[n]->setVisible (true);
                labels[n]->setVisible (true);
            }
            funcLabel->setVisible (false);
            funcButton->setVisible (false);

            pageOffset = 0;
            funcLabel->setText ("Func", dontSendNotification);
            if (! bigDisplay)
                updatePage();
            bigDisplay = true;
            
            gmLabel->setBounds (proportionOfWidth (0.2886f), proportionOfHeight (0.6035f), proportionOfWidth (0.0861f), proportionOfHeight (0.0310f));
            recallButton6->setBounds (proportionOfWidth (0.4202f), proportionOfHeight (0.1006f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton9->setBounds (proportionOfWidth (0.6633f), proportionOfHeight (0.1006f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton8->setBounds (proportionOfWidth (0.5823f), proportionOfHeight (0.1006f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            stopButton->setBounds (proportionOfWidth (0.4949f), proportionOfHeight (0.7505f), proportionOfWidth (0.1266f), proportionOfHeight (0.0967f));
            tapButton->setBounds (proportionOfWidth (0.4253f), proportionOfHeight (0.8743f), proportionOfWidth (0.1266f), proportionOfHeight (0.0967f));
            stepButton->setBounds (proportionOfWidth (0.5709f), proportionOfHeight (0.8743f), proportionOfWidth (0.1266f), proportionOfHeight (0.0967f));
            forwardButton->setBounds (proportionOfWidth (0.6266f), proportionOfHeight (0.7041f), proportionOfWidth (0.0759f), proportionOfHeight (0.1547f));
            reverseButton->setBounds (proportionOfWidth (0.4152f), proportionOfHeight (0.7041f), proportionOfWidth (0.0759f), proportionOfHeight (0.1547f));
            ballyButton->setBounds (proportionOfWidth (0.4949f), proportionOfHeight (0.6190f), proportionOfWidth (0.1266f), proportionOfHeight (0.1160f));
            gmFullOnButton->setBounds (proportionOfWidth (0.3025f), proportionOfHeight (0.6499f), proportionOfWidth (0.0633f), proportionOfHeight (0.0580f));
            gmFadeOnButton->setBounds (proportionOfWidth (0.3025f), proportionOfHeight (0.7350f), proportionOfWidth (0.0633f), proportionOfHeight (0.0580f));
            gmFullOffButton->setBounds (proportionOfWidth (0.3025f), proportionOfHeight (0.9130f), proportionOfWidth (0.0633f), proportionOfHeight (0.0580f));
            gmFadeOffButton->setBounds (proportionOfWidth (0.3025f), proportionOfHeight (0.8278f), proportionOfWidth (0.0633f), proportionOfHeight (0.0580f));
            recallButton1->setBounds (proportionOfWidth (0.0152f), proportionOfHeight (0.1006f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton2->setBounds (proportionOfWidth (0.0962f), proportionOfHeight (0.1006f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton3->setBounds (proportionOfWidth (0.1772f), proportionOfHeight (0.1006f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton4->setBounds (proportionOfWidth (0.2582f), proportionOfHeight (0.1006f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton5->setBounds (proportionOfWidth (0.3392f), proportionOfHeight (0.1006f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton7->setBounds (proportionOfWidth (0.5013f), proportionOfHeight (0.1006f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton10->setBounds (proportionOfWidth (0.7443f), proportionOfHeight (0.1006f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton11->setBounds (proportionOfWidth (0.8253f), proportionOfHeight (0.1006f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton12->setBounds (proportionOfWidth (0.9063f), proportionOfHeight (0.1006f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            funcButton->setBounds (proportionOfWidth (0.9291f), proportionOfHeight (0.6035f), proportionOfWidth (0.0380f), proportionOfHeight (0.0580f));
            funcLabel->setBounds (proportionOfWidth (0.8076f), proportionOfHeight (0.6190f), proportionOfWidth (0.1165f), proportionOfHeight (0.0310f));
            connectLabel->setBounds (proportionOfWidth (0.4000f), proportionOfHeight (0.0232f), proportionOfWidth (0.2076f), proportionOfHeight (0.0310f));
            pageButton->setBounds (proportionOfWidth (0.0114f), proportionOfHeight (0.0097f), proportionOfWidth (0.0380f), proportionOfHeight (0.0580f));
            pageLabel->setBounds (proportionOfWidth (0.0506f), proportionOfHeight (0.0232f), proportionOfWidth (0.0924f), proportionOfHeight (0.0310f));
            infoButton->setBounds (proportionOfWidth (0.9570f), proportionOfHeight (0.0155f), proportionOfWidth (0.0228f), proportionOfHeight (0.0348f));
            recallButton13->setBounds (proportionOfWidth (0.0152f), proportionOfHeight (0.2166f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton14->setBounds (proportionOfWidth (0.0962f), proportionOfHeight (0.2166f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton15->setBounds (proportionOfWidth (0.1772f), proportionOfHeight (0.2166f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton16->setBounds (proportionOfWidth (0.2582f), proportionOfHeight (0.2166f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton17->setBounds (proportionOfWidth (0.3392f), proportionOfHeight (0.2166f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton18->setBounds (proportionOfWidth (0.4202f), proportionOfHeight (0.2166f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton19->setBounds (proportionOfWidth (0.5013f), proportionOfHeight (0.2166f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton20->setBounds (proportionOfWidth (0.5823f), proportionOfHeight (0.2166f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton21->setBounds (proportionOfWidth (0.6633f), proportionOfHeight (0.2166f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton22->setBounds (proportionOfWidth (0.7443f), proportionOfHeight (0.2166f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton23->setBounds (proportionOfWidth (0.8253f), proportionOfHeight (0.2166f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton24->setBounds (proportionOfWidth (0.9063f), proportionOfHeight (0.2166f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton25->setBounds (proportionOfWidth (0.0152f), proportionOfHeight (0.3327f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton26->setBounds (proportionOfWidth (0.0962f), proportionOfHeight (0.3327f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton27->setBounds (proportionOfWidth (0.1772f), proportionOfHeight (0.3327f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton28->setBounds (proportionOfWidth (0.2582f), proportionOfHeight (0.3327f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton29->setBounds (proportionOfWidth (0.3392f), proportionOfHeight (0.3327f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton30->setBounds (proportionOfWidth (0.4202f), proportionOfHeight (0.3327f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton31->setBounds (proportionOfWidth (0.5013f), proportionOfHeight (0.3327f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton32->setBounds (proportionOfWidth (0.5823f), proportionOfHeight (0.3327f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton33->setBounds (proportionOfWidth (0.6633f), proportionOfHeight (0.3327f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton34->setBounds (proportionOfWidth (0.7443f), proportionOfHeight (0.3327f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton35->setBounds (proportionOfWidth (0.8253f), proportionOfHeight (0.3327f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton36->setBounds (proportionOfWidth (0.9063f), proportionOfHeight (0.3327f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton37->setBounds (proportionOfWidth (0.0152f), proportionOfHeight (0.4487f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton38->setBounds (proportionOfWidth (0.0962f), proportionOfHeight (0.4487f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton39->setBounds (proportionOfWidth (0.1772f), proportionOfHeight (0.4487f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton40->setBounds (proportionOfWidth (0.2582f), proportionOfHeight (0.4487f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton41->setBounds (proportionOfWidth (0.3392f), proportionOfHeight (0.4487f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton42->setBounds (proportionOfWidth (0.4202f), proportionOfHeight (0.4487f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton43->setBounds (proportionOfWidth (0.5013f), proportionOfHeight (0.4487f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton44->setBounds (proportionOfWidth (0.5823f), proportionOfHeight (0.4487f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton45->setBounds (proportionOfWidth (0.6633f), proportionOfHeight (0.4487f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton46->setBounds (proportionOfWidth (0.7443f), proportionOfHeight (0.4487f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton47->setBounds (proportionOfWidth (0.8253f), proportionOfHeight (0.4487f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));
            recallButton48->setBounds (proportionOfWidth (0.9063f), proportionOfHeight (0.4487f), proportionOfWidth (0.0772f), proportionOfHeight (0.1083f));            
        }
    }
    
    //[UserResized] Add your own custom resize handling here..
    gmLabel->setFont (Font (gmLabel->getHeight() * .7f, Font::plain));
    funcLabel->setFont (Font (funcLabel->getHeight() * .7f, Font::plain));
    pageLabel->setFont (Font (pageLabel->getHeight() * .7f, Font::plain));
    connectLabel->setFont (Font (connectLabel->getHeight() * .7f, Font::plain));
    
    for (int n=0 ; n<48 ; n++)
    {
        if (! labels[n]->isVisible())
            break;
        
        Rectangle<int> r = (buttons[n])->getBounds();
        int h = r.getHeight();
        (labels[n])->setBounds (r.getX(), r.getY() + h - (h >> 2), r.getWidth(), h >> 2);
        (labels[n])->setFont (Font (h / 5.0f, Font::plain));
    }
    
    if (overlay != nullptr)
        overlay->setBounds (0, 0, getWidth(), getHeight());
    //[/UserResized]
}

void LivePanelComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == funcButton)
    {
        //[UserButtonCode_funcButton] -- add your button handler code here..
        pageOffset++;
        if (pageOffset >= 4)
            pageOffset = 0;
        
        switch (pageOffset)
        {
            case 0:
                funcLabel->setText ("Func", dontSendNotification);
                break;
            case 1:
                funcLabel->setText ("Shift", dontSendNotification);
                break;
            case 2:
                funcLabel->setText ("Ctrl", dontSendNotification);
                break;
            default:
                funcLabel->setText ("Alt", dontSendNotification);
                break;
        };
        
        updatePage();
        //[/UserButtonCode_funcButton]
    }
    else if (buttonThatWasClicked == pageButton)
    {
        //[UserButtonCode_pageButton] -- add your button handler code here..
        if (overlay == nullptr)
        {
            overlay = new PagePickerComponent (lastPage);
            addAndMakeVisible (overlay);
            resized();
        }
        //[/UserButtonCode_pageButton]
    }
    else if (buttonThatWasClicked == infoButton)
    {
        //[UserButtonCode_infoButton] -- add your button handler code here..
        if (overlay == nullptr)
        {
            overlay = new AboutComponent();
            addAndMakeVisible (overlay);
            resized();
        }
        //[/UserButtonCode_infoButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void LivePanelComponent::buttonStateChanged(Button* buttonThatChanged)
{
    if (buttonThatChanged->isDown())
    {
        if (buttonThatChanged == stopButton)
            lpNet->activeStop();
        else if (buttonThatChanged == tapButton)
            lpNet->activeTap();
        else if (buttonThatChanged == stepButton)
            lpNet->activeStep();
        else if (buttonThatChanged == forwardButton)
            lpNet->activeForward();
        else if (buttonThatChanged == reverseButton)
            lpNet->activeReverse();
        else if (buttonThatChanged == ballyButton)
            lpNet->activeBally();
        else if (buttonThatChanged == gmFullOnButton)
            lpNet->setGM (8192);
        else if (buttonThatChanged == gmFadeOnButton)
            lpNet->fadeGM (3);
        else if (buttonThatChanged == gmFadeOffButton)
            lpNet->fadeGM (-3);
        else if (buttonThatChanged == gmFullOffButton)
            lpNet->setGM (0);
        else if (buttonThatChanged == recallButton1)
            lpNet->doRecall (pageOffset * 12);
        else if (buttonThatChanged == recallButton2)
            lpNet->doRecall (pageOffset * 12 + 1);
        else if (buttonThatChanged == recallButton3)
            lpNet->doRecall (pageOffset * 12 + 2);
        else if (buttonThatChanged == recallButton4)
            lpNet->doRecall (pageOffset * 12 + 3);
        else if (buttonThatChanged == recallButton5)
            lpNet->doRecall (pageOffset * 12 + 4);
        else if (buttonThatChanged == recallButton6)
            lpNet->doRecall (pageOffset * 12 + 5);
        else if (buttonThatChanged == recallButton7)
            lpNet->doRecall (pageOffset * 12 + 6);
        else if (buttonThatChanged == recallButton8)
            lpNet->doRecall (pageOffset * 12 + 7);
        else if (buttonThatChanged == recallButton9)
            lpNet->doRecall (pageOffset * 12 + 8);
        else if (buttonThatChanged == recallButton10)
            lpNet->doRecall (pageOffset * 12 + 9);
        else if (buttonThatChanged == recallButton11)
            lpNet->doRecall (pageOffset * 12 + 10);
        else if (buttonThatChanged == recallButton12)
            lpNet->doRecall (pageOffset * 12 + 11);
        else if (buttonThatChanged == recallButton13)
            lpNet->doRecall (12);
        else if (buttonThatChanged == recallButton14)
            lpNet->doRecall (13);
        else if (buttonThatChanged == recallButton15)
            lpNet->doRecall (14);
        else if (buttonThatChanged == recallButton16)
            lpNet->doRecall (15);
        else if (buttonThatChanged == recallButton17)
            lpNet->doRecall (16);
        else if (buttonThatChanged == recallButton18)
            lpNet->doRecall (17);
        else if (buttonThatChanged == recallButton19)
            lpNet->doRecall (18);
        else if (buttonThatChanged == recallButton20)
            lpNet->doRecall (19);
        else if (buttonThatChanged == recallButton21)
            lpNet->doRecall (20);
        else if (buttonThatChanged == recallButton22)
            lpNet->doRecall (21);
        else if (buttonThatChanged == recallButton23)
            lpNet->doRecall (22);
        else if (buttonThatChanged == recallButton24)
            lpNet->doRecall (23);
        else if (buttonThatChanged == recallButton25)
            lpNet->doRecall (24);
        else if (buttonThatChanged == recallButton26)
            lpNet->doRecall (25);
        else if (buttonThatChanged == recallButton27)
            lpNet->doRecall (26);
        else if (buttonThatChanged == recallButton28)
            lpNet->doRecall (27);
        else if (buttonThatChanged == recallButton29)
            lpNet->doRecall (28);
        else if (buttonThatChanged == recallButton30)
            lpNet->doRecall (29);
        else if (buttonThatChanged == recallButton31)
            lpNet->doRecall (30);
        else if (buttonThatChanged == recallButton32)
            lpNet->doRecall (31);
        else if (buttonThatChanged == recallButton33)
            lpNet->doRecall (32);
        else if (buttonThatChanged == recallButton34)
            lpNet->doRecall (33);
        else if (buttonThatChanged == recallButton35)
            lpNet->doRecall (34);
        else if (buttonThatChanged == recallButton36)
            lpNet->doRecall (35);
        else if (buttonThatChanged == recallButton37)
            lpNet->doRecall (36);
        else if (buttonThatChanged == recallButton38)
            lpNet->doRecall (37);
        else if (buttonThatChanged == recallButton39)
            lpNet->doRecall (38);
        else if (buttonThatChanged == recallButton40)
            lpNet->doRecall (39);
        else if (buttonThatChanged == recallButton41)
            lpNet->doRecall (40);
        else if (buttonThatChanged == recallButton42)
            lpNet->doRecall (41);
        else if (buttonThatChanged == recallButton43)
            lpNet->doRecall (42);
        else if (buttonThatChanged == recallButton44)
            lpNet->doRecall (43);
        else if (buttonThatChanged == recallButton45)
            lpNet->doRecall (44);
        else if (buttonThatChanged == recallButton46)
            lpNet->doRecall (45);
        else if (buttonThatChanged == recallButton47)
            lpNet->doRecall (46);
        else if (buttonThatChanged == recallButton48)
            lpNet->doRecall (47);
    }
}

void LivePanelComponent::handleCommandMessage (int commandId)
{
    //[UserCode_handleCommandMessage] -- Add your code here...
    // Page overlay?
    if (commandId == 0x1234)
    {
        if (overlay != nullptr)
        {
            PagePickerComponent* picker = dynamic_cast<PagePickerComponent*> (overlay);
            int page = picker->getPage();
            
            lpNet->setPage (page);
            lpNet->getPage (&page);
            
            removeChildComponent (picker);
            deleteAndZero (overlay);
            
            updatePage();
        }
    }
    else if (overlay != nullptr)
    {
        removeChildComponent (overlay);
        deleteAndZero (overlay);
    }
    //[/UserCode_handleCommandMessage]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//==============================================================================
void LivePanelComponent::timerCallback()
{
    bool state = lpNet->isConnected();
    if (state != lastState)
    {
        if (state)
            connectLabel->setText ("Connected", dontSendNotification);
        else
            connectLabel->setText ("Searching...", dontSendNotification);
        lastState = state;
        updatePage();
    }
    
    timerDivider++;
    if (timerDivider >= 10)
    {
        timerDivider=0;
        
        int page;
        if (lpNet->getPage (&page))
        {
            if (page != lastPage)
                updatePage();
        }
    }
}

//==============================================================================
void LivePanelComponent::updatePage()
{
    int page;
    
    if (! lpNet->getPage (&page))
        page = -1;
    
    lastPage = page;
    String p = "Page: ";
    if (page >= 0)
        p << String(page + 1);
    else
        p << '?';
    
    pageLabel->setText (p, dontSendNotification);
    
    for (int n=0 ; n<48 ; n++)
    {
        if (! buttons[n]->isVisible())
            break;
        
        LpNet::RecallInfo info;
        if (! lpNet->getRecall (pageOffset * 12 + n, info))
            info.isActive = false;
        
        (buttons[n])->setImages (false, true, info.isActive ? false
                                                            : true,
                        info.isActive ? ImageCache::getFromMemory (BinaryData::sequence_active2x_png, BinaryData::sequence_active2x_pngSize)
                                      : ImageCache::getFromMemory (BinaryData::sequence_inactive2x_png, BinaryData::sequence_inactive2x_pngSize),
                                 1.0000f, Colour (0x0),
                                 Image(), 1.0000f, Colour (0x0),
                                 Image(), 1.0000f, Colour (0x20000000));
        
        (labels[n])->setText (info.name, dontSendNotification);
    }
}

//[/MiscUserCode]


//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: stop_2x_png, 18537, "../Images/Stop@2x.png"
static const unsigned char resource_LivePanelComponent_stop_2x_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,200,0,0,0,100,8,6,0,0,0,195,134,127,11,0,0,0,1,115,82,71,66,0,174,206,28,233,
0,0,0,6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,219,10,30,4,39,23,16,68,225,63,0,0,32,0,73,68,65,84,120,218,237,189,
121,144,101,103,117,39,248,59,247,222,151,91,229,94,185,84,102,237,139,74,82,73,66,187,100,144,89,26,132,36,16,2,73,128,196,98,7,118,99,143,163,27,143,233,238,233,24,166,219,221,127,76,196,76,56,250,143,
142,240,76,187,163,81,55,198,102,176,16,102,211,46,16,8,1,194,104,67,82,73,42,85,149,106,207,170,172,202,204,202,253,229,242,242,45,247,126,103,254,120,119,57,223,114,95,102,74,133,25,198,60,69,170,50,
223,123,247,222,111,63,231,252,206,239,156,67,184,64,175,39,127,240,36,145,71,222,135,110,185,69,1,64,4,112,242,217,83,63,254,113,47,49,154,142,31,63,230,77,205,76,7,196,12,48,192,4,16,8,64,253,203,196,
12,16,213,63,3,103,159,17,199,95,136,223,97,32,253,133,1,128,226,111,51,20,8,32,134,199,170,126,47,16,178,166,80,124,105,124,119,230,248,217,20,127,181,222,168,250,167,72,26,88,191,90,60,147,146,142,113,
214,190,122,203,226,107,147,239,50,167,215,51,8,30,226,247,64,96,34,16,49,192,92,255,157,1,102,174,191,71,94,253,210,250,160,196,215,3,158,236,11,199,45,73,219,68,217,120,16,33,238,90,253,99,66,58,62,
245,103,100,223,101,162,250,39,156,221,55,238,74,125,180,146,135,19,197,221,37,128,185,62,118,94,220,127,86,32,202,230,0,233,8,137,241,77,218,77,4,86,245,231,19,49,152,227,121,240,160,205,85,253,26,249,
55,80,8,2,238,236,234,12,47,218,123,49,131,184,114,243,251,111,158,75,166,194,143,31,250,253,39,127,232,49,152,111,189,245,86,117,33,214,53,93,136,141,113,235,109,183,178,124,239,169,31,253,104,7,3,237,
251,247,239,87,129,239,247,13,13,15,223,52,63,55,223,51,51,59,211,87,90,94,238,100,165,60,242,72,201,38,152,27,68,190,152,178,5,110,109,16,185,240,89,244,42,125,67,78,150,249,59,231,12,3,103,27,192,218,
32,174,111,179,190,209,211,15,178,13,146,124,110,63,82,92,157,244,95,187,15,235,215,139,13,130,116,131,24,237,206,150,163,99,130,69,223,227,133,111,182,43,222,195,226,46,217,88,136,201,202,238,158,110,
100,247,6,113,207,129,249,22,59,54,72,178,167,136,149,82,158,231,145,106,107,219,176,208,215,223,63,213,213,213,57,51,121,126,242,217,114,185,60,117,245,53,215,248,0,74,31,252,224,7,79,203,91,255,224,
201,31,208,109,183,222,198,191,214,13,146,188,126,248,228,15,175,89,46,149,218,166,166,38,123,2,223,191,97,118,110,174,123,110,118,182,127,165,84,234,138,148,10,42,229,114,231,114,169,52,80,173,86,123,
88,41,159,136,212,234,205,226,245,245,132,243,222,176,62,204,230,37,231,81,28,95,66,235,25,57,198,175,240,69,235,124,64,131,239,55,186,213,106,143,161,183,218,79,113,161,121,143,53,76,55,51,123,228,121,
97,115,115,243,220,134,182,182,243,45,173,173,69,207,243,194,182,182,182,133,158,222,222,169,222,222,222,249,90,173,246,252,166,193,193,185,166,150,230,149,91,111,185,245,181,95,187,4,249,225,147,63,108,
86,172,110,40,149,74,219,231,230,230,246,142,141,157,27,158,159,47,14,172,44,47,247,174,172,172,244,174,148,203,189,97,24,118,49,179,15,102,15,4,229,123,126,217,15,130,21,0,138,140,67,223,53,70,244,54,
214,93,158,188,248,199,88,158,23,122,107,228,173,159,28,217,151,123,102,231,29,25,111,119,156,249,2,141,145,213,86,102,2,17,51,179,167,162,168,37,82,170,133,153,61,34,40,143,188,90,80,40,44,180,180,180,
78,183,181,182,204,182,109,104,159,237,233,233,153,220,188,121,120,172,187,167,231,205,230,230,230,81,63,240,95,248,224,205,31,140,126,229,27,228,177,199,30,165,143,124,228,14,6,128,239,127,255,7,29,96,
245,129,133,197,197,109,147,147,147,91,206,79,76,12,207,206,204,110,46,46,20,183,85,202,229,190,72,169,118,102,246,2,223,47,117,247,246,150,250,7,55,69,231,206,156,94,184,241,93,55,181,126,224,234,171,
55,23,2,159,34,165,222,246,228,54,106,188,235,90,106,112,216,231,29,106,107,185,87,222,253,208,64,137,115,93,71,171,124,159,215,56,121,141,218,187,218,24,174,167,61,141,230,173,209,1,179,214,69,199,226,
23,207,39,212,194,136,127,240,226,47,71,247,191,248,66,181,111,96,176,189,88,156,47,204,207,205,181,169,40,106,5,81,228,251,254,98,91,219,134,233,142,142,246,145,141,125,125,99,67,155,6,199,250,54,246,
141,182,119,116,140,18,241,211,183,125,232,246,101,0,120,244,177,199,232,142,143,124,132,47,216,6,121,244,145,71,188,59,62,250,81,229,3,244,200,99,143,14,69,138,239,152,60,127,126,248,228,201,147,123,
206,79,156,191,56,98,181,189,180,188,220,89,173,86,10,133,160,176,240,254,91,110,35,128,75,91,134,134,91,46,221,52,208,237,251,1,152,85,162,79,102,143,206,57,114,72,234,253,98,168,8,117,163,50,213,239,
173,149,45,244,34,182,187,167,155,124,13,186,79,166,82,142,244,190,196,198,173,229,179,99,35,95,83,37,196,10,165,180,217,57,234,31,201,231,57,150,154,169,19,26,253,78,255,79,142,235,153,114,183,1,165,
150,142,99,89,80,131,165,235,20,71,164,143,33,199,79,32,243,25,162,77,212,104,43,219,143,86,138,225,121,30,194,40,196,27,231,198,103,79,157,62,93,246,61,127,195,207,127,250,99,10,195,176,61,40,20,106,
157,93,221,69,159,48,50,56,52,116,100,247,238,93,199,7,6,6,206,41,224,241,59,110,255,200,4,0,60,252,200,35,244,177,143,126,148,223,246,6,121,248,225,135,189,143,125,236,99,10,0,30,125,244,145,75,149,82,
183,142,142,142,14,156,60,126,98,223,228,228,212,85,75,203,75,155,153,217,107,110,110,154,190,243,174,143,55,239,24,26,106,219,212,222,94,32,47,235,104,221,246,204,208,169,223,190,126,251,122,203,42,15,
81,138,196,177,4,54,148,194,248,194,82,245,216,232,185,210,19,143,61,20,86,170,213,94,143,40,236,232,236,56,219,215,63,176,255,226,189,123,15,13,109,222,60,3,198,247,63,250,209,59,142,2,192,67,15,61,68,
119,222,121,39,191,229,13,242,208,195,15,123,119,198,155,227,239,238,191,255,221,97,181,250,158,241,241,241,193,51,103,206,92,178,184,184,244,142,165,197,133,158,166,166,166,185,255,233,159,255,81,119,
127,199,134,66,71,107,171,151,194,136,226,212,77,241,24,54,14,65,129,226,32,5,112,76,116,196,161,52,196,131,34,49,155,186,170,154,42,174,54,232,2,210,144,37,253,150,100,156,141,217,135,228,176,98,56,62,
249,82,97,40,238,153,64,182,233,85,228,134,61,97,117,141,5,26,199,58,186,68,201,24,213,223,39,249,94,130,247,176,241,60,54,90,173,9,184,248,154,228,13,202,144,50,78,63,203,87,163,82,220,77,78,168,38,128,
12,233,75,156,163,212,177,64,220,178,126,164,159,145,113,189,68,57,99,137,68,76,150,138,80,92,89,81,231,23,150,170,95,253,219,191,46,86,107,181,238,150,230,230,217,141,125,125,175,110,223,190,253,200,
208,240,240,249,230,230,150,159,222,115,207,39,159,191,96,42,214,151,191,252,229,143,207,206,206,188,103,98,124,98,231,220,220,220,174,149,149,149,225,48,12,91,91,91,91,198,191,244,47,190,176,163,163,
173,149,180,197,155,170,58,244,219,35,239,183,175,95,237,203,216,52,242,181,80,90,81,255,233,191,254,213,232,74,185,188,169,224,251,203,109,237,237,103,123,123,123,79,110,218,180,105,164,127,96,224,39,
159,255,252,231,31,89,247,6,249,246,183,191,77,159,252,228,39,217,7,232,59,15,126,175,149,25,119,156,56,126,252,186,99,199,142,93,59,59,51,123,85,165,82,238,241,125,127,229,138,171,175,157,254,244,45,
31,216,210,84,104,170,239,101,102,16,121,249,167,254,170,230,216,58,55,147,195,159,96,233,246,220,24,130,95,183,217,232,252,186,227,205,220,182,225,2,140,7,55,48,225,223,226,120,179,171,79,148,127,201,
133,236,78,195,113,126,11,235,2,16,206,80,160,86,171,241,87,31,126,228,236,209,55,15,247,171,40,106,105,105,105,153,217,216,183,113,255,222,139,47,121,121,199,142,29,47,19,188,71,238,186,251,206,138,92,
251,185,27,228,91,223,250,22,221,115,207,61,12,0,223,249,246,183,135,65,116,199,248,216,216,230,35,111,30,185,106,102,118,230,198,197,133,133,129,32,8,150,238,254,196,189,213,223,185,104,87,47,17,101,
186,96,14,82,177,150,191,27,193,132,107,241,136,208,42,230,29,161,241,92,175,245,57,141,32,205,213,160,212,183,2,129,174,5,138,93,43,114,132,53,160,99,141,80,190,245,194,222,171,61,123,53,200,154,223,
70,255,216,216,145,42,138,240,15,111,30,155,121,228,193,239,180,70,81,212,214,222,209,49,222,63,48,240,194,190,125,251,246,247,247,247,143,131,241,232,39,62,249,137,137,250,30,248,123,186,231,158,123,
185,161,138,245,173,191,255,214,101,81,20,222,50,54,54,214,127,234,212,169,75,231,230,230,174,89,88,88,24,12,130,96,241,143,255,249,31,109,184,104,160,175,245,31,199,212,126,107,39,200,63,113,157,35,127,
204,126,35,134,243,194,55,50,185,219,145,137,201,210,95,255,205,95,175,132,81,212,190,97,67,251,88,127,127,223,43,123,46,186,232,208,208,208,208,20,192,79,221,115,207,189,135,115,55,237,55,191,249,77,
255,83,159,250,84,244,221,111,127,167,101,97,113,241,79,206,141,141,109,59,61,114,234,178,197,165,197,171,150,22,23,123,154,155,154,167,255,245,159,252,203,129,129,206,246,32,131,82,87,59,227,92,222,83,
199,119,180,99,130,243,189,220,218,223,246,125,82,147,47,207,171,238,108,3,229,67,170,174,231,184,140,210,213,206,74,50,224,226,181,156,187,148,115,222,230,157,109,196,107,56,250,205,113,88,143,108,112,
141,131,57,31,210,64,119,200,56,110,36,47,28,243,64,148,193,249,206,109,180,54,185,159,173,39,194,68,113,33,252,203,47,255,183,233,106,173,218,219,210,220,50,211,211,219,187,127,215,238,221,7,183,110,
221,50,178,161,165,237,43,119,125,226,227,213,251,191,113,63,125,246,51,159,101,0,240,1,224,254,111,220,239,253,254,167,63,195,15,125,255,27,180,82,138,254,217,248,216,248,21,167,78,158,120,71,113,190,
120,221,242,210,82,87,71,103,231,216,255,250,47,254,229,150,158,246,54,255,183,39,244,111,95,191,177,198,60,128,246,230,102,239,134,171,175,110,123,97,255,171,103,203,229,242,96,181,82,238,173,85,171,
81,115,75,243,82,235,134,182,232,187,223,253,238,169,239,125,247,123,233,101,94,114,113,4,240,210,28,111,156,157,153,189,246,220,185,179,59,202,149,202,101,139,139,11,27,155,154,155,103,254,183,63,249,
147,237,237,45,205,196,204,96,165,192,204,191,253,249,237,207,111,214,15,234,14,70,128,209,209,218,234,253,249,159,126,97,123,80,40,204,174,172,148,7,102,102,103,47,57,59,122,118,199,66,113,225,234,251,
239,191,191,71,238,43,255,235,127,247,119,222,231,126,239,247,248,107,95,255,122,103,181,90,189,123,244,204,153,189,99,231,206,93,177,48,95,220,69,68,229,207,124,230,247,154,134,123,186,155,157,170,7,
217,222,92,75,52,154,106,145,196,196,153,214,96,166,231,137,91,7,147,139,217,80,219,28,158,109,214,241,255,92,238,69,158,213,79,14,245,128,243,76,120,131,241,200,249,22,127,221,7,145,125,41,101,13,48,
114,84,23,135,186,73,198,60,200,62,230,106,191,18,146,103,123,110,73,204,149,165,198,153,84,1,249,44,115,12,228,154,48,218,104,170,236,233,239,6,18,200,121,107,98,45,236,199,216,124,143,97,225,192,243,
168,119,243,214,232,141,131,111,68,181,90,181,51,138,84,181,80,40,44,246,244,246,116,220,245,241,59,79,62,248,189,135,170,0,16,68,81,68,17,160,64,94,101,124,108,108,104,98,124,124,23,136,118,213,106,213,
194,174,61,23,77,92,54,188,105,123,178,248,44,250,71,158,30,206,38,197,129,141,107,216,184,134,115,160,90,184,239,9,2,160,242,41,25,90,219,76,253,157,141,127,115,154,146,167,218,54,180,35,114,250,149,
215,45,109,88,216,241,24,94,35,172,196,57,109,19,125,52,237,69,115,124,56,239,58,206,95,160,185,207,114,141,65,206,250,112,181,221,250,189,65,191,25,13,6,22,182,45,200,0,84,4,16,225,202,45,195,93,63,26,
28,60,53,113,238,220,246,165,165,165,93,99,99,99,211,173,109,109,99,59,246,238,42,3,192,223,252,205,223,144,247,249,207,125,78,125,237,255,249,138,87,171,172,92,187,180,180,184,169,180,178,50,60,59,51,
221,217,222,217,57,255,137,15,127,120,139,231,17,88,213,233,34,96,22,63,241,195,228,223,90,195,205,239,178,123,21,38,223,201,64,57,227,250,228,251,242,61,101,60,91,180,71,27,36,99,65,104,109,145,247,53,
6,220,236,27,28,63,156,211,71,173,155,226,122,229,90,16,198,88,201,123,67,140,153,213,71,54,62,131,221,31,206,57,180,172,103,185,250,155,179,144,181,177,128,99,14,28,243,96,13,93,206,51,181,53,194,246,
156,33,239,0,51,158,15,182,159,149,124,71,233,141,243,124,31,191,127,247,199,183,6,65,97,174,90,169,116,47,46,46,14,21,139,197,161,242,66,233,26,0,248,195,63,252,67,246,34,128,85,228,117,46,44,44,190,
123,161,184,208,235,121,126,191,138,84,97,215,158,61,181,193,246,13,126,253,185,10,12,54,250,202,198,123,82,231,203,249,94,28,53,151,253,43,174,151,215,154,215,179,99,92,243,218,99,222,39,125,14,235,215,
105,207,98,189,93,102,223,56,127,29,100,63,202,110,135,54,79,142,103,152,99,149,126,38,255,117,245,209,92,107,108,247,7,198,56,179,163,77,156,215,94,182,231,137,205,177,96,199,28,56,230,193,250,15,142,
191,97,172,17,216,115,38,239,199,121,107,45,57,59,205,107,237,49,86,81,4,86,140,193,142,246,96,215,69,23,213,148,82,77,43,165,149,190,197,133,133,254,165,197,197,155,190,250,213,175,118,0,64,0,0,71,14,
191,89,14,163,168,181,88,44,14,47,45,45,117,122,158,183,220,183,177,191,22,70,17,252,148,19,164,116,21,199,229,226,183,194,250,176,6,209,183,14,79,182,133,219,57,56,62,141,2,30,214,138,185,179,251,214,
246,117,122,228,161,173,42,186,96,106,211,6,131,22,158,187,110,119,190,198,85,194,234,60,253,92,54,0,233,146,79,234,247,230,120,179,176,89,228,231,204,186,253,7,90,187,91,195,228,108,217,100,58,199,220,
195,61,206,174,177,146,97,161,233,208,41,68,81,132,254,129,193,202,209,195,135,150,43,213,74,247,252,252,252,230,179,163,163,135,175,185,226,242,82,186,65,186,123,122,134,71,71,71,7,34,197,195,165,229,
229,13,87,95,119,253,252,45,87,189,99,139,239,251,96,165,28,156,42,118,136,109,147,190,206,235,88,236,111,193,237,200,141,140,7,216,113,178,188,234,141,86,55,41,0,219,96,93,205,30,91,75,155,217,254,124,
117,207,59,187,237,34,206,89,244,171,118,155,117,115,54,157,91,5,39,5,159,185,129,202,216,192,176,110,4,197,48,28,246,234,106,182,33,175,210,55,147,154,47,238,27,41,120,158,135,219,175,191,110,251,244,
212,228,236,193,215,95,235,46,149,74,3,203,165,210,64,113,165,60,4,224,108,112,223,125,247,117,149,150,75,31,97,230,54,21,69,77,204,76,173,173,173,17,121,94,93,181,98,215,233,70,2,176,98,161,170,58,118,
62,140,19,78,54,50,57,165,44,180,196,49,96,68,90,168,185,30,222,96,50,63,205,105,48,46,32,71,92,54,59,196,13,177,219,192,117,157,142,22,96,162,108,199,92,3,161,90,167,236,200,72,116,56,164,76,206,201,
239,148,100,36,116,122,7,202,197,38,234,152,157,204,108,204,85,154,228,194,96,35,219,188,183,188,241,20,90,7,72,60,58,103,93,57,165,155,144,106,228,114,246,186,145,59,50,151,81,186,183,57,189,151,231,
1,173,173,173,53,0,84,171,86,155,192,220,81,169,86,111,255,242,127,251,242,253,129,82,138,39,39,39,187,23,138,11,155,20,184,19,68,181,137,137,137,153,40,12,251,169,80,136,233,207,230,92,100,185,65,178,
172,34,42,94,79,108,123,160,141,22,214,179,90,0,36,213,54,22,11,75,163,139,103,155,128,57,231,32,134,16,239,9,218,166,231,57,129,209,234,120,110,92,8,78,140,40,201,181,205,108,107,46,105,28,2,116,58,118,
186,174,9,96,165,39,95,137,199,133,44,182,80,218,170,116,28,181,244,11,201,80,178,200,62,98,108,165,180,221,108,191,175,177,19,82,88,84,108,96,35,163,73,214,95,25,195,195,2,16,99,3,209,103,67,195,140,
159,23,31,122,172,146,141,150,205,163,150,133,197,152,27,98,61,132,139,140,117,196,44,198,69,74,187,228,30,172,159,195,146,84,175,52,68,187,78,151,143,194,8,19,19,227,51,0,245,68,74,117,23,139,11,155,
38,198,198,55,110,222,186,21,254,158,93,187,219,23,151,22,111,91,92,92,188,106,110,118,118,104,120,203,214,197,63,248,232,29,91,90,155,91,104,173,154,200,219,163,221,184,236,7,227,61,110,164,84,211,91,
120,232,42,230,8,191,13,110,16,175,245,178,53,168,64,180,26,235,118,237,102,213,219,159,167,213,188,212,180,134,231,174,194,18,198,42,54,210,26,76,178,117,63,59,70,179,46,217,181,107,227,129,99,199,138,
139,197,133,46,242,168,236,251,254,88,255,224,192,79,131,114,165,76,97,20,249,228,121,45,172,148,191,99,251,14,238,108,109,245,88,131,38,243,245,201,134,190,153,181,80,123,216,213,75,206,215,207,169,145,
24,65,254,131,200,177,240,77,142,148,118,232,202,24,217,134,94,195,252,14,154,125,163,85,108,21,151,211,149,57,223,49,152,55,192,102,48,24,27,28,42,94,7,239,89,72,47,103,104,48,229,248,149,200,86,173,
234,247,99,183,219,66,115,14,154,107,15,57,115,104,240,188,86,163,216,145,205,7,99,165,64,4,116,182,182,120,59,247,236,137,166,38,207,251,81,24,54,71,97,24,64,69,8,130,160,192,181,90,13,172,88,49,160,
170,181,90,20,70,17,2,34,139,10,200,142,211,140,164,206,234,80,105,217,49,24,137,88,214,17,17,232,209,126,171,158,236,200,69,175,200,80,60,76,27,68,215,75,217,182,125,18,127,12,235,237,170,219,62,117,
177,204,4,103,67,179,241,96,45,60,155,197,253,136,133,26,103,216,116,153,47,8,134,161,149,183,177,84,189,61,112,157,196,156,179,198,88,11,216,211,218,40,162,29,83,33,198,0,72,101,138,138,50,116,24,80,
58,54,230,124,72,229,81,147,54,38,221,80,182,87,33,75,42,71,110,251,157,156,49,238,186,45,76,38,86,195,186,100,174,39,198,83,96,170,171,89,213,106,53,4,160,152,25,42,254,9,52,92,89,41,170,59,5,51,92,92,
207,83,102,34,29,16,89,8,51,195,146,147,132,107,204,58,189,132,69,88,41,50,221,54,201,42,168,233,244,241,61,200,229,120,213,80,72,214,147,14,164,7,154,52,246,227,231,196,25,6,217,105,104,203,147,208,145,
20,43,54,186,217,98,20,212,237,17,214,132,134,161,255,107,134,163,152,86,69,113,155,84,14,220,172,52,56,213,6,9,147,208,227,152,158,162,88,79,218,32,78,120,138,109,135,122,55,164,173,38,114,7,36,33,188,
12,40,73,27,1,210,108,136,169,45,1,128,83,133,94,217,134,176,1,56,144,12,87,22,115,150,216,1,108,156,174,28,247,159,29,0,0,37,62,63,114,156,160,82,242,147,203,223,41,15,102,164,27,190,206,213,82,196,204,
241,114,100,176,98,4,74,69,80,194,41,163,132,243,197,45,222,145,99,2,234,198,150,13,245,233,240,157,243,122,182,141,177,134,106,111,67,205,207,254,128,57,7,47,204,131,60,93,198,187,227,2,134,97,156,58,
79,52,55,28,44,17,64,183,203,133,29,163,236,166,224,112,3,120,148,13,35,218,124,211,250,191,53,4,172,255,109,24,200,148,179,26,216,212,12,27,205,191,213,54,247,223,156,11,155,235,253,231,92,152,152,173,
207,189,228,208,136,127,20,43,132,28,33,72,96,92,142,93,152,204,170,190,115,213,91,79,109,122,33,237,249,223,196,28,40,252,255,241,254,174,37,167,216,170,174,94,113,24,48,51,162,48,132,82,170,238,161,
78,88,223,9,243,91,197,44,131,100,77,165,82,152,45,20,202,181,241,87,119,160,228,64,203,142,156,8,105,218,41,202,212,59,207,247,17,69,17,106,181,144,147,118,177,138,37,8,226,142,128,89,211,22,153,127,
67,211,243,16,161,173,163,3,205,109,173,240,11,5,4,65,161,174,205,68,17,194,48,66,117,101,5,213,242,10,170,229,50,240,155,218,199,245,13,8,76,54,109,10,52,115,150,60,59,61,217,149,66,84,11,17,134,33,162,
168,6,21,70,80,145,170,171,129,81,125,173,40,145,44,155,21,199,38,137,74,23,86,202,154,117,4,150,165,0,50,177,230,194,146,234,174,150,206,71,228,128,113,185,209,76,155,139,37,32,34,236,21,196,108,233,
52,172,46,86,227,147,174,43,98,40,21,165,48,52,51,67,133,17,2,139,171,147,236,124,207,107,52,220,191,206,169,182,89,36,158,135,158,193,65,244,109,217,130,246,158,30,120,254,234,113,93,42,138,80,42,22,
177,188,176,128,197,217,89,44,204,204,64,133,225,186,59,250,118,227,206,215,118,228,115,195,83,81,255,42,235,39,183,184,54,170,213,16,86,171,8,107,53,168,40,74,127,56,213,32,18,223,0,95,32,137,150,75,
135,118,112,34,217,48,238,179,67,154,45,127,79,236,201,201,77,61,204,185,247,103,67,229,229,196,231,194,137,121,193,218,191,129,82,153,197,14,65,78,203,75,242,246,235,60,115,93,22,64,247,224,32,182,239,
219,135,66,75,139,182,72,86,93,216,158,135,13,61,61,216,208,211,131,129,237,219,193,74,97,250,236,89,156,62,120,112,213,142,14,108,219,134,160,169,89,179,13,199,142,31,187,48,99,179,6,159,131,10,67,68,
81,4,86,81,253,68,143,213,228,168,86,69,88,173,33,12,67,168,90,13,74,69,241,92,154,225,176,148,255,40,118,37,165,140,203,66,16,178,205,99,64,96,201,233,92,47,167,192,13,142,52,210,195,78,44,63,138,116,
66,147,6,216,104,54,143,69,32,48,12,111,19,149,100,78,203,55,144,149,107,139,53,146,38,80,223,15,17,24,129,98,5,197,42,219,57,148,72,19,245,43,157,103,189,104,128,227,186,53,56,128,182,95,126,57,250,183,
109,187,48,210,201,243,208,218,209,33,96,200,28,195,153,128,254,237,219,209,218,222,174,93,127,238,216,49,189,92,128,107,32,214,42,98,24,136,194,16,97,181,154,234,246,137,26,28,214,106,168,213,106,245,
13,16,133,176,74,29,184,184,140,169,135,218,62,230,56,111,102,152,12,240,90,247,240,187,98,85,52,228,41,133,171,77,7,1,231,224,40,44,128,39,233,229,71,86,115,5,57,182,60,219,146,137,114,64,26,201,164,
128,133,124,114,102,43,197,234,103,192,113,224,81,106,172,43,185,147,168,129,181,38,34,191,200,237,147,96,130,206,147,178,8,50,230,105,197,6,83,197,56,129,4,33,114,199,59,174,192,64,206,230,8,171,85,44,
205,207,163,188,180,148,170,19,65,161,128,160,80,64,75,71,7,218,186,186,16,4,65,3,41,165,59,7,217,108,131,200,187,36,253,17,172,195,59,14,209,103,239,144,176,86,69,173,82,69,88,173,32,10,163,84,197,141,
194,26,162,90,84,215,139,115,216,193,36,33,227,244,132,20,207,74,78,84,22,185,113,117,254,142,78,50,37,93,85,75,78,217,4,134,102,43,227,35,12,103,33,114,120,120,134,154,36,185,119,102,214,201,116,61,41,
205,217,202,166,131,83,174,61,45,56,85,207,214,104,114,251,216,114,38,214,191,175,80,15,201,77,81,44,165,160,34,133,160,14,90,169,56,230,67,143,215,176,58,212,8,109,96,210,61,224,9,221,199,228,251,56,
163,253,200,13,79,166,206,22,253,218,190,45,91,208,191,117,171,165,74,149,138,69,156,61,114,4,243,83,83,150,67,10,134,31,167,173,163,19,189,67,67,232,29,26,66,75,34,13,98,189,221,238,171,173,220,153,207,
102,229,82,0,41,13,19,80,138,235,0,193,74,169,190,105,195,176,46,177,163,8,145,82,128,82,48,60,139,58,0,74,108,113,56,53,135,35,75,102,74,236,155,208,2,183,50,227,152,149,48,178,235,78,143,186,209,172,
204,168,195,108,78,235,14,82,157,151,198,98,227,19,153,129,90,38,249,212,224,93,37,27,58,254,190,54,83,146,79,231,100,92,216,48,112,194,239,170,183,207,224,113,177,157,45,43,219,255,148,106,75,41,146,
27,255,23,41,133,64,69,42,53,74,98,241,81,23,147,236,235,119,115,102,197,209,35,191,178,146,105,208,35,247,152,161,39,101,167,124,250,128,60,165,148,177,225,98,72,110,235,165,151,90,39,248,196,201,147,
24,121,227,160,197,230,37,176,214,78,74,55,211,2,150,23,138,24,61,242,38,58,122,122,177,105,215,46,20,154,154,116,255,143,35,10,50,57,155,146,231,39,27,37,170,133,169,206,207,172,80,41,173,160,186,178,
130,90,181,2,21,70,41,106,164,243,26,99,125,61,77,196,172,172,10,91,117,39,164,25,111,146,76,137,220,248,9,28,3,29,201,97,121,90,37,88,191,200,199,43,29,159,73,249,57,202,74,171,65,72,115,205,17,108,120,
140,229,70,214,88,0,41,109,68,200,87,162,204,192,38,149,222,187,254,24,101,248,243,178,195,147,96,4,2,8,86,47,49,65,213,93,240,194,65,109,248,243,36,193,25,186,163,148,227,254,166,2,66,49,56,140,16,40,
35,10,79,110,22,206,227,13,37,13,55,79,81,202,11,125,53,217,228,236,140,129,104,136,129,199,19,221,51,60,136,66,115,179,118,130,207,79,78,226,212,129,3,206,251,89,76,23,201,63,136,63,92,152,153,193,194,
204,12,252,66,96,249,127,92,204,23,22,248,125,146,109,124,250,220,89,212,42,149,85,253,71,44,194,233,51,218,7,91,18,71,155,80,98,61,4,63,199,11,200,14,233,206,154,149,146,88,3,202,246,191,101,34,63,27,
91,235,244,54,180,4,231,0,231,57,97,197,145,202,238,88,22,183,31,215,225,8,117,72,149,76,165,98,99,99,58,236,90,13,239,82,144,231,185,100,150,40,86,8,160,68,24,98,226,32,97,118,123,210,115,26,190,22,136,
203,237,97,94,47,54,198,232,25,220,100,189,123,246,200,145,181,251,52,26,124,45,170,214,44,56,149,153,81,45,151,81,171,84,82,88,52,170,213,180,252,175,68,132,74,169,212,216,219,150,83,155,208,57,48,102,
173,70,133,117,49,116,9,54,187,65,232,54,246,188,228,5,173,89,193,87,220,32,186,114,181,97,231,53,19,116,87,117,95,42,52,200,179,108,174,81,178,135,208,96,74,115,106,90,42,45,204,88,65,33,80,177,74,160,
233,95,169,71,93,31,117,18,39,185,25,58,147,162,21,90,229,3,74,165,138,21,23,147,250,129,40,7,211,202,120,92,89,125,17,70,91,87,151,166,94,133,181,26,150,102,102,244,56,25,33,154,211,122,18,214,169,12,
157,176,151,244,139,35,148,151,151,81,93,89,65,84,139,16,133,117,223,65,20,133,98,253,218,70,186,102,179,153,107,93,142,87,142,116,37,67,100,233,239,113,170,26,56,104,126,246,242,112,196,123,17,187,237,
242,58,124,43,217,179,100,197,183,144,185,192,217,124,151,13,214,21,187,113,157,84,205,142,29,116,138,157,72,176,84,163,108,252,32,46,109,161,204,253,64,26,138,168,149,198,16,206,81,201,55,147,237,79,
99,109,82,70,73,125,49,5,12,37,252,30,194,80,81,246,142,207,229,216,200,110,73,179,68,44,8,101,104,88,72,199,135,13,242,162,9,55,234,16,92,161,169,73,83,175,106,229,50,20,179,174,181,177,205,239,98,137,
190,136,224,171,40,140,176,178,184,136,242,242,114,29,82,173,133,8,163,208,73,67,230,6,71,94,66,167,128,3,157,150,253,82,134,103,152,28,135,181,92,242,205,27,218,209,187,105,16,45,27,54,160,169,173,13,
204,140,202,242,50,202,203,203,152,29,27,67,181,92,142,15,34,27,234,213,236,88,227,97,202,112,170,105,20,82,51,63,87,252,221,66,91,27,54,14,15,163,189,187,27,65,83,83,221,217,186,176,128,153,177,49,44,
23,139,90,160,150,202,233,91,186,148,89,10,180,152,185,235,128,165,153,28,73,161,216,14,30,101,129,226,145,101,57,234,136,100,130,71,144,54,59,118,178,57,21,41,4,245,236,14,42,150,24,49,188,197,12,95,
163,47,59,24,174,108,120,118,147,239,27,113,3,12,59,137,156,100,183,166,188,78,114,28,129,44,79,157,250,179,253,66,65,59,189,61,223,143,55,79,108,148,169,132,113,74,194,200,3,162,176,86,247,39,68,17,42,
203,203,88,89,94,66,173,34,36,67,226,68,210,112,130,172,110,250,167,255,195,127,104,168,0,220,251,239,255,253,170,74,194,3,255,199,255,153,82,253,89,158,38,70,130,56,191,208,132,139,111,188,17,91,47,185,
4,61,131,131,249,108,0,165,48,115,246,28,70,14,189,129,19,251,247,131,35,165,133,30,39,144,105,186,208,20,167,146,56,113,232,41,16,62,253,231,127,174,221,183,56,53,133,39,238,187,47,149,190,131,59,119,
98,223,77,55,97,96,251,118,7,188,93,127,205,142,143,227,240,115,207,97,244,240,161,84,68,41,8,199,162,160,127,168,68,162,11,176,130,137,181,3,145,137,28,7,44,105,49,215,12,147,37,158,132,34,232,200,85,
6,36,212,209,54,21,55,142,133,136,205,50,201,196,142,115,165,192,145,66,144,48,120,149,32,44,38,71,78,194,171,209,50,86,88,48,160,178,179,20,106,92,0,195,168,34,56,114,57,145,238,87,73,49,75,100,91,61,
190,38,172,86,81,104,206,18,61,54,181,182,34,104,110,70,173,92,17,196,27,66,164,20,106,149,114,236,112,171,161,188,180,132,74,169,148,110,180,186,71,85,108,76,1,113,214,105,225,148,197,219,95,168,8,61,
86,25,160,195,108,57,186,8,192,158,107,175,199,21,239,125,15,90,218,218,86,189,157,231,121,232,223,182,21,253,219,182,226,146,27,110,196,203,79,62,137,177,227,199,83,175,50,75,136,147,117,184,221,218,
164,38,93,133,25,228,17,174,191,253,118,236,190,234,234,85,219,210,59,52,132,155,238,190,27,99,39,174,196,115,15,61,136,106,105,37,9,102,72,231,147,148,196,2,89,100,147,76,156,144,36,96,107,185,9,12,245,
56,166,195,36,97,205,250,186,84,117,48,16,114,3,100,78,66,149,160,170,178,235,164,167,130,66,106,164,71,117,79,122,102,181,235,124,20,167,177,198,134,159,153,77,238,11,91,255,144,195,165,64,46,127,110,
94,118,14,113,125,101,121,89,219,32,0,48,188,103,15,70,222,120,3,213,149,50,170,43,43,117,111,115,185,140,74,169,4,229,66,149,114,60,175,108,44,216,84,213,80,23,102,127,36,116,30,87,213,118,34,15,215,
223,254,97,236,185,230,154,183,116,239,142,222,94,188,247,83,159,194,203,79,62,137,35,47,190,232,80,240,28,182,202,42,184,198,187,63,121,15,54,95,116,209,186,218,49,188,123,55,110,254,220,31,224,169,175,
125,13,229,229,101,219,91,173,217,94,14,132,202,212,165,96,115,179,50,181,81,198,215,235,129,136,236,8,101,72,75,253,37,27,5,122,185,58,25,11,165,56,246,131,104,252,171,216,30,97,112,28,138,72,206,72,
198,60,23,26,229,32,42,107,1,147,26,150,46,22,155,101,126,106,10,237,189,189,90,49,199,45,23,95,140,153,115,231,112,232,133,23,160,170,85,36,153,51,200,145,229,68,26,252,9,139,53,77,20,208,160,163,213,
114,57,253,189,208,212,4,50,200,156,242,243,70,118,74,18,224,36,13,109,6,240,187,119,125,12,59,175,184,194,121,221,252,228,36,206,159,30,193,202,226,18,60,207,67,91,103,39,134,118,239,193,134,174,78,125,
172,137,112,221,109,183,193,243,125,28,250,197,179,118,190,45,45,117,46,53,100,190,188,227,125,239,211,54,135,82,10,19,39,79,97,254,252,4,202,43,37,180,180,181,161,103,112,19,6,119,238,132,103,140,69,
87,95,31,222,247,233,79,227,251,95,249,10,152,149,0,11,40,86,185,114,114,250,154,250,187,86,223,210,4,0,50,80,200,218,128,36,212,45,206,152,195,217,247,100,110,172,12,18,80,208,129,170,136,9,65,202,248,
20,116,19,164,132,173,252,13,225,250,123,189,100,61,94,199,231,137,161,62,126,226,4,182,92,124,177,230,172,35,34,92,245,129,15,96,219,190,125,56,242,226,139,56,115,248,48,170,43,43,206,82,210,218,201,
197,134,241,220,160,51,223,252,139,191,72,167,239,142,47,124,1,221,3,3,218,231,127,255,23,127,177,54,198,25,219,80,199,158,107,174,113,110,142,217,241,113,188,240,232,163,152,62,119,206,57,54,219,46,185,
4,55,220,126,59,218,58,245,141,114,213,251,223,143,243,167,70,48,125,238,172,83,138,107,188,35,71,155,219,58,59,177,239,166,155,210,191,207,28,62,140,23,31,127,28,165,197,69,43,127,91,75,71,7,110,188,
253,118,108,187,244,82,237,30,27,135,135,113,249,77,55,225,245,103,158,177,252,50,86,188,97,14,71,140,44,63,8,91,165,188,157,232,62,115,195,239,176,165,9,233,145,133,28,211,254,161,162,4,230,205,236,143,
58,49,46,83,47,248,2,44,244,85,175,151,207,18,28,157,196,239,16,86,42,88,42,206,99,101,185,4,85,11,49,184,115,39,182,239,219,231,212,131,223,249,177,143,225,198,59,238,192,236,248,56,166,70,71,49,53,122,
22,51,99,103,177,48,61,99,224,213,121,131,106,122,250,201,70,213,216,101,48,187,168,6,108,240,205,116,47,51,17,163,181,163,3,215,125,232,67,14,223,206,81,252,244,129,7,160,84,40,128,14,189,56,234,233,
67,135,48,49,114,26,31,250,163,207,163,171,191,95,3,46,110,250,248,221,120,232,191,252,223,245,24,14,18,236,88,100,241,220,196,112,34,115,77,130,25,125,232,217,95,224,151,63,120,50,195,151,12,202,93,169,
88,196,79,30,120,0,215,223,118,27,246,189,235,93,218,125,174,120,239,123,113,242,245,215,177,56,55,107,100,175,151,33,217,50,147,61,139,220,13,36,24,194,137,169,64,49,227,77,134,237,146,46,128,4,19,131,
13,2,22,145,93,167,158,53,138,157,8,247,80,140,40,226,186,4,81,74,105,28,172,212,96,255,21,191,92,254,132,176,90,69,173,82,65,88,171,161,84,44,98,101,105,201,186,238,23,15,62,136,158,193,65,116,110,220,
152,107,188,246,109,222,140,190,205,155,113,233,239,100,42,208,228,153,51,152,56,117,10,99,199,143,99,118,124,92,83,77,216,193,189,34,129,158,233,42,173,203,176,85,13,78,13,179,68,66,70,167,184,248,134,
27,81,104,106,178,84,170,159,60,240,13,68,105,124,74,126,166,244,242,242,18,158,252,219,191,197,93,127,246,103,154,109,56,229,181,63,0,0,32,0,73,68,65,84,214,185,113,35,182,93,186,15,35,7,14,88,89,16,
217,200,69,149,247,26,59,126,28,47,62,241,125,88,110,117,182,15,151,23,159,120,2,221,131,131,24,222,189,59,125,219,15,2,92,124,227,141,248,229,19,79,24,71,45,59,18,67,218,160,133,109,150,186,194,182,29,
33,184,236,214,115,216,136,184,50,67,139,21,179,230,162,80,204,240,148,72,150,172,28,193,83,9,213,90,37,132,70,230,58,235,81,137,239,43,78,191,167,223,71,165,59,50,185,134,5,181,62,217,36,181,106,5,139,
115,179,152,29,31,199,249,145,17,76,156,60,137,233,179,103,177,188,176,144,62,47,123,190,66,165,180,140,239,255,245,87,48,53,58,186,230,205,216,212,210,130,45,123,247,226,186,91,111,197,71,191,240,5,220,
249,103,255,51,246,189,235,93,240,3,191,206,161,18,247,231,24,234,78,153,5,81,189,221,9,160,225,182,47,178,184,26,37,238,163,37,193,80,10,204,81,250,61,207,243,177,247,250,235,173,123,61,251,208,67,8,
171,181,108,108,211,177,20,99,161,178,177,95,158,159,195,43,63,122,202,186,207,190,119,190,83,204,167,74,195,72,147,254,49,43,55,136,17,219,28,207,63,246,152,120,126,36,230,87,137,54,168,244,158,207,63,
250,168,117,191,61,87,93,5,207,243,181,147,153,197,186,145,5,153,234,161,23,177,171,33,153,15,241,29,109,92,173,113,86,218,122,205,158,163,226,246,178,232,127,198,216,77,190,43,215,119,189,207,10,10,33,
60,136,5,161,199,166,235,193,248,36,79,125,233,21,142,105,145,154,7,93,164,161,215,53,200,44,40,43,170,213,80,156,158,198,228,233,211,152,56,121,10,83,103,206,98,110,114,50,133,98,101,84,28,132,243,50,
249,89,158,47,226,241,251,238,195,139,79,60,17,163,37,235,123,117,15,12,226,134,15,127,24,31,255,55,255,11,118,190,227,74,131,106,3,36,161,200,117,71,106,125,16,17,79,150,91,26,198,140,92,165,226,239,
37,152,186,50,226,179,99,82,168,82,24,216,177,221,130,115,167,70,71,49,113,234,20,24,42,246,73,213,191,171,68,190,128,58,216,160,178,77,173,128,55,95,120,222,2,10,6,182,109,67,75,91,91,252,124,100,7,0,
115,214,198,156,13,63,126,252,56,230,207,159,215,55,58,148,62,31,201,194,139,215,203,252,249,243,24,63,113,66,187,79,115,91,27,54,237,220,97,108,212,100,205,213,97,111,22,241,46,80,42,19,84,34,244,130,
229,184,10,166,135,233,220,131,245,156,24,218,226,120,46,33,222,79,181,38,165,85,146,72,109,148,144,17,36,19,9,35,109,189,174,147,155,104,108,94,226,226,60,120,45,62,149,162,8,75,197,34,150,139,69,132,
177,26,165,89,124,150,170,147,175,210,32,134,225,14,60,243,12,222,124,254,121,236,188,242,74,236,185,250,106,108,218,185,51,215,153,133,28,131,244,125,247,222,139,129,173,91,241,252,163,143,230,82,70,
86,35,16,153,16,164,140,120,179,168,67,113,206,26,87,60,203,177,87,94,73,65,19,19,149,230,6,92,182,176,166,112,234,192,1,92,108,72,164,254,109,219,226,40,201,181,20,153,201,94,39,95,127,221,8,121,69,131,
60,225,217,27,39,95,123,205,130,134,251,182,110,197,232,145,35,185,6,168,178,200,132,107,205,126,185,118,14,95,62,198,205,41,72,163,101,53,81,140,72,161,30,114,155,156,202,146,135,194,171,101,82,116,186,
22,140,10,173,74,161,86,173,162,92,42,97,121,110,46,115,212,193,230,220,128,221,220,62,23,31,199,92,166,149,114,25,71,94,120,1,111,190,240,2,154,91,91,177,105,215,46,12,237,220,137,129,109,219,176,113,
120,24,129,161,227,187,94,251,222,245,46,40,102,60,247,240,195,171,212,112,119,91,233,82,181,104,20,47,45,123,223,191,117,171,245,249,196,169,83,154,148,90,75,129,186,228,253,137,147,39,173,13,50,176,
109,27,70,14,28,104,24,4,235,122,157,63,125,58,165,207,80,254,222,176,142,139,243,167,79,91,247,234,223,178,197,26,31,147,111,181,86,87,147,171,152,239,26,106,22,55,252,110,118,110,41,77,2,41,138,98,46,
150,82,218,198,96,145,157,194,202,130,110,230,148,117,28,168,213,82,61,115,200,114,177,136,229,197,197,88,86,146,59,243,159,25,39,237,216,9,38,185,149,141,239,201,1,46,47,47,99,228,192,27,24,121,227,141,
116,175,118,15,12,98,211,142,29,24,222,179,7,219,246,237,179,140,226,228,117,249,77,55,225,220,177,99,56,125,240,160,197,3,74,29,135,57,233,116,57,246,232,234,233,178,205,197,165,111,237,246,238,110,125,
130,162,8,179,99,227,186,147,86,196,45,152,4,188,132,13,160,98,120,102,202,1,7,111,232,234,74,29,148,117,143,49,25,190,56,187,55,81,24,98,238,252,68,198,188,39,87,38,48,189,175,137,135,98,110,242,60,84,
20,105,137,51,218,123,122,226,77,79,105,110,192,140,129,97,140,139,203,77,2,105,144,103,217,41,147,181,33,51,58,106,9,202,53,122,138,141,149,88,97,12,202,228,98,133,73,210,6,100,201,227,18,87,187,171,
254,27,187,74,168,213,87,97,88,169,96,101,113,9,229,210,50,150,23,138,80,161,178,183,187,89,179,35,101,170,176,30,72,175,132,36,138,179,247,177,114,240,150,140,73,119,81,89,24,140,217,137,113,204,78,76,
224,208,243,207,33,40,52,97,239,117,215,227,154,15,222,140,13,134,255,0,0,174,187,229,22,140,28,120,35,102,209,176,112,168,37,109,67,67,21,139,5,115,40,229,248,144,136,108,163,108,57,52,183,182,106,247,
168,148,74,117,110,152,81,240,82,79,198,199,90,36,50,11,38,98,169,184,96,131,19,173,173,25,133,72,171,237,72,122,170,80,217,142,149,149,186,109,1,56,226,208,41,205,71,202,130,38,156,0,61,196,140,202,202,
138,22,179,223,220,218,170,249,94,116,52,139,29,8,153,30,35,203,90,146,133,56,233,80,26,3,198,122,74,81,38,131,67,104,80,182,217,85,186,161,62,207,9,155,36,49,224,163,72,213,19,199,105,145,84,2,97,208,
203,73,72,154,112,214,136,229,249,121,44,23,23,80,41,45,163,86,173,232,249,100,53,50,158,232,24,219,210,169,158,44,155,28,27,146,69,224,143,144,21,121,81,136,137,211,211,164,120,199,199,78,173,82,193,
193,95,252,3,78,188,250,42,110,249,131,207,105,176,100,226,224,26,220,185,3,19,39,79,165,252,41,150,37,24,242,146,140,43,214,253,38,44,206,188,52,151,175,74,251,200,68,104,54,12,244,106,165,108,167,186,
97,22,185,119,89,36,146,206,62,79,214,88,165,92,178,218,213,28,27,233,245,195,70,9,218,28,35,103,127,160,170,49,164,57,79,100,234,133,90,68,90,217,106,185,172,109,144,250,38,21,249,134,205,10,200,38,252,
203,70,49,143,52,37,173,210,73,136,48,34,38,149,30,57,153,240,234,72,177,6,177,115,44,121,147,117,153,216,190,90,221,144,248,209,41,221,157,13,35,5,130,188,165,229,40,34,66,88,173,96,97,122,26,203,11,
11,168,86,42,122,210,105,7,135,70,130,206,202,8,39,213,133,54,55,174,73,99,32,99,89,237,14,71,221,12,54,43,142,177,198,145,44,45,47,226,137,175,124,5,159,250,210,151,44,85,103,120,247,110,140,157,56,225,
44,190,162,23,1,213,121,86,102,45,17,233,55,38,129,219,231,169,54,72,176,120,163,30,137,50,66,134,83,5,203,56,221,89,121,110,35,152,217,78,225,9,147,109,107,25,85,57,21,219,132,100,113,132,0,82,163,241,
225,28,191,133,56,44,221,69,202,18,7,45,197,233,21,140,61,68,186,182,67,108,134,38,155,233,55,56,75,194,77,122,93,72,176,14,1,7,74,115,20,102,216,56,139,120,112,6,234,198,246,210,18,138,51,51,168,36,176,
170,96,223,74,115,75,147,60,89,46,59,163,74,81,22,228,98,150,116,81,134,41,73,100,58,183,244,92,228,172,5,233,187,75,12,234,147,93,127,167,90,42,225,213,167,159,198,239,222,125,183,142,186,108,222,156,
158,182,105,156,54,244,98,145,78,27,132,97,37,132,206,188,181,198,125,136,80,46,149,52,53,175,208,210,146,178,83,21,235,189,133,172,228,69,110,127,157,73,226,4,128,114,169,84,231,213,137,235,148,49,15,
150,90,214,220,156,26,213,206,177,39,54,107,238,104,90,111,147,169,58,174,172,196,84,124,189,221,36,110,206,182,226,163,171,225,32,48,137,211,223,236,129,51,224,74,176,50,136,117,1,44,19,212,147,40,196,
170,33,89,33,2,142,148,86,33,85,69,10,228,251,245,69,23,69,88,89,94,70,41,206,62,168,162,200,73,17,33,7,28,155,70,192,81,154,195,219,102,81,194,53,56,108,148,248,50,184,255,110,160,89,168,172,122,40,37,
57,205,134,236,110,35,7,15,90,27,164,101,195,134,204,176,181,194,196,168,129,138,101,224,232,164,143,83,38,13,234,11,163,98,108,144,186,202,69,217,226,20,79,53,243,64,185,80,168,22,35,87,87,98,215,200,
26,247,150,247,217,241,74,85,63,86,80,76,6,202,196,86,228,173,36,156,147,231,217,27,36,65,47,89,75,74,159,133,118,55,64,251,136,77,254,148,92,67,57,193,88,102,157,195,120,115,40,91,193,209,237,44,17,110,
94,55,210,129,32,50,74,236,130,8,149,229,37,172,132,10,197,169,169,152,234,97,0,251,46,22,133,40,10,34,19,229,41,165,35,47,76,236,240,112,100,49,11,90,96,190,233,99,16,249,92,205,117,154,137,77,93,47,
99,101,232,92,178,98,5,1,11,115,179,86,151,130,66,83,172,183,103,143,77,78,221,124,27,68,165,81,139,196,166,170,157,196,33,136,132,106,68,88,156,155,67,239,166,44,198,222,247,125,244,108,26,196,244,185,
49,3,113,49,243,87,9,101,77,196,209,244,109,222,108,181,107,113,110,174,190,225,200,81,72,71,107,19,52,138,72,119,255,0,102,39,38,82,80,32,149,212,90,32,146,94,105,151,25,232,217,52,8,223,72,253,186,56,
59,155,198,194,80,108,207,178,51,75,146,76,185,232,174,135,200,50,80,207,234,15,185,143,78,25,135,66,86,124,175,200,125,147,161,184,138,25,138,20,2,18,86,59,152,81,41,151,121,226,212,8,162,90,205,197,
40,92,141,113,184,122,145,210,156,242,166,202,228,5,241,42,172,72,110,228,246,50,42,179,230,5,65,48,224,145,173,183,175,44,47,105,206,58,237,212,101,206,13,50,178,249,68,182,239,67,142,215,196,201,147,
216,110,176,96,55,237,216,137,169,209,179,46,39,147,99,108,117,177,50,180,115,167,237,17,63,113,66,107,219,26,39,4,131,59,182,99,102,124,204,49,151,238,236,51,201,112,13,110,219,110,251,118,70,70,82,50,
103,67,187,39,175,82,110,163,245,134,245,56,14,57,231,123,89,233,15,205,59,175,84,166,98,33,70,178,162,40,66,181,82,133,39,10,29,2,36,4,8,11,68,139,116,168,217,149,39,140,140,76,176,86,160,135,200,95,
100,248,88,228,245,236,168,72,68,48,217,161,153,209,150,218,60,233,45,89,75,58,145,180,219,69,120,44,21,23,160,20,103,25,200,147,231,114,226,181,14,109,7,20,121,245,84,160,178,18,171,145,197,144,101,5,
42,48,198,78,28,183,238,115,201,13,55,224,181,159,253,44,203,72,46,193,1,202,241,71,81,253,212,191,200,17,108,53,118,226,4,84,106,131,144,27,253,112,188,46,186,230,26,28,124,246,89,88,241,226,150,215,
86,103,207,94,116,237,181,110,231,39,103,57,225,149,209,167,52,193,134,140,15,214,188,154,13,234,167,35,131,187,137,200,2,125,204,236,139,154,177,158,192,238,73,226,16,37,162,106,149,2,135,92,87,177,148,
70,24,227,152,7,100,236,48,87,1,18,71,244,160,171,100,56,175,230,242,111,196,148,205,73,22,1,7,66,149,85,12,114,51,61,93,237,216,125,181,29,78,58,62,114,42,43,129,109,24,200,4,160,90,94,177,174,41,180,
52,99,101,169,150,95,0,198,192,181,0,96,244,232,49,172,44,45,105,144,232,208,174,93,216,180,99,7,198,79,157,202,209,179,225,172,81,126,197,59,223,105,193,198,99,39,78,96,169,88,180,153,14,107,96,156,108,
189,228,18,116,15,8,53,171,129,43,44,121,179,119,104,8,91,227,88,29,8,199,237,233,195,135,99,9,194,57,233,208,88,179,51,220,245,41,243,43,38,17,55,42,217,33,252,53,202,81,184,135,165,157,39,212,171,152,
12,233,213,61,35,208,56,88,136,204,12,15,74,255,215,100,70,26,40,152,245,187,36,153,41,65,178,179,158,161,179,48,173,103,177,194,221,95,252,34,54,237,220,169,125,71,25,76,85,171,77,74,144,243,196,119,
58,122,122,113,205,251,223,111,13,233,137,215,94,213,88,163,16,76,95,165,148,147,130,223,213,223,111,16,8,149,99,60,88,99,158,134,181,26,94,255,249,207,173,123,189,255,51,159,65,189,78,125,206,245,114,
108,88,161,173,179,19,239,250,216,199,172,251,188,242,227,167,140,113,181,199,52,79,117,246,60,15,239,187,247,158,84,179,176,200,134,41,129,52,187,231,63,187,231,30,43,186,240,208,115,207,215,153,201,
74,103,240,194,57,46,236,152,127,165,145,44,93,235,71,229,172,157,20,161,85,145,96,30,139,57,53,215,165,244,5,198,215,122,10,9,141,27,113,2,95,133,72,210,140,229,130,83,156,50,76,51,250,183,178,216,147,
230,117,105,6,121,99,209,202,197,34,55,129,190,200,149,54,201,219,47,189,20,159,254,210,151,112,247,23,191,136,237,151,238,203,88,190,174,69,41,238,31,177,62,208,93,125,27,241,137,127,243,175,45,104,116,
228,224,65,20,167,103,180,129,83,6,77,250,252,153,51,214,130,218,125,229,149,218,34,80,50,248,76,25,140,94,177,40,94,125,250,233,186,47,73,242,167,182,110,197,237,127,252,199,153,216,87,108,49,130,147,
177,105,110,109,195,221,95,252,162,197,10,158,155,156,196,209,151,95,49,198,213,30,83,213,32,19,228,246,75,247,225,61,159,248,164,70,37,87,202,8,133,136,199,251,189,159,252,132,21,85,24,133,33,246,63,
253,99,45,140,64,15,153,48,199,69,57,230,159,197,248,231,173,31,125,243,166,247,150,73,224,228,6,146,116,127,54,198,53,245,11,162,78,86,148,19,70,130,139,165,28,177,102,108,100,1,228,60,158,139,67,189,
229,134,166,147,30,150,234,42,124,107,54,102,199,190,125,216,177,111,31,150,230,231,113,232,185,231,112,236,213,87,49,121,122,4,97,24,193,161,137,166,175,206,222,94,188,227,61,239,193,181,183,220,98,113,
178,162,48,196,211,15,60,16,83,76,36,75,129,69,162,99,224,236,209,163,86,31,174,189,249,102,84,86,86,240,230,11,47,160,56,61,221,32,86,95,232,191,49,202,244,147,111,126,19,183,126,238,115,186,13,112,245,
213,248,204,191,251,119,248,209,215,191,142,137,211,35,169,231,130,68,145,212,221,87,94,137,155,63,251,89,116,246,246,90,156,174,199,191,242,21,68,81,148,122,140,221,201,250,221,185,190,42,165,18,10,45,
45,240,60,15,215,126,240,131,232,232,237,197,83,223,248,70,154,251,74,170,71,27,186,187,112,243,103,63,235,180,127,158,127,252,49,204,158,159,52,19,177,219,60,181,36,133,171,88,7,118,242,120,193,63,35,
177,102,92,53,87,83,223,134,112,65,52,200,78,201,41,130,154,105,83,201,166,12,210,19,65,146,20,99,136,147,181,194,37,134,97,149,166,195,23,158,22,114,248,42,52,30,90,78,53,144,148,194,161,251,48,100,132,
42,231,160,20,237,221,221,184,225,67,31,194,13,31,250,16,194,90,13,231,79,159,198,236,196,4,86,150,150,80,94,90,2,131,209,212,210,138,206,141,189,24,216,186,13,125,155,55,59,233,240,204,140,31,125,253,
235,152,30,27,207,120,79,2,142,148,229,143,207,30,61,138,185,243,231,181,156,85,126,16,224,221,119,221,133,119,223,117,23,84,20,161,86,173,90,234,203,255,245,167,127,26,63,91,79,168,253,218,207,126,134,
109,151,92,130,75,111,188,209,64,180,118,224,247,255,227,127,196,212,217,179,24,61,122,20,75,243,243,240,60,15,29,61,61,216,121,249,229,185,17,149,207,124,239,123,105,92,70,157,161,193,34,111,178,68,81,
72,192,238,58,52,124,252,181,87,241,59,31,190,29,0,176,247,218,107,177,231,170,171,112,250,240,97,76,141,142,166,118,83,255,214,173,216,190,111,159,165,86,1,192,248,169,83,120,254,241,39,50,170,14,139,
50,12,177,127,76,73,16,131,149,5,211,50,103,9,241,52,246,64,74,139,99,61,146,89,227,226,145,133,98,75,242,165,89,174,35,203,81,157,241,219,56,97,243,42,67,31,84,204,240,92,60,156,100,114,149,164,76,56,
114,191,26,11,195,164,89,8,2,129,224,86,177,195,175,145,35,154,114,94,65,161,128,205,123,246,96,243,158,61,88,207,43,172,213,240,163,175,127,189,110,15,104,153,204,149,69,195,79,250,249,228,215,190,134,
123,255,237,191,181,178,155,0,245,152,112,147,136,152,33,196,202,98,249,2,192,163,247,221,135,106,165,130,43,223,243,30,39,93,188,127,203,150,85,251,193,204,120,250,129,7,240,210,83,79,101,241,221,128,
85,60,39,243,101,112,110,74,222,103,190,243,93,244,111,222,130,221,87,94,153,246,105,231,229,151,99,231,229,151,175,218,142,201,209,81,124,235,63,255,103,132,97,45,38,108,203,82,11,6,159,52,206,252,175,
88,119,71,146,6,14,201,213,160,251,194,44,159,152,18,168,39,65,171,227,238,44,178,19,11,130,204,72,207,236,151,40,140,224,15,15,109,110,99,165,222,23,69,209,158,106,181,210,211,219,187,177,180,163,163,
189,157,140,68,217,89,230,107,88,37,5,210,122,231,200,143,80,227,44,45,24,52,18,139,51,42,139,51,143,45,235,188,155,226,244,52,60,34,116,110,220,184,166,90,132,171,189,78,189,241,6,190,243,151,127,137,
145,67,135,82,142,148,204,163,43,209,48,249,83,156,154,194,248,200,8,118,92,118,25,154,28,20,15,215,235,31,30,122,208,206,46,146,220,95,1,39,94,221,143,149,165,37,12,199,165,24,214,243,154,155,156,196,
99,255,227,127,224,141,103,159,77,75,26,152,64,147,164,221,179,248,237,119,239,188,75,135,185,23,23,241,202,83,63,198,155,191,252,37,58,251,250,48,184,142,42,94,71,95,126,25,15,254,213,95,213,129,12,150,
37,214,68,114,14,13,144,18,107,198,76,42,159,114,85,117,142,150,225,55,182,214,137,230,241,79,74,25,56,179,131,37,64,69,253,247,227,243,197,197,226,252,92,187,239,251,51,133,66,225,68,251,134,13,79,7,
80,108,37,109,168,87,50,165,52,242,39,59,124,68,154,80,206,156,254,238,106,81,48,42,77,153,141,115,84,143,18,149,131,56,221,221,58,147,246,245,103,158,193,235,63,127,6,133,66,19,182,239,219,135,173,23,
95,140,45,123,247,98,211,246,237,107,10,140,98,165,48,123,254,60,142,189,242,10,14,252,226,31,48,125,246,156,100,61,107,34,143,65,38,35,80,235,218,241,253,175,226,191,254,171,127,133,189,215,94,139,157,
87,92,142,129,173,219,208,217,219,139,166,150,22,39,47,42,205,223,107,213,186,168,103,99,102,5,188,244,195,31,225,192,207,127,142,235,111,189,13,23,95,127,29,6,28,65,85,25,159,80,97,236,248,113,28,124,
238,57,188,250,179,159,166,84,32,51,115,71,110,190,5,202,37,150,129,89,33,172,41,60,246,223,239,195,161,231,158,197,187,238,248,40,182,236,221,155,171,158,158,61,122,20,47,62,249,36,142,190,244,146,141,
34,39,97,11,233,120,202,154,36,54,166,207,150,183,223,96,171,51,68,218,90,24,92,64,51,221,104,230,168,179,54,135,112,218,171,152,79,151,230,83,64,61,128,42,80,28,57,226,121,237,209,100,7,51,215,105,132,
58,28,156,228,72,61,46,165,142,141,125,27,197,93,96,228,64,99,160,90,169,224,216,254,253,56,182,127,127,170,254,117,245,245,97,227,208,16,218,187,187,209,220,218,138,166,150,22,132,181,26,170,113,150,
197,226,244,52,38,71,71,235,117,60,76,32,129,237,58,18,156,147,141,93,254,29,214,20,14,61,255,60,14,61,255,60,108,110,106,126,173,113,74,169,215,50,129,116,253,211,114,169,132,159,63,244,61,60,243,224,
247,208,209,211,131,193,237,219,177,161,179,19,109,157,157,224,40,194,242,226,34,150,139,69,140,157,56,129,114,169,148,19,105,105,132,0,3,107,246,129,72,122,15,51,112,226,181,215,113,226,181,215,177,161,
171,11,195,187,118,161,123,96,0,77,45,45,40,47,47,99,113,110,14,99,39,79,98,105,110,174,65,191,217,201,6,176,214,85,131,246,73,169,99,246,49,75,173,204,171,178,39,92,235,53,209,140,88,73,35,93,213,51,
43,154,186,87,86,192,211,246,186,38,213,127,178,72,48,151,189,173,47,61,43,186,139,244,145,97,7,162,146,49,150,180,66,90,89,65,71,237,228,203,254,152,63,63,137,249,201,73,125,177,147,73,140,20,233,250,
141,168,65,18,89,247,216,42,11,200,154,125,151,196,103,144,19,183,99,17,203,163,7,21,81,90,175,66,167,172,179,35,138,18,12,44,204,204,98,97,118,86,103,55,27,57,163,24,238,26,144,44,75,72,72,61,156,96,
148,1,200,33,95,26,213,162,150,230,230,113,244,149,87,0,87,173,67,57,71,164,207,57,89,121,6,200,85,174,50,143,207,107,59,20,137,140,167,82,157,38,66,36,112,34,173,4,174,238,86,78,19,89,75,169,149,188,
175,100,24,82,157,106,34,147,197,37,190,14,50,54,136,206,13,99,123,179,202,74,190,66,191,205,170,225,57,142,50,133,52,19,123,86,74,145,76,190,161,6,22,164,65,134,198,241,152,213,189,51,194,47,89,182,193,
56,99,157,181,49,89,67,74,204,190,105,109,83,50,141,190,148,138,36,116,126,118,110,180,76,109,36,237,94,112,176,117,37,163,213,12,233,101,35,14,130,137,140,211,57,6,85,196,162,37,129,123,170,28,193,146,
48,9,204,96,6,147,81,97,150,44,128,89,129,45,83,196,245,235,72,183,139,236,188,3,118,224,0,153,228,85,217,127,169,82,89,117,18,229,120,170,148,87,46,75,201,37,92,172,36,147,74,226,31,9,148,72,36,156,250,
64,20,195,19,53,177,89,11,89,52,88,145,44,59,67,178,28,93,188,168,140,1,98,89,206,36,78,67,159,16,152,53,174,12,217,1,107,144,240,164,216,116,156,81,233,201,172,30,148,158,215,164,69,233,177,176,177,8,
58,129,44,173,168,170,213,145,177,79,65,73,107,201,252,37,113,42,255,132,126,45,138,153,166,197,132,68,106,127,150,97,195,74,56,125,216,230,110,37,113,36,164,213,246,78,14,14,129,227,59,50,230,179,134,
27,82,186,73,156,53,79,226,53,32,195,123,147,98,72,201,162,34,217,30,225,19,99,193,173,74,121,108,156,240,227,178,19,92,175,88,69,34,32,15,89,104,178,44,69,157,186,22,178,177,134,172,243,8,89,52,41,41,
210,195,154,166,162,41,90,201,24,114,22,225,153,86,53,136,211,42,69,81,88,119,20,42,233,117,148,145,133,22,247,42,159,21,73,128,145,108,64,218,19,228,100,79,186,121,87,89,90,1,229,250,138,168,217,167,
67,194,38,202,225,78,115,67,6,130,150,209,184,237,118,155,85,31,216,153,2,200,206,86,104,213,110,52,244,111,43,172,54,57,253,5,27,48,75,197,100,200,45,102,59,202,81,160,111,100,226,53,236,32,128,26,5,
218,254,247,123,239,213,206,113,114,132,110,235,60,41,210,10,20,185,152,197,26,168,99,150,247,78,75,107,136,74,189,46,230,178,12,204,98,93,91,144,192,73,38,68,228,161,33,227,79,236,90,2,105,229,4,49,78,
74,75,122,8,112,132,56,121,53,100,184,161,18,177,16,162,214,54,242,98,205,13,111,53,25,19,146,214,188,22,13,37,114,102,172,176,204,53,75,254,138,96,115,49,131,172,101,1,119,32,105,196,246,54,73,60,204,
96,189,204,53,193,200,182,161,75,19,173,113,142,107,204,120,106,217,54,43,61,139,8,15,145,105,180,237,12,243,228,208,187,200,150,172,114,252,200,128,125,200,204,80,99,204,135,21,236,70,118,14,42,50,86,
167,198,188,101,88,53,226,9,58,51,87,224,205,68,34,184,12,142,18,227,154,78,47,10,207,41,88,53,67,82,167,174,145,125,71,223,72,164,217,11,172,88,163,38,39,106,37,36,149,133,17,39,175,86,42,61,35,18,29,
204,166,193,178,61,81,38,180,224,138,71,213,130,90,210,82,71,22,49,147,169,65,156,128,6,9,178,65,195,215,203,12,59,109,61,229,184,89,156,196,32,221,47,138,53,74,187,19,5,113,245,77,47,145,10,235,152,82,
226,128,48,19,102,185,48,87,237,30,198,160,106,57,107,84,142,183,201,73,151,181,231,194,76,76,107,225,190,236,102,237,82,30,203,214,209,166,164,152,32,155,168,21,25,149,116,29,69,99,76,145,110,150,155,
118,49,156,93,53,213,201,213,119,206,230,66,84,159,66,234,233,168,7,247,70,136,16,68,181,136,98,145,226,49,179,231,121,228,115,226,251,32,169,102,232,168,128,76,104,96,86,243,201,26,166,167,233,202,244,
94,192,202,131,196,110,56,185,190,113,204,24,17,57,41,230,36,101,118,19,9,79,172,89,230,145,4,239,128,77,186,125,122,194,233,213,4,205,224,183,60,194,153,52,206,181,244,104,34,16,130,132,45,67,146,7,65,
122,41,74,171,116,134,118,90,136,28,81,18,165,33,7,26,164,140,70,18,25,245,33,235,22,36,179,157,108,44,45,215,41,74,218,193,148,247,42,179,85,201,88,216,102,54,2,109,57,165,246,83,154,77,200,240,161,176,
6,241,179,177,6,243,120,130,26,163,36,13,219,134,22,37,154,122,242,99,191,155,231,121,1,179,242,152,25,28,213,203,245,5,240,153,57,228,40,138,194,50,152,163,201,169,73,111,121,160,95,181,69,161,231,14,
236,98,119,180,160,83,229,103,228,224,55,112,86,132,205,129,176,25,249,209,112,220,0,56,183,235,23,113,14,50,238,180,83,129,252,218,76,171,6,188,217,68,1,206,57,152,141,62,240,122,158,147,211,178,181,
148,145,98,118,228,2,112,75,142,60,219,142,221,131,150,35,124,115,103,202,78,113,154,211,29,70,254,26,68,3,37,162,241,248,215,219,182,236,7,234,252,249,137,0,140,8,64,5,132,48,98,5,127,231,174,157,133,
40,82,87,134,213,106,87,161,169,185,127,105,105,161,125,108,101,229,216,222,158,222,126,87,96,142,158,79,135,215,228,116,34,131,124,104,243,32,114,217,38,206,116,53,249,241,184,13,242,234,90,37,95,27,
168,130,172,179,197,184,81,95,27,170,133,220,160,33,141,116,73,221,73,154,1,17,220,112,37,144,70,138,65,110,114,135,6,43,53,63,133,111,106,118,112,163,189,234,54,182,115,199,137,27,239,4,206,57,54,93,
170,174,233,154,183,202,102,35,23,76,96,34,60,122,240,224,225,165,197,197,33,223,247,23,10,133,194,145,150,150,150,163,77,65,240,98,160,20,168,208,212,52,95,173,84,39,194,40,92,80,138,187,187,59,186,54,
34,45,107,204,208,10,83,115,34,138,29,14,16,102,155,66,161,133,233,102,139,158,200,1,134,73,131,79,26,137,42,173,202,152,209,183,69,198,19,205,96,78,32,65,182,81,116,146,57,197,152,83,232,80,111,23,107,
136,85,6,115,178,22,52,43,233,211,117,4,138,244,98,167,90,82,45,83,20,179,35,108,54,251,157,192,113,14,52,67,237,210,245,140,184,253,25,136,192,154,31,69,165,102,65,226,172,36,54,83,229,144,206,250,75,
48,105,165,27,191,80,130,152,170,57,48,216,128,172,133,207,43,173,181,172,100,125,77,67,71,165,172,58,0,27,170,152,18,20,69,150,55,16,14,41,51,4,153,245,67,34,41,184,67,76,153,143,73,194,188,41,20,204,
232,234,238,233,157,159,159,43,16,211,188,31,248,19,77,205,77,51,33,51,130,151,95,122,169,120,217,229,87,60,198,172,46,1,115,21,204,92,169,86,252,8,12,79,98,108,233,2,80,2,51,150,120,89,134,221,235,35,
28,111,14,101,165,113,179,13,83,206,240,108,146,3,203,18,27,55,193,1,173,232,122,86,16,158,108,195,204,132,252,116,39,147,168,133,71,6,92,158,190,79,117,20,195,72,190,197,48,164,157,76,135,233,52,176,
88,80,178,149,1,36,176,238,135,73,236,147,244,176,96,135,240,18,7,68,218,38,153,194,149,179,178,199,26,10,168,140,123,10,132,75,37,246,151,50,240,24,7,188,77,50,177,32,91,128,74,99,221,147,245,114,223,
202,44,33,174,140,228,4,162,174,59,11,112,32,169,59,41,24,27,89,89,53,54,208,192,108,99,178,170,111,158,74,165,92,0,51,19,81,149,21,47,2,244,248,203,47,189,188,228,3,192,134,246,150,21,159,188,171,107,
213,218,70,242,188,190,249,185,217,66,121,67,199,196,112,115,83,151,158,151,136,211,9,99,19,1,17,60,22,221,147,46,81,38,35,195,95,236,185,180,165,103,150,167,43,70,222,0,171,52,3,235,26,147,169,142,113,
14,65,207,245,151,56,233,37,228,13,141,243,42,251,170,117,65,248,123,216,248,64,47,45,12,200,40,55,135,255,197,186,94,58,174,86,209,104,101,22,22,165,91,20,172,101,244,100,221,79,192,6,179,193,24,15,197,
142,88,111,211,190,147,115,206,13,236,82,203,93,103,116,72,153,135,60,107,53,59,178,60,1,98,109,1,162,198,185,158,39,193,92,139,242,187,201,31,10,140,95,76,207,142,140,158,25,233,2,80,14,130,224,68,161,
169,233,0,87,241,131,169,217,41,14,0,160,115,67,119,75,24,214,86,106,181,112,204,35,218,83,173,86,55,47,44,46,46,162,99,3,148,142,99,152,33,45,22,235,210,165,110,90,113,37,226,148,206,80,90,27,14,146,
53,229,216,81,150,203,149,141,143,45,53,47,145,246,122,78,88,50,246,146,230,23,48,100,157,253,61,104,140,220,4,193,35,214,49,186,198,160,128,67,18,104,5,95,201,97,88,178,73,192,177,92,7,154,155,131,27,
155,120,114,94,97,166,51,37,193,37,51,114,87,154,105,92,77,170,136,210,56,87,70,58,81,13,215,35,193,183,115,236,124,205,87,35,36,185,171,30,141,172,113,40,180,19,101,172,67,178,49,64,20,23,138,205,138,
121,131,239,251,167,253,32,56,87,104,106,42,249,129,223,6,96,49,240,1,242,35,127,65,121,234,231,190,239,111,173,148,43,83,96,30,152,156,60,223,52,187,101,75,216,19,213,2,216,91,34,215,144,35,90,99,124,
19,103,106,170,37,222,45,151,129,163,124,130,197,219,33,93,83,35,125,24,88,11,66,32,167,223,79,79,202,233,68,161,109,53,216,144,2,156,51,207,249,156,82,61,178,141,115,141,127,177,128,137,157,36,63,141,
91,228,172,71,191,250,102,149,137,191,85,206,246,50,251,65,166,240,49,245,1,43,77,16,44,117,214,154,11,51,49,114,163,184,57,45,153,158,91,198,146,195,12,98,0,179,126,80,155,154,60,223,196,204,85,2,77,
123,158,55,229,123,254,47,14,188,254,250,34,0,248,251,46,187,204,127,253,208,235,170,103,99,247,36,51,174,12,195,176,187,208,212,220,95,41,175,244,156,95,94,30,221,219,211,211,237,214,27,77,21,135,5,53,
128,133,122,195,54,122,196,166,253,202,58,157,0,174,120,1,169,158,233,85,129,108,125,137,53,181,136,93,168,25,27,234,149,69,255,48,85,1,71,1,73,173,116,182,105,242,176,246,28,119,57,9,57,86,14,221,93,
198,194,104,14,82,17,146,32,206,67,251,25,172,217,71,154,253,102,193,138,48,40,46,236,24,59,118,34,69,204,13,36,163,201,174,53,33,119,249,12,67,45,178,39,43,71,173,204,79,250,169,205,161,50,212,112,6,
240,216,193,131,103,170,149,202,38,207,247,103,131,32,56,210,212,220,124,48,140,194,239,205,206,206,170,43,46,191,130,2,21,69,236,3,20,144,223,140,128,198,131,32,56,89,46,151,251,201,243,222,49,55,55,
219,119,44,218,85,188,200,227,174,52,57,151,180,55,19,154,73,178,123,21,156,241,29,12,71,166,99,54,115,86,113,102,18,178,238,150,99,147,189,171,109,18,157,135,227,170,209,195,6,106,70,142,211,146,217,
112,184,9,207,45,57,20,20,51,161,189,185,249,73,82,1,211,196,213,57,250,15,177,206,67,115,156,156,137,250,102,198,197,100,32,142,176,151,36,195,215,72,223,173,85,148,141,99,195,87,203,74,232,206,134,104,
123,223,211,245,65,172,227,47,78,209,144,37,6,97,131,108,164,213,172,39,78,73,160,122,162,116,195,161,108,52,137,152,156,222,23,89,167,228,72,136,185,210,210,226,0,128,42,17,157,44,20,10,39,10,77,133,
113,16,90,0,44,29,120,227,0,251,211,211,211,188,247,226,75,188,195,111,190,89,238,235,219,56,10,162,139,162,40,106,10,130,66,95,173,90,237,59,55,57,49,119,233,208,112,59,41,69,178,142,161,44,128,200,108,
27,210,186,113,37,3,226,117,98,164,158,115,41,59,150,53,242,164,48,84,89,254,46,172,207,244,148,87,6,233,18,102,222,47,221,72,134,50,251,19,223,95,201,193,20,198,187,48,152,101,177,33,187,189,217,233,
200,80,122,96,14,235,137,202,204,54,106,134,188,38,237,196,253,217,20,54,66,178,164,18,73,140,177,150,28,13,90,29,74,22,161,175,44,1,18,118,141,141,49,167,178,232,18,75,178,166,123,190,228,26,144,146,
208,26,91,152,247,214,219,146,30,170,98,252,82,31,77,76,239,209,250,3,125,124,107,228,241,15,247,191,92,84,74,245,250,126,48,90,40,20,94,111,110,110,62,2,194,223,31,57,124,36,173,68,228,3,192,198,141,
189,52,55,51,3,191,185,176,210,210,220,210,202,204,61,181,106,213,247,61,191,39,10,195,238,195,83,147,103,119,111,26,234,42,40,69,186,65,201,122,49,3,118,80,138,217,54,43,245,24,15,210,78,59,102,135,206,
205,89,154,156,172,96,76,70,115,215,227,28,216,146,10,122,248,142,204,226,71,78,39,30,25,17,133,41,117,93,110,98,65,160,135,129,140,164,207,22,234,129,89,195,34,245,217,136,232,168,204,165,163,63,199,
68,255,82,248,95,28,4,122,76,54,187,141,40,3,134,206,64,13,54,104,117,108,204,149,140,247,48,230,141,141,4,27,194,119,193,154,195,210,100,51,56,2,208,4,247,140,164,202,197,46,238,128,92,111,164,175,69,
173,174,141,161,166,17,176,236,249,234,59,47,191,116,134,149,26,32,207,155,241,3,255,64,83,115,243,225,32,8,158,59,118,244,216,97,41,115,124,0,152,153,153,225,221,123,246,248,163,167,207,168,174,238,206,
49,159,188,75,0,170,70,97,24,146,239,119,135,181,218,192,225,241,241,201,45,155,183,182,180,170,200,215,245,111,87,97,69,182,60,192,166,58,165,101,58,97,54,138,123,194,80,9,12,96,143,77,231,93,22,232,
146,72,5,169,83,147,176,17,92,69,117,44,8,211,80,211,165,228,73,251,43,210,249,39,161,154,36,78,54,50,108,33,146,82,206,208,197,83,88,153,115,42,218,138,231,50,244,144,4,50,32,79,200,57,113,105,79,174,
107,96,170,158,108,149,43,96,109,188,205,165,206,198,203,28,248,141,0,0,7,209,73,68,65,84,1,162,116,210,179,73,10,150,102,140,18,155,221,56,15,216,242,134,219,229,197,51,95,135,220,251,38,136,193,233,
6,154,245,10,181,71,94,126,113,154,21,15,120,190,55,227,123,222,43,77,205,205,7,11,133,194,104,200,252,80,113,110,46,218,187,119,47,205,204,204,88,84,187,244,181,123,215,174,203,20,243,45,181,90,173,191,
90,169,92,10,198,53,213,90,117,144,136,22,223,123,245,181,109,91,85,216,134,127,66,175,252,170,32,255,255,121,226,63,133,222,157,166,96,249,231,251,95,42,51,208,238,251,254,152,239,251,175,52,183,180,
28,42,20,10,83,32,122,234,228,137,19,135,205,107,180,188,57,187,118,237,162,185,185,57,204,205,205,77,117,247,116,159,241,60,111,16,68,43,81,88,35,207,243,250,162,40,236,63,61,62,86,161,222,254,197,1,
143,218,156,222,209,220,162,218,171,48,28,87,163,234,172,145,247,229,100,248,49,191,197,105,92,227,247,86,229,166,241,218,19,71,179,13,68,188,165,118,241,106,165,105,88,227,52,160,1,177,47,247,54,188,
142,97,2,219,190,194,92,170,90,94,105,3,22,30,22,182,202,131,176,11,208,142,37,199,254,114,109,250,165,3,175,54,49,115,87,16,4,83,158,231,189,220,220,210,242,90,16,20,206,1,120,240,212,201,147,35,0,176,
107,247,110,154,155,155,115,111,144,185,185,57,236,220,185,147,230,231,231,177,56,63,191,212,222,209,113,200,243,188,30,102,110,14,195,48,0,208,173,152,187,206,79,157,167,9,166,241,237,29,237,157,196,
76,12,51,36,66,42,25,153,184,212,202,42,75,79,178,244,58,231,204,145,44,112,2,214,83,199,216,6,164,120,166,208,160,109,131,77,142,191,157,251,74,243,101,107,198,180,0,68,211,164,11,246,245,217,183,72,
211,73,89,68,108,178,11,105,97,210,189,193,154,9,226,88,6,172,23,127,73,40,63,108,192,237,54,47,81,102,109,103,11,208,214,213,25,3,124,225,6,188,68,29,44,54,148,77,49,110,153,177,6,115,13,201,235,204,
74,184,44,82,254,232,125,39,253,185,12,212,136,248,7,103,70,71,207,140,142,244,48,208,234,249,254,140,7,188,94,104,106,58,16,4,193,235,28,225,91,167,207,140,20,19,1,113,242,228,73,118,249,79,26,190,134,
54,109,250,120,20,69,239,9,195,112,167,82,106,23,51,15,179,226,86,242,104,252,206,43,175,222,177,65,133,100,237,97,141,119,72,118,176,141,225,1,206,14,14,35,159,147,97,104,146,19,96,36,13,154,133,203,
195,235,44,174,74,134,49,154,155,61,214,26,44,171,112,189,22,253,167,179,1,204,3,93,203,179,107,120,140,101,16,158,157,63,43,187,94,86,219,210,124,211,90,45,195,216,120,21,113,229,48,243,141,185,178,207,
164,96,129,94,28,85,247,174,187,174,177,185,179,186,223,156,157,46,82,22,249,118,205,0,71,54,231,221,153,209,38,169,254,69,90,144,210,178,231,171,135,247,239,31,101,230,77,68,180,76,158,119,214,247,189,
147,65,80,24,241,3,255,39,99,99,227,143,172,182,246,27,166,38,220,178,121,179,183,176,184,200,75,75,75,135,59,187,186,150,61,207,15,8,52,5,86,85,63,240,187,195,40,26,56,50,49,62,211,61,52,28,248,68,94,
192,138,220,206,56,213,80,100,107,124,44,22,62,89,197,13,165,62,91,15,227,124,133,130,45,79,134,227,94,156,203,111,202,211,42,108,237,74,233,60,46,102,7,245,70,57,52,7,214,140,78,189,191,102,4,38,235,
208,186,38,125,116,47,29,27,84,21,45,102,59,189,169,114,199,112,56,8,96,46,0,5,70,157,13,35,119,102,58,46,156,171,101,57,64,1,139,231,230,82,85,217,242,111,0,140,101,223,87,227,76,229,31,190,186,127,142,
129,62,207,243,102,61,207,127,185,80,40,188,20,20,154,142,248,190,255,248,216,216,248,143,215,34,28,86,149,32,195,195,155,189,177,177,115,10,0,134,134,134,47,101,230,91,163,176,54,80,171,213,246,49,243,
85,81,20,109,6,179,71,68,211,87,92,178,175,105,168,181,181,173,47,172,54,233,226,193,69,54,210,63,107,24,183,224,204,121,77,110,61,219,20,21,38,148,107,29,114,121,79,54,51,19,26,132,17,215,189,243,31,
146,43,149,172,207,136,115,218,76,249,54,72,163,126,174,182,0,40,39,226,214,121,35,114,219,45,166,244,208,250,32,184,84,220,72,62,235,115,162,75,87,119,227,204,232,223,41,191,169,114,174,180,92,58,124,
244,205,136,153,123,65,20,250,190,127,214,35,218,31,52,53,29,10,130,96,6,68,223,31,31,27,59,10,0,91,182,108,166,179,103,207,241,219,218,32,241,198,240,198,199,199,148,15,80,255,224,166,33,102,117,71,20,
69,195,97,24,238,137,148,186,184,16,4,219,195,48,236,140,162,168,64,160,133,61,59,119,67,177,42,109,236,232,104,222,3,238,165,156,250,176,107,156,195,28,62,211,63,206,107,189,109,228,11,244,172,188,210,
17,148,167,226,57,239,103,135,10,191,221,246,240,26,142,148,213,198,193,165,38,231,245,35,143,75,150,240,191,142,40,76,79,45,20,43,190,231,111,56,125,102,196,3,115,59,145,87,43,52,53,21,195,176,54,226,
121,222,145,160,80,56,30,4,193,57,0,143,79,76,76,76,0,192,240,230,205,52,118,238,28,191,109,9,146,188,54,109,26,162,137,137,113,6,128,254,190,141,29,228,249,31,136,148,218,166,194,112,139,82,106,88,41,
181,153,153,183,177,82,125,12,180,3,240,8,40,53,53,55,151,218,54,180,135,197,185,217,197,109,219,182,183,92,223,221,185,165,16,41,82,148,83,78,217,97,130,152,19,227,182,67,140,206,164,89,89,224,192,55,
204,120,236,252,9,118,77,160,168,168,231,100,253,174,158,118,52,255,125,54,154,110,135,223,147,229,116,213,174,39,155,153,155,103,7,89,202,165,89,103,67,96,70,169,229,65,16,181,202,29,9,22,197,60,90,137,
85,92,98,196,57,46,194,86,18,254,141,144,136,159,159,157,63,51,118,238,108,109,67,71,123,123,181,82,41,84,43,149,54,6,90,1,68,4,44,122,190,63,77,192,136,231,121,99,228,251,99,158,231,141,250,190,63,202,
204,79,79,77,77,45,215,215,242,38,154,152,152,224,245,28,204,111,233,213,211,187,177,57,240,232,6,21,69,219,35,230,189,42,138,134,153,213,0,51,247,2,232,101,197,189,204,220,197,128,79,128,135,58,93,182,
12,208,10,57,74,154,172,118,58,173,21,75,231,117,116,46,175,158,37,55,218,124,235,108,139,107,195,172,197,23,192,57,253,94,235,4,174,119,147,174,103,44,121,53,208,98,149,246,173,117,204,4,134,227,49,208,
2,230,150,248,119,69,68,53,2,22,136,188,105,128,103,201,243,102,201,243,38,61,223,27,243,61,239,77,2,141,134,213,218,11,243,139,11,209,219,145,234,23,228,213,219,219,123,13,51,183,169,40,234,1,209,13,
28,69,221,138,185,159,153,187,0,4,96,238,100,230,1,6,122,98,112,64,93,88,143,17,91,84,245,53,47,67,25,139,178,158,149,67,57,207,176,24,172,228,110,210,219,233,191,140,134,204,123,254,170,98,214,16,79,
212,104,233,175,50,56,185,125,49,69,224,42,227,150,255,185,7,112,72,228,205,129,232,188,7,20,153,40,36,162,5,143,104,138,60,154,7,232,121,207,247,231,136,176,50,59,51,251,218,133,82,177,223,214,107,227,
198,141,52,51,51,163,173,203,158,158,158,29,96,110,175,133,161,66,29,69,184,137,149,234,97,230,62,102,238,68,34,77,86,177,51,214,162,211,175,215,12,190,144,131,198,107,55,189,47,172,253,180,74,220,77,
110,91,28,9,163,215,218,54,202,217,223,107,27,175,245,217,66,214,246,140,179,242,212,53,16,90,240,60,111,138,136,102,152,249,89,48,79,5,65,224,51,161,52,63,55,127,90,91,155,125,27,105,102,122,134,127,
173,27,68,110,20,102,246,138,179,179,10,0,34,49,126,93,93,157,189,4,106,10,163,200,99,165,2,11,152,32,253,48,100,134,145,155,202,182,32,32,147,40,104,142,148,236,189,44,110,74,40,214,57,39,107,154,233,
47,213,149,51,50,159,172,153,104,250,62,146,207,204,252,103,153,238,46,236,147,117,156,0,228,176,201,64,102,121,6,233,48,73,130,195,201,240,43,217,138,43,105,99,76,2,2,174,203,96,50,26,39,43,7,102,114,
218,72,41,107,38,14,36,104,81,126,218,134,146,70,145,246,125,35,181,85,226,76,36,74,197,138,87,71,166,88,49,87,22,22,22,230,132,191,130,0,160,107,99,175,71,4,158,153,158,85,23,98,93,255,191,33,214,58,
58,96,162,138,176,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LivePanelComponent::stop_2x_png = (const char*) resource_LivePanelComponent_stop_2x_png;
const int LivePanelComponent::stop_2x_pngSize = 18537;

// JUCER_RESOURCE: tap_2x_png, 17175, "../Images/Tap@2x.png"
static const unsigned char resource_LivePanelComponent_tap_2x_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,200,0,0,0,100,8,6,0,0,0,195,134,127,11,0,0,0,1,115,82,71,66,0,174,206,28,233,
0,0,0,6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,219,10,30,4,36,20,162,96,227,70,0,0,32,0,73,68,65,84,120,218,237,189,
121,144,28,231,117,39,248,123,153,89,125,3,141,62,209,104,0,2,8,146,0,111,82,164,200,145,76,75,26,201,20,169,131,148,168,145,69,123,28,210,142,189,242,142,119,39,98,198,187,235,141,113,204,206,70,120,
99,215,17,27,225,136,157,24,199,70,236,202,59,179,182,199,18,101,75,162,36,94,178,68,89,135,117,145,18,69,138,226,13,80,196,65,28,221,13,52,250,238,174,174,35,243,189,253,163,242,120,223,145,85,213,64,
107,36,79,168,24,77,116,87,85,102,126,249,229,119,188,247,123,191,247,123,132,109,122,61,241,213,39,136,2,10,222,119,247,221,12,0,9,32,217,103,95,255,198,55,70,73,208,243,250,235,63,13,230,23,46,70,36,
2,8,32,4,16,8,64,235,203,36,2,16,181,62,131,20,159,145,164,95,72,223,17,32,255,69,0,128,210,111,11,24,4,144,32,16,110,157,11,132,162,41,148,30,154,158,93,36,189,54,165,95,109,53,170,245,41,178,6,182,142,
86,215,164,236,198,164,104,95,171,101,233,177,217,119,69,242,227,5,132,0,233,123,32,8,17,136,4,16,105,253,46,128,136,180,222,163,160,117,104,171,83,210,227,129,64,223,139,164,45,201,219,68,69,127,16,33,
189,181,214,199,132,188,127,90,215,40,190,43,68,173,79,164,56,111,122,43,173,222,202,46,78,148,222,46,1,34,173,190,11,210,251,23,6,81,241,12,144,247,144,234,223,172,221,68,16,110,93,159,72,32,146,62,135,
0,198,179,106,29,163,255,6,42,81,36,59,135,119,198,87,31,62,34,32,169,223,245,238,187,150,178,71,17,166,23,253,202,19,95,11,4,34,247,220,115,15,111,199,184,166,237,152,24,247,188,247,30,209,239,125,253,
239,254,238,160,0,67,207,61,247,28,71,97,56,190,103,122,250,206,229,165,229,145,133,197,133,241,234,198,198,78,97,14,40,32,214,77,176,39,136,126,9,21,3,220,153,32,122,224,139,186,171,252,13,253,176,236,
223,165,164,27,164,152,0,206,4,241,125,91,204,137,158,127,80,76,144,236,115,247,146,234,232,236,254,141,243,136,121,188,154,32,200,39,136,213,238,98,56,122,30,176,186,247,116,224,219,237,74,231,176,58,
75,209,23,234,97,21,103,207,39,178,127,130,248,159,129,253,150,120,38,72,54,167,72,152,57,8,2,226,129,129,193,213,241,137,137,249,225,225,157,11,23,206,95,120,178,86,171,205,191,249,214,91,67,0,213,247,
188,231,61,111,232,83,127,245,137,175,210,123,239,121,175,252,92,39,72,246,250,218,19,95,187,117,163,90,29,152,159,191,48,18,133,225,29,139,75,75,187,150,22,23,39,54,171,213,225,132,57,170,215,106,59,
55,170,213,201,70,163,49,34,204,33,17,113,231,102,201,214,238,68,202,222,112,62,44,158,75,201,165,36,61,132,182,210,115,130,159,225,139,182,120,129,54,223,111,119,170,78,151,161,75,189,79,117,160,125,
142,46,30,183,136,4,20,4,113,111,111,239,210,224,192,192,249,190,254,254,149,32,8,226,129,129,129,213,145,209,209,249,209,209,209,229,102,179,249,131,169,221,187,151,122,250,122,55,239,185,251,158,231,
127,238,59,200,215,158,248,90,47,11,223,81,173,86,15,44,45,45,29,158,153,57,55,189,188,188,50,185,185,177,49,90,173,86,71,107,245,250,104,28,199,195,34,18,66,36,0,129,195,32,172,133,81,180,9,128,201,90,
244,125,125,68,151,49,238,202,246,139,255,28,195,115,187,167,70,217,248,41,217,251,74,215,236,178,37,227,114,251,89,182,169,143,156,182,138,16,136,68,68,2,78,146,190,132,185,79,68,2,34,112,64,65,51,170,
84,86,123,251,250,46,14,246,247,47,14,12,14,45,142,140,140,92,216,187,119,122,102,215,200,200,209,222,222,222,51,97,20,254,240,61,119,189,39,249,153,79,144,199,31,127,140,238,189,247,62,1,128,175,124,
229,171,59,32,252,107,171,107,107,111,186,112,225,194,190,243,115,115,211,139,11,139,123,151,87,150,247,55,234,245,137,132,121,72,68,130,40,12,171,253,67,59,54,134,70,70,26,27,139,11,213,253,55,220,36,
183,188,231,125,87,84,42,61,17,11,179,223,228,104,243,180,219,189,218,205,180,75,93,6,164,139,99,125,35,144,186,184,15,185,132,17,70,151,208,230,110,251,80,182,97,233,148,75,60,182,172,207,212,179,12,
130,32,104,52,27,241,143,191,252,232,137,153,99,175,132,189,59,118,14,108,110,172,247,108,174,175,15,114,146,244,131,40,9,195,112,173,175,191,127,126,120,231,206,55,198,198,199,103,246,76,237,158,25,31,
27,63,51,180,99,199,25,34,249,230,123,223,247,129,13,0,120,236,241,199,233,190,123,239,149,109,155,32,143,61,250,104,112,223,7,63,200,33,64,143,62,254,216,158,132,229,190,11,231,207,79,159,56,113,226,
170,243,115,231,143,108,54,26,7,234,181,205,157,73,220,172,84,162,202,234,149,183,191,181,17,18,173,143,31,56,72,7,175,191,241,64,37,8,136,69,132,0,34,162,54,107,92,217,104,235,102,95,161,46,158,114,153,
125,44,29,70,111,55,246,211,86,214,81,234,98,45,167,14,123,70,187,227,183,58,11,219,181,161,155,217,212,169,31,168,195,44,20,207,53,165,196,212,2,24,34,33,136,98,78,228,248,243,207,157,58,127,242,56,88,
104,232,212,243,207,246,198,113,60,20,68,81,179,127,112,104,121,160,167,242,198,238,61,123,142,93,121,229,161,215,39,39,39,207,49,240,229,251,62,112,239,28,0,60,242,232,163,244,161,15,126,80,46,123,130,
60,242,200,35,193,135,62,244,33,6,128,199,30,123,244,90,102,190,231,204,153,51,147,39,94,63,126,221,220,249,11,55,87,171,27,251,68,36,232,237,237,185,120,253,187,239,78,246,31,185,174,119,124,114,114,
52,80,206,159,32,67,78,80,160,37,219,178,65,111,183,49,189,149,54,252,188,140,174,110,141,163,127,72,70,101,231,231,88,128,107,45,164,176,0,115,36,69,198,68,206,207,206,44,156,125,245,229,198,171,223,
253,86,79,189,209,24,13,136,226,193,161,161,51,147,187,119,255,228,200,225,195,175,236,217,187,119,1,130,175,124,240,131,247,189,6,0,15,63,252,48,221,127,255,253,114,201,19,228,225,71,30,9,238,79,39,199,
167,31,124,240,237,113,163,241,142,217,217,217,221,167,79,159,190,102,105,121,229,198,90,117,99,180,167,167,103,233,87,127,235,183,43,99,211,123,251,119,12,13,246,147,66,101,46,197,215,163,14,235,9,41,
176,71,74,214,99,88,32,163,126,247,82,134,83,217,20,238,102,205,43,128,229,146,115,21,192,85,155,125,211,93,205,21,24,221,213,250,45,219,60,29,168,4,136,18,152,104,95,55,150,155,209,135,82,128,115,93,
141,31,113,175,183,186,186,86,189,120,238,76,245,201,207,126,58,105,52,155,187,122,123,123,23,198,199,199,159,63,112,224,192,177,61,211,211,231,123,123,251,254,254,129,7,62,250,131,109,51,177,62,249,201,
79,126,100,113,113,225,29,115,179,115,87,44,46,46,30,218,220,172,77,39,73,220,223,223,223,55,123,239,239,255,225,212,142,161,193,126,211,177,242,32,144,191,124,253,242,245,51,120,233,144,147,61,230,86,
87,215,170,143,255,233,159,204,111,214,106,83,149,48,220,232,31,28,60,59,54,54,118,98,106,106,234,212,196,228,228,183,62,241,137,79,60,186,229,9,242,249,207,127,158,62,250,209,143,74,8,208,67,95,250,98,
191,8,238,59,254,250,235,111,249,233,79,127,122,219,197,139,23,111,105,54,26,35,97,24,110,238,61,124,205,204,59,126,243,227,7,250,122,122,34,64,192,144,52,144,245,179,239,140,110,253,231,237,190,230,47,
95,191,248,147,37,251,55,72,127,223,108,52,227,111,253,167,255,240,198,220,27,167,246,114,146,244,245,244,244,46,76,76,142,63,119,248,200,53,207,30,60,120,240,89,66,240,232,135,255,201,253,117,61,246,
75,39,200,231,62,247,57,122,224,129,7,4,0,30,250,252,231,167,65,116,223,236,204,204,222,99,71,143,221,114,126,254,194,29,155,27,27,187,163,40,90,191,229,158,247,47,221,116,231,59,247,81,26,128,46,6,17,
117,49,164,219,249,32,221,56,195,93,129,131,91,180,221,187,49,188,186,113,158,59,125,247,114,252,158,173,56,217,219,5,222,162,195,243,146,45,128,15,151,106,220,93,202,184,48,207,25,51,203,11,223,249,251,
211,207,127,253,171,19,73,146,12,244,15,14,206,76,77,77,61,125,221,117,215,61,55,49,49,49,11,193,99,191,254,209,95,159,107,205,129,207,210,3,15,252,134,180,53,177,62,247,217,207,93,159,36,241,221,51,51,
51,19,39,79,158,188,118,254,226,197,55,87,55,54,166,162,40,90,123,251,199,126,39,185,226,234,195,187,33,242,203,37,235,151,175,127,16,175,12,32,58,254,234,43,115,223,251,235,191,170,196,73,50,52,48,48,
112,110,114,114,242,185,171,174,190,250,149,61,123,246,204,3,242,245,7,30,248,141,87,237,99,179,157,8,127,243,55,127,19,2,192,23,62,255,80,223,198,198,198,93,199,79,156,220,119,244,232,209,91,231,206,
159,127,235,198,250,218,158,158,74,101,225,189,255,226,247,43,7,175,188,122,183,176,20,190,70,198,103,18,243,71,195,114,154,29,33,138,222,83,246,55,140,99,36,61,167,20,91,104,118,157,140,79,164,206,97,
236,179,234,223,236,59,40,105,103,246,62,172,115,229,231,214,237,177,246,171,252,220,240,180,3,229,247,174,239,5,214,53,97,157,207,185,119,241,127,14,17,179,111,157,126,84,247,235,249,158,239,89,58,207,
200,190,174,231,156,190,253,220,184,150,232,54,251,175,231,222,159,228,227,64,196,29,67,240,62,3,1,51,67,88,112,232,154,107,166,238,254,111,255,85,88,137,162,165,141,141,245,125,51,231,102,222,246,210,
139,47,222,118,252,248,241,253,141,70,227,93,95,122,232,11,61,0,240,224,103,30,204,55,142,48,125,35,248,248,63,253,45,121,248,43,159,161,205,106,242,174,217,153,217,27,79,158,56,126,211,194,226,226,109,
245,205,205,93,3,67,67,231,238,253,31,254,112,114,116,215,232,144,108,121,219,188,28,211,233,114,205,133,95,100,216,182,91,136,122,59,98,220,248,7,122,252,229,247,113,118,117,78,127,25,26,218,209,119,
224,182,219,195,147,207,60,61,87,175,215,118,215,106,181,209,184,209,72,122,251,122,215,251,7,7,146,47,124,225,11,39,191,248,133,47,90,59,136,8,18,64,214,151,100,108,113,97,241,182,115,231,206,30,92,89,
223,184,118,115,99,99,188,210,211,179,112,223,127,255,135,251,119,12,12,244,137,112,43,142,145,254,72,233,15,91,191,115,155,239,118,251,195,219,122,12,111,241,252,92,250,25,126,6,247,195,151,121,223,91,
63,150,183,173,207,183,243,248,75,109,119,113,253,108,172,82,190,251,8,118,14,13,245,127,240,15,254,205,222,168,82,89,172,215,106,147,243,23,47,30,57,123,230,236,193,213,149,213,55,63,248,224,131,35,122,
138,133,159,250,244,167,131,127,246,177,143,201,127,250,212,167,118,54,26,141,127,114,230,244,233,195,51,231,206,221,184,182,186,114,101,16,4,181,59,62,252,209,234,158,189,251,70,128,148,208,153,49,64,
51,70,167,180,217,37,8,57,37,220,0,186,13,198,110,137,35,159,47,62,109,152,68,121,59,96,50,76,197,131,63,249,128,115,104,0,63,107,167,152,76,69,161,238,131,0,25,21,214,195,72,46,101,9,144,102,215,150,
69,129,160,218,6,21,40,240,180,145,148,61,104,220,167,197,204,117,238,73,212,3,54,30,182,245,172,172,142,104,135,143,144,184,215,178,3,89,58,128,226,237,55,171,15,243,251,85,253,39,158,104,25,217,253,
153,153,153,173,244,130,74,20,134,209,224,142,165,153,215,142,70,113,220,28,78,18,110,84,42,149,181,145,209,145,29,31,254,200,253,39,190,244,197,135,27,0,16,37,73,66,9,192,160,160,62,59,51,179,103,110,
118,246,80,45,142,175,72,226,184,50,177,111,255,217,171,110,188,249,80,222,230,220,247,16,171,61,186,49,190,14,211,70,34,21,199,147,114,16,236,78,100,233,96,154,105,3,91,15,48,246,15,74,125,13,221,94,
209,179,71,76,163,218,57,95,73,147,164,164,93,165,7,102,131,207,114,112,252,150,180,117,56,89,247,110,45,44,82,210,48,227,249,72,73,211,196,124,166,220,201,52,182,158,43,124,109,177,16,47,237,76,57,183,
220,69,136,83,63,159,118,109,20,113,239,55,239,186,86,136,245,240,155,111,221,119,244,59,223,60,190,52,127,225,208,234,234,218,161,153,153,153,139,253,3,3,51,7,15,31,170,1,192,95,252,197,95,80,248,216,
195,15,227,47,255,234,63,6,113,35,190,99,110,110,246,109,23,230,47,94,183,190,178,252,166,222,129,193,149,183,127,252,119,134,118,12,13,245,253,252,109,201,95,224,160,68,89,216,255,114,2,54,221,16,32,
255,75,10,232,72,187,157,25,151,70,26,237,226,21,16,209,200,129,67,193,201,31,63,83,141,227,230,48,5,65,181,127,96,96,113,215,142,225,133,71,30,121,228,220,35,143,60,130,32,1,132,147,96,231,234,234,218,
219,87,87,86,71,227,132,39,56,225,202,232,190,125,155,19,227,19,195,176,108,185,159,235,15,228,23,163,29,190,54,161,164,157,216,134,251,196,127,161,125,167,219,214,238,158,177,253,247,199,220,26,211,19,
187,119,15,143,78,239,173,50,115,79,117,163,58,182,182,186,58,177,190,182,118,231,159,255,249,159,239,0,128,8,0,142,189,122,180,22,39,73,255,202,202,202,116,173,186,177,51,8,130,141,225,241,241,245,56,
73,164,18,134,132,95,140,253,227,151,175,95,110,224,219,122,51,2,65,194,140,29,19,147,235,23,78,159,218,104,52,27,35,203,203,203,123,207,158,57,243,234,173,55,222,80,205,81,172,93,35,35,211,155,155,155,
147,245,102,115,170,81,171,13,77,93,121,120,253,214,187,63,112,36,10,66,226,50,28,92,52,174,173,240,233,110,126,196,196,196,189,241,144,110,222,147,78,177,21,41,240,255,210,115,74,231,107,26,231,146,46,
98,57,210,225,92,158,24,131,88,199,94,242,61,171,182,162,136,23,57,231,149,46,250,218,58,15,58,246,81,201,253,73,151,247,35,93,222,175,126,190,29,143,17,235,252,26,250,21,132,97,64,183,127,224,67,215,
140,189,233,224,122,18,199,59,170,213,234,228,70,181,58,185,178,89,219,3,0,209,159,253,217,159,13,87,55,170,247,138,200,64,156,36,61,34,66,149,254,254,70,72,65,30,152,49,28,93,149,184,239,162,76,172,16,
32,242,56,93,240,56,205,100,50,206,196,162,114,138,157,12,46,173,92,68,199,185,180,174,35,26,69,99,19,77,201,115,191,197,143,166,137,141,166,217,235,38,91,237,246,180,147,197,211,126,49,251,39,107,183,
216,192,129,5,62,216,249,236,122,164,106,178,15,195,202,21,247,68,32,53,82,100,131,44,165,41,38,90,188,1,30,84,171,12,149,44,235,87,184,223,23,241,244,105,9,118,1,53,78,178,103,43,214,24,176,41,211,66,
150,243,78,41,127,80,16,6,132,158,190,190,6,0,106,54,26,61,16,217,81,111,52,62,240,201,255,231,147,15,70,204,44,23,46,92,216,181,186,178,58,149,48,15,131,168,89,93,188,184,210,76,146,125,68,97,14,143,
153,141,45,137,149,170,207,50,164,160,3,228,227,162,27,14,18,83,242,157,142,208,82,89,104,29,30,228,172,244,73,248,195,226,101,40,12,164,164,41,162,68,37,108,228,174,221,117,196,223,39,226,187,143,14,
237,245,222,119,201,51,109,247,200,4,229,247,221,238,239,118,207,78,221,131,88,136,116,123,180,176,109,163,186,104,99,75,85,37,230,4,155,75,139,203,0,237,110,198,201,174,149,149,213,169,185,153,217,177,
189,251,247,35,188,234,208,149,67,107,235,107,239,93,94,89,189,105,125,117,101,239,206,241,137,149,119,124,236,19,83,131,253,125,149,98,205,47,203,62,40,143,96,210,37,39,245,92,42,121,205,205,160,240,
183,165,253,117,186,203,30,233,212,166,78,217,28,91,183,243,165,244,62,58,3,66,219,207,54,104,71,64,221,42,9,212,60,211,214,124,28,51,110,36,234,61,178,174,211,238,185,70,65,64,227,135,175,221,121,250,
165,159,172,213,214,55,118,81,64,181,48,12,103,38,118,79,254,125,84,171,215,40,78,146,80,128,62,97,14,71,166,247,54,134,135,119,244,139,10,56,101,147,131,209,33,46,100,175,152,208,34,46,190,239,75,73,
114,144,191,171,161,186,193,253,188,140,4,35,222,171,147,209,50,243,248,66,102,71,156,135,45,222,101,128,173,199,37,198,25,117,223,73,135,152,99,217,176,51,251,180,243,160,46,227,71,147,115,47,98,125,
79,75,247,8,196,184,87,182,250,206,61,222,124,166,101,45,22,239,243,101,171,87,187,73,160,134,234,127,187,109,246,162,206,198,114,211,122,37,169,35,62,188,115,103,223,200,244,190,133,181,197,197,48,137,
227,222,36,142,35,112,130,32,138,42,34,204,16,97,17,128,57,142,227,56,78,4,194,158,91,18,151,28,103,61,64,191,233,40,222,9,80,30,182,146,146,176,153,116,220,249,187,216,155,141,182,154,103,54,91,220,202,
114,201,190,193,198,247,145,190,103,118,187,62,182,236,62,221,97,47,165,45,44,187,19,46,125,10,40,13,53,154,119,43,206,123,102,95,152,247,139,124,114,160,237,241,254,103,95,254,252,197,234,21,177,222,
245,223,143,24,253,192,165,223,129,5,52,248,250,33,19,49,140,147,4,156,196,113,203,119,111,81,88,88,4,81,129,204,8,132,153,132,133,114,230,172,116,99,95,94,202,103,221,108,233,178,133,247,47,133,220,39,
93,79,166,173,253,126,185,215,232,230,94,225,241,100,113,137,247,44,91,120,78,29,157,145,75,124,254,101,159,93,234,179,164,174,175,33,153,232,157,0,204,76,34,146,138,92,10,132,5,17,115,146,18,190,52,204,
152,110,32,151,16,253,112,132,242,254,179,128,232,226,53,69,182,116,221,109,104,159,105,14,202,150,58,172,251,203,139,137,40,110,135,131,179,133,254,53,146,227,68,12,193,197,109,139,173,56,202,153,151,
51,30,58,223,186,8,33,12,40,167,161,180,118,16,70,44,9,34,73,225,194,44,90,222,154,28,2,9,82,157,216,174,93,62,83,32,211,25,161,180,213,209,218,206,74,111,207,73,208,190,80,1,131,150,29,103,39,51,151,
57,161,237,196,174,236,235,150,92,195,247,47,145,97,19,183,109,163,77,230,108,35,61,234,235,67,67,50,88,75,159,74,89,122,2,181,121,58,146,67,7,204,130,102,146,32,225,86,224,45,17,6,51,131,165,21,107,96,
78,13,86,97,131,126,166,115,60,252,231,167,46,167,148,95,102,200,118,202,41,229,192,101,58,202,173,241,29,32,10,2,196,73,34,205,102,51,231,26,10,167,59,8,152,33,172,38,135,20,246,37,91,80,109,225,196,
185,238,170,233,6,145,229,4,139,114,89,205,155,33,47,90,3,175,19,216,22,6,45,157,100,173,127,63,126,231,29,63,183,160,237,95,125,255,105,229,188,138,53,148,185,195,196,43,247,196,200,114,162,181,59,42,
246,115,161,76,188,154,210,32,89,182,48,154,86,63,179,160,30,39,104,36,9,154,73,140,56,97,36,204,233,64,231,220,54,111,9,110,23,116,255,36,163,112,72,1,243,139,23,94,33,103,76,181,230,58,25,73,114,80,
97,44,205,32,119,149,123,161,184,145,226,181,178,72,185,239,110,255,103,159,49,146,36,22,168,123,226,56,65,228,229,213,131,33,18,148,110,86,210,165,19,220,206,53,109,183,25,118,103,161,111,205,238,39,
250,57,146,36,164,204,121,181,49,59,27,14,113,227,20,100,197,72,69,153,35,146,211,39,138,103,202,42,149,178,158,36,168,55,154,168,199,9,98,78,16,51,35,137,25,140,214,42,159,43,209,231,235,156,120,23,105,
34,127,172,176,163,153,164,68,174,181,137,40,4,55,141,18,22,225,90,76,150,176,64,218,162,206,70,60,84,5,87,196,218,128,90,114,134,12,112,107,113,208,115,129,69,16,49,23,111,100,54,24,24,224,64,186,220,
112,221,30,244,105,157,219,16,32,218,172,46,98,65,198,157,98,32,93,169,127,254,28,115,232,69,164,139,30,100,3,189,55,1,99,245,173,20,113,105,198,45,83,166,181,114,51,68,8,245,56,70,173,217,68,35,78,208,
140,19,36,146,32,17,91,0,185,164,29,58,157,197,103,165,9,140,178,20,185,166,151,194,104,115,177,120,59,181,36,159,111,197,69,12,129,120,46,233,26,134,229,227,136,74,29,201,168,238,150,146,125,182,131,
177,105,126,138,186,6,25,152,187,24,225,140,236,89,177,8,18,8,34,22,6,167,153,95,249,204,81,92,126,223,38,95,212,156,48,59,129,20,79,63,103,141,168,66,21,98,49,22,114,135,58,127,48,46,84,172,153,45,110,
44,195,223,54,7,219,33,160,17,111,93,191,184,18,133,206,115,187,148,243,136,206,127,145,54,251,30,73,250,149,86,116,183,214,136,209,72,18,36,73,106,218,64,208,108,198,168,197,9,154,113,19,113,194,6,183,
136,58,196,64,236,221,200,148,248,43,150,92,70,209,142,98,178,168,167,38,22,84,43,84,60,71,46,206,37,144,188,166,8,169,157,192,97,129,232,201,102,47,136,82,68,51,252,76,23,49,118,233,98,204,165,181,71,
52,237,41,109,103,214,142,188,143,168,24,156,173,29,180,96,175,71,146,78,253,220,89,111,121,86,169,147,222,198,170,151,54,158,128,143,33,209,134,5,32,210,193,104,146,238,129,67,41,249,226,103,158,252,
81,199,0,167,253,254,135,111,187,25,35,67,3,198,123,15,170,243,116,152,21,126,136,86,76,59,160,222,140,81,109,52,81,111,54,210,85,95,192,2,52,226,38,154,113,130,152,197,11,125,22,123,52,123,189,23,246,
133,105,165,189,195,237,70,158,197,202,71,42,209,48,38,41,201,19,51,23,90,24,225,60,241,44,112,212,17,74,23,109,26,25,215,112,239,49,143,127,232,246,167,109,205,118,193,124,73,102,24,110,6,51,131,19,70,
36,220,154,49,34,108,178,91,69,46,13,129,22,127,70,167,119,32,122,138,210,56,54,98,123,44,181,147,181,231,229,249,121,109,221,146,19,57,8,139,72,251,8,140,213,62,230,108,203,6,54,234,117,172,215,26,168,
55,155,136,83,120,61,78,24,49,179,58,175,79,98,212,189,150,8,195,129,12,141,141,128,173,152,116,167,248,130,24,209,111,18,128,169,12,253,179,210,114,197,122,96,196,240,108,60,30,63,11,38,97,210,50,223,
140,116,100,139,223,224,112,19,212,247,165,157,61,33,118,175,74,78,118,52,192,170,148,10,31,113,186,125,75,110,203,170,65,33,237,56,54,101,46,54,149,46,249,222,161,101,236,30,101,185,217,157,78,214,38,
221,183,171,89,238,247,180,90,165,217,168,237,138,144,117,127,156,196,72,152,33,2,36,194,88,175,213,177,94,171,163,214,140,115,20,168,220,15,34,15,202,231,135,44,242,149,87,60,72,151,116,130,59,178,235,
8,236,53,212,11,173,72,123,242,75,241,69,207,96,213,168,167,136,135,114,68,94,143,188,12,156,128,222,209,202,118,24,233,230,129,151,4,87,197,74,103,96,129,196,9,34,214,111,26,185,29,162,24,185,237,35,
161,62,167,186,211,66,239,39,63,74,41,146,211,30,44,144,182,100,180,78,66,254,228,12,0,171,29,218,230,150,214,138,95,107,198,72,146,150,73,180,217,104,96,125,179,152,12,86,120,164,189,123,158,162,40,210,
161,111,188,126,133,120,166,148,0,110,3,212,20,160,118,104,36,188,43,60,81,201,36,17,177,196,56,124,247,42,14,147,189,245,7,151,196,112,252,15,76,20,2,64,29,172,5,127,137,62,151,192,104,132,18,164,64,
199,116,176,48,2,23,19,131,21,46,46,44,122,71,42,250,128,202,67,88,101,168,136,94,160,115,108,27,86,74,67,135,40,179,190,62,107,65,11,11,52,104,69,119,91,23,213,56,58,195,19,23,148,34,122,83,4,69,45,59,
86,196,128,137,207,46,46,97,163,222,192,70,189,209,234,35,114,159,73,150,130,162,251,135,149,106,10,1,69,49,77,49,39,132,136,139,254,153,43,13,153,118,28,137,237,171,166,253,33,249,228,211,33,84,17,113,
82,70,200,218,208,141,202,2,198,254,32,133,53,68,69,106,5,89,51,151,165,100,111,23,11,204,241,76,110,187,31,11,33,23,1,49,25,240,175,173,181,65,186,253,156,62,83,81,125,148,45,62,86,61,70,74,129,9,91,
198,137,193,136,56,211,47,66,161,117,5,6,36,116,189,112,31,92,221,113,146,248,28,122,241,119,140,215,248,16,119,0,146,138,196,146,7,52,32,49,29,52,195,71,75,33,191,12,123,207,235,150,164,163,32,97,198,
234,230,38,54,234,13,52,227,216,49,177,230,150,86,210,7,150,151,175,205,7,8,43,216,178,112,112,11,155,120,160,167,130,169,93,195,152,28,222,129,193,158,30,244,86,34,212,227,4,213,122,29,107,155,117,156,
154,95,192,122,163,158,78,40,141,178,104,52,82,27,163,82,84,205,213,235,97,182,50,8,167,243,36,245,41,210,161,158,77,224,29,253,189,56,56,49,142,137,157,67,232,141,34,196,73,130,197,141,42,78,93,88,192,
194,198,70,142,56,65,33,90,66,150,96,136,26,19,237,66,113,162,125,132,124,129,107,45,13,34,58,193,78,237,17,162,130,3,30,200,88,132,12,71,167,88,140,172,197,198,22,84,81,85,140,53,170,197,150,230,27,4,
45,20,171,53,41,68,57,233,69,160,176,83,8,110,171,148,181,173,30,219,14,211,32,116,157,58,101,173,200,69,204,39,142,19,172,84,171,88,221,172,163,17,183,34,199,205,164,229,64,39,44,94,112,74,160,163,105,
26,81,49,87,242,158,40,196,141,111,218,139,235,246,238,193,145,233,41,76,14,239,232,216,39,179,75,43,120,250,248,41,124,235,165,99,168,54,26,150,47,72,182,39,226,69,59,254,223,223,253,152,113,206,153,
197,101,252,175,15,61,158,175,16,215,238,153,194,251,222,124,3,14,239,217,141,160,100,251,126,99,126,1,79,60,255,10,158,57,241,134,53,168,208,141,97,166,222,99,181,92,43,127,69,212,61,80,107,252,25,91,
151,151,95,109,47,168,46,76,42,165,70,41,249,253,51,189,218,90,66,119,156,48,34,78,146,22,138,133,76,237,161,133,184,180,252,15,130,143,245,79,214,255,77,26,74,249,208,245,150,51,246,156,203,197,111,76,
186,0,28,3,164,48,0,114,191,41,171,169,158,126,214,76,90,209,99,102,193,218,102,29,43,27,85,108,54,155,45,4,201,34,184,180,155,124,137,184,78,30,165,164,189,28,62,36,193,111,254,202,237,120,251,53,87,
161,183,82,217,210,162,177,103,100,24,31,122,203,205,184,231,230,235,240,208,15,158,197,183,95,249,169,187,246,101,245,212,179,251,150,150,57,81,150,141,151,97,251,97,24,226,99,111,255,71,248,213,107,
174,234,216,142,3,19,99,248,231,119,189,29,191,114,230,74,252,127,223,252,46,214,107,117,55,62,149,239,6,174,175,104,216,231,36,206,80,39,163,144,76,122,95,204,169,217,41,249,46,157,199,52,40,5,175,187,
173,193,232,237,12,49,178,111,51,120,55,15,131,72,198,25,75,245,124,19,70,36,48,241,223,124,139,201,160,68,135,75,69,10,70,244,202,170,193,12,237,152,115,152,253,160,101,105,76,30,14,134,225,11,26,113,
145,245,72,173,135,198,9,163,218,104,32,97,198,102,51,198,106,117,19,107,181,90,107,48,41,22,170,228,190,10,91,233,61,101,225,141,214,181,10,218,68,246,43,21,235,37,11,174,223,63,189,229,201,161,95,125,
149,10,62,246,246,183,98,255,216,40,62,245,157,167,212,226,194,233,115,181,28,93,78,159,82,89,190,42,17,254,197,221,239,196,77,7,246,109,169,29,55,236,159,198,191,254,224,123,241,39,143,60,129,181,205,
205,116,160,102,65,55,46,156,66,85,98,175,216,8,116,136,29,6,87,130,211,32,94,177,176,20,11,92,14,247,166,12,129,214,0,102,83,147,46,125,128,36,38,164,225,21,90,204,29,20,211,148,203,81,61,161,212,7,87,
241,64,17,176,36,173,72,122,225,181,171,112,187,192,202,139,115,233,34,236,76,94,51,18,78,22,204,205,228,238,15,228,1,223,242,137,228,129,103,196,202,70,211,19,175,86,111,96,189,222,50,149,170,245,6,214,
107,117,196,204,78,202,48,27,166,144,138,196,230,90,0,82,146,211,150,237,198,108,250,52,22,88,234,67,18,235,205,24,51,75,203,56,183,184,140,213,205,77,108,214,27,72,68,208,223,83,193,212,240,78,92,177,
123,2,227,59,134,156,235,189,243,186,195,152,91,94,193,19,63,121,89,41,155,102,38,137,118,50,211,165,171,36,224,115,255,237,55,27,147,131,153,241,202,185,89,156,93,88,194,122,173,134,161,190,62,236,31,
27,197,181,123,167,16,4,129,179,171,253,171,247,191,27,255,199,151,190,140,152,217,28,11,42,36,64,138,14,67,246,110,44,182,113,152,237,120,190,72,77,49,186,76,255,131,84,224,209,12,16,138,136,55,136,157,
79,131,172,77,204,10,248,81,99,202,163,249,155,48,35,130,66,176,144,250,35,45,20,139,77,4,201,107,205,217,105,153,229,52,135,2,101,32,239,228,104,27,120,243,8,168,100,171,205,242,122,21,171,181,116,82,
52,154,104,52,155,249,138,89,172,242,102,130,12,89,232,154,113,125,78,157,216,210,248,11,59,225,161,50,226,222,70,173,142,167,94,59,142,231,78,157,198,107,51,115,136,19,49,234,239,217,8,207,145,233,221,
248,232,219,222,130,43,167,38,141,75,126,228,31,221,134,23,222,56,131,217,165,149,2,12,176,16,86,177,1,46,245,26,25,28,196,251,110,185,33,255,251,217,19,111,224,211,223,121,10,203,213,77,7,12,25,30,236,
199,199,222,241,54,220,118,232,128,113,142,43,38,199,241,222,91,110,196,99,207,60,111,232,233,234,88,161,184,97,13,99,18,251,222,99,13,71,230,200,28,27,37,213,88,35,106,57,29,167,64,109,52,28,237,235,
87,177,117,137,211,65,32,122,185,85,22,84,182,73,36,66,136,36,139,226,170,237,37,251,82,231,24,157,108,201,233,182,163,27,237,29,108,55,203,92,88,208,136,19,44,172,175,99,117,179,134,102,28,163,30,39,
110,0,78,96,38,20,217,202,50,162,182,18,39,94,37,109,111,36,99,189,194,163,234,163,191,255,249,167,158,193,75,103,206,162,17,199,230,204,102,143,44,112,122,236,209,115,115,248,227,47,60,142,223,254,199,
119,226,157,215,31,201,15,137,194,0,239,185,233,122,252,229,223,127,223,140,24,91,237,47,235,247,129,222,158,252,247,39,126,242,18,254,250,123,79,59,118,124,214,166,165,141,42,254,175,191,253,6,254,233,
175,222,129,123,212,164,2,128,251,222,114,51,158,58,118,28,243,171,107,48,44,168,118,9,124,108,77,24,189,155,104,108,86,195,148,108,65,188,6,239,75,189,199,166,57,37,101,204,8,177,128,13,129,163,106,35,
134,107,145,242,177,56,201,96,94,245,133,212,73,55,80,6,39,1,197,239,25,217,50,8,240,186,191,182,195,109,141,90,149,224,148,48,35,78,18,212,155,49,46,174,173,99,181,90,69,35,73,148,45,235,243,90,212,217,
133,172,160,26,149,51,76,115,16,159,138,213,216,235,131,136,69,248,131,179,21,17,1,207,30,63,229,93,74,200,182,3,44,70,128,8,240,23,223,250,62,14,78,142,225,192,196,120,254,201,175,28,185,18,127,253,221,
31,162,214,108,40,81,109,115,251,210,113,59,223,235,165,211,231,240,224,119,126,152,198,7,172,45,144,204,209,245,153,239,254,0,251,198,70,112,253,254,189,249,241,149,48,196,93,55,93,139,207,124,247,135,
106,82,102,49,39,113,102,171,16,89,247,236,241,85,29,198,48,25,196,86,178,96,89,147,126,226,206,6,109,182,149,82,100,124,35,39,139,3,166,249,81,194,130,36,17,4,194,173,236,175,44,72,194,106,38,21,176,
87,139,171,197,249,79,150,107,144,49,129,139,127,139,128,35,171,127,57,205,38,19,227,115,163,126,68,250,95,35,110,98,165,90,197,133,149,21,188,62,59,135,231,79,157,198,171,231,102,48,191,186,138,122,28,
27,181,31,52,11,57,107,87,43,200,145,101,179,177,113,29,168,182,34,127,31,22,147,153,91,62,134,37,90,145,47,90,234,186,249,162,146,157,43,61,150,61,109,43,250,176,232,27,251,39,239,43,78,240,183,63,126,
209,184,110,79,20,225,208,212,184,113,175,118,191,139,74,88,114,119,62,198,167,190,253,100,218,62,157,255,195,96,184,207,148,69,240,169,111,63,217,210,176,85,175,59,175,185,10,97,64,86,63,176,53,30,36,
13,188,217,227,134,141,239,138,167,15,56,207,60,100,231,25,183,194,15,48,198,160,125,126,136,239,94,84,118,163,211,231,42,64,46,166,160,67,43,31,68,196,8,148,72,222,248,18,38,174,157,144,82,66,78,244,
29,171,75,133,176,178,27,235,205,38,214,54,107,168,214,27,88,171,109,98,99,179,222,90,51,236,149,78,97,215,102,116,93,114,110,146,145,72,99,163,96,228,83,26,17,23,151,111,131,6,229,12,3,242,148,79,32,
59,88,169,168,212,249,191,82,66,142,37,229,79,8,94,61,51,235,92,251,170,221,147,120,241,141,179,5,225,142,52,108,73,109,237,172,151,206,204,96,102,97,201,100,70,168,122,38,228,97,254,158,189,184,132,151,
207,204,224,70,229,220,15,245,245,225,154,189,123,240,194,169,179,128,147,197,147,30,79,54,151,139,44,210,40,187,91,52,185,218,47,94,182,111,10,113,59,230,148,184,185,175,246,6,146,251,190,68,138,148,
41,133,48,35,103,226,37,233,228,66,140,8,210,218,82,216,138,32,182,104,20,54,151,69,165,69,90,50,146,118,154,20,140,109,81,219,140,169,204,10,51,22,214,214,177,86,171,161,90,107,98,179,209,200,7,15,137,
5,123,229,16,157,201,125,145,188,114,144,114,54,148,93,76,134,121,37,142,49,44,121,26,42,114,200,49,191,3,46,153,32,82,4,192,40,203,115,200,32,98,38,107,156,74,14,123,230,7,178,242,106,85,170,40,229,218,
185,173,94,92,218,88,119,174,61,61,186,203,204,246,99,61,207,216,35,5,91,188,126,112,236,245,34,210,111,161,148,153,248,130,233,84,181,38,206,15,142,29,55,38,8,0,92,57,53,129,231,79,157,41,34,223,100,
145,254,124,69,133,80,228,252,56,246,40,50,196,218,195,234,35,79,48,48,99,7,24,126,164,88,92,25,81,67,134,242,56,81,235,57,217,228,25,197,195,82,190,14,197,130,72,88,191,93,152,59,156,5,101,60,238,181,
135,41,228,21,234,178,19,91,226,132,177,184,182,142,133,245,13,212,26,205,212,129,117,23,145,92,98,214,102,135,102,216,185,184,97,75,95,129,150,178,100,33,237,127,48,108,12,190,125,72,158,133,21,108,105,
242,160,216,178,169,245,120,60,48,49,134,155,14,238,199,155,198,199,176,111,108,4,59,250,251,208,215,211,131,190,158,74,105,52,219,126,13,246,246,22,52,119,54,217,179,172,57,88,158,215,79,103,207,23,177,
4,31,93,81,60,207,85,4,175,205,206,57,231,186,114,247,100,203,137,85,126,153,222,80,201,199,198,21,51,43,154,118,0,0,32,0,73,68,65,84,114,0,26,66,225,235,22,81,46,113,250,142,74,86,170,82,53,83,177,37,
229,220,251,52,198,170,184,80,47,179,32,97,180,82,110,179,173,69,127,193,206,206,148,18,74,169,145,90,41,105,224,40,95,225,25,245,56,198,90,181,134,139,171,107,88,171,215,115,19,165,140,251,75,22,26,7,
69,70,204,153,161,93,32,105,228,105,172,38,121,91,126,185,73,192,107,135,198,229,81,222,108,147,81,48,4,185,186,211,239,188,254,8,238,187,253,205,216,59,54,130,203,125,13,244,246,56,32,129,3,127,120,26,
29,39,9,206,46,44,153,38,152,157,89,80,114,207,51,11,75,136,147,4,81,24,230,239,141,239,220,97,32,74,90,12,162,148,111,231,121,78,5,65,215,236,83,39,206,215,86,30,75,188,96,145,157,54,44,2,39,119,133,
21,38,36,138,139,149,251,85,148,164,92,44,102,167,48,37,107,13,121,149,1,159,19,204,160,83,43,211,198,80,107,240,109,214,235,216,168,213,177,184,190,129,165,245,141,78,153,29,30,198,13,89,193,37,87,63,
0,37,177,147,194,135,128,65,243,54,249,0,102,206,137,46,41,237,34,118,190,29,132,12,21,13,29,108,204,24,186,195,253,125,248,131,251,223,143,195,211,83,216,174,87,79,20,181,72,140,148,153,15,228,39,225,
89,175,245,90,189,229,108,147,25,252,33,21,232,246,171,49,16,88,4,213,122,3,59,7,250,149,31,210,155,198,201,60,68,67,18,144,248,200,147,48,200,72,133,185,68,5,51,91,236,187,200,216,195,100,140,11,103,
244,40,51,140,172,56,153,25,176,242,100,40,42,213,119,167,64,104,18,103,162,13,200,181,139,116,165,30,13,129,249,161,220,226,253,122,163,137,229,141,22,157,99,105,125,3,113,98,38,125,154,84,121,15,175,
75,84,58,36,137,114,1,60,212,18,131,130,46,41,233,197,98,186,74,198,214,109,61,33,214,53,1,173,0,147,131,53,10,186,136,164,147,159,69,38,130,225,129,62,252,209,111,126,24,211,163,157,119,13,73,179,10,
155,73,226,92,111,160,183,215,102,139,168,132,54,157,193,159,249,66,254,28,143,205,70,163,160,17,105,67,202,182,81,196,214,210,109,253,93,173,215,141,9,146,237,100,34,126,115,71,236,5,79,220,10,11,102,
9,10,241,224,64,226,201,235,40,252,52,131,253,39,101,246,132,47,36,91,34,179,148,203,22,33,79,185,77,18,110,9,199,21,48,97,33,125,34,92,68,27,253,107,126,235,162,139,235,235,88,92,171,98,173,182,137,90,
163,233,216,122,58,174,193,226,146,12,181,248,115,182,231,137,14,244,105,243,200,78,199,205,157,21,113,77,80,45,243,98,163,77,12,15,215,190,59,153,75,22,143,128,179,126,64,4,252,206,175,189,211,59,57,
150,55,170,120,242,232,107,56,122,118,22,231,22,151,176,176,186,129,245,122,189,160,136,144,201,78,120,232,95,255,75,47,23,76,121,188,42,103,70,58,212,59,101,127,12,162,68,214,144,213,34,40,222,126,176,
24,183,109,178,194,164,52,254,83,46,55,238,140,35,135,132,104,102,32,58,227,35,219,141,8,86,255,166,190,44,217,85,137,165,184,39,5,42,20,116,119,195,254,114,41,221,154,215,82,107,54,113,126,101,5,75,235,
27,168,214,27,198,238,64,206,120,51,111,150,21,234,103,4,14,179,246,114,225,240,57,245,89,148,117,148,33,93,98,37,38,129,96,57,241,54,154,229,242,36,197,118,112,125,193,86,27,230,133,150,79,40,120,81,
135,247,236,198,219,60,108,217,135,158,124,26,15,125,239,233,22,151,137,116,96,208,26,12,105,27,122,163,200,187,123,49,139,39,123,176,189,227,212,223,219,211,242,51,213,46,68,6,251,156,140,93,94,196,132,
211,117,36,62,163,208,100,38,56,181,153,17,218,58,23,139,187,70,158,199,225,164,216,235,100,46,195,193,203,76,57,115,66,112,73,80,82,60,5,131,68,243,87,178,221,80,205,1,78,3,134,17,51,231,138,121,5,221,
151,157,21,167,150,50,98,47,44,175,98,117,115,179,20,254,244,243,78,220,42,67,66,229,49,19,41,59,198,94,85,164,228,82,48,147,139,28,13,71,241,201,114,74,27,245,14,43,146,110,152,15,100,216,216,111,61,
226,78,142,39,158,123,1,159,249,246,83,202,252,115,21,68,236,21,114,208,50,175,244,14,34,118,61,113,105,15,189,13,246,245,182,80,34,77,199,48,42,124,177,101,118,21,190,89,64,228,180,101,163,150,129,45,
86,94,138,184,17,110,17,51,0,32,30,93,69,45,66,228,248,155,105,38,161,120,86,76,105,55,25,80,50,254,236,247,84,150,21,219,249,32,28,35,146,68,17,20,211,248,71,152,178,57,227,132,177,182,217,242,41,230,
87,214,16,115,114,25,98,208,190,4,251,110,78,2,107,57,217,234,117,203,7,14,161,93,102,182,116,156,32,190,123,185,241,192,126,231,152,47,62,249,140,201,54,133,23,230,49,78,57,53,50,92,30,135,217,162,8,
94,37,12,177,103,116,4,103,46,46,182,185,79,255,10,183,119,124,212,64,176,0,224,194,202,106,145,138,44,102,158,123,217,243,46,215,210,44,151,246,113,124,26,177,131,138,94,248,178,100,76,180,97,254,41,
144,166,168,47,41,224,4,136,18,93,254,32,253,111,173,90,69,204,130,185,165,101,172,84,55,93,251,48,181,113,72,0,95,234,82,23,227,12,134,44,95,137,133,64,158,133,160,84,66,90,193,133,25,138,66,206,231,
126,75,87,60,105,92,84,234,164,139,199,93,41,70,250,232,208,160,227,119,156,95,94,241,48,198,200,99,29,21,87,191,102,239,30,191,117,110,9,241,161,13,186,163,95,87,79,79,225,244,252,130,71,188,160,189,
134,229,213,123,118,187,49,149,153,57,151,94,238,211,60,50,86,34,55,122,230,123,38,32,141,16,250,16,69,141,224,217,133,138,252,212,234,130,47,166,158,22,217,59,29,27,98,37,44,2,38,70,68,202,107,135,8,
106,181,186,188,118,110,22,141,132,29,145,228,2,223,96,75,95,200,151,29,72,185,47,80,10,203,138,25,234,35,43,34,34,78,246,135,69,236,179,196,14,108,249,26,209,231,241,76,84,67,84,193,35,70,35,101,48,175,
148,87,190,26,234,239,179,204,145,90,154,95,110,34,48,82,66,242,207,134,208,59,110,184,198,187,222,153,129,74,120,228,227,252,175,95,189,246,48,190,254,147,23,141,100,86,123,7,213,227,56,235,217,59,175,
59,236,156,235,232,217,25,67,228,28,214,226,37,70,207,107,223,67,12,45,124,246,141,15,214,138,252,126,218,137,153,120,167,115,89,185,36,250,5,104,209,84,201,225,93,49,204,94,86,242,187,105,189,156,194,
196,202,157,147,36,105,161,81,65,208,98,69,146,153,79,168,105,9,6,45,196,154,225,6,96,68,38,210,192,25,203,51,227,193,168,14,43,114,0,196,43,37,36,98,166,112,154,252,96,183,13,62,5,191,108,165,97,18,199,
121,23,133,205,151,208,121,13,16,76,3,190,148,74,0,237,232,47,32,209,93,131,131,5,133,135,124,17,92,149,46,155,218,224,183,95,125,8,251,199,199,252,22,129,24,224,110,30,41,238,132,193,221,116,197,155,
176,119,108,4,103,46,46,21,89,116,16,67,165,198,180,96,4,251,199,198,112,211,193,55,153,49,149,205,26,94,56,249,134,145,47,148,245,62,27,30,157,185,155,23,28,52,19,185,20,143,146,138,189,76,154,195,156,
204,40,60,101,253,160,192,126,37,230,144,75,159,170,113,33,164,4,91,179,49,200,86,86,45,51,36,150,150,137,197,108,178,65,89,4,148,231,169,151,59,211,126,180,142,76,56,18,118,116,154,114,116,76,83,197,
141,9,216,214,107,96,63,129,209,247,125,241,123,25,98,5,142,196,23,72,42,25,109,204,236,177,156,139,41,189,176,186,110,76,144,193,190,94,92,187,111,15,94,62,125,206,82,237,208,73,92,197,250,58,212,215,
131,255,238,253,119,149,195,204,236,171,180,215,89,5,51,12,2,252,243,123,222,141,255,229,83,159,51,117,81,60,125,153,189,245,223,188,247,93,185,63,154,189,190,241,252,203,168,103,73,105,162,247,5,223,
84,45,164,222,10,50,41,219,17,43,227,115,115,192,80,121,60,74,61,51,113,246,39,192,204,89,112,119,59,27,92,176,25,209,25,27,56,72,243,108,157,40,162,169,17,84,82,28,222,87,44,62,149,16,50,142,53,126,50,
202,178,85,228,94,209,153,203,175,101,21,133,207,233,234,234,124,198,117,165,253,185,140,182,139,243,89,153,147,92,156,211,190,142,224,133,83,167,157,99,254,235,187,223,133,40,12,20,181,158,189,125,50,
212,215,139,255,237,99,15,96,124,231,142,182,129,69,243,217,176,115,63,101,175,91,14,29,196,39,238,126,87,201,179,49,255,254,221,187,223,141,91,14,29,52,142,111,38,9,30,123,250,25,71,63,74,140,251,17,
115,44,180,235,115,239,223,98,61,19,246,60,31,152,192,18,216,61,214,232,31,223,231,122,28,138,251,60,83,116,55,96,112,254,192,56,189,41,246,77,22,46,72,92,54,159,94,84,101,170,92,17,66,23,34,49,190,11,
147,247,197,138,98,207,48,222,19,225,146,118,176,243,144,204,220,21,24,223,111,229,88,180,57,167,245,57,139,46,89,224,14,208,226,187,112,250,231,219,47,190,226,28,115,100,239,30,252,241,199,31,192,212,
200,206,34,133,56,75,206,73,175,247,43,215,28,198,159,254,222,63,195,225,212,57,95,92,91,47,117,210,179,140,183,226,33,11,116,192,215,126,109,212,234,185,226,227,135,223,118,59,254,231,7,62,132,145,161,
1,111,223,142,12,14,226,223,254,198,253,184,255,109,111,113,206,243,55,223,126,18,231,46,46,123,7,179,51,30,216,157,68,236,125,134,109,126,52,203,131,225,14,244,60,168,13,107,44,137,219,62,88,199,24,19,
72,181,43,79,59,71,139,172,168,27,164,43,6,177,55,194,98,255,73,165,85,125,196,78,26,113,206,100,71,22,237,10,65,30,133,178,82,92,207,47,25,74,150,228,132,216,249,7,214,223,90,0,77,50,73,27,159,137,67,
84,170,179,251,242,233,179,120,250,216,113,220,113,228,74,227,253,27,14,236,199,127,248,151,191,135,23,79,157,198,177,179,51,88,221,220,68,127,79,15,38,119,237,196,109,87,29,194,168,18,108,96,22,252,187,
47,253,45,254,248,191,122,192,27,40,244,5,131,164,77,127,205,175,172,226,135,199,94,199,111,188,227,109,169,227,125,4,111,61,114,53,126,114,242,20,78,204,94,192,106,181,138,157,3,3,56,180,103,18,183,28,
58,232,152,85,0,112,236,236,12,62,251,157,39,213,238,218,70,127,185,212,33,242,49,112,187,131,172,165,221,247,141,90,10,30,115,203,115,201,34,115,34,83,89,17,3,234,205,72,188,81,190,26,66,173,176,44,173,
226,209,78,96,193,46,162,229,159,56,6,103,42,83,48,84,197,198,116,180,214,28,167,58,56,168,203,185,181,83,3,246,120,24,68,238,132,104,83,5,151,44,91,188,157,104,67,30,193,69,73,137,122,1,254,207,47,61,
134,63,253,189,223,198,212,200,46,227,216,32,32,220,124,232,0,110,182,4,17,236,29,234,255,254,242,215,240,163,215,95,111,179,44,120,67,252,22,217,208,124,253,229,215,191,141,43,118,79,224,142,52,144,25,
134,1,110,187,234,16,110,187,234,80,199,193,121,98,238,60,254,237,95,125,22,205,132,205,254,47,147,211,20,88,227,196,130,201,136,186,136,229,72,174,49,102,106,141,150,32,200,222,152,142,171,214,166,178,
103,82,149,77,134,4,148,238,200,80,153,133,2,201,216,188,78,4,81,184,165,243,100,69,124,11,137,205,114,240,181,60,90,87,136,58,231,26,171,206,247,77,236,219,173,93,209,46,192,68,110,140,197,27,86,117,
181,87,40,203,130,203,178,235,218,209,154,146,22,152,232,71,93,144,154,71,27,248,131,255,248,41,252,209,111,253,122,110,50,117,243,90,219,220,196,191,127,248,43,248,206,75,175,150,243,154,152,203,113,
132,54,13,143,147,4,127,244,224,231,240,63,222,127,47,222,115,235,77,93,183,233,251,175,28,195,191,251,210,151,177,86,173,230,217,130,74,59,52,215,22,131,87,219,70,188,237,51,250,219,97,17,155,65,92,51,
30,34,229,123,142,194,251,115,104,198,202,97,48,33,13,53,1,147,192,76,157,206,200,138,113,130,136,19,13,31,42,78,10,43,8,82,172,88,143,104,72,20,37,197,98,77,232,84,151,219,18,11,246,53,86,102,131,100,
104,37,241,144,187,80,233,234,84,94,107,171,180,128,135,203,56,237,6,17,202,225,90,175,245,73,185,169,118,97,121,5,191,255,201,191,196,251,111,127,51,62,114,231,29,152,30,27,45,61,231,226,218,58,190,246,
227,23,240,133,239,253,0,75,27,213,156,134,94,234,164,187,73,137,121,118,157,148,215,58,70,28,11,254,228,11,143,226,155,47,188,140,223,250,199,119,226,134,3,251,189,181,27,69,4,47,157,58,131,47,62,249,
67,124,239,149,99,176,201,116,121,21,167,156,61,111,169,38,106,8,86,44,0,50,227,130,89,207,196,38,27,138,93,185,140,74,170,113,216,120,187,189,102,217,76,95,35,83,186,101,70,145,230,35,102,109,103,6,152,
17,129,253,78,117,0,183,161,165,204,4,197,152,21,61,75,236,68,63,105,195,173,19,114,41,5,93,80,141,164,3,57,180,96,168,88,61,92,150,40,164,230,225,239,254,251,79,250,43,2,181,99,7,168,208,74,147,99,60,
252,212,143,240,200,83,63,194,222,177,81,92,179,127,26,195,131,3,232,239,233,65,189,217,196,194,218,58,78,206,93,192,169,243,243,222,123,186,235,223,252,239,158,154,99,38,15,201,73,42,42,179,253,85,71,
253,232,216,235,248,209,177,215,49,50,52,136,107,246,239,197,158,209,93,232,239,237,193,218,102,43,177,237,181,51,51,184,184,186,86,146,124,230,50,133,68,80,154,73,90,54,110,196,195,139,42,125,134,240,
247,65,71,104,94,58,179,151,36,103,154,91,96,82,26,148,141,88,18,75,161,67,44,39,157,204,220,71,39,160,109,15,60,49,87,63,66,169,240,66,185,107,64,118,104,182,227,238,221,174,188,184,183,227,219,92,223,
105,174,88,245,201,109,209,38,178,42,100,89,231,23,0,103,230,47,226,204,252,69,56,181,23,180,239,70,37,58,91,228,17,149,2,185,89,100,109,160,233,156,166,175,230,251,194,218,26,190,255,242,209,210,69,195,
200,58,116,248,80,166,229,92,184,9,228,21,107,240,46,78,228,153,1,84,110,53,235,252,17,51,219,203,234,83,199,34,111,159,54,41,164,16,64,157,15,194,169,54,175,13,121,130,25,146,35,25,2,226,54,101,113,68,
252,129,2,21,45,183,15,115,139,127,194,40,214,152,135,113,236,61,149,225,113,176,201,155,13,104,146,145,221,81,75,190,149,76,181,219,65,59,52,165,194,174,152,36,110,224,14,109,10,219,82,9,113,88,218,237,
206,246,202,32,154,40,232,41,224,82,134,2,137,69,223,81,147,48,67,49,137,200,76,76,19,178,72,177,69,127,219,89,13,196,98,41,25,186,52,19,83,71,204,6,57,84,37,116,177,105,94,172,152,16,218,20,102,215,145,
87,109,215,234,154,164,209,201,124,160,80,11,152,82,177,184,108,30,70,146,184,186,88,69,36,61,139,125,146,103,50,40,186,152,229,15,152,35,148,84,102,159,75,13,49,83,41,185,84,56,218,144,43,21,31,251,75,
188,4,60,18,91,97,152,60,182,129,158,185,118,109,63,242,103,182,139,175,174,21,123,77,66,23,245,51,151,73,18,155,195,84,86,251,132,173,73,46,133,252,144,131,198,185,206,189,192,98,223,102,233,174,176,
226,62,118,73,186,156,2,36,185,216,183,95,162,195,18,208,75,219,203,118,166,39,200,204,9,210,237,208,20,68,201,214,69,13,6,216,103,116,205,128,252,126,178,138,84,162,185,88,108,116,103,107,204,82,17,79,
98,21,204,101,110,149,96,203,157,191,84,238,166,165,104,18,22,26,182,10,233,49,100,115,50,164,33,67,126,180,227,40,80,242,245,197,205,21,249,195,226,143,165,216,157,175,30,76,6,249,233,114,41,98,171,41,
42,71,89,11,75,147,178,97,116,44,134,28,110,117,150,77,71,234,252,200,209,173,130,109,106,183,150,20,25,17,22,176,104,174,218,4,83,172,54,215,146,18,147,155,202,214,195,39,203,31,209,177,170,92,100,29,
132,119,252,79,127,100,104,71,193,30,62,101,169,47,66,58,43,195,148,65,82,105,200,169,224,17,108,229,76,91,217,210,166,26,138,66,175,50,157,102,49,244,7,68,21,251,41,38,107,121,53,92,93,200,154,220,138,
41,98,182,87,224,114,159,19,97,4,84,136,26,22,234,62,140,36,137,91,129,66,102,54,41,19,12,179,110,158,232,64,155,184,122,44,42,69,209,16,146,99,77,205,118,189,105,173,123,36,14,195,40,77,249,101,41,4,
24,68,113,121,212,86,66,100,62,64,95,174,150,206,81,247,213,248,51,160,22,93,181,136,196,32,9,154,131,170,176,131,141,29,140,204,226,223,210,182,200,75,218,174,220,42,203,224,83,113,10,117,138,199,43,
38,167,236,153,24,138,48,174,233,109,7,171,200,74,80,19,3,217,19,18,127,213,96,85,251,93,60,98,197,162,157,29,98,203,140,45,196,10,73,17,68,197,147,159,174,181,210,164,196,235,214,62,146,136,167,2,33,
41,54,86,58,94,116,120,133,141,200,189,138,180,39,72,197,171,51,114,161,10,189,219,6,186,216,24,154,210,102,146,108,117,203,62,102,203,248,214,121,184,100,102,114,181,108,86,165,240,151,51,124,21,126,
157,11,241,177,237,89,153,98,114,186,4,154,213,158,194,183,206,130,136,100,218,107,68,160,180,20,118,238,63,101,246,168,150,102,16,178,132,209,204,130,66,246,64,200,244,102,13,168,50,109,140,30,123,69,
105,8,206,11,46,21,102,71,97,159,106,59,158,242,152,84,145,99,157,163,91,233,245,73,111,233,68,22,92,155,154,28,249,119,88,165,200,42,97,54,53,17,136,179,65,169,252,16,18,135,136,73,164,76,102,70,94,203,
195,113,254,93,60,223,52,64,211,148,96,206,22,66,139,100,73,234,249,231,26,103,186,30,100,86,36,85,97,206,121,220,38,31,39,228,148,33,204,168,50,81,46,216,11,205,89,100,100,161,116,79,57,122,99,162,228,
190,131,184,69,17,200,7,209,137,205,170,84,78,175,165,192,39,40,199,2,236,60,4,113,68,230,124,206,113,155,172,70,49,5,229,220,196,41,203,151,17,187,110,183,248,243,168,0,139,177,10,131,97,74,109,32,234,
118,234,42,166,71,35,70,230,157,43,136,102,7,209,236,123,86,59,152,85,219,195,244,29,92,170,136,237,247,144,83,27,82,252,192,4,92,160,146,202,176,13,41,220,0,199,220,18,31,239,215,205,20,164,18,181,154,
60,39,69,109,64,34,45,173,204,4,9,162,164,153,80,58,43,72,68,2,161,32,146,156,136,164,215,108,75,31,203,17,8,17,39,173,74,148,86,174,169,149,68,237,80,69,147,207,67,86,169,219,18,7,222,28,162,228,73,176,
241,4,58,196,21,125,107,73,14,81,73,245,44,113,185,63,190,88,164,141,130,91,99,220,16,172,32,50,39,131,139,32,59,101,18,28,243,202,234,67,246,32,229,197,254,84,86,225,133,74,209,123,66,9,252,237,137,102,
219,22,153,119,236,168,235,177,231,121,25,247,148,85,44,38,229,208,163,13,44,78,37,84,59,31,106,110,154,191,36,68,145,8,7,34,2,73,24,146,36,136,16,138,72,44,137,48,215,32,146,212,151,46,246,198,155,213,
141,168,175,127,208,6,51,236,42,66,26,87,47,44,47,109,74,136,105,127,139,138,194,234,122,29,86,248,196,94,85,124,49,24,127,41,105,49,86,103,241,28,163,7,150,185,35,232,224,155,43,35,68,228,40,17,153,177,
42,42,42,172,26,122,213,236,206,32,163,50,150,148,168,115,228,8,142,169,230,225,139,27,194,2,71,68,153,153,2,159,36,142,214,212,85,144,46,21,136,35,43,22,8,91,139,162,165,56,100,204,38,22,171,250,24,153,
187,149,222,141,116,217,54,173,130,98,250,177,106,183,181,86,26,134,155,106,158,171,220,148,105,52,232,103,199,69,131,226,205,141,106,125,113,161,15,130,4,64,29,132,56,17,70,120,197,161,43,42,73,194,55,
39,205,230,46,14,163,241,164,86,221,217,152,59,247,122,255,161,171,39,8,68,134,89,144,214,114,19,41,124,0,33,82,51,91,12,137,151,60,58,158,107,182,145,42,214,110,202,193,120,147,136,242,220,130,244,186,
100,169,32,102,215,32,197,229,79,49,124,77,103,16,109,183,74,129,76,217,57,35,208,218,106,121,78,66,209,14,189,254,137,173,228,145,247,135,101,74,17,169,251,205,250,143,172,18,203,86,37,45,237,180,90,
37,221,12,249,35,171,239,50,103,151,172,60,24,164,8,96,86,139,47,119,223,132,172,5,172,144,156,21,79,228,91,148,194,97,65,23,34,245,44,69,33,97,48,248,72,122,113,17,141,128,26,215,35,24,202,170,226,211,
212,37,195,225,22,163,54,53,121,114,71,138,231,162,30,147,185,112,38,204,23,190,254,248,177,102,181,186,15,65,184,218,91,169,28,235,235,235,123,173,39,138,158,142,152,65,149,158,158,229,70,189,49,135,
102,99,133,89,70,194,161,29,195,34,45,28,203,44,52,47,38,169,42,21,83,21,37,179,77,10,42,205,166,113,81,242,140,149,63,64,134,169,146,167,103,146,79,229,59,149,251,100,86,91,12,169,186,124,170,88,14,137,
242,73,37,79,133,101,82,106,243,22,66,146,59,145,112,11,136,138,157,236,175,156,90,91,248,147,115,167,82,133,165,196,206,173,86,168,148,152,169,194,44,150,217,67,138,76,105,85,164,34,88,81,238,116,226,
17,137,27,77,82,166,128,93,52,179,117,225,66,205,93,148,175,69,186,134,57,84,1,83,242,112,93,136,242,202,200,118,161,164,124,87,78,183,52,173,201,69,100,130,181,26,105,210,147,159,28,150,117,97,126,80,
46,133,164,208,41,85,8,148,168,5,20,176,207,236,76,93,148,96,112,104,23,175,173,86,66,208,114,24,133,115,61,189,61,11,177,8,162,103,159,121,102,229,250,27,110,124,92,132,175,33,145,6,68,36,174,215,123,
164,197,121,55,133,34,28,218,128,56,38,152,88,108,207,114,14,150,120,66,254,162,252,26,11,241,176,241,74,139,212,168,61,60,179,66,148,229,52,146,248,217,242,226,41,141,38,122,160,194,169,207,237,117,157,
9,126,121,83,235,30,109,24,82,27,203,110,247,138,71,236,142,188,132,39,51,45,194,42,193,236,201,72,53,189,99,75,205,210,182,41,161,234,253,149,40,170,107,122,186,147,137,45,46,233,80,107,7,24,94,165,245,
92,181,20,105,97,138,105,237,223,244,220,228,246,155,141,202,234,221,46,173,160,43,73,163,209,3,17,33,162,134,176,172,1,244,229,103,159,121,118,61,2,128,141,234,202,76,68,209,5,98,158,163,48,220,83,187,
48,183,99,249,153,167,142,14,223,250,214,107,17,4,228,5,212,141,7,224,241,104,85,82,17,249,100,41,52,138,149,71,186,138,129,207,98,150,100,206,87,26,205,189,145,66,45,176,157,172,71,17,240,178,10,21,138,
11,69,27,230,177,192,159,28,85,198,190,183,35,85,82,152,34,57,214,192,150,63,99,24,247,30,190,89,110,26,144,242,35,84,104,210,70,53,44,153,73,189,170,19,43,167,64,55,128,225,139,40,234,232,99,7,4,193,
215,110,50,22,74,112,27,231,158,81,34,175,40,121,127,25,136,21,21,138,40,121,31,151,169,48,150,61,167,172,28,53,51,175,252,240,187,175,214,23,230,15,2,88,11,136,46,80,16,92,168,173,213,103,1,32,2,128,
157,131,187,250,226,184,185,217,108,198,51,32,186,146,227,120,95,99,117,101,7,3,68,162,171,209,8,28,221,124,241,70,145,92,230,1,163,52,199,201,132,34,253,200,145,24,116,12,83,183,191,48,85,196,85,81,132,
120,124,28,118,233,41,22,34,225,6,54,169,132,142,106,213,232,118,234,11,232,149,93,99,248,228,4,44,205,27,37,107,137,213,80,184,189,66,43,189,16,33,171,110,160,214,175,181,182,39,177,61,99,152,108,9,177,
150,121,5,153,154,231,178,189,95,93,100,144,11,117,118,233,130,81,234,9,241,219,129,76,97,189,235,136,225,139,34,151,88,34,171,184,82,97,242,102,62,106,144,174,192,141,181,149,29,44,50,24,4,225,169,48,
138,206,85,122,122,170,97,20,14,0,88,139,66,128,194,36,92,229,128,191,27,134,225,254,160,217,156,79,68,118,55,150,23,7,154,43,75,139,149,225,145,81,1,27,246,98,171,243,217,51,59,197,244,85,152,140,173,
142,196,183,82,146,233,21,218,43,183,33,56,108,210,183,201,209,79,34,75,4,214,98,25,251,56,78,36,150,98,189,197,238,17,238,32,36,43,37,4,99,113,87,68,145,84,114,198,7,228,155,66,202,5,61,70,91,149,102,
41,55,147,1,202,170,6,166,56,38,142,145,51,227,240,227,85,67,185,144,98,207,229,113,196,132,107,53,113,80,183,23,100,1,182,98,214,66,215,229,231,72,215,130,54,240,75,241,155,151,208,34,212,98,219,82,14,
229,7,194,173,186,47,217,187,105,155,69,237,226,9,3,241,242,194,98,99,121,105,80,68,26,1,209,66,16,4,243,97,16,126,255,197,23,94,88,3,128,240,186,235,175,15,95,120,229,5,30,25,219,117,65,4,55,39,113,188,
75,194,112,60,105,52,70,155,23,102,103,250,14,30,30,201,40,85,133,191,201,150,98,136,71,149,132,117,70,88,171,227,13,244,74,138,26,14,89,134,34,171,78,213,180,23,129,186,166,40,1,105,81,21,121,115,68,
138,85,165,44,56,215,132,163,194,2,87,184,91,204,18,16,162,203,115,217,170,43,74,108,93,255,100,14,119,214,126,201,162,244,142,26,138,125,191,38,85,38,19,99,128,125,140,37,212,80,32,130,98,182,65,181,
145,21,101,72,96,93,91,138,54,230,37,30,180,66,137,209,206,226,122,57,135,15,30,117,28,3,125,18,11,33,100,143,242,137,22,79,215,229,209,68,255,163,148,71,196,66,208,224,94,59,167,9,177,66,189,50,68,150,
249,226,55,191,50,155,52,27,211,20,4,139,81,37,58,214,211,219,251,114,156,196,95,92,92,92,228,27,111,184,145,2,78,18,9,1,138,40,236,141,162,104,54,138,162,19,72,146,147,66,212,172,175,173,78,85,79,190,
246,70,62,8,82,245,197,214,85,72,227,136,38,197,66,108,60,47,219,70,213,214,171,62,203,210,123,73,196,250,142,231,188,98,194,135,164,32,103,211,60,33,51,37,86,196,109,147,211,118,117,109,253,68,32,158,
182,75,187,25,167,104,254,98,29,47,6,172,106,152,51,101,231,19,27,223,245,124,214,169,13,82,152,96,5,244,106,7,103,168,228,188,240,62,55,227,7,118,191,216,199,146,213,70,42,57,159,213,207,58,112,100,212,
209,244,152,244,226,224,210,230,53,33,249,24,102,73,176,254,250,171,167,227,205,234,30,0,141,32,8,78,84,42,149,227,149,158,202,108,165,167,210,7,0,47,190,244,162,68,175,30,61,202,71,142,92,19,188,252,
234,171,171,71,142,28,126,36,170,84,38,194,102,243,56,83,176,59,169,215,222,180,242,252,211,107,189,251,14,54,195,74,165,2,104,85,15,127,153,179,82,78,129,27,235,85,246,174,237,160,180,241,234,51,150,
169,79,229,34,55,235,164,77,209,87,241,219,192,206,181,237,244,126,111,24,211,19,175,247,103,252,136,134,193,219,114,8,172,227,219,232,0,123,255,166,60,39,54,133,168,217,106,155,88,62,172,56,68,40,87,
39,220,46,62,227,49,70,173,196,185,220,31,36,107,161,240,30,79,37,231,34,47,23,199,208,226,245,34,171,30,26,188,14,41,16,192,141,70,99,245,133,103,251,152,121,48,8,163,19,81,20,29,143,162,232,76,146,36,
143,191,118,236,181,92,115,41,4,128,177,177,81,90,90,88,64,216,91,217,236,235,237,235,23,145,17,142,155,17,136,118,113,146,140,84,79,28,61,215,187,255,80,47,133,149,138,165,67,236,69,52,200,77,29,65,233,
113,70,57,90,23,21,244,127,80,114,125,205,106,144,82,94,138,255,45,91,60,195,147,107,47,157,80,44,133,72,145,197,235,108,215,94,93,90,27,112,211,147,75,197,49,202,197,62,58,168,128,251,191,95,22,165,39,
248,132,69,200,228,89,149,32,91,98,113,85,75,251,207,183,158,82,121,155,224,75,49,246,125,14,43,137,136,128,120,179,186,49,255,149,47,158,23,230,73,4,180,16,85,162,23,123,122,123,95,141,162,232,169,159,
190,246,211,87,117,147,66,0,88,88,88,144,43,175,186,42,60,243,198,105,30,222,181,115,38,164,224,26,128,26,156,36,49,19,13,115,156,236,174,30,63,186,216,59,181,175,25,244,245,245,3,150,250,160,157,104,
159,235,208,22,28,45,135,96,102,207,124,177,35,198,162,162,195,37,133,28,45,234,188,33,58,145,63,117,113,32,106,241,212,23,97,59,76,109,180,87,172,240,178,133,174,57,239,139,74,64,42,138,67,102,78,186,
118,96,141,214,91,155,175,144,46,62,105,162,212,5,231,163,144,109,130,248,114,151,124,85,160,252,18,140,38,157,190,172,96,170,101,114,193,148,141,205,102,4,11,156,184,20,218,25,22,86,129,81,241,145,84,
109,186,1,60,53,97,196,142,213,152,249,248,141,197,139,11,11,223,120,124,83,88,38,41,160,139,81,24,254,184,167,183,247,229,74,165,114,38,22,121,120,101,105,41,57,124,248,48,45,44,44,148,173,167,192,149,
135,14,93,207,34,119,55,155,205,137,70,189,126,109,204,252,102,142,227,41,34,90,27,190,253,206,70,255,222,3,211,112,160,190,203,120,93,114,205,145,45,28,187,77,47,111,86,235,118,182,193,145,247,232,230,
220,86,49,152,203,122,6,158,147,180,251,236,103,242,160,225,155,233,93,29,234,227,135,101,191,214,206,156,58,183,242,236,147,125,2,12,81,16,158,171,68,225,115,189,125,125,175,84,42,149,121,16,125,253,
196,241,227,175,218,231,51,42,163,28,58,116,136,150,150,150,176,180,180,52,191,107,100,215,233,32,8,118,131,104,83,226,152,132,48,198,73,50,89,63,119,154,36,137,103,42,99,83,195,26,216,182,99,73,54,76,
110,228,228,219,193,55,103,59,164,114,206,186,111,239,245,69,119,61,49,23,131,174,160,216,125,100,135,66,197,22,68,176,254,38,88,169,147,174,57,86,198,206,53,219,86,104,75,249,110,215,76,76,182,180,161,
108,155,159,76,147,198,23,170,161,82,17,11,242,247,97,73,223,147,83,189,214,211,23,40,51,171,109,253,50,51,175,199,111,137,146,197,64,176,206,98,203,11,89,187,58,179,200,218,75,63,62,181,246,210,115,227,
34,50,28,4,225,133,40,10,127,220,219,215,247,124,20,85,206,1,248,210,201,19,39,78,1,192,161,43,175,164,165,165,165,114,139,252,138,43,174,160,147,39,79,74,8,208,244,254,253,253,68,116,95,163,94,127,75,
163,209,184,45,73,146,91,68,100,132,128,205,202,200,216,185,93,119,222,117,32,140,194,138,40,179,42,79,138,39,31,13,150,220,98,117,104,239,115,154,1,188,34,135,216,153,133,42,255,216,16,207,207,179,199,
92,145,2,175,90,9,224,169,6,105,138,143,137,179,26,152,65,40,242,105,90,104,31,73,145,253,204,96,153,88,162,32,84,16,8,169,164,88,166,180,31,220,164,10,177,250,54,38,201,233,22,42,85,129,252,241,95,189,
112,217,52,126,42,25,255,112,250,189,64,2,204,126,40,155,138,166,224,129,211,255,249,252,212,129,197,34,69,156,227,102,115,233,219,95,123,35,94,91,217,39,64,31,136,22,42,97,248,92,79,111,239,179,149,158,
158,103,193,244,232,233,179,111,212,179,13,226,196,137,19,210,193,101,117,95,123,166,166,62,146,36,201,59,226,56,190,34,97,62,36,34,211,96,233,167,128,102,71,223,243,161,201,168,175,127,176,192,113,116,
192,168,221,38,104,231,37,136,89,151,163,99,41,45,178,146,243,203,203,236,216,117,8,179,28,12,113,249,46,78,80,172,248,199,30,93,106,64,9,57,58,7,94,68,10,154,68,231,87,10,245,201,112,105,219,206,76,208,
210,90,129,84,234,195,251,223,51,239,135,200,170,79,158,231,96,184,253,41,54,176,162,111,134,208,1,37,4,76,53,20,43,211,209,102,38,80,25,114,87,112,182,200,224,143,81,94,143,38,174,86,215,23,255,238,209,
5,17,153,34,162,13,10,130,179,97,24,156,136,162,202,169,48,10,191,53,51,51,251,104,167,177,31,182,251,112,223,222,189,193,234,218,154,172,175,175,191,186,115,120,120,35,8,194,136,64,243,16,110,32,160,
225,132,121,119,237,248,209,213,96,199,206,77,84,42,66,149,74,143,233,203,181,73,239,243,56,206,94,148,78,202,157,1,27,10,247,73,31,101,14,184,199,141,46,157,190,54,253,193,113,82,97,102,190,123,157,216,
54,55,224,228,204,219,121,250,62,116,6,112,68,163,139,96,31,121,111,68,164,61,184,101,103,118,250,92,154,178,187,54,217,2,210,230,26,165,143,220,251,177,56,0,72,91,153,108,19,254,79,135,67,92,221,88,171,
207,157,91,94,254,222,55,154,2,140,19,209,66,24,132,207,86,42,149,103,162,74,207,177,48,12,191,60,51,51,251,141,110,54,135,142,59,200,244,244,222,96,102,230,28,3,192,158,61,211,215,138,200,61,73,220,156,
108,54,155,215,37,204,55,11,243,62,136,4,68,116,177,255,170,107,155,61,211,251,122,122,118,141,77,100,42,28,130,50,11,96,27,156,251,203,121,209,118,53,161,93,62,225,207,170,93,221,124,169,60,237,207,87,
86,200,252,118,59,133,190,237,234,208,178,88,80,137,153,152,81,139,124,200,105,106,74,52,22,230,47,212,103,206,52,107,39,95,235,19,145,81,16,197,65,16,158,9,3,250,73,212,211,243,74,20,69,11,32,250,202,
236,204,204,107,0,176,111,223,94,58,123,246,156,92,214,4,73,39,70,48,59,59,195,33,64,19,187,167,246,136,240,125,73,146,76,199,113,124,85,194,124,4,20,28,16,78,118,10,115,133,64,171,189,251,14,212,193,
201,90,101,108,2,189,7,174,186,34,8,195,32,51,114,115,187,210,50,23,96,251,21,90,200,65,19,213,28,97,90,37,62,173,76,131,2,158,85,185,27,98,10,68,64,153,92,98,111,245,217,86,45,166,194,120,110,158,89,
166,152,214,94,50,82,122,245,247,253,86,130,177,157,20,34,2,202,48,36,50,172,62,223,250,226,212,166,87,2,24,134,99,36,102,110,5,105,210,164,45,20,173,72,149,100,176,136,253,75,28,89,16,181,187,37,89,207,
189,4,17,44,178,78,201,84,86,209,149,75,3,16,39,204,181,19,199,78,52,23,46,16,40,220,209,56,127,174,15,34,67,66,212,12,162,202,50,113,242,70,16,4,199,162,74,229,245,40,138,206,1,248,242,220,220,220,28,
0,76,239,221,75,51,231,206,201,101,239,32,217,107,106,106,15,205,205,205,10,0,76,140,143,237,160,32,252,181,132,249,77,28,199,251,152,121,154,153,247,50,243,126,136,76,8,48,4,32,32,160,74,149,202,6,245,
13,212,101,125,117,179,50,53,157,12,221,114,199,33,10,43,21,136,36,63,211,149,157,218,109,84,219,113,145,54,106,243,62,97,243,173,94,177,52,23,241,8,72,0,0,2,127,73,68,65,84,176,72,29,118,96,143,211,238,
61,132,186,106,183,254,160,192,49,200,16,182,240,158,223,75,56,104,179,75,248,62,49,203,210,6,18,55,227,245,31,255,224,120,115,254,124,133,250,250,250,37,110,246,74,179,57,40,64,63,128,132,128,53,4,193,
124,72,244,70,16,4,51,20,134,51,65,16,156,9,195,240,140,136,124,115,126,126,126,163,53,150,167,104,110,110,78,46,229,41,111,233,53,50,58,214,27,5,116,7,39,201,129,68,228,48,39,201,180,8,79,138,200,168,
8,70,33,50,42,34,195,2,132,212,146,73,97,16,106,0,109,146,201,203,112,251,178,139,225,72,29,76,221,110,67,43,104,3,166,117,115,174,78,109,33,116,36,136,108,41,236,211,237,3,108,139,117,108,33,18,209,77,
255,75,135,121,125,169,125,134,194,253,15,4,232,131,72,95,250,59,19,81,147,128,85,16,93,36,96,145,130,96,145,130,224,66,16,6,51,97,16,28,37,208,153,184,209,252,225,242,218,106,178,93,203,224,37,191,70,
71,71,111,21,145,1,78,146,17,16,221,33,73,178,139,69,38,68,100,24,64,4,145,157,34,50,41,192,72,10,14,240,246,6,249,108,115,97,11,195,208,72,156,218,238,192,154,117,210,50,112,235,82,98,110,14,143,165,
205,236,246,142,88,155,19,210,110,232,119,232,156,210,123,241,132,199,219,245,91,249,231,1,32,49,81,176,4,162,243,1,176,34,68,49,17,173,6,68,243,20,208,50,64,63,8,194,112,137,8,155,139,11,139,207,111,
151,135,121,89,175,177,177,49,90,88,88,48,198,229,200,200,200,65,136,12,53,227,152,1,140,7,65,112,167,48,143,136,200,184,136,236,68,182,155,116,97,85,92,138,43,186,109,254,247,22,172,55,106,111,244,108,
47,44,33,109,139,73,181,171,128,230,198,88,187,108,27,149,204,239,238,250,75,137,218,109,113,80,230,110,144,100,22,8,173,6,65,48,79,68,11,34,242,36,68,230,163,40,10,133,80,93,94,90,126,195,24,155,227,
99,180,112,113,65,126,174,19,68,79,20,17,9,86,22,23,25,0,18,213,127,195,195,59,71,9,212,19,39,73,32,204,145,99,146,146,185,24,154,133,135,124,37,211,138,250,67,45,135,147,12,124,52,123,207,145,13,106,
3,58,17,233,180,108,83,212,217,166,151,104,119,32,251,204,19,72,246,68,191,187,95,1,156,188,38,192,163,242,175,163,143,69,74,129,91,253,202,194,168,140,62,214,170,102,148,170,229,218,17,19,83,176,154,
76,197,99,243,94,244,189,233,64,167,110,1,89,52,245,252,251,86,24,37,115,208,51,154,0,32,1,81,28,134,161,176,72,125,117,117,117,73,197,43,8,0,134,199,70,3,34,200,194,197,69,222,142,113,253,255,3,139,89,
134,35,248,179,17,69,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LivePanelComponent::tap_2x_png = (const char*) resource_LivePanelComponent_tap_2x_png;
const int LivePanelComponent::tap_2x_pngSize = 17175;

// JUCER_RESOURCE: step_2x_png, 19046, "../Images/Step@2x.png"
static const unsigned char resource_LivePanelComponent_step_2x_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,200,0,0,0,100,8,6,0,0,0,195,134,127,11,0,0,0,1,115,82,71,66,0,174,206,28,233,
0,0,0,6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,219,10,30,4,34,3,119,233,193,7,0,0,32,0,73,68,65,84,120,218,237,189,
103,144,100,215,117,38,248,157,151,153,149,89,222,117,249,110,116,119,181,67,195,59,130,0,1,2,20,9,18,160,1,232,4,136,6,164,104,180,67,81,179,59,17,51,179,82,104,99,102,199,4,135,26,77,140,98,103,151,
218,208,144,43,142,200,33,9,26,128,164,8,67,193,144,32,41,145,132,19,26,30,232,110,180,71,117,153,174,170,44,151,85,89,105,222,187,103,127,228,51,231,154,151,85,13,52,165,221,136,73,68,7,42,205,123,239,
190,251,174,57,231,59,223,249,14,225,28,189,30,126,232,97,34,143,188,119,191,235,93,10,0,2,128,163,239,126,250,232,163,125,196,104,57,122,244,136,55,87,156,207,18,51,192,0,19,64,32,0,141,31,19,51,64,212,
248,14,156,124,71,28,254,32,252,132,129,248,15,6,0,10,127,205,80,32,128,24,30,171,198,185,64,72,154,66,225,161,225,217,153,195,107,83,248,211,70,163,26,223,34,106,96,227,104,113,77,138,110,140,147,246,
53,90,22,30,27,253,150,57,62,158,65,240,16,126,6,2,19,129,136,1,230,198,223,12,48,115,227,51,242,26,135,54,58,37,60,30,240,228,189,112,216,146,184,77,148,244,7,17,194,91,107,124,77,136,251,167,113,141,
228,183,76,212,248,134,147,243,134,183,210,232,173,232,226,68,225,237,18,192,220,232,59,47,188,127,86,32,74,158,1,226,30,18,253,27,181,155,8,172,26,215,39,98,48,135,207,193,131,246,172,26,199,200,247,
64,46,155,229,174,238,46,127,207,222,125,12,226,234,77,111,191,105,49,122,20,153,240,162,15,62,252,136,199,96,190,249,230,155,213,185,24,215,116,46,38,198,205,183,220,204,242,179,159,254,228,39,59,24,
232,120,246,217,103,85,54,147,217,50,50,58,122,221,210,226,82,111,113,161,184,165,188,182,214,197,74,121,228,145,146,77,48,39,136,124,49,37,3,220,154,32,114,224,179,184,171,248,3,249,176,204,191,57,165,
27,56,153,0,214,4,113,253,154,245,137,30,127,145,76,144,232,123,251,146,226,232,232,254,181,243,176,126,188,152,32,136,39,136,209,238,100,56,58,30,176,184,247,112,224,155,237,10,231,176,56,75,210,23,226,
97,37,103,143,39,178,123,130,184,159,129,249,17,59,38,72,52,167,136,149,82,158,231,145,106,107,107,95,217,50,48,48,215,221,221,85,156,61,51,251,88,165,82,153,187,252,138,43,50,0,202,239,124,231,59,79,
201,83,63,244,240,67,116,203,205,183,240,63,234,4,137,94,143,60,252,200,21,107,229,114,219,220,220,108,111,54,147,185,122,97,113,177,103,113,97,97,96,189,92,238,14,148,202,86,43,149,174,181,114,121,176,
86,171,245,178,82,25,34,82,27,55,139,207,238,78,56,237,3,235,203,228,185,164,92,138,195,67,232,108,122,142,241,27,124,209,89,94,160,201,239,155,157,106,163,203,208,235,189,79,113,160,121,142,77,60,110,
102,246,200,243,252,124,62,191,216,222,214,118,166,208,218,186,236,121,158,223,214,214,182,210,219,215,55,215,215,215,183,84,175,215,159,24,30,26,90,108,41,228,215,111,126,215,205,207,255,163,239,32,143,
60,252,72,94,177,186,186,92,46,111,95,92,92,220,59,53,53,57,186,180,180,60,184,190,182,214,87,46,151,251,42,213,106,159,239,251,221,204,156,1,179,7,130,202,120,153,74,38,155,93,7,160,200,88,244,93,125,
68,111,96,220,165,237,23,255,16,195,243,92,79,141,180,241,147,178,247,165,174,217,105,75,198,27,237,103,62,71,125,100,181,149,153,64,196,204,236,169,32,40,4,74,21,152,217,35,130,242,200,171,103,115,185,
149,124,161,48,223,222,218,186,208,214,222,177,208,219,219,59,59,54,54,58,213,211,219,123,40,159,207,79,100,178,153,39,223,121,211,59,131,223,248,4,121,224,129,251,233,125,239,187,149,1,224,193,7,31,234,
4,171,119,172,148,74,231,205,206,206,110,61,51,51,51,186,80,92,24,91,90,94,218,86,171,86,7,2,165,58,152,217,203,102,50,229,246,174,238,181,174,254,254,218,242,236,153,242,238,43,175,162,203,223,113,243,
14,47,147,205,0,80,110,147,163,201,211,118,175,45,72,236,32,215,104,106,152,45,172,27,115,41,167,54,134,19,111,162,135,98,51,170,241,67,98,221,26,17,63,113,143,84,72,127,133,54,94,189,93,166,146,214,230,
196,76,179,251,144,133,31,182,193,238,231,180,8,221,63,138,141,162,216,39,147,143,193,52,63,29,166,174,110,151,90,159,113,227,158,60,21,248,193,211,127,243,192,241,147,47,62,231,181,245,244,180,149,87,
87,91,214,86,86,218,85,16,180,130,40,200,100,50,165,66,107,235,92,119,87,215,169,254,45,91,166,70,134,135,166,182,244,111,153,232,232,236,156,32,226,159,221,242,238,247,174,1,192,253,15,60,64,183,190,
239,125,124,206,38,200,253,247,221,231,221,122,219,109,42,3,208,125,15,220,63,18,40,190,117,246,204,153,209,227,199,143,239,62,51,115,102,95,165,94,223,94,173,172,119,249,245,90,46,151,205,173,92,120,
253,13,117,143,104,117,112,199,206,204,214,61,231,111,117,63,201,102,190,1,54,88,251,207,230,179,180,9,192,142,245,47,109,244,110,198,126,58,155,117,148,54,177,150,211,6,123,70,179,227,83,103,225,38,251,
142,54,88,29,248,44,251,129,154,207,66,231,100,111,106,3,134,115,141,249,181,87,94,154,152,58,126,84,49,168,227,240,83,143,183,248,190,223,225,101,179,245,246,206,174,165,66,54,115,106,104,100,228,240,
174,93,227,71,7,7,7,39,21,240,227,91,223,251,190,25,0,184,247,190,251,232,253,183,221,198,111,120,130,220,123,239,189,222,251,223,255,126,5,0,247,223,127,223,126,165,212,205,19,19,19,131,199,143,30,187,
96,230,204,236,165,229,242,218,86,102,246,242,249,150,249,55,189,231,54,222,182,247,252,124,71,79,111,207,166,86,97,233,39,114,115,95,206,185,111,184,22,124,142,193,165,205,111,143,105,243,242,44,143,
117,158,166,201,247,103,115,126,215,253,110,212,36,150,62,84,228,151,83,202,238,65,103,209,14,164,108,88,236,240,225,232,236,111,60,245,217,154,6,131,4,78,24,188,178,48,191,248,218,193,87,106,207,252,
228,193,108,181,86,235,243,136,252,246,142,142,137,193,161,161,231,246,237,221,251,202,200,216,88,17,140,7,111,187,237,214,87,1,224,71,63,250,17,125,224,3,31,224,215,61,65,126,116,239,189,222,7,194,201,
241,173,187,238,122,171,95,171,221,48,61,61,61,244,218,107,175,157,191,188,82,186,184,188,90,234,107,105,105,89,188,249,51,191,223,210,55,60,92,200,180,180,180,146,216,84,207,218,215,11,157,146,244,245,
36,130,42,117,107,36,13,143,98,199,211,111,182,46,115,202,47,210,214,222,205,172,121,228,48,233,56,190,147,198,8,35,74,197,153,82,71,176,0,163,55,181,126,159,205,158,182,153,35,40,5,136,98,232,104,31,
111,98,192,105,125,200,9,56,151,138,185,68,227,192,129,46,50,8,126,117,125,189,56,53,181,254,147,255,254,213,122,173,94,239,201,231,243,197,45,91,182,60,191,125,251,246,195,35,163,163,103,242,249,194,
47,238,184,227,246,39,206,153,137,245,229,47,127,249,195,11,11,197,27,102,166,103,118,46,44,44,140,175,175,87,70,131,192,111,109,109,45,76,223,254,135,255,122,36,219,210,82,192,255,120,253,143,215,255,
199,94,245,74,101,253,158,255,252,197,217,245,74,101,56,151,201,172,181,182,183,159,238,239,239,63,62,60,60,124,114,96,112,240,231,159,253,236,103,239,59,235,9,114,207,61,247,208,237,183,223,206,25,128,
190,255,215,63,108,101,198,173,199,142,30,189,234,200,145,35,87,206,207,207,95,86,175,213,122,51,153,204,250,142,11,46,154,126,219,71,63,177,157,200,203,196,88,20,27,235,10,81,115,183,130,176,49,62,174,
57,107,2,182,55,205,7,39,78,187,129,137,110,238,59,14,147,89,131,131,57,197,32,72,162,113,205,113,35,233,193,55,53,249,245,56,140,30,228,65,186,237,209,204,182,52,237,46,43,174,225,186,182,1,128,108,8,
57,109,18,62,76,219,222,200,4,87,154,63,27,243,88,59,130,2,168,32,8,126,242,245,191,60,53,121,252,216,168,10,130,66,75,75,190,56,48,184,229,217,189,251,206,63,176,99,199,142,3,4,239,190,15,126,232,3,85,
57,246,83,39,200,221,119,223,77,119,220,113,7,3,192,247,239,185,103,20,68,183,78,79,77,141,29,62,116,248,178,185,226,252,213,107,165,210,80,54,155,93,189,246,182,15,45,237,187,250,154,49,48,211,217,57,
197,205,122,235,117,196,62,54,124,82,155,113,68,55,103,120,109,206,121,222,232,183,155,5,23,206,22,4,216,76,155,206,21,184,76,175,99,228,191,17,0,253,245,140,11,235,156,124,240,137,95,159,126,226,129,
123,251,131,32,104,107,235,232,152,26,26,26,122,234,130,11,46,120,118,96,96,96,26,140,251,127,251,246,223,158,105,204,129,239,209,29,119,252,14,55,53,177,238,254,222,221,23,6,129,255,174,169,169,169,129,
19,39,78,236,47,46,44,92,190,90,42,13,103,179,217,210,45,191,247,121,30,220,118,222,192,102,108,51,222,96,202,108,124,156,251,215,205,176,253,255,63,191,94,143,19,207,155,176,235,223,208,5,254,1,238,225,
31,234,124,211,39,142,205,62,242,181,191,204,248,65,208,209,214,214,54,57,56,56,248,236,238,61,123,94,25,25,25,153,3,248,167,119,220,241,59,7,205,99,50,209,31,223,253,238,119,51,223,255,254,247,249,7,
247,124,191,176,186,186,122,199,169,215,38,182,29,59,122,244,210,133,197,197,171,214,86,75,131,249,150,150,226,135,254,249,31,181,245,12,12,245,198,206,24,71,94,85,227,127,242,159,68,57,52,118,132,160,
247,68,135,155,239,73,59,134,195,115,114,60,17,226,235,68,124,34,227,252,112,252,159,69,155,93,237,140,207,35,218,19,255,22,242,26,12,227,176,228,220,208,143,69,202,239,88,54,207,209,126,173,255,82,126,
47,143,97,205,50,225,148,115,179,126,207,108,60,3,227,153,89,255,144,254,15,142,115,186,246,115,237,90,172,91,83,174,235,217,247,199,241,56,96,182,199,16,156,207,32,233,168,142,222,158,246,241,203,174,
240,143,252,253,19,165,74,101,125,104,189,188,222,95,42,149,60,0,213,142,142,246,222,79,124,236,206,231,191,119,247,221,193,93,223,190,139,126,248,131,31,38,139,238,93,223,190,203,251,228,199,62,206,63,
124,240,219,88,91,194,77,19,167,38,222,126,244,232,145,203,23,151,150,174,172,148,203,93,237,157,157,147,31,250,23,127,60,154,107,201,231,207,126,219,124,35,166,211,27,53,23,206,230,152,127,232,88,249,
102,249,30,231,34,198,157,190,58,215,3,5,95,133,255,2,5,197,10,129,98,4,74,33,224,6,17,81,49,67,49,135,147,136,193,10,141,247,20,46,82,202,225,130,54,65,155,204,217,67,228,118,149,210,96,255,152,130,26,
146,93,9,0,81,131,112,74,33,241,52,67,4,34,47,254,59,67,30,50,25,130,71,30,168,94,91,127,240,75,127,118,166,82,89,31,205,230,114,75,67,131,131,7,246,236,219,251,204,232,216,216,207,62,246,209,143,253,
76,54,49,27,45,25,1,192,171,139,188,101,113,97,241,202,201,201,211,59,74,229,245,11,214,74,165,45,133,214,214,233,223,254,195,127,117,158,151,201,100,56,173,179,57,205,249,77,153,24,175,59,32,240,122,
143,73,46,72,98,133,161,13,207,189,145,177,247,70,141,135,205,124,183,185,251,14,2,133,106,16,160,30,255,107,12,250,64,53,6,124,50,200,221,79,241,156,60,18,182,127,192,155,184,101,230,148,211,164,116,
131,182,243,56,193,238,13,95,173,151,125,250,243,163,79,127,245,207,23,170,149,202,240,220,252,252,190,214,182,182,133,142,142,206,203,239,186,235,174,103,63,254,241,143,199,44,97,250,230,183,190,229,
125,234,206,59,249,107,223,252,102,103,189,94,191,253,248,177,99,151,157,56,126,252,205,203,203,203,151,16,80,127,199,157,159,90,217,182,111,255,168,238,159,137,200,21,55,217,37,8,54,178,98,81,42,82,28,
249,120,241,107,194,36,146,40,153,140,46,113,202,178,147,246,185,134,0,177,206,84,100,218,124,16,32,162,194,58,41,35,41,112,30,73,118,45,89,240,157,175,20,42,117,31,85,223,71,93,249,168,249,10,126,192,
8,88,65,41,5,37,219,142,100,249,149,12,96,134,129,130,49,217,79,140,66,170,72,72,175,39,129,98,37,212,121,54,32,7,106,142,143,132,116,118,173,203,76,90,141,12,160,196,169,14,105,93,45,159,73,200,29,22,
145,97,114,33,134,90,92,142,67,90,126,227,52,75,7,95,58,121,232,209,7,7,152,85,166,167,167,247,185,221,187,119,63,185,123,239,158,3,32,254,235,79,222,249,187,171,0,144,13,130,128,2,64,129,188,234,244,
212,212,200,204,244,244,120,53,8,118,6,190,159,27,222,190,227,244,214,125,251,199,173,25,45,12,96,18,235,132,141,29,232,54,96,50,70,205,223,59,150,138,148,135,98,58,22,4,221,174,222,120,217,73,222,104,
199,130,157,109,78,221,1,93,166,66,108,78,112,138,161,99,31,88,169,215,177,94,243,81,169,251,168,5,1,252,32,128,175,24,74,169,148,5,151,82,150,87,130,57,186,216,21,218,118,173,236,134,131,200,8,83,12,
148,126,29,118,237,15,220,4,219,21,11,82,180,210,179,99,12,233,91,137,48,203,92,79,159,147,137,160,154,181,145,163,44,28,225,55,18,192,170,241,153,2,208,189,239,130,243,58,158,126,252,248,114,113,126,
124,101,165,52,62,53,53,53,223,218,214,54,181,99,239,120,5,0,190,246,181,175,81,246,179,191,251,187,234,191,127,227,171,94,189,186,126,229,234,106,105,120,181,92,30,89,91,94,234,46,180,119,44,222,248,
209,79,12,50,187,128,251,164,83,184,73,7,54,31,87,238,161,223,244,152,148,112,201,235,243,117,228,245,55,226,190,110,2,102,97,74,242,86,12,162,221,90,173,142,114,173,142,170,239,163,230,7,177,233,147,
218,175,169,212,151,232,209,110,198,222,49,118,35,222,152,187,207,169,11,202,102,38,42,111,96,226,38,195,53,245,103,36,90,33,99,63,76,218,14,152,102,130,49,217,95,176,145,100,102,180,202,219,243,158,15,
246,62,247,157,175,47,250,245,90,79,169,84,26,89,94,94,30,169,172,148,175,0,240,212,167,63,253,105,206,6,0,171,192,235,94,89,89,126,235,202,242,74,95,160,120,80,5,42,55,180,99,71,165,189,179,171,95,131,
161,206,137,95,240,6,143,229,115,117,62,126,67,54,191,121,170,74,189,142,181,106,13,235,190,143,106,221,71,93,5,80,138,29,164,221,112,149,36,231,58,158,172,181,202,53,87,185,105,64,80,58,183,20,39,90,
37,40,99,178,219,59,24,180,172,115,54,44,71,217,154,192,172,89,185,166,185,73,108,91,167,201,146,148,4,76,53,202,12,59,172,225,232,11,101,207,123,147,142,67,138,12,171,220,77,51,146,231,207,116,245,244,
117,14,14,77,20,79,191,214,95,94,43,247,151,86,86,6,86,75,165,235,254,234,175,254,234,224,103,62,243,153,82,22,0,14,31,60,84,241,131,160,117,121,121,121,180,186,94,238,244,60,111,173,119,112,104,141,217,
224,78,83,26,204,128,205,147,76,163,78,221,12,129,211,248,222,114,35,204,38,176,219,101,112,142,253,102,68,161,148,243,3,64,213,247,81,170,84,176,94,245,81,13,124,212,3,5,165,120,99,162,165,230,98,52,
144,32,87,91,98,127,129,211,221,164,104,180,147,210,221,150,120,220,10,215,208,178,96,88,216,187,42,5,92,97,219,113,182,136,165,209,199,230,70,24,62,95,5,251,252,108,194,84,241,61,233,59,111,179,103,28,
79,20,163,63,163,180,225,116,115,60,218,136,24,74,248,208,196,196,237,125,253,165,197,169,211,107,181,122,173,119,105,105,105,236,244,196,196,193,43,46,190,168,28,163,88,61,189,189,163,19,19,19,131,53,
223,31,174,148,203,29,59,47,186,116,254,210,183,191,107,79,195,196,119,100,129,49,12,39,221,72,223,220,0,225,136,59,85,109,0,163,40,199,224,97,3,138,114,117,172,153,146,235,162,85,184,64,2,214,191,95,
169,84,177,86,173,162,92,243,81,11,234,8,20,107,169,174,198,120,77,218,168,194,188,111,147,89,194,201,68,6,219,171,25,153,11,15,235,12,101,18,237,139,250,48,38,119,134,239,101,146,13,113,50,16,26,75,93,
226,160,154,199,187,82,138,35,31,131,144,220,75,28,167,50,54,19,115,193,39,182,23,204,248,18,74,76,118,149,44,152,22,97,145,117,87,134,200,129,5,135,39,82,209,162,33,207,207,104,228,248,39,194,0,80,212,
200,129,231,120,141,96,111,248,250,183,239,95,41,206,207,46,76,156,26,44,151,203,131,107,229,242,224,242,122,101,4,192,233,236,87,190,242,149,238,242,90,249,125,204,220,22,40,149,103,102,202,183,181,213,
117,247,59,221,196,36,195,49,106,22,1,161,141,32,188,13,174,65,230,188,108,118,44,27,25,206,140,38,247,194,88,89,175,160,84,169,97,189,94,71,205,247,161,194,167,210,120,120,238,153,203,98,55,100,22,210,
4,194,25,108,172,106,33,202,18,162,58,44,120,224,28,14,98,34,134,98,210,151,111,129,194,88,190,63,39,104,16,71,72,141,138,242,247,41,246,127,228,202,18,25,4,108,13,222,164,29,241,96,102,19,141,74,0,55,
101,116,36,195,182,179,156,76,100,182,205,41,137,254,41,144,229,54,89,139,43,235,38,90,60,27,56,17,220,176,23,66,129,166,49,67,133,184,150,138,115,233,153,178,249,124,13,0,213,107,181,22,48,119,86,107,
181,247,126,249,191,126,249,174,172,82,138,103,103,103,123,86,150,87,134,253,32,232,2,81,125,101,118,102,73,177,26,165,141,176,77,178,35,150,108,89,156,228,64,78,82,236,47,50,70,65,140,126,146,136,16,
147,3,22,112,219,52,108,225,71,141,247,229,90,61,222,29,106,117,31,1,91,112,84,252,208,56,141,160,200,2,2,141,159,191,146,118,146,184,99,1,157,202,208,62,18,155,136,217,220,22,29,246,141,245,190,161,227,
162,13,62,105,103,185,236,85,118,33,81,250,181,217,224,172,179,12,4,70,171,182,182,237,168,116,244,130,36,21,193,21,133,226,100,34,203,137,232,112,54,56,213,59,151,125,169,223,107,60,33,67,123,52,241,
130,132,153,9,102,191,180,178,4,208,112,221,15,122,150,151,87,134,103,166,166,251,199,182,109,67,246,208,43,7,115,149,106,165,175,92,169,140,174,45,47,119,246,14,13,47,191,237,206,79,239,34,102,129,238,
199,130,58,77,30,154,249,48,84,154,77,227,216,83,12,165,14,11,110,224,77,56,217,228,128,251,26,159,47,149,203,88,169,84,177,94,171,161,30,168,166,81,230,196,100,112,217,114,105,246,45,217,239,133,38,69,
114,38,199,121,148,110,14,166,5,48,53,233,28,78,159,56,50,159,162,25,162,228,126,86,72,133,219,109,168,216,56,103,26,210,198,236,184,182,248,141,153,16,102,45,181,236,240,149,196,46,34,236,177,100,98,
43,17,22,86,194,12,230,180,197,194,219,249,222,15,237,90,187,251,27,203,235,203,43,61,165,213,210,104,113,161,216,59,178,117,140,179,149,106,133,252,32,200,128,168,149,149,202,12,110,223,94,111,41,20,
10,74,107,71,130,29,147,69,47,118,236,49,81,160,138,12,128,207,242,235,57,117,104,195,101,159,55,217,135,228,122,189,176,90,198,242,122,5,235,245,186,13,167,198,244,6,217,50,115,189,135,72,249,210,59,
149,181,13,52,70,228,53,144,128,160,111,247,196,161,66,133,59,150,230,142,251,179,49,239,72,246,213,6,244,19,78,199,62,200,188,23,17,137,150,73,105,16,65,67,136,69,82,238,225,214,241,108,62,83,209,98,
7,12,75,14,204,0,76,201,179,49,110,130,82,151,72,165,197,162,18,119,146,157,254,189,126,207,97,43,242,133,182,142,193,225,133,181,165,165,76,224,251,249,192,247,179,80,1,178,217,108,142,235,245,58,148,
10,20,3,202,175,213,125,165,20,19,201,61,86,144,197,44,27,210,52,105,92,20,2,121,156,78,223,64,250,58,110,35,48,41,235,235,226,218,58,150,203,235,88,171,213,161,148,114,44,118,108,77,66,54,162,175,141,
197,136,227,232,176,138,86,190,120,150,43,61,132,197,141,1,195,148,68,166,85,242,148,237,123,100,205,216,10,39,41,226,72,56,153,129,120,102,205,247,33,169,225,6,101,12,92,195,231,115,204,159,88,181,138,
132,111,98,200,40,232,192,176,74,226,207,225,189,38,125,17,158,45,246,169,224,204,205,136,180,206,34,31,41,58,54,106,115,98,4,135,109,136,34,247,202,30,67,218,114,21,135,69,148,152,106,186,255,20,161,
109,122,79,37,247,172,66,68,75,196,128,152,3,223,111,248,251,9,53,39,203,17,67,146,25,172,20,177,98,11,66,51,29,30,243,65,144,180,79,93,76,19,142,28,84,99,181,39,7,2,18,31,199,150,73,73,161,41,178,86,
169,161,184,90,198,106,181,134,186,10,194,193,42,152,111,204,150,213,197,70,123,180,141,60,130,76,173,232,176,22,64,48,130,162,134,3,76,9,122,163,28,134,158,43,222,43,99,19,194,95,182,156,96,125,202,81,
227,252,177,95,198,169,220,38,115,226,40,209,56,114,64,202,241,32,141,221,6,214,145,46,9,118,16,67,113,52,1,96,229,89,177,152,240,82,165,145,13,239,80,194,188,204,2,232,9,205,181,232,252,38,234,171,216,
193,80,136,253,37,29,101,96,203,246,96,141,45,30,239,48,74,17,51,135,34,151,12,86,140,172,82,65,204,212,140,58,69,133,65,23,247,211,21,196,18,54,29,61,55,123,65,174,216,77,77,104,139,245,144,24,168,115,
165,85,44,151,203,88,175,251,14,114,27,107,118,169,134,242,106,168,41,219,89,143,209,14,217,44,195,113,51,177,67,118,73,228,108,164,224,152,12,194,134,20,234,102,40,140,28,61,77,43,99,147,83,142,138,151,
180,216,70,38,131,146,65,98,167,179,101,132,228,243,86,70,223,42,135,184,35,155,82,76,108,123,88,236,128,200,205,62,209,151,99,88,109,228,84,183,148,157,81,6,106,106,241,68,169,19,141,205,66,177,130,207,
1,178,209,172,101,86,130,168,207,150,180,231,198,145,107,133,13,114,61,177,121,206,40,163,230,7,152,93,89,69,105,189,138,90,16,52,65,173,220,214,54,27,16,162,59,152,99,68,203,56,173,189,77,184,218,142,
239,217,237,85,24,129,29,50,218,199,182,185,96,93,159,83,64,12,108,16,165,117,174,90,41,206,123,218,179,98,247,95,76,41,87,82,41,125,230,30,170,150,55,203,105,89,139,205,64,159,230,81,107,59,8,161,52,
8,90,113,194,165,99,21,238,32,80,10,172,84,188,93,179,228,253,195,148,6,179,77,39,155,231,224,48,157,164,185,228,80,12,137,94,235,181,26,206,172,172,97,181,82,69,192,74,15,24,53,227,34,16,59,219,226,17,
97,184,167,19,131,157,29,40,180,228,208,218,210,2,2,80,243,3,84,235,62,22,203,101,44,172,150,177,88,46,27,102,137,114,196,21,109,244,203,242,164,4,219,153,37,181,132,56,54,21,200,234,75,181,193,196,179,
83,129,92,192,4,105,80,185,105,155,43,209,143,182,124,158,14,132,235,126,72,26,200,15,138,196,191,185,9,129,192,5,243,39,30,136,246,11,146,22,73,2,6,36,164,98,233,11,43,45,239,220,54,129,217,80,58,149,
132,73,54,90,195,9,92,30,110,18,81,92,75,249,1,178,201,150,18,229,10,112,248,99,106,78,65,227,230,168,43,111,18,17,46,215,234,56,179,82,66,169,82,65,16,176,243,105,152,49,165,134,191,96,116,66,216,191,
89,15,184,120,219,24,222,188,107,7,118,14,244,163,37,155,217,112,191,170,249,1,78,47,44,97,162,184,128,163,103,230,113,100,102,14,213,192,183,252,11,157,154,237,232,11,195,111,99,17,34,102,7,112,161,117,
155,165,70,193,205,161,41,24,27,163,128,120,93,254,83,226,31,176,78,67,49,252,76,150,59,174,36,8,178,238,11,178,225,123,88,168,166,37,48,14,77,228,90,243,237,76,255,85,143,147,10,134,180,140,111,176,155,
170,100,100,66,36,135,58,144,49,132,65,96,82,128,66,131,59,39,230,130,98,70,86,169,228,131,200,6,147,222,63,73,193,177,116,241,41,237,115,54,5,195,116,186,63,2,63,192,212,210,50,150,215,171,13,24,150,
57,65,131,66,71,139,200,53,67,140,8,177,28,7,12,92,180,109,4,183,95,125,57,186,219,90,113,54,175,150,108,6,227,131,253,24,31,236,199,141,251,247,32,80,10,79,28,61,137,123,158,122,214,24,179,34,130,27,
174,33,215,237,25,71,103,33,175,61,172,135,158,127,37,9,52,34,41,99,224,84,232,16,220,15,14,239,95,163,137,27,234,45,218,252,33,129,20,153,164,107,78,34,228,100,81,224,41,37,71,53,66,242,82,172,24,81,
150,66,194,179,113,127,164,140,151,4,128,96,71,191,52,177,206,149,41,116,199,98,44,69,128,131,129,226,69,41,224,134,115,196,226,26,164,12,43,132,147,93,133,195,93,81,49,35,0,35,171,184,145,102,201,34,
173,82,177,208,83,101,211,214,52,239,222,193,70,35,209,64,149,124,54,181,176,130,133,181,50,106,126,32,182,186,104,82,176,228,176,217,245,45,216,222,138,36,192,118,199,53,87,224,45,123,199,113,46,94,25,
207,195,72,79,23,88,57,236,110,73,52,100,224,250,125,227,24,233,233,214,142,127,240,185,87,68,224,202,232,51,71,254,67,18,24,87,128,34,11,77,50,87,3,150,72,93,108,164,49,44,182,61,195,153,79,161,131,246,
6,219,49,4,79,137,133,128,142,17,196,98,102,43,18,31,47,128,74,222,19,11,52,42,217,9,76,14,154,54,217,204,21,87,208,83,156,52,58,173,94,74,178,75,70,192,16,73,118,44,11,227,142,37,26,155,244,39,3,177,
203,129,6,204,171,132,96,65,195,49,137,86,116,114,27,3,218,64,165,13,146,111,86,202,21,76,47,47,163,92,173,167,58,122,204,46,103,141,52,250,129,109,239,37,87,254,200,181,87,165,78,142,181,74,21,167,138,
11,152,89,42,133,145,244,0,173,45,57,180,181,180,96,184,167,27,219,250,123,80,200,229,156,102,36,179,178,131,114,166,243,229,10,142,179,114,252,196,220,9,37,173,25,186,233,16,23,180,97,189,135,19,162,
151,64,245,149,211,123,81,70,173,141,52,59,151,83,16,55,150,68,22,78,195,130,116,31,144,57,13,218,99,103,46,144,189,73,53,115,190,13,200,156,201,162,221,184,18,198,44,218,60,37,4,204,196,163,107,236,70,
177,155,193,141,132,53,21,40,100,89,53,102,12,135,142,93,236,164,179,94,184,38,13,181,49,147,142,40,92,225,38,138,11,88,90,91,135,175,148,22,163,181,182,121,210,221,73,19,110,101,118,168,199,9,251,248,
205,187,119,56,39,199,107,197,69,60,240,204,139,56,52,53,35,226,10,198,58,20,174,48,163,253,61,184,124,251,54,92,182,125,43,134,123,186,18,134,3,59,17,248,141,49,56,229,16,197,53,247,123,74,163,208,152,
34,160,238,204,66,142,206,161,217,182,114,35,80,34,136,200,216,152,235,207,90,176,176,17,253,79,179,169,205,160,135,169,186,160,224,216,120,224,92,114,101,0,200,48,223,180,116,100,131,223,224,164,122,
147,9,61,56,128,14,7,79,46,162,172,104,96,21,26,194,21,89,21,40,225,131,168,120,6,145,149,203,234,130,62,245,25,190,86,173,97,114,97,25,171,213,138,253,200,181,9,231,10,216,0,186,215,166,115,226,201,33,
0,144,207,102,113,219,21,151,88,131,231,23,175,188,138,239,63,249,204,6,122,30,201,84,61,93,92,194,233,226,18,30,120,230,5,236,28,28,192,111,93,184,23,157,133,188,17,113,78,7,188,93,145,135,13,233,198,
198,110,168,37,19,105,86,183,73,173,145,169,171,46,46,91,115,248,148,226,117,85,95,67,29,161,180,148,231,239,234,74,55,157,39,94,22,153,29,57,133,228,244,200,237,172,70,157,254,170,54,68,134,54,147,215,
234,186,15,29,197,101,197,96,63,64,86,201,15,99,253,41,61,210,107,75,133,235,23,152,91,89,197,236,242,10,170,190,143,166,136,188,204,103,112,170,81,112,106,236,211,149,143,116,209,182,81,203,33,127,101,
114,26,119,63,241,12,172,68,153,38,221,69,130,54,126,236,204,28,142,157,153,69,33,151,213,193,0,193,135,210,135,43,167,239,32,41,138,232,250,143,27,40,10,55,37,237,164,68,123,216,49,165,216,177,115,137,
129,206,148,62,125,156,230,140,96,48,88,147,196,76,226,160,148,40,135,213,15,148,236,162,174,193,238,74,173,22,8,192,134,101,82,156,37,250,216,208,181,209,239,52,174,155,41,152,37,138,21,178,80,201,196,
72,108,48,189,243,211,98,63,83,139,75,152,91,89,13,9,129,238,39,202,6,233,206,12,119,153,245,94,156,231,128,142,142,69,126,224,37,219,198,172,67,30,120,250,121,40,14,98,126,148,64,241,44,6,117,226,148,
106,177,100,128,129,245,106,93,19,58,129,195,74,167,148,17,166,66,155,86,167,70,36,39,139,226,35,164,21,44,117,115,206,108,13,76,35,240,73,108,233,76,80,236,23,36,172,226,120,207,96,214,1,53,214,181,135,
53,146,41,155,225,205,132,124,41,226,155,86,249,3,197,41,198,28,55,205,22,209,145,108,19,215,160,132,221,97,137,191,176,129,86,199,72,168,77,186,100,249,220,4,42,168,111,20,225,4,129,66,86,133,81,116,
70,148,151,144,56,233,112,197,231,24,152,152,95,196,124,105,53,68,187,140,114,7,18,221,114,152,237,250,96,79,72,108,156,146,0,173,77,36,201,51,98,96,107,127,143,246,219,245,90,29,199,102,139,58,78,111,
32,113,81,231,69,216,59,133,79,87,155,227,113,102,144,116,238,34,18,29,199,129,178,180,116,253,6,34,199,49,59,85,243,3,88,15,34,178,193,115,137,81,100,182,57,111,204,166,49,202,6,85,132,197,239,67,103,
62,170,100,203,128,138,150,2,35,168,207,6,201,146,69,198,94,130,183,36,11,142,121,223,108,5,228,108,214,3,75,31,33,14,0,135,161,59,214,1,11,147,216,202,150,41,110,66,219,58,233,82,177,249,220,109,195,
154,196,179,97,17,73,143,76,169,40,220,145,101,52,252,14,40,153,74,98,236,137,225,153,79,205,23,49,95,90,11,19,131,200,109,12,177,101,75,165,70,26,153,201,101,249,234,209,81,182,43,183,54,76,5,66,103,
171,94,117,97,101,125,61,158,253,105,209,43,83,34,200,197,18,54,109,89,214,176,114,18,192,122,202,198,39,115,163,173,84,70,55,159,128,13,184,210,101,74,1,132,209,222,110,12,116,117,160,179,181,21,29,133,
22,212,253,0,165,74,5,11,171,235,56,49,59,143,128,149,38,133,195,26,159,138,237,84,29,39,197,6,41,108,224,228,243,206,66,30,59,6,183,96,160,171,3,133,92,14,126,16,160,184,90,198,201,217,121,20,87,215,
196,113,202,120,22,202,128,111,57,97,104,146,153,55,13,23,61,84,231,118,165,5,94,55,168,200,196,230,170,207,208,124,112,102,110,160,88,42,8,26,40,86,56,8,148,216,69,40,188,145,211,11,139,56,179,188,218,
16,39,136,210,80,35,44,153,12,135,172,137,212,76,146,85,7,45,225,152,67,83,65,187,5,69,73,180,20,142,66,52,138,145,207,230,140,128,95,22,138,149,193,138,18,217,136,36,109,224,168,94,57,91,148,184,141,
10,95,126,245,115,159,104,234,6,254,63,255,228,206,13,29,249,223,251,202,55,160,147,213,147,157,55,202,191,137,204,162,243,182,244,226,237,23,158,143,11,183,141,162,167,189,45,245,156,149,122,29,135,38,
103,240,200,11,47,227,200,212,156,149,175,33,242,131,83,4,42,24,127,249,185,79,106,231,156,92,88,194,191,187,231,190,248,167,231,143,141,224,189,151,95,140,189,163,67,240,82,108,227,83,115,69,60,244,252,
203,120,250,232,73,104,201,229,150,153,35,146,157,64,128,82,161,217,201,22,157,133,41,4,175,55,171,92,110,149,140,16,80,186,180,233,148,158,54,205,97,144,80,41,5,14,20,178,12,29,255,141,183,23,34,204,
46,175,96,114,97,9,190,10,132,45,24,229,52,171,100,59,51,38,43,147,8,237,24,182,177,98,118,144,185,216,246,253,164,238,43,9,12,67,20,138,44,87,171,232,18,78,122,111,123,27,186,91,11,88,42,87,18,106,62,
153,194,206,4,98,21,39,54,177,138,76,7,101,36,36,153,98,141,209,138,119,78,234,211,135,145,93,6,91,16,102,178,155,247,119,118,224,246,107,174,196,85,187,182,199,166,96,179,87,33,151,195,101,59,182,225,
178,29,219,240,194,169,211,248,250,223,62,142,229,181,245,68,56,66,137,48,188,33,150,192,77,228,148,20,3,25,242,240,201,27,222,140,235,247,239,217,176,29,219,7,250,241,185,155,110,192,117,123,119,225,
47,31,253,37,86,43,85,177,208,133,204,182,16,98,79,82,38,56,161,216,71,112,175,96,23,112,20,91,138,215,94,210,204,52,109,195,118,73,118,69,28,124,210,125,56,138,242,93,184,113,159,9,121,151,161,56,128,
167,196,182,162,66,138,201,90,165,138,23,79,157,198,201,185,121,248,129,31,43,169,55,118,25,21,51,127,149,52,103,34,152,24,9,2,16,159,179,49,11,67,182,164,14,41,39,54,31,226,36,149,70,7,170,6,212,22,199,
102,34,140,90,197,196,50,185,149,71,175,155,46,222,31,182,67,197,231,209,216,202,172,132,67,150,156,47,226,255,43,22,247,168,20,20,148,22,89,229,115,166,111,29,198,158,226,243,70,253,218,32,105,142,15,
109,193,191,254,240,123,241,166,221,59,54,53,57,204,215,37,219,183,226,95,125,240,221,24,237,237,138,207,29,223,167,88,41,33,232,21,105,55,71,96,252,207,183,188,109,83,147,67,190,46,58,111,12,127,252,
129,91,208,213,90,208,144,161,168,223,85,56,158,162,254,78,254,65,127,222,241,223,114,165,79,98,119,141,123,104,188,87,48,207,165,160,229,189,71,177,142,184,207,163,54,25,230,21,135,113,16,8,4,11,80,40,
173,174,241,75,19,147,240,34,148,156,116,251,79,202,170,114,132,16,200,196,26,97,42,41,195,54,108,144,12,41,84,240,128,158,52,195,9,247,75,227,205,134,168,139,146,193,245,240,220,135,38,167,177,115,112,
139,246,80,110,185,236,34,20,75,107,120,244,165,67,177,99,168,121,57,58,243,192,38,55,40,210,239,89,233,65,37,2,80,174,214,146,85,187,37,103,153,26,242,251,212,233,33,20,96,76,20,234,162,109,163,248,103,
239,121,59,114,217,172,117,220,236,114,9,71,103,102,81,44,173,98,189,86,67,161,37,135,45,157,157,216,191,117,4,189,134,249,213,223,217,129,63,122,255,45,248,55,119,223,139,229,181,178,230,228,91,180,176,
38,19,255,3,111,186,12,151,108,223,154,180,93,41,188,114,122,26,167,139,11,40,85,170,232,44,228,177,117,75,31,46,24,27,129,231,121,218,177,35,189,61,248,103,239,121,7,254,228,7,15,192,23,137,108,9,122,
100,82,112,66,216,91,160,141,74,186,79,102,34,157,136,150,19,29,206,123,33,0,0,32,0,73,68,65,84,185,233,40,108,232,18,235,106,48,130,210,18,45,86,225,132,10,152,144,109,68,209,67,254,59,3,126,189,206,
96,14,163,168,148,130,210,64,219,170,211,157,75,155,196,40,169,35,182,142,149,46,68,198,46,118,135,24,216,143,191,122,12,239,190,252,98,125,181,35,194,157,55,92,131,183,238,223,131,71,95,60,136,3,199,
79,97,45,220,226,217,12,11,40,87,188,138,29,91,179,110,254,253,193,87,191,21,127,246,197,143,126,16,99,253,189,90,27,254,224,171,223,66,42,168,111,74,215,26,140,137,190,206,118,124,238,93,55,90,147,227,
165,215,38,241,163,191,127,22,71,167,103,117,145,110,225,210,189,121,239,56,62,114,221,213,154,159,210,217,90,192,239,223,116,35,254,244,222,7,45,146,39,12,170,152,235,89,247,182,183,227,61,162,143,15,
28,59,137,111,254,221,227,88,90,91,183,226,15,61,109,173,248,196,141,215,226,202,241,29,218,57,118,14,110,193,45,87,92,140,251,159,126,94,195,28,88,246,47,235,99,202,73,93,131,193,79,83,186,57,197,174,
74,128,18,144,145,29,111,104,40,37,147,35,50,52,20,160,130,8,230,109,56,37,16,102,6,57,178,192,200,138,90,146,163,29,122,64,38,102,168,66,10,145,65,131,3,201,152,136,18,242,37,3,27,78,240,121,194,169,
217,34,158,62,122,18,87,237,222,225,180,131,63,243,246,235,241,169,183,189,5,39,231,138,56,58,51,139,99,51,115,56,49,59,135,51,75,43,54,195,52,6,241,73,119,232,153,117,112,193,34,252,165,80,77,28,152,
138,126,63,236,140,168,255,193,187,222,134,142,66,94,59,223,119,127,245,20,254,230,153,23,66,83,203,96,26,8,30,219,99,135,143,226,208,233,41,252,209,7,222,131,209,190,4,2,223,55,54,140,107,247,140,227,
87,135,142,38,98,106,114,197,230,244,45,164,45,223,18,255,253,208,179,47,225,59,191,122,210,240,121,19,202,206,226,106,25,95,250,241,163,248,216,91,223,140,155,47,187,72,59,207,109,87,93,134,39,14,29,
195,236,74,201,225,172,75,144,143,146,248,153,193,30,208,234,38,194,61,27,226,192,111,51,138,140,43,206,24,185,12,97,126,20,43,70,16,112,99,7,81,209,46,18,250,1,210,153,99,52,27,12,110,85,119,157,98,199,
206,196,123,155,37,148,198,13,106,150,74,10,252,183,71,127,137,109,91,250,48,20,113,168,140,151,231,121,24,31,26,192,248,208,0,112,105,98,2,29,153,62,131,131,167,167,240,242,196,20,78,205,21,197,250,194,
26,58,155,166,135,222,172,182,136,98,101,244,139,45,223,227,186,167,43,118,110,195,238,145,33,237,179,191,126,242,0,254,230,153,231,99,179,76,239,119,182,192,204,226,234,26,254,203,253,143,224,63,124,
236,67,200,231,146,93,232,221,151,95,140,95,30,124,213,136,91,232,38,74,179,215,75,175,77,226,174,95,62,145,182,36,104,247,121,215,223,61,142,173,253,189,184,80,4,114,115,153,12,222,113,201,126,124,251,
151,79,56,244,202,108,218,135,91,60,51,138,35,41,23,64,174,153,223,14,227,185,201,72,210,67,10,17,1,71,49,195,147,105,134,74,56,82,138,5,186,165,16,167,32,70,239,99,71,71,37,52,121,22,145,120,21,189,87,
201,63,165,229,252,114,232,47,133,206,82,116,141,40,38,19,178,43,85,124,188,222,134,168,109,165,245,10,254,228,7,247,227,216,204,236,166,157,199,182,124,11,46,221,177,13,31,185,254,205,248,194,71,63,136,
63,249,248,135,113,203,101,23,35,231,101,227,107,201,107,67,82,113,196,189,168,20,147,37,185,7,193,235,137,255,175,68,191,178,214,103,239,189,242,82,237,60,167,139,139,248,209,19,207,66,69,125,167,196,
113,42,89,204,20,179,214,223,211,75,203,120,244,133,87,180,115,109,219,210,135,221,67,3,218,53,21,71,73,66,112,212,164,131,230,115,124,227,23,143,133,96,5,172,49,1,21,194,153,209,115,98,224,27,191,120,
44,86,152,137,94,215,239,223,131,140,151,73,28,113,37,254,89,142,51,11,103,90,111,175,76,137,213,199,104,232,131,43,179,111,163,118,70,207,83,144,114,229,120,82,114,76,43,40,248,240,192,141,45,69,177,
17,73,55,46,162,32,107,195,69,131,39,6,134,66,36,0,2,141,82,201,192,136,227,48,198,128,143,144,3,101,96,208,17,74,161,146,235,177,64,200,226,235,132,3,110,126,101,13,255,254,123,247,226,219,127,247,4,
74,235,149,179,70,124,182,246,247,226,227,55,92,131,63,251,212,29,184,118,223,238,198,117,20,11,68,46,106,179,188,71,213,36,146,142,120,2,41,165,244,246,43,49,192,144,244,215,80,87,39,246,142,14,107,231,
121,228,249,151,224,115,160,13,28,173,79,20,196,98,164,180,137,248,171,112,183,144,175,125,99,163,9,42,24,61,139,208,172,72,16,68,199,238,49,49,137,201,226,162,129,66,233,99,67,133,43,55,135,11,203,233,
226,34,94,158,152,210,206,211,81,40,96,255,216,176,232,75,21,163,163,201,192,134,62,216,181,69,54,68,170,84,132,81,66,239,15,232,172,244,104,172,169,48,3,53,106,163,82,201,130,172,226,36,193,24,167,77,
92,1,159,145,141,6,66,12,228,10,68,75,179,151,25,14,190,169,142,14,57,116,34,172,96,29,193,16,245,114,216,227,137,64,157,193,14,141,176,115,182,133,191,252,64,225,129,167,159,195,79,159,127,25,215,238,
219,133,235,47,216,139,243,199,70,206,10,34,237,237,104,199,63,125,247,219,177,123,120,160,177,98,178,20,163,77,90,77,208,105,31,246,14,162,12,251,22,238,32,153,248,252,252,173,35,214,121,254,254,200,
241,196,159,49,235,135,43,61,234,173,52,14,22,112,114,118,30,149,122,93,203,117,217,55,58,132,251,148,114,179,125,155,164,69,63,126,232,168,33,171,106,62,123,78,50,9,133,201,247,248,225,163,184,88,160,
95,0,176,107,120,16,207,157,120,77,248,228,73,142,162,130,131,172,158,86,214,132,155,232,70,179,38,41,103,17,33,45,81,57,134,70,181,138,38,87,160,208,72,185,141,77,27,241,3,173,68,1,28,213,203,28,181,
77,156,49,104,210,89,109,174,10,174,176,165,7,18,206,15,100,61,121,118,20,38,210,123,167,92,171,225,209,23,15,226,103,47,190,130,246,66,1,251,183,142,224,252,173,163,216,51,60,136,237,131,91,144,119,36,
71,153,175,155,47,191,24,204,192,215,127,254,171,88,229,207,165,165,165,210,100,139,152,83,81,33,78,73,173,217,63,166,79,144,149,242,58,22,87,203,41,131,195,166,122,179,131,90,179,82,94,71,161,59,185,
223,193,238,46,161,131,219,28,189,146,175,163,211,51,49,189,136,69,80,94,146,15,45,89,39,6,94,157,58,99,157,107,215,240,64,82,169,22,137,162,189,236,83,43,206,215,180,141,236,4,139,204,180,97,182,228,
42,195,69,69,80,154,116,179,78,65,81,16,114,177,148,178,236,53,38,119,205,189,152,96,6,35,93,84,99,101,137,129,46,203,173,241,198,133,120,228,241,204,110,214,64,179,242,245,241,35,35,160,180,94,193,83,
71,78,224,169,35,199,195,14,243,48,214,215,131,125,99,195,184,232,188,173,184,98,124,7,10,45,238,9,115,203,21,23,227,197,83,19,120,250,216,9,45,2,204,2,117,227,52,100,36,222,178,77,1,206,136,74,18,197,
92,146,21,111,212,128,138,187,218,90,241,221,127,249,121,156,203,87,71,107,62,49,163,34,22,174,18,207,207,177,219,250,65,128,211,197,69,219,252,138,149,226,13,162,97,88,235,144,1,76,22,139,240,131,0,217,
76,34,156,177,165,171,83,36,162,201,136,56,132,154,142,33,134,202,100,141,43,125,209,97,51,188,35,162,242,46,22,52,244,235,3,150,191,211,224,98,249,145,104,67,104,207,131,245,168,35,216,26,216,172,137,
3,155,185,91,100,241,153,36,146,69,150,24,88,34,61,25,43,47,196,165,0,116,188,72,31,100,28,199,60,160,201,106,27,181,7,227,173,159,26,113,29,14,48,49,87,196,196,124,17,63,125,254,101,180,100,179,120,219,
69,251,241,225,107,175,66,111,71,187,213,241,119,92,119,53,254,254,200,137,68,34,84,75,68,165,77,152,88,22,54,38,71,164,86,92,178,211,128,118,127,19,175,246,124,94,39,154,90,245,25,237,251,89,173,84,27,
106,51,228,72,203,101,183,185,19,189,11,184,129,24,74,58,80,71,62,159,48,40,146,229,219,129,55,177,35,175,35,26,161,164,179,255,56,205,158,112,104,137,165,201,44,113,196,69,68,28,246,8,2,213,16,142,75,
194,236,137,244,73,156,154,72,166,18,114,162,4,104,75,71,59,108,90,81,146,72,89,137,249,134,254,146,18,92,47,67,254,198,20,6,145,124,38,179,91,44,153,23,51,111,57,28,35,213,122,29,15,63,251,2,30,59,244,
42,254,215,15,188,7,23,24,249,37,219,7,183,96,223,216,16,14,77,78,59,140,25,110,18,37,135,139,46,235,134,132,195,115,117,24,204,228,223,196,43,155,201,8,40,147,109,226,159,227,181,94,173,129,161,82,88,
179,236,54,191,197,107,205,224,203,181,21,242,9,175,170,41,128,159,226,27,25,169,184,156,54,62,132,100,19,153,82,77,177,64,182,38,134,156,236,108,156,140,157,132,238,46,236,47,37,226,32,201,106,172,179,
131,19,117,116,157,213,107,167,18,234,55,171,68,16,78,211,18,140,43,39,37,14,159,165,185,36,74,244,145,40,101,70,134,221,169,59,241,186,234,188,101,147,49,176,188,182,142,63,253,254,3,248,47,159,253,24,
250,187,58,181,135,117,225,121,91,241,202,196,148,206,196,78,113,192,19,88,84,172,115,146,153,235,136,95,69,3,54,151,201,88,84,148,245,90,45,165,79,29,54,102,26,244,111,45,148,194,199,52,12,113,78,201,
168,85,138,157,233,239,72,117,160,29,22,141,209,63,228,120,28,214,53,100,50,151,60,33,39,218,205,242,65,43,184,37,197,156,5,131,36,127,133,117,168,59,218,65,88,41,100,85,24,40,84,154,253,165,28,128,128,
91,173,28,41,239,221,185,6,16,52,115,199,51,53,19,93,172,196,25,99,85,225,148,75,25,40,19,219,163,210,26,69,171,149,10,126,244,228,51,248,236,59,111,212,105,18,67,3,49,171,180,89,190,184,109,98,137,100,
48,83,69,157,109,5,145,213,74,5,61,237,137,153,55,183,188,130,207,255,215,175,3,169,192,7,54,244,231,52,113,10,210,49,70,61,103,70,165,110,37,109,249,156,200,111,177,107,202,177,21,213,214,35,220,50,18,
15,52,84,102,180,243,105,90,135,100,251,155,20,21,231,180,87,76,110,54,25,144,50,254,204,207,68,150,149,50,9,139,202,71,150,3,137,107,39,1,195,152,254,65,70,110,199,230,229,117,211,115,142,193,155,44,
38,155,146,255,124,86,215,77,143,120,155,233,90,207,28,59,97,77,144,206,214,130,1,233,110,162,116,181,83,167,200,145,208,35,218,186,82,214,39,72,71,161,144,114,30,96,243,148,98,97,187,167,154,52,205,239,
171,189,80,208,178,244,108,109,50,118,150,95,6,26,210,175,237,249,188,225,211,84,12,231,185,89,31,233,62,77,83,102,229,70,50,210,212,228,222,89,240,188,56,97,144,171,0,200,6,26,245,59,138,76,42,48,60,
77,169,206,228,222,68,122,187,182,87,177,225,184,212,241,124,147,135,213,204,66,104,82,68,69,194,133,196,100,235,170,147,221,243,12,221,89,158,91,94,177,90,153,207,102,133,99,235,170,63,156,130,98,57,
107,116,72,110,145,78,167,157,93,94,193,121,3,253,98,96,230,209,94,200,99,117,189,226,238,91,210,119,90,218,228,122,97,139,23,80,211,71,149,203,100,48,218,215,139,137,249,98,83,154,134,110,111,54,206,
57,182,165,79,67,176,26,59,99,41,70,196,92,207,4,164,239,186,128,91,4,66,10,222,73,213,95,23,83,54,225,139,137,62,49,132,15,217,8,128,42,102,40,82,200,146,160,127,104,113,16,45,89,210,172,110,164,12,125,
33,187,112,123,44,16,208,12,150,101,157,115,69,70,68,68,163,35,59,206,98,138,29,176,131,25,20,159,135,145,178,131,36,73,251,68,54,189,124,165,188,46,114,239,195,246,114,243,234,112,145,112,28,57,248,87,
236,84,67,33,188,120,242,53,92,181,123,167,118,158,139,206,27,195,99,135,142,24,128,134,109,191,195,144,195,33,237,222,97,245,162,46,193,179,177,164,209,158,209,33,156,154,155,51,252,58,35,247,156,97,
97,152,123,70,135,172,115,189,58,57,13,14,133,239,148,107,124,40,169,91,107,43,92,65,60,47,29,185,12,11,26,33,77,240,144,245,231,192,100,160,158,81,28,4,178,94,14,188,200,196,50,105,38,170,1,105,197,9,
60,241,36,82,74,227,83,197,105,88,9,89,73,112,170,66,49,4,121,126,37,50,183,4,15,6,26,130,150,216,131,9,105,39,178,11,5,149,133,19,30,146,8,118,39,84,25,150,9,83,50,107,18,186,146,94,227,164,24,233,237,
182,30,232,210,218,90,40,34,151,156,91,38,247,215,3,223,58,38,67,164,73,185,106,138,149,156,36,95,37,220,32,133,231,78,156,178,206,115,227,69,251,19,18,157,82,70,178,15,199,237,114,241,150,96,38,2,41,
93,177,134,85,194,107,130,124,158,142,215,91,47,216,23,39,188,197,215,138,199,70,194,37,210,51,242,20,174,191,96,159,117,174,195,147,211,122,66,148,198,119,211,249,88,166,227,12,193,243,131,24,63,136,
169,63,28,223,155,28,95,172,141,11,196,9,123,136,199,179,210,104,85,241,231,62,55,76,44,101,12,122,197,12,138,243,212,211,157,105,103,80,23,164,197,2,108,43,45,41,155,202,114,139,19,222,53,55,245,26,148,
67,251,41,229,247,236,46,157,201,70,224,40,122,127,237,249,118,198,220,225,211,83,80,42,72,177,150,221,201,81,173,45,57,172,148,43,176,106,126,176,45,159,22,193,142,199,166,102,112,106,118,30,219,69,2,
216,53,251,118,99,251,64,31,78,156,153,75,233,123,114,194,5,169,225,88,135,72,31,167,244,165,124,93,178,243,60,140,246,247,224,244,252,2,116,129,9,73,70,87,218,189,109,219,210,143,75,118,156,167,251,31,
235,21,60,119,236,4,88,5,150,101,160,85,214,181,132,58,154,240,200,181,128,172,41,58,65,134,244,169,244,57,116,64,129,217,158,3,138,21,60,40,99,91,97,157,97,202,90,245,169,13,254,69,182,28,140,99,181,
127,10,218,198,99,166,191,54,189,22,107,223,125,225,206,219,113,254,214,81,216,27,25,59,127,207,206,223,52,254,13,246,116,225,253,111,190,210,122,16,79,30,62,166,129,24,122,251,24,203,107,101,235,152,
209,190,222,132,177,10,24,36,75,214,136,157,178,79,190,243,183,191,214,151,3,34,252,241,237,239,71,91,24,92,51,25,211,201,106,155,214,215,172,201,201,234,253,196,206,254,112,189,50,158,135,207,221,114,
83,148,196,236,104,139,178,206,243,185,119,191,3,25,35,187,240,209,231,95,66,205,15,82,159,129,126,111,130,164,26,255,13,75,224,176,241,157,178,143,213,250,199,245,189,210,89,231,230,255,67,116,215,83,
80,241,3,83,225,0,87,174,201,162,146,24,137,18,179,76,58,248,49,245,90,41,99,64,232,162,116,154,191,35,76,33,150,236,77,109,171,53,219,209,248,252,242,93,59,240,103,159,189,19,95,248,196,237,184,114,215,
246,208,150,212,77,194,152,186,220,228,156,195,189,93,248,226,39,126,7,133,22,29,146,124,230,232,9,156,89,90,22,148,108,149,176,68,195,123,57,238,160,217,191,121,223,238,36,93,64,153,247,3,65,25,15,217,
169,33,3,247,239,94,58,132,87,69,80,18,0,198,250,251,240,31,127,247,35,24,234,233,209,31,178,82,226,33,51,244,128,111,242,187,12,121,120,231,101,151,224,11,119,222,110,248,153,238,190,77,123,93,190,107,
7,126,239,157,191,5,21,184,7,179,124,198,255,211,205,191,133,203,140,172,194,186,31,224,222,39,15,88,207,176,233,63,201,242,80,176,7,186,72,191,208,199,18,219,237,131,113,140,54,129,196,216,138,38,27,
208,32,43,202,6,145,28,212,206,8,139,249,214,72,87,209,118,56,83,231,200,60,147,200,21,117,169,187,147,67,161,44,5,30,187,98,215,78,92,177,107,39,138,43,37,60,250,252,203,120,252,224,171,56,58,53,3,63,
80,186,242,172,230,23,51,6,187,186,240,238,171,46,195,135,174,187,218,34,49,250,65,128,191,248,241,35,137,82,187,168,193,29,115,144,0,188,232,240,29,62,120,237,155,176,86,169,226,231,47,188,140,51,75,
203,233,246,169,140,248,134,127,255,135,239,252,16,95,250,252,167,181,180,217,93,35,67,248,243,223,255,20,238,123,242,0,238,127,226,105,44,172,150,173,96,16,139,254,202,101,178,184,100,231,54,92,119,225,
62,92,183,127,31,186,219,219,48,191,82,18,249,25,58,4,210,236,181,86,169,160,208,210,130,140,231,225,67,111,121,19,6,187,187,240,23,63,254,9,22,74,37,235,183,125,157,29,248,167,239,123,23,174,115,248,
30,223,249,219,95,99,106,126,161,185,189,222,20,58,111,242,123,173,150,130,171,220,154,125,201,68,232,48,82,89,97,13,234,141,72,188,217,120,53,132,88,89,20,3,158,11,40,116,169,180,219,45,208,56,83,145,
130,161,40,54,70,162,20,177,158,119,108,38,167,75,154,224,198,193,142,254,174,78,220,241,214,107,112,199,91,175,65,205,247,113,116,106,6,167,231,23,176,92,46,163,84,94,7,131,209,218,146,199,80,79,55,198,
71,6,177,99,112,192,73,135,103,102,124,233,254,135,48,33,30,104,92,134,205,40,12,243,226,169,9,76,206,47,96,108,75,159,70,233,248,212,77,55,226,83,55,221,136,32,80,168,212,235,214,29,124,232,139,255,7,
108,122,29,225,204,202,10,190,240,157,31,224,139,159,212,119,180,246,66,30,31,189,241,45,248,200,13,215,226,196,153,57,28,62,61,133,197,213,53,172,85,170,200,101,51,232,40,228,209,219,217,129,157,67,131,
56,111,160,223,130,87,245,117,77,105,40,142,156,50,230,107,110,185,132,39,14,31,193,71,110,120,11,0,224,250,11,247,225,218,243,247,224,185,19,39,113,124,102,22,203,107,101,116,183,181,97,124,100,16,151,
141,239,176,204,170,200,143,251,222,47,31,79,196,57,136,54,17,203,137,202,86,179,161,53,234,152,27,27,80,123,164,90,91,82,72,59,146,66,82,96,143,180,92,31,142,181,184,66,54,175,21,65,100,213,200,193,54,
34,190,209,88,82,204,27,184,117,174,155,73,234,15,199,26,171,142,8,1,44,137,225,180,226,159,205,59,184,37,155,197,5,231,109,197,5,231,109,61,43,190,82,205,247,241,231,247,61,132,135,194,52,87,56,98,13,
74,19,207,3,254,207,123,255,6,255,233,211,31,135,231,217,15,48,147,241,208,158,201,59,232,22,82,189,94,95,128,94,56,241,26,254,151,47,127,29,255,238,227,191,141,177,254,62,203,47,25,31,30,196,248,240,
224,217,17,177,152,67,176,129,92,123,127,211,254,252,218,35,191,192,248,208,32,174,222,183,59,190,167,43,119,143,227,202,221,27,23,44,58,62,115,6,255,219,215,191,131,90,221,215,106,115,128,146,129,232,
98,6,36,96,56,195,86,49,104,66,183,97,1,95,147,206,121,33,139,242,24,78,192,192,211,164,151,98,178,162,31,192,83,129,128,192,68,52,29,74,20,243,148,89,134,113,106,166,216,117,196,255,77,118,100,140,249,
11,50,37,139,255,32,84,181,37,225,138,13,141,84,129,213,197,145,253,255,252,253,251,241,248,193,87,27,157,127,14,94,7,142,28,199,63,249,210,87,240,208,129,231,160,225,137,177,25,148,104,72,73,254,218,
115,199,78,226,223,124,243,123,88,116,232,116,53,13,114,107,197,115,196,253,130,113,114,102,22,127,240,127,255,55,252,240,215,79,161,82,171,191,161,251,154,152,43,226,158,95,61,161,247,175,232,75,237,
158,224,142,235,252,219,187,238,198,79,158,121,225,172,174,251,235,87,14,227,15,191,250,45,148,202,235,49,89,42,22,42,84,172,201,155,36,242,174,73,91,116,33,117,3,134,53,126,47,48,102,109,92,193,128,178,
147,196,40,196,126,179,6,87,71,237,9,97,245,44,148,219,169,246,156,208,96,10,51,65,203,58,52,74,83,177,3,14,118,66,199,100,83,10,92,107,155,120,243,240,129,231,240,240,129,231,26,138,130,187,118,224,226,
29,231,225,162,29,231,97,207,232,48,90,114,217,13,31,160,82,140,201,98,17,143,189,242,42,30,126,230,5,156,154,157,115,70,110,99,33,238,38,139,237,19,135,142,224,99,127,250,127,225,186,11,247,225,202,61,
227,216,53,50,140,129,174,78,180,230,243,206,156,19,102,78,61,87,244,213,90,165,130,191,248,241,195,184,235,231,191,196,251,175,185,10,87,239,219,141,61,99,35,78,51,198,244,159,14,159,158,194,129,35,199,
241,228,225,163,56,124,122,106,195,141,162,169,56,134,82,168,43,198,127,186,231,94,252,236,249,151,240,177,183,93,143,139,118,108,75,53,79,95,58,57,129,31,252,250,73,252,234,229,67,169,140,22,118,132,
226,211,216,48,86,149,168,24,190,37,103,241,207,166,247,106,176,151,56,102,154,27,96,82,184,48,100,85,156,243,108,164,28,10,146,160,150,251,104,5,180,141,70,18,195,25,214,53,223,164,178,127,197,155,180,
223,24,237,40,87,171,120,236,224,97,60,118,240,112,252,179,161,222,30,108,219,210,143,45,221,157,104,203,231,209,218,210,16,122,46,87,171,88,171,84,49,179,180,132,227,211,103,146,213,217,165,219,44,165,
229,101,155,76,209,166,176,139,106,190,194,207,158,123,9,63,123,238,37,87,233,118,253,199,142,85,194,204,226,140,62,95,92,93,195,215,127,250,11,124,253,167,191,64,123,62,143,189,99,163,232,237,104,71,
87,123,43,218,11,5,212,124,31,235,213,42,22,75,107,152,152,47,98,178,184,136,32,8,156,253,109,22,132,74,229,246,136,65,36,19,156,158,60,116,4,79,30,58,130,222,206,118,236,223,54,134,145,190,94,180,182,
180,160,84,169,96,126,105,5,135,39,167,49,31,83,118,200,40,29,230,120,142,230,12,160,84,142,140,193,11,212,25,29,90,159,178,131,151,211,164,108,30,19,132,202,165,200,7,81,161,54,47,155,76,94,165,192,241,
42,197,161,34,98,10,227,202,69,235,229,196,97,33,102,91,64,14,112,20,156,100,59,145,202,100,221,42,251,238,72,147,199,79,218,53,93,92,194,116,113,201,42,164,98,135,216,140,37,148,200,162,139,89,148,10,
179,98,18,59,206,202,233,196,73,98,119,217,63,110,182,59,135,63,92,173,84,240,204,177,227,177,22,21,147,17,96,35,210,232,19,214,172,96,131,120,34,200,106,212,76,88,78,127,88,88,40,173,226,215,175,188,
106,173,153,100,41,25,194,14,227,113,90,30,119,162,105,197,162,240,103,210,199,74,112,174,164,15,165,108,71,158,147,108,68,169,174,73,32,157,50,22,165,18,71,209,124,40,205,130,203,114,96,235,98,37,145,
244,40,127,142,28,147,129,204,178,224,250,10,200,74,99,213,145,246,60,200,96,211,70,14,176,114,214,157,50,249,96,96,23,251,139,157,4,60,98,163,16,166,57,185,201,156,185,102,109,63,114,112,123,162,135,
103,92,203,150,8,72,156,82,192,209,134,228,92,48,250,130,225,74,169,209,29,250,168,30,164,166,147,197,176,72,126,81,49,25,54,217,183,81,186,43,132,195,236,120,5,65,136,222,197,149,99,117,218,163,61,211,
101,127,36,85,22,181,210,113,50,39,72,182,67,82,16,227,50,45,209,66,68,241,121,185,137,25,18,223,79,84,145,138,37,23,75,105,221,217,24,179,36,52,225,68,48,87,169,70,9,182,200,118,140,148,197,21,20,136,
51,137,134,109,196,62,53,84,217,99,151,40,44,208,34,203,136,71,37,179,226,21,33,86,101,55,137,252,228,36,131,176,16,226,141,21,184,73,22,160,73,6,62,107,40,7,197,242,166,150,130,10,153,43,15,25,44,232,
198,249,85,204,182,21,209,130,240,30,19,182,169,217,90,130,44,164,64,70,161,83,214,30,160,174,112,207,32,161,87,155,252,86,25,15,159,12,22,177,140,85,81,44,120,144,148,145,86,142,108,1,6,217,101,53,180,
74,61,233,91,8,199,215,37,145,44,76,70,134,140,137,146,25,250,136,148,232,45,55,122,66,87,137,73,138,253,36,52,144,244,106,184,178,120,19,185,202,196,107,237,101,7,247,57,96,5,143,148,6,144,68,17,252,
32,240,27,129,66,165,148,78,77,80,208,235,230,153,197,102,76,61,22,145,162,168,213,95,80,44,54,145,52,117,16,118,238,8,73,85,39,78,240,115,161,170,199,98,43,209,107,138,179,51,87,75,230,168,187,106,252,
105,92,47,89,181,136,88,160,124,230,160,74,236,96,109,7,35,189,248,55,55,45,242,18,182,43,182,202,162,90,41,108,21,234,100,107,231,75,76,85,153,175,193,228,54,215,216,25,172,34,141,54,255,214,127,249,
191,187,221,70,203,130,73,204,55,182,229,67,68,252,2,137,58,5,67,175,245,40,158,7,71,32,141,145,159,142,120,231,75,75,80,227,100,44,24,172,110,89,113,75,171,187,25,9,96,71,25,216,150,8,98,8,88,5,8,197,
171,33,216,149,145,179,98,24,232,236,202,181,84,98,21,145,95,43,195,248,150,114,220,134,240,50,41,78,162,192,225,142,195,36,132,28,162,254,37,131,212,205,100,0,7,122,201,55,179,61,137,111,157,104,6,107,
246,26,133,117,67,68,192,135,34,123,84,74,82,176,40,81,166,17,216,13,47,95,19,102,166,120,215,72,76,80,221,198,86,148,236,251,81,193,165,196,236,72,236,83,105,199,199,245,86,144,228,88,179,64,141,17,42,
140,128,96,20,131,140,4,162,67,147,35,41,32,146,12,216,104,157,85,208,38,2,69,101,232,196,51,37,98,139,136,73,36,76,102,133,184,150,135,230,254,88,210,53,14,3,52,76,9,86,113,154,183,78,178,36,241,252,
21,12,9,162,248,254,85,92,137,0,146,234,30,143,19,178,202,16,70,34,124,217,88,176,23,146,179,168,16,133,210,29,229,232,181,137,18,251,14,76,86,144,135,92,16,29,155,172,74,225,244,178,172,174,107,48,84,
57,5,175,99,35,51,48,93,160,195,112,66,77,59,137,245,250,119,58,55,25,102,114,78,52,210,83,251,199,129,141,91,229,223,224,78,221,183,155,216,76,15,55,17,37,96,51,185,152,141,146,212,102,254,5,219,57,46,
204,112,122,76,204,6,119,66,212,37,212,1,42,89,215,80,68,179,83,42,99,147,97,18,57,177,13,78,220,0,203,220,98,23,239,215,206,20,36,195,76,76,98,60,26,208,18,26,82,141,114,74,1,2,100,131,122,64,225,172,
32,102,246,152,188,108,35,63,136,161,175,217,134,62,150,46,16,2,173,182,161,88,85,163,50,106,196,228,84,139,119,201,11,107,150,69,147,50,12,176,72,209,4,187,224,188,67,208,88,139,186,146,196,18,66,219,
157,82,106,73,177,205,253,129,157,204,195,38,10,110,140,113,77,176,66,108,117,114,147,181,206,231,128,63,137,53,142,130,126,175,6,82,14,193,2,208,129,5,151,224,159,142,222,19,82,224,111,23,130,205,46,
36,222,24,59,226,122,202,241,188,180,123,34,81,124,85,175,159,230,134,197,201,129,20,34,37,187,84,55,127,137,137,178,204,202,99,102,112,160,192,65,128,44,50,204,236,115,192,74,85,192,28,84,23,231,243,
254,122,121,45,91,104,109,103,171,142,157,40,142,99,32,136,137,229,37,77,9,214,237,239,56,91,87,55,55,216,8,159,152,171,138,43,6,35,181,3,88,214,242,22,43,29,59,142,145,3,203,89,60,211,97,235,74,250,144,
9,183,203,251,136,114,183,73,170,201,40,123,6,201,85,82,113,138,58,71,140,224,232,106,30,228,136,153,193,0,71,88,152,153,12,151,36,142,168,134,27,155,101,73,195,73,168,173,198,127,163,137,60,129,152,77,
202,168,19,74,164,239,86,154,108,43,81,226,207,144,33,149,165,85,97,98,205,233,214,48,61,51,202,160,4,254,145,230,139,66,175,39,10,102,248,235,107,229,234,66,177,0,70,0,160,10,130,31,176,66,102,231,248,
206,92,16,168,75,131,122,189,71,101,178,91,130,74,185,171,54,51,121,180,117,124,207,0,129,72,51,11,194,90,110,204,137,15,192,68,98,102,179,94,49,137,69,140,130,161,169,124,48,235,213,149,92,73,68,9,37,
32,188,110,168,153,37,207,25,41,21,198,142,21,81,156,3,65,108,0,193,162,77,122,57,47,55,123,129,57,241,133,152,245,253,202,76,26,74,250,195,48,165,136,196,253,70,253,71,70,137,101,113,125,113,255,44,139,
128,59,138,14,153,125,23,57,187,100,228,193,68,133,65,163,90,124,177,251,198,100,44,96,137,94,50,59,34,223,44,20,14,153,146,93,91,230,189,68,253,75,218,106,192,218,226,194,6,225,37,185,94,114,46,171,200,
141,0,49,164,195,205,90,109,106,114,228,142,36,207,69,60,38,125,225,12,148,154,253,233,3,135,235,229,242,86,120,153,149,124,46,119,184,80,40,188,218,146,205,62,149,85,10,148,107,105,89,170,85,107,51,168,
215,150,149,226,222,76,71,103,55,115,3,199,210,11,205,11,2,88,52,253,34,148,41,124,79,2,42,141,166,113,82,242,76,212,117,176,228,99,194,7,70,250,22,44,129,186,184,152,57,233,78,89,130,112,33,174,150,43,
235,176,83,88,49,139,76,40,51,66,83,20,52,28,94,154,64,108,38,251,11,167,214,16,66,130,138,157,74,17,150,98,51,183,90,160,82,172,199,43,20,27,102,15,37,172,86,51,22,74,144,43,109,228,92,134,229,237,204,
104,146,48,5,204,162,153,141,11,83,130,26,10,95,139,100,13,243,16,200,33,205,6,212,3,141,204,122,245,19,57,73,100,250,131,212,228,138,76,39,50,178,11,19,100,82,104,28,144,201,89,9,207,199,42,6,122,72,
244,73,84,8,148,194,186,126,202,101,118,134,46,138,215,222,209,163,74,43,185,12,104,41,147,205,204,180,228,91,138,62,51,178,7,158,126,122,249,194,139,46,126,128,89,157,79,204,53,48,179,95,173,182,112,
131,243,174,11,69,88,180,1,91,69,141,73,82,84,184,9,7,139,29,33,127,22,126,141,129,120,152,120,37,25,142,47,177,190,178,146,1,251,178,14,43,195,81,9,149,205,210,104,12,173,20,181,89,159,219,233,58,147,
30,113,182,180,243,28,222,170,22,126,32,87,247,178,37,118,199,118,163,244,123,149,148,24,176,155,78,99,70,122,77,53,75,211,166,132,136,146,167,40,170,75,122,186,149,137,205,108,211,167,68,21,97,205,171,
52,158,171,148,34,77,76,49,209,127,209,185,201,238,55,19,149,149,187,93,88,65,151,131,90,173,5,204,76,68,53,86,92,2,232,199,7,158,62,176,154,5,128,181,242,242,84,150,178,179,164,212,12,101,50,35,149,217,
153,206,165,167,31,63,212,125,197,53,251,19,14,55,219,65,83,41,237,174,108,142,150,204,249,176,60,89,137,98,197,145,174,100,224,43,214,245,126,227,149,70,114,111,34,187,118,131,234,204,236,168,143,174,
85,241,52,227,49,82,88,131,200,102,185,166,177,239,205,72,21,39,166,72,140,53,24,229,151,117,227,62,37,238,16,154,142,164,77,60,74,36,53,217,240,202,69,156,70,174,234,164,132,83,32,27,160,224,226,154,
203,232,227,6,8,130,171,221,164,45,148,77,229,140,21,82,228,21,57,238,47,13,177,162,68,17,37,238,227,52,21,198,180,231,20,101,248,40,165,150,159,252,229,193,106,113,110,7,128,146,71,52,75,158,55,91,41,
85,167,1,32,11,0,93,237,61,5,223,175,175,215,235,254,20,136,118,41,223,223,90,91,89,238,108,48,20,148,24,97,12,75,55,159,157,81,36,155,121,160,144,74,224,99,103,5,80,55,68,202,82,127,212,80,232,38,27,
232,212,89,198,130,115,111,209,83,12,68,194,14,108,82,10,29,213,168,209,109,142,24,45,99,80,98,248,100,5,44,245,27,37,99,137,149,80,184,185,66,11,189,96,38,173,110,160,174,95,107,108,79,108,122,198,208,
217,18,108,44,243,2,50,213,207,101,122,191,178,200,160,74,212,217,153,82,86,20,178,77,54,201,68,96,35,34,175,228,174,195,154,47,138,88,162,137,68,76,68,176,17,68,158,190,23,174,192,181,210,114,167,98,
110,247,188,204,201,76,54,59,153,107,105,41,103,178,153,54,0,165,108,6,160,76,144,89,81,158,250,101,38,147,217,230,213,235,115,1,243,80,109,105,161,173,190,188,184,144,235,238,237,99,40,205,94,108,116,
190,114,204,78,214,125,21,69,218,86,71,236,90,41,73,247,10,205,149,91,19,28,22,83,138,57,41,106,169,13,0,35,218,47,71,175,139,227,68,58,241,208,132,234,137,21,154,11,201,178,139,96,12,171,154,76,52,200,
137,157,24,191,14,125,9,2,141,70,240,148,16,153,201,0,85,162,6,38,91,38,14,11,132,81,183,5,141,200,131,226,24,154,228,48,162,175,231,170,146,70,28,148,237,109,108,236,122,84,93,43,170,73,172,87,130,137,
159,175,66,26,165,90,154,184,137,8,53,155,182,148,69,249,1,43,40,18,222,84,216,102,22,187,120,160,0,127,169,184,80,91,90,108,103,230,154,71,84,244,60,111,46,227,101,126,253,226,11,47,148,0,32,115,193,
133,23,102,94,120,229,5,213,219,223,51,203,140,75,3,223,239,225,76,102,75,80,171,245,213,103,167,167,10,59,246,246,70,148,170,196,223,84,134,98,136,67,149,68,201,140,176,70,199,107,232,21,39,53,28,162,
12,69,37,58,85,210,94,24,226,154,156,84,145,141,234,214,65,83,49,17,165,218,0,235,154,176,84,88,160,39,212,8,81,9,173,44,176,86,130,78,147,1,19,17,38,77,242,42,134,29,19,181,23,104,245,241,88,150,253,
138,239,87,167,202,104,26,82,154,154,135,33,212,128,36,205,89,107,131,104,163,18,148,33,145,178,166,159,43,190,71,113,77,192,104,167,72,183,146,137,114,166,58,142,134,62,177,129,16,38,12,14,167,170,137,
228,114,197,52,116,93,81,38,46,57,7,67,58,148,13,116,76,142,77,146,136,172,82,243,63,123,112,58,168,215,70,201,243,22,178,185,236,225,150,124,254,101,63,240,127,184,176,176,160,46,190,232,98,242,84,16,
112,6,160,44,101,242,217,108,118,58,155,205,30,71,16,156,96,162,122,181,180,50,92,62,241,234,169,120,16,40,37,108,119,210,178,6,181,128,51,155,120,94,180,141,138,173,87,124,23,165,247,18,179,241,27,199,
121,89,135,15,73,64,206,186,121,66,154,122,163,134,163,234,24,168,230,51,104,56,163,246,183,217,118,110,54,227,4,205,159,141,227,205,44,66,114,96,189,230,104,48,241,93,199,119,27,181,129,19,19,44,129,
94,205,224,12,165,156,23,206,231,166,253,131,217,47,230,177,100,180,145,82,206,103,244,179,12,28,25,34,114,150,73,207,22,46,173,95,19,28,143,97,197,1,86,143,30,124,205,95,47,143,0,168,121,158,119,60,151,
203,29,203,181,228,166,115,45,185,2,0,188,248,210,139,156,61,120,232,144,218,183,239,124,239,229,131,7,87,246,237,219,123,111,54,151,27,200,212,235,199,20,121,67,65,181,114,222,242,243,79,149,242,91,119,
212,51,185,134,236,135,41,243,13,226,0,0,9,206,73,68,65,84,82,42,222,102,201,101,155,167,113,10,236,88,175,176,119,77,7,165,137,87,31,194,125,228,82,185,136,205,58,182,210,29,108,227,137,83,50,119,210,
210,251,157,97,76,71,188,222,157,241,195,18,6,111,202,33,48,142,119,242,87,40,253,61,169,24,60,225,200,20,214,218,198,134,15,203,22,17,202,214,9,55,139,207,56,140,81,35,113,46,246,7,201,88,40,156,199,
83,202,185,200,201,197,209,180,120,157,200,170,131,6,47,67,10,4,168,90,173,182,242,194,129,130,82,170,221,203,100,143,103,179,217,99,217,108,118,34,8,130,7,94,61,252,234,106,116,173,12,0,244,247,247,209,
98,177,136,76,62,183,94,200,23,90,153,185,87,249,245,44,136,122,84,16,244,150,143,31,154,204,111,27,207,83,38,151,147,40,174,131,138,111,112,119,140,246,57,225,85,114,39,21,165,240,169,220,217,104,250,
251,166,162,25,41,215,130,41,158,97,252,223,25,193,118,141,33,50,168,139,70,202,73,202,156,215,42,160,177,131,175,148,42,84,144,166,102,191,65,157,16,215,239,211,162,244,4,151,176,8,233,60,171,20,100,
139,13,174,106,106,255,185,214,83,74,111,147,85,72,61,237,123,24,73,68,4,248,235,229,181,185,7,127,120,134,149,26,132,71,197,108,46,251,98,75,62,127,48,155,205,62,126,228,213,35,7,101,147,50,0,80,44,22,
121,215,238,221,153,137,83,175,169,238,158,174,169,12,121,231,3,84,83,65,224,43,162,110,229,7,67,229,99,135,22,242,195,91,235,94,161,208,10,24,74,124,6,12,23,83,7,4,71,203,34,152,153,51,159,205,136,49,
139,232,112,74,33,71,131,58,175,137,78,196,79,221,81,249,202,81,95,68,153,97,106,173,189,108,132,151,13,116,205,250,156,69,2,146,174,229,155,196,17,216,144,103,102,157,170,45,163,190,164,199,0,180,112,
55,73,49,2,87,238,146,171,10,148,187,38,186,78,167,79,43,152,106,152,92,208,101,99,163,25,33,181,146,57,109,146,50,220,228,81,74,17,7,55,233,6,112,212,132,97,51,86,195,26,34,89,91,152,47,22,31,125,96,
157,21,15,146,71,243,217,76,230,153,150,124,254,229,92,46,55,225,51,255,104,121,113,49,216,187,119,47,21,139,197,180,245,20,216,53,62,126,161,98,126,87,189,94,31,168,85,171,251,125,165,46,87,190,63,76,
68,165,238,55,93,87,107,29,219,62,10,11,234,123,3,175,215,93,115,228,44,142,61,71,47,118,213,186,60,151,109,48,137,83,155,58,183,81,12,230,13,61,3,199,73,154,125,247,27,121,208,112,205,244,77,29,234,226,
135,69,127,86,38,78,78,46,31,120,172,192,64,7,121,153,201,92,54,243,108,190,80,120,37,151,203,205,129,232,167,199,143,29,59,104,158,79,83,23,27,31,31,167,197,197,69,44,46,46,206,245,244,246,188,230,121,
222,16,136,214,217,247,137,9,253,42,8,6,171,147,175,17,7,254,84,174,127,184,91,2,219,102,44,201,132,201,181,156,124,51,248,102,109,135,148,206,89,119,237,189,174,232,174,35,230,162,209,21,4,187,143,204,
80,168,238,228,216,239,9,70,234,164,109,142,165,177,115,245,182,81,76,141,113,221,174,158,152,108,104,67,153,54,63,233,38,141,43,84,67,70,200,193,162,225,54,51,193,244,94,212,145,98,56,250,2,105,102,117,
74,153,240,38,58,29,90,226,154,203,106,36,3,245,54,118,117,165,152,75,47,61,115,178,244,210,179,91,152,185,219,243,50,179,217,108,230,153,124,161,240,124,54,155,155,4,240,215,39,142,31,63,9,0,227,187,
118,209,226,226,98,186,69,190,115,231,78,58,113,226,4,103,0,26,221,182,173,149,136,110,173,85,171,87,213,106,181,43,131,32,184,140,153,123,9,88,207,245,246,79,246,92,119,211,246,76,54,147,99,97,86,197,
73,241,228,162,193,154,113,138,13,124,54,131,71,148,172,6,142,89,40,242,143,181,26,35,113,246,152,45,82,224,84,43,1,28,213,32,117,241,49,182,86,3,61,8,69,46,77,11,233,35,9,178,159,30,44,99,221,127,138,
248,69,70,215,165,142,14,87,14,12,137,240,169,99,65,230,152,110,33,82,21,200,29,255,149,11,151,73,227,167,148,241,15,171,223,19,36,64,239,135,180,169,168,11,30,88,253,31,207,79,25,88,76,82,196,149,95,
175,47,254,237,35,167,252,210,242,86,6,10,32,42,230,50,153,103,91,242,249,3,185,150,150,3,80,116,223,107,167,79,85,163,13,226,248,241,227,188,129,203,106,191,70,134,135,63,28,4,193,13,190,239,239,12,148,
26,103,230,81,40,110,37,143,166,251,222,249,254,193,108,161,181,61,193,113,100,192,168,217,38,104,230,37,136,44,191,102,78,28,105,161,38,141,76,151,86,102,71,75,1,226,36,7,131,109,190,139,21,20,75,254,
103,142,46,49,160,68,237,115,183,57,162,255,29,45,34,174,82,131,150,44,143,97,219,233,9,90,82,43,144,82,125,120,247,103,250,253,232,53,12,101,14,134,221,159,108,2,43,242,102,8,27,160,132,208,40,155,86,
166,163,201,76,160,52,228,46,225,108,145,198,31,163,184,122,148,95,46,175,46,252,228,190,34,51,15,19,209,26,121,222,233,76,198,59,158,205,230,78,102,178,153,159,79,77,77,223,183,209,216,207,52,251,114,
235,216,152,183,82,42,241,234,234,234,193,174,238,238,53,207,203,100,9,52,7,86,53,120,212,29,40,53,84,57,118,104,197,235,236,90,71,46,199,148,203,181,232,190,92,147,244,62,135,227,236,68,233,154,20,187,
48,161,112,151,244,81,228,128,59,220,232,212,233,107,210,31,44,39,21,122,230,187,211,137,109,114,3,86,206,188,153,167,239,66,103,0,171,206,96,18,236,35,231,141,48,55,7,183,204,204,78,151,75,147,118,215,
58,91,96,147,34,166,220,252,55,58,104,225,244,201,83,174,162,23,73,245,203,107,165,234,204,228,210,210,175,30,173,51,176,133,136,138,25,47,115,32,151,203,61,157,205,181,28,206,100,50,63,158,154,154,126,
116,51,155,195,134,59,200,232,232,152,55,53,53,169,0,96,100,100,116,63,51,223,28,248,245,193,122,189,126,65,160,212,165,172,212,86,48,123,68,52,223,186,123,127,189,101,116,107,75,75,79,255,64,164,194,
193,72,179,0,206,129,115,255,70,94,116,174,154,208,44,159,240,55,213,174,205,252,40,61,237,207,85,86,200,148,178,70,10,129,230,220,117,104,90,44,40,197,76,140,168,69,46,228,52,52,37,106,197,185,217,234,
212,68,189,114,226,213,2,51,247,129,200,247,188,204,68,198,163,231,178,45,45,175,100,179,217,34,136,30,156,158,154,122,21,0,182,110,29,163,211,167,39,249,13,77,144,112,98,120,211,211,83,42,3,208,192,208,
240,8,179,186,53,8,130,81,223,247,119,7,74,237,3,121,219,89,5,93,172,84,142,64,43,249,173,219,171,80,65,41,215,63,128,252,246,221,59,189,76,198,139,140,220,216,174,52,204,5,152,126,133,20,114,144,68,181,
88,213,144,52,229,120,144,78,97,78,224,89,145,187,193,186,64,4,132,201,197,230,86,31,109,213,172,43,140,199,230,153,97,138,73,237,37,45,165,87,254,222,109,37,104,219,73,34,34,32,12,67,34,205,234,115,173,
47,26,125,29,186,0,134,230,24,177,158,91,65,146,52,105,10,69,11,82,37,105,44,98,247,18,71,6,68,109,111,73,198,115,79,65,4,147,172,83,74,96,91,93,106,148,225,129,84,160,84,229,248,225,227,245,226,44,129,
50,157,181,51,147,5,48,119,48,81,221,203,230,150,72,5,167,60,207,59,156,205,229,142,102,179,217,73,0,63,158,153,153,153,1,128,209,177,49,154,154,156,228,55,188,131,68,175,225,225,17,154,153,153,102,0,
24,216,210,223,73,94,230,29,129,82,231,41,223,223,170,148,26,85,74,141,41,165,182,129,121,128,129,14,0,30,1,101,202,229,214,168,208,86,229,213,149,245,220,240,104,208,113,217,213,227,148,201,229,192,28,
252,70,87,118,106,182,81,157,139,139,52,81,155,119,156,254,172,175,152,26,88,164,13,118,96,135,211,238,60,132,54,213,110,249,69,130,99,144,38,108,225,60,191,147,112,208,100,151,128,91,165,85,56,251,30,
251,117,127,245,153,39,142,213,231,206,228,168,80,104,101,191,158,231,122,189,157,129,86,0,1,1,37,120,222,92,134,232,148,231,121,83,148,201,76,121,158,55,145,201,100,38,152,249,103,115,115,115,107,141,
177,60,76,51,51,51,252,122,158,242,89,189,122,251,250,243,89,143,174,86,65,176,61,96,222,171,130,96,148,89,13,50,115,31,51,250,192,220,199,204,221,12,100,168,33,147,162,64,168,0,180,78,58,47,195,238,203,
77,12,71,218,192,212,221,108,104,5,77,192,180,205,156,107,163,182,16,54,36,136,156,85,216,103,179,15,176,41,214,113,22,145,136,205,244,63,111,48,175,95,111,159,33,113,255,61,6,10,96,46,132,127,43,34,170,
19,176,2,162,121,2,22,200,243,22,200,243,102,189,140,55,149,241,188,67,4,154,240,107,245,39,151,74,43,193,185,90,6,95,247,171,175,175,239,10,102,110,83,65,208,11,162,171,57,8,122,20,243,0,51,119,3,200,
130,185,139,153,7,25,232,13,193,1,117,110,131,124,166,185,112,22,195,80,75,156,58,215,129,53,227,164,105,224,214,235,137,185,89,60,150,38,179,219,57,98,77,78,72,179,161,191,65,231,164,222,139,35,60,222,
172,223,210,191,247,0,246,137,188,69,16,157,241,128,101,38,242,137,104,197,35,154,35,143,150,0,122,194,203,100,22,137,176,190,80,92,120,254,92,121,152,111,232,213,223,223,79,197,98,81,27,151,189,189,189,
59,192,220,81,247,125,5,96,139,231,121,215,177,82,189,204,188,133,153,187,16,237,38,155,176,42,94,143,43,122,206,252,239,179,176,222,168,185,209,115,110,97,137,20,136,120,195,182,56,120,101,155,109,27,
165,204,239,205,245,151,16,181,59,203,65,25,187,65,28,89,32,180,226,121,222,28,17,21,153,249,49,48,207,101,179,217,12,19,202,75,139,75,90,61,188,254,45,253,84,156,47,242,63,234,4,145,19,133,153,189,229,
133,5,5,0,129,232,191,238,238,174,62,2,181,248,65,224,177,82,89,203,36,37,125,49,212,11,15,217,143,155,68,253,161,134,195,73,26,62,26,125,102,201,6,53,1,157,136,100,90,182,46,234,108,210,75,164,59,16,
125,231,8,36,59,162,223,155,95,1,172,188,38,192,161,242,47,163,143,73,74,129,30,196,179,13,87,210,250,88,170,154,81,168,150,107,70,76,116,193,106,210,21,143,245,123,145,247,38,3,157,178,5,100,208,212,
227,223,27,97,148,200,65,143,104,2,0,123,68,126,38,147,97,197,92,93,89,89,89,20,241,10,2,128,238,254,62,143,8,92,156,95,80,231,98,92,255,191,93,229,181,159,171,198,106,47,0,0,0,0,73,69,78,68,174,66,96,
130,0,0};

const char* LivePanelComponent::step_2x_png = (const char*) resource_LivePanelComponent_step_2x_png;
const int LivePanelComponent::step_2x_pngSize = 19046;

// JUCER_RESOURCE: forward_2x_png, 14663, "../Images/Forward@2x.png"
static const unsigned char resource_LivePanelComponent_forward_2x_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,120,0,0,0,160,8,6,0,0,0,199,9,168,144,0,0,0,1,115,82,71,66,0,174,206,28,
233,0,0,0,6,98,75,71,68,0,0,0,0,0,0,249,67,187,127,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,219,10,29,20,35,35,91,15,220,16,0,0,32,0,73,68,65,84,120,218,237,125,
89,116,28,231,117,230,189,127,45,189,97,95,8,16,164,72,144,20,73,237,182,101,199,171,118,239,73,188,38,142,115,50,142,39,25,159,204,67,94,102,242,158,115,230,97,242,54,231,36,51,199,243,52,62,182,51,73,
156,76,70,147,88,118,18,199,178,64,106,33,41,137,148,34,82,27,40,9,32,137,173,1,16,27,129,222,151,170,123,231,161,182,255,255,171,26,104,82,160,68,82,40,29,136,64,119,117,119,117,221,255,191,203,119,191,
123,47,192,206,177,115,236,28,59,199,206,177,115,236,28,59,199,206,177,115,236,28,87,119,224,13,114,13,193,143,144,174,73,191,54,222,228,103,231,184,193,4,44,0,64,124,255,251,223,239,126,224,129,7,238,
32,162,225,90,173,214,237,56,78,182,94,175,167,93,215,181,136,40,188,54,33,4,27,134,65,134,97,52,76,211,172,166,211,233,170,109,219,43,93,93,93,75,135,14,29,58,11,0,180,35,236,247,95,192,8,0,226,133,23,
94,56,216,213,213,245,145,98,177,56,66,68,183,21,10,133,92,185,92,206,86,171,213,76,173,86,75,55,155,77,219,117,93,147,136,68,248,66,68,54,12,195,53,77,179,97,154,102,37,147,201,148,45,203,90,235,238,
238,94,238,232,232,88,201,229,114,43,204,60,157,205,102,151,15,31,62,60,183,35,232,247,86,192,8,0,198,228,228,228,195,165,82,233,112,165,82,57,188,188,188,220,187,182,182,214,87,40,20,122,171,213,106,
167,227,56,22,34,178,16,194,69,68,66,68,70,196,150,66,18,66,184,134,97,52,179,217,108,41,155,205,174,230,114,185,181,116,58,61,63,52,52,180,148,201,100,46,88,150,117,113,71,208,239,141,128,141,169,169,
169,71,214,215,215,239,218,216,216,184,125,126,126,126,215,202,202,202,80,169,84,234,117,28,39,5,0,44,132,112,59,246,238,79,13,221,247,209,189,153,142,156,109,155,150,48,13,1,66,8,12,46,143,153,217,37,
23,200,37,168,53,234,78,181,92,105,230,143,255,226,77,34,50,16,145,82,169,84,53,155,205,22,7,6,6,86,178,217,236,228,224,224,224,76,111,111,239,204,75,47,189,244,252,183,190,245,45,23,17,221,29,1,111,179,
141,61,127,254,252,97,102,126,240,202,149,43,119,77,79,79,143,44,45,45,141,148,74,165,94,34,50,77,211,108,12,125,242,161,225,161,253,163,3,153,84,26,187,115,105,68,64,96,102,96,0,16,232,253,238,171,103,
96,102,32,98,96,102,104,184,46,59,228,66,163,225,112,189,209,160,141,245,43,149,202,234,74,121,253,181,151,231,109,219,174,117,118,118,94,233,238,238,158,31,30,30,158,234,239,239,127,203,48,140,87,123,
122,122,150,134,134,134,74,59,2,222,166,93,123,241,226,197,223,220,216,216,184,127,122,122,122,95,62,159,191,109,125,125,125,151,235,186,150,109,219,149,195,95,253,237,123,122,58,187,172,238,92,22,125,
9,70,154,148,253,75,210,180,51,50,2,3,123,231,250,130,119,93,2,135,9,106,245,38,59,174,203,27,197,66,253,202,236,236,250,250,235,158,160,7,6,6,22,135,134,134,46,246,244,244,188,213,213,213,245,246,250,
250,250,235,159,252,228,39,139,31,52,181,189,221,2,54,47,92,184,240,187,139,139,139,247,79,78,78,142,46,46,46,238,171,213,106,29,182,109,87,143,124,237,219,119,245,118,117,89,93,217,244,182,126,38,17,
131,16,8,165,106,157,171,141,6,151,202,165,198,244,241,39,223,97,118,221,238,76,102,177,183,183,119,106,112,112,112,114,100,100,100,218,178,172,127,59,112,224,192,244,7,73,200,219,117,179,241,196,201,
19,131,131,253,3,95,159,203,231,239,155,156,156,60,180,178,178,188,151,137,197,222,135,63,191,107,239,129,131,125,61,185,172,8,54,41,182,186,18,150,254,85,30,71,240,246,176,186,187,189,83,253,231,24,193,
33,23,26,142,195,27,165,178,187,52,51,179,86,158,155,186,130,27,107,11,157,157,157,11,187,119,239,190,52,178,103,207,219,153,116,250,249,195,135,15,95,248,160,8,217,220,14,225,190,250,234,171,183,25,134,
248,234,133,139,23,239,157,156,156,60,188,177,177,49,100,154,102,253,238,223,249,206,189,187,122,186,76,67,24,129,102,141,52,49,104,194,12,132,75,154,176,201,123,146,17,60,245,204,209,107,189,247,100,
95,179,51,24,40,32,99,217,104,118,9,211,58,120,112,96,189,175,191,99,110,236,159,215,235,245,250,129,70,163,209,193,204,29,35,35,35,230,196,228,132,56,124,251,225,137,15,130,144,223,237,14,198,115,103,
207,222,6,136,95,155,158,154,190,111,242,194,228,209,66,161,48,152,201,100,138,31,254,246,119,63,218,219,217,33,34,25,122,123,13,130,157,184,201,38,222,236,239,118,143,122,211,129,90,163,193,213,122,131,
23,167,46,44,175,189,114,122,182,171,171,107,117,255,232,254,201,221,195,187,207,118,116,116,156,56,114,228,200,45,47,228,119,181,131,159,126,250,233,65,16,248,213,169,75,83,247,77,78,94,56,90,42,21,251,
7,238,254,80,234,142,79,124,250,104,87,54,131,193,14,11,118,40,5,62,149,38,54,14,151,128,247,183,31,28,41,155,91,125,158,1,18,36,131,210,214,183,77,3,4,166,208,178,76,48,110,63,50,136,134,45,150,79,63,
139,116,145,144,92,194,221,195,187,225,173,183,223,134,59,142,30,189,165,133,252,110,4,108,246,245,247,125,125,234,210,165,123,39,39,39,143,22,139,197,254,225,79,60,208,123,248,158,251,134,59,210,105,
84,212,103,228,18,249,106,85,222,139,250,189,229,45,238,118,235,231,245,37,97,8,1,136,136,86,214,64,60,48,218,15,136,184,244,194,211,112,105,106,10,152,25,134,121,24,206,159,63,15,119,222,121,231,45,43,
228,107,21,176,241,230,27,111,252,238,244,204,244,125,147,147,23,14,175,175,175,15,14,222,243,145,212,225,187,239,29,206,165,109,228,45,239,21,199,212,238,86,170,153,181,115,177,197,187,234,143,11,244,
246,123,79,54,35,96,255,254,62,134,135,97,233,249,103,97,106,106,10,136,9,70,120,4,198,223,124,19,238,186,251,238,91,82,200,215,34,96,28,31,31,255,141,249,249,249,251,39,39,47,28,90,95,95,31,74,167,211,
197,163,31,255,212,209,108,58,229,237,92,230,182,45,61,131,230,61,163,244,103,160,221,253,231,24,131,184,24,128,16,90,46,18,89,208,196,20,2,38,93,185,140,216,179,111,127,31,243,67,176,252,194,179,48,61,
53,13,76,12,187,135,119,195,27,111,188,1,247,220,115,207,45,39,228,171,21,48,190,244,210,75,71,214,214,214,62,58,57,57,57,186,188,188,188,215,52,141,250,135,190,253,221,143,118,101,211,24,19,172,228,238,
114,104,59,81,19,130,247,27,179,127,6,179,100,101,65,146,108,244,47,7,171,64,17,172,255,62,154,176,3,139,14,12,32,0,161,59,151,21,180,127,180,15,24,96,233,133,167,97,122,122,58,84,215,175,191,254,58,220,
123,239,189,183,148,144,175,86,192,194,117,221,7,103,166,167,247,45,46,46,238,35,34,113,247,111,255,225,189,125,29,57,193,28,120,199,28,132,174,128,126,84,131,8,192,64,192,140,128,82,28,196,225,137,20,
9,41,220,169,242,118,150,98,167,224,239,16,245,146,183,45,251,219,30,91,235,115,68,232,205,102,5,238,223,223,199,240,8,92,62,229,9,25,5,10,102,134,87,95,125,21,62,244,161,15,221,50,66,190,26,1,227,43,
175,188,242,216,229,203,151,239,202,207,207,223,86,171,213,59,70,31,251,82,255,96,119,167,201,44,235,216,104,135,5,66,139,158,39,101,183,69,58,24,84,129,3,69,2,3,244,221,111,146,98,99,255,179,16,0,136,
3,215,60,210,247,172,89,101,150,23,128,39,228,238,108,86,240,190,253,125,76,143,192,229,83,79,139,139,23,46,34,19,3,49,195,185,179,231,224,195,31,249,240,45,33,228,171,17,176,177,177,81,184,99,118,118,
118,100,125,125,125,151,105,25,213,61,163,163,125,134,136,130,26,53,230,109,21,12,65,98,240,19,216,86,111,65,200,54,152,21,123,12,74,232,165,253,43,169,253,240,61,228,168,59,124,15,6,68,128,174,92,86,
236,25,221,223,199,240,8,46,156,56,38,46,94,188,136,142,227,16,13,15,195,43,175,188,2,247,223,127,255,77,47,228,118,5,140,47,189,244,210,163,243,243,243,183,47,45,45,141,56,142,99,221,247,59,223,61,218,
157,203,10,98,78,12,120,24,85,200,138,253,29,135,44,197,179,200,26,194,229,61,230,197,204,114,188,27,89,235,0,170,196,36,88,83,243,207,73,87,245,254,10,32,223,206,35,32,244,118,116,8,222,63,218,91,202,
31,89,217,184,248,206,192,244,244,52,51,51,192,240,48,252,219,203,47,195,71,63,246,177,155,90,200,237,10,88,20,10,133,67,243,11,11,67,165,82,169,215,178,172,74,79,87,167,197,204,173,93,99,221,54,6,218,
51,124,142,19,124,50,117,231,177,18,36,121,187,206,119,138,149,205,140,146,125,141,158,32,223,84,72,39,248,31,142,126,76,238,57,119,0,221,217,172,56,242,169,7,15,231,119,239,89,187,252,252,51,238,204,
204,204,237,204,12,67,67,67,240,210,203,47,193,175,125,236,215,110,90,33,183,37,224,39,159,124,242,72,181,90,57,188,186,178,50,228,186,100,222,253,219,191,123,164,35,157,70,213,214,105,81,43,163,230,5,
111,130,109,192,102,79,115,228,140,39,8,87,57,159,89,13,156,153,35,0,132,147,206,241,181,10,2,116,103,51,130,247,31,232,99,6,184,252,252,211,48,51,61,13,196,4,195,52,12,167,207,156,134,79,124,252,19,55,
165,144,219,17,176,72,217,169,251,230,231,231,123,203,229,114,175,105,136,122,87,103,206,98,166,80,117,6,153,30,111,3,17,64,144,191,13,212,178,44,46,102,64,212,34,87,6,96,68,233,60,142,71,184,124,21,72,
52,199,195,180,72,238,254,255,57,178,37,236,199,201,221,185,140,128,209,209,62,128,71,96,241,212,211,48,59,51,11,2,132,24,228,65,120,241,197,23,225,147,159,252,228,77,39,228,182,4,92,40,22,70,86,215,214,
250,155,205,166,189,255,177,47,15,118,165,85,156,153,101,160,80,215,155,4,9,238,21,199,213,184,252,122,221,43,210,212,252,213,165,72,56,33,94,142,63,26,44,128,238,108,70,192,190,209,62,166,71,97,225,212,
49,113,105,234,18,18,19,12,194,32,60,255,252,243,240,233,79,127,250,166,18,242,150,2,254,241,143,127,60,224,58,206,109,165,66,161,23,0,104,215,222,61,125,186,119,28,58,81,44,249,61,138,151,133,241,176,
37,230,149,169,191,199,210,195,156,168,181,99,41,100,108,161,3,218,142,5,1,67,239,154,248,81,92,56,121,76,76,77,93,66,215,117,105,104,104,23,156,58,117,10,62,243,153,207,220,52,66,222,74,192,184,103,207,
200,135,243,243,11,29,213,90,181,19,17,221,180,101,163,231,92,177,186,35,17,1,153,129,52,167,40,114,153,36,127,154,253,243,3,51,136,16,62,38,155,71,150,157,95,9,52,9,98,93,66,140,251,116,172,122,242,97,
248,139,146,192,57,25,228,14,189,107,4,232,201,117,8,26,61,224,123,215,111,15,48,207,48,51,195,174,93,12,39,78,158,132,7,31,120,224,166,16,242,86,2,22,181,122,99,176,88,216,232,108,58,142,213,127,215,
135,115,158,115,149,144,174,227,40,241,174,132,169,200,9,176,162,228,69,7,206,147,20,236,106,184,73,100,70,81,131,185,91,132,104,144,160,225,99,14,89,66,40,30,197,208,30,216,210,149,205,136,163,159,121,
240,240,220,158,189,107,139,39,143,209,236,236,44,35,162,96,96,120,238,185,231,224,161,135,30,186,225,133,188,229,14,174,86,42,61,229,114,37,135,128,52,114,247,125,35,65,248,34,153,88,85,13,198,178,127,
73,185,32,253,230,98,92,15,115,130,71,206,173,114,76,44,209,119,84,91,47,35,224,73,72,120,235,216,14,192,64,132,174,108,86,236,221,127,160,15,224,49,152,63,113,28,167,166,166,60,155,220,63,8,207,60,243,
44,60,242,200,195,55,180,144,183,222,193,181,90,87,173,86,203,2,128,155,78,217,166,167,198,52,244,15,227,30,114,164,113,89,75,3,108,29,24,37,111,49,73,68,33,230,172,66,212,16,36,42,195,15,103,201,67,64,
95,237,171,86,59,60,203,7,207,81,67,82,61,196,43,35,246,238,27,237,163,7,30,197,249,103,199,196,212,212,20,186,77,135,118,13,13,193,211,79,63,13,143,62,250,232,13,43,228,45,119,48,19,229,26,141,70,26,
0,192,52,204,72,21,203,209,139,180,141,153,34,15,58,206,195,194,54,238,3,182,112,145,72,250,80,93,77,163,30,16,43,216,38,199,28,60,86,246,184,135,145,120,201,144,96,145,50,7,56,183,119,29,221,185,156,
216,187,255,64,111,233,160,103,147,103,121,142,25,0,118,237,218,5,199,143,31,135,199,30,123,236,134,20,178,216,234,110,19,115,218,113,28,155,153,193,52,5,178,127,239,2,254,155,242,175,254,123,112,159,
57,184,231,28,123,12,180,243,216,127,19,14,127,151,223,88,146,157,242,19,157,199,156,96,2,194,215,104,23,38,61,198,228,11,52,248,92,210,18,33,204,208,149,201,136,163,159,121,232,240,158,7,62,183,183,84,
42,245,205,205,205,221,190,184,184,120,127,177,88,122,240,216,177,177,195,112,99,84,107,94,229,14,6,182,29,199,49,153,25,13,20,26,91,35,80,109,155,152,179,240,30,73,89,31,109,227,233,155,107,51,16,12,
53,239,58,12,110,88,214,28,106,216,22,224,217,155,219,224,205,252,136,0,9,245,178,80,48,58,218,199,240,40,204,159,56,14,76,115,30,172,74,131,240,212,175,158,130,207,127,225,243,55,212,78,222,50,14,38,
151,208,175,244,67,3,49,90,217,114,92,194,45,180,172,238,221,48,183,190,145,45,127,199,56,44,145,136,140,114,236,92,53,199,37,197,235,160,57,15,242,107,16,84,183,61,225,195,186,178,25,177,103,255,129,
62,224,71,97,254,196,49,200,207,229,1,1,5,121,176,46,124,241,139,95,188,97,132,188,181,128,153,145,152,4,2,2,10,137,1,201,16,243,89,85,161,232,126,82,107,207,181,21,96,193,146,159,158,4,96,200,200,25,
114,12,83,75,64,170,56,17,204,14,227,107,14,20,13,43,57,106,212,48,119,68,132,78,95,200,196,159,133,249,19,99,98,102,102,6,153,25,184,191,31,126,249,203,95,194,151,190,244,165,27,66,200,91,10,152,93,2,
38,63,56,98,142,237,143,100,199,169,197,234,15,153,24,242,29,149,34,37,137,141,193,10,51,131,91,127,130,206,227,218,196,101,83,92,55,221,140,200,169,77,41,206,15,235,162,52,108,91,32,120,66,30,29,237,
99,250,44,230,79,60,37,166,167,103,208,117,29,26,24,216,5,255,250,139,127,133,47,255,250,151,223,119,33,111,189,131,33,114,92,146,178,131,58,71,25,53,223,85,22,9,178,166,60,117,60,155,253,247,211,225,
171,86,136,39,39,252,173,135,219,184,137,137,229,36,191,129,213,28,71,194,137,65,88,229,33,94,89,193,7,15,244,22,230,14,175,20,47,190,51,48,55,199,190,159,56,0,255,252,47,255,2,191,249,27,191,241,190,
10,121,235,29,76,228,127,209,0,98,84,195,146,80,133,73,145,10,179,100,202,180,123,206,82,212,195,152,140,63,171,249,5,41,158,101,85,14,42,68,233,67,26,250,155,198,128,150,22,158,96,11,100,43,153,2,140,
202,2,232,202,100,196,157,15,60,114,120,110,239,254,181,249,231,198,40,63,151,103,0,16,253,125,12,255,244,79,255,4,95,249,202,87,222,55,33,111,45,96,63,244,8,210,127,145,179,26,109,27,213,241,65,45,179,
180,73,12,156,228,64,169,123,30,228,98,37,86,30,103,237,189,41,97,183,201,175,167,184,128,144,226,104,27,202,190,118,139,40,65,87,249,8,158,227,53,58,218,199,240,89,200,63,251,20,210,44,33,51,67,63,247,
193,207,127,254,115,248,234,87,191,250,190,8,185,13,1,147,191,115,33,44,208,78,78,7,37,137,9,91,159,27,214,250,6,217,134,4,207,182,133,103,28,255,188,86,46,90,64,19,10,42,19,189,223,65,198,156,145,37,
250,143,12,162,7,215,69,218,2,104,241,117,252,157,188,119,255,129,62,126,240,115,56,247,236,175,196,236,204,12,186,174,75,3,204,240,196,207,126,6,95,255,218,215,222,115,33,111,109,131,67,7,75,221,11,122,
134,70,207,229,226,166,16,164,135,120,161,12,113,38,197,64,220,206,34,218,34,206,98,201,39,136,217,84,14,205,15,114,2,80,198,172,125,15,153,82,20,84,73,177,20,39,3,116,231,50,130,14,28,232,45,204,30,89,
41,92,120,103,96,46,159,103,102,134,1,38,248,233,79,127,10,223,248,198,55,222,83,33,183,145,240,151,208,33,226,48,222,84,80,65,136,103,31,184,141,196,252,150,37,165,91,34,155,173,252,230,152,211,219,98,
97,72,192,11,114,18,153,219,15,149,162,26,100,217,175,160,0,76,65,21,76,237,202,164,197,157,15,122,54,57,255,220,83,110,62,159,191,157,136,96,96,128,225,31,254,241,31,225,183,190,249,205,247,76,200,237,
237,96,73,117,177,196,216,80,162,30,205,1,106,25,49,97,155,143,201,206,90,203,236,125,18,123,139,227,156,247,132,130,242,88,91,173,88,41,35,41,40,28,163,10,137,203,150,35,86,169,227,199,201,123,71,71,
251,24,62,7,249,103,199,96,126,97,1,188,157,204,240,248,227,143,195,183,190,245,173,247,68,200,109,120,209,145,128,73,78,207,113,240,93,49,6,233,71,177,166,166,194,36,161,201,55,5,131,146,20,70,73,64,
168,124,38,66,251,183,163,69,202,88,225,90,39,235,131,77,202,230,88,123,158,19,138,226,84,211,15,29,153,140,216,187,127,180,15,30,250,44,228,159,125,10,230,153,0,17,69,111,95,31,252,223,199,31,135,223,
121,15,132,220,6,146,69,209,14,150,120,175,42,200,17,223,138,50,10,21,232,49,102,61,113,24,252,77,138,211,197,9,88,39,43,119,21,85,112,186,85,229,26,162,246,57,237,47,140,104,137,161,134,143,197,61,120,
214,155,200,248,127,7,96,200,200,254,209,62,126,232,115,48,247,204,83,98,150,230,60,196,139,8,254,254,239,255,30,190,253,237,111,95,87,33,139,45,119,67,152,161,97,240,67,226,208,155,14,67,40,95,238,4,
73,143,203,143,65,24,114,49,36,60,206,97,48,166,60,31,149,196,248,78,173,116,77,114,74,43,124,60,192,199,137,61,13,20,100,138,252,191,33,200,22,17,171,25,43,249,111,255,119,98,2,8,22,57,51,120,55,193,
127,61,115,112,65,82,54,139,148,204,22,130,23,66,141,140,30,232,27,121,232,115,251,74,197,226,174,185,217,217,219,87,150,151,239,47,151,74,15,254,159,191,251,187,235,154,133,106,219,139,102,66,45,23,140,
137,30,43,39,225,211,172,25,218,182,82,73,210,206,227,214,139,47,233,222,48,199,129,175,86,106,27,88,211,63,26,144,166,233,33,216,50,74,84,224,119,239,110,32,34,244,100,179,2,70,15,246,22,230,142,172,
20,38,223,30,200,207,47,48,160,87,240,246,183,63,249,91,248,189,127,247,123,215,101,39,111,189,131,193,223,5,76,210,239,254,223,254,202,102,105,197,178,183,93,162,85,31,58,103,20,61,47,189,62,218,5,50,
98,38,253,205,9,73,224,246,146,207,17,250,22,124,14,112,235,127,35,157,33,153,10,9,224,137,253,7,45,254,150,244,13,98,152,218,100,0,232,204,166,197,93,15,62,122,120,207,67,95,184,173,92,42,13,228,231,
242,135,86,87,215,62,86,174,148,31,252,201,79,126,114,93,118,114,91,80,101,98,18,125,11,199,70,142,37,147,224,202,4,63,54,220,78,17,238,196,210,174,98,168,54,92,168,59,14,52,93,23,154,76,64,46,131,75,
4,46,3,48,250,128,4,107,136,148,15,160,112,152,51,86,235,148,16,61,23,78,0,130,33,16,12,67,128,137,2,108,211,128,148,97,64,218,50,229,52,246,38,14,25,43,238,38,42,244,32,10,227,228,142,76,70,236,61,120,
160,151,225,11,48,251,204,47,197,92,126,14,93,114,169,175,175,15,254,250,111,254,26,126,255,59,191,191,173,59,185,77,168,210,191,73,44,185,136,128,201,184,174,22,238,176,156,13,146,96,63,110,17,203,186,
196,80,174,55,160,218,108,66,221,37,112,92,55,76,65,131,70,248,139,199,179,20,58,109,200,122,22,130,35,128,6,124,238,24,249,59,14,17,144,1,154,46,0,56,126,156,143,81,87,32,96,175,21,132,101,26,96,27,2,
50,150,13,185,148,5,6,138,205,161,150,132,74,72,12,136,124,7,70,123,11,179,71,87,54,38,223,26,88,88,88,96,38,2,134,1,248,223,127,245,87,240,239,191,251,221,109,19,114,59,249,96,197,137,73,52,98,177,0,
54,142,24,134,113,142,70,195,44,214,235,80,174,53,188,157,73,20,143,129,53,232,90,47,9,86,50,83,8,137,24,181,110,114,60,170,174,238,59,232,190,128,202,229,114,129,192,109,50,212,26,12,133,90,3,160,224,
189,143,37,12,72,89,38,116,216,54,116,166,236,100,252,5,89,1,78,0,0,58,51,25,113,231,131,143,30,158,219,187,127,109,238,217,95,185,139,139,139,183,19,51,244,247,247,193,95,254,229,143,225,15,254,224,15,
183,69,200,91,35,89,76,154,133,217,2,26,220,2,61,44,213,26,80,168,53,160,222,116,192,145,104,242,114,86,40,12,171,180,218,97,150,176,255,96,45,96,152,63,150,4,165,101,184,212,208,11,165,42,67,13,159,196,
86,223,139,253,188,48,73,171,207,43,76,111,146,3,13,199,133,82,181,6,139,128,32,16,32,109,89,208,153,182,161,43,157,242,125,0,127,161,33,134,249,13,1,12,157,217,180,216,123,224,64,31,195,23,96,238,153,
39,145,22,23,1,0,184,175,175,143,126,248,163,31,210,247,254,195,247,222,117,71,190,171,66,178,162,120,120,171,30,55,82,70,134,25,86,203,85,40,215,27,208,112,221,24,202,24,239,133,229,99,212,164,89,184,
32,78,102,148,80,36,41,55,27,176,47,36,111,158,137,164,106,9,150,98,115,53,154,13,249,212,172,178,45,147,162,104,133,215,229,35,92,44,129,32,46,3,56,245,6,148,26,13,88,216,40,130,109,24,144,77,217,48,
144,203,130,30,99,120,96,72,218,67,188,30,254,60,204,61,243,43,94,92,188,76,204,228,12,12,14,54,127,248,195,31,54,191,247,189,239,205,188,27,33,183,157,46,84,53,115,68,163,145,191,118,208,127,131,128,
97,165,88,134,82,163,14,142,203,137,185,87,137,186,28,79,179,38,81,48,40,1,2,147,226,153,112,7,107,181,192,65,59,136,68,62,126,152,184,247,90,55,132,96,11,234,22,159,101,60,45,202,121,203,181,206,160,
153,7,255,3,235,142,11,117,167,10,87,202,85,48,133,128,142,148,13,3,29,217,144,63,142,128,208,153,201,136,61,163,7,250,248,193,207,114,254,196,24,175,44,99,147,9,138,131,187,6,42,255,235,7,63,168,254,
199,63,250,163,165,107,21,176,177,197,243,214,35,15,63,242,197,213,181,213,125,0,0,135,63,241,153,161,196,124,168,255,251,90,165,10,11,133,18,44,23,203,80,109,54,193,37,142,209,122,24,188,132,5,50,107,
55,158,19,249,123,81,222,254,106,22,177,164,179,97,171,60,127,130,233,225,120,255,61,80,191,129,18,17,168,192,12,104,208,109,116,46,49,67,181,217,132,181,114,21,10,181,58,48,19,164,45,19,0,16,44,195,192,
84,71,103,166,153,202,24,87,166,46,52,80,160,133,136,149,116,58,93,252,212,167,62,117,249,248,241,227,244,222,64,149,218,209,112,92,88,42,150,161,210,104,68,157,95,33,216,157,24,121,175,18,26,21,96,212,
154,149,13,157,37,10,59,245,68,116,216,255,242,235,159,221,118,148,231,153,119,46,194,179,239,76,105,201,254,214,32,74,100,133,227,206,155,14,236,132,226,69,144,190,87,20,72,213,29,7,150,139,14,44,21,
43,144,179,45,24,232,200,66,198,182,112,207,237,71,7,106,133,141,70,97,242,173,186,97,24,7,108,59,181,210,217,217,185,240,103,127,246,103,243,127,250,167,127,234,92,103,21,29,221,128,141,106,29,214,74,
21,207,174,34,132,78,75,200,171,32,140,24,19,137,246,43,137,223,172,53,35,100,117,87,108,251,193,17,15,36,72,160,48,39,228,179,81,69,180,116,149,29,251,22,9,69,20,220,50,251,133,80,170,215,161,84,175,
131,109,24,152,181,76,99,215,161,35,125,111,191,249,234,229,98,169,120,32,155,205,22,251,250,250,54,94,127,253,245,197,235,130,100,17,81,136,8,49,3,172,20,43,48,113,121,5,22,214,139,80,119,92,239,113,
242,0,17,34,138,176,101,32,9,245,138,160,91,98,207,222,145,175,178,162,231,200,135,135,165,199,136,195,215,93,39,249,6,31,20,225,212,50,10,22,126,111,31,93,35,214,144,59,31,205,35,249,60,253,117,254,38,
33,21,183,103,169,122,35,248,169,59,46,172,150,171,88,6,35,211,243,225,143,239,169,54,156,221,87,174,172,221,94,173,86,239,125,248,225,135,62,113,45,72,87,27,59,24,66,130,220,196,226,50,184,204,201,213,
122,74,190,52,129,149,161,59,216,172,162,60,44,151,143,202,97,82,11,188,153,152,161,225,56,239,74,192,77,215,129,176,152,78,97,149,168,201,40,166,40,121,169,112,180,120,51,219,14,106,103,2,8,34,165,205,
58,121,250,215,32,132,72,141,220,54,232,188,254,202,242,250,250,198,136,97,152,43,0,176,255,191,255,197,95,76,254,231,63,249,147,133,109,22,48,249,25,21,128,38,75,33,6,123,76,7,249,226,53,176,42,6,226,
199,115,186,241,54,133,106,66,30,160,213,188,171,229,98,25,190,127,252,84,2,91,160,5,163,64,162,84,69,97,15,74,166,32,94,212,66,28,47,147,85,232,61,24,248,13,24,179,191,168,0,61,82,108,79,73,223,81,34,
34,32,131,33,4,178,157,178,6,30,254,226,225,229,167,126,126,190,82,169,236,41,22,138,251,140,190,158,67,0,176,120,53,97,83,219,233,194,32,135,201,228,77,64,33,41,29,71,228,217,94,2,239,28,10,166,164,4,
207,115,144,122,83,255,13,210,113,158,17,160,144,131,237,181,61,212,146,25,91,93,27,147,111,175,73,74,134,200,41,74,210,174,1,148,223,245,235,75,250,61,80,205,161,153,33,138,18,49,28,124,119,233,243,195,
239,239,127,118,96,194,164,215,4,38,41,60,143,60,179,8,204,96,166,51,169,204,145,123,7,43,149,74,111,181,94,59,232,52,155,135,254,252,207,255,124,247,182,219,96,208,111,100,120,113,129,112,34,225,123,
23,75,17,213,150,229,231,252,47,68,210,2,0,207,224,134,143,135,139,137,195,133,66,156,76,178,35,86,111,84,112,3,73,185,113,164,9,189,213,239,242,99,20,101,207,20,193,146,34,108,214,22,1,73,137,145,200,
199,240,207,129,232,95,146,94,3,210,226,99,233,51,0,0,132,33,68,102,239,190,254,102,179,153,46,22,10,253,27,235,133,129,74,165,210,255,91,191,245,77,177,109,42,26,228,248,78,198,108,37,216,46,34,218,144,
214,143,61,162,225,200,180,23,47,76,141,252,81,230,40,191,140,192,190,106,68,233,243,54,209,46,16,107,214,35,161,145,114,39,91,21,149,82,7,12,112,204,211,87,42,45,98,209,112,66,162,5,1,144,56,106,190,
22,168,252,64,59,7,38,77,163,164,202,183,71,105,5,201,0,2,5,218,153,92,38,123,199,189,187,106,23,222,42,214,234,245,145,206,174,206,3,7,15,30,122,7,0,234,219,19,7,187,65,142,23,165,157,68,16,15,38,226,
4,117,25,48,136,72,60,172,84,164,160,14,12,36,101,213,91,177,100,153,162,133,130,26,125,151,163,198,46,201,101,169,17,208,162,188,182,69,216,166,186,65,164,117,8,75,40,8,0,21,90,139,184,105,42,54,29,65,
178,152,80,84,73,0,2,208,234,233,207,86,137,115,213,106,165,191,90,173,14,164,211,233,110,0,88,218,30,39,11,34,38,101,32,232,152,199,20,182,246,37,53,45,40,57,98,106,79,30,12,61,82,198,22,172,140,54,66,
28,162,104,1,177,82,34,8,161,150,64,185,69,177,124,207,9,227,45,140,245,132,82,152,204,224,24,215,75,209,82,202,194,214,71,199,180,202,126,115,2,179,69,139,62,16,1,17,49,213,211,219,197,118,42,213,104,
52,250,171,213,234,96,111,111,223,30,0,88,110,199,217,218,218,6,75,142,78,232,104,73,49,108,96,71,227,113,32,73,156,43,82,227,66,146,98,229,4,155,22,115,158,90,58,89,164,58,65,129,19,232,219,110,96,10,
109,56,17,68,54,158,124,187,7,20,57,88,242,115,36,217,240,208,102,6,137,23,8,29,38,239,222,248,247,130,228,184,54,112,246,244,199,64,123,78,183,251,218,121,62,9,14,77,211,176,135,70,58,234,141,70,174,
86,171,245,54,155,141,254,63,254,227,63,182,182,137,209,17,71,178,2,155,22,54,51,100,208,232,177,113,104,51,92,223,24,47,44,107,29,68,202,189,177,18,116,11,243,166,187,158,181,226,115,150,51,88,97,53,
130,142,33,43,116,248,16,31,71,41,105,26,94,57,65,216,248,197,235,83,174,214,86,34,234,67,132,90,149,225,96,156,247,169,84,137,160,72,239,222,219,191,126,241,237,203,142,227,12,52,155,205,93,182,109,167,
1,160,177,173,80,37,113,20,232,203,230,4,101,21,201,172,20,8,68,41,163,136,251,44,23,119,135,53,184,200,32,23,132,196,201,117,9,9,8,86,73,64,33,11,131,181,218,81,221,8,99,130,150,140,13,220,130,132,54,
20,113,243,202,114,5,164,223,135,58,34,123,74,41,179,144,37,34,19,20,212,248,63,6,103,6,197,237,200,96,100,178,54,216,233,116,189,94,207,54,26,141,236,198,250,186,216,158,29,236,171,13,68,159,126,170,
211,16,73,99,47,203,220,231,120,94,205,235,134,23,171,232,100,197,185,218,108,2,139,98,131,153,180,221,134,97,106,3,148,4,135,146,232,211,106,109,160,189,86,18,16,37,249,149,100,21,170,244,147,216,90,
36,142,82,147,74,29,27,39,55,60,79,130,18,25,209,176,109,219,232,232,74,185,229,141,76,163,209,204,14,14,13,117,3,192,198,86,118,184,173,108,146,28,7,163,228,83,121,206,180,52,127,129,80,203,197,170,69,
101,33,255,41,248,210,228,113,148,72,242,114,80,163,118,81,107,29,29,150,210,68,242,82,169,232,172,17,228,66,101,233,167,43,149,54,105,200,145,83,214,130,208,16,154,22,105,39,43,212,34,189,161,1,39,239,
124,181,187,95,156,85,28,251,100,111,49,32,3,179,235,186,169,102,179,145,181,76,179,99,251,108,48,168,164,117,153,171,140,50,120,27,171,165,229,88,103,223,64,184,161,67,238,87,25,202,172,136,168,29,177,
90,250,18,95,124,50,237,137,195,182,196,32,219,77,249,111,169,30,216,131,90,89,26,110,201,114,208,147,192,230,64,159,190,4,16,181,121,64,165,53,53,106,6,84,137,248,228,154,54,226,48,206,87,216,45,28,47,
212,144,249,122,214,224,112,87,243,202,170,233,56,142,229,184,14,110,147,138,246,178,68,1,192,143,45,147,95,122,204,218,194,110,106,33,110,244,5,228,118,194,172,129,28,241,247,218,221,211,5,255,227,59,
223,188,230,68,195,127,250,235,127,240,111,40,133,161,156,66,213,77,116,247,32,129,96,212,74,163,115,114,232,199,82,98,5,37,161,66,252,214,233,221,12,68,54,151,38,38,116,93,50,153,41,5,109,212,95,182,
197,201,2,185,252,68,242,34,163,16,24,99,137,147,216,87,195,104,38,82,162,58,226,77,168,34,215,35,85,24,192,143,129,190,212,169,190,140,170,159,165,51,54,89,66,194,16,91,80,210,226,90,141,19,22,58,199,
128,148,232,66,66,174,8,51,122,209,20,35,49,25,136,98,155,194,36,142,218,236,202,61,245,41,134,42,169,180,26,111,145,162,196,22,213,86,61,171,156,42,100,140,193,136,81,15,144,237,151,50,177,74,70,136,
252,9,144,102,53,73,51,83,89,70,37,57,50,17,200,209,194,149,204,4,106,133,231,8,241,230,168,154,117,143,105,71,212,123,147,88,166,65,76,64,174,43,92,215,221,62,21,13,190,189,34,130,228,206,235,50,97,77,
171,6,140,203,38,142,13,171,141,204,124,0,68,234,52,203,137,2,98,168,55,155,239,110,7,39,196,189,186,57,137,85,48,232,93,2,56,65,89,107,24,186,140,207,83,146,141,14,233,64,49,127,63,114,38,129,1,133,97,
6,128,206,54,10,56,162,166,114,108,42,134,142,235,113,66,130,95,230,58,161,242,21,213,29,195,106,161,245,22,128,229,226,122,1,254,235,79,127,161,222,64,148,189,113,12,161,82,148,218,55,68,231,74,107,117,
51,15,118,179,98,245,205,185,34,177,197,14,177,189,201,122,170,31,228,150,234,222,53,98,152,165,34,114,137,67,95,168,61,22,98,27,54,152,36,44,90,198,100,35,87,24,101,102,162,34,112,255,57,210,208,90,137,
212,142,160,17,220,164,44,68,235,54,70,170,118,80,63,155,64,110,102,134,172,222,202,48,96,98,47,60,195,16,240,71,37,22,199,192,183,8,59,233,169,241,155,236,28,201,235,92,173,234,105,229,36,38,85,34,199,
233,124,193,53,134,206,110,189,214,244,160,98,102,70,216,30,1,203,29,92,131,112,9,53,255,159,53,213,132,82,204,71,10,215,82,71,166,164,180,93,196,139,145,108,58,110,234,103,121,236,8,86,26,142,234,139,
34,113,166,67,208,49,72,114,43,80,47,54,15,195,25,159,68,47,79,110,225,128,5,46,47,16,239,89,66,86,71,40,178,6,95,130,182,40,194,119,82,197,173,248,52,94,136,202,110,179,233,50,51,9,20,14,185,114,21,193,
187,244,162,35,168,82,203,9,177,218,83,42,108,6,78,186,215,201,42,209,29,101,144,153,162,105,162,177,193,146,148,16,180,200,139,137,188,172,144,92,233,128,113,119,54,234,118,27,57,126,73,182,146,21,83,
35,185,60,28,111,218,200,18,233,32,82,247,106,55,34,93,189,203,185,167,200,116,105,133,121,178,141,15,97,97,63,1,210,104,16,34,186,0,208,36,162,106,59,49,198,213,181,50,36,86,84,72,172,204,139,213,57,
129,74,91,74,63,189,23,188,1,66,156,168,21,138,131,160,5,60,164,57,238,190,74,198,24,166,204,201,233,186,176,23,136,234,94,197,218,164,41,116,218,100,203,170,87,49,36,177,193,244,197,17,139,171,89,65,
128,162,161,155,178,170,224,192,49,37,174,46,204,108,32,51,35,98,29,1,27,219,178,131,229,116,157,140,100,197,191,58,170,227,232,90,117,161,145,32,93,185,97,9,131,230,249,144,234,203,181,210,46,161,14,
208,136,108,50,103,35,217,22,234,189,54,212,110,210,241,6,106,209,75,8,227,141,172,17,61,247,40,106,78,163,66,145,74,2,6,84,222,93,56,195,81,50,3,186,240,137,28,106,172,44,85,50,182,93,23,66,212,13,203,
216,30,70,71,0,85,34,35,16,81,52,214,70,115,41,89,217,118,12,9,83,174,18,65,158,40,61,238,121,188,73,21,39,216,114,164,10,133,165,164,204,90,25,169,204,218,136,53,21,120,54,138,69,0,0,24,187,73,68,65,
84,151,73,249,168,209,91,35,226,126,52,194,39,154,249,144,216,176,77,71,227,146,180,24,171,90,130,35,160,61,130,125,81,66,124,57,194,161,129,128,157,106,189,129,166,109,32,66,201,52,205,210,234,202,234,
250,246,168,104,191,89,9,197,242,163,73,94,34,111,154,243,84,158,71,140,87,23,50,111,26,116,36,94,27,168,213,8,36,3,3,45,145,83,181,92,52,244,128,195,48,205,215,11,28,143,145,57,230,253,182,55,146,75,
29,57,132,225,2,84,252,24,78,94,24,204,12,141,210,70,149,106,149,170,232,236,44,10,33,54,10,133,66,109,251,176,232,160,103,133,52,164,130,147,170,250,99,130,150,77,10,73,126,4,135,171,87,6,75,16,227,69,
154,155,134,154,204,155,118,174,84,199,49,73,189,168,65,27,22,46,171,81,138,34,1,214,113,28,197,203,197,112,50,121,196,203,138,122,95,6,206,158,218,73,34,62,14,129,91,118,141,147,182,16,185,84,91,156,
47,8,20,117,33,196,58,3,175,118,116,228,120,155,4,204,106,159,71,150,186,206,162,202,2,84,71,233,72,37,215,236,249,15,168,87,210,163,234,80,113,139,246,55,136,173,242,193,156,16,73,182,22,184,215,218,
65,181,179,76,42,214,66,114,154,18,90,12,19,215,0,101,148,119,168,226,43,113,60,193,130,50,43,68,47,163,96,72,170,90,118,155,205,102,121,242,252,106,54,155,45,217,182,189,10,128,203,143,63,254,255,154,
219,39,224,48,165,39,215,218,74,106,76,98,131,146,100,7,9,162,170,225,196,182,15,44,155,191,56,104,136,173,19,51,177,5,193,45,186,72,36,229,127,228,146,148,216,52,53,45,42,13,227,96,109,54,35,74,105,69,
14,18,41,44,33,233,1,241,65,242,134,245,121,198,172,120,247,148,48,204,196,219,17,213,229,203,235,0,224,24,134,177,98,154,230,10,19,45,181,155,134,105,115,7,7,80,153,146,128,85,86,191,226,123,176,214,
43,10,227,62,23,75,197,215,172,67,154,202,12,203,214,249,96,230,86,157,105,147,234,135,52,91,151,212,174,18,227,30,32,107,70,62,160,232,48,170,189,44,101,142,154,204,215,86,199,21,123,244,27,111,229,171,
140,1,57,161,133,82,97,148,23,30,229,75,134,97,148,77,211,92,50,77,115,225,7,63,248,193,106,187,152,123,91,80,37,72,64,7,38,153,139,164,62,223,20,5,193,44,21,123,163,204,65,98,181,229,16,250,171,28,57,
18,58,98,43,184,146,37,202,14,198,91,26,73,245,70,73,142,18,182,211,165,152,19,209,68,85,151,107,137,121,214,38,159,203,170,95,173,77,210,138,1,66,7,81,33,57,112,253,202,218,70,117,122,114,61,155,201,
92,49,77,115,193,117,156,75,87,147,68,189,42,210,157,204,104,144,51,61,177,188,66,139,88,129,65,154,104,162,117,149,141,186,228,145,210,130,136,91,51,104,164,157,162,130,246,114,255,119,57,12,147,255,
79,146,240,53,60,78,77,89,202,142,86,216,161,39,26,31,192,154,115,28,27,168,41,63,71,12,160,123,247,82,149,71,224,39,68,26,134,220,202,252,108,193,48,68,41,157,201,44,167,211,169,101,64,88,217,86,1,19,
145,210,163,131,181,220,135,174,5,183,26,86,201,73,179,148,88,171,225,211,160,68,228,100,98,124,208,10,137,53,16,151,229,222,29,50,139,66,25,9,196,81,225,159,178,68,2,244,156,226,45,12,65,107,231,40,45,
157,208,28,197,27,129,169,26,3,147,194,104,142,205,224,68,96,118,138,197,106,233,237,55,150,51,217,236,138,105,152,23,0,112,252,71,63,250,241,250,213,164,69,175,170,33,56,109,53,206,85,11,79,228,108,42,
38,125,89,141,40,128,73,97,234,102,201,6,110,53,3,2,37,53,170,193,73,74,231,91,57,220,73,200,84,33,180,28,35,36,215,104,233,237,143,177,5,27,154,165,21,174,164,210,181,155,138,8,76,141,102,99,233,185,
95,93,48,13,163,148,78,165,230,237,148,157,39,162,171,42,29,109,111,7,187,113,226,187,174,238,88,83,119,73,203,32,30,159,70,101,45,168,181,57,8,207,67,208,218,27,37,59,128,168,181,34,70,25,231,212,48,
106,150,106,163,48,105,155,177,158,164,87,161,97,181,173,3,43,109,23,213,243,40,132,57,149,169,172,177,157,175,222,63,68,100,34,166,226,212,228,34,52,27,149,76,71,199,66,58,147,190,100,89,214,197,31,253,
232,71,87,221,109,167,205,218,164,40,39,41,187,247,114,250,62,106,162,164,15,204,82,209,30,101,243,38,176,42,88,123,25,111,194,243,162,192,67,103,121,150,130,22,192,106,54,159,81,21,137,204,77,150,152,
236,170,71,29,16,243,253,30,93,40,89,19,214,8,245,177,122,71,134,196,42,201,120,251,153,200,2,52,139,133,114,105,98,124,57,157,74,93,182,83,169,243,182,105,157,159,158,158,58,7,215,192,80,107,179,157,
176,148,23,150,203,50,229,125,23,184,251,178,10,211,49,95,224,216,192,119,84,138,183,34,158,2,133,99,94,189,103,191,245,223,254,167,52,143,73,74,231,109,210,149,63,17,253,208,209,47,100,117,134,147,12,
115,233,180,198,192,86,234,153,3,72,10,201,146,16,189,77,96,204,96,247,54,27,205,43,47,159,186,100,184,238,170,149,74,93,180,109,251,66,211,113,222,56,118,236,248,53,241,147,218,178,193,97,51,207,32,76,
34,93,85,41,70,38,217,195,146,102,1,234,97,68,216,66,1,73,105,57,232,1,44,1,243,145,213,248,25,212,204,150,82,91,43,121,51,138,14,193,120,242,130,165,89,149,138,208,56,230,80,196,139,135,65,102,159,96,
124,247,42,117,212,114,124,238,67,64,82,165,162,64,4,114,29,103,245,204,169,11,110,97,125,35,155,205,206,102,50,153,11,150,101,189,83,42,149,46,195,53,30,109,121,209,1,47,58,72,58,32,36,44,110,72,42,181,
84,211,119,1,213,52,98,138,200,12,7,150,22,78,148,52,14,211,104,168,150,173,178,212,61,67,178,186,49,15,141,19,76,108,203,82,55,45,73,17,126,79,242,141,80,232,184,105,111,68,146,177,194,0,241,74,112,222,
56,41,201,225,107,42,151,221,213,151,79,77,54,46,231,11,233,108,102,62,147,201,78,164,211,233,201,98,161,240,230,19,63,251,153,115,221,4,44,99,209,164,217,76,82,20,47,68,112,155,130,215,106,62,38,163,
106,223,37,90,42,202,195,168,20,150,131,218,169,70,135,136,88,107,77,203,1,14,41,49,34,244,104,57,214,153,30,81,83,56,106,21,126,0,211,202,174,53,75,48,35,130,206,217,82,137,126,138,117,86,250,85,35,0,
179,179,250,210,201,137,218,194,92,33,157,78,231,115,217,220,59,217,76,250,237,82,169,244,226,19,63,251,89,13,222,197,209,230,236,66,14,203,61,100,54,73,44,190,132,36,174,58,171,184,171,196,68,10,43,12,
21,90,75,148,16,69,142,170,17,131,197,129,114,173,72,171,2,50,249,65,138,119,177,219,60,80,77,168,91,216,164,153,25,104,190,48,39,88,47,210,236,117,32,106,225,11,119,229,204,169,137,218,194,108,49,155,
201,204,119,116,116,156,207,102,50,175,85,170,213,167,159,120,226,137,34,188,203,163,173,126,209,97,35,112,162,176,214,39,240,156,213,205,35,3,245,234,222,142,149,121,72,47,84,76,159,52,15,152,148,90,
77,53,246,229,4,55,59,198,132,148,138,145,61,123,174,183,108,66,173,84,6,1,147,155,230,110,113,96,204,47,86,98,137,4,71,80,120,79,56,43,103,78,78,212,23,230,138,233,116,58,159,205,102,199,51,153,204,185,
66,177,56,246,139,95,252,226,93,11,247,42,40,59,18,139,70,222,197,192,137,147,197,228,118,127,73,177,50,104,121,86,210,38,143,70,239,25,213,205,6,32,188,18,112,105,47,146,67,186,144,35,38,85,65,6,216,
117,148,241,161,80,168,65,150,137,64,245,188,49,169,223,185,54,215,15,147,224,58,108,61,202,71,120,210,117,86,78,159,154,168,47,204,22,211,233,116,62,215,145,27,207,102,178,103,11,133,194,216,47,127,249,
203,2,108,83,209,206,85,246,139,166,120,247,126,5,155,196,22,74,76,22,117,50,125,135,19,180,167,218,237,70,229,164,177,76,222,147,234,92,244,174,180,204,42,100,196,172,9,9,165,138,73,146,242,177,168,213,
118,178,150,85,144,76,69,88,203,20,99,221,233,163,227,1,4,10,207,230,158,57,57,81,243,119,110,46,155,29,207,164,50,103,11,197,194,216,147,79,62,185,109,194,189,6,160,67,117,156,194,47,23,64,130,177,250,
71,104,65,103,137,193,27,144,84,62,192,138,67,3,90,159,164,132,240,18,24,146,186,32,176,36,24,133,236,198,26,167,39,212,224,222,238,14,59,15,16,107,67,139,181,118,197,177,251,18,167,244,1,35,8,20,128,
76,206,234,75,167,38,170,243,179,197,76,58,157,207,102,115,227,233,76,246,108,161,88,28,123,234,169,95,109,171,112,219,116,178,84,218,108,88,12,230,23,76,135,187,77,166,135,50,43,13,183,85,26,11,72,5,
88,220,18,217,217,188,92,81,13,86,113,179,4,127,66,249,188,156,240,208,71,43,176,54,102,54,92,114,74,131,33,214,27,20,248,182,159,66,187,207,154,187,236,219,127,103,249,204,201,137,218,252,76,49,157,9,
108,110,250,108,177,88,24,27,27,27,219,118,225,94,117,186,144,100,70,135,14,106,160,52,186,72,194,28,149,89,28,44,217,84,165,219,103,0,130,96,172,185,59,226,214,26,38,105,10,75,212,47,3,21,74,76,132,66,
161,130,168,73,12,138,68,96,42,242,197,80,154,167,172,34,102,136,1,111,13,67,240,6,129,189,157,11,236,172,158,62,57,81,11,108,110,54,55,158,78,167,207,22,139,197,177,99,199,142,93,23,225,94,67,186,144,
21,192,49,134,31,37,22,61,147,146,171,141,144,3,185,152,45,72,58,68,94,58,37,116,196,1,76,2,250,226,228,56,57,45,24,85,18,232,148,69,222,36,179,207,177,217,192,74,6,42,198,50,241,23,79,80,6,19,86,100,
16,8,33,0,128,221,149,211,39,39,235,11,179,197,116,42,149,207,164,51,231,83,169,212,185,82,169,52,118,252,248,241,235,38,220,171,178,193,177,218,55,95,77,99,66,57,37,74,136,142,14,123,5,117,195,114,16,
164,44,18,127,144,70,72,208,35,169,88,141,180,196,133,95,87,172,112,248,100,166,100,104,122,35,132,13,53,71,13,181,153,150,97,151,160,196,68,118,139,128,155,57,121,214,185,247,249,110,254,137,159,156,
101,6,200,244,244,44,103,123,7,23,236,70,229,220,202,202,234,177,190,190,158,234,245,20,110,219,94,116,240,165,137,56,134,200,112,44,23,11,177,222,20,154,175,161,198,181,161,48,36,226,25,171,252,105,102,
82,210,128,44,217,202,144,195,196,82,13,55,105,69,216,204,201,121,102,173,218,149,245,141,142,91,54,41,86,181,147,228,89,24,2,192,64,116,87,94,124,238,2,185,108,164,51,233,217,52,226,27,102,173,116,238,
202,250,250,24,17,85,201,189,254,51,162,219,170,46,164,112,48,22,169,30,174,226,234,112,75,160,168,37,128,20,10,131,163,14,61,168,165,215,100,252,89,225,49,199,129,227,192,137,103,173,3,78,192,247,10,
62,148,98,1,29,38,179,140,56,169,1,33,183,8,7,163,149,33,132,0,68,112,151,79,159,152,168,205,207,84,82,169,84,62,155,205,78,164,82,169,215,214,175,92,25,35,162,106,111,111,47,117,118,117,190,255,3,162,
229,30,29,164,79,35,145,199,155,203,249,0,76,162,112,39,248,189,49,58,102,228,145,202,94,183,210,251,148,100,20,75,113,212,163,178,15,138,23,154,7,221,103,3,71,143,194,89,75,24,3,104,212,126,156,234,240,
106,153,191,28,130,36,18,203,72,8,1,2,193,89,61,125,98,162,54,63,91,74,165,82,249,92,46,119,33,149,178,207,148,203,229,39,187,187,186,171,140,12,157,157,157,252,248,227,143,55,223,119,1,135,125,21,49,
154,239,27,166,200,24,85,45,204,45,192,139,88,118,135,55,65,1,163,118,69,58,12,170,186,181,106,107,58,181,229,3,183,220,142,129,19,135,210,92,134,176,234,16,80,205,6,132,45,43,228,9,108,242,76,114,10,
157,75,2,4,83,24,128,8,206,138,39,220,98,42,149,202,167,211,153,241,148,157,58,91,42,87,198,78,157,60,89,184,222,54,247,154,146,13,65,169,73,56,239,47,220,73,188,89,155,73,72,48,207,81,248,128,173,90,
21,33,104,57,125,72,158,27,158,212,160,37,121,26,121,168,2,164,226,165,68,159,73,167,195,66,92,195,168,243,36,34,19,97,24,8,8,225,206,45,218,182,157,79,167,211,227,233,180,125,182,88,46,142,189,240,252,
11,239,185,112,219,244,162,213,38,164,173,153,12,24,191,89,128,106,131,52,9,188,224,164,237,45,67,138,218,70,229,132,69,196,97,65,183,228,252,201,249,86,198,168,249,89,176,211,153,165,216,90,243,125,21,
88,82,251,110,202,233,42,5,196,16,2,4,162,179,114,230,57,127,231,218,249,116,38,51,158,74,165,206,150,75,149,177,23,94,124,127,132,123,77,113,48,104,13,54,85,104,82,207,219,170,55,15,89,230,115,37,147,
243,98,213,0,160,193,128,242,158,12,124,2,150,247,170,222,249,59,185,201,103,82,133,164,226,169,43,87,16,241,153,245,244,161,41,16,4,10,103,245,244,137,137,234,252,76,168,150,211,169,212,217,114,185,60,
118,250,244,233,247,77,184,215,134,100,105,113,31,182,218,213,10,138,4,106,241,26,70,104,144,54,81,50,108,172,38,87,252,69,129,136,220,106,16,99,10,153,18,124,226,36,198,13,73,139,33,244,178,53,104,50,
32,233,51,183,232,5,143,12,166,48,20,225,218,182,157,79,165,82,227,118,202,62,91,174,84,198,206,188,207,194,109,51,31,172,141,106,87,0,124,169,195,187,210,224,152,125,26,11,75,21,0,50,41,156,227,246,78,
219,182,49,118,164,210,114,88,227,24,163,63,231,1,81,203,91,169,211,24,228,196,3,203,147,215,90,214,62,169,79,202,253,166,13,97,128,64,112,87,79,159,152,12,133,155,78,159,183,108,235,92,185,84,30,123,
249,229,151,223,119,225,94,85,178,65,46,170,210,27,132,161,94,242,200,156,88,247,170,140,170,212,6,81,37,57,52,241,10,8,80,74,53,163,107,146,24,39,138,183,78,106,115,19,140,63,182,89,168,30,59,37,108,
197,136,96,32,186,115,255,248,183,103,1,0,210,93,93,203,153,190,129,5,163,92,60,183,177,190,113,172,171,171,171,122,35,8,183,77,21,29,37,6,136,88,185,89,177,202,19,208,58,162,75,241,103,146,123,45,115,
170,213,170,32,25,97,194,68,186,75,216,63,83,75,216,3,233,78,52,171,93,99,244,197,130,241,44,83,192,145,38,212,225,54,0,195,68,48,133,112,87,78,63,119,129,152,12,219,182,103,77,224,55,68,105,227,92,161,
88,28,99,230,42,17,193,141,114,180,19,7,123,83,22,40,216,156,172,134,162,24,135,0,85,21,10,26,34,165,67,123,106,151,15,208,200,176,36,179,166,3,85,143,106,147,239,168,89,152,190,68,130,137,219,81,104,
22,17,214,213,222,207,81,143,13,140,40,180,114,53,33,3,152,134,1,6,10,119,229,204,201,137,202,220,116,197,182,237,124,38,147,153,176,44,235,181,66,161,48,70,68,213,174,174,46,202,102,115,124,19,9,152,
189,121,78,192,2,125,218,75,75,232,17,182,130,39,229,226,173,56,0,152,52,171,87,181,125,82,241,152,111,119,99,25,29,121,245,201,11,18,131,98,53,181,199,51,72,19,110,188,68,23,41,68,131,224,243,76,211,
0,33,132,179,114,230,228,68,53,63,93,178,44,43,159,201,164,47,88,166,121,166,86,173,61,217,209,209,81,101,96,200,230,178,124,236,216,88,243,102,17,48,51,115,3,0,28,102,182,60,231,55,232,60,166,199,187,
106,6,2,1,149,17,9,155,53,89,217,236,144,59,230,115,82,216,42,157,164,148,177,250,35,222,163,215,197,103,3,35,75,228,63,31,2,141,72,9,209,249,134,97,130,33,208,89,61,253,220,68,117,126,182,104,153,86,
62,149,74,141,155,166,121,182,82,173,142,189,246,218,107,133,27,197,230,94,181,128,137,168,6,0,13,102,182,188,13,17,117,73,100,191,131,123,232,216,80,212,15,90,238,107,217,186,119,14,110,2,118,96,11,192,
5,19,27,151,201,144,181,138,60,197,103,2,199,224,210,176,135,136,52,159,194,247,31,76,195,0,83,160,179,118,250,196,68,37,31,132,66,246,184,109,219,103,171,149,218,216,235,111,188,126,195,10,183,221,29,
92,6,128,26,51,231,124,228,18,100,58,108,56,75,87,166,119,115,235,236,145,210,199,74,234,151,161,16,217,52,37,205,74,173,31,183,69,137,150,59,202,182,202,228,42,45,64,165,16,144,124,85,97,154,2,76,195,
139,115,43,249,153,162,101,89,121,203,182,198,45,203,58,91,173,86,199,222,120,227,141,27,90,184,237,8,152,0,160,136,136,85,102,54,192,117,29,102,54,64,114,106,228,83,57,33,67,234,9,22,85,119,59,76,170,
163,68,153,141,90,241,160,204,149,5,13,59,142,216,228,17,96,141,137,67,143,194,250,83,86,58,175,235,163,58,80,115,229,252,27,99,24,96,10,195,89,57,253,220,68,213,23,174,109,219,227,150,105,157,173,213,
170,99,111,190,57,126,195,11,23,0,192,216,202,4,238,218,181,235,136,235,186,251,29,199,25,70,196,170,232,237,239,141,71,182,172,162,77,138,205,67,181,27,14,168,56,51,178,138,57,203,127,179,4,134,197,90,
24,201,240,127,172,101,162,12,204,180,154,67,204,45,29,60,211,16,96,153,134,179,234,57,84,69,203,242,213,178,101,159,173,215,235,99,227,227,231,111,10,225,182,181,131,17,96,73,8,81,100,134,230,149,241,
87,221,145,163,247,112,163,209,64,153,163,20,155,192,23,96,196,177,174,53,113,8,65,161,180,134,121,90,185,159,7,74,2,228,112,215,235,197,215,156,228,81,203,109,248,213,116,51,36,246,113,11,119,174,112,
87,79,63,55,89,157,159,45,154,166,153,183,44,243,188,97,154,231,170,245,234,216,219,111,189,125,211,8,183,45,27,92,173,213,207,25,134,241,5,68,40,185,68,125,6,2,49,179,17,22,119,105,137,36,5,229,106,197,
101,141,97,215,114,207,70,169,50,158,226,97,19,75,180,14,78,200,83,170,92,115,86,128,144,16,186,100,169,224,91,198,172,17,193,52,76,119,246,167,127,115,22,0,32,213,217,181,156,233,237,93,128,141,141,115,
229,98,241,88,54,151,171,222,76,194,109,71,69,195,149,43,107,181,254,190,254,59,92,114,135,92,151,250,179,187,70,192,181,236,220,230,113,77,27,57,200,4,85,169,198,64,122,35,15,78,168,218,103,149,93,32,
53,35,11,85,54,71,222,55,75,246,129,65,125,75,195,48,32,101,91,238,218,233,231,46,52,11,27,142,105,154,121,19,241,117,209,108,188,88,169,86,198,136,169,106,153,22,47,47,47,187,55,147,128,219,153,127,71,
40,112,94,8,177,10,204,141,249,167,255,117,193,182,108,14,39,120,115,48,154,156,148,9,160,193,115,250,72,119,110,49,77,124,211,31,144,42,44,164,9,167,161,160,72,27,7,79,236,87,69,82,16,224,122,215,8,254,
99,254,36,82,191,187,27,8,33,192,50,76,119,245,197,19,19,229,185,233,146,97,24,115,182,109,79,152,166,249,90,165,92,25,35,162,106,38,157,161,116,42,117,83,237,222,182,144,44,0,32,215,117,95,51,12,227,
227,136,226,10,145,59,44,128,26,204,156,146,250,113,134,13,75,81,34,134,99,12,229,74,104,87,152,80,186,137,186,125,212,109,253,38,229,156,12,73,231,114,236,53,65,163,36,211,52,193,54,77,103,245,204,115,
19,149,185,153,146,105,154,121,203,182,46,24,66,156,169,55,234,79,166,51,233,42,3,64,58,157,226,87,206,158,109,222,108,2,198,118,85,249,161,67,135,254,168,94,175,63,210,104,52,238,70,196,198,238,175,253,
222,71,234,205,122,124,202,85,82,207,237,88,135,21,53,70,85,90,44,176,86,140,146,132,133,48,66,155,67,71,146,46,34,124,220,52,13,72,153,150,179,250,210,137,137,234,220,76,209,23,238,184,105,153,103,155,
141,230,216,165,75,151,110,42,135,234,90,119,176,167,166,17,47,24,134,113,39,34,142,16,209,160,137,220,168,17,164,34,135,137,226,117,38,172,182,237,149,49,226,96,92,140,178,243,72,154,28,174,33,85,172,
244,203,224,196,10,196,112,8,6,50,196,49,47,181,247,143,101,26,96,155,102,24,231,26,166,145,55,45,115,220,48,140,179,141,122,99,108,106,106,234,166,23,110,91,78,86,112,172,173,173,205,244,246,246,30,98,
230,94,114,221,254,141,183,94,95,234,187,231,35,187,154,205,38,170,115,146,56,214,144,84,71,39,147,74,72,91,206,0,132,205,155,174,197,167,149,176,18,225,114,130,27,103,154,38,164,45,203,241,178,66,83,
69,195,52,242,150,101,121,194,109,54,198,166,167,167,111,9,225,94,149,128,1,128,123,123,123,187,16,96,216,37,234,32,162,254,142,225,61,236,90,169,92,232,157,234,12,8,6,165,97,163,204,210,80,158,147,86,
4,43,168,69,52,239,156,19,60,111,86,62,40,177,47,106,108,145,88,166,9,41,203,114,86,207,156,156,40,207,77,249,113,174,175,150,155,205,177,217,153,217,91,70,184,87,43,96,88,95,95,159,238,233,237,221,203,
204,221,174,235,246,22,166,38,155,131,247,126,164,167,209,108,26,144,184,87,18,138,120,147,106,69,98,245,189,122,227,70,140,133,74,8,45,106,200,54,153,126,106,134,194,61,49,81,201,79,23,13,195,200,155,
166,53,110,154,230,217,70,163,57,54,55,59,119,75,9,247,170,5,12,0,208,213,213,85,70,196,125,204,156,38,162,190,141,243,175,45,246,223,123,255,80,163,217,140,53,245,151,147,5,58,36,200,33,241,92,198,170,
65,235,254,46,77,35,209,72,239,172,180,114,85,167,156,161,244,250,224,199,223,185,238,218,153,147,147,149,252,116,81,24,34,111,154,230,121,211,48,206,53,157,230,88,62,159,191,229,132,123,77,2,46,20,10,
107,221,61,221,157,192,208,67,68,41,102,238,47,156,127,109,186,247,158,143,140,56,142,131,156,84,132,38,25,90,101,230,189,134,96,178,212,52,84,223,157,241,30,152,24,27,145,196,242,160,169,112,140,158,
0,203,180,216,50,13,154,251,233,79,94,105,22,214,27,86,174,99,41,51,176,43,15,245,218,139,181,122,237,152,101,89,149,66,161,224,194,45,120,24,215,242,162,194,70,97,178,187,187,123,0,0,114,68,148,102,230,
62,168,86,214,178,123,246,245,55,93,7,245,246,20,160,59,59,172,86,22,180,154,11,17,213,0,177,198,143,84,155,138,42,173,37,194,29,143,96,26,6,216,150,197,150,97,56,107,103,78,78,54,54,214,27,66,136,57,
193,252,6,212,170,167,27,245,250,24,1,87,13,97,112,177,88,220,17,176,44,177,98,177,56,222,213,213,181,27,0,82,204,156,174,93,89,205,154,66,20,179,67,123,122,155,78,19,223,45,146,201,74,21,35,75,29,170,
185,213,178,137,106,141,0,192,178,44,182,45,147,13,224,230,202,11,207,76,84,230,103,55,12,67,204,25,166,53,110,8,241,106,189,209,56,198,12,85,203,182,200,182,108,94,223,88,167,29,1,107,177,113,38,147,
185,40,132,24,0,0,155,153,211,149,229,197,84,115,109,105,185,231,224,145,129,70,163,145,56,156,110,243,78,250,155,240,180,48,217,147,150,193,144,192,3,79,167,82,108,155,134,203,213,114,105,249,212,241,
201,218,202,210,154,129,98,70,24,198,121,67,224,107,174,235,142,153,166,89,49,132,193,150,101,241,244,204,116,19,110,209,3,223,237,235,7,6,6,6,17,241,27,174,235,126,216,117,221,195,196,60,12,0,141,125,
223,252,206,189,245,70,211,116,92,39,106,129,168,183,229,128,132,238,240,137,207,99,130,5,214,46,4,5,88,166,9,166,97,176,137,208,40,78,140,207,23,39,223,94,161,70,109,85,8,49,107,24,198,132,97,24,111,
19,209,51,75,75,75,197,91,209,161,218,238,29,12,0,0,149,74,165,146,73,103,102,12,195,232,4,0,139,153,13,102,238,41,156,127,117,165,103,244,160,101,102,114,41,151,8,131,94,151,74,231,243,208,83,230,196,
126,89,81,39,218,248,200,184,192,195,18,40,64,160,128,76,202,38,203,68,7,106,213,242,220,47,254,225,157,218,229,249,53,32,119,65,8,241,150,16,226,77,33,196,184,227,56,39,86,86,86,74,31,20,225,110,199,
14,14,223,167,187,187,59,103,154,230,215,137,232,126,215,117,71,137,104,132,129,59,82,93,189,60,252,216,151,111,39,97,216,142,235,162,227,184,232,56,78,88,130,137,177,122,235,160,19,78,180,229,21,34,188,
79,52,176,44,127,183,26,6,35,0,185,27,235,235,229,185,75,27,133,119,198,87,16,177,36,132,88,64,20,111,9,67,76,34,192,4,17,141,175,173,173,213,224,3,118,224,118,107,132,190,254,190,175,16,209,93,68,116,
144,137,110,35,226,126,0,48,51,187,134,173,129,143,125,102,47,164,51,57,151,25,153,25,93,215,69,151,8,92,34,69,208,65,139,93,57,79,96,8,1,66,24,96,26,130,81,8,54,16,9,156,102,163,182,48,183,86,93,90,168,
148,166,47,174,35,66,9,1,87,80,136,89,97,24,211,136,240,22,48,190,70,236,174,174,95,89,119,224,3,120,224,117,120,79,209,211,211,115,55,48,255,26,1,28,102,114,135,153,97,152,153,187,153,217,182,114,157,
86,247,209,187,122,50,195,123,186,69,58,147,102,20,6,131,39,112,175,159,36,135,137,38,225,183,80,64,244,3,32,6,226,90,181,210,44,21,234,229,252,244,70,233,226,196,6,0,52,0,177,132,136,107,2,113,25,16,
47,26,66,204,1,226,165,74,169,252,106,189,81,119,225,3,124,224,245,122,223,76,54,155,182,45,243,83,204,48,202,76,35,204,176,155,153,135,152,185,11,0,210,204,108,1,0,166,186,123,237,236,222,125,157,102,
38,107,162,97,10,35,149,50,209,176,12,118,154,174,219,168,59,236,58,68,141,186,91,189,60,95,174,173,173,214,208,176,144,234,213,42,34,214,16,176,4,0,203,40,224,50,130,88,68,1,43,0,112,30,65,44,172,111,
172,175,125,144,108,237,123,45,224,240,253,179,217,108,206,48,140,59,0,240,32,51,237,2,224,94,98,232,3,230,110,0,200,1,176,205,140,38,2,8,64,54,188,18,164,168,41,63,3,184,8,224,2,176,11,222,212,235,50,
2,110,0,194,21,68,220,64,196,37,68,92,96,230,75,0,176,94,44,22,11,59,130,125,239,4,44,237,232,140,37,80,12,2,224,110,4,30,98,134,110,64,200,49,115,154,1,108,4,176,0,216,100,0,1,81,167,103,2,0,199,251,
193,6,34,212,16,177,4,0,69,0,190,12,128,87,24,120,165,92,42,111,192,230,201,164,29,1,191,199,159,137,233,116,218,70,196,110,0,176,1,192,2,0,11,16,44,121,50,187,191,131,155,16,253,56,192,92,36,134,186,
48,144,171,149,170,187,35,212,27,79,192,239,230,26,118,132,185,115,236,28,59,199,206,177,115,236,28,59,199,206,177,115,236,28,59,199,117,62,254,63,152,229,162,182,137,224,143,40,0,0,0,0,73,69,78,68,174,
66,96,130,0,0};

const char* LivePanelComponent::forward_2x_png = (const char*) resource_LivePanelComponent_forward_2x_png;
const int LivePanelComponent::forward_2x_pngSize = 14663;

// JUCER_RESOURCE: reverse_2x_png, 14756, "../Images/Reverse@2x.png"
static const unsigned char resource_LivePanelComponent_reverse_2x_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,120,0,0,0,160,8,6,0,0,0,199,9,168,144,0,0,0,1,115,82,71,66,0,174,206,28,
233,0,0,0,6,98,75,71,68,0,0,0,0,0,0,249,67,187,127,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,219,10,29,20,36,52,151,157,207,16,0,0,32,0,73,68,65,84,120,218,237,125,
231,151,28,215,117,231,189,21,186,58,76,234,73,0,186,7,51,152,68,18,164,8,138,35,144,10,228,172,130,37,153,164,178,124,214,242,106,247,236,174,247,236,39,159,227,207,251,15,200,31,215,222,79,107,159,181,
101,153,182,36,7,90,162,162,37,90,162,36,75,162,69,138,20,24,0,2,36,103,16,38,116,79,234,153,78,213,185,234,221,253,208,21,222,123,85,213,51,160,6,36,0,78,225,52,186,167,67,117,215,187,239,166,223,77,
0,71,199,209,113,116,28,29,71,199,209,113,116,28,29,71,199,209,113,116,92,223,129,71,75,112,160,53,138,186,241,7,113,247,204,185,39,238,249,35,2,223,132,68,85,46,95,190,124,127,165,82,25,111,183,219,163,
205,102,51,97,89,86,194,182,237,152,109,219,10,99,204,91,63,69,81,72,85,213,142,97,24,77,77,211,234,241,120,188,172,40,202,230,47,127,249,203,215,254,248,143,255,184,236,16,157,29,17,248,109,38,236,210,
210,210,68,189,94,31,67,196,169,90,173,54,106,154,230,104,185,92,30,235,116,58,195,141,70,35,101,89,86,210,178,172,152,109,219,42,17,241,4,102,170,170,90,186,174,183,227,241,120,51,145,72,52,82,169,84,
125,96,96,160,166,40,202,90,127,127,127,190,82,169,188,248,254,247,191,255,10,199,225,71,4,126,43,9,219,233,116,102,26,141,198,236,214,214,214,120,179,217,204,212,106,181,225,122,189,62,82,175,215,251,
108,219,214,25,99,106,212,9,136,8,157,155,194,24,83,137,8,53,77,235,36,18,137,234,192,192,64,113,120,120,120,111,108,108,172,152,76,38,151,250,250,250,150,230,230,230,254,13,0,236,27,77,232,119,52,129,
137,72,125,226,137,39,212,7,30,120,224,3,197,98,113,114,103,103,103,178,94,175,207,21,10,133,209,122,189,222,223,106,181,18,68,164,40,138,98,223,249,232,103,223,21,79,196,117,93,143,169,168,32,42,168,
0,34,122,106,151,17,1,179,25,88,182,109,183,26,245,206,218,203,231,114,123,87,150,26,206,166,64,77,211,90,125,125,125,197,209,209,209,173,76,38,179,61,56,56,184,60,52,52,116,241,212,169,83,63,115,8,125,
68,224,195,60,182,182,182,250,74,165,210,184,109,219,247,237,238,238,222,181,185,185,121,170,92,46,103,170,213,106,186,221,110,199,179,15,62,52,209,55,60,146,74,13,12,198,117,77,83,53,93,3,5,21,208,84,
21,187,34,25,1,17,129,168,203,128,136,8,140,168,171,188,17,129,128,160,209,104,81,187,211,166,66,110,125,239,242,207,126,148,183,44,43,166,40,138,213,215,215,87,28,31,31,207,79,77,77,229,211,233,244,69,
68,252,197,233,211,167,151,110,132,142,126,39,18,24,159,125,246,217,254,161,161,161,123,43,149,202,157,165,82,233,174,173,173,173,153,66,161,112,188,221,110,199,179,15,60,52,49,156,205,14,37,147,169,152,
170,40,160,235,58,42,138,2,138,226,44,21,34,0,17,32,32,16,74,210,149,176,43,113,145,91,94,103,3,52,26,77,170,213,107,214,75,223,248,251,243,237,118,59,169,170,106,103,104,104,104,59,155,205,174,77,77,
77,173,14,14,14,158,155,153,153,249,222,97,115,243,59,141,192,120,245,234,213,169,78,167,243,158,124,62,63,181,179,179,51,87,44,22,79,85,91,173,19,138,162,41,119,125,236,209,59,227,137,164,174,107,26,
198,141,24,50,70,62,97,15,233,104,52,91,84,171,213,172,23,255,249,107,175,182,219,237,68,60,30,55,143,31,63,190,58,55,55,119,237,248,241,227,231,102,103,103,255,1,0,172,35,2,191,57,67,106,182,209,108,
126,32,159,203,221,185,177,177,49,93,173,86,79,232,99,199,179,233,201,233,244,104,38,59,148,72,36,84,85,85,80,85,84,64,36,112,248,84,180,130,200,125,14,1,144,68,19,201,97,96,239,62,196,81,118,23,188,222,
108,210,246,250,122,241,181,167,190,187,137,10,178,209,209,177,245,185,185,185,203,19,217,236,43,59,187,133,111,45,62,188,184,115,24,6,24,190,99,136,187,188,52,95,175,213,31,206,231,243,247,173,174,174,
78,87,42,149,49,0,192,187,30,251,252,153,84,127,95,60,17,55,80,85,84,145,80,50,225,194,254,150,137,186,223,103,185,131,49,6,213,154,105,61,255,247,143,159,183,44,203,24,28,28,220,154,155,155,91,154,154,
154,60,111,219,236,59,247,221,119,223,218,111,75,228,119,2,129,241,141,55,222,152,55,77,115,113,99,115,227,254,149,107,43,115,149,74,101,100,242,3,31,156,26,63,57,57,162,105,58,198,116,29,53,77,61,184,
245,125,64,218,7,23,155,156,255,187,247,238,123,235,245,6,61,247,245,175,188,208,104,52,250,7,6,6,118,230,102,231,94,159,58,53,245,10,16,125,251,221,247,223,255,91,17,89,189,221,137,251,218,235,175,207,
87,43,213,197,252,70,126,225,218,181,107,243,229,114,121,116,250,131,31,155,25,63,57,57,18,55,12,212,52,13,85,85,17,88,144,28,18,200,56,35,73,2,27,67,200,39,190,30,36,55,17,2,111,155,17,32,196,116,13,
143,223,125,38,99,35,214,11,43,87,53,211,172,37,21,69,209,134,134,211,67,95,248,194,23,174,61,254,248,227,181,35,2,135,16,247,210,165,75,243,213,74,101,113,99,115,99,225,218,74,151,115,103,63,242,200,
244,88,54,155,78,24,113,84,84,5,21,84,222,74,207,91,210,196,254,161,105,26,14,142,31,27,84,251,6,96,243,141,75,80,171,213,146,170,170,40,39,50,153,193,191,248,243,191,120,249,205,186,80,202,237,74,220,
139,175,190,202,115,238,92,165,92,25,153,249,240,199,167,199,78,100,210,9,35,142,136,200,113,152,127,35,233,239,176,231,137,187,167,30,127,203,207,69,61,235,254,139,197,116,60,57,127,231,216,196,253,15,
164,74,165,210,216,242,242,229,249,220,250,250,153,87,47,92,248,131,55,203,140,183,35,129,241,194,133,11,243,149,74,117,49,151,207,45,184,58,119,246,195,31,159,30,203,100,211,241,120,28,187,238,41,1,99,
12,136,168,251,216,185,231,111,140,187,1,243,31,19,243,239,137,17,0,255,121,230,124,150,133,159,83,184,49,233,70,0,177,152,142,179,247,159,157,140,199,227,213,82,169,116,108,121,249,242,236,198,230,230,
194,197,139,23,63,241,102,108,166,219,141,192,120,254,252,249,249,74,165,178,152,223,200,47,172,172,172,204,85,42,229,145,153,15,253,238,244,104,38,147,78,24,70,23,92,228,117,32,57,88,132,112,79,222,99,
247,70,222,155,129,127,194,59,135,251,57,7,2,229,78,14,210,185,220,115,147,36,182,201,251,49,113,35,134,239,253,226,31,158,213,52,181,181,179,179,51,177,188,188,124,106,111,111,239,61,207,63,255,252,29,
215,75,228,219,137,192,248,242,203,47,207,87,42,149,197,173,237,173,179,43,43,43,115,229,114,121,100,230,195,143,76,143,101,186,98,153,16,69,161,72,210,99,98,206,99,8,121,158,113,207,131,244,119,247,115,
64,254,99,255,117,6,64,204,59,15,115,158,35,0,143,195,25,240,18,163,187,65,146,137,56,62,248,159,254,199,189,140,49,101,115,115,115,114,117,101,101,210,182,237,197,235,165,217,237,66,96,124,233,197,151,
230,43,213,234,226,214,214,214,217,43,151,175,204,150,75,229,177,217,143,60,50,61,158,201,164,19,113,163,171,110,25,235,18,139,113,196,37,95,76,11,68,39,2,98,140,123,236,16,198,59,7,248,159,103,238,121,
28,238,101,206,251,201,23,189,238,247,0,49,232,210,156,249,220,204,192,231,106,34,239,60,169,84,66,187,251,145,79,31,111,54,91,125,185,124,254,100,177,88,188,251,220,185,115,31,185,30,46,190,29,8,140,
231,206,157,155,47,87,43,139,27,249,252,194,149,43,87,230,74,165,210,248,236,71,31,57,53,150,205,164,13,195,64,95,142,2,39,98,201,89,112,87,164,18,39,158,93,66,131,127,239,113,182,123,42,242,69,57,247,
156,43,189,131,230,23,239,118,137,102,25,255,8,184,71,10,34,140,101,179,105,77,87,27,165,82,105,124,109,109,45,83,46,87,238,186,30,131,235,86,39,48,254,230,133,23,230,171,213,234,226,230,198,198,194,202,
202,202,124,185,92,30,29,59,253,174,212,216,137,204,80,50,158,64,0,4,70,0,182,71,48,95,149,118,5,41,8,132,5,249,230,137,94,242,136,236,235,85,215,192,2,239,61,76,218,36,0,62,71,250,239,241,159,227,69,
52,111,236,185,6,93,220,48,240,129,47,252,183,123,44,203,210,183,183,183,51,149,74,121,238,249,231,159,255,240,65,185,88,187,149,137,251,252,11,207,187,98,121,97,109,109,109,174,90,173,14,223,241,209,
199,38,199,50,93,63,151,56,67,6,1,125,2,34,250,156,139,46,251,161,191,100,174,177,228,126,17,249,2,0,209,33,168,255,102,209,216,10,0,27,146,49,134,156,79,204,67,155,20,77,178,68,50,161,233,186,94,55,77,
51,157,223,216,56,214,215,215,55,11,0,63,129,3,68,158,110,85,14,198,231,126,253,220,124,181,92,93,220,216,220,88,88,117,64,140,185,223,121,100,122,52,147,77,27,156,43,228,233,64,38,61,118,217,152,113,
70,21,255,30,119,209,153,104,5,19,147,204,111,201,2,239,121,3,249,111,10,121,76,129,115,27,122,12,223,243,133,255,122,175,109,51,109,183,80,56,214,104,212,231,159,122,234,169,59,110,87,17,141,207,62,251,
236,188,89,49,23,183,183,183,207,174,173,174,205,85,170,213,145,249,143,62,210,245,115,141,24,34,231,186,136,34,214,215,113,130,110,149,45,234,253,254,9,214,178,251,152,9,127,121,150,55,255,60,49,225,
60,204,121,206,19,217,158,117,13,130,152,38,98,16,79,196,53,77,85,90,181,90,45,189,179,83,72,27,49,227,204,65,232,119,171,17,24,255,253,223,255,125,190,106,86,23,183,182,183,206,94,189,118,117,182,92,
46,143,205,255,206,163,211,163,199,179,233,120,172,107,80,117,45,86,230,45,158,15,56,48,9,124,96,189,129,136,48,96,130,56,171,154,124,67,75,148,12,36,50,34,39,49,120,96,195,7,31,197,115,10,190,178,243,
56,174,199,240,174,71,62,117,178,211,233,196,118,247,246,70,42,213,74,230,118,35,48,62,243,204,51,243,166,89,93,220,220,216,92,184,118,237,234,92,185,92,30,159,255,232,99,167,198,50,217,180,17,119,173,
229,235,187,145,36,94,195,129,15,16,44,104,1,239,224,223,3,209,239,37,138,0,61,201,87,17,192,73,18,16,172,237,238,109,248,216,241,33,0,96,102,165,146,182,45,235,228,87,190,242,149,209,219,133,192,248,
139,95,254,178,107,45,111,110,45,172,174,174,206,151,203,149,209,241,211,247,166,198,50,217,161,184,17,71,116,128,3,65,12,242,62,45,73,194,148,124,225,9,146,213,11,34,92,225,40,94,230,17,0,136,135,55,
56,107,25,124,223,26,228,231,221,231,4,178,185,220,203,28,145,236,90,227,208,189,14,79,202,116,31,107,170,134,136,104,55,154,141,254,82,165,210,151,205,102,222,189,159,53,125,43,88,209,248,243,159,255,
124,222,52,171,139,133,157,194,217,181,181,181,153,106,181,50,114,215,199,63,57,57,150,205,166,13,195,192,46,90,132,156,181,74,98,0,39,228,49,111,240,18,132,191,39,248,94,18,92,106,215,242,37,112,232,
207,45,53,177,174,133,78,204,183,148,249,223,229,25,226,66,48,89,132,49,69,227,154,32,166,235,152,189,255,129,161,213,223,60,91,173,86,202,253,205,145,145,49,135,73,237,91,149,131,241,103,63,251,183,121,
179,218,53,168,174,93,187,54,91,174,84,198,238,248,216,39,186,98,217,48,186,193,62,81,6,74,143,197,231,194,112,103,89,100,131,160,91,69,159,149,120,127,154,243,113,5,73,225,137,229,48,3,14,36,224,132,
34,13,61,198,9,117,87,90,76,156,126,215,9,4,100,181,90,61,213,168,215,135,110,101,14,198,159,254,244,167,243,166,89,93,220,222,218,90,88,203,173,207,85,43,213,177,187,30,253,212,228,120,38,59,20,51,98,
8,142,88,70,148,184,137,0,0,153,147,81,197,31,14,167,59,17,7,230,176,144,23,72,64,17,244,242,29,96,215,95,70,201,223,137,96,249,158,9,24,196,49,191,47,17,220,20,107,34,242,243,173,9,128,113,238,57,3,0,
61,166,171,0,96,55,155,205,100,179,217,28,216,143,73,111,86,2,227,79,126,242,147,121,211,52,23,183,183,183,23,214,215,215,231,43,213,202,232,241,187,207,164,198,79,100,135,140,152,129,46,190,11,4,64,138,
19,217,101,221,149,66,32,32,134,28,191,160,176,192,68,17,68,146,233,66,17,50,61,228,156,206,207,134,253,179,107,80,32,178,240,85,238,38,37,14,4,113,181,143,43,114,177,155,230,217,110,183,227,196,88,234,
86,228,96,124,250,233,31,207,87,171,230,226,246,246,214,66,62,159,159,51,77,115,248,244,199,63,61,57,150,205,164,141,88,12,125,4,202,221,218,228,51,23,81,216,242,5,120,8,229,245,118,22,22,123,240,29,70,
112,162,127,26,10,228,227,5,127,1,9,24,88,79,230,15,17,18,168,116,17,57,203,178,98,140,40,126,171,17,24,127,244,175,63,154,175,86,170,139,219,133,157,133,252,122,110,174,106,214,70,78,255,238,39,167,199,
50,153,180,17,51,208,19,108,116,29,82,49,32,20,131,6,19,18,47,174,1,8,67,184,145,68,110,10,24,90,252,235,210,99,193,0,227,101,114,244,14,114,158,19,95,64,64,100,140,33,17,105,4,20,187,149,8,140,79,61,
245,212,124,181,102,46,238,22,10,103,115,235,185,25,179,90,29,57,253,187,159,234,194,143,177,24,186,192,125,104,30,163,75,16,146,197,33,112,249,203,196,241,154,200,190,130,56,119,223,47,229,61,7,55,86,
200,119,30,228,177,35,117,132,84,91,87,201,70,109,78,15,11,71,240,138,220,108,182,111,192,225,102,33,48,254,240,135,63,156,55,77,115,113,119,119,247,236,218,218,218,172,105,154,163,167,31,249,212,212,
104,38,155,142,197,116,46,65,145,227,65,4,64,226,253,73,103,173,156,138,17,140,240,131,40,66,6,34,240,33,63,110,81,67,196,46,129,239,27,245,74,147,238,193,154,33,34,152,130,155,147,124,209,15,222,181,
17,18,16,50,162,91,130,192,248,131,127,249,193,124,181,106,46,22,10,219,11,235,235,249,57,211,172,142,221,253,200,167,39,199,50,217,161,152,174,59,216,114,72,86,57,33,48,247,226,29,199,146,39,12,69,172,
39,68,152,68,129,111,112,4,3,235,165,9,92,228,201,141,80,57,143,5,75,92,208,5,174,53,206,122,252,18,8,221,38,30,243,179,238,103,201,222,63,209,242,237,38,48,126,239,251,223,159,175,214,170,139,133,157,
194,66,46,151,155,55,171,213,209,99,247,156,73,141,101,39,134,186,98,217,193,111,17,2,78,143,199,145,82,152,47,146,105,34,1,12,142,97,36,42,147,92,181,0,17,236,44,132,24,201,207,125,38,0,66,233,239,16,
98,134,159,154,194,175,152,92,249,65,55,53,129,241,187,223,253,238,124,173,106,46,238,238,237,118,117,174,105,142,156,126,244,51,147,227,142,88,22,140,101,10,163,17,249,225,220,158,174,104,15,49,25,96,
111,234,38,167,243,2,150,35,182,64,107,206,48,67,201,229,161,16,247,59,204,178,118,165,15,3,209,238,34,226,220,110,20,173,60,114,171,27,217,205,203,193,248,157,239,124,103,190,102,154,139,187,123,123,
103,215,215,215,103,77,211,28,189,231,209,207,76,141,101,50,93,157,11,124,242,74,15,219,3,37,214,226,87,197,163,12,31,85,231,197,34,227,238,101,61,45,139,71,20,56,138,132,207,247,250,157,162,33,70,61,
125,97,12,193,83,209,19,35,158,57,72,33,144,236,77,68,96,252,214,183,191,61,111,154,230,98,161,80,88,200,231,114,115,85,211,28,123,215,99,159,245,116,46,80,8,91,162,44,87,121,238,115,22,26,121,54,115,
3,9,8,200,19,194,209,149,8,204,161,123,24,72,193,19,93,206,220,144,132,41,50,14,88,118,45,111,238,183,120,167,142,50,169,241,128,168,24,73,155,193,13,96,220,92,4,198,39,159,124,114,190,102,86,23,11,133,
221,133,92,62,63,95,171,154,163,199,223,117,95,106,52,59,49,228,114,46,147,234,123,200,209,105,162,40,148,119,177,172,231,252,205,32,240,10,15,248,211,126,8,195,1,28,110,217,2,38,201,162,135,110,156,23,
113,127,232,146,151,219,194,118,227,246,12,227,117,48,187,185,56,24,191,241,205,111,122,156,187,177,177,49,87,171,213,134,239,126,236,51,147,227,217,108,58,166,169,24,224,25,215,64,225,248,169,139,17,
56,181,187,228,214,233,58,28,139,158,239,36,33,18,65,251,153,34,145,197,253,108,237,30,47,135,73,216,208,205,212,219,28,0,18,5,139,23,24,65,95,7,31,16,221,121,203,8,140,79,60,241,196,124,205,37,238,230,
230,92,205,172,141,220,243,216,167,167,199,50,153,180,174,235,216,245,71,40,212,62,34,105,17,253,152,44,207,174,24,140,194,203,148,64,10,250,210,20,109,28,247,54,191,121,127,59,196,173,238,237,28,7,159,
11,49,228,120,238,5,47,230,65,55,29,7,227,63,61,241,196,124,173,94,95,44,238,237,157,205,111,228,103,234,102,109,228,158,199,62,59,61,118,34,155,214,245,24,10,177,82,222,54,10,81,95,72,81,251,150,246,
225,55,242,131,66,176,79,140,225,0,23,229,70,160,120,123,155,56,165,2,196,149,154,146,100,30,240,42,156,130,70,26,73,142,146,127,205,200,37,24,56,193,149,183,153,192,248,143,255,248,143,243,53,211,92,
44,22,139,103,215,115,185,217,186,89,27,125,215,39,62,59,53,146,201,164,117,93,195,64,197,45,137,127,147,100,144,16,199,2,97,190,34,29,132,48,178,235,196,165,210,250,168,9,6,193,103,36,209,160,2,167,52,
69,146,1,93,154,49,9,10,229,76,37,228,45,99,249,243,193,60,90,226,67,75,200,233,224,183,217,200,194,127,248,251,191,239,186,66,187,187,11,27,27,27,115,102,173,54,246,174,79,124,110,114,52,147,29,138,105,
142,43,36,100,57,80,184,120,228,89,25,253,37,99,18,61,100,108,158,247,97,101,113,74,18,192,224,227,220,28,100,41,61,239,27,64,114,158,51,5,149,45,113,172,27,10,173,129,148,26,226,94,3,103,44,130,100,133,
187,14,3,159,76,255,54,17,24,191,254,181,175,207,215,106,181,197,189,98,241,108,46,191,49,91,175,153,163,199,239,189,47,53,238,186,66,224,103,69,96,192,54,238,233,45,112,40,176,152,86,28,102,208,244,18,
199,161,159,167,158,193,197,224,235,20,18,27,238,25,82,146,141,10,17,119,14,250,212,24,200,161,102,172,187,115,223,46,29,140,95,251,218,215,230,107,245,218,98,113,175,120,54,159,207,207,214,106,93,177,
60,62,113,114,72,211,53,148,197,36,5,252,203,131,117,190,160,30,248,125,148,117,202,43,65,226,253,145,131,4,105,165,159,232,75,4,199,177,67,183,61,3,11,132,54,194,96,18,64,23,149,34,190,165,150,116,181,
20,188,70,55,209,225,109,176,162,241,239,190,250,119,243,166,105,46,238,237,237,185,174,208,216,153,79,126,126,114,108,98,98,72,211,52,47,111,153,7,20,144,115,135,194,247,48,245,14,142,71,69,13,120,124,
66,202,144,64,153,213,89,144,97,16,68,209,47,136,112,10,124,204,203,215,10,243,164,100,23,176,203,132,92,144,146,14,104,71,240,117,200,111,49,84,137,143,255,237,223,206,215,106,245,197,189,66,97,97,115,
107,107,190,102,154,163,39,238,125,119,106,44,147,29,210,53,29,163,192,133,104,172,57,202,48,146,184,155,72,188,15,141,36,112,162,145,179,74,197,31,36,158,35,52,50,21,8,13,132,197,151,69,201,19,240,135,
145,179,0,100,52,21,163,240,115,146,34,102,248,150,234,96,252,155,191,249,202,124,189,102,46,238,238,238,45,108,111,109,205,213,234,245,225,123,63,249,249,201,177,236,68,90,211,117,12,24,76,1,11,53,66,
42,123,16,22,47,19,41,34,1,78,134,20,185,215,67,163,18,20,14,21,18,249,92,14,33,134,182,4,59,146,23,40,16,119,67,176,213,161,108,36,147,248,147,3,236,27,97,97,59,134,22,123,139,8,140,95,254,235,47,207,
214,235,141,135,246,246,246,238,223,220,220,156,171,215,235,163,247,126,242,243,167,70,179,217,180,166,169,136,228,135,83,186,161,80,95,94,122,13,61,29,130,185,225,115,55,162,67,30,70,199,188,149,70,207,
134,14,177,190,32,24,88,32,129,51,201,247,85,185,247,202,206,23,95,231,235,137,217,72,49,138,94,188,90,142,66,137,223,70,209,144,244,1,28,59,95,226,49,14,131,191,177,4,198,47,127,249,203,147,237,118,251,
125,187,187,133,251,182,182,118,102,107,181,218,200,189,159,252,220,169,209,76,38,237,234,92,38,96,199,82,130,26,201,96,58,9,175,203,145,24,228,162,76,225,41,79,193,60,138,223,95,184,231,192,23,196,24,
65,199,182,161,195,108,104,116,44,40,214,154,80,172,55,32,95,174,66,219,182,69,113,202,127,167,23,224,8,49,252,145,122,170,160,112,195,1,163,113,107,71,253,220,112,43,250,255,253,229,95,142,181,219,173,
247,236,108,23,238,220,221,45,204,212,106,213,209,123,30,251,204,169,209,76,54,173,171,26,70,93,212,126,72,42,133,5,142,66,160,121,146,115,170,4,81,142,130,190,59,232,161,40,8,134,162,129,1,26,244,25,
6,140,245,165,0,0,192,182,109,88,43,85,224,66,126,27,106,173,118,79,12,58,96,34,176,48,114,241,249,95,40,108,104,62,20,25,150,250,243,150,132,11,255,228,79,254,68,99,182,61,93,44,22,167,203,149,242,29,
85,211,28,157,255,200,35,147,227,217,201,97,77,117,92,33,71,132,160,240,211,81,224,68,191,181,39,134,0,7,162,193,132,2,81,121,80,143,164,76,12,206,228,165,195,233,214,168,170,42,156,26,73,67,118,104,0,
206,173,229,225,234,78,49,224,90,9,214,183,164,102,153,220,105,88,48,226,72,242,30,72,144,84,16,17,65,187,97,80,229,151,190,244,37,173,191,191,63,99,154,230,93,165,82,121,186,82,169,140,103,23,30,60,121,
226,212,204,176,170,40,194,143,64,41,252,231,237,79,46,100,36,92,94,143,66,33,138,112,153,40,80,214,0,162,95,36,139,97,34,176,34,242,153,16,1,116,53,186,5,134,174,170,240,222,83,39,1,136,224,74,161,8,
97,41,121,36,253,111,51,6,109,155,65,199,182,193,178,25,88,204,6,155,1,216,204,134,110,21,41,3,198,21,158,19,151,61,26,230,55,220,112,168,242,252,249,243,202,67,15,61,180,96,154,230,93,85,179,58,221,106,
181,82,39,230,238,72,107,154,166,162,130,200,95,48,69,1,20,146,251,65,161,106,7,3,16,38,131,144,232,13,111,12,161,100,94,133,108,242,74,163,9,63,120,245,13,223,30,64,62,163,178,251,71,50,22,131,209,84,
2,102,198,134,225,196,224,64,224,28,103,167,38,96,215,172,195,70,185,10,205,142,213,213,219,182,13,22,99,96,51,240,106,147,3,176,119,24,108,67,126,132,69,48,211,34,132,208,141,22,209,248,193,15,254,135,
247,86,171,230,189,197,226,222,92,219,166,204,29,31,254,120,38,217,215,159,64,68,36,218,207,60,228,35,247,189,2,168,162,254,36,232,129,254,241,40,15,147,92,223,168,95,193,162,124,240,46,247,212,154,45,
168,53,91,240,198,118,1,198,250,250,224,163,167,231,32,174,251,203,165,42,10,204,142,141,192,115,87,214,128,16,129,207,206,66,97,75,146,228,111,75,201,247,36,198,4,137,66,226,137,129,16,103,119,103,178,
27,1,116,252,159,63,251,179,227,213,170,57,181,181,181,149,41,149,202,25,140,25,202,137,153,217,97,197,105,141,78,61,252,128,96,168,142,14,238,33,132,98,189,112,128,68,12,58,208,169,27,237,14,212,218,
109,104,116,44,232,116,108,176,56,14,188,178,83,132,29,179,6,255,253,253,11,220,32,14,128,59,143,143,193,64,50,14,165,122,83,244,6,2,169,64,76,244,235,67,127,171,12,135,146,32,189,2,123,153,237,147,68,
240,38,9,140,22,179,103,171,149,234,100,189,94,207,90,150,101,60,244,197,63,188,83,211,99,154,162,40,156,136,11,169,48,112,107,95,185,80,25,127,177,65,166,70,7,190,68,33,37,21,37,145,29,133,98,99,32,140,
225,31,54,35,200,151,202,208,236,116,160,99,51,199,191,237,5,92,35,92,222,42,192,165,141,109,184,59,115,76,56,215,204,232,48,252,102,37,39,58,190,66,226,31,11,128,25,4,209,201,244,114,90,11,95,249,232,
121,254,204,41,44,61,108,29,252,167,127,250,167,39,218,237,214,108,163,213,156,169,215,235,233,153,15,124,232,132,17,143,235,62,46,218,5,32,144,131,212,2,190,44,113,126,46,133,224,79,36,138,74,185,63,
115,120,31,231,40,23,140,160,218,106,7,174,195,98,54,148,234,205,240,79,163,12,32,248,156,244,210,90,62,64,224,201,225,65,120,225,218,154,180,81,137,75,8,128,0,240,17,106,135,120,105,71,232,25,27,66,69,
139,80,193,113,3,116,240,239,253,222,231,149,122,189,62,82,51,107,163,213,74,101,164,211,233,196,199,167,103,134,21,85,9,128,25,252,194,176,3,97,51,7,3,119,124,239,23,35,221,135,82,189,1,102,179,13,77,
203,2,155,69,143,14,116,35,50,192,165,28,160,100,253,251,90,181,123,191,182,87,10,156,167,207,48,252,106,126,144,132,152,27,220,8,213,26,238,228,22,224,18,231,185,4,44,68,159,123,229,248,146,179,113,14,
85,7,207,204,204,234,138,162,76,55,91,173,76,179,217,28,156,125,248,67,153,68,50,101,40,168,160,239,201,35,68,122,58,129,116,82,148,16,33,238,66,16,195,81,142,128,191,8,80,48,27,96,182,154,208,234,88,
96,75,229,159,81,34,218,117,149,208,177,202,136,75,178,32,12,3,59,187,175,153,205,86,224,60,201,152,238,85,246,119,207,129,98,40,143,28,191,223,69,179,8,3,200,157,107,83,32,135,209,33,177,208,32,75,56,
94,112,8,4,142,199,227,131,141,70,99,180,209,168,143,48,192,190,129,209,99,73,84,28,78,240,10,120,66,120,147,95,57,169,151,70,144,136,76,18,227,114,9,7,130,217,108,66,169,222,132,70,167,3,182,180,131,
3,97,134,40,17,38,244,167,148,202,74,221,42,3,15,24,35,15,203,38,82,66,252,102,20,218,58,8,25,85,196,97,0,20,6,175,6,171,37,253,162,20,12,189,50,190,27,15,179,15,143,192,24,143,39,178,197,226,222,88,187,
221,30,209,82,125,241,129,225,225,62,68,196,158,11,41,233,142,104,160,50,58,152,79,68,176,99,214,160,218,104,65,187,211,17,195,106,60,196,23,86,220,0,0,20,1,18,186,69,227,68,216,229,46,230,91,121,188,
110,99,28,138,214,103,196,2,231,106,182,59,161,81,29,129,59,145,56,108,74,54,158,185,194,53,161,18,131,69,214,185,16,81,104,220,252,77,19,248,143,254,232,143,244,78,167,61,210,108,54,211,173,118,59,149,
57,125,239,128,162,107,74,47,49,10,161,14,210,193,234,231,59,150,13,59,102,13,204,86,11,58,182,237,72,109,174,191,36,15,90,146,104,176,241,112,33,117,203,165,35,69,180,155,134,202,200,215,34,114,147,35,
175,30,8,1,166,70,6,3,231,217,169,154,61,140,29,242,137,76,82,126,150,128,126,48,209,87,118,45,50,230,219,8,216,117,124,111,76,210,93,44,22,139,119,58,157,113,203,178,70,173,78,199,24,159,158,29,81,220,
8,40,65,32,57,152,56,244,185,87,156,214,131,5,136,192,102,54,108,87,106,80,109,182,192,34,155,51,122,28,13,64,124,189,110,184,104,11,214,126,19,132,219,33,228,225,192,1,141,17,37,75,8,224,61,167,78,6,
94,93,41,236,57,238,74,84,57,163,15,214,202,213,44,242,250,132,33,112,158,65,197,149,201,30,58,22,93,46,149,20,93,215,147,173,86,43,25,235,27,72,26,201,164,142,72,209,253,168,34,64,242,176,101,220,40,
87,160,220,104,128,109,51,41,161,130,131,57,89,120,30,27,65,68,40,120,63,28,133,184,197,33,209,94,232,74,131,96,233,253,153,147,25,184,227,248,184,232,110,217,54,92,88,223,224,26,158,113,241,102,47,13,
201,63,15,239,111,19,135,112,9,13,124,184,196,6,185,45,132,27,29,59,108,55,9,199,142,29,27,108,53,91,73,219,182,19,169,177,227,241,88,204,208,136,33,2,70,23,221,4,162,105,28,243,150,26,13,216,53,107,208,
108,91,225,210,157,132,192,113,208,208,102,17,226,254,58,130,233,140,136,11,195,131,40,42,185,100,2,130,46,231,254,254,131,247,7,206,241,204,210,85,168,181,219,209,94,56,63,235,65,168,168,33,129,114,178,
171,132,196,37,23,200,241,18,175,246,233,16,83,118,152,101,247,117,58,237,164,109,219,134,135,158,98,176,152,43,2,122,5,114,172,201,252,110,25,170,205,150,211,30,80,244,158,194,210,117,248,150,12,192,
120,245,20,205,154,93,189,203,97,187,81,70,22,49,193,119,231,17,48,35,166,67,58,145,132,233,177,97,120,112,118,10,166,70,135,131,186,183,98,194,191,188,124,49,104,29,75,40,156,139,27,35,3,96,78,121,14,
202,146,78,210,19,196,39,216,115,27,221,219,7,236,144,117,176,101,91,104,89,150,206,108,166,141,76,158,26,34,103,141,163,114,14,120,132,170,92,111,194,118,165,10,205,78,199,113,41,164,233,171,32,57,250,
146,74,103,30,34,196,39,204,249,90,41,8,89,50,161,191,73,24,212,114,98,104,0,254,236,63,127,254,77,199,134,11,85,19,254,226,39,207,64,179,221,225,198,87,250,16,173,151,152,239,94,8,243,37,15,97,148,211,
193,23,39,73,201,124,4,66,48,131,185,5,120,135,164,131,145,136,25,182,205,52,70,12,227,253,3,134,231,215,97,116,202,231,118,197,132,93,179,6,182,155,195,235,94,96,79,216,138,122,32,92,225,128,164,208,
187,66,16,0,36,66,127,135,112,116,108,27,158,93,190,6,223,59,119,1,26,157,142,8,87,160,220,30,56,72,183,158,1,148,136,120,106,48,45,144,31,0,114,72,28,140,168,232,140,152,74,140,60,233,200,136,4,204,217,
93,218,124,177,4,165,122,35,232,27,82,4,100,135,124,221,137,44,230,57,88,18,73,232,22,21,176,124,145,130,41,168,14,34,116,24,7,17,193,15,95,190,8,63,186,240,90,32,211,22,34,138,25,67,128,168,174,210,64,
140,10,128,251,225,97,33,162,4,98,189,150,7,85,30,146,14,182,109,27,153,109,43,140,24,104,49,93,17,173,217,238,151,172,239,22,161,92,111,8,147,69,228,146,20,49,77,39,232,123,34,163,0,216,224,245,12,35,
167,183,36,249,196,22,138,77,153,212,224,2,163,161,0,70,4,45,135,3,249,67,65,132,152,166,9,33,65,30,177,250,212,194,189,48,123,108,12,254,242,167,207,64,199,178,186,113,96,38,33,83,192,197,134,165,72,
61,114,77,74,121,119,175,139,150,241,63,16,133,181,21,247,11,121,8,217,161,133,11,109,219,70,114,198,192,169,170,170,17,185,141,62,17,214,247,74,80,170,213,101,51,39,144,114,74,16,28,184,76,16,82,73,72,
33,254,97,72,129,81,16,46,160,232,188,2,233,216,44,85,224,75,223,250,33,132,53,179,67,68,24,27,232,131,211,153,99,240,193,211,243,112,76,202,230,184,59,123,28,254,231,135,62,0,255,247,199,191,232,118,
255,9,9,82,250,226,154,130,198,87,88,151,46,10,241,61,24,5,209,57,15,219,118,212,222,161,137,104,64,98,142,181,104,219,54,35,2,200,151,43,176,107,214,128,57,95,134,32,214,176,134,119,103,100,33,154,37,
74,198,69,128,93,81,9,15,16,37,18,163,78,198,128,17,58,214,34,114,8,25,131,205,82,5,182,74,21,248,183,75,75,240,31,223,187,0,31,186,91,156,127,113,207,196,9,120,244,190,187,225,251,47,94,144,181,163,0,
163,250,191,141,132,216,148,160,75,228,4,0,190,72,93,238,245,225,218,62,36,66,150,191,53,129,9,157,14,202,140,193,222,222,94,59,215,236,248,240,30,136,121,202,20,154,75,122,192,228,89,206,59,16,10,5,220,
191,153,100,116,17,122,186,138,15,242,33,39,219,163,22,193,45,195,20,99,173,76,104,141,4,4,240,15,191,250,13,196,117,29,222,55,63,45,124,254,209,251,238,134,23,175,174,65,190,88,18,9,235,41,77,38,228,
87,121,46,19,15,135,32,72,115,12,61,168,74,10,152,96,32,166,14,7,12,23,30,168,33,56,179,109,91,65,197,34,34,182,177,83,104,91,150,77,238,136,55,198,141,138,179,165,73,33,140,64,156,202,201,186,201,218,
228,142,126,99,78,27,126,230,183,216,247,70,221,48,242,230,251,1,3,255,61,222,249,187,171,195,24,23,201,225,38,153,49,167,204,146,122,24,77,242,116,80,191,65,184,59,111,176,123,109,95,253,229,175,97,167,
82,21,62,175,42,10,252,254,251,22,156,41,164,140,107,189,207,156,177,117,206,111,102,204,185,110,121,210,105,55,219,146,31,179,199,175,37,147,135,134,184,211,76,129,196,33,94,135,64,96,98,140,53,0,160,
131,136,54,107,183,25,99,228,41,121,127,70,31,184,99,13,156,89,67,222,139,222,123,152,48,141,132,188,89,69,46,161,128,113,243,11,160,187,40,64,252,36,19,238,158,49,255,111,231,115,221,145,174,76,152,170,
2,44,188,199,6,11,153,188,226,46,48,115,62,230,206,43,108,91,22,124,237,153,95,7,78,115,103,230,24,220,157,61,230,103,153,48,240,230,46,49,190,103,187,212,249,157,145,59,115,141,235,229,206,184,238,238,
210,53,48,97,52,15,55,37,141,29,14,129,1,1,219,136,216,34,34,106,108,172,150,137,24,185,3,22,253,137,157,220,224,71,96,254,197,114,68,115,119,132,207,249,76,216,141,252,88,55,97,132,141,55,180,34,56,250,
205,155,239,75,254,20,19,198,109,132,168,80,94,112,172,14,243,231,33,185,28,12,190,191,249,234,218,6,92,202,109,4,206,245,201,133,51,30,215,146,71,10,127,144,134,123,141,46,83,48,198,197,115,121,137,70,
190,132,115,55,160,55,141,148,113,12,192,173,203,65,90,25,30,136,192,170,174,182,20,69,105,41,138,210,106,23,182,235,140,89,204,191,120,18,196,138,55,232,9,156,153,69,64,65,226,200,147,80,56,162,56,163,
161,130,67,154,249,17,100,28,71,128,179,193,228,121,72,76,152,164,18,158,178,227,206,87,16,57,166,187,81,108,71,141,248,131,158,25,60,249,235,151,2,231,153,61,54,6,119,30,63,38,76,41,101,156,58,98,196,
205,94,96,18,97,185,245,240,38,198,8,211,86,228,129,213,242,115,135,163,131,105,183,176,91,210,52,205,68,4,19,181,152,106,53,90,109,198,186,194,67,30,176,232,94,136,119,1,140,5,134,47,2,11,231,84,111,
186,54,131,144,161,84,221,93,109,123,211,183,253,81,52,204,22,199,207,136,67,172,194,179,194,24,39,218,129,231,32,87,218,56,162,18,192,215,139,203,91,219,112,113,61,200,197,143,45,220,235,111,4,103,94,
48,47,69,72,34,168,76,36,255,183,2,183,225,64,34,54,243,46,8,135,198,0,0,25,24,73,68,65,84,166,150,3,55,138,239,80,56,184,82,169,52,21,69,41,43,138,90,101,205,122,163,109,150,27,228,40,42,38,17,138,73,
162,149,129,184,216,46,103,135,94,104,64,100,202,23,200,25,63,30,167,186,231,4,143,240,46,199,123,170,161,151,145,197,196,123,96,34,135,9,247,140,224,59,47,4,185,248,238,137,19,112,106,108,196,55,36,73,
50,226,132,57,197,172,199,245,81,228,61,227,230,58,241,191,243,80,8,220,215,151,34,2,218,85,20,165,164,160,210,106,110,230,43,196,108,22,62,38,78,20,35,93,201,26,98,13,114,143,61,227,198,91,80,110,158,
159,59,140,89,22,243,76,180,38,189,13,231,238,108,238,124,145,241,96,94,53,68,140,179,3,233,250,94,203,109,192,235,249,205,16,93,124,175,240,91,4,73,98,179,160,129,200,60,27,52,56,182,135,130,175,129,
160,14,153,167,54,14,133,192,79,60,241,207,29,0,220,137,197,98,187,154,174,153,181,229,75,187,86,167,211,161,238,33,77,233,34,193,184,32,111,126,32,227,220,37,198,233,27,223,106,238,90,188,204,39,16,243,
45,99,198,207,5,148,184,138,241,196,98,226,172,193,232,180,89,153,128,65,3,77,116,165,124,144,225,219,33,186,248,254,233,73,200,164,7,129,241,131,165,25,113,179,149,124,93,111,3,103,29,187,82,72,216,184,
221,215,152,244,156,56,180,250,96,64,199,65,7,99,17,49,182,173,105,90,65,85,213,2,0,88,141,157,173,18,49,70,68,76,92,36,105,220,185,48,100,145,73,127,187,224,5,103,57,186,186,150,60,212,134,243,79,57,
195,69,28,96,197,89,210,60,97,34,138,164,9,32,96,137,11,68,134,112,110,118,157,149,11,107,57,88,222,220,14,64,156,159,88,56,35,138,85,136,24,37,79,254,96,106,198,173,13,115,214,146,9,146,160,187,150,140,
243,72,120,131,237,176,8,12,127,245,87,127,181,171,105,218,134,166,105,219,170,170,214,26,27,57,147,17,35,126,194,38,115,119,42,227,230,241,18,55,179,215,243,1,193,215,153,220,56,86,112,28,13,215,192,
241,231,7,58,23,41,56,250,76,152,29,232,74,18,129,56,145,139,32,90,241,252,57,69,163,39,100,250,168,179,232,223,122,238,92,224,172,239,187,99,6,70,251,83,142,120,117,140,45,217,55,103,190,245,207,24,11,
0,46,188,215,225,113,47,112,110,162,187,206,7,76,217,185,158,209,118,100,91,214,85,77,211,54,52,85,45,54,86,150,75,173,226,94,217,21,211,110,252,181,75,32,38,136,102,119,225,153,75,100,198,28,160,194,
95,80,22,230,255,114,214,173,123,145,190,216,227,7,58,71,140,128,237,233,38,113,58,223,53,204,8,68,244,141,124,85,194,36,95,252,197,107,171,112,117,187,16,64,183,62,177,112,166,187,33,57,247,202,147,94,
174,116,98,254,70,247,12,51,126,64,53,127,93,16,244,52,188,209,242,135,5,85,114,49,131,66,60,110,236,196,19,137,29,85,85,204,122,126,173,194,88,55,250,224,234,9,240,22,73,156,170,13,156,219,68,32,89,176,
32,94,144,167,91,37,148,202,5,16,100,151,131,145,104,120,144,4,136,68,167,205,6,245,46,15,83,50,105,211,120,200,154,243,247,147,207,254,38,112,222,255,112,247,157,48,16,143,7,16,39,215,178,103,1,85,38,
125,7,4,221,70,222,128,5,217,136,61,68,2,195,95,255,245,87,74,0,120,81,83,181,203,154,30,43,152,175,95,216,233,84,171,13,34,70,140,120,139,152,133,232,28,145,243,100,140,218,247,23,153,100,0,201,128,10,
4,56,11,28,220,91,198,191,221,223,18,228,94,16,13,61,239,123,153,47,6,57,78,98,156,228,112,165,16,49,130,95,47,95,129,149,157,93,225,220,186,166,194,39,222,195,233,98,160,0,44,27,37,109,100,35,145,31,
146,233,161,90,188,157,113,3,234,131,137,49,182,25,51,98,185,120,219,200,119,90,173,145,237,159,255,235,229,227,31,251,212,105,69,215,99,196,2,113,105,41,30,234,102,66,67,32,91,42,16,44,23,27,24,113,217,
143,44,60,158,138,97,209,169,238,217,254,224,127,255,121,68,217,42,159,212,134,161,133,94,209,1,176,238,85,252,175,191,125,34,208,229,199,139,167,49,8,47,145,21,162,158,226,96,15,182,175,24,133,235,106,
8,126,221,227,101,31,127,252,241,109,93,215,175,196,19,241,171,137,68,98,3,58,237,122,245,218,242,38,235,194,62,68,129,136,18,111,192,248,150,175,199,169,204,247,11,65,176,108,129,179,138,249,209,232,
32,78,229,38,16,71,167,123,193,13,222,162,6,73,106,136,163,215,137,139,126,241,238,136,96,93,67,8,48,227,26,133,196,4,152,17,56,216,213,53,32,101,127,27,4,9,69,161,110,27,4,48,124,137,227,237,27,211,194,
129,86,86,174,189,148,205,100,135,99,134,209,103,116,58,9,115,233,98,204,24,207,164,245,254,129,62,0,18,199,225,72,57,12,20,145,88,198,23,130,137,157,226,48,208,46,152,248,26,77,224,27,157,249,28,79,78,
33,118,183,122,202,149,9,33,205,195,132,194,236,224,232,87,198,55,215,3,169,72,157,251,93,68,225,241,123,97,92,79,144,199,3,137,240,193,94,96,238,24,92,95,122,93,79,109,210,155,26,16,253,244,211,63,233,
116,44,235,66,44,22,187,172,235,250,21,213,182,119,139,47,60,115,149,117,218,29,158,139,123,194,145,64,33,200,23,132,187,46,46,248,225,69,120,36,171,218,211,117,28,128,193,129,38,190,161,39,25,53,44,24,
95,21,192,20,94,103,2,147,16,47,206,178,118,140,47,96,98,28,23,60,131,79,182,194,253,113,244,140,129,240,26,113,238,147,39,125,2,152,181,35,97,110,100,35,180,102,179,185,213,215,215,247,70,34,145,24,178,
44,107,176,94,41,37,118,127,253,204,229,145,247,61,60,143,168,234,204,173,213,245,82,87,165,121,232,194,124,87,177,39,35,10,141,205,36,142,15,235,217,192,64,76,109,161,96,207,42,79,37,131,152,68,142,1,
14,195,64,59,95,175,38,215,181,5,184,26,41,230,214,141,241,163,123,156,234,64,146,88,159,132,148,21,46,159,182,87,63,17,97,158,1,103,203,208,193,116,176,250,102,9,252,218,107,175,177,153,233,233,98,50,
149,234,39,130,152,205,172,190,86,105,47,209,174,148,235,137,19,39,135,1,65,33,10,27,105,35,103,204,251,157,83,189,130,48,10,235,245,193,45,148,99,16,9,53,59,251,92,179,71,112,138,72,36,34,10,153,169,
33,204,233,22,23,92,24,10,194,85,16,10,189,58,228,132,58,127,146,140,152,35,75,129,146,88,146,122,122,240,57,241,229,75,175,108,19,17,36,147,201,213,165,165,165,127,5,0,235,208,9,12,0,240,218,235,175,
91,51,51,51,59,201,68,98,0,0,98,182,109,199,155,197,61,163,83,41,153,137,236,100,26,160,75,100,185,1,137,219,168,132,136,228,122,79,62,160,231,247,232,32,241,42,73,168,227,16,117,39,121,6,49,73,253,60,
40,52,101,222,107,60,38,15,19,160,160,142,14,186,5,66,105,134,103,169,187,85,252,66,130,33,223,90,190,155,228,38,53,61,3,177,81,121,120,154,30,16,0,84,46,189,178,13,8,144,74,166,110,44,129,29,78,110,207,
206,205,109,36,226,241,62,68,212,24,99,137,122,113,215,104,151,203,102,50,123,50,13,0,138,11,102,136,68,16,107,122,137,162,83,244,8,130,205,87,136,122,116,225,61,64,146,38,4,202,94,161,55,235,203,238,
30,161,159,221,232,72,21,226,70,211,18,82,160,247,52,9,249,166,129,42,100,105,83,16,68,73,227,234,165,243,219,0,4,201,68,114,117,121,121,249,198,18,216,37,242,228,212,84,46,149,74,37,1,64,99,140,197,155,
197,93,163,93,46,153,73,143,147,195,123,119,200,61,116,130,61,117,14,66,0,185,122,130,164,228,105,169,39,164,52,156,200,11,138,0,4,162,75,196,103,55,146,168,106,252,206,64,20,104,30,142,220,111,145,17,
167,224,28,114,177,141,90,176,108,133,47,214,35,168,188,254,202,54,0,64,34,153,92,189,124,249,242,141,39,48,0,192,210,210,82,251,228,201,147,185,190,84,95,18,20,208,152,205,226,205,226,158,207,201,142,
78,14,167,13,133,38,55,115,129,39,81,84,75,3,52,136,164,6,42,68,94,243,19,191,7,135,175,223,189,222,91,78,173,173,231,150,132,205,49,68,63,242,229,17,12,197,20,215,176,253,24,232,97,30,16,46,4,114,239,
59,226,220,35,97,46,165,244,249,234,107,231,183,1,0,146,201,196,234,229,203,87,222,26,2,3,0,44,47,47,183,79,158,60,153,75,37,82,73,228,56,185,83,118,117,50,250,68,238,213,240,138,194,22,47,228,141,68,
158,193,130,254,78,8,142,178,225,45,43,12,23,205,36,27,61,146,253,36,231,170,243,66,129,36,149,33,87,44,80,136,64,166,158,26,197,29,175,194,147,219,71,117,92,2,39,18,137,213,43,87,222,66,2,3,0,92,190,
124,185,61,49,113,50,151,76,165,146,0,168,49,198,226,141,226,158,209,169,148,205,100,230,36,71,100,130,232,105,101,17,149,220,94,105,37,8,16,163,103,36,185,175,19,183,234,60,71,120,47,161,16,192,231,167,
225,241,1,250,48,176,2,66,12,123,169,114,189,247,53,68,90,23,16,84,43,8,210,32,174,238,238,245,8,156,76,172,94,189,114,245,173,37,48,0,192,149,43,151,219,19,19,217,92,42,149,116,116,178,29,111,236,237,
26,237,74,217,76,102,39,211,36,17,89,232,250,70,20,144,77,126,235,32,193,179,242,147,2,120,174,8,151,228,146,206,39,95,212,82,239,182,49,215,99,7,80,132,125,39,22,183,144,196,245,36,14,231,160,160,84,
16,54,22,129,192,193,87,175,190,13,4,238,18,249,74,59,155,205,230,146,201,100,18,17,53,34,242,196,117,210,19,215,76,108,240,77,254,252,32,66,10,218,53,252,232,59,105,65,68,187,74,106,54,70,60,0,33,79,
104,33,255,220,189,154,186,68,166,186,4,25,14,37,139,82,8,14,144,60,85,92,204,233,118,157,117,129,1,136,171,119,150,68,244,181,107,215,222,30,2,3,0,92,189,122,181,157,205,102,115,137,68,34,5,4,26,49,102,
52,75,123,70,187,92,170,185,214,117,23,150,115,9,135,98,217,44,5,219,223,8,179,255,200,143,200,80,160,144,45,186,131,101,24,74,46,206,67,216,71,160,202,58,24,249,96,150,115,29,124,222,151,55,84,146,31,
100,25,54,121,2,34,176,117,18,174,210,37,112,60,30,95,93,89,89,233,73,224,27,61,156,146,226,113,163,81,40,236,62,157,30,78,35,12,164,135,168,184,19,107,228,86,148,220,183,86,94,204,124,230,139,247,19,
128,234,129,23,46,255,209,126,45,141,40,96,111,123,156,131,193,201,61,242,252,66,224,230,12,75,237,154,69,224,212,237,148,67,210,108,36,183,255,6,115,155,171,56,157,96,153,91,204,204,130,206,159,51,137,
60,216,185,145,196,201,183,126,243,47,231,103,146,24,108,1,222,170,191,65,193,134,235,57,152,77,192,152,221,40,238,237,253,88,107,154,63,139,35,190,108,24,70,158,217,164,22,158,253,249,101,13,209,118,
71,7,19,87,56,38,7,194,153,148,229,24,86,230,194,164,50,24,33,233,45,164,250,129,15,235,121,165,39,228,167,19,121,249,81,188,248,4,169,125,2,227,115,181,184,176,40,147,19,26,152,255,91,89,48,224,47,38,
64,64,240,218,88,55,121,193,77,56,0,162,155,99,126,112,255,64,63,49,98,172,88,44,54,74,197,226,143,135,134,134,20,0,48,24,99,216,200,175,102,119,158,251,197,210,200,123,31,158,87,16,84,63,67,33,138,127,
125,108,56,170,159,118,248,100,53,20,11,197,93,110,97,220,36,112,160,110,147,109,46,254,225,115,143,104,228,184,156,31,54,61,212,77,151,236,22,129,163,48,220,249,64,96,141,4,81,138,207,117,79,230,17,150,
110,96,176,225,160,199,197,139,23,217,187,223,253,110,5,21,132,184,17,239,212,235,245,149,68,34,158,80,20,37,206,24,83,91,165,61,163,83,41,85,83,19,147,105,2,31,12,161,80,55,36,136,74,137,136,62,5,173,
89,199,21,18,68,27,241,227,105,156,122,92,66,174,125,81,216,68,83,177,165,17,79,1,36,148,186,188,135,121,75,24,217,30,142,34,12,182,40,72,214,124,237,252,54,2,128,17,79,172,174,173,173,189,173,58,24,0,
0,190,241,141,111,240,13,49,58,15,61,252,240,83,169,68,210,182,109,214,36,34,106,228,86,179,133,231,126,177,52,252,224,195,243,10,42,154,197,108,191,157,184,103,180,48,113,172,14,69,140,9,39,110,245,57,
130,121,90,145,241,77,200,194,230,20,74,214,182,236,71,133,248,196,8,130,2,13,101,208,0,121,121,87,175,23,145,185,4,7,191,195,159,139,133,179,183,159,131,195,142,181,213,213,246,248,241,241,92,50,17,247,
176,107,135,147,205,100,118,202,177,174,41,24,132,160,8,39,55,24,231,19,66,122,196,251,80,72,82,27,99,138,112,140,100,95,89,244,199,40,36,76,205,219,198,161,238,148,28,225,162,30,206,179,44,172,56,201,
81,123,237,252,54,32,64,220,48,86,215,115,185,183,207,77,234,117,172,175,173,183,143,141,31,207,197,19,241,36,32,106,68,14,118,93,41,153,169,137,169,52,0,41,204,237,202,30,232,89,1,65,39,56,192,193,16,
224,194,32,214,204,115,107,80,37,144,52,173,84,38,14,69,166,231,132,224,202,1,164,138,207,72,8,217,184,129,111,244,55,169,249,198,5,207,77,202,221,172,4,6,0,88,95,95,111,143,143,143,231,18,137,68,18,192,
5,67,28,88,211,33,178,205,100,136,135,164,208,155,220,183,7,35,253,93,146,22,30,36,34,200,159,22,34,70,17,112,106,175,9,119,97,113,49,36,153,236,60,242,17,34,69,2,224,12,128,249,122,151,192,134,97,172,
230,243,249,155,151,192,0,0,185,92,174,61,126,236,88,46,30,55,146,64,78,128,162,196,19,25,20,183,91,94,144,81,186,73,117,20,50,40,146,143,205,134,205,82,145,227,247,0,193,134,199,20,18,200,12,211,165,
192,151,146,80,48,187,129,228,44,144,64,250,173,44,34,72,130,39,249,208,37,65,237,86,34,176,75,228,177,209,177,156,17,55,82,128,232,33,94,157,74,185,150,156,232,98,215,158,11,133,16,134,246,7,172,154,
232,84,39,10,157,9,40,6,155,200,239,73,77,20,26,132,15,215,186,20,62,236,1,67,208,56,226,96,82,1,109,145,57,87,78,32,242,57,56,102,196,86,55,54,54,222,126,43,250,32,136,151,97,24,141,114,169,252,116,127,
255,0,42,199,135,135,112,175,16,171,175,175,40,245,245,149,23,179,159,251,226,253,54,128,202,67,127,161,226,175,87,60,202,75,66,71,209,183,69,169,73,57,159,66,235,161,162,36,101,21,133,13,64,162,112,144,
218,237,102,23,144,30,76,66,225,68,37,35,199,139,195,242,199,14,82,225,175,222,36,4,134,137,137,9,181,217,108,218,237,118,107,45,142,164,144,109,35,99,44,97,217,214,80,167,82,50,251,79,78,13,17,128,226,
37,123,115,240,33,15,37,82,88,95,177,40,88,58,204,136,70,57,137,143,132,41,100,65,212,148,184,74,12,89,231,19,132,37,237,120,239,22,166,173,4,109,5,97,83,113,166,72,109,233,213,109,34,2,195,136,175,110,
110,110,222,18,28,12,201,100,138,24,99,172,82,169,52,42,149,202,143,251,251,251,21,4,48,136,8,235,235,43,217,2,192,210,200,3,15,207,147,10,170,101,219,224,143,58,247,59,189,118,225,101,110,106,56,55,136,
204,107,164,230,225,21,156,111,73,46,86,236,91,213,252,228,110,167,137,47,23,130,22,199,228,130,52,143,28,57,254,116,145,52,129,11,137,4,204,153,48,204,111,118,30,75,83,222,17,17,168,219,9,150,232,0,44,
124,211,112,240,213,171,87,216,29,119,222,161,160,130,96,196,140,78,171,217,90,49,98,177,132,162,160,143,120,85,43,213,228,196,84,154,0,20,219,102,33,92,233,183,15,230,51,89,5,191,210,11,73,114,186,147,
194,34,191,62,191,241,134,156,208,62,152,122,233,243,136,121,12,120,192,92,179,168,224,1,42,96,190,126,126,19,0,88,44,22,91,219,218,218,250,209,45,193,193,0,0,63,253,201,79,5,196,235,204,153,51,79,197,
227,134,109,24,70,147,8,168,158,91,201,210,115,108,105,248,193,135,231,73,85,52,219,182,196,16,27,16,135,5,131,147,95,207,55,70,21,81,48,116,115,180,144,31,201,23,2,74,145,128,56,122,98,255,77,145,138,
66,220,43,23,72,113,235,98,228,112,24,248,111,68,84,137,136,8,17,45,34,106,239,247,19,84,184,137,143,173,173,173,246,112,122,36,103,196,141,36,0,120,126,178,85,41,155,169,137,169,52,17,250,126,50,248,
152,179,152,86,229,155,212,232,181,121,8,90,186,60,72,134,33,152,68,212,176,45,10,24,85,145,102,94,196,231,36,111,73,2,162,229,233,112,154,170,82,229,210,43,91,136,216,212,52,237,242,206,206,206,207,0,
192,190,37,9,12,0,176,189,189,221,30,30,30,206,197,98,177,36,1,105,196,40,222,44,57,68,62,121,42,77,64,138,109,115,196,245,22,13,67,97,143,0,25,34,50,23,9,34,140,98,47,104,136,97,208,21,132,197,70,2,146,
96,159,9,155,129,6,165,92,10,143,174,169,172,124,233,149,109,69,81,170,154,166,189,177,179,179,243,204,45,77,96,159,200,233,92,76,143,249,156,236,96,215,125,19,167,210,68,78,102,136,80,117,75,28,202,37,
57,83,252,120,27,22,130,49,242,212,135,144,178,65,10,247,121,189,132,61,12,203,107,150,42,41,16,184,164,192,96,21,134,159,21,2,130,133,174,35,118,202,175,157,47,170,170,90,208,52,237,210,206,206,206,175,
161,71,89,241,45,65,96,0,128,157,157,157,118,58,237,16,25,65,35,2,39,64,81,54,251,78,78,165,137,72,225,227,201,20,30,179,11,44,99,32,212,200,219,93,40,129,28,210,12,35,175,28,73,206,9,11,102,186,134,96,
210,82,3,102,228,97,76,255,36,114,11,241,198,210,197,213,230,206,150,173,105,218,186,174,235,23,118,118,118,94,233,165,135,111,25,2,3,0,20,10,133,246,96,122,48,167,235,177,20,0,105,68,100,180,203,69,163,
83,41,213,82,142,117,237,18,57,180,138,130,100,104,49,196,114,230,58,202,9,89,184,36,142,159,245,85,37,137,145,75,39,97,142,48,172,68,69,172,184,32,62,90,21,58,164,210,213,207,221,157,20,139,197,104,231,
23,63,90,7,64,59,22,139,93,213,84,245,133,237,157,157,229,94,107,166,193,173,117,144,174,233,141,90,181,250,116,50,153,66,237,248,200,80,163,88,140,213,214,87,148,218,250,202,139,19,159,251,47,247,119,
108,91,229,167,151,130,64,4,17,10,244,199,223,4,27,43,4,36,129,91,123,132,32,230,82,243,207,113,224,133,239,192,242,21,18,225,176,42,143,109,97,152,222,239,246,130,0,21,129,49,98,154,170,168,123,136,138,
217,104,182,94,186,165,173,232,176,99,116,116,84,109,117,218,182,101,89,107,154,109,41,100,117,144,136,18,140,177,33,171,82,50,251,167,166,135,92,113,205,231,30,131,28,226,227,45,106,215,209,18,42,30,
65,76,159,68,10,6,3,32,42,68,25,222,205,126,223,99,63,191,171,92,44,84,175,45,55,52,77,203,105,170,246,202,242,242,210,207,96,159,182,30,183,26,7,67,220,48,136,49,198,26,141,70,163,94,171,255,56,145,76,
40,224,32,94,181,245,149,44,17,44,13,63,184,56,79,68,170,109,89,224,143,161,241,139,178,187,162,215,25,71,70,114,38,14,159,28,128,130,101,46,100,62,2,30,32,39,42,12,37,15,137,100,9,35,104,252,218,103,
4,244,126,74,220,48,40,247,211,31,108,0,0,40,138,178,139,10,230,97,255,158,45,183,30,7,111,108,110,178,137,137,172,2,136,160,235,90,167,221,105,175,232,170,150,0,5,227,196,64,109,149,138,134,85,45,85,
251,79,78,167,25,145,98,51,219,179,169,73,80,131,20,146,239,20,12,24,4,244,54,248,92,28,72,193,9,139,106,69,203,100,209,236,35,209,18,247,136,235,236,60,67,83,218,229,75,175,84,21,69,45,24,70,236,42,17,
253,96,111,111,111,231,182,35,48,0,192,230,230,22,219,45,20,236,66,161,96,23,139,197,118,255,192,192,186,166,107,49,236,230,88,27,173,82,209,232,84,75,102,255,196,116,154,1,41,221,73,225,65,253,122,93,
88,84,212,28,90,174,20,80,152,4,46,75,118,207,88,243,55,155,156,63,72,178,203,229,60,50,244,24,229,190,245,245,87,136,8,117,93,187,170,105,218,185,203,151,47,255,232,32,63,254,150,36,176,124,148,74,165,
118,127,127,127,78,211,180,36,32,104,140,88,188,93,42,26,157,74,201,236,159,116,57,153,113,92,74,82,104,192,143,80,241,156,45,122,60,36,116,211,9,171,31,34,169,241,7,133,249,194,33,125,66,66,225,76,110,
134,110,92,87,219,165,139,175,212,20,69,217,141,197,98,203,170,170,62,183,183,183,119,249,32,107,115,91,16,216,37,114,95,127,95,78,83,53,15,12,113,2,20,230,192,201,83,105,155,35,178,76,56,144,96,72,58,
0,143,239,11,76,70,128,92,161,207,147,36,167,185,70,96,137,184,193,214,158,252,218,171,64,68,154,174,95,209,52,237,229,43,87,174,60,113,16,253,123,91,17,24,0,160,92,46,119,137,172,139,68,182,170,21,179,
255,228,169,52,57,68,222,175,152,19,66,136,29,104,227,32,116,97,35,193,50,151,145,14,177,234,149,132,172,61,10,83,228,222,188,106,4,165,82,218,169,92,93,178,20,85,221,136,233,250,178,162,170,207,150,74,
165,203,7,93,147,219,138,192,0,0,149,114,165,157,76,165,114,186,166,37,137,64,3,160,120,171,236,136,107,199,240,10,246,120,36,136,194,36,4,239,197,235,235,33,85,40,10,45,158,40,160,155,249,216,111,160,
189,68,100,30,48,65,42,30,239,172,253,224,155,235,8,80,215,117,125,73,211,180,115,215,174,93,123,242,160,220,123,91,18,24,0,160,90,169,180,83,169,84,78,83,213,20,0,104,140,152,209,46,151,12,171,82,174,
249,156,108,11,139,237,215,129,5,203,82,66,147,233,248,186,100,10,202,93,66,12,233,204,206,3,145,24,9,168,18,0,36,19,9,182,246,205,175,158,7,0,69,211,180,171,186,174,47,1,192,247,43,149,74,225,122,214,
226,182,36,48,0,192,208,208,16,53,91,205,117,93,215,147,198,232,177,81,102,219,90,115,119,91,175,92,122,101,99,232,158,251,142,3,32,50,70,40,148,202,240,174,20,74,216,114,68,93,148,136,63,115,21,136,36,
182,83,245,252,113,129,129,229,233,225,221,47,141,199,227,148,251,230,87,127,3,0,9,69,81,214,116,93,95,86,53,245,87,107,107,107,191,130,235,12,65,223,182,4,238,239,239,87,45,219,178,153,101,175,97,187,
165,48,171,3,68,100,48,70,3,118,87,39,15,41,138,162,16,1,50,155,111,102,230,67,155,124,111,76,185,52,156,2,9,233,124,168,146,4,68,76,200,36,129,96,189,21,111,137,199,13,131,170,47,62,247,122,171,180,167,
43,138,178,161,235,250,146,170,170,207,175,175,175,127,243,122,68,243,109,79,224,145,225,17,133,128,192,182,108,219,178,237,181,174,11,133,10,0,139,181,202,69,189,93,44,152,125,19,83,131,138,170,42,4,
216,29,161,11,36,137,77,10,105,165,138,66,72,15,132,176,228,111,135,68,38,227,9,170,191,126,225,74,121,233,98,71,81,148,109,77,211,222,80,85,245,165,124,62,255,85,232,17,243,125,71,18,184,84,46,177,225,
244,176,2,0,160,170,106,199,182,237,85,85,193,164,211,15,67,109,155,21,173,185,153,55,147,199,78,36,117,195,208,80,81,176,99,89,142,52,197,144,236,13,174,123,29,87,223,68,225,78,210,190,174,149,156,6,
219,151,72,176,221,103,158,190,84,189,118,217,82,16,61,226,218,182,253,79,245,122,189,254,102,215,225,182,37,176,227,54,49,211,52,109,211,52,237,90,173,214,78,38,147,235,170,162,196,1,192,2,34,176,26,
117,165,182,122,173,1,196,172,196,200,120,82,85,53,21,17,209,118,10,192,69,226,200,65,95,12,192,38,97,148,13,203,131,119,15,5,17,116,85,131,100,60,110,173,126,243,171,175,116,106,166,170,32,110,170,170,
250,134,162,40,47,49,198,158,44,20,10,123,191,205,26,220,214,4,150,143,90,173,214,54,12,35,167,40,138,6,0,77,0,232,48,171,163,53,182,54,88,121,233,98,105,224,212,76,74,55,98,138,170,170,104,219,204,105,
150,203,66,50,55,192,107,47,28,218,16,151,128,139,41,75,141,212,168,155,25,169,40,10,196,13,131,41,13,179,184,254,189,127,186,66,0,138,162,40,235,154,170,46,169,170,122,142,217,236,219,187,187,187,59,
240,219,164,96,190,211,8,12,0,208,104,52,218,134,97,228,17,177,3,136,45,32,104,33,130,70,140,105,149,165,75,21,178,237,142,110,36,40,150,74,197,52,77,3,69,81,0,16,176,155,166,235,15,156,230,147,240,8,
248,92,107,191,203,157,95,16,217,245,153,53,85,131,88,76,39,35,166,83,12,161,181,245,244,191,188,190,119,241,37,19,0,107,138,162,172,168,170,186,172,40,202,243,157,78,231,27,197,82,177,244,219,18,151,
71,222,223,113,199,80,122,72,83,80,29,1,164,51,68,112,23,179,237,41,98,236,36,1,141,18,65,95,223,212,204,80,98,252,68,50,126,98,98,24,52,61,102,19,41,196,24,90,54,67,198,108,176,221,233,211,66,54,36,10,
132,85,21,165,123,83,85,66,68,82,17,9,154,141,90,225,133,103,214,27,219,155,29,0,176,20,5,119,81,81,214,20,69,185,162,40,202,197,189,221,189,239,190,89,131,234,136,192,33,135,17,51,212,100,95,234,62,32,
154,182,25,155,0,162,25,70,52,70,68,195,64,212,7,0,177,190,153,249,193,84,118,106,80,239,27,48,48,158,72,2,130,226,100,225,118,91,129,115,141,114,20,135,194,136,72,8,72,72,204,102,205,70,179,177,153,43,
151,95,191,88,234,212,170,29,68,108,35,98,25,17,54,81,81,55,21,128,37,64,124,190,84,42,189,250,102,92,161,35,2,31,96,29,134,6,135,134,9,216,9,0,56,77,12,70,9,216,113,98,112,12,0,198,8,168,143,136,226,
138,145,72,144,221,161,248,240,72,60,113,44,147,82,98,134,138,170,166,168,49,67,67,77,87,201,238,216,118,171,101,145,109,49,171,81,183,234,235,171,213,86,185,216,6,0,66,196,14,0,52,17,177,130,136,91,136,
176,129,168,228,17,225,90,187,99,253,170,81,175,55,15,67,36,31,17,120,159,245,232,239,239,31,0,128,33,68,156,38,162,19,68,52,78,68,131,64,144,38,160,65,0,72,1,80,12,0,85,2,80,17,64,245,106,18,252,204,
123,155,0,24,34,89,0,216,6,128,26,32,150,21,132,61,0,44,34,42,219,0,116,197,182,237,215,234,245,122,237,70,16,246,136,192,251,175,11,166,250,82,131,8,56,10,64,105,0,60,6,0,253,68,212,71,4,241,46,145,65,
115,110,10,249,195,6,24,0,90,4,208,65,128,54,34,54,129,160,134,8,101,2,220,2,160,13,70,108,167,81,111,116,110,36,97,143,8,124,29,107,148,72,38,84,102,19,42,8,6,32,246,59,68,213,1,64,71,0,157,248,62,222,
93,80,171,3,224,221,218,68,84,110,54,155,109,56,120,11,204,35,2,223,4,28,126,208,131,142,150,235,232,56,58,142,142,163,227,232,56,58,142,142,163,227,232,56,58,110,165,227,255,3,64,27,108,248,155,155,196,
178,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LivePanelComponent::reverse_2x_png = (const char*) resource_LivePanelComponent_reverse_2x_png;
const int LivePanelComponent::reverse_2x_pngSize = 14756;

// JUCER_RESOURCE: bally_2x_png, 18303, "../Images/Bally@2x.png"
static const unsigned char resource_LivePanelComponent_bally_2x_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,200,0,0,0,120,8,6,0,0,0,183,146,189,235,0,0,0,1,115,82,71,66,0,174,206,28,
233,0,0,0,6,98,75,71,68,0,149,0,58,0,58,15,85,170,235,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,219,10,29,21,18,30,196,248,253,132,0,0,32,0,73,68,65,84,120,218,237,
189,121,172,100,231,117,39,118,206,119,239,173,237,213,219,151,126,107,247,123,175,187,217,27,187,73,170,69,54,73,137,148,108,197,162,99,103,16,193,113,44,39,35,39,14,226,0,1,2,100,48,65,96,120,252,215,
140,97,100,128,113,146,129,39,3,68,35,216,146,29,104,198,137,103,98,56,136,39,35,107,180,144,18,37,138,164,68,82,36,155,221,236,237,45,245,222,171,125,223,239,242,157,252,81,203,253,182,106,146,98,115,
85,125,134,204,126,245,234,221,170,186,245,157,239,156,243,59,191,243,59,0,227,53,94,227,53,94,227,53,94,227,53,94,227,53,94,227,53,94,227,53,94,227,53,94,227,53,94,227,53,94,227,245,17,94,56,190,5,31,
236,250,231,255,252,127,67,206,1,136,56,16,113,224,156,128,56,1,7,2,226,28,126,247,119,127,151,198,119,105,188,62,150,235,207,254,236,207,241,107,95,251,218,61,63,132,254,224,15,254,0,255,225,63,250,135,
227,195,109,236,65,62,122,235,235,95,255,58,126,233,75,95,122,219,167,254,175,254,234,83,108,121,113,21,3,34,224,72,0,132,240,208,165,135,232,229,151,95,70,14,1,220,255,224,5,254,123,255,227,239,189,173,
235,253,254,63,248,7,248,63,253,227,127,60,246,56,99,3,249,240,172,191,252,203,255,11,9,8,190,248,27,191,169,109,204,175,255,171,127,141,94,183,105,87,170,149,104,173,82,113,90,237,182,99,199,39,226,20,
4,9,159,40,230,241,192,34,78,54,17,217,192,24,227,60,64,226,4,128,72,220,247,136,136,8,17,93,36,234,2,231,93,7,161,235,251,126,11,145,181,152,133,158,235,186,124,126,113,209,255,195,127,244,7,124,252,
77,140,13,228,67,181,254,205,191,249,215,248,235,191,254,159,106,70,241,175,254,226,235,78,181,82,139,213,235,141,105,34,154,234,122,254,130,199,131,37,215,245,166,189,118,203,246,61,63,18,4,126,194,247,
253,8,15,184,29,112,110,19,16,35,206,89,16,4,72,68,64,64,132,189,175,198,7,34,31,17,61,64,244,236,104,140,51,139,53,45,203,174,3,98,131,49,44,97,224,151,16,176,18,113,156,114,50,18,105,253,225,31,253,
145,102,44,127,255,239,255,15,248,79,255,233,255,58,246,44,99,3,121,239,215,95,253,213,255,141,191,246,107,255,137,180,217,254,207,191,252,139,104,165,84,153,234,180,59,51,29,207,63,230,6,193,154,219,
237,44,184,157,238,100,183,221,154,246,125,127,198,243,188,73,223,247,227,126,16,56,129,239,59,156,115,139,69,99,49,230,56,22,15,56,0,2,99,204,66,2,0,206,57,240,32,224,60,240,57,113,30,120,237,182,71,
60,240,24,162,207,24,235,50,198,90,136,88,103,204,170,58,241,120,219,137,70,43,12,32,3,196,15,29,198,50,136,88,155,72,38,106,127,244,79,254,103,87,124,159,127,239,191,255,123,248,199,255,236,143,199,134,
50,54,144,247,102,253,245,95,255,53,126,225,11,95,24,110,176,175,254,233,159,36,59,93,119,201,117,221,141,46,231,27,173,86,123,165,93,173,78,117,221,238,98,215,117,103,221,110,55,225,121,94,60,96,44,25,
155,154,77,78,44,44,77,68,39,146,54,115,28,59,62,57,21,77,206,206,68,157,72,196,34,14,128,12,145,89,22,34,34,4,65,0,129,239,243,128,7,196,253,128,218,205,186,87,56,56,104,52,242,217,86,224,251,224,117,
58,94,187,82,106,120,141,70,195,178,173,182,109,219,13,219,182,75,182,109,231,236,88,188,26,113,156,60,242,96,7,17,15,108,219,46,125,249,203,95,174,141,191,189,177,129,188,111,235,43,95,249,74,12,17,55,
187,221,206,118,189,221,217,106,54,26,107,221,86,107,161,209,104,204,119,218,157,73,31,113,42,54,53,51,25,157,158,137,207,172,111,36,231,87,86,147,137,228,100,36,234,68,24,99,8,136,0,8,8,140,33,18,0,32,
1,112,232,219,29,17,12,254,201,161,247,111,78,4,126,224,83,16,112,8,2,31,92,215,11,26,205,134,95,56,72,53,50,55,174,87,43,135,251,141,192,237,54,25,96,35,226,56,181,72,52,82,117,162,177,180,229,68,143,
28,6,123,142,227,236,34,64,234,43,95,249,74,125,252,237,141,13,228,61,91,95,251,218,215,18,190,239,175,4,65,176,221,104,54,239,175,55,26,91,213,114,121,190,217,104,206,117,221,110,18,35,209,153,149,139,
15,45,44,109,109,79,39,39,167,156,72,36,98,57,142,13,22,50,4,32,160,129,13,0,193,224,135,222,127,168,103,19,125,227,24,184,168,193,243,104,232,179,194,231,17,1,248,65,64,174,231,66,163,217,246,106,197,
130,155,190,115,171,158,190,246,122,177,91,45,87,109,219,174,69,34,209,98,124,34,145,143,38,18,41,43,8,222,180,44,235,38,50,76,255,233,159,126,181,49,254,54,199,6,114,207,214,223,252,219,191,153,40,151,
74,203,205,102,107,163,209,233,158,235,118,59,219,229,124,126,185,82,169,172,180,219,237,153,169,141,205,185,141,139,15,206,206,175,172,78,76,36,19,182,99,217,216,219,199,131,221,78,138,33,132,143,209,
208,115,136,207,3,193,16,72,54,142,190,5,17,245,127,63,248,45,113,232,184,46,213,234,77,175,148,203,116,247,95,127,181,156,121,237,229,140,227,56,149,88,60,158,141,199,19,105,43,226,236,58,140,221,176,
109,107,39,26,141,30,124,249,203,255,194,29,127,187,99,3,249,153,215,239,253,254,239,91,151,238,191,127,169,221,110,159,105,180,91,103,107,149,234,90,163,94,95,173,215,235,75,205,102,115,209,158,156,158,
59,241,240,99,243,27,39,79,207,36,226,81,134,160,158,254,178,87,24,110,113,30,230,201,119,125,140,66,79,51,248,53,66,104,52,146,103,25,70,104,189,191,110,181,219,180,127,231,118,253,234,183,255,246,168,
85,204,151,29,199,41,69,163,209,76,108,34,113,16,113,34,59,142,101,189,201,144,221,254,243,255,227,207,243,227,111,122,244,178,198,183,192,188,190,250,213,175,70,23,23,23,238,107,119,187,159,168,84,107,
159,44,21,10,103,139,133,194,169,106,181,186,78,177,248,234,246,167,62,123,226,220,19,159,89,94,91,91,159,136,70,108,68,225,172,233,157,238,195,189,11,124,112,18,17,233,103,82,255,33,162,222,111,168,111,
0,56,120,80,124,26,134,94,73,51,68,144,31,119,28,11,231,23,23,163,43,103,47,204,76,174,31,159,238,120,94,178,146,62,140,248,174,55,21,4,254,36,1,206,16,241,228,165,75,151,220,215,94,123,173,60,120,157,
223,249,157,223,193,151,94,122,105,188,1,198,30,100,244,250,230,55,191,145,204,102,115,231,171,141,230,149,122,165,178,85,40,20,54,170,213,234,177,137,181,141,213,141,7,46,47,205,46,46,197,39,226,9,203,
98,136,131,93,201,165,83,127,24,36,1,23,54,62,40,39,63,245,50,112,0,196,208,43,0,1,17,15,173,6,6,142,40,244,52,40,62,134,66,168,37,120,17,128,240,181,56,231,80,111,182,248,222,205,55,43,87,191,245,141,
3,191,213,40,70,99,209,76,114,114,234,40,98,89,111,68,34,145,23,156,104,228,250,215,190,250,53,127,252,237,143,61,200,221,141,227,91,223,154,207,100,50,151,171,181,218,19,165,124,225,108,54,155,221,174,
86,43,107,43,159,184,178,117,230,177,79,175,28,91,58,22,143,70,163,140,49,192,240,212,38,249,204,17,14,127,4,49,79,232,239,123,41,239,0,45,180,18,61,13,1,104,143,233,238,71,189,6,201,79,71,128,72,36,130,
11,75,75,241,217,173,147,211,245,106,213,174,166,143,34,174,235,198,17,217,36,32,78,19,39,254,200,39,31,41,189,252,202,203,99,35,25,27,136,190,190,243,221,111,91,191,241,197,47,174,229,178,185,71,42,213,
234,167,114,233,236,125,185,92,110,171,237,186,75,103,159,250,143,182,182,239,191,52,63,153,136,91,164,134,82,162,121,8,161,142,244,144,156,48,104,91,124,232,57,196,107,12,188,4,0,224,112,183,147,96,22,
114,248,37,38,240,198,92,166,31,162,77,77,78,218,11,155,155,147,62,218,78,238,206,45,230,121,110,156,56,143,35,99,211,156,115,235,204,125,103,90,215,174,95,27,163,92,99,3,9,215,211,207,60,19,205,164,51,
103,42,213,234,149,74,169,244,112,58,157,62,93,44,20,54,35,11,199,86,238,127,234,239,156,88,63,113,34,57,64,166,250,113,142,124,94,147,106,4,131,148,28,135,135,188,106,67,10,46,165,93,131,64,247,46,40,
25,92,223,30,80,125,46,133,6,35,190,54,245,8,44,128,0,177,72,140,45,172,173,37,99,75,203,177,163,27,215,201,237,180,19,60,8,162,192,216,148,109,177,248,133,243,23,218,111,92,123,99,152,151,252,214,111,
253,22,190,250,234,171,99,3,249,121,92,207,124,247,153,100,54,147,185,88,111,54,62,85,41,151,31,60,58,58,60,85,46,151,55,230,206,221,191,126,254,51,159,91,89,90,88,136,33,162,98,28,56,68,139,76,62,161,
183,65,81,243,19,36,249,11,84,194,51,10,195,51,197,67,201,222,103,24,187,13,243,27,241,113,14,189,194,35,192,32,183,49,123,45,199,178,113,126,105,41,62,189,177,153,200,31,30,80,179,82,142,5,190,31,101,
142,51,135,4,241,251,47,93,242,30,120,240,129,210,235,175,189,198,127,94,141,227,231,222,64,190,255,189,103,230,211,153,163,203,149,90,237,201,92,190,112,127,250,232,104,171,90,173,173,174,94,126,116,
237,236,149,199,143,77,37,19,54,132,169,134,114,174,163,158,11,128,156,44,15,79,110,52,184,4,229,47,193,24,138,145,244,240,48,43,161,240,181,80,10,173,72,122,222,200,240,174,255,36,134,0,51,51,179,145,
217,173,173,100,189,90,195,74,250,200,241,186,221,8,48,76,34,194,20,16,241,79,124,226,161,210,107,175,189,230,3,0,124,241,139,95,196,11,23,238,199,171,87,175,142,13,228,227,188,158,125,238,135,214,127,
246,155,191,185,154,205,102,31,41,87,171,159,202,164,211,167,179,153,204,102,179,217,92,90,121,232,145,133,83,159,248,228,66,50,17,183,229,195,91,40,218,137,121,2,41,123,27,229,124,128,12,22,33,61,79,
76,47,80,216,191,40,196,80,178,169,72,63,163,132,94,133,143,209,48,254,146,125,20,244,107,43,125,240,12,8,0,146,19,19,246,252,241,173,164,111,217,86,238,246,77,244,60,47,70,68,113,64,156,230,1,103,39,
79,158,108,223,188,121,179,121,122,125,19,88,196,182,47,92,184,192,206,157,59,71,215,174,93,27,27,200,199,206,56,126,248,195,72,38,157,62,91,175,213,174,20,75,165,71,211,71,71,167,242,249,194,102,100,
241,216,218,249,167,254,206,198,214,217,243,179,241,88,196,2,82,194,34,2,64,196,225,238,150,80,34,50,66,82,250,143,66,82,143,90,88,214,171,125,144,246,71,24,134,90,128,10,164,43,108,125,82,60,154,232,
182,52,199,55,64,218,194,95,196,163,81,54,191,182,150,140,45,46,199,210,183,110,244,242,18,30,68,17,217,52,99,86,252,190,51,103,58,169,236,97,253,59,223,254,182,127,254,220,57,11,16,172,179,103,207,242,
235,215,174,143,13,228,227,178,158,251,209,115,201,92,54,119,177,222,104,60,89,42,149,30,60,76,165,78,149,74,165,227,201,141,205,149,11,159,253,165,149,165,197,197,24,99,56,220,165,124,80,176,19,44,65,
179,139,225,230,150,79,121,18,178,144,81,207,19,210,105,221,63,16,128,230,176,208,236,125,228,136,142,4,183,210,123,69,57,212,34,205,182,6,255,112,108,27,23,150,142,197,167,143,111,38,10,7,41,106,148,
75,49,30,4,81,230,216,115,118,52,58,53,59,191,232,31,91,156,47,253,187,127,247,13,111,125,125,221,138,69,99,112,237,218,53,26,27,200,199,96,61,255,252,11,243,71,71,71,151,203,213,218,147,133,108,246,236,
209,225,225,86,181,86,91,157,222,60,57,127,223,227,79,46,205,205,206,70,165,77,214,63,110,81,220,88,70,248,86,12,143,72,123,236,238,224,174,41,9,145,47,51,170,146,139,66,26,36,131,192,163,255,72,244,134,
36,7,99,97,120,134,8,179,179,51,145,217,205,147,201,70,189,134,149,244,161,19,184,110,36,177,112,108,213,78,36,22,45,223,107,108,109,111,87,255,253,55,191,217,190,118,237,218,199,190,147,241,99,111,32,
63,121,249,37,235,75,127,247,63,95,203,102,179,143,20,203,149,79,101,210,71,167,179,217,236,86,219,245,142,221,247,249,95,57,113,250,242,195,75,83,19,73,71,205,51,72,67,159,48,44,115,160,158,21,160,105,
35,42,187,93,206,149,123,48,212,224,202,162,193,153,131,48,195,149,251,30,46,164,169,8,191,227,164,32,97,189,103,32,41,213,20,17,141,27,84,240,129,250,121,201,118,210,67,100,133,221,59,204,237,116,108,
34,138,115,207,77,216,150,101,159,220,222,110,221,190,125,187,62,54,144,143,240,122,241,39,47,69,211,135,135,103,42,213,234,163,249,66,225,74,250,232,240,84,62,95,216,180,231,22,86,206,127,254,63,220,
88,221,56,158,116,172,94,23,159,140,20,153,67,121,12,211,2,97,211,203,129,21,18,106,201,57,145,33,205,54,121,157,97,18,13,250,27,25,97,116,114,194,78,106,166,46,120,64,249,115,136,89,62,10,54,43,154,96,
44,26,97,11,235,27,201,232,194,82,116,239,229,31,251,157,122,45,194,131,32,110,57,206,60,34,38,78,159,62,213,188,117,235,246,176,94,242,133,47,252,199,120,253,250,155,99,3,249,40,172,87,94,122,41,153,
201,164,47,86,106,245,39,203,165,226,197,163,195,195,147,197,82,105,99,246,244,249,245,179,79,124,118,101,126,110,62,142,106,9,15,201,24,203,244,78,106,57,132,25,60,166,134,51,234,99,68,134,68,153,70,
161,92,52,26,69,86,173,248,46,32,0,16,26,174,139,138,135,19,192,6,49,238,34,217,99,58,182,141,115,11,75,49,123,118,206,58,188,250,42,247,61,127,202,247,60,27,25,155,98,200,38,238,187,239,76,247,204,185,
211,165,155,55,110,241,143,155,113,124,108,13,228,149,151,95,153,63,60,58,188,92,170,86,159,40,20,242,231,143,14,15,55,43,149,202,234,250,149,79,31,63,245,137,203,75,147,19,9,91,173,19,104,197,112,45,
160,17,96,210,254,102,67,0,101,131,145,124,58,143,74,192,37,244,169,143,183,42,175,138,134,192,138,12,219,93,34,45,14,158,139,122,238,129,202,59,34,195,73,32,254,173,248,89,45,134,184,180,188,154,88,58,
127,113,178,217,168,179,74,250,40,18,4,129,3,128,9,64,156,2,34,126,254,220,185,210,141,27,55,253,177,129,124,136,215,171,215,94,181,254,203,255,226,183,215,50,153,204,149,98,185,242,233,163,131,131,251,
50,71,233,173,70,163,177,120,234,151,126,229,248,230,153,115,115,177,136,195,136,104,228,38,150,226,34,53,209,30,244,199,106,70,37,120,24,18,55,23,201,7,190,248,67,255,186,52,32,4,19,25,223,11,145,14,
14,32,134,220,45,205,4,105,196,231,0,115,77,70,51,76,197,130,184,16,150,245,120,92,219,9,159,49,204,239,220,198,32,240,98,196,121,28,16,167,137,200,218,216,216,104,237,237,237,53,198,6,242,33,92,87,95,
125,35,122,116,120,116,166,92,169,60,90,44,22,175,28,164,82,39,243,185,252,166,135,184,184,245,233,207,46,174,159,60,61,27,117,108,102,220,44,168,134,59,242,153,45,23,3,117,72,23,32,76,150,239,190,7,245,
212,95,254,35,185,230,65,156,70,32,82,97,55,34,154,109,90,130,155,141,1,22,153,65,4,148,18,21,28,246,160,12,62,115,44,26,101,11,107,27,201,248,210,114,236,232,198,155,228,117,219,9,226,20,37,196,41,139,
177,248,214,246,86,123,119,103,119,152,151,124,254,169,207,179,219,183,111,211,216,64,62,192,117,237,234,213,228,97,230,232,98,185,86,123,178,82,42,93,76,165,82,219,165,98,113,99,230,244,185,245,11,159,
123,106,117,121,109,125,210,177,24,27,110,15,101,115,16,25,207,110,32,45,185,32,179,195,33,211,6,22,67,39,193,24,144,129,206,0,134,144,146,98,202,190,123,103,185,41,6,84,226,60,241,119,92,79,144,104,244,
62,37,153,19,172,85,231,197,235,59,246,128,199,181,149,40,28,30,80,171,82,142,241,32,136,90,142,51,7,68,241,237,147,219,222,169,83,39,43,119,238,236,4,75,75,75,206,153,51,103,173,173,173,45,216,217,217,
161,177,129,188,207,235,141,107,215,230,15,14,15,47,151,202,229,39,10,249,252,249,131,84,106,179,82,169,172,174,62,252,248,241,147,15,93,94,74,38,18,246,128,108,72,35,66,13,50,109,238,17,134,96,10,105,
212,19,90,45,135,136,124,46,84,0,44,173,134,97,176,1,9,210,29,185,185,85,50,188,30,31,146,10,203,9,215,53,190,1,149,76,41,252,140,128,48,59,59,27,153,219,220,78,214,106,189,122,137,239,121,17,0,72,2,178,
41,226,156,175,173,173,215,222,120,253,170,59,145,156,128,72,52,194,54,55,55,97,119,119,151,198,6,242,62,172,221,55,175,91,191,253,95,255,206,90,58,157,190,146,47,149,63,157,62,56,184,47,125,120,180,85,
175,215,23,79,254,226,47,31,63,113,246,220,92,204,113,152,140,208,144,6,225,170,198,16,50,113,105,228,166,13,209,36,52,164,242,42,40,75,122,40,102,124,53,249,49,50,180,230,18,146,236,52,196,199,70,88,
189,86,63,65,67,40,73,24,246,163,72,142,137,116,168,90,169,211,36,39,38,236,249,19,155,73,223,114,172,252,157,155,232,251,126,140,56,143,51,39,50,231,76,36,99,179,11,11,205,27,215,94,175,3,0,79,78,78,
226,230,214,38,237,238,238,142,13,228,189,92,183,110,221,138,238,31,29,158,41,150,203,143,22,11,197,43,135,251,251,39,179,185,236,166,11,184,184,249,248,103,22,215,79,158,154,117,108,155,169,167,188,20,
194,160,26,91,145,153,83,37,96,60,42,6,68,134,132,26,181,80,199,240,79,25,47,214,176,41,99,184,167,229,62,2,98,69,82,219,135,202,125,12,233,41,98,74,67,61,88,91,126,76,68,227,80,242,72,40,97,207,216,163,
225,244,141,45,30,139,178,249,181,245,100,252,216,114,44,115,227,58,185,157,78,130,57,78,114,98,233,216,9,100,24,157,155,156,172,4,65,80,125,225,249,23,252,143,146,113,124,36,13,228,246,173,91,201,195,
195,163,139,165,74,237,201,114,177,112,113,127,127,127,187,88,40,108,76,159,58,187,126,238,23,62,191,122,108,117,117,210,182,45,102,68,165,148,100,88,101,150,147,122,242,138,249,129,70,53,49,213,17,250,
61,24,18,88,75,18,151,80,164,172,147,201,251,144,25,24,54,198,121,4,111,39,33,26,9,210,137,249,11,73,7,199,8,8,88,177,109,215,243,160,217,233,66,181,213,134,86,199,69,76,76,196,99,203,107,241,90,250,144,
183,43,229,136,219,237,48,10,130,41,240,253,88,44,26,235,110,31,223,42,238,165,246,62,82,244,148,143,148,104,195,237,59,183,231,83,169,212,3,165,114,229,74,54,147,61,149,205,164,215,106,213,234,210,202,
35,159,90,95,63,115,110,62,30,233,135,84,2,157,130,52,152,83,208,168,34,253,148,150,168,38,162,130,8,145,16,174,224,176,171,80,116,66,196,121,40,168,32,189,62,10,137,251,128,6,34,60,38,4,85,36,84,231,
135,94,67,85,94,236,73,49,42,180,24,232,139,71,112,129,78,2,146,182,150,70,69,65,249,119,3,212,172,213,238,66,203,115,161,235,122,208,117,61,112,57,7,215,247,122,146,168,156,128,7,188,15,79,243,62,85,
133,4,230,49,135,86,173,214,78,63,247,76,186,145,218,171,218,182,149,139,198,19,169,72,196,185,97,51,246,3,199,177,95,121,230,123,223,111,191,109,75,30,27,200,91,175,212,173,35,171,238,86,87,114,185,236,
67,133,66,241,147,233,244,209,118,38,155,217,104,119,220,185,237,207,126,126,99,121,99,99,218,177,45,228,164,114,141,122,140,92,181,79,155,212,124,68,20,113,35,181,13,86,77,218,41,44,206,169,173,179,92,
78,126,7,175,143,10,122,22,86,215,245,90,10,23,26,70,212,231,73,8,28,113,224,146,147,234,125,118,174,185,69,18,148,85,0,58,158,11,173,110,239,127,29,207,7,207,243,192,13,56,4,60,128,32,232,25,56,23,169,
254,92,244,158,164,25,176,166,254,72,189,233,88,221,122,189,157,122,250,155,169,102,246,200,179,44,171,16,141,70,246,162,177,248,109,139,225,143,56,167,159,190,248,226,139,217,177,129,220,139,100,252,
96,47,114,184,127,120,95,183,221,190,148,47,20,30,74,165,82,155,197,98,113,205,158,91,92,218,124,248,209,229,185,249,133,4,67,134,132,134,141,76,162,52,78,184,193,84,254,20,128,168,55,165,40,29,14,13,
74,216,220,74,114,175,27,67,8,179,114,18,34,138,126,151,18,39,46,37,218,128,20,254,173,88,7,33,46,20,31,7,137,4,151,228,71,165,207,65,4,1,39,104,116,58,208,234,184,208,241,60,232,250,30,116,93,31,2,62,
144,19,234,25,225,0,189,226,156,11,70,205,251,161,31,215,148,29,137,147,0,106,200,143,13,238,169,104,56,0,0,158,231,6,213,189,157,74,230,249,239,21,184,219,45,68,156,200,126,36,26,189,109,49,235,117,134,
248,226,139,63,126,241,206,224,181,31,123,236,113,124,238,185,31,210,216,64,222,193,218,223,79,37,143,142,14,207,23,171,149,199,42,165,210,233,253,221,189,19,229,114,121,37,190,122,124,241,212,99,79,44,
79,77,78,68,6,27,133,148,214,62,185,24,39,111,100,253,185,3,67,64,0,233,4,231,10,199,9,12,39,121,63,52,67,89,120,65,50,36,37,193,144,188,26,145,142,166,137,30,99,104,72,60,212,207,34,128,70,183,11,141,
118,27,58,158,15,29,215,3,143,115,8,130,96,120,109,49,156,27,26,195,48,44,236,25,11,246,147,237,208,179,202,94,200,180,233,9,100,163,1,193,104,136,212,67,169,103,248,205,124,182,118,248,131,103,178,110,
185,80,180,109,231,48,150,72,164,45,132,87,152,197,158,103,12,175,191,240,252,139,31,90,138,202,135,54,73,63,56,72,205,167,82,169,203,133,82,249,201,236,209,209,217,212,126,106,171,92,46,175,78,172,159,
152,223,190,242,216,210,244,212,100,84,220,167,82,69,25,239,146,240,106,222,131,244,150,109,48,36,234,198,148,153,12,61,24,116,247,196,216,244,20,4,131,92,79,15,34,170,117,58,80,110,52,33,87,171,67,182,
218,128,76,181,6,153,106,29,202,205,38,212,59,93,232,122,1,248,1,151,140,89,205,131,52,166,164,168,228,40,134,105,2,125,158,48,124,2,138,132,124,146,189,171,94,58,145,243,39,64,128,72,60,25,77,172,109,
36,188,86,19,90,165,124,36,240,189,8,32,38,1,113,10,56,241,19,27,199,75,7,135,135,62,0,192,229,203,159,196,213,149,21,76,167,211,99,15,98,90,233,92,198,106,214,27,43,185,108,47,223,56,60,60,220,206,100,
50,27,109,207,155,63,241,196,47,110,44,173,110,76,69,28,11,135,241,46,13,152,34,225,238,235,41,123,168,106,234,160,81,59,168,159,100,42,128,21,72,237,182,52,58,119,81,67,54,18,226,126,34,161,96,71,226,
9,45,34,66,161,178,98,171,219,133,122,167,11,173,174,7,109,207,133,128,7,192,131,65,8,67,192,185,210,135,72,48,12,153,164,156,128,15,54,52,31,230,85,195,252,70,56,241,67,0,32,84,128,36,234,39,248,82,206,
163,122,11,24,26,227,208,227,8,121,90,239,119,56,244,204,131,223,35,0,116,219,29,175,120,237,213,92,254,149,23,114,22,179,138,142,227,164,156,72,244,150,205,216,11,1,15,174,190,250,234,171,153,179,23,
78,67,34,146,180,123,151,10,130,87,126,250,42,141,13,164,191,50,217,76,36,149,74,221,215,105,119,46,229,10,133,135,14,246,247,55,11,133,252,154,53,187,112,236,248,39,31,61,54,55,191,144,64,161,210,102,
28,15,64,58,157,68,66,161,84,132,75,75,150,65,136,243,65,11,43,196,195,152,147,156,212,203,121,75,127,83,18,192,127,245,233,135,223,241,189,112,253,0,58,158,7,205,174,11,233,114,5,246,139,101,120,61,117,
4,71,229,170,57,212,25,20,13,7,159,133,147,38,28,55,108,162,82,255,118,240,24,239,135,113,210,99,131,80,141,15,13,62,108,198,226,97,81,149,135,57,23,14,27,177,228,251,70,0,224,123,46,175,29,236,149,210,
63,120,58,67,110,183,236,68,34,41,39,18,189,195,16,95,7,160,159,84,74,229,189,212,225,129,255,192,131,15,216,8,128,68,228,253,244,3,52,146,15,77,136,149,203,229,146,135,7,135,23,203,213,218,147,249,124,
254,193,189,157,59,167,242,249,252,70,116,121,99,249,228,167,62,179,58,59,51,19,7,20,235,92,4,138,190,179,153,146,36,170,130,152,56,237,154,84,143,32,248,118,151,18,195,128,125,75,166,198,38,225,250,141,
78,7,174,108,159,120,231,95,12,99,16,117,108,152,140,69,97,101,118,26,206,174,46,195,147,231,78,195,133,245,21,40,53,91,144,175,53,164,188,0,36,86,176,2,54,16,105,161,27,144,137,146,162,120,78,84,67,82,
249,254,201,148,25,210,10,148,114,127,73,63,186,99,12,99,83,179,137,248,202,90,172,85,200,81,183,81,143,115,30,68,209,178,231,152,19,157,140,79,77,249,147,137,68,249,218,27,215,188,153,153,89,203,182,
109,200,102,179,63,223,6,146,47,228,231,247,247,246,47,23,74,165,39,51,233,163,179,251,251,251,91,165,82,47,223,216,122,228,177,165,233,100,50,106,236,221,120,11,138,33,201,223,146,86,51,144,13,204,36,
253,41,84,248,200,144,135,40,165,241,174,239,67,169,209,134,124,163,1,217,90,3,114,213,6,212,218,93,248,165,11,247,221,179,123,53,51,145,128,43,167,54,97,113,42,9,175,238,29,202,39,180,202,33,27,20,35,
7,246,163,20,65,135,164,22,18,66,65,161,50,47,94,91,132,138,165,215,68,48,84,88,5,30,177,130,32,246,30,66,112,18,137,232,196,234,241,9,183,221,132,86,161,16,9,124,63,18,157,157,91,97,241,196,34,115,59,
205,249,249,133,234,245,235,215,219,217,108,246,3,45,44,218,31,228,139,55,202,37,171,210,104,174,236,238,236,62,148,47,22,31,62,60,72,109,101,210,153,141,150,235,206,111,254,194,83,27,11,171,107,83,145,
97,75,172,137,193,23,102,183,3,103,175,247,56,144,177,239,193,40,194,64,102,102,149,214,99,222,191,100,189,235,66,189,211,129,86,215,5,207,247,129,15,107,23,166,25,30,114,104,214,245,238,14,220,68,109,
27,24,27,29,1,95,57,181,5,113,199,129,255,253,223,127,175,7,225,170,142,142,244,182,92,146,164,131,122,201,27,242,112,243,242,209,182,31,166,233,4,6,30,203,224,224,66,181,4,51,164,232,136,117,148,1,201,
57,146,76,198,87,174,60,185,238,36,167,156,226,235,47,219,141,98,62,17,73,36,24,114,238,50,134,211,103,206,156,121,245,205,55,223,60,250,185,52,144,74,185,18,189,147,218,63,221,104,181,30,204,231,114,
15,28,30,28,156,200,229,114,235,108,122,110,233,190,135,31,91,158,155,155,75,32,34,14,18,81,157,33,107,72,150,85,225,29,2,67,145,80,24,178,108,26,89,160,80,71,196,195,177,218,110,67,181,221,133,142,231,
129,31,144,92,40,131,97,230,60,130,172,24,174,108,181,14,255,228,223,126,167,7,40,12,165,76,197,202,124,239,177,132,99,195,250,236,12,92,60,190,6,143,158,218,132,120,36,34,93,231,210,137,117,248,15,46,
158,131,111,188,242,186,16,57,133,116,23,49,228,211,253,42,13,107,30,18,205,6,13,69,77,49,2,163,176,53,89,4,27,72,12,201,16,164,251,34,241,195,176,159,187,245,31,176,162,17,103,241,226,39,86,163,51,115,
177,131,167,255,214,242,91,45,199,178,45,138,68,99,51,8,176,112,246,236,153,231,174,95,127,243,246,224,221,95,184,112,1,175,94,189,250,190,133,92,31,72,136,85,173,214,146,169,131,212,197,98,169,252,100,
169,144,191,184,183,187,123,50,159,207,111,36,183,78,175,111,61,242,216,202,244,244,116,28,77,220,110,141,88,40,118,192,210,91,24,209,136,132,66,65,186,194,223,34,84,59,29,40,52,90,144,173,215,33,95,239,
193,170,110,191,214,96,10,244,196,113,105,98,220,255,249,251,207,200,158,179,211,133,31,220,188,3,154,50,175,130,146,117,61,31,138,141,38,92,61,72,195,115,55,238,192,214,226,2,204,37,39,164,107,109,31,
91,128,103,222,184,1,158,31,40,8,93,255,130,164,180,210,146,54,177,71,190,65,72,186,23,18,239,95,31,8,192,1,231,204,8,145,143,112,67,106,97,182,143,114,33,99,24,153,158,137,71,166,102,161,186,123,139,
130,32,152,226,60,176,145,177,41,0,152,88,90,92,234,46,204,47,148,10,197,2,207,231,223,223,129,88,239,187,129,212,170,181,249,189,189,221,203,133,98,241,137,76,38,115,126,127,111,111,179,88,44,173,46,
62,244,200,241,227,23,46,45,37,226,49,219,148,21,27,11,127,134,28,99,176,59,112,68,200,161,126,129,36,132,80,45,207,235,27,68,19,242,245,6,212,187,93,112,253,30,255,72,144,8,209,5,221,196,19,84,26,135,
214,251,189,201,64,158,189,185,35,39,177,90,20,39,247,115,116,60,31,126,178,187,15,143,158,218,130,120,196,9,67,0,203,130,163,82,5,82,165,178,212,61,24,234,94,113,205,128,105,196,65,66,10,200,16,18,239,
133,1,63,20,166,226,226,245,36,195,27,122,66,3,194,39,235,179,10,71,4,98,116,118,54,57,185,117,102,194,239,180,177,83,204,71,57,231,14,32,75,0,192,20,0,240,197,165,197,82,161,80,120,95,139,138,239,91,
136,213,234,180,172,70,173,177,178,187,183,251,137,108,161,240,200,225,222,222,230,81,58,125,188,217,108,206,28,127,226,23,215,151,54,78,204,216,150,133,68,244,54,10,116,119,43,230,145,126,154,11,167,
170,120,104,6,156,160,212,106,65,189,235,130,235,249,50,231,72,245,15,210,168,1,146,169,41,194,151,47,147,100,105,116,217,80,170,150,247,54,242,48,98,151,170,120,225,243,187,158,7,127,251,211,171,240,
155,143,203,176,241,185,245,21,120,238,198,29,197,184,228,233,84,168,28,25,188,127,122,15,110,10,31,122,49,28,210,94,244,68,188,255,183,52,152,149,40,35,86,178,65,40,30,25,149,209,116,106,88,214,87,176,
140,79,79,37,150,31,125,98,37,50,53,109,229,95,249,49,16,239,58,220,182,34,182,19,73,48,206,39,183,182,183,94,223,185,179,147,254,88,25,72,187,213,142,238,237,238,157,110,52,91,15,22,138,249,7,247,119,
247,78,100,179,185,117,151,96,110,253,177,207,204,46,110,156,152,118,132,100,28,65,63,125,136,0,204,154,153,106,145,78,135,38,197,159,154,174,7,149,118,7,154,93,119,88,199,144,197,211,72,175,147,128,156,
99,72,215,150,114,23,4,36,46,79,175,29,101,34,72,35,171,210,160,165,67,52,68,155,94,63,208,115,214,217,68,66,72,161,120,216,31,143,163,194,73,21,178,22,63,27,202,53,38,48,76,201,82,239,59,145,70,255,151,
153,195,189,203,34,137,98,19,138,24,159,144,11,57,209,168,51,127,255,131,43,145,217,185,104,230,135,207,216,94,183,19,229,156,71,109,199,137,51,196,185,173,237,173,23,119,238,236,12,121,92,39,183,79,178,
219,119,110,243,143,164,129,116,219,157,228,222,254,254,249,66,185,252,88,181,84,58,185,187,187,123,162,88,44,174,78,108,158,94,61,117,225,210,194,68,34,238,48,68,36,53,105,54,156,76,170,47,17,79,36,20,
145,26,37,182,174,180,59,80,107,119,161,227,251,114,111,7,137,1,86,8,115,34,17,112,110,128,129,73,132,71,213,80,77,174,168,147,177,167,91,222,148,230,80,141,180,205,45,30,22,149,70,91,187,86,34,22,49,
31,25,36,111,88,146,37,86,128,8,13,90,190,122,56,74,132,90,129,67,84,105,25,125,28,145,112,24,160,210,6,16,138,218,73,7,77,255,223,204,178,217,212,198,214,130,253,185,137,72,230,185,239,57,157,82,222,
225,156,71,157,104,116,6,137,146,91,91,219,9,32,186,177,179,187,227,118,186,29,123,115,115,19,136,83,176,183,191,23,124,100,12,164,219,237,206,239,238,238,62,144,43,20,174,100,210,233,83,71,135,7,107,
229,114,101,105,241,193,71,214,151,183,79,207,71,35,54,83,142,49,67,225,143,164,254,134,193,72,50,174,22,172,134,232,74,111,87,23,155,45,168,117,187,224,250,10,29,67,141,184,9,21,106,73,31,67,194,80,242,
70,244,94,36,116,34,74,36,73,210,61,153,81,136,78,57,181,73,217,87,97,109,2,100,68,172,127,61,50,32,191,174,23,8,132,65,16,84,90,184,244,86,180,137,235,98,216,51,24,149,128,114,92,68,2,106,37,246,199,
32,9,163,224,72,225,118,129,60,82,78,202,85,250,127,139,66,33,183,231,245,132,168,76,56,249,18,243,75,83,107,159,125,202,201,189,244,163,72,109,231,166,205,57,143,91,182,227,88,22,76,34,209,228,198,250,
250,213,116,62,219,154,159,157,199,104,36,98,29,223,216,128,253,84,42,248,80,27,72,215,247,173,118,163,185,114,231,206,157,135,114,133,194,195,7,169,253,173,163,195,163,141,86,167,51,183,254,196,231,54,
22,86,214,166,109,22,170,165,73,52,241,81,197,63,49,6,54,84,195,57,0,20,234,109,104,184,46,184,65,16,98,240,4,66,99,144,60,38,64,8,12,228,32,167,207,241,146,168,43,166,232,14,132,230,37,5,66,11,237,99,
244,228,28,125,238,148,57,159,66,161,70,49,151,72,232,144,121,171,165,135,153,166,250,142,225,240,9,109,65,246,144,106,5,156,32,164,154,168,188,54,50,21,90,21,41,202,225,235,113,33,151,35,26,230,50,131,
215,239,81,238,197,82,23,65,36,153,140,31,187,242,233,117,103,106,58,82,120,229,69,139,115,30,225,150,21,113,162,177,164,149,72,204,175,68,98,63,205,29,236,167,227,137,36,79,38,19,176,177,190,142,169,
131,3,250,80,26,8,39,138,238,237,236,156,174,55,90,15,102,115,153,7,14,82,169,19,217,108,118,29,38,103,150,182,159,248,220,202,204,204,108,92,230,83,41,117,11,229,11,36,77,80,65,94,133,102,27,234,221,
46,120,1,151,66,51,253,68,146,71,154,169,243,58,116,136,88,165,174,144,18,70,169,220,46,12,79,113,201,67,141,176,15,52,140,56,0,146,147,86,105,42,110,239,25,23,143,175,106,215,218,203,21,193,200,218,21,
242,27,4,67,157,7,212,62,122,153,102,47,135,93,134,19,2,101,48,2,239,198,72,80,179,197,17,28,33,145,57,76,194,184,6,59,18,113,230,47,60,176,18,153,158,141,102,158,123,218,241,186,221,40,68,34,201,248,
196,228,58,88,237,99,243,243,243,223,235,116,221,157,131,131,131,123,138,114,217,247,214,56,120,114,127,127,239,66,190,84,126,180,82,42,158,220,217,217,217,44,20,139,203,137,227,219,43,107,247,63,184,
148,136,15,130,101,133,27,36,37,196,134,228,81,249,210,203,237,46,212,59,29,112,62,5,107,53,0,0,32,0,73,68,65,84,7,52,111,169,163,13,164,68,1,135,122,83,36,33,89,114,85,92,73,24,4,165,195,33,151,75,122,
12,164,144,67,122,30,24,154,175,70,122,16,113,216,167,146,11,25,242,173,68,36,2,79,61,112,65,187,212,139,119,118,134,57,13,73,85,108,217,163,201,92,44,125,102,174,10,252,145,230,129,48,244,52,234,33,166,
161,124,38,113,58,52,101,40,74,40,134,82,146,70,131,218,11,0,48,203,98,83,199,55,23,172,248,175,70,50,207,61,237,116,203,69,7,208,138,91,150,213,19,181,139,69,99,235,171,43,215,15,142,210,222,135,206,
64,136,104,238,206,157,157,7,138,229,210,149,204,209,209,201,253,84,106,163,82,46,47,205,93,122,120,125,249,228,201,249,168,99,51,50,132,28,170,180,166,158,152,247,107,7,174,7,229,126,131,208,160,26,174,
245,114,144,156,210,74,95,150,84,232,210,155,167,228,126,6,189,171,208,212,7,162,191,14,73,175,163,34,106,166,34,165,22,234,40,253,28,131,205,55,159,76,192,127,251,75,159,129,233,68,92,186,210,11,183,
118,32,87,173,107,243,212,85,148,72,77,176,73,253,183,58,197,106,128,58,41,80,45,220,69,187,88,251,188,4,66,8,170,132,108,2,30,30,230,52,3,162,62,200,30,138,139,158,14,97,98,97,113,106,253,23,126,217,
201,188,248,3,167,177,191,227,48,198,152,229,216,200,16,147,1,135,137,213,213,213,215,142,142,142,154,31,26,3,33,162,99,251,169,212,131,133,66,254,114,42,149,58,115,112,112,112,188,209,106,207,175,125,
250,23,55,230,151,151,167,45,214,171,111,168,94,158,200,64,46,20,78,193,128,56,20,154,109,104,116,61,137,90,174,122,124,82,12,67,85,41,151,3,107,146,78,90,57,179,52,180,219,170,249,130,104,80,134,16,12,
251,61,217,240,54,234,32,230,121,232,189,191,138,218,54,76,196,98,176,62,55,13,15,28,95,135,79,110,159,128,168,35,127,93,185,106,13,254,229,179,207,203,137,241,112,190,161,208,51,174,76,172,146,179,106,
197,187,98,248,153,249,160,111,4,229,254,252,193,99,160,204,111,68,69,213,126,200,240,13,89,142,194,70,7,69,73,70,166,236,12,159,39,132,89,34,208,226,76,36,227,75,15,127,106,37,104,183,189,86,46,99,113,
238,58,150,101,49,100,204,102,136,209,165,165,197,107,185,92,62,247,110,247,246,187,238,7,185,115,231,206,178,101,89,247,167,211,233,135,247,247,247,207,29,29,29,29,247,99,201,213,229,7,47,175,206,204,
206,37,16,7,185,42,87,32,81,185,230,48,220,76,156,160,218,117,161,58,12,161,196,19,136,11,205,71,48,108,208,9,191,16,185,22,162,22,243,134,125,235,156,122,170,28,156,11,33,81,168,86,66,131,86,213,193,
151,127,215,62,138,193,191,7,222,140,11,253,24,189,107,255,241,151,126,237,158,3,33,175,239,31,194,159,124,247,89,168,54,219,97,55,161,248,190,196,254,23,169,177,42,244,160,212,235,162,10,67,60,205,171,
134,189,242,188,159,60,139,191,231,195,36,91,16,134,16,94,35,236,179,231,58,162,197,67,68,48,124,61,174,220,83,161,81,75,84,157,17,222,135,239,185,65,227,32,85,206,189,240,253,116,208,237,228,24,99,187,
140,177,55,16,241,42,17,189,146,207,231,179,31,136,7,33,34,172,215,107,243,233,116,230,76,38,155,189,112,144,74,157,204,100,50,27,126,52,190,188,241,200,99,199,147,201,100,116,208,48,164,215,11,6,144,
105,120,132,4,4,80,104,180,160,225,118,67,58,3,87,18,98,181,66,71,166,234,180,44,112,53,76,134,165,234,55,104,68,68,147,160,244,16,78,86,145,52,82,40,44,168,228,34,194,134,189,151,43,224,28,190,127,253,
22,60,123,253,38,220,201,22,20,137,34,33,170,1,61,135,145,106,57,2,148,44,166,197,36,76,190,21,115,139,112,232,137,52,89,100,136,64,129,120,176,104,228,21,148,105,56,64,26,26,54,160,179,132,85,123,229,
121,98,190,167,244,188,88,182,109,77,157,216,154,183,226,113,39,243,220,211,232,213,107,68,68,158,229,56,140,56,185,11,139,11,126,33,95,40,2,0,28,91,94,194,108,38,247,142,190,26,246,78,141,66,248,49,158,
207,23,182,43,149,234,253,185,108,246,84,177,88,220,104,181,90,147,75,231,47,45,76,244,141,67,72,255,52,183,53,184,65,77,207,131,131,106,29,118,75,85,168,187,46,112,33,183,48,209,220,213,56,159,180,120,
71,9,187,72,14,149,212,209,153,162,9,146,82,29,23,189,155,84,10,32,146,202,251,164,120,66,83,145,239,94,44,139,49,248,212,153,147,240,212,3,23,96,109,118,90,19,144,32,82,61,7,73,97,145,36,99,36,222,79,
146,246,159,156,237,43,181,111,241,112,34,21,238,35,37,121,34,57,12,86,110,176,12,148,12,107,91,202,107,168,133,88,196,48,79,10,247,2,198,23,143,77,175,60,241,185,19,177,185,133,101,206,249,137,192,243,
182,57,231,103,137,96,107,97,97,33,6,0,240,78,141,227,29,123,144,65,193,155,115,142,249,124,126,163,94,175,95,42,151,75,231,115,185,220,102,55,158,220,218,120,232,209,149,169,217,185,9,132,187,144,11,
251,31,170,210,238,66,181,211,5,95,163,154,171,50,59,130,91,87,128,122,181,26,46,133,8,170,188,167,90,217,38,146,85,67,20,99,84,195,245,65,136,54,82,17,94,164,152,208,232,154,206,32,52,233,122,222,91,
26,67,196,214,191,30,199,178,224,225,147,155,112,121,235,56,252,213,243,47,193,223,188,244,154,70,81,28,53,16,72,226,28,144,254,105,177,95,164,8,115,17,1,201,227,58,23,110,240,60,174,41,251,138,222,140,
143,156,247,136,164,247,169,132,3,24,112,144,157,107,69,98,82,194,117,236,231,58,177,153,185,201,133,135,31,63,158,121,246,59,190,87,175,17,99,204,35,142,93,198,176,149,156,153,124,179,81,169,7,239,75,
136,213,233,116,54,243,249,252,195,249,124,254,194,193,193,193,241,114,185,124,108,233,202,133,197,201,217,217,9,171,159,115,104,161,78,255,127,249,102,27,26,174,39,73,202,12,167,218,43,216,202,16,161,
39,147,20,180,138,192,128,212,34,74,2,4,51,56,57,185,80,15,208,52,178,212,177,104,164,48,115,165,228,95,225,109,17,232,94,201,64,186,28,172,76,165,6,127,248,255,124,67,50,112,201,59,246,15,3,198,16,230,
147,19,112,98,113,30,174,156,218,132,139,199,215,97,80,95,101,140,193,175,63,246,73,152,136,69,225,47,126,240,130,240,153,72,25,50,42,8,72,8,212,144,97,223,8,153,194,88,197,192,80,173,87,221,69,184,91,
25,255,171,25,199,208,50,20,80,69,199,4,101,39,131,194,245,12,157,160,131,80,47,54,51,151,156,191,244,201,245,244,179,223,246,2,30,4,12,153,207,129,181,35,86,164,59,55,59,183,95,42,151,222,17,4,252,142,
233,238,156,243,249,131,131,131,139,71,71,71,15,30,28,30,156,46,228,11,171,177,181,227,75,75,39,239,155,139,216,150,101,226,20,114,32,200,54,218,144,111,180,160,235,115,173,150,64,168,184,81,130,126,83,
147,64,134,38,57,148,9,163,189,17,162,12,36,160,100,168,192,192,202,70,39,197,43,72,0,2,234,167,49,142,252,50,73,35,4,18,0,252,202,3,231,165,123,88,239,116,225,153,235,55,13,85,107,193,8,251,141,69,141,
142,11,135,197,50,252,232,214,14,92,61,56,130,243,235,43,144,136,134,141,83,167,87,142,193,65,161,12,71,165,178,60,78,193,80,158,15,91,103,72,203,39,148,151,15,31,27,201,104,80,230,144,74,33,25,42,225,
149,88,223,48,212,100,64,237,153,87,198,47,160,2,129,147,50,112,66,42,172,34,218,19,201,8,7,192,118,54,205,1,128,1,81,128,0,45,34,170,117,58,157,119,52,1,139,189,67,227,136,23,10,133,19,185,92,238,116,
46,151,59,94,46,149,23,163,43,27,75,107,151,46,47,71,29,199,145,7,77,246,84,254,142,234,45,216,173,212,161,229,121,90,64,74,100,232,203,16,198,44,139,186,85,164,84,200,71,206,45,23,78,96,49,22,24,198,
224,226,172,78,129,40,71,119,173,215,83,136,162,133,50,115,195,47,75,140,175,135,241,254,91,177,121,73,39,93,14,12,154,203,177,229,240,90,183,51,121,248,95,254,223,111,66,219,149,15,193,191,251,228,163,
192,24,211,24,208,56,228,114,161,134,34,13,74,53,97,171,172,72,199,81,115,51,99,109,221,124,242,43,220,54,35,229,69,160,169,209,144,143,37,35,100,192,21,175,205,13,21,76,233,92,226,195,135,152,237,216,
243,231,31,88,158,57,119,105,133,56,95,32,162,13,206,249,54,1,109,204,206,78,199,223,19,3,225,156,179,189,189,189,229,76,38,115,186,92,46,223,87,42,149,86,188,104,98,113,233,252,197,99,241,88,239,72,27,
244,20,4,68,144,169,183,96,175,90,135,142,31,8,73,160,97,238,134,32,239,137,10,194,68,134,154,4,129,66,19,39,243,102,226,35,74,123,212,7,98,181,47,132,72,162,125,75,244,118,146,233,42,3,118,171,202,150,
32,173,66,127,151,161,78,168,212,85,12,6,9,92,191,126,166,82,131,111,254,244,170,244,236,185,228,4,92,222,58,1,234,238,225,226,29,38,153,74,34,111,116,210,106,83,36,50,129,73,73,220,41,172,115,112,82,
20,32,85,111,58,248,59,222,231,183,145,130,22,146,92,152,29,28,58,70,28,144,84,163,35,205,72,6,63,179,136,99,79,159,58,187,16,91,90,89,34,206,87,136,243,147,204,178,207,4,1,45,189,87,30,36,94,175,215,
87,243,249,252,122,177,88,60,214,108,54,103,102,183,78,205,79,36,39,162,162,171,203,212,155,176,95,109,64,219,11,12,39,50,41,194,199,34,240,35,23,181,36,244,5,13,212,14,181,210,45,74,95,130,88,120,82,
171,237,36,253,14,65,196,226,73,66,114,12,96,140,84,148,36,97,19,12,255,79,162,147,211,93,200,88,96,28,125,30,122,60,195,73,221,127,159,63,186,117,91,187,220,67,91,199,165,147,85,146,218,33,57,239,82,
200,54,18,168,129,74,50,65,170,74,137,41,177,34,53,108,35,5,216,26,188,9,210,224,221,81,247,91,252,28,58,18,217,247,24,253,48,84,138,62,250,96,9,16,128,157,152,136,77,157,188,111,158,19,205,114,128,229,
32,224,171,0,176,52,53,53,21,189,231,6,114,120,120,24,107,118,187,39,90,173,214,90,181,90,157,113,214,78,172,76,173,174,205,88,216,147,222,200,54,219,176,87,25,24,6,105,33,140,124,90,168,3,44,73,239,143,
16,247,13,39,9,205,34,1,90,37,3,111,72,83,70,20,10,134,106,72,165,109,126,146,243,33,18,191,124,137,55,62,170,70,67,119,153,241,167,219,135,120,166,75,16,182,176,121,229,156,10,224,168,84,131,182,235,
74,215,219,58,182,160,157,172,164,10,72,12,245,175,73,2,4,8,13,48,175,129,198,51,64,184,84,14,128,126,48,129,254,186,32,194,195,164,209,107,164,198,43,82,3,59,53,15,34,51,181,69,64,51,137,0,208,178,88,
252,216,202,100,114,99,115,158,56,159,227,190,183,68,68,199,1,96,110,240,23,51,51,179,120,79,12,164,217,108,78,181,219,237,99,205,102,115,169,211,233,76,78,45,175,76,70,35,81,187,216,106,75,57,134,26,
107,138,197,185,144,245,106,218,96,166,208,201,16,197,163,206,105,210,175,71,90,255,135,88,7,48,100,228,250,36,114,210,222,82,191,170,110,196,120,21,171,211,5,228,70,82,77,6,212,122,137,5,76,114,29,192,
16,182,212,219,29,233,114,51,137,4,220,173,97,64,165,128,0,201,60,40,161,193,69,58,249,73,253,89,169,159,104,233,136,200,160,86,32,248,240,80,192,33,199,74,67,76,70,121,89,82,11,189,138,151,35,21,225,
236,61,104,197,226,209,137,245,19,51,64,48,5,68,199,0,241,4,39,90,142,39,19,54,0,64,165,82,166,119,109,32,68,52,227,186,238,233,86,187,179,90,171,213,102,61,207,139,5,204,162,195,90,3,107,174,39,109,175,
225,124,9,169,55,90,174,130,146,129,63,165,13,188,33,165,8,72,20,230,14,170,126,172,240,133,163,122,218,25,78,81,210,108,68,245,72,52,76,200,205,96,130,162,71,11,242,117,228,80,140,70,219,199,240,191,
92,206,131,12,239,87,252,28,92,65,113,0,0,162,142,51,68,12,81,202,171,72,250,124,96,168,253,168,94,65,235,150,212,10,163,6,226,227,32,213,0,217,48,80,253,64,98,20,129,164,181,59,144,82,247,144,239,163,
252,94,9,70,233,36,11,64,4,50,22,157,95,154,176,18,241,9,2,152,37,206,23,129,104,201,102,86,242,93,133,88,98,213,60,147,201,204,182,90,173,141,118,189,62,219,106,181,38,57,160,237,89,142,29,12,103,95,
160,176,177,148,47,192,20,111,66,168,1,5,220,100,247,32,241,116,200,84,123,144,18,107,67,248,132,138,113,106,164,67,209,184,16,76,28,85,99,8,55,2,206,85,235,61,119,47,217,246,63,43,31,136,168,97,136,139,
17,72,247,82,37,75,14,238,221,100,92,14,163,155,157,142,86,147,209,91,56,20,207,72,58,221,95,103,92,11,200,150,196,159,87,217,202,33,227,192,212,223,47,14,68,33,195,172,246,62,113,37,172,83,145,158,207,
128,193,211,137,51,92,6,186,91,195,3,182,207,247,178,18,137,216,244,153,139,139,68,52,65,68,179,64,180,64,156,79,223,179,28,164,88,44,198,219,237,246,92,183,211,158,118,61,47,150,188,252,248,134,239,68,
39,85,234,133,138,98,168,121,130,216,56,32,247,111,139,156,30,161,14,129,10,218,163,124,25,70,250,188,116,66,163,116,58,73,167,160,104,80,138,49,145,176,73,81,105,222,1,35,204,172,144,34,239,242,254,52,
68,70,108,149,5,83,79,136,126,232,172,205,206,104,34,114,213,86,91,6,26,200,224,15,100,190,135,66,45,81,144,44,18,199,170,9,57,130,216,247,2,122,180,170,157,244,106,228,96,160,164,144,146,39,130,80,251,
50,80,177,76,137,156,17,77,28,194,221,204,102,137,229,181,169,216,194,177,89,34,154,38,128,37,0,156,182,98,22,222,19,3,105,54,155,145,86,171,149,108,181,90,9,178,157,136,149,152,136,17,17,18,137,73,179,
156,108,247,78,67,52,184,98,52,22,232,84,70,46,145,1,73,33,21,25,164,97,88,17,110,70,174,229,63,131,214,78,85,240,77,174,98,131,54,46,64,1,104,228,132,29,228,247,172,10,51,234,98,114,138,125,160,28,182,
105,77,92,72,58,167,191,255,187,199,207,158,210,174,119,35,157,21,234,16,34,171,64,52,62,148,225,111,129,140,56,172,244,144,24,198,80,88,95,32,18,68,94,213,28,107,4,181,69,69,44,21,190,27,33,41,176,189,
16,210,169,72,158,234,205,164,119,167,188,11,21,197,67,64,43,22,143,216,201,169,4,1,36,1,96,22,0,166,226,86,204,249,153,169,38,226,23,219,110,183,29,215,117,19,158,231,69,251,170,122,198,99,219,220,106,
169,138,71,211,200,36,204,36,136,165,74,239,32,141,30,193,172,253,157,233,212,1,212,103,130,24,168,133,164,13,0,85,7,102,146,81,156,11,7,181,1,189,83,73,247,32,164,35,86,26,132,173,124,134,213,217,105,
248,188,82,153,7,0,120,233,206,158,30,215,2,24,115,26,85,249,81,53,22,45,73,3,89,131,66,162,159,136,57,133,208,125,9,42,31,151,84,166,49,25,8,41,42,171,76,164,188,43,207,39,147,32,29,72,58,94,146,23,181,
44,198,34,142,133,64,81,34,72,2,209,36,34,139,3,128,251,51,25,8,10,221,47,237,118,219,246,125,63,226,121,94,4,136,24,34,210,176,188,143,32,137,70,135,205,255,202,128,71,5,217,34,5,150,27,150,87,73,41,
82,13,212,1,133,202,176,20,98,25,58,242,100,196,74,173,244,146,66,91,144,79,103,52,193,199,35,187,15,149,77,45,25,21,189,69,34,162,123,79,117,72,102,120,157,222,110,60,189,188,4,255,221,47,255,2,196,28,
249,224,75,21,74,240,202,110,74,139,235,181,147,124,36,209,82,172,115,96,24,6,131,174,210,98,30,49,1,202,72,4,49,162,64,48,119,80,146,81,235,12,9,117,86,132,70,142,80,197,55,212,215,210,219,35,144,161,
21,157,157,139,19,129,13,64,81,64,140,3,208,207,238,65,196,229,186,46,11,130,192,34,34,214,51,130,144,67,19,126,32,131,16,130,200,202,68,5,30,148,194,162,129,120,179,220,155,174,62,143,144,128,56,26,10,
88,104,104,139,149,116,208,250,92,46,212,33,104,115,157,78,131,88,101,35,87,219,118,117,212,229,110,140,94,173,95,219,36,24,1,0,22,34,204,79,38,97,251,216,2,60,122,250,36,60,176,185,1,12,101,143,196,137,
224,207,158,254,193,240,254,153,104,29,154,68,170,145,8,40,58,115,84,106,83,164,108,250,112,84,27,24,64,25,169,139,19,105,132,14,128,249,51,195,8,96,132,200,224,14,165,73,89,114,149,95,212,34,166,254,
137,31,153,153,75,196,230,23,147,157,98,222,1,128,8,17,89,247,196,64,250,48,33,18,17,2,162,34,75,105,80,216,35,83,30,161,214,44,116,23,43,80,114,205,231,45,7,35,204,24,230,24,130,123,30,36,222,124,16,
235,162,194,70,5,57,255,16,33,73,177,181,71,124,45,233,48,212,25,170,161,35,68,161,160,165,127,150,149,217,105,248,103,191,253,27,119,245,48,182,101,166,187,171,223,203,159,126,235,123,112,53,117,168,
105,19,131,33,252,80,56,13,58,29,70,82,65,65,64,228,35,168,48,242,65,129,202,118,231,82,72,172,82,88,194,51,147,70,134,170,38,17,15,146,250,216,101,134,49,24,243,16,149,41,140,182,109,177,72,212,1,0,155,
136,34,136,232,56,182,131,158,239,209,187,50,144,209,57,138,81,191,71,170,75,136,138,249,100,42,238,17,104,189,229,170,247,32,37,76,144,100,169,20,1,56,82,147,111,131,81,138,61,34,198,89,228,234,225,174,
38,243,32,204,69,20,42,221,40,81,45,70,207,7,97,136,144,80,80,168,119,186,26,157,14,124,237,59,63,128,31,190,121,75,10,23,7,161,26,87,6,255,0,152,138,176,35,217,158,146,141,13,65,104,146,164,176,65,28,
8,26,118,5,42,76,91,131,218,34,42,209,135,200,50,150,248,174,168,67,211,40,138,247,1,8,61,248,34,194,38,120,56,20,213,42,25,162,101,89,253,125,239,0,128,237,88,214,189,55,144,240,106,28,136,80,167,228,
168,201,169,34,128,76,38,138,128,161,129,135,12,66,204,168,105,93,145,89,111,73,161,62,168,33,3,209,40,144,193,28,62,169,153,44,73,80,178,194,49,163,187,35,88,239,102,181,186,46,60,123,253,38,252,213,
143,94,130,106,171,101,214,156,210,254,191,92,5,7,1,70,39,165,254,65,2,5,61,164,162,136,178,68,242,44,147,209,32,135,236,161,13,103,167,20,101,16,154,186,60,133,92,20,229,186,151,9,10,18,184,194,10,209,
178,39,29,129,104,89,232,68,172,62,122,139,68,132,196,238,1,138,101,89,22,49,198,56,34,114,226,189,129,141,195,112,2,85,102,165,144,224,25,52,118,149,84,14,84,23,50,236,149,38,5,138,5,253,180,71,50,85,
165,133,249,230,210,23,134,33,115,79,45,106,170,96,129,150,252,9,97,53,161,17,230,85,95,205,216,248,243,14,86,192,57,180,186,46,180,93,15,10,181,58,220,201,21,224,118,38,7,47,221,217,7,55,240,229,112,
150,192,64,103,151,137,148,3,0,130,171,225,162,38,134,69,114,111,184,20,66,9,247,30,65,214,215,37,5,125,34,49,247,232,3,47,35,6,190,72,40,151,40,160,205,5,149,22,66,131,246,176,216,127,101,152,201,168,
134,184,22,50,102,217,140,4,28,234,173,146,144,183,133,98,197,227,113,223,117,93,207,178,44,159,2,15,101,21,112,83,226,69,134,90,7,233,213,85,163,132,14,14,153,253,82,117,217,164,226,14,225,152,47,174,
160,55,168,38,214,34,139,87,107,170,18,141,12,5,234,135,233,243,201,20,24,49,4,19,71,142,137,223,230,127,243,39,255,82,35,61,202,253,225,250,99,162,252,141,244,26,74,104,173,178,97,37,66,159,105,190,162,
72,126,84,213,29,197,33,58,4,6,164,81,204,173,16,212,230,40,66,3,118,141,74,2,45,161,92,194,123,69,20,154,231,200,0,0,112,105,227,35,136,33,46,130,54,179,20,245,130,44,5,196,201,119,131,80,50,2,1,223,
34,79,127,91,133,194,120,60,238,69,34,145,182,109,219,30,17,97,192,3,36,19,73,207,192,223,38,13,202,4,169,223,131,192,32,13,64,6,6,220,240,218,220,136,122,160,64,252,147,201,113,242,40,48,185,42,12,34,
125,174,31,23,115,0,19,144,64,66,53,95,40,44,34,141,66,239,12,112,45,168,162,16,42,132,41,136,166,41,90,193,106,30,33,110,120,52,76,215,149,249,2,138,64,31,201,2,12,36,50,114,85,106,15,128,54,133,75,230,
192,169,61,233,160,124,155,194,227,72,35,168,252,66,226,61,244,6,92,64,39,71,80,120,12,250,198,34,4,169,48,161,137,184,31,112,207,11,16,32,64,64,142,128,228,227,61,168,164,79,77,77,117,227,241,120,51,
26,141,118,200,237,18,239,116,124,52,162,34,36,209,20,196,132,76,231,84,41,39,40,128,198,36,149,169,8,168,133,20,3,218,246,112,147,105,50,254,242,49,70,163,148,12,72,151,161,145,60,143,24,230,41,138,37,
10,141,107,24,22,132,52,27,50,8,72,155,59,25,213,30,117,237,32,81,169,25,160,123,96,233,30,17,104,179,74,72,234,32,28,1,177,162,9,253,82,117,2,192,12,25,147,50,38,130,84,161,18,53,60,37,144,251,202,21,
118,181,230,157,65,250,62,76,195,142,204,32,9,1,4,156,243,32,8,8,48,0,0,15,0,124,223,237,190,123,54,239,252,252,124,59,145,72,212,99,177,88,7,1,168,121,243,90,37,130,216,6,141,117,137,130,229,171,28,28,
212,66,44,89,60,78,134,253,72,128,144,69,213,61,201,203,160,226,125,68,94,147,132,100,41,155,27,85,112,128,107,212,118,77,176,217,160,162,40,211,79,76,32,134,110,28,164,133,96,66,146,41,98,247,90,106,
160,54,158,41,220,39,233,16,82,69,244,212,254,12,210,85,22,201,160,135,101,234,55,80,154,102,36,175,100,72,49,80,117,221,226,207,168,130,35,100,14,72,70,168,221,152,230,170,232,222,60,188,55,129,219,13,
130,118,203,5,64,15,16,93,0,240,124,223,127,247,6,178,188,188,92,137,68,34,217,120,114,178,107,219,118,215,203,29,117,177,219,110,147,70,64,146,73,119,178,182,149,162,234,71,234,4,41,165,31,218,64,243,
30,218,197,72,213,118,201,41,104,112,179,252,37,200,255,213,116,61,212,176,108,8,113,146,17,57,226,74,190,0,35,92,190,132,206,145,108,216,38,150,42,168,132,198,193,71,66,145,20,168,39,209,230,214,87,2,
213,189,144,97,170,175,170,161,75,122,99,140,236,65,140,92,171,144,43,37,49,37,148,98,172,184,217,149,243,208,32,203,36,27,10,25,149,99,228,26,87,72,22,39,222,45,228,106,110,181,220,2,32,15,1,186,128,
248,150,74,240,236,46,73,250,240,101,25,99,101,34,218,75,76,36,202,19,19,19,53,68,12,92,183,107,73,120,185,232,246,164,176,132,228,140,13,244,222,4,41,180,66,115,113,77,71,108,72,87,59,20,133,228,180,
244,72,169,110,147,97,88,179,97,130,148,105,146,148,44,158,134,138,222,44,193,144,197,175,144,48,9,77,29,144,164,73,122,26,164,194,148,48,194,176,97,65,167,184,211,91,136,46,12,194,45,211,196,44,174,230,
48,48,74,198,219,152,117,106,223,59,87,105,52,32,135,146,138,47,212,96,123,9,76,65,82,196,79,196,240,126,208,47,163,176,30,56,231,221,114,177,131,0,62,34,118,16,177,141,61,47,242,238,115,16,0,128,100,
50,153,141,71,99,7,211,211,211,37,199,113,186,173,244,97,199,65,116,193,32,64,173,109,82,146,147,38,129,197,46,221,24,83,187,44,13,36,45,6,6,129,234,151,194,117,226,154,136,50,33,201,61,34,166,216,92,
101,234,106,161,154,114,194,146,130,189,163,65,237,3,185,174,221,69,134,77,14,58,166,47,138,34,168,22,165,246,107,135,109,176,33,122,7,164,235,33,128,129,126,30,34,81,164,229,62,166,249,206,68,106,72,
70,186,161,107,93,133,168,204,88,23,195,30,208,154,209,228,247,46,23,94,73,128,233,85,145,64,109,174,164,122,64,249,174,207,187,29,159,0,59,0,80,7,130,26,249,126,251,158,25,200,217,179,103,107,179,211,
83,251,11,11,11,133,120,60,94,239,238,220,168,243,114,177,10,10,235,213,200,64,82,101,125,6,20,117,17,222,20,36,104,72,233,175,16,111,178,44,167,169,18,67,148,196,126,128,14,130,130,158,144,92,80,10,77,
64,100,250,162,185,24,197,21,156,136,72,104,29,21,62,61,87,147,78,185,176,137,164,74,26,201,163,149,53,36,10,233,174,64,2,74,197,80,53,132,37,25,16,65,221,80,101,254,22,106,173,179,18,255,95,76,215,213,
141,12,106,114,78,154,178,101,239,114,104,8,20,12,135,6,145,70,88,36,41,183,25,109,160,195,195,145,115,238,150,139,77,175,86,105,33,66,29,17,203,136,80,109,117,58,254,61,51,16,34,42,199,98,177,55,39,167,
167,83,51,51,51,5,199,113,186,237,204,161,103,33,4,195,91,205,117,55,106,84,32,81,234,38,226,156,59,16,212,220,117,29,221,193,235,40,132,184,17,9,179,198,160,215,168,223,164,43,159,75,199,181,222,95,32,
117,195,105,253,219,58,211,142,140,108,60,81,2,73,62,77,81,83,233,64,153,176,41,121,107,28,26,28,167,17,66,111,38,190,155,58,152,84,155,88,11,18,90,36,194,191,92,209,35,38,73,96,129,36,133,24,245,5,185,
86,23,35,185,165,214,164,62,163,162,154,42,23,204,164,180,172,38,247,158,231,53,110,94,47,5,157,118,3,16,42,0,144,6,196,242,219,217,247,111,155,106,194,24,163,82,169,116,135,115,126,179,177,178,114,188,
90,173,206,149,83,59,209,232,212,116,134,173,158,88,13,40,64,147,186,135,169,233,69,131,122,213,239,13,73,15,73,196,88,5,21,174,63,129,89,219,105,112,210,161,233,125,8,200,17,7,29,194,212,248,88,26,247,
77,248,30,57,24,4,64,148,226,21,73,98,222,38,177,104,145,8,107,18,200,147,248,102,134,13,47,247,116,147,41,182,147,192,10,41,244,2,83,225,19,195,239,131,195,176,231,127,168,8,79,38,152,89,14,109,80,160,
137,160,218,57,73,33,157,4,213,114,193,221,232,66,192,117,234,74,152,139,171,236,95,10,26,213,78,59,151,110,32,98,29,145,149,0,40,77,4,149,183,181,239,223,9,253,97,118,118,182,190,186,186,122,109,110,
126,126,103,113,113,49,29,141,70,155,181,59,55,92,22,248,29,144,85,111,101,52,135,80,211,60,82,199,153,105,120,248,168,19,10,12,52,115,245,240,196,240,52,67,33,126,69,169,114,77,242,137,45,81,225,197,
249,233,226,137,168,179,125,65,158,0,40,133,50,42,163,25,135,97,30,142,208,46,38,169,214,65,202,105,175,245,115,147,46,129,74,138,55,54,181,188,14,1,3,133,159,165,214,87,4,38,183,33,89,167,17,160,54,25,
200,180,166,193,162,130,134,48,145,145,17,96,34,167,130,161,150,38,29,179,200,132,231,33,80,167,211,169,190,254,114,30,0,218,136,88,4,160,35,68,150,107,54,123,243,180,103,102,230,240,158,25,8,34,242,100,
50,249,230,252,220,220,203,27,27,27,233,217,217,217,12,115,187,221,198,79,95,72,59,8,93,19,42,33,222,125,173,46,193,21,225,50,73,228,204,60,51,207,68,74,148,244,153,20,18,161,172,17,172,146,22,65,110,
232,49,73,245,104,130,114,234,30,146,161,83,110,24,147,16,74,169,130,62,219,68,130,120,81,17,42,80,233,37,164,221,15,210,120,71,98,247,157,58,124,130,43,53,25,20,40,28,186,161,146,65,122,72,245,22,58,
204,108,128,208,73,37,129,42,227,23,6,124,97,241,80,20,188,28,146,41,143,85,11,140,125,14,30,5,194,192,157,128,186,133,108,179,147,207,54,17,177,100,69,163,89,68,188,133,136,217,240,235,13,238,77,136,
37,132,90,30,17,93,243,125,255,68,181,94,159,236,116,58,19,149,98,254,152,155,57,172,179,165,213,72,48,220,14,168,97,214,195,188,12,195,129,83,106,182,193,133,234,187,190,81,21,40,95,243,58,10,55,137,
64,243,106,168,201,221,168,19,96,81,209,214,237,31,183,72,90,239,2,1,153,121,81,10,69,5,80,133,94,65,130,89,113,168,59,79,134,97,158,10,232,160,208,67,164,51,8,5,82,166,72,223,80,115,60,53,180,67,83,95,
142,236,53,229,126,124,115,82,71,134,123,160,97,156,20,106,179,32,200,179,98,132,50,134,180,79,72,25,43,173,171,30,9,7,140,64,189,241,203,197,106,241,133,103,11,128,216,96,12,179,20,248,187,12,241,118,
181,86,173,14,254,178,90,173,210,61,51,16,34,66,68,36,68,76,21,139,197,231,218,237,246,76,187,221,142,123,158,23,173,191,250,99,54,243,200,147,140,79,78,205,113,101,90,105,191,83,160,103,20,40,247,67,
235,122,184,40,135,47,164,147,14,85,142,142,121,226,184,129,234,75,186,162,163,148,179,40,201,134,156,231,80,88,167,33,61,204,32,117,146,22,133,164,62,181,101,215,44,93,36,231,4,8,134,134,46,5,219,15,
157,164,202,206,165,144,122,195,77,157,247,102,4,72,236,71,34,2,51,141,69,65,174,140,149,126,146,117,210,164,153,245,82,101,48,60,68,134,159,13,197,240,16,245,228,70,24,5,16,66,225,24,170,41,14,222,158,
231,185,245,55,95,175,18,241,54,50,76,51,203,78,1,241,27,140,97,230,157,236,249,159,185,97,106,110,110,238,205,78,167,51,239,115,62,235,117,187,214,254,254,190,93,253,241,247,105,250,129,71,220,96,126,
105,41,8,2,22,198,189,92,50,8,148,40,151,36,241,253,197,94,11,52,20,194,134,161,130,24,94,8,115,97,101,225,0,157,123,37,169,141,144,137,170,111,168,105,104,158,9,165,220,117,112,192,113,109,50,21,202,
97,141,202,166,149,226,87,144,18,112,53,175,18,189,204,224,46,113,77,41,82,69,113,72,111,163,5,145,58,46,251,13,84,40,154,36,239,71,249,254,138,237,97,100,104,243,85,219,165,65,215,22,147,250,110,20,66,
152,145,69,109,128,133,145,112,40,164,135,125,88,151,123,174,91,123,245,199,217,214,209,65,3,25,102,44,102,237,34,192,43,0,248,90,185,82,109,189,103,6,34,86,215,17,209,227,156,191,226,251,254,180,117,
225,60,18,113,76,165,14,78,150,95,250,17,76,159,189,216,181,215,183,214,189,32,176,6,98,98,92,87,245,52,232,172,234,21,115,93,140,90,208,132,3,3,42,163,78,185,53,104,115,133,212,7,253,132,85,43,209,90,
241,211,20,254,8,102,202,133,138,62,154,54,79,255,73,68,58,209,142,70,53,103,139,188,113,17,30,215,4,224,192,192,0,214,169,32,90,34,109,164,192,144,169,74,168,144,24,73,34,16,106,185,34,161,6,101,144,
192,218,21,231,126,72,103,10,200,243,18,7,247,85,36,44,134,210,82,50,96,206,59,237,86,233,135,223,61,236,86,74,1,99,44,195,44,182,203,44,251,13,4,120,185,84,44,230,223,169,35,120,87,99,160,25,99,85,34,
250,78,34,145,104,6,65,16,0,32,237,239,167,78,86,174,189,58,157,180,157,2,91,90,93,244,137,24,129,218,134,169,87,103,205,82,252,164,33,149,58,95,136,12,176,44,129,97,219,75,57,203,112,243,34,105,74,32,
164,97,186,194,252,110,50,41,164,8,65,31,130,166,176,46,162,214,168,22,2,5,185,212,112,70,56,26,95,131,140,147,21,149,51,149,171,3,131,100,131,65,225,16,194,17,136,16,168,116,26,237,160,18,54,188,240,
62,16,195,48,154,244,118,195,80,151,76,9,157,6,109,180,26,40,160,140,190,211,234,58,18,189,9,128,119,59,173,202,11,223,75,119,171,101,15,25,203,216,182,125,7,129,174,33,194,115,197,66,49,245,179,236,241,
119,61,39,29,17,27,68,244,52,15,2,23,9,124,203,178,130,189,189,189,237,198,235,47,241,248,89,31,236,149,245,121,143,192,14,219,115,197,19,141,131,220,190,42,182,180,26,192,190,17,181,36,210,4,197,64,71,
158,20,228,198,228,173,180,161,54,194,251,226,70,125,41,113,3,99,72,123,33,109,158,171,65,252,128,194,211,143,244,176,136,20,189,41,77,106,72,100,23,244,239,229,176,110,161,108,28,186,139,66,139,89,102,
149,228,94,113,37,89,87,167,81,12,129,6,210,61,12,153,218,11,212,48,12,244,136,64,42,47,42,159,95,158,168,212,243,34,188,221,108,86,95,121,62,223,41,21,59,140,177,3,59,18,217,67,206,127,138,200,190,85,
40,20,110,252,172,251,251,93,25,8,231,28,25,99,132,136,1,17,253,40,224,65,128,22,115,29,199,233,238,239,239,111,149,223,124,45,192,98,222,157,56,115,97,198,179,156,100,95,25,69,201,1,12,213,240,190,0,
51,55,168,114,152,154,153,212,106,55,42,124,44,48,141,120,211,10,81,178,103,145,21,91,72,99,178,154,98,125,53,148,4,21,6,213,20,220,21,131,54,156,186,164,161,69,6,38,163,129,84,9,96,110,247,85,141,64,
109,28,51,121,83,51,9,82,73,252,77,45,181,98,210,44,57,39,195,24,232,161,28,45,106,218,6,67,184,183,63,186,97,104,165,28,128,120,16,120,133,76,185,250,210,11,21,175,211,106,89,140,237,51,198,238,88,64,
175,161,101,125,59,151,203,237,12,94,119,113,105,17,243,185,60,189,159,33,22,5,158,135,150,227,16,34,122,62,119,95,112,108,167,13,192,154,19,19,19,173,91,183,110,117,10,133,220,122,249,233,84,119,250,
204,133,162,189,113,114,181,235,243,136,152,3,72,173,166,18,231,87,173,34,131,185,8,165,229,25,114,91,237,240,239,185,206,180,32,67,104,33,85,225,135,225,130,106,132,100,40,141,169,85,95,185,110,73,160,
124,56,113,67,73,33,152,82,108,33,179,118,84,184,121,12,163,171,7,155,7,113,56,101,22,197,58,144,218,207,98,208,161,151,122,106,64,156,13,216,15,207,140,35,184,133,194,48,113,121,118,160,244,10,92,131,
233,197,54,95,18,122,26,134,207,224,74,95,15,1,240,78,171,89,121,225,251,7,221,114,145,1,64,213,182,172,93,203,178,118,16,241,121,0,120,62,151,203,29,136,223,195,59,53,142,123,18,98,89,142,51,124,81,155,
69,124,0,120,57,159,207,215,167,166,146,185,196,68,162,115,227,198,141,102,38,147,61,94,187,241,198,180,125,116,176,55,241,137,199,86,219,128,19,34,77,30,17,149,254,0,50,224,232,100,152,68,43,39,193,40,
22,141,12,39,45,153,6,3,2,244,36,114,136,96,228,212,86,149,37,140,50,100,43,81,237,21,106,9,40,36,69,189,241,73,150,216,35,77,172,154,52,88,149,212,92,139,204,149,102,84,85,45,181,86,91,253,160,80,67,
34,3,246,161,212,183,70,121,164,65,249,212,211,190,42,0,0,6,231,73,68,65,84,72,239,172,84,19,36,84,194,39,148,104,51,164,2,158,0,4,20,84,138,149,252,51,223,204,82,111,26,112,150,49,107,199,178,237,59,
8,240,61,0,248,113,38,147,169,193,61,88,54,188,7,107,113,113,241,86,199,237,228,163,209,104,38,22,139,61,62,57,185,91,63,72,165,142,151,203,229,197,242,211,255,95,58,113,255,229,25,107,225,216,148,15,
204,9,40,64,81,133,68,160,70,141,28,75,44,17,11,5,172,149,148,153,34,210,1,38,104,49,24,67,44,33,105,87,2,117,80,27,147,136,27,250,69,184,57,109,150,79,89,52,87,109,12,93,114,36,144,26,181,78,117,149,
193,42,154,162,233,126,152,20,39,149,191,31,209,129,99,228,207,169,161,174,170,40,9,160,170,141,224,48,92,48,26,160,16,222,114,80,123,121,80,204,227,56,184,221,110,123,247,86,181,122,237,213,6,0,116,108,
203,58,180,34,145,67,6,112,149,49,246,140,231,5,175,231,114,153,224,94,237,229,247,196,64,0,0,98,145,88,21,0,190,155,73,167,211,241,104,236,201,233,233,153,218,65,106,127,57,155,205,174,55,174,190,28,
4,65,80,73,156,58,27,143,172,111,205,251,12,163,65,192,17,132,174,61,45,52,17,136,104,186,70,172,1,78,29,196,179,28,148,74,182,194,40,26,53,251,28,76,83,219,201,84,119,147,209,21,3,169,145,12,112,169,
34,201,13,67,49,10,146,167,253,74,99,217,8,12,234,131,40,107,4,27,68,175,81,245,96,2,202,36,169,200,27,230,63,154,90,163,53,192,88,43,172,147,242,124,174,107,158,137,119,64,172,152,15,78,51,164,33,226,
70,68,68,237,102,179,254,218,79,242,173,244,97,128,136,174,101,89,121,198,88,202,142,68,142,16,232,21,219,178,158,222,219,219,79,223,235,125,140,240,62,172,122,189,177,148,201,164,31,46,150,74,23,178,
153,204,137,131,131,131,213,82,177,184,220,104,54,103,124,223,183,236,169,25,156,56,255,224,156,31,79,206,112,226,200,137,144,115,177,121,73,101,128,26,20,82,36,134,42,201,93,101,164,255,94,234,97,151,
194,181,1,137,81,229,20,137,224,130,73,40,142,164,94,15,174,122,30,227,20,171,94,86,47,51,104,21,98,31,215,105,37,189,235,132,234,43,82,136,40,188,30,87,149,220,37,229,69,10,167,129,129,220,160,37,134,
97,92,107,76,210,239,35,112,82,116,1,76,247,76,190,31,226,189,39,101,74,113,239,87,156,128,83,224,165,15,138,245,107,175,212,188,102,19,1,160,131,136,101,203,178,210,150,101,101,152,101,221,68,132,31,
35,99,175,239,237,236,54,222,139,189,251,190,24,8,0,64,165,94,115,144,211,114,42,149,58,95,46,151,47,101,243,249,237,108,58,189,84,173,86,231,235,245,250,156,235,121,81,110,59,86,252,216,154,19,217,216,
156,9,34,177,9,14,196,136,0,120,192,145,83,175,59,112,144,172,137,220,32,174,12,95,25,110,60,137,248,216,223,64,92,225,191,146,210,124,197,101,21,13,18,5,36,196,47,159,235,10,26,32,140,70,70,205,112,133,
247,56,208,11,38,189,59,78,155,252,68,242,112,79,125,99,41,3,59,165,207,169,43,124,16,113,93,97,69,157,6,220,159,20,203,73,174,123,12,174,27,134,121,92,233,31,39,93,156,124,68,255,189,4,125,115,78,225,
225,194,131,160,92,172,53,110,188,81,241,106,21,242,59,173,0,1,91,136,88,180,44,43,107,217,78,17,129,110,48,198,126,138,140,189,185,115,231,78,238,189,220,183,239,155,129,136,171,84,42,30,79,167,51,231,
115,185,220,169,90,163,113,188,88,44,30,43,21,10,11,181,90,109,174,211,233,76,250,65,96,83,52,102,51,198,40,50,51,103,89,171,39,102,120,60,145,12,56,88,82,178,54,236,24,35,157,214,160,109,76,249,244,151,
96,86,18,132,175,185,222,253,23,26,6,87,78,64,69,0,78,245,70,82,115,17,41,180,176,112,48,141,164,243,43,181,158,114,185,40,38,109,90,210,58,47,137,200,208,138,74,178,119,32,85,18,148,36,205,175,129,217,
115,146,33,96,243,245,80,243,6,160,222,63,82,21,251,135,181,162,30,55,196,247,125,55,159,169,180,83,59,245,160,221,4,226,28,189,90,213,5,128,46,246,72,134,69,102,59,69,11,241,16,0,110,51,198,118,108,102,
93,187,113,235,102,238,253,216,171,31,136,129,12,86,46,151,159,105,181,154,155,217,92,238,116,169,88,60,81,171,215,55,170,149,202,108,189,94,159,106,52,26,211,157,78,39,233,186,110,156,115,206,48,145,
180,208,113,16,1,57,1,1,15,2,28,16,40,73,33,8,114,141,204,166,244,53,152,84,78,40,100,19,247,24,224,100,14,145,72,249,242,71,232,129,209,93,94,195,20,102,72,253,39,92,69,133,100,111,163,246,171,147,210,
249,39,245,211,171,191,83,228,129,212,231,152,194,35,249,96,17,197,229,184,50,210,2,66,120,151,212,124,200,160,32,206,57,250,157,54,121,141,186,223,135,80,218,136,88,99,140,85,25,99,101,102,89,21,32,216,
183,44,182,203,24,123,147,136,118,111,220,184,209,125,63,247,232,7,106,32,131,85,44,228,153,235,251,179,153,116,102,171,94,175,111,84,171,213,133,118,187,189,212,238,116,142,181,219,173,169,118,171,157,
232,116,58,177,110,183,27,247,60,47,234,123,190,227,7,190,195,57,183,56,231,140,19,33,113,142,250,151,42,108,86,245,119,202,38,31,134,76,138,174,150,233,90,218,198,129,112,128,189,62,8,199,208,39,110,
186,230,32,222,87,67,165,17,127,171,81,80,6,237,176,163,12,119,196,103,55,189,134,116,157,145,159,247,238,247,87,241,28,212,159,184,20,16,145,15,0,62,34,184,0,216,69,196,14,0,180,24,99,109,64,86,69,160,
44,2,102,152,197,50,136,120,128,200,246,11,245,160,158,75,93,167,15,98,111,126,40,12,68,92,135,187,135,150,133,192,92,240,39,114,249,252,70,181,90,221,104,54,155,211,141,70,35,209,110,183,147,110,215,
157,224,60,136,250,1,143,18,112,139,56,49,206,121,143,173,195,251,33,9,87,40,31,195,47,140,15,67,50,82,242,143,1,66,198,57,215,194,49,46,94,79,187,38,25,54,5,1,231,131,205,166,252,173,246,63,46,244,76,
113,249,58,20,134,127,195,247,71,28,128,43,189,225,194,103,24,249,94,40,212,238,234,61,198,7,241,191,102,224,52,240,194,156,180,67,100,120,127,1,250,215,37,41,92,28,252,45,233,247,140,128,122,6,66,68,
93,2,232,34,64,179,23,70,177,58,99,172,130,136,251,12,173,180,239,249,109,206,253,224,141,235,215,232,131,222,143,31,58,3,81,215,238,206,29,230,19,90,196,57,2,15,240,240,232,136,33,32,150,171,21,214,108,
54,216,192,97,115,222,251,226,56,244,93,60,239,203,150,41,27,133,7,33,10,68,212,11,103,248,240,103,62,220,4,28,56,64,192,229,176,133,211,112,147,241,97,34,27,110,18,62,16,129,16,196,43,248,128,163,68,
0,156,7,195,199,56,231,253,122,5,7,78,40,128,7,4,60,224,225,117,120,111,195,13,85,96,2,46,244,200,4,161,88,67,255,61,241,225,251,236,75,36,240,222,231,30,134,89,226,125,225,130,129,2,245,223,95,255,223,
196,123,239,105,184,233,5,3,10,6,247,128,128,122,55,116,104,56,131,123,201,7,226,27,132,194,119,194,129,49,198,25,179,184,21,137,244,110,112,224,19,5,64,17,194,224,217,159,188,72,48,94,227,53,94,227,53,
94,227,53,94,227,53,94,227,53,94,227,53,94,227,53,94,227,53,94,227,53,94,239,112,253,255,3,216,112,119,75,89,163,54,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LivePanelComponent::bally_2x_png = (const char*) resource_LivePanelComponent_bally_2x_png;
const int LivePanelComponent::bally_2x_pngSize = 18303;

// JUCER_RESOURCE: gmfullOn_2x_png, 6348, "../Images/GMFullOn@2x.png"
static const unsigned char resource_LivePanelComponent_gmfullOn_2x_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,100,0,0,0,60,8,6,0,0,0,144,63,31,206,0,0,0,1,115,82,71,66,0,174,206,28,
233,0,0,0,6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,219,10,30,15,33,30,51,151,17,252,0,0,24,76,73,68,65,84,120,218,
237,92,89,112,28,215,117,61,175,215,217,49,152,193,66,130,224,38,145,162,8,26,18,69,69,187,84,90,34,81,150,108,121,83,49,118,172,216,78,57,229,165,82,165,252,231,47,149,114,242,21,127,56,78,197,118,202,
169,168,92,118,42,178,75,142,28,201,182,118,74,164,41,238,11,192,5,220,4,2,34,1,98,223,102,159,233,190,55,31,189,189,238,25,74,140,67,91,178,140,70,177,0,246,52,122,122,238,121,247,158,115,151,7,96,249,
88,62,150,143,229,99,249,88,62,150,143,229,99,249,184,246,135,248,67,123,224,103,158,121,38,94,172,55,186,167,198,199,58,42,165,82,190,90,169,102,234,86,35,102,91,150,70,68,0,64,0,74,186,174,23,141,88,
98,42,214,222,54,99,90,141,217,111,125,235,31,74,203,128,92,163,227,167,207,62,219,62,54,51,123,211,252,196,68,255,226,210,226,166,165,165,165,222,26,113,151,150,202,100,210,29,93,201,120,91,214,84,53,
69,64,40,162,86,41,219,213,82,217,186,124,250,228,188,93,171,22,85,162,25,35,102,142,199,99,177,19,201,108,251,137,132,161,29,255,246,63,125,123,97,25,144,223,226,120,254,249,231,115,23,199,46,125,242,
210,187,23,239,156,154,154,218,152,232,93,179,161,103,227,230,182,206,213,107,82,201,120,92,23,2,96,0,32,6,3,96,102,128,25,4,128,201,134,101,19,138,165,146,117,241,244,208,194,200,169,227,139,133,139,
23,46,36,18,169,51,217,124,254,64,38,17,255,245,63,127,247,187,211,203,128,92,197,241,226,139,191,204,94,26,187,248,224,248,248,229,135,70,71,70,110,93,113,243,109,215,247,221,117,119,103,76,215,4,3,96,
39,52,129,92,0,152,153,153,225,188,198,4,16,51,129,5,0,176,205,128,96,48,49,202,245,58,159,120,123,207,204,233,55,95,57,147,205,102,143,101,178,217,215,146,177,216,235,223,255,193,15,138,203,128,92,225,
248,217,115,207,245,143,92,24,254,194,185,179,231,238,202,247,245,223,184,249,142,123,87,196,76,93,48,51,152,152,25,12,102,22,46,16,96,6,156,115,14,24,97,47,97,192,185,158,193,112,126,15,140,114,181,142,
163,187,118,78,92,216,187,235,120,62,159,223,215,145,203,61,243,111,63,252,225,240,135,225,243,171,31,38,48,158,253,217,207,30,57,62,48,240,141,115,35,163,127,122,223,95,126,253,214,181,27,111,200,232,
170,42,136,136,1,8,6,4,136,5,4,0,6,24,2,142,165,225,127,7,130,48,230,252,199,185,144,1,1,48,136,153,85,77,17,189,215,93,159,234,220,212,183,234,200,107,47,231,235,141,198,117,247,220,125,207,244,192,192,
192,165,101,15,1,240,214,206,221,177,209,75,35,95,28,28,24,120,130,179,29,183,223,241,248,19,61,138,128,27,138,88,144,207,19,158,87,56,30,1,38,159,59,56,226,49,32,233,156,207,47,228,226,196,96,34,6,132,
168,212,234,248,197,247,190,51,140,114,225,80,71,71,215,11,243,172,255,228,141,231,254,147,255,104,61,100,247,174,93,157,103,206,159,121,250,240,161,67,79,38,174,219,116,203,237,219,31,93,33,32,224,68,
39,22,236,174,114,239,203,177,174,239,7,190,209,29,132,220,243,238,245,46,52,174,151,184,32,186,160,2,66,16,19,107,138,34,250,238,184,171,125,106,102,62,55,118,118,104,101,54,174,119,222,186,109,219,169,
19,39,78,212,118,236,216,161,158,58,117,138,255,104,0,121,237,245,55,250,79,158,60,241,244,209,35,71,31,219,250,228,23,111,222,216,183,37,235,240,47,251,222,235,216,82,2,130,131,80,196,254,185,224,37,
38,41,116,69,193,67,112,189,247,30,46,195,96,221,166,27,211,122,71,119,199,208,222,221,221,2,98,237,199,250,251,71,126,254,243,159,207,124,238,201,207,233,67,67,67,244,145,7,228,87,191,254,245,35,135,
15,31,254,198,153,11,35,15,222,249,231,95,217,152,207,231,227,204,204,196,12,1,22,81,32,188,245,238,24,149,164,255,179,116,158,125,211,123,161,10,194,37,120,102,201,211,224,176,143,115,74,56,98,0,232,
232,236,138,245,124,108,107,231,209,215,94,206,198,59,187,183,246,109,188,126,252,249,255,126,126,228,35,205,33,135,143,28,137,141,142,142,126,241,232,145,35,79,212,211,237,183,255,201,163,143,245,40,
142,193,24,12,193,204,238,234,149,149,147,71,218,205,92,193,196,193,107,82,62,194,222,61,228,115,68,1,160,46,224,190,84,102,128,136,24,2,162,82,171,227,39,127,247,183,103,227,177,216,137,92,46,247,139,
151,95,126,249,71,31,73,15,57,118,236,88,231,233,161,161,191,217,191,127,255,103,179,253,219,110,187,249,158,123,187,5,132,23,125,68,16,223,217,247,142,80,216,241,137,29,62,31,64,6,202,243,14,137,95,124,
158,145,248,199,7,2,65,8,244,252,201,225,21,85,108,125,232,225,252,212,220,92,238,242,249,115,43,250,250,250,58,183,244,245,157,58,123,238,92,237,35,3,200,190,125,251,250,7,143,15,62,125,240,224,161,143,
111,120,248,19,91,214,111,218,212,238,91,14,44,130,184,223,194,88,236,38,130,254,221,164,240,35,3,135,128,224,61,32,73,6,13,0,131,34,64,248,156,239,147,189,195,42,2,235,54,109,78,233,249,174,252,153,253,
123,186,1,177,110,75,255,150,243,231,207,157,95,120,248,225,135,181,225,225,97,250,131,5,228,205,221,187,183,31,60,112,224,155,39,79,159,125,224,158,175,124,109,75,46,159,139,57,81,131,193,128,96,215,
42,228,115,65,192,27,178,225,32,121,7,135,136,58,240,42,217,184,236,162,72,78,44,12,56,73,86,108,33,85,38,220,252,133,133,23,10,59,186,186,98,61,253,219,58,143,189,241,74,182,209,176,214,223,184,121,243,
252,27,175,191,62,122,255,131,247,107,163,35,163,244,7,5,200,59,231,135,99,159,248,228,39,190,188,127,239,222,167,22,160,222,123,199,147,95,88,111,234,186,2,111,9,194,225,12,230,80,18,231,135,32,72,132,
205,18,145,67,226,20,41,31,132,148,22,6,74,76,150,202,178,26,243,176,112,125,70,150,206,142,163,64,120,222,98,26,166,182,250,182,187,186,79,31,58,208,102,91,246,198,13,55,108,74,88,243,246,209,139,19,
163,215,92,18,255,206,72,125,120,120,184,243,248,241,227,95,59,112,224,192,35,29,55,223,214,191,174,175,47,239,26,128,153,156,58,147,84,139,10,145,54,185,4,45,199,127,38,150,56,65,34,229,22,231,60,111,
107,69,244,44,189,167,69,132,98,165,134,90,163,142,134,109,195,178,109,20,171,53,84,170,53,88,100,131,201,185,15,17,49,24,130,152,48,252,210,11,163,229,203,23,47,100,179,217,151,98,166,254,189,93,187,
247,44,125,232,1,57,117,230,116,255,224,209,163,95,61,116,232,240,253,91,62,181,227,198,246,92,46,206,32,6,11,48,147,240,29,193,45,18,122,53,40,217,200,50,17,123,134,105,6,15,190,202,242,60,138,164,208,
68,204,168,91,13,148,170,53,212,45,11,181,186,133,165,74,5,213,122,195,207,244,73,126,63,34,199,91,200,1,151,152,28,112,157,215,216,125,14,177,48,58,60,247,238,107,191,122,39,157,105,123,51,149,76,124,
127,207,158,61,195,31,90,64,6,7,7,30,222,183,119,255,95,156,29,29,185,115,235,167,119,172,77,167,82,49,114,165,17,201,69,65,41,244,120,114,148,67,198,164,32,52,145,151,75,80,80,50,145,164,175,32,70,131,
108,20,42,53,212,27,13,44,86,171,40,86,106,78,56,34,10,60,143,60,15,164,38,111,36,167,74,236,2,194,254,123,145,255,94,12,178,137,93,113,32,42,133,197,202,217,159,254,232,92,60,30,223,159,74,166,254,227,
224,161,131,123,183,110,189,89,17,80,248,232,177,163,252,129,3,50,53,57,21,59,247,206,59,79,237,221,187,231,83,37,35,113,235,77,15,109,95,229,38,95,78,9,68,14,25,114,8,65,107,16,252,220,128,189,60,65,
184,70,34,84,26,22,138,213,26,234,13,11,133,90,5,10,171,136,233,42,152,9,229,122,29,149,134,5,171,97,185,128,217,32,114,69,3,147,31,250,124,35,51,193,193,199,134,87,51,11,131,227,2,67,4,114,20,130,155,
175,8,97,217,22,206,63,255,236,59,84,44,28,78,166,211,191,212,234,213,31,219,134,46,152,64,131,131,131,252,129,145,250,244,244,116,231,192,224,224,211,187,119,237,250,140,190,102,195,182,45,119,223,183,
66,8,207,234,126,27,73,226,218,168,228,148,43,181,236,24,200,243,32,102,44,150,171,88,170,86,48,54,191,136,201,197,34,230,74,101,20,171,85,212,27,22,18,134,129,174,182,36,122,219,179,200,165,18,80,133,
2,219,182,81,183,45,216,228,24,27,145,48,200,77,146,217,243,60,14,66,148,239,41,8,174,37,255,217,5,17,177,96,33,218,111,220,146,171,20,11,217,165,177,119,87,106,237,249,53,194,178,6,6,7,7,171,31,152,202,
122,247,226,197,254,35,135,15,61,253,246,158,183,63,190,126,251,39,111,233,93,119,93,155,247,212,236,53,137,88,6,65,74,223,130,172,47,164,180,230,43,21,204,151,43,184,52,183,136,153,66,9,75,213,42,74,
181,58,108,219,17,198,66,48,52,69,65,38,30,195,138,182,52,86,231,114,232,206,102,144,141,199,17,51,52,128,1,139,8,13,203,134,237,122,69,32,153,195,128,144,164,172,184,73,58,83,240,108,161,215,25,16,78,
18,201,204,72,173,90,147,81,226,137,244,212,201,193,30,8,177,174,103,213,202,115,83,83,211,243,191,119,64,206,156,59,191,125,207,174,93,223,60,122,226,196,3,91,119,124,169,63,149,76,234,126,80,98,39,217,
107,21,166,32,53,143,192,64,161,90,195,66,197,1,96,186,88,70,161,90,71,181,97,69,86,177,99,68,1,192,80,85,180,39,18,232,205,182,97,85,46,139,124,42,137,152,161,195,80,85,196,116,29,113,67,135,34,132,3,
74,195,130,69,228,115,65,200,176,104,225,17,126,225,210,229,53,247,156,204,37,210,115,9,175,204,31,203,117,164,50,215,111,106,159,56,122,48,103,219,180,118,229,202,21,211,51,51,179,151,126,47,128,212,
202,181,216,142,207,255,217,151,223,122,115,231,83,83,22,223,123,211,227,159,94,111,106,154,240,82,93,134,195,25,65,194,21,100,20,2,2,68,140,133,114,21,147,133,34,38,10,69,44,85,106,168,212,173,144,215,
180,226,24,69,8,196,117,13,29,169,36,86,183,103,209,211,158,65,54,145,128,161,169,80,132,128,34,4,84,161,192,208,53,196,117,3,186,170,192,38,66,221,114,250,235,54,145,212,75,137,170,58,242,243,29,242,
243,21,185,84,195,225,60,198,173,2,184,173,99,193,68,172,153,134,158,187,105,91,215,252,240,249,108,101,105,113,109,103,87,119,204,140,103,143,23,11,243,88,187,118,173,178,184,184,200,215,28,144,106,173,
214,121,248,216,145,167,223,220,185,243,179,230,134,205,183,109,220,118,91,183,170,170,194,253,88,126,214,45,16,73,190,108,194,66,165,134,177,197,37,204,20,203,40,213,235,176,108,10,12,35,129,64,82,229,
214,251,240,170,34,144,52,13,116,165,211,232,205,103,209,221,150,70,42,22,131,174,42,80,132,128,16,142,62,17,66,64,81,20,24,154,138,184,97,192,208,52,0,140,134,101,193,178,109,39,236,69,90,191,144,248,
202,249,145,164,6,23,66,101,154,80,216,10,229,81,14,40,0,68,251,13,125,185,90,165,156,93,26,191,212,99,26,106,87,123,123,251,169,209,209,209,234,234,222,94,101,105,105,137,175,25,32,139,133,165,254,131,
251,14,60,189,107,215,91,31,95,251,208,99,183,116,245,172,202,248,133,11,246,248,66,94,129,140,133,74,21,99,139,69,204,150,43,40,213,27,32,138,84,109,131,193,4,41,131,150,242,9,16,12,85,65,38,22,119,248,
34,159,69,103,58,137,132,105,64,83,20,31,136,144,116,20,128,34,20,232,170,130,184,161,195,212,117,8,8,88,182,141,134,77,176,108,27,240,20,29,59,34,130,90,24,220,255,226,22,252,227,113,16,228,60,8,194,
235,251,167,86,174,206,232,237,249,236,236,217,83,43,205,124,231,77,41,93,59,115,105,108,108,246,154,121,200,228,212,212,131,111,238,220,249,205,131,3,3,15,108,249,204,231,63,150,76,196,13,63,192,184,
178,214,11,77,75,213,26,38,138,37,204,148,202,40,213,172,72,252,165,80,165,150,201,205,51,164,226,160,119,47,69,0,134,166,161,61,145,64,79,182,13,189,185,54,228,146,9,152,154,6,53,10,4,115,211,143,66,
8,104,170,138,152,161,35,166,107,80,21,197,1,197,245,22,143,59,40,186,218,189,133,225,169,61,185,191,226,183,128,195,234,45,224,34,8,47,223,49,51,217,68,122,253,198,220,229,3,191,73,49,120,117,182,45,
59,85,40,20,198,254,223,128,76,78,78,222,183,123,247,238,191,26,153,95,186,191,255,177,79,109,212,20,69,184,34,74,120,97,202,102,194,76,169,130,137,66,9,197,90,3,150,212,143,64,52,30,195,1,128,41,18,163,
165,85,170,8,32,174,107,200,39,83,232,205,101,208,147,205,160,45,30,135,238,242,69,4,13,73,88,115,228,187,128,166,8,152,186,142,152,161,67,87,85,16,49,26,150,237,135,48,199,152,144,164,120,64,244,225,
30,12,75,158,36,71,3,132,188,198,205,239,4,17,177,98,152,70,174,255,150,174,133,225,243,169,122,185,220,153,105,107,43,148,138,197,145,223,26,144,197,197,197,45,251,247,31,248,234,217,177,241,251,54,61,
176,253,58,85,192,45,79,67,48,24,165,122,3,19,133,18,102,75,85,212,44,91,138,185,158,146,162,160,225,68,184,66,46,192,32,225,44,75,1,134,42,4,82,166,137,206,76,10,189,185,54,116,165,83,72,153,102,19,95,
32,220,161,109,81,104,116,194,23,0,40,138,128,161,170,72,24,6,98,186,238,242,138,141,6,217,176,109,187,69,201,70,42,207,48,34,231,229,194,165,23,94,157,177,24,146,60,142,33,4,147,205,0,68,219,198,205,
29,197,75,239,38,234,197,66,60,149,78,141,148,203,229,233,255,51,32,68,212,189,111,223,190,191,62,116,232,224,3,155,30,255,108,159,174,8,215,108,16,139,213,26,198,150,138,40,212,26,176,41,154,125,123,
213,217,48,49,59,225,138,155,245,190,63,37,2,232,170,130,182,120,12,43,50,105,172,110,111,67,62,149,64,220,208,161,169,18,16,204,173,67,149,132,76,48,243,224,8,12,120,188,162,169,136,155,58,98,134,1,85,
40,104,88,13,212,27,78,18,73,82,190,130,232,162,193,21,18,76,119,154,69,6,207,47,110,186,179,74,204,204,130,133,72,175,223,144,159,26,56,168,51,113,58,153,74,157,170,84,42,133,171,6,196,178,44,109,104,
104,104,199,222,125,251,30,95,243,240,227,55,199,76,83,7,131,23,170,53,113,185,80,66,169,209,8,145,119,216,141,37,87,150,98,179,223,243,110,82,41,78,188,55,53,21,185,68,28,61,217,12,86,181,103,208,158,
112,248,66,81,132,83,13,111,46,176,95,1,24,52,21,228,61,213,167,184,188,146,48,12,196,76,29,170,80,96,17,161,222,240,120,133,66,109,99,105,216,206,149,195,81,245,133,200,168,145,20,13,224,95,39,136,137,
133,16,162,109,195,230,220,236,201,1,2,115,209,48,245,227,245,90,61,244,184,218,149,0,153,157,157,93,63,52,52,116,143,177,122,253,166,84,34,25,91,170,214,121,166,92,17,204,173,230,157,88,74,166,228,18,
55,133,75,15,28,244,175,217,43,191,123,124,161,105,200,37,19,88,145,73,161,51,149,68,210,52,160,169,74,83,177,141,67,228,221,138,57,228,184,37,249,140,219,128,97,33,160,0,48,117,13,29,233,20,116,69,129,
169,107,48,53,21,151,231,22,176,84,170,160,46,21,31,185,85,22,15,68,212,88,192,39,212,148,124,194,227,35,193,4,86,204,184,153,221,220,127,195,194,208,241,187,85,85,221,5,96,248,170,0,25,190,120,233,214,
177,177,177,13,157,247,111,207,95,88,112,60,203,83,66,36,203,64,175,41,26,116,74,253,7,38,153,248,154,228,35,65,48,160,42,10,146,134,142,124,42,129,149,109,105,228,18,113,196,13,29,170,226,129,17,14,63,
239,13,12,71,251,83,87,12,113,66,8,24,154,134,108,50,233,40,49,93,131,169,105,184,56,51,139,249,66,9,181,122,61,212,95,9,86,124,139,124,73,202,95,130,206,38,133,19,74,111,49,10,160,189,239,230,174,185,
147,3,27,1,220,21,5,68,109,237,253,156,60,49,56,240,212,165,153,185,91,236,158,117,221,64,48,23,27,14,83,20,138,153,65,108,165,80,168,226,232,16,130,251,144,186,42,144,78,196,176,178,45,141,85,217,12,
58,220,18,136,166,4,158,193,173,86,251,149,60,166,213,121,110,253,123,240,165,181,128,174,57,33,44,110,24,16,66,160,97,219,168,219,13,216,182,29,148,236,165,100,209,95,114,28,8,22,106,202,252,35,163,71,
236,214,246,152,1,69,85,27,229,18,215,231,102,39,77,211,56,80,175,55,234,239,233,33,243,243,243,218,220,220,92,79,124,205,250,52,17,65,40,130,131,62,51,34,179,9,20,46,43,184,117,7,162,112,27,53,120,88,
39,116,152,186,134,108,60,134,238,76,10,93,233,36,210,49,19,134,170,134,67,84,139,220,130,163,43,190,101,168,194,21,68,48,183,84,99,138,162,32,97,26,88,209,222,6,67,115,188,197,208,20,92,158,95,64,185,
90,69,195,98,255,179,122,156,71,18,217,19,113,104,50,6,161,233,151,166,34,42,3,44,146,61,107,50,133,119,78,175,85,160,230,1,20,223,19,144,241,241,113,181,82,169,164,148,68,155,69,206,187,11,142,104,109,
150,164,173,239,142,178,210,16,220,148,103,48,51,20,8,36,76,29,185,132,163,164,114,201,4,146,166,147,31,68,13,205,45,188,224,74,124,130,43,120,71,171,27,114,4,57,225,102,161,166,174,163,35,147,134,238,
22,41,77,93,195,248,204,60,22,74,101,84,237,122,75,249,75,242,152,43,1,44,24,108,71,234,95,44,75,97,8,38,192,200,229,147,204,72,91,68,89,0,163,239,9,72,161,80,16,68,164,10,33,92,5,36,21,8,41,188,218,209,
74,194,134,134,157,3,3,233,170,64,82,55,208,153,78,162,59,147,66,123,60,134,184,174,195,201,51,221,164,129,185,153,23,208,236,29,87,34,119,92,41,69,12,77,175,52,247,101,188,226,165,161,105,104,79,37,93,
121,108,32,174,27,24,157,154,198,244,226,18,170,141,186,52,116,7,169,173,140,240,224,133,92,77,134,148,244,74,157,81,161,235,134,106,198,18,84,175,165,222,151,212,147,201,36,11,119,60,201,225,3,197,127,
136,112,110,196,145,169,255,32,81,146,203,32,10,28,242,206,196,12,116,165,147,232,78,167,144,77,196,96,168,26,60,44,194,198,198,123,134,42,190,66,142,46,11,128,43,121,79,100,48,174,117,182,172,170,72,
199,226,80,243,10,116,85,117,170,3,138,130,169,249,69,148,185,6,178,2,66,151,155,90,96,246,187,147,44,130,134,22,75,189,58,7,20,6,20,85,17,134,105,114,173,170,190,47,32,189,189,189,246,177,99,199,202,
5,203,210,188,184,231,52,155,60,231,36,183,15,29,157,228,136,148,169,93,73,107,104,10,178,102,220,229,139,4,82,166,1,93,81,253,44,186,149,153,155,87,112,235,100,176,21,229,112,20,184,22,94,133,150,156,
228,42,48,6,132,34,16,55,60,94,209,96,234,58,76,77,197,216,236,60,138,229,10,200,178,92,153,139,200,200,82,96,7,138,10,27,146,162,138,77,12,171,97,71,63,67,75,64,218,218,218,172,108,54,59,51,122,225,93,
78,245,172,3,131,194,61,113,121,148,147,35,234,74,10,97,2,128,169,106,200,37,98,232,78,167,145,79,198,145,48,116,40,66,129,237,230,35,225,25,170,200,10,102,132,11,122,161,235,100,113,129,208,224,27,71,
212,85,235,123,134,95,231,200,125,188,207,161,42,42,178,201,4,214,119,117,66,115,123,46,23,167,102,177,88,46,163,97,53,130,156,132,16,46,185,32,154,8,75,52,207,12,38,219,182,27,141,42,132,40,191,47,32,
170,170,150,118,238,254,205,5,58,122,180,36,216,110,48,132,30,66,93,170,212,18,34,210,206,47,30,50,52,33,96,104,10,76,77,3,4,187,3,8,13,103,138,80,138,227,44,13,87,203,198,8,201,236,200,74,247,227,179,
220,229,131,164,249,101,131,52,21,48,195,234,47,252,158,225,235,156,251,147,211,187,17,2,9,211,68,76,215,80,80,68,104,168,47,36,122,16,86,157,65,242,236,220,156,24,162,54,59,179,8,171,81,18,138,82,184,
170,196,112,195,186,181,191,25,234,236,124,164,120,241,66,187,210,187,174,11,222,162,151,36,95,64,234,104,150,120,12,216,96,148,235,13,16,149,176,88,174,52,247,181,253,214,169,52,155,5,105,204,135,194,
201,151,63,55,229,164,191,161,233,119,150,70,125,32,159,39,114,103,130,25,176,57,244,236,94,232,141,142,31,133,158,131,188,46,34,193,34,66,185,90,195,82,165,10,219,178,165,74,69,100,204,149,25,118,36,
7,161,224,115,11,102,70,125,118,178,10,33,166,84,136,169,171,2,164,183,183,247,112,95,95,223,192,206,157,59,175,107,95,189,62,91,39,50,220,61,3,161,246,44,249,250,27,210,176,154,3,144,109,51,108,139,221,
193,52,231,53,155,32,37,149,146,17,229,158,9,59,243,84,254,48,27,177,100,188,72,127,219,187,214,87,49,193,252,85,243,189,162,191,75,254,152,143,63,135,69,210,112,156,123,173,127,63,34,216,204,176,201,
6,217,220,34,9,108,230,14,47,129,244,55,159,186,5,232,249,19,71,47,43,138,114,178,90,111,44,93,21,32,66,136,122,177,88,252,175,243,231,207,111,186,124,120,111,44,118,203,157,171,108,247,1,5,3,182,183,
58,228,21,138,208,74,240,103,205,153,200,175,241,16,219,129,81,165,15,234,164,59,225,21,75,210,42,151,141,72,20,245,12,2,185,179,85,142,81,221,178,191,236,121,254,53,18,112,222,190,67,255,58,242,231,192,
56,116,46,32,229,160,34,76,209,90,149,60,145,18,40,44,105,154,223,203,85,22,143,31,26,83,20,101,68,81,148,125,141,70,45,68,236,202,123,149,223,83,169,212,225,187,239,185,247,21,179,86,30,231,201,177,89,
38,22,236,139,174,240,240,66,16,131,169,117,88,114,203,15,45,115,24,132,55,228,132,86,151,163,35,65,210,148,161,92,220,35,169,242,74,114,125,141,162,163,162,209,24,31,212,168,32,135,41,242,188,93,62,39,
66,17,32,218,166,150,84,78,160,166,100,145,225,79,61,66,88,165,197,98,225,236,208,164,170,169,251,148,134,117,52,106,115,229,253,26,84,55,108,220,248,239,219,31,125,244,245,198,217,227,99,202,228,165,
113,105,187,153,143,139,223,120,242,243,34,106,218,25,235,23,232,34,218,61,4,30,73,221,68,169,149,75,110,243,7,209,94,75,100,68,40,84,214,119,139,155,130,195,234,39,148,97,135,122,226,104,2,77,238,227,
80,104,232,194,201,51,252,159,73,106,190,73,109,97,223,123,156,4,93,88,197,165,165,137,151,255,231,178,166,107,123,84,69,251,241,98,181,66,87,37,123,67,23,104,106,133,153,255,94,0,213,23,94,120,241,211,
176,44,13,43,87,119,185,43,149,1,18,114,121,154,56,92,47,242,213,153,180,89,38,60,86,26,94,241,161,221,181,161,30,123,115,245,20,64,83,241,146,34,109,215,144,122,139,128,128,72,254,20,42,11,73,94,66,114,
5,183,105,224,14,161,109,19,8,229,66,236,86,148,72,80,169,88,152,124,245,133,73,221,48,222,208,53,245,95,166,167,103,38,91,218,251,170,6,128,133,168,216,220,248,71,85,85,151,94,125,245,213,39,166,199,
222,181,82,219,238,206,215,45,219,244,233,157,156,189,30,34,104,246,251,45,220,166,228,49,164,72,2,53,3,193,32,91,86,110,104,34,76,14,216,89,82,76,238,66,32,180,12,41,242,112,5,49,34,109,128,230,45,15,
33,111,243,85,31,252,73,124,31,2,225,252,233,14,185,132,226,60,19,5,127,57,66,48,74,67,199,199,150,206,156,152,51,13,227,21,93,215,190,51,49,49,121,241,154,13,91,79,78,77,60,246,210,75,47,127,233,212,
201,83,183,39,183,222,153,165,108,46,31,244,164,193,110,199,205,169,12,135,166,201,57,66,144,129,186,33,150,101,42,135,207,49,133,254,108,6,113,64,242,254,189,73,50,58,201,215,160,197,20,123,32,28,66,
215,129,124,227,58,74,43,188,29,193,25,192,14,164,50,201,207,230,171,59,119,203,2,179,96,48,96,53,234,83,175,190,48,193,181,234,176,97,154,47,2,248,215,137,137,137,202,53,159,126,47,22,10,107,143,28,59,
246,245,189,111,191,125,215,244,244,244,250,196,230,155,76,116,175,94,217,176,173,176,177,37,213,36,43,38,10,237,205,8,27,8,44,127,88,137,200,153,155,64,33,255,61,40,84,154,160,144,178,106,222,8,228,252,
78,144,95,52,191,55,251,192,162,233,57,40,104,231,122,42,76,250,29,6,163,49,55,61,93,60,121,172,94,155,157,158,213,117,125,159,110,154,207,93,28,29,125,229,119,190,29,97,126,110,174,127,255,129,3,59,134,
134,134,110,25,31,31,191,30,153,246,54,189,103,181,170,100,178,177,186,170,183,249,106,131,60,133,197,254,42,228,72,227,199,249,80,182,223,6,101,105,223,70,56,111,144,228,170,231,97,196,161,237,6,158,
113,109,146,183,53,144,36,103,37,249,28,146,229,174,55,248,0,147,68,204,14,240,222,125,229,156,6,54,89,213,201,75,83,214,210,130,90,24,58,94,20,138,152,208,53,125,64,55,140,55,152,249,165,145,11,23,174,
250,143,167,93,147,253,33,147,83,83,43,207,158,57,115,231,216,216,216,237,227,227,227,55,204,205,205,117,87,107,181,132,109,219,102,163,209,48,109,34,213,15,51,36,25,131,91,159,11,60,64,250,206,145,130,
102,228,126,50,120,68,50,56,145,235,66,43,58,250,94,145,231,144,67,155,4,10,121,177,25,220,128,16,117,178,172,50,132,88,208,84,117,88,85,213,65,77,211,222,98,193,103,207,12,157,177,63,240,29,84,163,35,
35,166,69,212,115,122,104,40,51,57,49,209,94,171,215,227,182,109,43,150,101,11,128,217,178,44,225,172,64,27,182,229,132,15,219,118,62,172,237,78,125,16,185,241,220,157,90,39,34,119,38,215,14,140,109,187,
25,51,145,251,207,53,162,219,118,181,217,6,217,94,18,25,220,135,200,125,221,246,128,178,157,12,220,187,15,19,200,38,127,27,131,243,44,182,243,186,115,142,109,34,193,76,204,196,53,8,81,48,116,125,94,85,
148,217,195,71,142,204,98,249,88,62,150,143,223,225,241,191,6,28,131,21,25,103,162,195,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LivePanelComponent::gmfullOn_2x_png = (const char*) resource_LivePanelComponent_gmfullOn_2x_png;
const int LivePanelComponent::gmfullOn_2x_pngSize = 6348;

// JUCER_RESOURCE: gmfadeOn_2x_png, 6576, "../Images/GMFadeOn@2x.png"
static const unsigned char resource_LivePanelComponent_gmfadeOn_2x_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,100,0,0,0,60,8,6,0,0,0,144,63,31,206,0,0,0,1,115,82,71,66,0,174,206,28,
233,0,0,0,6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,219,10,30,15,54,50,4,204,249,137,0,0,25,48,73,68,65,84,120,218,
237,124,87,144,28,231,117,238,247,247,76,79,222,73,155,128,5,22,129,4,8,98,161,37,65,82,164,152,84,164,116,41,74,164,146,101,21,28,164,107,251,150,111,217,86,93,21,253,238,55,151,203,246,147,253,224,80,
78,101,151,85,46,219,117,101,149,116,233,75,217,98,38,5,8,68,14,187,8,139,196,197,46,54,96,243,236,196,206,231,248,161,211,223,61,43,17,182,33,43,120,155,69,0,219,211,211,225,124,255,9,223,119,78,47,176,
185,109,110,155,219,230,182,185,109,110,155,219,230,182,185,221,253,77,252,164,221,240,215,190,246,181,108,203,180,6,151,230,231,250,180,118,187,87,215,244,162,105,91,25,199,182,147,68,4,0,4,160,173,170,
106,43,149,201,45,101,42,165,149,180,109,173,254,238,239,254,94,123,19,144,187,180,253,211,215,191,94,153,91,89,125,160,182,176,48,90,111,212,247,53,26,141,237,6,241,64,178,80,44,246,244,13,228,179,165,
114,58,145,84,4,132,34,12,173,227,232,237,142,125,251,202,165,154,99,232,173,4,209,74,42,147,158,207,102,50,23,243,229,202,197,92,42,121,225,15,255,224,15,215,55,1,249,15,108,47,191,252,114,117,102,110,
246,51,179,183,102,30,95,90,90,218,155,219,190,99,207,208,222,253,165,254,225,29,133,124,54,171,10,1,48,0,16,131,1,48,51,192,12,2,192,228,192,118,8,173,118,219,158,185,50,177,62,117,249,66,189,57,115,
243,102,46,87,184,90,238,237,61,89,204,101,191,243,199,127,242,39,203,155,128,220,193,246,237,111,255,75,121,118,110,230,99,243,243,183,63,62,61,53,245,200,150,7,31,189,119,228,137,39,251,51,106,82,48,
0,118,67,19,200,3,128,153,153,25,238,103,76,0,49,19,88,0,0,59,12,8,6,19,163,99,154,124,241,189,163,43,87,222,125,253,106,185,92,62,95,44,151,223,204,103,50,111,253,197,95,254,101,107,19,144,239,179,125,
227,155,223,28,157,186,57,249,11,215,175,93,127,162,119,100,244,254,253,31,121,122,75,38,173,10,102,6,19,51,131,193,204,194,3,2,204,128,187,207,5,35,234,37,12,184,199,51,24,238,247,192,232,232,38,206,
29,126,103,225,230,177,195,23,122,123,123,143,247,85,171,95,251,171,191,254,235,201,31,135,231,79,252,56,129,241,245,111,124,227,19,23,198,198,126,227,250,212,244,255,248,232,255,250,245,71,118,238,189,
175,168,38,18,130,136,24,128,96,64,128,88,64,0,96,128,33,224,90,26,193,223,64,24,198,220,31,220,3,25,16,0,131,152,57,145,84,196,246,123,238,45,244,239,27,217,118,246,205,215,122,77,203,186,231,169,39,
159,90,30,27,27,155,221,244,16,0,223,125,231,72,102,122,118,234,75,227,99,99,159,229,114,223,99,31,121,241,179,67,138,128,23,138,88,80,144,39,124,175,112,61,2,76,65,238,224,152,199,128,164,125,65,126,
33,15,39,6,19,49,32,132,102,152,248,231,63,255,163,73,116,154,167,251,250,6,94,169,177,250,15,111,127,243,31,249,191,173,135,28,57,124,184,255,234,141,171,47,157,57,125,250,139,185,123,246,61,244,216,
243,159,220,34,32,224,70,39,22,236,173,114,255,63,215,186,129,31,4,70,119,17,242,246,123,199,123,208,120,94,226,129,232,129,10,8,65,76,156,84,20,49,242,145,39,42,75,43,181,234,220,181,137,173,229,172,
218,255,200,195,15,95,190,120,241,162,113,232,208,161,196,229,203,151,249,191,13,32,111,190,245,246,232,165,75,23,95,58,119,246,220,11,7,191,248,165,7,247,142,28,40,187,249,151,3,239,117,109,41,1,193,
97,40,226,96,95,248,17,147,20,186,226,224,33,60,222,191,134,151,97,176,107,223,253,61,106,223,96,223,196,177,35,131,2,98,231,135,70,71,167,190,245,173,111,173,252,236,23,127,86,157,152,152,160,159,122,
64,254,245,59,223,249,196,153,51,103,126,227,234,205,169,143,61,254,139,191,178,183,183,183,55,203,204,76,204,16,96,17,7,194,95,239,174,81,73,250,153,165,253,28,152,222,15,85,16,94,130,103,150,60,13,110,
246,113,119,9,183,24,0,250,250,7,50,67,31,58,216,127,238,205,215,202,217,254,193,131,35,123,239,157,127,249,255,189,60,245,83,157,67,206,156,61,155,153,158,158,254,210,185,179,103,63,107,246,84,30,251,
240,39,95,24,82,92,131,49,24,130,153,189,213,43,87,78,126,210,238,206,21,76,28,126,38,241,17,246,207,33,239,35,10,1,245,0,15,74,101,6,136,136,33,32,52,195,196,63,252,246,111,93,203,102,50,23,171,213,234,
63,191,246,218,107,127,247,83,233,33,231,207,159,239,191,50,49,241,155,39,78,156,248,66,121,244,225,71,31,124,234,233,65,1,225,71,31,17,198,119,14,188,35,18,118,130,196,142,32,31,64,6,202,247,14,41,191,
4,121,70,202,63,1,16,8,67,160,239,79,110,94,73,136,131,31,127,174,119,105,109,173,122,251,198,245,45,35,35,35,253,7,70,70,46,95,187,126,221,248,169,1,228,248,241,227,163,227,23,198,95,58,117,234,244,167,
246,60,247,233,3,187,247,237,171,4,150,3,139,48,238,111,96,44,246,136,96,112,54,41,252,200,192,33,76,240,62,144,36,131,6,128,65,49,32,130,156,31,36,123,55,171,8,236,218,183,191,160,246,14,244,94,61,113,
116,16,16,187,14,140,30,184,113,227,250,141,245,231,158,123,46,57,57,57,73,63,177,128,188,123,228,200,243,167,78,158,252,202,165,43,215,158,125,234,87,126,237,64,181,183,154,113,163,6,131,1,193,158,85,
40,200,5,97,222,144,13,7,201,59,56,146,168,67,175,146,141,203,30,138,228,198,194,48,39,201,21,91,164,42,19,30,127,97,225,135,194,190,129,129,204,208,232,195,253,231,223,126,189,108,89,246,238,251,247,
239,175,189,253,214,91,211,207,124,236,153,228,244,212,52,253,68,1,242,254,141,201,204,167,63,243,233,95,62,113,236,216,151,215,145,120,250,35,95,252,133,221,105,85,85,224,47,65,184,57,131,57,66,226,130,
16,4,41,97,179,148,200,33,229,20,137,15,66,162,133,97,37,38,151,202,114,53,230,99,225,249,140,92,58,187,142,2,225,123,75,58,149,78,14,63,250,196,224,149,211,39,75,142,237,236,221,115,223,190,156,93,115,
206,205,44,76,223,245,146,248,135,150,212,39,39,39,251,47,92,184,240,107,39,79,158,252,68,223,131,143,142,238,26,25,233,245,12,192,76,174,206,36,105,81,145,164,77,94,130,150,227,63,19,75,57,65,74,202,
27,236,243,189,109,163,68,207,210,53,109,34,180,52,3,134,101,194,114,28,216,142,131,150,110,64,211,13,216,228,128,201,61,15,17,49,24,130,152,48,249,234,43,211,157,219,51,55,203,229,242,171,153,180,250,
231,135,143,28,109,252,216,3,114,249,234,149,209,241,115,231,126,245,244,233,51,207,28,248,220,161,251,43,213,106,150,65,12,22,96,38,17,56,130,39,18,250,26,148,108,100,57,17,251,134,233,6,47,212,171,92,
57,197,53,178,31,154,136,25,166,109,161,173,27,48,109,27,134,105,163,161,105,208,77,43,96,250,36,95,143,200,245,22,114,193,37,38,23,92,247,51,246,238,67,172,79,79,174,221,122,243,95,223,239,41,150,222,
45,228,115,127,113,244,232,209,201,31,91,64,198,199,199,158,59,126,236,196,255,188,54,61,245,248,193,207,31,218,217,83,40,100,200,43,141,72,22,5,165,208,227,151,163,44,197,121,242,74,81,95,6,33,201,11,
32,1,8,0,89,53,9,53,161,160,169,27,168,181,218,88,106,52,209,212,12,55,28,17,133,158,71,190,7,82,151,55,146,171,18,123,128,112,112,45,10,174,197,32,135,216,43,14,132,214,172,107,215,254,233,239,174,103,
179,217,19,133,124,225,111,79,157,62,117,236,224,193,7,21,1,133,207,157,63,199,63,114,64,150,22,151,50,215,223,127,255,203,199,142,29,253,92,59,149,123,228,129,143,63,191,205,35,95,174,4,34,135,12,57,
132,96,99,16,2,110,192,62,79,16,158,145,8,154,101,163,165,27,176,108,7,12,194,150,98,17,91,74,61,176,29,7,179,107,235,152,173,173,163,209,214,92,0,224,128,200,43,26,152,130,208,23,24,153,9,46,62,14,124,
205,44,10,142,7,12,17,200,173,16,60,190,34,132,237,216,184,241,242,215,223,167,86,243,76,190,167,231,95,146,166,254,247,78,74,21,76,160,241,241,113,254,145,37,245,229,229,229,254,177,241,241,151,142,28,
62,252,51,234,142,61,15,31,120,242,163,91,132,240,173,30,180,145,164,92,27,47,57,101,165,150,93,3,249,30,196,140,122,71,71,67,215,48,87,171,99,177,222,194,90,187,3,205,52,145,85,85,236,168,86,176,165,
212,131,92,74,69,42,145,64,62,149,70,82,8,24,182,13,195,182,64,78,140,80,162,123,33,132,158,199,97,136,10,60,5,225,177,20,220,187,32,34,22,44,68,229,254,3,85,173,213,44,55,230,110,109,77,86,122,119,8,
219,30,27,31,31,215,127,100,85,214,173,153,153,209,179,103,78,191,244,222,209,247,62,181,251,249,207,60,180,125,215,61,37,255,174,217,111,18,177,12,130,68,223,66,214,23,169,180,106,154,134,90,71,195,236,
90,29,43,205,54,26,186,142,182,97,194,113,220,194,56,149,80,208,87,200,99,87,95,21,125,133,28,52,203,198,124,173,142,122,71,67,54,173,162,148,203,34,173,38,97,90,54,52,203,253,94,88,50,71,1,33,169,178,
226,174,210,153,194,123,139,124,206,128,112,73,36,51,163,176,109,71,81,201,230,122,150,46,141,15,65,136,93,67,219,182,94,95,90,90,174,253,151,3,114,245,250,141,231,143,30,62,252,149,115,23,47,62,123,240,
208,47,141,22,242,121,53,8,74,236,146,189,141,194,20,164,230,17,24,104,234,6,214,53,23,128,229,86,7,77,221,132,110,217,177,85,236,26,49,157,76,96,75,169,7,59,123,171,168,228,178,168,107,58,166,86,86,49,
189,178,134,90,187,13,203,113,144,79,167,80,201,103,145,86,85,88,182,3,221,178,97,57,78,183,97,177,129,71,4,194,165,151,215,188,125,114,46,145,238,75,248,50,127,166,218,87,40,222,187,175,178,112,238,84,
213,113,104,231,214,173,91,150,87,86,86,103,255,75,0,49,58,70,230,208,207,255,220,47,127,247,221,119,190,188,100,243,211,15,188,248,249,221,233,100,82,248,84,151,225,230,140,144,112,133,140,66,64,128,
136,177,222,209,177,216,108,97,161,217,66,67,51,160,153,118,196,107,54,202,49,249,84,10,91,75,69,236,168,86,144,79,169,88,109,183,49,181,178,134,197,245,6,218,166,9,195,180,209,54,44,152,182,141,140,154,
68,37,159,67,62,147,6,17,67,55,45,24,182,45,245,82,226,85,29,5,124,135,2,190,34,75,53,28,229,49,158,10,224,181,142,5,19,113,50,157,82,171,15,60,60,80,155,188,81,214,26,245,157,253,3,131,153,116,182,124,
161,213,172,97,231,206,157,74,189,94,231,187,14,136,110,24,253,103,206,159,125,233,221,119,222,249,66,122,207,254,71,247,62,252,232,96,34,145,16,222,99,5,172,91,32,70,190,28,194,186,102,96,174,222,192,
74,171,131,182,105,194,118,40,52,140,4,2,73,202,173,23,29,208,147,73,97,91,181,132,237,229,18,212,164,130,197,122,11,55,87,214,176,210,108,65,183,236,160,204,181,108,27,29,195,132,102,90,80,147,73,84,
114,89,244,100,51,96,6,58,134,1,211,178,187,90,191,144,242,149,251,79,146,26,92,136,200,52,145,176,21,225,81,46,40,0,68,229,190,145,170,161,117,202,141,249,217,161,116,42,49,80,169,84,46,79,79,79,235,
195,219,183,43,141,70,131,239,26,32,245,102,99,244,212,241,147,47,29,62,252,221,79,237,252,248,11,15,13,12,109,43,6,194,5,251,249,66,94,129,140,117,77,199,92,189,133,213,142,134,182,105,129,40,158,100,
131,193,4,137,65,115,192,15,20,193,168,230,179,24,238,173,96,107,177,7,12,198,92,173,129,169,149,53,212,90,237,32,20,201,158,101,147,75,240,58,186,14,69,81,80,202,101,81,206,101,161,40,138,203,71,44,211,
229,64,190,135,16,2,182,206,113,239,140,228,149,238,253,36,253,27,128,240,251,254,133,173,195,69,181,210,91,94,189,118,121,107,186,183,255,129,130,154,188,58,59,55,183,122,215,60,100,113,105,233,99,239,
190,243,206,87,78,141,141,61,123,224,103,126,254,67,249,92,54,21,152,193,43,107,253,208,212,208,13,44,180,218,88,105,119,208,54,236,88,252,165,136,82,203,228,241,12,73,28,244,207,149,84,4,170,249,60,118,
244,86,208,223,83,128,105,219,184,181,86,195,204,106,13,245,142,22,50,125,153,40,122,237,116,34,66,91,55,208,214,13,0,140,158,108,22,213,124,14,73,69,192,116,108,232,150,5,135,92,115,82,124,181,251,11,
195,175,246,228,254,74,208,2,70,100,97,133,185,8,194,231,59,233,98,57,215,179,123,111,245,246,201,239,21,24,60,92,46,149,151,154,205,230,220,127,26,144,197,197,197,143,30,57,114,228,127,79,213,26,207,
140,190,240,185,189,73,69,17,94,17,37,252,48,229,48,97,165,173,97,161,217,70,203,176,96,75,253,8,196,227,49,92,0,152,98,49,90,90,165,169,100,2,3,61,121,236,168,86,80,201,103,209,210,117,76,175,172,97,
174,214,64,75,55,98,189,117,105,5,123,92,193,27,104,128,102,154,104,233,58,136,24,61,153,52,42,61,121,100,84,21,166,237,64,51,45,216,182,227,25,19,82,41,30,38,250,104,15,134,37,79,146,163,1,34,94,227,
241,59,65,68,172,164,210,169,234,232,67,3,235,147,55,10,102,167,211,95,44,149,154,237,86,107,234,63,12,72,189,94,63,112,226,196,201,95,189,54,55,255,209,125,207,62,127,79,66,192,147,167,33,24,140,182,
105,97,161,217,198,106,91,135,97,59,82,204,245,43,41,10,27,78,132,239,195,5,24,36,66,197,47,155,76,98,107,177,128,225,222,10,122,50,41,172,181,59,152,90,94,195,237,122,3,186,101,69,194,7,249,18,8,100,
195,72,98,36,51,12,203,70,83,215,97,57,132,124,42,133,106,33,143,92,58,5,219,113,65,177,28,187,139,171,200,125,120,102,196,246,35,226,153,228,55,116,188,68,31,122,174,16,76,14,3,16,165,189,251,251,90,
179,183,114,102,171,153,45,244,20,166,58,157,206,242,191,27,16,34,26,60,126,252,248,255,57,125,250,212,179,251,94,252,194,136,170,8,223,108,162,174,27,152,107,180,208,52,44,56,20,103,223,190,65,56,218,
111,0,197,226,52,34,83,34,128,64,33,157,194,80,185,136,237,149,50,50,106,18,203,141,22,110,174,172,98,185,209,130,233,56,94,207,92,206,55,212,101,48,159,208,65,154,211,50,29,27,45,77,135,110,91,72,39,
147,168,246,20,80,204,102,0,38,104,134,9,211,182,36,47,69,196,91,57,210,199,223,40,185,83,4,188,64,220,244,102,149,152,153,5,11,209,179,123,79,239,210,216,41,149,137,123,242,133,194,101,77,211,154,119,
12,136,109,219,201,137,137,137,67,199,142,31,127,113,199,115,47,62,152,73,167,85,48,120,93,55,196,237,102,27,109,203,138,36,239,168,27,75,174,44,197,230,160,231,221,85,165,0,66,8,148,178,41,108,175,20,
177,181,84,132,34,4,22,234,13,220,90,93,199,106,171,5,199,145,174,129,168,106,43,223,71,52,124,68,13,107,58,14,218,154,1,205,50,145,80,18,232,237,201,163,148,203,1,2,110,89,108,90,222,106,167,72,139,24,
8,189,81,94,76,144,159,89,234,219,67,82,27,188,227,4,49,177,16,66,148,246,236,175,174,94,26,35,48,183,82,105,245,130,105,152,124,71,128,124,245,171,95,189,247,204,153,51,95,50,202,125,79,12,108,27,46,
55,13,139,231,155,109,161,5,101,99,236,38,130,90,94,54,22,69,165,7,14,251,215,236,203,239,96,36,132,64,37,151,193,112,165,132,193,98,15,136,8,115,181,58,102,86,215,177,222,233,192,113,200,19,23,253,170,
40,218,182,149,135,28,72,82,129,195,156,21,182,130,45,199,65,71,55,209,49,116,8,8,148,242,89,84,242,57,36,19,9,24,150,141,142,110,70,193,222,136,197,3,177,106,44,204,39,212,69,62,225,231,35,193,4,22,137,
100,146,108,43,165,45,47,234,9,37,113,209,48,140,8,163,79,126,223,126,198,204,236,35,115,115,115,123,250,159,121,190,247,230,186,235,89,126,37,68,145,36,234,75,227,65,243,45,184,97,146,19,95,87,249,232,
2,163,42,10,170,249,44,182,149,139,40,231,178,208,76,19,179,107,117,220,94,111,160,101,24,112,136,2,209,47,2,50,115,180,159,66,20,43,16,162,178,189,236,149,166,109,99,169,222,132,97,217,208,12,3,59,251,
251,176,123,176,31,169,164,187,62,23,107,235,158,140,47,121,56,197,64,144,249,146,196,95,194,206,38,69,9,165,191,24,5,80,25,121,112,96,237,210,216,94,0,79,0,152,252,64,15,97,230,252,197,241,177,47,207,
174,172,61,228,12,237,26,4,194,185,216,104,152,162,72,204,12,99,43,197,66,74,108,8,193,3,70,77,8,12,148,10,24,174,148,81,204,102,208,208,116,220,90,171,225,246,122,19,29,211,128,67,81,98,70,82,149,230,
159,139,226,222,26,91,185,254,96,68,40,143,120,223,35,130,110,154,104,104,58,108,199,70,46,147,70,95,79,1,185,116,10,150,227,160,109,24,112,36,142,67,18,89,12,150,28,135,5,11,117,49,255,216,232,17,123,
218,30,51,160,36,18,86,167,205,230,218,234,98,58,157,58,105,154,150,249,3,61,164,86,171,37,215,214,214,134,178,59,118,247,16,17,132,34,56,236,51,35,54,155,64,81,89,193,211,29,136,162,109,212,240,102,221,
125,57,85,197,96,49,143,161,82,15,210,201,36,86,90,109,204,172,214,176,210,106,195,180,156,174,137,195,72,121,41,141,244,68,65,142,78,156,248,113,95,200,101,183,96,176,227,126,207,97,66,189,211,193,181,
219,38,58,134,137,123,183,12,96,75,165,4,53,145,64,90,77,98,122,121,5,109,77,243,174,237,62,171,127,63,36,37,123,34,142,76,198,32,50,253,210,37,162,50,192,34,63,180,163,216,124,255,202,78,5,137,94,0,173,
31,8,200,252,252,124,66,211,180,130,146,43,217,228,94,93,112,172,214,102,169,180,13,220,81,54,158,224,46,158,225,3,87,204,164,177,165,88,192,96,177,224,37,239,38,102,106,235,88,107,181,97,59,20,144,199,
32,254,70,60,47,202,23,224,247,51,220,182,75,36,28,250,40,6,129,132,98,124,193,179,147,102,152,184,185,184,4,205,178,176,111,104,11,6,74,69,236,223,190,13,106,66,193,212,194,10,214,59,237,104,219,88,138,
205,36,143,185,18,60,192,99,250,151,28,94,1,193,4,164,170,189,121,102,244,216,68,101,0,211,63,16,144,102,179,41,136,40,33,132,240,42,32,73,32,164,216,106,223,168,132,141,12,59,135,85,72,66,1,138,233,12,
182,20,11,168,230,178,176,29,194,98,163,133,249,245,58,214,53,205,235,220,185,245,60,199,6,29,32,135,47,175,77,75,210,3,67,10,89,36,77,150,68,27,99,20,9,185,228,239,3,96,218,14,230,150,87,96,91,54,180,
45,3,216,214,91,193,253,219,183,33,149,72,226,198,237,5,172,54,154,176,28,169,179,233,201,45,136,145,67,196,8,174,124,95,114,103,84,168,106,42,145,206,228,200,52,10,31,152,212,243,249,60,11,111,60,201,
93,25,74,112,19,81,110,196,177,169,255,144,40,33,38,194,37,133,64,37,151,197,246,114,17,213,92,22,45,195,196,204,218,58,110,175,55,208,49,205,152,4,209,93,94,82,44,153,198,135,224,200,39,161,36,27,92,
42,77,129,232,185,16,151,74,24,150,195,184,93,171,65,179,76,152,150,133,221,131,253,184,127,120,27,210,170,138,43,179,115,88,172,213,97,144,21,188,127,34,177,198,192,3,130,235,139,176,161,197,82,175,206,
47,62,160,36,20,145,74,167,217,208,35,121,92,217,8,144,237,219,183,59,233,116,186,99,219,118,210,143,123,28,153,166,37,111,53,115,212,29,41,38,83,123,127,166,85,5,131,133,60,118,247,85,48,84,234,129,162,
8,172,180,218,88,104,52,208,241,153,183,31,70,68,152,124,253,5,65,49,105,69,34,57,17,201,158,98,189,142,72,165,71,20,235,199,32,34,102,250,84,223,114,8,171,235,77,92,159,95,196,252,90,13,185,116,10,251,
135,183,225,129,221,59,49,220,87,65,54,149,138,200,53,145,123,243,175,233,15,102,196,139,26,10,117,60,118,136,97,91,78,220,246,27,2,82,42,149,236,114,185,188,210,158,159,101,33,20,248,253,13,57,15,176,
60,100,22,84,89,20,198,122,207,160,10,20,79,174,200,33,159,74,65,179,108,44,54,90,88,110,182,96,88,142,228,226,222,131,145,127,114,138,172,106,64,138,215,129,49,40,194,51,100,242,25,57,87,140,27,80,215,
96,157,11,156,223,191,183,201,65,173,213,194,205,133,101,204,44,175,194,114,108,244,23,123,48,212,91,69,41,155,133,2,17,54,173,16,93,64,136,11,158,210,164,126,8,24,131,201,113,28,203,210,33,68,231,3,67,
86,34,145,104,191,115,228,123,55,233,220,185,182,96,199,98,8,53,82,251,75,74,45,33,86,218,5,226,97,88,155,155,150,131,213,118,27,45,93,135,97,219,104,106,6,26,154,230,214,250,65,201,72,17,195,18,71,101,
17,226,216,108,174,196,53,186,74,109,105,22,139,164,196,30,25,204,246,65,39,68,94,135,243,47,163,91,38,230,86,215,160,155,38,42,133,28,132,80,208,212,58,208,45,43,80,175,17,161,0,209,105,124,185,234,100,
142,198,121,98,8,99,117,165,14,219,106,11,69,105,222,17,49,220,179,107,231,247,38,250,251,63,209,154,185,89,81,182,239,26,128,63,16,45,149,124,97,82,71,119,137,231,93,223,34,66,67,55,92,133,22,4,199,97,
56,68,174,244,29,33,115,136,132,26,116,113,14,132,83,34,242,244,33,228,151,117,32,9,153,50,123,71,212,72,65,233,42,205,70,202,173,98,239,243,182,161,163,99,24,152,91,93,245,181,61,88,182,227,105,119,178,
82,17,27,115,101,134,19,227,32,20,158,91,48,51,204,213,69,29,66,44,37,32,150,62,48,100,121,121,228,204,200,200,200,88,251,202,133,102,82,8,211,155,169,226,136,52,34,197,237,112,34,35,220,71,1,39,33,152,
142,3,203,38,88,14,121,132,143,35,30,17,127,45,141,72,74,202,36,123,128,136,41,198,46,8,222,48,91,72,210,16,19,58,41,166,59,5,32,80,87,211,73,38,180,14,57,48,44,59,208,186,108,199,113,75,219,13,73,96,
183,130,224,19,72,183,194,11,181,249,218,197,115,183,133,16,151,116,211,106,220,17,32,66,8,243,195,31,254,240,255,29,30,30,190,220,60,115,108,89,8,17,120,134,240,87,23,119,191,203,71,27,148,172,17,193,
81,94,151,17,181,52,54,213,129,48,182,71,52,41,95,49,38,142,117,10,209,245,170,130,44,163,68,216,52,201,98,33,34,83,38,126,246,218,200,107,101,77,44,8,113,254,130,0,135,161,76,132,161,149,72,170,242,60,
207,173,143,159,158,83,20,101,74,81,148,227,150,101,56,119,4,8,0,20,10,133,51,79,62,245,244,235,105,163,51,207,139,115,171,76,236,81,132,112,108,48,242,22,147,84,235,243,6,82,53,69,62,139,190,233,20,137,
237,145,23,110,194,85,79,114,126,144,18,116,88,206,202,101,112,124,84,52,30,227,195,202,16,146,113,221,118,99,212,224,32,17,137,0,93,10,51,228,65,109,57,87,133,207,232,78,61,66,216,237,122,171,121,109,
98,49,145,76,28,87,44,251,220,29,85,89,242,118,223,222,189,127,243,252,39,63,249,150,117,237,194,156,178,56,59,47,189,110,22,224,18,150,168,136,141,122,198,110,62,86,137,116,233,63,36,117,19,37,79,241,
201,34,226,189,150,216,136,80,68,214,247,74,94,17,153,148,143,49,236,72,79,28,93,160,201,125,28,138,135,88,57,108,145,92,166,203,218,153,127,29,48,32,132,221,106,52,22,94,251,255,183,147,106,242,104,66,
73,254,125,93,215,186,94,103,72,126,16,32,201,100,66,99,230,223,17,128,254,202,43,223,254,60,108,59,137,173,195,3,222,74,101,128,4,119,149,148,177,209,255,32,244,116,191,198,44,149,3,93,131,115,209,16,
214,173,158,2,232,18,47,41,214,118,13,5,81,68,219,176,93,93,193,88,120,149,188,132,100,5,183,107,224,14,145,215,38,228,23,143,220,146,10,96,38,65,237,86,115,241,141,87,22,213,84,234,109,53,153,248,211,
229,229,149,197,13,237,125,71,3,192,66,104,14,91,191,159,72,36,26,111,188,241,198,103,151,231,110,217,133,135,159,236,53,109,39,29,164,119,114,223,245,16,97,179,63,104,225,70,95,3,64,172,178,66,160,71,
65,48,200,145,43,55,116,37,204,0,52,146,20,102,127,33,16,54,12,41,242,112,5,49,98,109,128,238,87,30,162,165,113,88,126,35,152,182,247,158,65,184,191,186,67,150,80,60,62,22,254,230,8,193,104,79,92,152,
107,92,189,184,150,78,165,94,87,213,228,31,45,44,44,206,220,181,97,235,197,165,133,23,94,125,245,181,95,186,124,233,242,99,249,131,143,151,169,92,237,13,101,106,176,155,216,200,85,134,35,211,228,161,92,
45,179,214,96,31,201,70,145,246,49,69,120,2,201,90,150,127,60,73,70,39,249,24,108,48,197,78,82,82,151,142,3,5,198,37,34,105,248,219,207,95,228,77,161,120,215,144,239,205,231,83,254,43,11,204,130,193,128,
109,153,75,111,188,178,192,134,62,153,74,167,191,13,224,207,22,22,22,180,187,62,253,222,106,54,119,158,61,127,254,215,143,189,247,222,19,203,203,203,187,115,251,31,72,99,112,120,171,229,216,81,99,67,122,
248,192,224,20,14,38,108,96,32,176,252,176,82,34,103,238,2,133,130,107,200,149,87,212,248,242,28,88,8,60,5,33,137,152,54,184,54,7,192,162,235,62,40,172,208,188,105,124,249,59,12,134,181,182,188,220,186,
116,222,52,86,151,87,85,85,61,174,166,211,223,156,153,158,126,253,135,254,58,66,109,109,109,244,196,201,147,135,38,38,38,30,154,159,159,191,23,197,74,73,29,26,78,40,197,114,198,76,168,165,160,218,32,191,
194,226,96,21,6,32,120,141,31,247,161,156,160,13,202,210,123,27,145,113,79,201,80,190,81,124,163,83,228,115,246,248,78,184,218,101,73,39,48,100,176,72,194,66,131,2,128,73,74,204,228,13,215,185,231,133,
4,60,28,178,245,197,217,37,187,177,158,104,78,92,104,9,69,44,168,73,117,76,77,165,222,102,230,87,167,110,222,188,227,95,158,118,87,222,15,89,92,90,218,122,237,234,213,199,231,230,230,30,155,159,159,191,
111,109,109,109,80,55,140,156,227,56,105,203,178,210,14,81,34,8,51,36,25,131,55,222,23,122,128,244,55,71,5,205,248,249,100,240,136,100,112,98,199,69,86,116,252,90,177,251,144,67,155,4,10,249,177,25,108,
65,8,147,108,187,3,33,214,147,137,196,100,34,145,24,79,38,147,223,101,193,215,174,78,92,117,126,228,111,80,77,79,77,165,109,162,161,43,19,19,197,197,133,133,138,97,154,89,199,113,20,219,118,4,192,108,
219,182,112,87,160,3,199,230,64,78,97,38,56,142,3,98,114,87,168,227,174,84,255,103,199,113,191,19,24,219,113,89,52,17,121,255,123,70,116,220,99,28,118,64,142,183,95,58,15,145,247,185,227,3,229,128,61,
41,39,184,158,67,112,124,64,137,192,142,227,126,238,238,99,135,72,48,19,51,177,1,33,154,41,85,173,37,20,101,245,204,217,179,171,216,220,54,183,205,237,135,184,253,27,169,57,90,121,254,52,215,3,0,0,0,0,
73,69,78,68,174,66,96,130,0,0};

const char* LivePanelComponent::gmfadeOn_2x_png = (const char*) resource_LivePanelComponent_gmfadeOn_2x_png;
const int LivePanelComponent::gmfadeOn_2x_pngSize = 6576;

// JUCER_RESOURCE: gmfadeOff_2x_png, 6357, "../Images/GMFadeOff@2x.png"
static const unsigned char resource_LivePanelComponent_gmfadeOff_2x_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,100,0,0,0,60,8,6,0,0,0,144,63,31,206,0,0,0,1,115,82,71,66,0,174,206,28,
233,0,0,0,6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,219,10,30,16,12,13,128,121,238,128,0,0,24,85,73,68,65,84,120,218,
237,92,233,151,28,87,117,255,189,170,174,233,109,122,166,151,89,164,145,52,90,140,109,89,198,146,141,151,128,129,96,64,6,59,38,38,56,241,9,228,152,147,67,18,146,79,249,3,242,33,159,66,14,95,66,78,8,33,
96,130,141,13,177,141,45,7,219,178,100,100,91,49,193,178,22,91,219,104,36,205,104,180,204,162,89,187,123,102,122,223,235,189,155,15,181,189,87,61,66,2,188,136,131,222,57,210,244,84,85,87,189,186,203,239,
254,238,125,247,13,112,109,92,27,215,198,165,7,123,183,111,56,53,57,25,52,133,24,56,51,58,218,149,94,88,72,52,154,205,48,231,92,51,77,206,0,34,211,52,153,16,2,68,28,220,36,16,4,56,39,16,9,112,206,33,72,
64,8,1,226,4,33,132,251,59,231,214,119,132,32,8,178,206,115,193,173,107,132,128,16,214,61,4,183,174,225,196,33,184,125,92,186,143,16,246,121,46,64,68,16,130,131,132,0,119,238,67,2,130,11,112,18,32,65,
246,92,184,117,222,58,70,92,8,70,36,136,4,53,192,88,169,195,48,114,186,166,45,29,61,118,108,233,170,80,72,58,147,89,125,118,108,236,163,179,179,179,119,205,205,205,221,176,188,188,220,223,104,52,194,156,
243,80,179,213,10,10,206,117,33,4,179,4,96,11,142,44,65,17,145,251,217,61,6,128,86,186,206,62,102,125,182,175,227,246,53,228,40,69,254,44,124,207,35,112,110,146,163,12,245,188,176,159,105,223,91,190,159,
32,16,72,153,11,17,113,34,106,1,104,16,81,29,140,229,3,186,62,174,235,250,112,32,16,248,37,49,58,59,54,58,198,223,87,133,228,150,151,111,121,251,157,119,30,30,29,29,189,109,110,110,238,186,222,193,245,
137,193,219,238,140,70,19,201,176,17,12,6,32,200,18,26,217,47,6,2,220,151,3,224,28,39,2,136,32,64,246,49,40,199,200,210,144,123,92,189,23,32,136,188,243,112,4,8,212,154,77,228,203,85,148,27,13,52,154,
45,152,66,0,36,32,4,64,176,61,192,86,140,35,116,79,241,146,33,56,247,180,141,193,85,156,61,23,206,77,202,78,142,47,151,230,102,196,252,145,131,69,166,177,5,35,96,156,8,4,2,111,128,177,61,147,19,19,149,
247,84,33,229,82,105,253,208,137,19,127,179,127,255,254,143,103,50,153,141,119,252,241,151,186,123,214,111,74,16,9,64,192,125,49,191,224,28,171,244,60,192,58,14,223,181,194,61,38,124,202,89,73,49,0,145,
0,136,208,104,153,88,42,87,81,174,215,209,104,154,16,80,189,198,186,204,241,40,128,136,91,74,129,207,51,101,207,37,217,43,45,197,11,231,249,130,32,32,100,175,1,9,66,46,147,46,157,127,229,133,124,163,152,
207,25,134,113,200,232,48,158,159,190,56,253,250,123,162,144,116,102,225,254,61,123,94,253,234,200,233,145,187,62,246,231,95,93,29,75,166,34,142,48,45,216,177,47,92,65,112,242,203,200,22,237,41,97,5,47,
32,178,4,41,41,25,146,23,44,87,170,200,87,107,168,55,91,224,66,172,32,76,231,90,33,65,30,164,235,172,223,5,9,107,30,180,210,53,146,66,253,158,101,95,39,64,32,238,93,15,16,90,173,22,189,243,232,191,93,
100,66,76,116,4,131,187,0,252,231,194,194,66,237,93,81,8,167,150,49,122,234,204,223,191,190,119,239,23,204,64,199,141,183,125,225,75,171,25,99,204,122,184,103,165,151,182,104,219,34,109,79,129,128,4,81,
54,44,217,56,45,67,153,227,1,68,0,132,128,0,144,45,149,80,172,54,208,48,77,247,156,103,189,30,220,120,80,163,90,57,201,199,87,82,160,19,111,136,3,132,182,120,163,40,65,144,4,153,206,239,194,53,24,34,194,
249,125,111,204,165,135,14,47,25,129,192,107,134,17,248,246,194,66,122,250,82,114,214,175,68,25,68,20,62,121,226,228,63,236,124,121,215,195,155,238,254,228,150,235,254,224,238,94,48,198,0,146,175,2,17,
179,61,193,59,67,228,126,242,78,56,158,1,219,11,0,128,121,150,5,247,156,5,93,16,64,166,84,194,66,161,140,76,169,140,170,237,13,238,253,29,15,133,4,141,242,36,236,207,214,181,206,92,156,227,146,17,57,207,
37,225,205,204,57,239,92,235,204,201,253,225,88,155,251,67,146,133,165,240,196,186,245,177,158,45,91,147,51,71,15,245,11,33,214,197,98,157,103,171,213,234,210,111,164,16,211,228,225,211,167,79,253,227,
174,93,47,63,184,249,158,123,7,123,54,108,76,216,111,237,137,89,121,81,242,20,226,187,70,18,179,79,149,109,50,178,225,168,134,133,98,25,233,82,25,181,22,183,44,86,86,37,9,231,245,219,132,5,248,44,222,
17,46,147,32,81,216,115,103,194,53,3,33,205,221,182,5,23,166,156,121,10,121,226,202,123,73,255,75,50,33,2,116,195,208,123,182,108,139,205,30,61,148,36,66,50,18,137,30,171,215,107,149,95,91,33,143,60,242,
200,223,237,218,181,235,161,45,247,62,112,99,98,205,186,110,225,4,9,166,26,160,39,106,201,43,136,20,101,248,95,194,157,180,20,51,170,173,22,210,197,50,210,197,50,42,141,166,21,23,64,82,108,113,190,231,
89,41,201,86,12,233,58,87,113,80,148,2,201,178,109,2,39,29,146,149,11,213,211,164,103,64,86,52,60,193,67,130,95,75,149,222,181,186,97,232,61,55,111,237,154,59,250,78,16,140,88,136,233,111,55,76,147,174,
88,33,229,114,249,246,221,187,119,255,181,22,141,109,94,183,245,182,36,72,40,102,237,10,7,146,0,86,152,60,147,38,76,204,243,6,9,176,176,84,173,97,161,80,66,190,86,131,105,10,200,232,101,89,49,217,12,78,
86,12,60,168,178,5,45,72,17,209,10,194,244,4,41,252,199,104,37,154,46,121,160,227,50,210,204,93,170,44,193,158,103,4,22,107,243,236,128,16,48,58,244,122,173,66,149,244,2,33,160,95,104,54,155,243,178,204,
181,95,17,55,58,142,28,57,242,229,233,233,233,45,91,182,223,191,74,141,13,164,194,17,36,136,34,95,116,240,91,18,169,216,188,80,44,227,220,98,14,203,213,26,76,1,192,142,67,68,4,98,164,88,36,218,96,208,
243,0,63,166,11,159,151,56,147,23,146,130,24,100,236,167,54,152,5,236,57,200,239,205,212,88,37,193,130,133,26,210,253,188,99,164,24,197,166,79,126,118,64,8,177,65,8,241,81,195,8,234,87,164,144,153,153,
153,219,71,70,70,182,221,178,253,254,30,48,198,224,131,29,209,230,42,80,163,130,34,12,40,112,209,226,28,115,197,18,46,44,229,80,110,52,37,200,17,18,181,149,56,0,217,65,210,79,135,237,159,172,13,195,37,
24,117,238,205,36,66,225,207,99,36,178,209,78,42,32,221,31,158,103,146,159,138,75,196,128,72,69,198,54,228,0,86,223,245,241,53,68,116,115,168,195,232,186,34,133,76,77,77,125,60,155,205,14,38,7,55,116,
181,121,143,15,171,229,216,225,90,191,171,40,235,117,52,0,156,4,230,139,21,76,231,75,168,54,91,146,69,251,149,8,37,131,119,61,142,201,193,139,160,132,19,89,137,146,199,184,223,22,178,186,132,79,254,76,
130,31,102,87,17,172,57,48,48,4,52,13,134,30,64,64,211,161,105,204,157,151,60,95,153,105,193,7,103,36,5,119,135,94,119,175,191,174,11,68,125,28,212,119,89,133,112,206,163,203,203,203,155,122,214,14,198,
44,122,11,197,141,125,33,92,133,34,85,54,96,68,8,104,12,141,150,85,212,75,69,195,72,132,131,48,116,93,250,142,76,45,85,146,64,146,137,185,30,100,71,38,153,82,43,215,218,160,194,156,160,229,83,180,144,
4,4,120,101,16,40,212,151,16,50,12,244,118,199,176,113,85,31,54,175,93,141,13,253,189,136,71,162,8,104,154,202,166,64,16,12,109,243,245,238,231,205,208,145,102,36,158,140,16,88,152,136,98,178,236,3,43,
41,164,80,40,4,242,249,124,207,234,155,182,4,61,107,103,18,187,144,216,148,31,226,45,81,0,16,96,0,230,75,21,104,12,232,141,68,144,138,134,208,161,107,40,212,26,152,41,148,176,196,171,104,10,238,222,199,
225,37,214,187,48,207,211,36,248,112,30,38,36,202,235,8,193,205,232,225,131,35,31,180,120,193,132,36,95,33,41,49,5,2,186,134,68,103,4,31,90,221,143,85,241,56,72,8,204,46,229,80,170,214,0,198,212,180,74,
72,116,159,224,99,152,146,193,73,222,204,24,99,76,99,29,36,68,228,178,30,50,51,51,163,55,26,141,136,198,116,238,241,36,242,4,229,207,33,100,143,177,39,144,171,53,48,177,92,64,181,101,162,102,114,228,235,
117,148,27,77,104,140,33,17,9,161,39,26,70,164,35,0,141,84,70,228,33,136,176,89,14,107,131,54,57,46,41,47,10,63,21,149,13,136,181,145,16,18,62,196,180,201,28,193,242,142,85,241,56,214,166,146,136,116,
24,200,87,170,152,93,202,33,95,173,128,115,174,168,82,65,15,133,32,168,241,12,204,51,17,198,0,232,70,27,203,93,209,67,42,149,10,35,34,230,86,86,236,151,100,246,52,212,4,76,101,17,13,147,35,93,169,192,
52,173,50,7,17,208,226,2,185,106,29,77,147,163,201,57,122,34,97,196,195,65,52,205,40,132,32,20,107,117,53,136,10,130,32,230,74,140,24,64,220,73,218,73,202,27,228,136,41,32,149,209,224,184,12,73,185,136,
68,129,212,184,39,197,66,98,132,168,17,196,154,100,2,171,226,221,224,92,96,98,105,25,231,102,23,48,159,203,163,222,104,57,34,245,202,37,150,253,120,132,67,34,62,110,28,180,41,176,3,115,156,4,200,108,54,
25,99,252,178,10,137,197,98,164,105,26,39,226,138,23,8,159,213,145,196,40,0,32,91,169,161,228,176,38,9,78,72,16,90,36,80,172,55,208,226,28,205,150,137,158,104,4,189,209,8,52,198,160,51,134,165,74,213,
85,128,96,114,78,0,5,186,64,176,73,159,202,134,100,22,230,197,36,149,229,145,243,14,82,185,69,161,78,12,72,70,162,88,155,74,98,77,50,14,77,99,152,72,103,49,158,206,32,91,40,161,105,154,18,139,146,169,
47,181,37,198,66,194,47,199,136,137,193,73,253,33,172,100,171,65,140,149,47,171,144,129,129,1,30,14,135,203,96,76,39,155,41,49,70,74,16,118,221,147,1,77,147,35,93,174,194,228,220,230,237,228,37,68,146,
66,57,1,229,102,19,38,231,104,154,28,125,177,8,122,162,97,232,204,130,196,197,114,213,206,69,252,73,159,10,11,138,213,73,128,201,28,38,38,231,62,194,33,173,66,73,98,201,87,114,209,52,29,169,206,8,54,244,
245,96,32,17,71,139,155,152,202,46,98,50,189,136,92,185,130,150,105,130,185,149,92,127,180,84,153,161,146,5,168,148,207,245,162,202,210,82,149,49,148,116,77,203,95,86,33,137,68,194,76,38,147,115,103,143,
29,206,220,252,192,218,20,115,97,64,206,208,237,12,187,82,71,169,209,178,214,5,100,254,207,148,40,166,4,213,74,179,5,147,11,52,185,137,254,88,20,241,112,200,245,148,108,169,140,134,201,149,32,238,167,
217,2,80,147,78,169,60,47,123,172,131,37,10,105,16,94,144,181,147,127,116,4,116,244,196,58,177,177,175,23,125,221,49,84,27,77,76,164,51,152,204,46,162,92,173,195,228,194,51,4,153,204,200,101,146,182,128,
66,190,210,145,202,75,23,79,15,101,24,180,41,2,45,93,54,168,51,198,42,125,253,253,135,169,213,204,146,16,36,87,82,101,242,59,87,170,160,212,106,217,238,41,7,89,166,36,79,74,232,119,86,243,204,22,22,138,
21,92,92,46,34,87,169,33,214,209,129,193,68,23,6,186,99,136,24,1,155,178,146,170,12,39,17,180,255,41,132,130,168,141,254,146,189,4,208,14,95,222,111,145,96,7,6,83,73,108,94,179,26,171,226,93,40,86,107,
24,155,157,195,249,185,52,138,21,203,235,225,48,63,48,247,94,66,130,109,39,169,85,8,135,20,67,152,243,61,187,100,47,56,167,194,133,177,139,76,99,35,229,114,165,124,69,137,225,218,53,107,142,173,89,179,
230,252,242,228,133,101,217,5,9,64,147,115,76,23,203,104,113,97,11,104,133,50,56,185,177,214,77,180,108,80,241,50,118,33,176,88,169,226,98,46,143,197,74,5,65,195,192,154,120,55,6,226,93,232,12,117,216,
21,126,169,142,36,197,50,161,120,131,67,62,152,228,13,194,71,3,213,234,43,3,67,44,24,194,250,158,20,174,31,232,71,60,26,65,182,88,194,232,204,28,38,179,75,168,181,90,246,148,153,82,44,148,33,84,113,6,
43,203,144,202,54,94,21,65,200,152,75,192,220,209,131,115,154,166,157,211,117,253,160,95,238,151,84,72,42,149,154,184,233,166,155,246,207,159,60,126,74,112,83,56,124,187,220,108,98,190,92,7,119,11,106,
158,93,56,56,174,150,32,124,37,16,25,91,137,192,133,192,114,181,142,233,92,17,11,197,18,24,3,6,186,99,88,151,140,35,30,14,65,103,186,45,90,230,6,75,230,146,6,230,43,24,146,154,190,58,139,94,82,169,133,
136,160,105,26,226,209,48,54,174,234,193,117,171,250,16,238,232,192,220,114,14,163,179,243,152,91,202,163,209,106,249,248,52,169,229,15,31,107,35,101,161,141,201,146,112,123,7,64,2,96,0,231,45,90,58,121,
252,172,174,105,7,4,241,169,43,162,189,0,16,8,4,76,33,196,238,108,54,123,211,193,231,126,18,191,227,203,127,185,45,223,104,162,80,111,72,86,41,148,82,53,236,230,5,63,204,216,109,13,74,121,90,48,72,214,
76,40,212,234,104,154,38,26,45,19,171,187,98,88,213,213,137,128,198,160,107,5,44,150,43,104,182,184,47,241,130,27,168,101,85,16,212,114,188,43,44,123,186,154,166,33,21,141,96,93,79,18,3,137,56,136,4,38,
179,139,152,88,200,98,169,92,129,201,77,175,106,108,127,137,228,170,179,92,248,164,246,242,191,90,120,148,227,39,3,145,192,169,39,191,63,164,235,250,97,61,16,120,173,176,180,196,175,88,33,0,160,105,90,
186,80,40,60,81,171,213,163,167,94,121,177,163,243,238,237,55,57,54,231,34,15,131,135,73,114,48,83,252,154,124,107,38,94,227,131,247,171,64,185,97,49,176,150,201,49,208,29,67,79,103,4,1,77,131,198,24,
22,139,101,84,155,43,100,231,254,5,50,95,69,90,206,77,116,93,67,170,51,138,77,125,61,232,235,138,161,97,154,152,204,44,98,42,179,136,66,165,6,238,46,49,251,106,115,206,49,102,55,58,168,57,128,132,14,190,
37,9,103,110,246,137,177,231,255,251,148,17,48,14,234,1,253,201,197,236,226,220,138,142,112,185,5,170,238,238,238,211,233,116,250,153,106,181,210,121,110,255,255,118,36,238,254,204,117,32,230,149,46,164,
58,155,26,220,153,91,123,194,165,202,241,66,130,59,219,210,42,141,22,90,188,132,70,171,133,129,120,23,186,195,33,232,169,4,2,154,134,133,92,1,149,102,83,242,52,95,237,75,248,87,235,188,103,4,3,58,250,
186,99,216,208,155,66,178,179,19,229,122,29,227,11,25,204,44,45,163,88,171,219,107,236,170,48,193,212,238,25,242,45,166,41,20,215,137,29,202,98,154,157,212,10,96,228,153,199,71,208,106,189,109,24,198,
142,76,38,51,114,73,100,186,146,53,245,254,254,254,125,233,76,38,192,246,237,227,167,94,217,81,239,189,239,161,155,29,171,246,234,56,118,112,87,202,208,190,242,6,148,250,29,24,147,155,11,60,203,110,180,
90,72,23,77,52,77,19,3,241,46,164,162,17,172,79,197,161,49,96,110,57,143,82,189,97,199,112,230,181,239,16,181,175,149,216,2,10,27,29,24,72,116,97,176,39,133,174,112,8,75,165,10,38,22,50,152,205,231,80,
111,180,124,37,119,207,43,132,186,18,43,197,39,38,189,4,41,203,187,106,213,23,16,173,22,31,249,201,15,70,3,70,224,128,17,10,62,54,55,55,247,206,175,146,245,21,41,4,0,250,251,250,126,145,207,231,22,147,
137,228,215,246,191,250,66,61,254,233,7,182,178,64,192,144,163,4,73,140,194,179,40,180,45,50,201,94,161,88,184,219,26,100,49,185,197,114,21,77,206,209,52,77,244,197,98,24,76,198,97,104,26,102,150,243,
200,85,107,0,231,110,108,88,169,169,130,192,208,21,14,98,77,34,142,193,158,4,130,134,129,116,190,136,11,11,25,164,243,5,52,185,105,161,173,128,186,202,231,36,182,10,116,121,107,50,74,83,131,80,95,196,
93,184,101,132,218,210,98,121,124,231,115,167,59,147,169,183,169,94,251,143,153,217,217,115,151,147,243,21,43,4,0,226,241,196,201,122,163,241,205,96,56,180,184,255,173,189,37,118,195,45,219,58,250,86,
39,156,154,132,82,77,181,33,203,153,44,91,137,183,43,11,70,240,21,15,9,166,32,228,42,53,52,91,38,154,45,19,171,227,93,88,147,232,70,64,215,160,45,46,99,169,92,129,224,66,93,176,130,229,53,204,46,98,14,
166,18,24,72,116,67,211,52,204,46,231,48,153,206,34,93,40,193,228,118,176,134,176,146,88,161,178,40,185,78,199,164,165,1,183,18,225,47,171,202,107,33,76,195,194,59,111,205,230,70,79,142,68,194,145,61,
58,55,31,155,156,157,45,172,91,187,86,155,158,153,17,239,154,66,0,32,20,12,102,27,213,198,191,118,70,163,243,111,189,245,214,131,233,11,99,31,73,126,244,15,7,221,234,188,240,101,206,74,169,66,180,173,
113,147,91,20,164,182,69,59,135,230,22,170,182,82,184,137,129,120,28,171,186,99,232,208,116,24,186,142,108,177,132,90,211,84,24,86,135,161,33,30,137,96,125,42,137,190,238,24,90,156,91,101,144,204,18,114,
229,42,56,23,174,91,145,84,182,151,201,134,188,78,175,150,90,208,182,6,15,169,48,73,2,56,183,227,199,103,169,89,31,138,70,35,59,107,13,246,244,244,228,56,173,95,191,94,155,154,154,18,239,105,111,239,248,
248,248,246,183,246,237,251,234,232,216,216,29,125,247,255,217,22,185,55,22,114,27,167,219,140,102,119,3,42,13,102,78,247,160,220,232,236,111,90,179,26,224,66,129,0,250,186,58,177,54,209,141,88,40,136,
66,173,142,233,236,50,230,243,69,84,26,13,16,9,116,4,2,232,137,69,49,152,74,32,21,139,162,218,104,98,50,179,136,233,165,28,138,213,154,242,12,39,16,203,77,220,94,83,156,212,250,234,54,227,201,243,244,
216,164,51,127,97,154,226,204,83,255,53,26,12,6,15,132,195,161,199,207,156,25,59,244,235,202,52,240,219,40,100,211,166,77,123,47,78,79,167,147,169,228,215,222,126,237,133,90,252,211,127,180,149,244,128,
225,239,66,81,214,205,152,106,145,68,190,204,94,109,180,80,8,83,173,217,196,108,174,128,70,171,133,117,201,56,146,157,17,108,236,75,65,215,25,230,114,69,152,220,68,95,87,12,131,169,4,186,34,33,20,42,53,
76,100,22,49,187,148,71,165,209,104,99,102,114,167,72,219,66,159,191,28,67,190,202,48,212,170,68,101,126,38,55,189,247,149,241,206,206,206,95,134,194,193,239,158,58,121,122,252,55,145,233,111,165,16,0,
24,92,183,238,100,54,155,253,102,40,20,94,60,184,127,111,73,172,219,244,225,240,250,235,123,228,82,56,218,186,58,252,199,188,154,105,91,227,128,175,220,221,52,77,44,228,75,22,132,153,113,244,198,58,177,
177,55,133,206,96,16,92,8,36,59,35,8,25,6,22,139,101,140,103,22,177,96,43,16,109,168,47,153,9,169,245,48,149,166,171,255,252,13,11,0,144,61,122,104,182,120,238,244,72,60,149,124,45,192,216,15,135,135,
135,243,31,248,134,157,76,58,19,58,127,225,252,95,28,56,120,224,139,75,38,110,141,223,249,137,65,183,207,85,110,122,150,155,151,37,88,114,97,3,22,164,192,7,17,14,100,192,62,175,57,12,42,25,199,64,119,
23,194,29,6,24,3,106,205,22,230,115,5,76,100,150,176,88,44,162,197,185,11,83,254,190,225,149,224,209,58,6,101,235,129,219,29,223,214,196,45,48,254,179,167,206,50,211,28,138,68,34,47,27,188,245,52,239,
48,24,9,136,225,225,97,186,42,118,80,13,15,159,216,126,232,224,219,143,156,57,127,246,174,222,123,255,228,6,98,76,119,99,133,244,178,150,108,133,26,63,220,120,35,9,68,185,214,219,167,225,44,10,118,6,13,
172,73,116,99,32,17,71,64,99,152,93,206,99,42,187,140,92,185,140,150,211,13,15,40,91,6,132,210,24,109,223,91,126,174,188,201,71,154,139,112,183,52,16,4,55,249,249,159,62,126,58,28,14,191,221,25,237,252,
209,225,35,135,15,222,122,235,54,141,65,163,227,67,199,233,3,247,16,121,156,30,29,185,229,228,137,19,127,117,228,200,209,79,37,62,243,133,15,147,174,27,138,39,64,21,188,183,135,195,215,165,78,158,48,101,
101,200,30,7,8,132,140,14,36,162,97,48,123,123,66,177,82,3,183,155,39,84,15,36,105,219,129,69,121,157,237,113,78,1,210,31,224,125,187,166,64,36,208,200,231,42,23,95,249,217,72,87,87,215,47,162,209,232,
163,251,247,239,31,127,183,100,247,158,40,196,102,96,189,195,195,195,95,63,124,248,240,189,250,230,109,219,244,222,85,9,72,214,222,182,199,130,200,218,67,232,38,102,194,183,175,3,18,251,17,118,3,180,103,
209,86,169,94,192,228,246,62,65,34,101,191,71,251,190,15,248,182,40,8,149,57,9,111,237,27,146,114,230,246,238,158,104,44,101,166,226,241,238,61,161,96,199,247,222,220,183,191,120,85,111,250,148,199,133,
243,227,161,11,227,231,191,114,248,240,225,7,23,91,226,35,241,187,62,57,40,195,146,74,119,165,77,60,242,62,15,101,239,159,237,93,220,222,185,68,50,173,134,79,161,222,119,5,164,123,113,120,223,181,21,97,
57,141,144,54,229,144,186,223,196,126,238,228,11,79,141,117,104,218,112,52,26,221,201,170,129,167,15,12,189,41,222,109,153,105,239,165,66,174,251,208,166,250,231,62,247,185,31,125,234,158,123,190,59,216,
221,249,127,153,221,59,70,228,196,75,94,184,96,240,247,216,66,106,110,134,215,220,38,236,229,97,223,154,181,187,194,77,190,78,18,230,163,208,140,218,218,150,188,50,15,83,10,110,30,211,21,124,242,185,39,
134,163,193,224,155,201,68,226,219,7,15,28,120,202,72,176,247,68,118,239,169,135,200,227,208,161,67,183,140,140,142,124,237,248,177,161,79,117,127,98,251,102,132,34,17,106,195,108,207,51,96,51,52,161,
4,120,82,119,41,173,192,220,224,143,83,66,218,180,9,105,183,47,249,118,216,250,61,194,126,118,171,152,43,207,189,250,226,233,120,60,241,102,172,59,246,189,61,175,236,153,216,190,125,123,96,239,222,189,
230,239,180,66,0,96,104,104,168,119,228,244,233,191,61,122,236,216,189,250,230,109,91,3,61,171,18,234,30,62,111,33,171,77,112,242,214,105,55,14,8,143,37,249,2,184,115,76,222,168,233,84,5,172,56,198,125,
213,3,184,251,217,157,251,228,78,28,153,175,142,143,157,78,36,18,63,143,70,34,143,237,218,189,187,240,94,203,232,125,85,8,0,28,61,118,44,52,53,57,249,149,227,199,143,63,152,215,58,110,143,110,187,115,
157,159,9,145,47,126,136,75,176,30,43,232,122,202,33,169,33,77,254,14,108,38,231,223,85,11,123,147,170,88,97,223,224,212,142,39,206,134,195,225,83,201,100,242,165,87,95,125,245,199,239,151,124,222,119,
133,56,99,207,158,61,219,143,29,63,254,200,248,196,196,93,169,123,191,120,3,49,232,214,95,93,112,182,26,67,181,114,172,148,180,137,21,55,107,122,205,211,162,173,86,37,231,67,66,170,81,185,241,137,11,126,
241,133,159,156,142,247,173,58,209,29,9,62,186,243,165,157,251,223,79,185,104,31,148,66,238,187,239,190,189,119,222,113,199,183,110,221,186,117,79,238,245,151,78,192,20,38,145,26,232,133,218,39,177,66,
147,28,83,90,162,228,245,12,200,187,154,228,142,21,167,157,7,74,223,169,229,109,229,66,121,246,229,167,143,244,247,247,239,137,71,195,255,180,243,165,157,251,31,250,211,135,140,247,83,46,31,152,135,56,
99,223,155,111,246,142,157,29,251,250,241,227,67,159,199,218,141,55,26,27,110,232,103,180,66,201,197,253,211,22,82,5,214,201,154,229,132,146,124,91,161,149,191,208,224,229,39,114,214,46,136,80,58,117,
124,182,54,113,118,164,183,183,119,79,103,103,231,99,207,60,243,76,225,225,135,31,214,119,236,216,193,127,175,20,2,0,191,252,197,190,208,212,244,196,87,134,135,135,31,44,6,66,183,135,183,222,177,14,82,
114,38,164,36,208,159,213,11,41,151,88,105,15,57,145,90,18,17,254,220,6,2,11,63,127,241,108,72,199,80,79,178,103,103,142,5,159,126,227,127,158,166,15,74,22,87,133,66,156,177,227,249,231,183,15,159,56,
241,200,212,197,139,183,39,62,255,197,155,5,7,107,91,91,185,68,81,82,165,203,164,48,48,57,243,22,36,92,230,5,18,124,246,165,159,158,76,36,18,135,251,251,250,31,127,242,199,79,30,250,160,101,112,85,41,
4,0,158,125,238,217,91,46,94,188,248,229,115,103,207,125,140,173,221,120,99,96,253,245,3,110,5,88,202,41,132,196,158,200,233,56,17,220,251,12,143,89,57,11,81,112,105,45,80,159,60,183,80,25,61,113,50,149,
74,29,236,73,38,159,252,193,15,127,56,126,53,188,255,85,167,16,0,216,181,107,119,124,118,118,250,158,217,185,249,207,78,77,78,222,110,108,188,113,83,96,240,186,126,21,166,218,147,61,200,197,74,249,79,
53,73,185,74,115,118,114,177,48,244,206,153,120,60,62,212,213,213,245,122,52,18,121,227,251,143,62,90,190,90,222,253,170,84,136,51,94,124,241,197,228,244,244,244,3,51,51,51,31,203,100,50,215,155,177,248,
134,200,166,205,125,20,237,140,113,65,204,201,73,156,6,7,97,215,184,224,120,136,5,99,36,22,211,185,226,185,145,69,42,44,95,140,68,58,199,186,227,221,7,186,99,177,215,255,253,59,223,201,94,109,239,124,
85,43,196,25,207,61,251,108,98,33,189,112,211,98,118,233,35,133,98,225,198,98,177,184,182,214,104,164,132,17,236,52,146,61,49,173,43,30,1,211,52,2,99,188,81,51,205,90,181,85,25,63,155,5,55,171,134,30,
200,117,132,130,115,225,80,232,84,52,26,61,30,137,70,206,124,235,95,190,149,191,90,223,245,119,66,33,242,120,226,137,39,194,245,122,189,119,126,126,190,183,90,173,246,212,107,245,174,166,217,10,113,211,
12,88,9,30,4,128,138,97,24,101,35,96,164,99,221,177,140,174,105,249,111,124,227,159,43,184,54,174,141,107,227,218,184,54,174,141,107,227,218,184,54,126,79,199,255,3,135,241,142,111,121,255,127,18,0,0,
0,0,73,69,78,68,174,66,96,130,0,0};

const char* LivePanelComponent::gmfadeOff_2x_png = (const char*) resource_LivePanelComponent_gmfadeOff_2x_png;
const int LivePanelComponent::gmfadeOff_2x_pngSize = 6357;

// JUCER_RESOURCE: gmfullOff_2x_png, 6122, "../Images/GMFullOff@2x.png"
static const unsigned char resource_LivePanelComponent_gmfullOff_2x_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,100,0,0,0,60,8,6,0,0,0,144,63,31,206,0,0,0,1,115,82,71,66,0,174,206,28,
233,0,0,0,6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,219,10,30,16,7,11,138,238,146,126,0,0,23,106,73,68,65,84,120,218,
237,92,217,151,92,197,121,255,213,189,183,247,233,153,233,158,141,77,18,136,176,9,35,129,89,98,99,59,198,182,176,33,118,112,76,194,137,157,131,79,142,147,56,121,202,31,144,135,60,197,57,126,137,115,226,
56,142,141,99,28,176,3,24,68,12,8,9,11,80,112,140,208,2,218,70,35,205,72,163,101,164,217,167,123,186,167,247,229,46,85,95,30,238,86,247,118,15,146,109,4,242,177,74,71,51,221,117,235,222,91,245,237,223,
175,190,26,224,114,187,220,46,183,213,27,123,175,31,56,125,238,92,204,18,226,170,19,199,143,247,230,150,150,50,186,97,36,56,231,138,101,113,6,16,89,150,197,132,16,32,226,224,22,129,32,192,57,129,72,128,
115,14,65,2,66,8,16,39,8,33,188,239,156,219,247,8,65,16,100,95,231,130,219,99,132,128,16,246,51,4,183,199,112,226,16,220,233,151,158,35,132,115,157,11,16,17,132,224,32,33,192,221,231,144,128,224,2,156,
4,72,144,51,23,110,95,183,251,136,11,193,136,4,145,32,29,140,213,162,145,72,73,85,148,226,193,67,135,138,151,4,67,114,249,252,149,39,39,39,63,50,63,63,127,207,194,194,194,141,43,43,43,35,186,174,39,56,
231,113,195,52,99,130,115,85,8,193,108,2,56,132,35,155,80,68,228,125,246,250,0,80,183,113,78,159,253,217,25,199,157,49,228,50,69,254,44,66,239,35,112,110,145,203,140,224,117,225,188,211,121,182,252,60,
65,32,80,96,46,68,196,137,200,4,160,19,81,27,140,149,53,85,157,82,85,117,76,211,180,95,18,163,147,147,199,39,249,251,202,144,210,202,202,109,111,191,243,206,35,199,143,31,191,99,97,97,225,250,161,181,
235,50,107,239,184,59,149,202,100,19,145,88,76,131,32,155,104,228,44,12,4,120,139,3,224,246,19,1,68,16,32,167,15,129,62,178,57,228,245,7,159,5,8,34,255,58,92,2,2,45,195,64,185,222,68,93,215,161,27,38,
44,33,0,18,16,2,32,56,26,224,48,198,37,186,207,120,73,16,220,103,58,194,224,49,206,153,11,231,22,45,159,155,90,169,45,204,137,197,3,123,171,76,97,75,17,45,114,68,211,180,55,192,216,142,115,103,207,54,
46,42,67,234,181,218,186,209,35,71,254,122,247,238,221,31,203,231,243,215,221,245,71,95,234,27,92,183,62,67,36,0,1,111,97,97,194,185,82,233,107,128,221,143,208,88,225,245,137,16,115,186,49,6,32,18,0,17,
116,211,66,177,222,68,189,221,134,110,88,16,8,106,141,61,204,213,40,128,136,219,76,65,72,51,101,205,37,89,43,109,198,11,247,253,130,32,32,100,173,1,9,66,41,159,171,157,126,229,133,178,94,45,151,34,145,
200,190,72,52,242,252,236,204,236,235,23,133,33,185,252,210,131,59,118,188,250,213,137,241,137,123,62,250,103,95,189,50,157,29,72,186,196,180,205,142,51,176,11,225,228,197,200,18,237,51,161,139,22,16,
217,132,148,152,12,73,11,86,26,77,148,155,45,180,13,19,92,136,46,196,116,199,10,201,228,65,26,103,127,23,36,236,121,80,183,49,18,67,195,154,229,140,19,32,16,247,199,3,4,211,52,233,157,199,254,117,134,
9,113,54,26,139,109,3,240,31,75,75,75,173,247,132,33,156,204,200,241,99,39,254,238,245,157,59,191,96,105,209,155,238,248,194,151,174,100,140,49,251,229,190,148,174,46,209,142,68,58,154,2,1,201,68,57,102,
201,177,211,178,41,115,53,128,8,128,16,16,0,150,107,53,84,155,58,116,203,242,174,249,210,235,155,27,223,212,4,165,156,228,254,110,12,116,253,13,113,128,208,225,111,2,76,16,36,153,76,247,187,240,4,134,
136,112,122,215,27,11,185,209,253,197,136,166,189,22,137,104,223,94,90,202,205,174,70,103,245,66,152,65,68,137,163,71,142,254,253,214,151,183,61,178,254,222,79,108,184,254,247,239,29,2,99,12,32,121,20,
136,152,163,9,254,21,34,239,147,127,193,213,12,56,90,0,0,204,151,44,120,215,108,211,5,1,228,107,53,44,85,234,200,215,234,104,58,218,224,61,223,213,80,72,166,81,158,132,243,217,30,235,206,197,237,151,132,
200,125,47,9,127,102,238,117,119,172,59,39,239,151,43,109,222,47,137,22,54,195,51,107,214,165,7,55,108,204,206,29,220,55,34,132,88,147,78,247,156,108,54,155,197,95,139,33,150,197,19,227,227,199,254,97,
219,182,151,31,186,249,190,251,215,14,94,123,93,198,89,181,79,230,192,66,201,103,72,104,140,68,230,16,43,59,104,228,152,163,22,150,170,117,228,106,117,180,76,110,75,172,204,74,18,238,242,59,136,5,132,
36,222,37,46,147,76,162,112,230,206,132,39,6,66,154,187,35,11,158,153,114,231,41,228,137,7,214,37,253,148,104,66,4,168,145,136,58,184,97,83,122,254,224,190,44,17,178,201,100,234,80,187,221,106,252,202,
12,121,244,209,71,255,118,219,182,109,15,111,184,255,243,55,101,174,94,211,39,92,39,193,130,2,232,147,90,210,10,162,0,51,194,139,240,38,45,249,140,166,105,34,87,173,35,87,173,163,161,27,182,95,0,73,190,
197,189,207,151,82,146,165,24,210,56,143,113,8,48,5,146,100,59,1,156,212,37,51,23,65,77,147,222,1,153,209,240,9,15,201,252,218,172,244,199,170,145,136,58,120,235,198,222,133,131,239,196,192,136,197,153,
250,182,110,89,116,193,12,169,215,235,119,110,223,190,253,175,148,84,250,230,53,27,239,200,130,68,64,172,61,226,64,34,64,151,201,51,105,194,196,124,109,144,12,22,138,205,22,150,42,53,148,91,45,88,150,
128,108,189,108,41,38,39,130,147,25,3,223,84,57,132,22,20,32,81,23,98,250,132,20,225,62,234,22,166,75,26,232,170,140,52,115,47,84,150,204,158,47,4,118,212,230,203,1,65,139,68,213,118,171,65,141,220,18,
65,83,207,24,134,177,40,211,92,121,23,191,17,61,112,224,192,151,103,103,103,55,108,216,252,224,21,65,223,64,65,115,4,201,68,81,200,59,132,37,137,130,182,121,169,90,199,169,66,9,43,205,22,44,1,192,241,
67,68,4,98,20,144,72,116,152,65,95,3,194,54,93,132,180,196,157,188,144,24,196,32,219,126,234,48,179,128,51,7,121,221,44,232,171,36,179,96,91,13,233,121,126,31,5,132,98,253,39,62,115,149,16,226,90,33,196,
71,34,145,152,122,65,12,153,155,155,187,115,98,98,98,211,109,155,31,28,4,99,12,33,179,35,58,84,5,65,175,16,32,6,2,230,194,228,28,11,213,26,206,20,75,168,235,134,100,114,132,20,218,74,49,0,57,78,50,28,
14,59,191,89,135,13,151,204,168,251,108,38,5,20,225,60,70,10,54,58,131,10,72,207,135,175,153,20,14,197,165,192,128,40,104,25,59,44,7,112,229,61,31,187,154,136,110,141,71,35,189,23,196,144,233,233,233,
143,45,47,47,175,205,174,189,182,183,67,123,66,182,90,246,29,158,244,123,196,98,96,206,139,44,33,176,88,109,96,190,92,135,110,90,80,192,160,50,64,13,252,102,80,20,6,133,1,10,3,84,6,251,187,2,40,42,131,
170,40,80,153,2,85,97,80,20,5,10,179,255,171,204,191,166,48,37,48,78,83,24,84,248,159,53,5,246,117,69,129,198,20,104,76,133,166,216,215,85,69,133,162,40,210,119,233,55,83,160,40,246,122,228,133,203,194,
70,20,208,175,64,72,79,142,73,37,34,244,173,187,190,23,68,195,28,52,44,211,86,235,154,115,112,158,218,190,125,251,250,193,107,214,166,237,240,22,1,53,14,185,240,160,41,146,165,129,1,26,99,80,24,67,169,
105,192,176,76,244,196,162,72,69,53,59,17,147,160,14,225,235,186,51,105,46,65,33,240,67,81,201,166,11,41,244,21,78,30,224,250,28,97,39,39,1,159,224,190,195,13,175,237,220,133,252,196,48,156,139,72,99,
4,217,128,100,219,48,81,111,53,81,111,235,222,61,0,65,48,217,84,201,129,7,5,204,38,115,198,37,251,179,73,2,75,128,40,125,94,134,84,42,21,173,92,46,15,94,121,203,134,152,47,237,76,138,46,164,104,42,108,
226,65,176,141,136,128,2,134,82,75,71,66,83,48,152,138,35,166,165,160,184,247,49,95,154,60,199,39,57,103,239,90,192,4,248,4,247,62,203,125,210,61,68,97,127,21,12,135,65,157,126,14,142,163,135,100,130,
124,188,138,163,222,214,145,43,87,48,87,224,104,233,38,184,155,232,10,41,220,39,132,34,76,41,160,145,2,33,198,24,99,10,139,146,16,201,243,50,100,110,110,78,213,117,61,217,203,84,78,128,99,116,220,69,178,
64,22,65,33,51,230,26,206,82,75,71,181,213,70,68,85,193,16,69,79,148,16,215,84,36,34,26,84,198,58,146,16,234,22,86,174,218,215,45,196,14,122,172,48,97,16,10,139,113,158,247,249,12,34,88,150,133,74,179,
133,106,179,141,70,187,141,182,110,248,204,8,91,143,0,163,131,254,12,204,15,122,24,3,160,70,84,8,29,231,101,72,163,209,96,68,196,60,100,197,125,8,28,32,46,96,151,130,11,212,45,142,92,163,1,203,178,113,
43,110,114,8,161,131,59,123,14,217,100,28,169,104,4,170,162,216,218,34,135,193,129,207,204,143,82,92,117,98,204,211,214,110,81,155,19,55,73,247,73,99,67,182,189,35,121,165,160,81,118,97,120,139,115,84,
154,45,204,21,86,112,54,183,140,92,169,130,70,91,7,23,20,140,32,133,164,185,82,224,227,229,53,78,8,236,106,60,39,1,178,12,131,49,198,207,203,144,116,58,77,138,162,112,34,30,208,2,33,19,65,134,19,156,1,
203,141,22,106,110,212,228,44,92,16,161,101,112,24,150,5,195,178,160,91,22,134,82,73,164,99,81,68,84,197,150,20,116,215,186,128,195,236,118,49,248,165,75,216,26,30,17,66,5,208,253,89,46,230,213,50,12,
20,170,53,76,231,139,152,89,46,96,185,90,67,187,109,11,151,156,179,120,185,152,124,191,100,191,92,33,38,6,55,245,135,176,147,45,157,24,171,159,151,33,87,93,117,21,79,36,18,117,48,166,146,35,121,76,82,
183,0,68,194,0,195,226,200,213,155,176,56,119,226,118,217,47,216,255,57,231,168,180,9,38,231,48,44,142,225,158,36,122,227,49,196,52,21,138,171,139,33,194,211,170,36,11,143,241,19,208,144,69,237,114,55,
173,242,147,121,224,166,197,5,26,237,54,242,149,42,166,243,5,204,22,138,88,169,213,97,72,24,90,208,91,34,152,80,6,36,74,114,178,146,255,107,20,139,77,198,80,83,21,165,124,222,176,55,147,201,88,217,108,
118,97,230,208,254,188,55,85,17,206,208,157,12,187,209,198,98,173,9,203,217,231,240,108,57,163,192,96,34,130,97,89,168,235,6,114,181,6,102,203,85,228,235,13,52,116,3,150,179,235,119,1,40,231,187,50,198,
119,214,97,30,80,119,237,160,96,40,47,156,57,150,27,13,204,20,138,56,49,191,136,179,185,101,20,171,13,232,166,9,33,231,27,97,152,164,195,161,80,8,58,10,198,165,133,241,209,60,131,50,77,160,226,121,25,
194,24,107,12,143,140,236,39,211,88,38,33,72,70,82,101,169,90,168,53,80,51,77,71,61,229,104,143,5,146,39,121,166,166,37,80,55,76,228,235,13,204,149,170,88,172,214,81,109,183,97,186,91,177,239,42,209,65,
230,188,43,11,169,27,237,105,85,147,72,68,208,77,19,197,90,29,103,115,203,152,156,91,196,236,114,1,165,122,3,38,55,157,181,48,47,253,16,146,217,118,147,218,0,164,34,249,16,230,222,231,64,246,130,115,170,
156,153,156,97,10,155,168,215,27,231,55,89,0,112,205,213,87,31,186,250,234,171,79,175,156,59,115,107,246,186,27,6,228,5,24,156,99,169,222,244,98,116,230,98,72,50,12,238,42,135,240,224,31,63,44,16,132,
182,176,77,131,97,113,232,166,133,161,52,71,111,60,142,152,170,66,14,194,58,147,155,144,112,211,170,158,96,21,59,215,249,92,75,8,180,12,19,203,213,26,102,243,5,204,20,86,176,82,171,161,101,24,224,1,176,
48,8,213,4,148,1,110,240,33,111,194,217,38,141,83,112,46,11,7,247,46,40,138,114,74,85,213,189,225,105,173,154,169,15,12,12,156,189,229,150,91,118,47,30,61,124,76,112,75,184,241,118,221,48,176,88,111,131,
123,128,154,47,23,94,156,19,128,32,66,16,136,183,161,104,111,185,150,91,45,204,87,106,152,43,85,81,168,55,208,52,12,223,78,83,208,198,83,55,39,31,78,132,186,48,166,187,118,216,38,202,228,2,245,86,27,11,
197,18,78,45,44,97,42,183,140,66,173,138,182,110,216,137,167,228,176,137,58,145,93,25,149,112,33,30,137,18,126,94,67,2,96,0,231,38,21,143,30,62,169,42,202,30,65,124,58,76,247,85,53,68,211,52,75,8,177,
125,121,121,249,150,189,207,253,164,255,174,47,255,197,166,178,110,160,210,214,157,137,49,55,214,11,248,14,17,134,193,189,127,34,0,79,11,7,116,51,45,130,37,116,88,150,133,182,105,161,157,182,48,152,74,
34,25,141,216,81,216,5,136,121,71,68,181,154,63,146,18,78,33,8,38,183,243,139,197,149,50,166,243,69,44,85,42,168,53,155,48,45,238,104,188,189,70,146,81,103,25,248,164,78,248,63,8,60,202,72,50,3,145,192,
177,39,191,63,170,170,234,126,85,211,94,171,20,139,252,130,25,2,0,138,162,228,42,149,202,19,173,86,59,117,236,149,23,163,61,247,110,190,5,46,202,239,78,134,121,98,16,116,102,1,189,166,142,196,205,45,124,
0,0,193,5,26,156,195,228,28,186,105,66,55,77,12,167,123,208,27,143,66,83,213,142,125,102,90,37,202,66,23,198,80,135,227,23,158,243,94,169,55,48,87,40,57,33,109,29,45,67,135,201,69,0,137,8,88,76,230,64,
41,193,28,64,178,14,161,45,9,9,149,0,17,38,159,255,239,99,17,45,178,87,213,212,39,11,203,133,133,174,138,112,190,192,166,175,175,111,60,151,203,61,211,108,54,122,78,237,254,223,104,230,222,79,95,15,98,
54,142,3,25,110,70,200,185,51,15,189,197,106,112,188,240,251,133,32,180,184,9,211,178,195,98,195,178,48,156,238,65,127,34,142,168,166,217,160,94,152,201,23,144,155,4,136,70,4,238,229,23,117,204,22,138,
152,43,150,80,172,213,209,54,204,14,19,5,22,196,181,40,180,153,22,8,113,93,152,37,176,153,230,236,80,10,96,226,153,31,77,192,52,223,142,68,34,91,242,249,252,196,170,150,233,66,246,212,71,70,70,118,229,
242,121,141,237,218,197,143,189,178,165,61,244,192,195,183,194,1,228,124,28,199,118,238,20,128,161,131,56,155,36,60,54,146,192,228,226,2,39,96,176,44,148,155,2,186,105,162,101,152,104,247,246,96,32,149,
68,60,26,129,166,40,96,171,36,121,239,26,210,146,107,30,57,234,237,54,114,149,26,102,150,139,88,40,149,80,107,182,161,155,70,112,115,201,213,220,224,78,172,100,34,153,180,8,10,108,239,6,81,95,64,152,38,
159,248,201,15,142,107,17,109,79,36,30,123,124,97,97,225,157,119,163,245,5,49,4,0,70,134,135,127,81,46,151,10,217,76,246,107,187,95,125,161,221,255,169,207,111,100,154,22,145,189,132,87,180,38,71,35,33,
188,72,214,22,10,238,110,121,21,29,156,115,152,220,130,105,113,180,77,19,186,101,97,48,149,66,58,30,147,252,10,147,55,43,86,117,230,46,64,104,58,120,212,194,74,25,51,133,34,114,229,42,234,237,54,76,75,
174,37,147,124,130,144,129,83,87,242,153,239,27,200,247,213,242,66,188,141,91,70,104,21,11,245,169,173,207,141,247,100,7,222,166,118,235,223,231,230,231,79,157,143,206,23,204,16,0,232,239,207,28,109,235,
250,55,99,137,120,97,247,91,59,107,236,198,219,54,69,135,175,204,56,246,42,88,97,226,152,44,119,178,172,91,220,30,216,48,146,1,66,27,71,106,24,134,227,87,44,232,134,137,225,222,180,99,194,164,208,184,
91,238,66,50,30,69,104,91,38,74,245,6,230,138,37,204,21,86,176,92,173,163,169,187,209,156,176,147,88,17,140,162,100,24,133,201,168,50,163,32,102,37,3,137,30,136,168,96,233,157,183,230,75,199,143,78,36,
19,201,29,42,183,30,63,55,63,95,89,115,205,53,202,236,220,156,120,207,24,2,0,241,88,108,89,111,234,255,210,147,74,45,190,245,214,91,15,229,206,76,126,56,251,145,63,88,235,161,243,34,88,216,230,65,207,
82,48,32,35,173,14,234,211,185,219,71,0,39,129,150,224,176,44,19,134,105,161,109,154,48,250,250,144,77,37,16,143,104,80,24,67,183,148,197,53,35,92,8,52,61,127,177,130,185,149,18,202,245,166,237,47,188,
154,43,248,123,44,114,149,101,104,43,32,176,179,136,112,53,139,115,157,217,107,63,181,229,199,39,201,104,143,166,82,201,173,45,157,61,61,123,110,138,214,173,91,167,76,79,79,139,139,90,219,59,53,53,181,
249,173,93,187,190,122,124,114,242,174,225,7,255,116,131,92,27,11,185,140,211,43,70,115,170,1,67,155,82,238,230,146,95,232,28,46,90,19,80,20,134,84,52,130,161,116,15,174,236,235,197,96,58,133,84,52,10,
85,177,247,36,229,12,153,72,192,244,246,47,170,152,41,172,96,169,92,65,181,217,130,97,89,222,59,92,71,44,23,113,251,69,113,82,233,171,87,140,39,207,211,143,38,221,249,11,203,18,39,158,250,207,227,177,
88,108,79,34,17,255,209,137,19,147,251,126,85,154,106,191,9,67,214,175,95,191,115,102,118,54,151,29,200,126,237,237,215,94,104,245,127,234,15,55,146,170,69,194,85,40,129,125,51,22,148,72,162,80,102,31,
44,180,240,238,183,184,64,173,213,134,97,114,219,217,155,38,70,122,211,72,199,99,208,84,197,169,219,115,49,51,142,114,179,137,197,82,5,179,197,21,228,203,53,212,219,58,56,183,36,28,10,129,74,145,142,141,
62,80,103,248,138,176,191,240,231,222,88,156,43,205,238,124,101,170,167,167,231,151,241,68,236,187,199,142,142,79,253,58,52,253,141,24,2,0,107,215,172,57,186,188,188,252,205,120,60,81,216,187,123,103,
77,172,89,255,161,196,186,27,6,229,58,92,116,84,117,132,251,124,204,180,163,112,64,202,107,44,34,112,195,128,89,225,208,13,19,109,195,196,21,253,189,232,79,218,161,177,91,112,189,210,104,96,97,165,140,
217,98,9,133,106,29,109,195,173,239,10,103,14,193,18,157,240,150,43,133,203,106,186,20,44,0,192,242,193,125,243,213,83,227,19,253,3,217,215,52,198,126,56,54,54,86,254,192,15,236,228,115,249,248,233,51,
167,255,124,207,222,61,95,44,90,184,189,255,238,143,175,245,234,92,229,162,103,185,120,89,50,75,158,217,112,28,58,66,38,194,53,25,110,52,166,49,21,189,137,24,134,123,123,112,85,166,15,153,84,18,32,66,
209,113,222,11,43,21,148,27,13,232,142,137,18,206,249,19,4,222,217,105,30,237,62,4,142,30,120,213,241,29,69,220,2,83,63,123,234,36,179,172,209,100,50,249,114,132,155,79,243,104,132,145,128,24,27,27,163,
15,148,33,110,27,27,59,178,121,223,222,183,31,61,113,250,228,61,67,247,255,241,141,196,152,234,249,10,105,177,54,109,69,208,127,120,254,70,34,72,96,172,127,78,67,0,80,25,67,79,44,130,129,158,30,12,164,
83,128,32,228,171,53,228,43,53,84,155,77,24,156,75,199,12,228,247,200,133,209,206,179,229,247,202,135,124,164,185,8,239,72,3,65,112,139,159,254,233,143,198,19,137,196,219,61,169,158,255,218,127,96,255,
222,219,111,223,164,48,40,116,120,244,48,125,224,26,34,183,241,227,19,183,29,61,114,228,47,15,28,56,248,201,204,167,191,240,33,82,213,72,64,19,16,36,188,127,134,35,84,165,78,62,49,101,102,200,26,167,40,
64,84,213,144,136,104,32,34,212,117,29,45,221,132,229,248,139,160,6,146,116,236,192,134,10,220,227,113,194,171,100,9,190,35,116,106,10,68,2,122,185,212,152,121,229,103,19,189,189,189,191,72,165,82,143,
237,222,189,123,234,189,162,221,69,97,136,19,129,13,141,141,141,125,125,255,254,253,247,171,55,111,218,164,14,93,145,129,36,237,29,103,44,156,210,31,255,48,140,8,157,235,128,20,253,8,7,198,119,142,65,
8,103,191,157,236,179,136,194,145,110,249,188,71,231,185,15,132,142,40,136,96,228,36,252,189,111,72,204,89,216,185,253,172,94,204,79,247,247,247,237,136,199,162,223,123,115,215,238,234,123,73,183,139,
198,16,0,56,115,122,42,126,102,234,244,87,246,239,223,255,80,193,20,31,238,191,231,19,107,101,179,20,12,119,165,67,60,242,57,143,192,217,63,71,187,184,115,114,137,228,176,26,33,134,250,247,10,72,207,226,
240,239,117,24,97,243,84,72,135,114,40,120,222,196,121,239,185,23,158,154,140,42,202,88,42,149,218,202,154,218,211,123,70,223,20,239,53,205,148,139,201,144,235,127,111,125,251,179,159,253,236,127,125,
242,190,251,190,187,182,175,231,255,242,219,183,76,200,137,151,12,66,49,132,107,108,33,21,55,187,53,185,14,113,24,117,217,214,117,118,184,41,184,183,237,151,147,73,37,165,161,247,147,92,226,212,181,128,
92,240,115,207,61,49,150,138,197,222,204,102,50,223,222,187,103,207,83,145,12,187,40,180,187,168,26,34,183,125,251,246,221,54,113,124,226,107,135,15,141,126,178,239,227,155,111,70,60,153,164,14,155,237,
107,6,156,8,77,4,28,60,5,79,41,117,137,220,16,246,83,66,58,180,9,233,180,47,133,78,216,134,53,194,121,183,89,45,213,23,94,125,113,188,191,63,243,102,186,47,253,189,29,175,236,56,187,121,243,102,109,231,
206,157,214,111,53,67,0,96,116,116,116,104,98,124,252,111,14,30,58,116,191,122,243,166,141,218,224,21,153,224,25,62,127,35,171,131,112,242,209,105,207,15,8,63,74,10,57,112,183,79,62,168,233,162,2,182,
31,227,33,244,0,222,121,118,247,57,165,35,7,22,155,83,147,227,153,76,230,231,169,100,242,241,109,219,183,87,46,54,141,222,87,134,0,192,193,67,135,226,211,231,206,125,229,240,225,195,15,149,149,232,157,
169,77,119,175,9,71,66,20,242,31,98,149,168,199,118,186,62,115,72,42,72,147,239,129,19,201,133,79,213,194,57,164,42,186,156,27,156,222,242,196,201,68,34,113,44,155,205,190,244,234,171,175,254,248,253,
162,207,251,206,16,183,237,216,177,99,243,161,195,135,31,157,58,123,246,158,129,251,191,120,35,49,168,246,95,93,112,143,26,35,40,229,232,150,180,137,174,135,53,253,194,106,209,129,85,201,249,144,144,48,
42,207,63,113,193,103,94,248,201,120,255,240,21,71,250,146,177,199,182,190,180,117,247,251,73,23,229,131,98,200,3,15,60,176,243,238,187,238,250,214,237,27,55,238,40,189,254,210,17,88,194,10,215,233,10,
10,23,143,80,176,52,211,117,226,8,109,132,121,192,161,188,183,45,109,58,65,46,69,245,11,42,120,189,82,159,127,249,233,3,35,35,35,59,250,83,137,127,220,250,210,214,221,15,255,201,195,145,247,147,46,31,
152,134,184,109,215,155,111,14,77,158,156,252,250,225,195,163,159,195,53,215,221,20,185,246,198,17,70,93,32,23,239,79,91,72,8,172,64,7,20,35,40,116,20,58,240,23,26,252,252,68,206,218,5,17,106,199,14,207,
183,206,158,156,24,26,26,218,209,211,211,243,248,51,207,60,83,121,228,145,71,212,45,91,182,240,223,41,134,0,192,47,127,177,43,62,61,123,246,43,99,99,99,15,85,181,248,157,137,141,119,173,129,148,156,9,
41,9,12,103,245,66,202,37,186,157,33,39,10,66,34,34,156,219,64,96,233,231,47,158,140,171,24,29,204,14,110,45,177,216,211,111,252,207,211,244,65,209,226,146,96,136,219,182,60,255,252,230,177,35,71,30,157,
158,153,185,51,243,185,47,222,42,56,88,199,222,202,42,160,100,48,92,166,64,4,38,103,222,130,132,23,121,129,4,159,127,233,167,71,51,153,204,254,145,225,145,31,61,249,227,39,247,125,208,52,184,164,24,2,
0,207,62,247,236,109,51,51,51,95,62,117,242,212,71,217,53,215,221,164,173,187,225,42,15,1,150,114,10,33,69,79,222,201,42,193,165,83,86,126,100,5,233,68,149,235,200,219,231,78,45,53,142,31,57,58,48,48,
176,119,48,155,125,242,7,63,252,225,212,165,176,254,75,142,33,0,176,109,219,246,254,249,249,217,251,230,23,22,63,51,125,238,220,157,145,235,110,90,175,173,189,126,36,104,166,58,147,61,200,96,165,252,167,
154,164,92,197,152,63,87,168,140,190,115,162,191,191,127,180,183,183,247,245,84,50,249,198,247,31,123,172,126,169,172,253,146,100,136,219,94,124,241,197,236,236,236,236,231,231,230,230,62,154,207,231,
111,176,210,253,215,38,215,223,60,76,169,158,52,23,196,220,156,196,45,231,20,14,198,5,87,67,108,51,70,162,144,43,85,79,77,20,168,178,50,147,76,246,76,246,245,247,237,233,75,167,95,255,183,239,124,103,
249,82,91,243,37,205,16,183,61,247,236,179,153,165,220,210,45,133,229,226,135,43,213,202,77,213,106,245,154,150,174,15,136,72,172,39,146,29,76,43,189,253,73,48,69,33,48,198,245,150,101,181,154,102,99,
234,228,50,184,213,140,168,90,41,26,143,45,36,226,241,99,169,84,234,112,50,149,60,241,173,127,254,86,249,82,93,235,111,5,67,228,246,196,19,79,36,218,237,246,208,226,226,226,80,179,217,28,108,183,218,189,
134,101,198,185,101,105,206,169,92,1,160,17,137,68,234,17,45,146,75,247,165,243,170,162,148,191,241,141,127,106,224,114,187,220,46,183,203,237,114,187,220,46,183,203,237,114,251,29,109,255,15,140,78,53,
54,190,170,232,177,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LivePanelComponent::gmfullOff_2x_png = (const char*) resource_LivePanelComponent_gmfullOff_2x_png;
const int LivePanelComponent::gmfullOff_2x_pngSize = 6122;

// JUCER_RESOURCE: smallButton_2x_png, 1861, "../Images/SmallButton@2x.png"
static const unsigned char resource_LivePanelComponent_smallButton_2x_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,60,0,0,0,60,8,6,0,0,0,58,252,217,114,0,0,0,1,115,82,71,66,0,174,206,
28,233,0,0,0,6,98,75,71,68,0,0,0,0,0,0,249,67,187,127,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,219,12,24,17,12,40,96,148,250,140,0,0,6,197,73,68,65,84,104,222,237,
90,77,139,28,85,20,61,29,242,111,92,5,92,4,2,18,5,157,133,160,89,72,22,42,18,144,184,16,36,160,11,107,8,110,66,226,20,145,104,98,34,162,97,220,101,229,71,76,132,224,198,77,150,34,126,36,19,135,96,38,127,
192,133,203,100,82,117,207,117,241,222,125,239,190,234,26,233,238,84,103,18,169,7,77,117,79,213,84,191,243,238,185,231,158,119,171,129,113,140,99,28,227,24,199,56,198,177,91,99,242,136,191,111,237,63,
206,173,254,31,0,79,1,252,238,198,237,10,80,144,10,85,64,65,28,222,247,84,253,168,22,96,178,108,160,87,110,221,169,12,152,82,161,170,80,42,8,2,84,16,128,42,161,4,20,10,37,241,250,254,125,245,178,128,79,
150,5,244,234,159,91,149,1,160,34,0,141,96,85,9,168,130,240,127,11,47,170,134,115,170,56,114,224,233,193,129,79,134,6,123,117,243,110,165,170,49,122,10,40,193,4,42,68,154,17,32,122,35,157,193,43,0,21,
226,205,131,251,235,161,64,79,6,141,234,230,221,202,34,24,162,27,65,179,140,92,166,48,139,107,124,148,83,228,227,53,111,61,119,96,144,104,79,134,0,251,195,230,221,202,3,66,223,164,253,185,192,241,18,156,
186,107,140,13,246,55,40,32,225,248,246,243,207,60,84,180,39,195,80,152,113,130,49,103,1,128,220,1,124,184,198,24,48,5,44,177,193,82,33,222,23,249,222,239,172,28,92,24,244,158,135,9,239,149,205,173,74,
149,32,17,64,24,72,218,100,9,153,162,103,56,71,102,122,83,21,84,66,37,150,171,248,127,246,119,42,65,187,167,16,231,174,253,84,45,58,231,61,15,19,93,165,213,83,166,137,105,4,66,50,170,176,77,150,14,164,
229,49,33,241,72,34,131,83,133,74,88,164,148,219,140,98,135,112,191,25,140,204,96,148,94,3,128,203,183,238,84,72,20,206,165,165,151,194,26,74,19,98,137,74,116,45,104,45,241,154,72,105,39,104,93,234,219,
189,223,123,121,101,110,106,47,20,225,203,27,127,85,160,163,153,139,130,104,142,170,167,112,58,26,88,139,162,42,72,41,207,209,177,193,174,81,73,172,48,86,157,190,124,173,90,54,165,3,149,85,3,48,155,84,
1,62,215,89,70,202,83,220,103,163,59,53,229,102,98,3,35,120,184,5,66,190,134,98,236,145,180,176,243,82,123,238,8,127,123,227,118,85,68,204,9,83,202,231,78,84,145,38,29,34,164,113,210,62,239,3,216,168,
246,78,252,36,45,76,48,41,150,239,182,176,31,126,115,117,174,40,239,93,36,186,221,114,99,121,87,248,101,85,60,104,5,141,180,104,90,65,35,130,166,109,209,180,68,43,45,90,17,180,34,16,17,180,36,90,137,11,
69,201,116,142,204,129,105,0,20,19,205,226,51,153,0,123,39,19,63,191,213,33,69,107,237,235,63,54,43,13,30,48,68,70,1,161,224,126,211,98,187,105,177,221,52,216,110,91,108,183,45,154,166,13,165,133,18,106,
169,1,49,49,50,69,79,239,153,76,135,69,52,105,65,241,57,51,39,179,136,248,254,248,187,245,44,128,231,137,48,148,138,123,77,131,123,15,26,220,143,199,7,173,244,228,111,164,106,172,155,116,53,85,149,33,
167,93,158,210,213,240,94,112,238,156,198,242,229,23,205,229,242,160,148,198,214,223,255,20,70,64,189,56,169,148,34,214,183,0,180,250,204,162,134,171,132,200,219,61,125,244,187,202,173,78,232,252,113,
104,209,90,3,2,125,133,4,37,79,76,40,33,239,132,225,156,125,182,247,26,143,98,234,28,34,44,150,179,18,204,135,8,243,53,118,76,139,27,238,41,222,117,117,94,179,170,245,204,42,125,242,199,235,85,162,30,
35,80,177,247,44,202,141,80,227,2,132,28,14,231,197,57,46,201,84,37,29,165,243,103,91,60,17,134,180,160,66,69,210,66,73,90,212,240,90,57,126,178,26,148,210,66,38,113,241,246,113,42,231,52,71,82,187,134,
35,150,20,216,53,93,250,79,229,179,118,104,222,201,115,103,124,102,165,245,204,128,19,56,113,95,226,141,131,155,132,89,73,165,203,235,169,73,122,223,92,2,180,243,234,196,169,80,103,159,195,110,145,7,142,
176,132,146,225,69,69,217,83,42,24,237,32,179,145,136,38,67,24,252,180,40,83,237,46,5,168,100,75,218,65,217,246,209,137,24,58,238,78,85,135,5,108,84,22,247,5,66,231,156,122,41,202,98,129,242,226,120,16,
130,80,126,67,174,138,57,44,215,20,240,233,208,173,6,201,103,83,135,181,150,167,14,173,212,89,133,153,192,26,173,205,100,72,20,20,49,91,88,8,157,119,83,38,60,81,177,163,202,67,76,43,36,138,149,64,218,
44,128,106,105,227,239,33,138,235,103,78,214,67,2,94,181,60,206,165,69,82,89,201,165,200,149,158,244,94,18,240,92,154,202,207,54,121,42,33,42,105,1,90,219,48,164,107,20,34,86,26,243,98,74,206,223,97,157,
22,59,197,127,90,93,53,119,37,201,94,71,36,140,237,27,106,121,63,79,81,167,7,112,90,33,190,25,224,132,141,51,210,121,110,192,66,238,144,171,59,184,171,216,187,202,202,158,187,22,121,119,196,178,221,195,
238,61,58,34,217,209,8,77,13,131,37,108,15,207,190,122,168,206,52,246,78,170,204,205,228,142,204,65,121,131,81,252,77,203,243,162,249,222,206,168,168,63,22,175,32,156,63,95,56,93,47,3,112,206,99,53,209,
10,19,84,203,171,152,79,98,46,203,91,196,52,65,73,121,151,22,197,187,55,179,144,17,76,206,89,251,14,205,206,43,50,110,158,54,207,220,13,128,207,142,28,174,147,88,196,73,136,18,62,242,89,132,178,253,12,
158,89,58,214,209,169,184,137,32,213,9,33,11,131,211,245,215,66,193,47,159,159,169,231,153,255,188,128,83,148,165,40,51,86,154,88,70,52,150,24,177,82,35,57,114,234,252,176,248,255,209,232,179,197,221,
83,28,11,108,145,89,136,213,114,155,120,23,143,190,86,251,250,74,9,17,74,245,86,34,29,117,167,58,156,23,35,1,115,199,162,134,75,183,204,229,215,111,95,124,82,207,59,247,69,159,60,172,1,192,27,231,215,
171,190,210,84,90,207,238,70,33,251,95,177,246,141,119,95,83,126,57,246,191,104,143,104,194,249,223,191,60,187,208,211,135,69,27,241,171,105,7,197,146,166,229,54,48,210,182,103,15,27,196,43,239,147,69,
115,100,197,221,211,239,165,85,179,40,238,202,163,150,75,199,142,214,65,85,131,13,180,230,64,202,49,201,34,164,82,10,155,237,151,147,144,73,92,0,47,120,150,227,110,241,132,196,205,245,79,235,69,231,60,
200,211,195,87,78,95,168,186,173,156,220,206,137,91,183,180,217,40,119,89,197,198,66,186,61,45,51,46,249,222,27,235,23,118,237,233,225,84,91,229,165,83,31,87,185,201,214,113,89,126,7,37,140,59,164,29,
250,96,112,181,54,2,191,185,126,254,177,120,62,60,5,252,197,19,31,85,185,17,160,189,141,55,198,103,78,148,184,40,177,149,27,104,140,242,122,33,54,190,58,255,88,253,2,160,55,218,47,124,176,86,133,72,150,
109,152,169,231,71,96,199,59,231,30,118,39,87,31,187,223,120,244,2,127,246,253,19,21,41,49,146,221,38,66,89,146,44,159,111,92,60,247,196,252,138,103,71,224,54,246,31,91,173,186,64,127,237,183,135,79,212,
239,180,102,94,128,101,3,28,199,56,198,49,142,113,140,99,28,227,216,181,241,47,221,149,91,127,82,141,218,81,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LivePanelComponent::smallButton_2x_png = (const char*) resource_LivePanelComponent_smallButton_2x_png;
const int LivePanelComponent::smallButton_2x_pngSize = 1861;

// JUCER_RESOURCE: smallLogo_png, 3433, "../Images/SmallLogo.png"
static const unsigned char resource_LivePanelComponent_smallLogo_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,128,0,0,0,32,8,6,0,0,0,218,34,112,37,0,0,0,44,116,69,88,116,67,114,101,97,
    116,105,111,110,32,84,105,109,101,0,87,101,100,32,49,53,32,83,101,112,32,50,48,48,52,32,49,51,58,52,54,58,53,55,32,45,48,56,48,48,240,190,31,224,0,0,0,7,116,73,77,69,7,212,9,15,20,48,17,190,209,155,19,
    0,0,0,9,112,72,89,115,0,0,10,240,0,0,10,240,1,66,172,52,152,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,12,192,73,68,65,84,120,218,237,90,11,84,85,101,22,254,206,229,94,94,23,132,203,195,23,138,128,
    10,153,40,34,146,102,154,175,212,202,204,193,201,201,76,103,249,10,243,213,154,106,38,115,90,205,172,105,86,182,86,57,229,248,126,164,105,101,169,164,162,226,19,212,178,26,37,27,65,205,204,80,209,68,69,
    1,121,115,121,221,251,207,247,195,189,118,185,158,11,162,33,171,230,238,229,93,231,120,206,254,255,189,207,255,237,127,239,111,159,3,224,20,167,56,197,41,78,113,138,83,254,31,69,105,110,7,126,139,146,
    149,115,195,151,135,94,141,24,242,109,187,64,191,2,142,235,193,243,128,134,148,169,155,210,8,95,198,240,240,8,127,242,104,224,216,58,152,107,155,123,177,126,73,25,185,66,180,212,106,208,106,235,115,202,
    201,102,118,69,130,159,220,8,253,161,252,73,80,223,182,156,55,36,170,27,151,96,75,160,163,81,27,68,209,183,51,215,111,42,0,8,126,132,135,174,230,161,155,59,0,154,75,26,19,116,53,162,105,110,143,239,86,
    158,88,46,92,172,231,6,79,132,182,245,193,192,161,139,133,187,229,94,115,149,184,92,212,130,145,223,128,94,166,69,47,215,242,255,52,212,15,98,38,238,0,228,250,228,87,207,1,70,191,47,122,234,117,24,152,
    93,140,196,145,145,88,24,100,192,163,31,28,70,156,167,43,204,26,5,65,197,229,88,189,115,186,98,106,14,223,44,92,96,37,106,235,175,154,196,179,38,175,82,25,119,158,135,80,155,75,50,144,222,162,238,59,13,
    216,219,103,119,233,150,18,96,207,1,126,245,1,240,232,82,225,213,187,3,118,245,239,136,152,246,6,120,150,84,112,59,149,162,242,135,108,24,83,126,196,108,179,25,159,52,87,0,88,133,192,28,67,109,77,182,
    23,9,236,96,130,146,110,163,187,130,135,248,250,116,26,97,87,216,95,179,15,0,205,147,43,132,239,239,86,138,246,119,242,96,28,27,192,177,109,239,205,50,214,177,235,77,187,65,242,124,207,12,165,228,82,1,
    62,234,220,18,158,90,22,3,31,15,32,204,31,174,121,101,184,200,96,216,45,193,31,185,92,184,198,173,18,97,60,54,23,231,25,140,218,244,110,47,6,254,182,88,50,197,47,10,254,237,138,166,87,48,254,60,186,7,
    210,71,44,23,93,26,59,120,72,4,230,61,218,5,95,112,23,182,107,218,245,171,43,145,109,48,233,137,72,164,210,231,158,99,63,16,83,135,132,227,69,111,86,125,95,130,31,224,5,120,184,2,221,219,34,44,212,31,
    115,200,3,186,250,235,209,43,190,47,142,187,235,28,166,226,38,21,217,226,241,48,25,234,156,64,166,250,3,205,1,190,20,141,151,27,188,92,20,248,153,204,8,110,236,96,31,119,232,21,5,193,76,179,109,154,210,
    73,123,97,125,119,151,245,157,62,183,174,172,70,241,201,43,56,115,189,24,102,25,0,94,4,159,215,240,221,85,100,51,3,120,85,155,161,119,211,66,207,160,240,226,245,240,123,233,167,173,88,128,148,153,64,45,
    8,100,121,136,183,187,54,167,169,193,151,162,49,9,152,184,72,82,68,99,7,115,156,28,91,125,39,99,239,70,204,2,102,139,207,198,45,207,41,27,191,207,198,123,95,159,135,241,139,179,168,60,156,9,113,48,3,229,
    44,11,233,133,70,188,200,18,241,141,89,62,163,169,198,201,102,229,2,22,64,231,220,134,170,42,57,108,10,209,202,85,185,167,232,253,2,98,245,87,177,144,88,238,112,221,182,19,152,233,234,2,189,167,27,162,
    153,13,18,153,217,90,19,248,42,121,191,210,132,18,57,166,202,4,99,115,251,46,129,181,212,252,183,29,168,172,188,87,224,75,209,90,23,147,233,180,92,30,159,249,64,68,6,249,34,154,100,42,152,105,214,131,
    139,86,89,96,68,214,213,66,164,241,120,98,239,204,159,25,181,217,6,9,171,144,156,249,135,5,96,124,102,30,182,111,125,78,201,84,51,58,125,163,120,154,243,150,188,63,78,217,105,189,54,108,177,208,4,122,
    35,138,76,190,39,211,120,91,206,233,86,81,133,178,124,146,185,107,197,72,75,152,162,124,111,213,21,210,174,77,212,242,222,126,121,28,187,86,244,48,120,34,34,175,4,159,211,165,160,1,157,240,102,255,221,
    162,146,28,32,148,65,130,216,14,24,217,111,175,240,101,41,16,167,175,97,199,166,201,202,81,123,223,158,90,45,58,7,27,16,99,240,64,152,70,3,79,250,89,85,88,142,172,107,69,248,238,70,25,210,152,81,42,239,
    118,209,101,59,199,32,152,142,186,173,158,85,226,121,47,133,58,9,77,142,62,100,0,136,154,157,97,214,187,33,114,237,17,49,135,0,12,255,41,31,213,87,10,113,221,88,137,18,23,23,232,58,6,160,101,159,16,180,
    184,90,132,84,253,251,226,165,45,83,149,255,88,129,16,118,233,131,181,54,244,145,8,44,88,115,24,58,254,119,190,154,209,190,97,152,155,149,143,170,161,139,197,161,228,89,74,241,248,15,197,192,39,186,226,
    77,18,184,7,207,231,194,72,192,115,9,126,169,86,3,215,136,86,8,232,19,10,125,76,178,56,112,36,19,127,79,140,87,142,208,166,106,210,10,241,67,108,108,48,94,200,184,142,29,4,47,135,65,52,168,188,10,94,165,
    149,208,51,120,193,50,16,198,145,129,44,31,50,100,243,71,44,19,255,101,151,80,83,76,216,89,4,143,232,138,249,225,173,48,234,114,1,20,174,65,14,159,191,136,138,154,246,190,240,235,217,14,134,124,35,78,
    26,214,138,127,126,58,81,217,114,55,139,110,33,124,161,245,168,172,160,78,198,189,224,0,90,46,134,217,207,19,202,172,254,120,79,2,191,252,43,124,200,197,74,226,189,83,36,120,133,92,48,23,46,87,203,22,
    110,24,220,59,4,179,159,236,134,125,46,107,196,196,132,201,202,103,102,245,234,97,46,171,132,224,188,174,142,140,18,136,82,2,163,171,50,163,98,242,122,49,108,202,131,72,60,126,25,213,9,105,88,85,84,142,
    109,84,201,160,237,98,33,109,179,85,34,123,127,128,125,254,223,158,141,197,126,215,53,98,18,179,149,73,173,114,9,94,47,171,221,159,126,27,39,41,41,249,75,196,80,250,161,11,242,193,160,110,109,144,144,
    126,25,235,88,14,22,49,179,105,116,26,148,211,70,205,28,204,90,157,167,244,197,54,99,21,186,48,112,19,25,128,9,204,110,199,169,39,9,155,160,31,222,12,198,46,61,218,97,206,51,49,216,28,144,32,22,100,228,
    96,46,179,65,249,29,130,31,223,128,154,108,15,101,103,16,102,233,32,154,48,0,76,16,140,112,133,196,169,52,249,12,230,242,65,55,112,87,22,218,233,93,230,47,173,96,177,248,108,120,23,36,14,141,192,154,220,
    133,34,131,236,191,234,86,20,172,255,96,118,100,84,150,14,222,52,186,107,209,109,124,44,214,127,158,129,156,148,31,240,170,187,43,146,100,70,176,213,101,27,87,197,12,228,74,31,171,217,173,120,210,191,
    56,142,207,80,155,223,198,151,154,123,251,102,42,69,242,200,32,203,145,71,157,11,140,187,166,43,215,109,199,12,95,34,220,199,68,227,163,242,74,132,175,252,26,115,93,52,88,203,113,217,182,58,108,115,11,
    218,25,16,201,210,38,56,135,252,230,16,167,212,190,225,59,221,152,197,118,0,254,43,252,205,69,45,232,182,98,13,130,193,77,25,4,90,166,74,205,101,194,125,232,28,62,118,213,224,163,93,51,148,50,71,202,41,
    179,148,139,190,171,197,203,227,123,97,127,155,22,136,103,240,200,241,183,48,235,154,178,80,207,59,70,6,14,170,170,81,222,181,13,198,177,252,4,124,117,14,175,178,116,108,218,101,243,198,110,204,106,17,
    19,211,30,211,186,182,197,31,88,179,125,210,179,112,146,89,226,13,166,243,4,6,196,147,80,249,142,97,118,76,104,93,44,215,111,25,211,210,27,3,66,252,209,123,233,33,108,214,186,96,25,119,245,205,224,103,
    89,8,189,191,13,38,176,172,76,37,135,104,127,234,42,46,237,253,30,139,75,42,177,155,65,112,165,49,11,237,0,252,120,11,41,148,239,247,15,224,214,32,144,237,225,38,254,134,221,5,198,245,138,150,56,185,144,
    104,193,100,194,193,61,51,29,131,111,21,166,201,195,76,163,197,44,27,17,204,195,69,26,187,122,108,199,207,84,69,226,68,176,180,1,122,4,95,202,175,33,160,7,247,205,82,76,195,150,8,143,14,6,196,197,4,99,
    10,185,200,32,242,144,138,29,39,113,144,165,41,137,58,159,147,229,159,217,63,91,49,245,73,18,195,161,18,98,53,182,85,140,155,133,250,117,41,190,36,123,5,124,106,150,189,47,173,224,147,8,63,220,43,24,207,
    135,183,196,40,130,237,201,22,51,149,188,98,133,177,26,201,244,225,68,99,83,127,125,224,203,19,89,235,169,35,219,195,149,42,195,135,202,241,212,153,118,231,48,59,22,45,193,207,239,210,186,38,173,121,223,
    206,0,102,137,14,236,16,244,197,21,40,179,46,186,157,40,22,150,94,95,9,16,76,181,230,220,82,228,135,249,147,56,234,208,237,229,45,98,80,143,246,152,204,14,32,252,199,235,184,122,40,3,235,114,74,177,153,
    117,248,27,118,30,117,210,54,28,0,234,8,100,169,47,131,64,45,41,145,115,92,99,22,131,183,59,58,196,127,42,38,18,248,169,173,91,224,33,6,102,113,226,9,164,100,21,32,145,67,15,144,51,100,49,3,54,250,61,
    66,67,224,91,197,146,9,228,169,90,16,200,206,224,108,67,31,131,238,68,180,231,114,145,72,114,247,26,119,221,172,138,197,98,171,125,13,182,151,126,157,240,122,89,21,52,92,160,175,56,166,39,137,151,198,
    218,111,75,225,121,37,83,169,134,0,251,168,141,31,178,72,40,122,87,200,247,248,153,103,174,97,235,3,193,152,48,233,65,172,44,52,162,250,187,43,72,63,157,141,215,56,127,50,23,252,52,125,41,177,142,99,173,
    118,165,159,11,216,227,159,98,54,168,105,95,105,171,218,30,104,7,162,97,32,73,230,120,11,128,156,239,0,91,214,76,114,145,23,25,12,166,179,57,56,75,46,180,48,191,20,219,249,28,233,12,190,60,91,253,63,125,
    38,94,245,114,67,104,90,22,94,97,7,81,232,200,32,1,11,65,109,175,111,255,250,57,205,81,159,111,9,2,217,30,170,125,56,122,155,247,58,161,246,171,224,133,134,128,181,252,37,144,234,117,219,22,83,195,182,
    234,196,206,83,248,75,68,107,196,246,235,136,132,81,43,68,119,181,129,36,99,225,243,246,138,117,247,183,194,184,205,233,216,197,181,222,192,212,153,195,221,226,69,50,119,159,85,175,164,2,103,217,135,159,
    127,184,51,38,112,76,172,29,248,110,61,219,227,141,182,62,8,189,120,3,231,42,170,177,143,139,253,58,249,128,134,245,245,60,23,245,31,219,167,41,243,184,211,142,238,158,241,51,248,156,231,62,146,207,13,
    253,194,48,189,180,2,81,204,62,130,181,27,12,164,110,183,131,63,83,119,33,3,18,228,45,117,158,237,241,101,194,192,235,149,7,126,196,204,188,82,148,178,212,20,167,94,196,194,27,165,152,147,50,91,217,207,
    84,127,19,252,225,75,69,171,191,110,23,243,227,162,240,86,121,53,250,50,248,90,213,179,248,210,149,76,168,127,6,142,150,247,237,63,221,202,255,91,198,69,195,177,200,76,146,169,242,217,247,166,93,235,15,
    181,220,65,77,54,217,234,213,124,29,91,55,65,89,88,182,90,20,63,212,17,255,26,29,133,99,15,165,136,67,76,207,71,8,76,1,89,175,55,23,187,103,168,63,6,179,117,115,255,240,40,62,225,98,189,115,240,5,229,
    39,159,149,98,21,185,192,168,184,238,88,211,125,135,232,207,221,116,140,132,114,61,65,157,49,160,19,62,254,125,20,190,140,217,41,54,114,103,157,150,243,116,10,196,136,118,190,136,218,114,28,71,57,199,
    218,228,218,148,58,191,98,157,208,245,14,197,28,246,252,27,6,238,21,41,178,223,150,173,34,137,151,33,144,182,67,12,120,184,160,28,218,21,95,99,53,3,236,93,158,151,50,128,38,178,37,253,119,228,78,17,75,
    187,169,23,110,96,45,115,188,204,60,53,129,109,251,196,69,70,156,96,167,177,105,64,103,140,13,222,35,12,124,182,47,228,139,174,206,129,24,157,122,1,137,139,198,40,211,76,171,196,216,62,33,88,196,142,96,
    65,110,9,158,142,221,38,142,48,64,243,88,26,61,248,140,145,29,252,49,136,89,196,127,205,17,236,34,55,121,151,190,93,192,111,64,234,148,69,182,59,221,3,189,240,71,182,92,131,228,95,215,200,87,172,178,94,
    115,199,93,191,144,135,52,130,187,135,106,187,185,51,110,50,96,238,162,168,14,126,152,203,90,62,132,132,169,252,216,37,60,181,99,154,146,250,216,82,17,21,228,139,89,100,216,195,153,50,13,52,36,114,74,
    112,145,59,125,31,153,252,70,146,169,111,147,158,87,110,242,4,234,199,50,208,158,13,246,195,35,62,238,8,226,125,109,53,83,54,193,203,166,237,99,87,139,144,68,0,246,49,51,228,90,244,59,145,40,74,187,143,
    49,181,235,142,92,64,156,191,39,220,121,109,9,125,120,153,233,57,201,238,217,244,254,122,188,68,208,199,243,217,100,9,170,102,16,157,97,202,95,198,103,92,79,95,170,88,102,194,120,111,28,137,232,227,212,
    13,119,211,193,77,190,116,162,191,55,88,242,78,50,67,236,97,7,147,68,178,124,177,190,69,85,251,14,175,34,201,76,197,195,108,198,200,93,125,59,127,15,120,203,216,70,218,117,28,0,86,33,27,55,48,159,182,
    230,93,15,81,75,230,138,184,19,114,184,248,170,252,128,139,235,194,133,9,83,20,120,113,167,255,196,197,204,179,153,75,126,101,244,151,11,73,99,5,172,171,217,108,247,28,178,104,234,7,202,183,117,180,237,
    46,106,107,118,1,109,231,210,118,169,138,93,133,118,67,104,215,151,118,47,83,63,151,96,118,100,22,184,97,235,131,221,252,242,203,101,107,233,15,3,42,143,254,92,221,249,188,82,135,75,48,16,188,57,79,27,
    206,171,183,16,203,98,206,153,203,192,111,210,151,50,78,113,138,83,156,226,20,167,56,197,41,78,113,202,61,145,255,1,118,131,206,202,76,146,94,5,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LivePanelComponent::smallLogo_png = (const char*) 
resource_LivePanelComponent_smallLogo_png;
const int LivePanelComponent::smallLogo_pngSize = 3433;


