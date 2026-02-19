/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.12

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
WaveshaperAudioProcessorEditor::WaveshaperAudioProcessorEditor (WaveshaperAudioProcessor* ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    gainLabel.reset (new juce::Label ("Gain Label",
                                      TRANS ("Gain [db]")));
    addAndMakeVisible (gainLabel.get());
    gainLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    gainLabel->setJustificationType (juce::Justification::centredLeft);
    gainLabel->setEditable (false, false, false);
    gainLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    gainLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    gainLabel->setBounds (16, 16, 78, 24);

    gainSlider.reset (new juce::Slider ("Gain Slider"));
    addAndMakeVisible (gainSlider.get());
    gainSlider->setRange (-70, 0, 0.1);
    gainSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    gainSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 20);
    gainSlider->setColour (juce::Slider::backgroundColourId, juce::Colours::white);
    gainSlider->setColour (juce::Slider::thumbColourId, juce::Colours::black);
    gainSlider->setColour (juce::Slider::trackColourId, juce::Colours::white);
    gainSlider->setColour (juce::Slider::textBoxHighlightColourId, juce::Colour (0x66ffffff));
    gainSlider->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0xfffafafa));
    gainSlider->addListener (this);

    gainSlider->setBounds (96, 16, 214, 24);

    kposLabel.reset (new juce::Label ("Kpos Label",
                                      TRANS ("K positive")));
    addAndMakeVisible (kposLabel.get());
    kposLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    kposLabel->setJustificationType (juce::Justification::centredLeft);
    kposLabel->setEditable (false, false, false);
    kposLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    kposLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    kposLabel->setBounds (16, 48, 78, 24);

    kposSlider.reset (new juce::Slider ("Kpos Slider"));
    addAndMakeVisible (kposSlider.get());
    kposSlider->setRange (1, 20, 1);
    kposSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    kposSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 20);
    kposSlider->setColour (juce::Slider::backgroundColourId, juce::Colours::white);
    kposSlider->setColour (juce::Slider::thumbColourId, juce::Colours::black);
    kposSlider->setColour (juce::Slider::trackColourId, juce::Colours::white);
    kposSlider->setColour (juce::Slider::textBoxOutlineColourId, juce::Colours::white);
    kposSlider->addListener (this);

    kposSlider->setBounds (96, 48, 214, 24);

    knegLabel.reset (new juce::Label ("Kneg Label",
                                      TRANS ("K negative")));
    addAndMakeVisible (knegLabel.get());
    knegLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    knegLabel->setJustificationType (juce::Justification::centredLeft);
    knegLabel->setEditable (false, false, false);
    knegLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    knegLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    knegLabel->setBounds (16, 80, 78, 24);

    knegSlider.reset (new juce::Slider ("Kneg Slider"));
    addAndMakeVisible (knegSlider.get());
    knegSlider->setRange (1, 20, 1);
    knegSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    knegSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 20);
    knegSlider->setColour (juce::Slider::backgroundColourId, juce::Colours::white);
    knegSlider->setColour (juce::Slider::thumbColourId, juce::Colours::black);
    knegSlider->setColour (juce::Slider::trackColourId, juce::Colours::white);
    knegSlider->setColour (juce::Slider::textBoxOutlineColourId, juce::Colours::white);
    knegSlider->addListener (this);

    knegSlider->setBounds (96, 80, 214, 24);

    cascadeLabel.reset (new juce::Label ("Cascade Label",
                                         TRANS ("Cascades")));
    addAndMakeVisible (cascadeLabel.get());
    cascadeLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    cascadeLabel->setJustificationType (juce::Justification::centredLeft);
    cascadeLabel->setEditable (false, false, false);
    cascadeLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    cascadeLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    cascadeLabel->setBounds (16, 112, 70, 24);

    cascadeSlider.reset (new juce::Slider ("Cascade Slider"));
    addAndMakeVisible (cascadeSlider.get());
    cascadeSlider->setRange (1, 10, 1);
    cascadeSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    cascadeSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 20);
    cascadeSlider->setColour (juce::Slider::backgroundColourId, juce::Colours::white);
    cascadeSlider->setColour (juce::Slider::thumbColourId, juce::Colours::black);
    cascadeSlider->setColour (juce::Slider::textBoxOutlineColourId, juce::Colours::white);
    cascadeSlider->addListener (this);

    cascadeSlider->setBounds (96, 112, 214, 24);

    invertLabel.reset (new juce::Label ("Invert Label",
                                        TRANS ("Invert Output")));
    addAndMakeVisible (invertLabel.get());
    invertLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    invertLabel->setJustificationType (juce::Justification::centredLeft);
    invertLabel->setEditable (false, false, false);
    invertLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    invertLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    invertLabel->setBounds (16, 144, 102, 24);

    invertButton.reset (new juce::ToggleButton ("Invert Button"));
    addAndMakeVisible (invertButton.get());
    invertButton->setButtonText (juce::String());
    invertButton->addListener (this);
    invertButton->setColour (juce::ToggleButton::textColourId, juce::Colours::white);

    invertButton->setBounds (104, 144, 46, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 200);


    //[Constructor] You can add your own custom stuff here..
    WaveshaperAudioProcessor* ourProcessor = getProcessor();

    float gainLevel = ourProcessor->getParameter(WaveshaperAudioProcessor::gain);
    if (gainLevel > 0.0f) {
        float dbValue = 20.f * log10(gainLevel);
        gainSlider->setValue(dbValue, juce::dontSendNotification);
    }
    else
        gainSlider->setValue(-70.0f, juce::dontSendNotification);

    kposSlider->setValue(ourProcessor->getParameter(WaveshaperAudioProcessor::kpos), juce::dontSendNotification);

    knegSlider->setValue(ourProcessor->getParameter(WaveshaperAudioProcessor::kneg), juce::dontSendNotification);

    cascadeSlider->setValue(ourProcessor->getParameter(WaveshaperAudioProcessor::cascade), juce::dontSendNotification);

    invertButton->setToggleState((bool)ourProcessor->getParameter(WaveshaperAudioProcessor::invert), juce::dontSendNotification);

    getProcessor()->RequestUIUpdate();
    startTimer(200);
    //[/Constructor]
}

WaveshaperAudioProcessorEditor::~WaveshaperAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    gainLabel = nullptr;
    gainSlider = nullptr;
    kposLabel = nullptr;
    kposSlider = nullptr;
    knegLabel = nullptr;
    knegSlider = nullptr;
    cascadeLabel = nullptr;
    cascadeSlider = nullptr;
    invertLabel = nullptr;
    invertButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void WaveshaperAudioProcessorEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xffb2501f));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void WaveshaperAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void WaveshaperAudioProcessorEditor::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    WaveshaperAudioProcessor* ourProcessor = getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == gainSlider.get())
    {
        //[UserSliderCode_gainSlider] -- add your slider handling code here..
        float val = std::pow(10.0f, (float)gainSlider->getValue() / 20.0f);
        ourProcessor->setParameter(WaveshaperAudioProcessor::gain, val);
        //[/UserSliderCode_gainSlider]
    }
    else if (sliderThatWasMoved == kposSlider.get())
    {
        //[UserSliderCode_kposSlider] -- add your slider handling code here..
        ourProcessor->setParameter(WaveshaperAudioProcessor::kpos, (float)kposSlider->getValue());
        //[/UserSliderCode_kposSlider]
    }
    else if (sliderThatWasMoved == knegSlider.get())
    {
        //[UserSliderCode_knegSlider] -- add your slider handling code here..
        ourProcessor->setParameter(WaveshaperAudioProcessor::kneg, (float)knegSlider->getValue());
        //[/UserSliderCode_knegSlider]
    }
    else if (sliderThatWasMoved == cascadeSlider.get())
    {
        //[UserSliderCode_cascadeSlider] -- add your slider handling code here..
        ourProcessor->setParameter(WaveshaperAudioProcessor::cascade, (float)cascadeSlider->getValue());
        //[/UserSliderCode_cascadeSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void WaveshaperAudioProcessorEditor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    WaveshaperAudioProcessor* ourProcessor = getProcessor();
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == invertButton.get())
    {
        //[UserButtonCode_invertButton] -- add your button handler code here..
        float val = invertButton->getToggleState() ? 1.0f : 0.0f;
        ourProcessor->setParameter(WaveshaperAudioProcessor::invert, val);
        //[/UserButtonCode_invertButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void WaveshaperAudioProcessorEditor::timerCallback(){
    WaveshaperAudioProcessor* ourProcessor = getProcessor();

    if (ourProcessor->NeedsUIUpdate())
    {
        float gainLevel = ourProcessor->getParameter(WaveshaperAudioProcessor::gain);
        if (gainLevel > 0.0f) {
            float dbValue = 20.f * log10(gainLevel);
            gainSlider->setValue(dbValue, juce::dontSendNotification);
        }
        else
            gainSlider->setValue(-70.0f, juce::dontSendNotification);

        kposSlider->setValue(ourProcessor->getParameter(WaveshaperAudioProcessor::kpos), juce::dontSendNotification);

        knegSlider->setValue(ourProcessor->getParameter(WaveshaperAudioProcessor::kneg), juce::dontSendNotification);

        cascadeSlider->setValue(ourProcessor->getParameter(WaveshaperAudioProcessor::cascade), juce::dontSendNotification);

        bool invertState = (bool)ourProcessor->getParameter(WaveshaperAudioProcessor::invert);
        if (invertButton->getToggleState() != invertState)
            invertButton->setToggleState(invertState, juce::dontSendNotification);

        ourProcessor->ClearUIUpdateFlag();
    }

}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="WaveshaperAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="WaveshaperAudioProcessor* ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="400" initialHeight="200">
  <BACKGROUND backgroundColour="ffb2501f"/>
  <LABEL name="Gain Label" id="cac3e639c3f4c358" memberName="gainLabel"
         virtualName="" explicitFocusOrder="0" pos="16 16 78 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Gain [db]" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="Gain Slider" id="16d9798e68f9a486" memberName="gainSlider"
          virtualName="" explicitFocusOrder="0" pos="96 16 214 24" bkgcol="ffffffff"
          thumbcol="ff000000" trackcol="ffffffff" textboxhighlight="66ffffff"
          textboxoutline="fffafafa" min="-70.0" max="0.0" int="0.1" style="LinearHorizontal"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="Kpos Label" id="bd4fbd938d8689af" memberName="kposLabel"
         virtualName="" explicitFocusOrder="0" pos="16 48 78 24" edTextCol="ff000000"
         edBkgCol="0" labelText="K positive" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="Kpos Slider" id="fae9db6422add8e8" memberName="kposSlider"
          virtualName="" explicitFocusOrder="0" pos="96 48 214 24" bkgcol="ffffffff"
          thumbcol="ff000000" trackcol="ffffffff" textboxoutline="ffffffff"
          min="1.0" max="20.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="Kneg Label" id="65e388ddf6df6c7b" memberName="knegLabel"
         virtualName="" explicitFocusOrder="0" pos="16 80 78 24" edTextCol="ff000000"
         edBkgCol="0" labelText="K negative" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="Kneg Slider" id="7ed8ea80b3c698fc" memberName="knegSlider"
          virtualName="" explicitFocusOrder="0" pos="96 80 214 24" bkgcol="ffffffff"
          thumbcol="ff000000" trackcol="ffffffff" textboxoutline="ffffffff"
          min="1.0" max="20.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="Cascade Label" id="2c302f9b75ba009a" memberName="cascadeLabel"
         virtualName="" explicitFocusOrder="0" pos="16 112 70 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Cascades" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="Cascade Slider" id="af3e4caab804c7b6" memberName="cascadeSlider"
          virtualName="" explicitFocusOrder="0" pos="96 112 214 24" bkgcol="ffffffff"
          thumbcol="ff000000" textboxoutline="ffffffff" min="1.0" max="10.0"
          int="1.0" style="LinearHorizontal" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="Invert Label" id="121277f905b5feb9" memberName="invertLabel"
         virtualName="" explicitFocusOrder="0" pos="16 144 102 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Invert Output" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="Invert Button" id="9d6a4c8d6c1c5522" memberName="invertButton"
                virtualName="" explicitFocusOrder="0" pos="104 144 46 24" txtcol="ffffffff"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

