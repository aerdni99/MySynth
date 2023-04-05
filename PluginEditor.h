/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "ADSRComponent.h"
#include "OscComponent.h"

//==============================================================================
/**
*/
class MySynthAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    MySynthAudioProcessorEditor (MySynthAudioProcessor&);
    ~MySynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:

    MySynthAudioProcessor& audioProcessor;
    ADSRComponent adsr;
    OSCComponent osc1;
    OSCComponent osc2;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MySynthAudioProcessorEditor)
};
