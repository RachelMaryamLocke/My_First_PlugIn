/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class PlugIn2AudioProcessorEditor  : public juce::AudioProcessorEditor,
                                     public juce::Slider::Listener
{
public:
    PlugIn2AudioProcessorEditor (PlugIn2AudioProcessor&);
    ~PlugIn2AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider* slider) override;

private:
    
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PlugIn2AudioProcessor& audioProcessor;
    juce::Slider mGainControlSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlugIn2AudioProcessorEditor)
};
