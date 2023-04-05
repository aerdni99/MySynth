/*
  ==============================================================================

    ArpeggiatorComponent.h
    Created: 5 Apr 2023 1:19:29am
    Author:  aerdn

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class ArpeggiatorComponent : public juce::Component {
  public:
    ArpeggiatorComponent(juce::AudioProcessorValueTreeState& apvts);
    ~ArpeggiatorComponent() override;

    void paint(juce::Graphics& g) override;
    void resized() override;
  private:
    /*
    I want to be able to control...
    bpm, toggle on/off.

    for now, default order will be ascending.
    */

    juce::Slider bpmSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> bpmAttachment;
    juce::Label bpmLabel;

    juce::ToggleButton powerButton;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> powerAttachment;
    juce::Label powerLabel;
};

/*
Idea for a unique component:

An AI repeater. Functionally, you would be able to press a button to have the computer listen for a pattern you play
and then try to figure out the pattern you were trying to play along to.
So if you played any rhythm, the computer would try and make a quantized pattern based on {what you played, set bpm, time signature}

Like an AI sequencer.
*/
