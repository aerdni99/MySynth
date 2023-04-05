/*
  ==============================================================================

    ADSRComponent.h
    Created: 19 Mar 2023 10:45:20pm
    Author:  aerdn

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class ADSRComponent : public juce::Component {
public:
    ADSRComponent(juce::AudioProcessorValueTreeState& apvts);
    ~ADSRComponent() override;

    void paint(juce::Graphics& g) override;
    void resized() override;

private:
    void setSliderParams(juce::Slider& slider, juce::Label& label, std::string name);

    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;

    juce::Label attackLabel;
    juce::Label decayLabel;
    juce::Label sustainLabel;
    juce::Label releaseLabel;

    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

    std::unique_ptr<SliderAttachment> attackAttachment;
    std::unique_ptr<SliderAttachment> decayAttachment;
    std::unique_ptr<SliderAttachment> sustainAttachment;
    std::unique_ptr<SliderAttachment> releaseAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ADSRComponent)
};