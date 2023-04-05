/*
  ==============================================================================

    ArpeggiatorComponent.cpp
    Created: 5 Apr 2023 1:19:29am
    Author:  aerdn

  ==============================================================================
*/

#include "ArpeggiatorComponent.h"

ArpeggiatorComponent::ArpeggiatorComponent(juce::AudioProcessorValueTreeState& apvts) {
    // Associate the values from the apvts with the UI!
    bpmAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "ARP_BPM", bpmSlider);
    powerAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(apvts, "ARP_TOGGLE", powerButton);

    // Style the components
    bpmSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    bpmSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    bpmSlider.setPopupDisplayEnabled(true, false, this);
    addAndMakeVisible(bpmSlider);

    addAndMakeVisible(bpmLabel);
    bpmLabel.setText("BPM", juce::dontSendNotification);
    bpmLabel.attachToComponent(&bpmSlider, false);
    bpmLabel.setJustificationType(juce::Justification(4));

    addAndMakeVisible(powerButton);
    powerButton.setButtonText("");
    addAndMakeVisible(powerLabel);
    powerLabel.setText("ARP", juce::dontSendNotification);
    powerLabel.attachToComponent(&powerButton, false);
    powerLabel.setJustificationType(juce::Justification(4));

}

ArpeggiatorComponent::~ArpeggiatorComponent() {
}

void ArpeggiatorComponent::resized() {
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 5;
    const auto width = bounds.getWidth();
    const auto height = bounds.getHeight();

    powerButton.setBounds(width / 4, height / 4, width / 2 - 2 * padding, height / 2);
    bpmSlider.setBounds(width / 2 + padding, height / 4, width / 2 - 2 * padding, height / 2);
    powerButton.setColour(0, juce::Colours::white);
}

void ArpeggiatorComponent::paint(juce::Graphics &g) {
    g.fillAll(juce::Colours::darkgrey);
}
