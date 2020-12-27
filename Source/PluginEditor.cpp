/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PlugIn2AudioProcessorEditor::PlugIn2AudioProcessorEditor (PlugIn2AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    mGainControlSlider.setBounds(0, 0, 100, 100);
    addAndMakeVisible(mGainControlSlider);
    mGainControlSlider.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    mGainControlSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    mGainControlSlider.addListener(this);
    
}

PlugIn2AudioProcessorEditor::~PlugIn2AudioProcessorEditor()
{
}

//==============================================================================
void PlugIn2AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello!", getLocalBounds(), juce::Justification::centred, 1);
}

void PlugIn2AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void PlugIn2AudioProcessorEditor::sliderValueChanged(juce::Slider* slider){
    DBG("SLIDER VALUE CHANGED");
}
