/*
  ==============================================================================

    OscComponent.h
    Created: 20 Mar 2023 3:55:42pm
    Author:  aerdn

  ==============================================================================
*/

#pragma once

#include <juceHeader.h>

class OSCComponent: public juce::Component {
public:
    OSCComponent(juce::AudioProcessorValueTreeState& apvts, juce::String oscID,juce::String gainID,juce::String pitchID);
    ~OSCComponent() override;

    void paint(juce::Graphics &g) override;
    void resized() override;
private:
    juce::ComboBox oscSelector;
    juce::Slider gainSlider;
    juce::Slider pitchSlider;

    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscSelAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> pitchAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OSCComponent)
};
