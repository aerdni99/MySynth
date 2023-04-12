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
    typeSelectorAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, "ARP_SEL", typeSelector);

    // This defines the contents of our combobox selector
    juce::StringArray choices{ "Off", "Repeat" };
    typeSelector.addItemList(choices, 1);
    typeSelector.setSelectedItemIndex(0);
    addAndMakeVisible(typeSelector);

    // Style the components
    bpmSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    bpmSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    bpmSlider.setPopupDisplayEnabled(true, false, this);
    addAndMakeVisible(bpmSlider);
    addAndMakeVisible(bpmLabel);
    bpmLabel.setText("BPM", juce::dontSendNotification);
    bpmLabel.attachToComponent(&bpmSlider, false);
    bpmLabel.setJustificationType(juce::Justification(4));

    addAndMakeVisible(typeSelector);
    addAndMakeVisible(typeLabel);
    typeLabel.setText("ARP", juce::dontSendNotification);
    typeLabel.attachToComponent(&typeSelector, false);
    typeLabel.setJustificationType(juce::Justification(4));

}

ArpeggiatorComponent::~ArpeggiatorComponent() {
}

void ArpeggiatorComponent::resized() {
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 5;
    const auto width = bounds.getWidth();
    const auto height = bounds.getHeight();

    typeSelector.setBounds(width / 4, height / 4, width / 2 - 2 * padding, height / 2);
    bpmSlider.setBounds(width / 2 + padding, height / 4, width / 2 - 2 * padding, height / 2);
}

void ArpeggiatorComponent::paint(juce::Graphics &g) {
    g.fillAll(juce::Colours::darkgrey);
}
