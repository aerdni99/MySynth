/*
  ==============================================================================

    ADSRComponent.cpp
    Created: 19 Mar 2023 10:45:20pm
    Author:  aerdn

  ==============================================================================
*/

#include "ADSRComponent.h"
#include <JuceHeader.h>

ADSRComponent::ADSRComponent(juce::AudioProcessorValueTreeState& apvts) {
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

    attackAttachment = std::make_unique<SliderAttachment>(apvts, "ATTACK", attackSlider);
    decayAttachment = std::make_unique<SliderAttachment>(apvts, "DECAY", decaySlider);
    sustainAttachment = std::make_unique<SliderAttachment>(apvts, "SUSTAIN", sustainSlider);
    releaseAttachment = std::make_unique<SliderAttachment>(apvts, "RELEASE", releaseSlider);

    setSliderParams(attackSlider, attackLabel, "Attack");
    setSliderParams(decaySlider, decayLabel, "Decay");
    setSliderParams(sustainSlider, sustainLabel, "Sustain");
    setSliderParams(releaseSlider, releaseLabel, "Release");
}

ADSRComponent::~ADSRComponent() {

}

void ADSRComponent::paint(juce::Graphics &g) {
    g.fillAll(juce::Colours::darkgrey);
}

void ADSRComponent::resized() {
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 10;
    const auto sliderWidth = bounds.getWidth() / 4 - padding;
    const auto sliderHeight = bounds.getHeight() - 4 * padding;
    const auto sliderStartX = 0;
    const auto sliderStartY = bounds.getHeight() / 3;

    attackSlider.setBounds(sliderStartX + padding, sliderStartY, sliderWidth, sliderHeight);
    decaySlider.setBounds(attackSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    sustainSlider.setBounds(decaySlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    releaseSlider.setBounds(sustainSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
}

void ADSRComponent::setSliderParams(juce::Slider& slider, juce::Label& label, std::string name) {
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    slider.setPopupDisplayEnabled(true, false, this);
    addAndMakeVisible(slider);

    addAndMakeVisible(label);
    label.setText(name, juce::dontSendNotification);
    label.attachToComponent(&slider, false);
    label.setJustificationType(juce::Justification(4));
    return;
}