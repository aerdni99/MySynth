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
    // bpmAttachment = std::make_unique<SliderAttachment>(apvts, ...);

    // Style the components
    bpmSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    bpmSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    bpmSlider.setPopupDisplayEnabled(true, false, this);
    addAndMakeVisible(bpmSlider);

    addAndMakeVisible(bpmLabel);
    bpmLabel.setText("BPM", juce::dontSendNotification);
    bpmLabel.attachToComponent(&bpmSlider, false);
    bpmLabel.setJustificationType(juce::Justification(4));

    powerButton.setButtonText("Arpeggiator");
    addAndMakeVisible(powerButton);
}

void ArpeggiatorComponent::resized() {
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 10;
    const auto width = bounds.getWidth() / 2 - padding;
    const auto height = bounds.getHeight() - 4 * padding;
    const auto startX = 0;
    const auto startY = bounds.getHeight() / 3;

    powerButton.setBounds(startX + padding, startY, width, height);
    bpmSlider.setBounds(powerButton.getRight() + padding, startY, width, height);
}

void ArpeggiatorComponent::paint(juce::Graphics &g) {
    g.fillAll(juce::Colours::darkgrey);
}
