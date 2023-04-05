/*
  ==============================================================================

    OscComponent.cpp
    Created: 20 Mar 2023 3:55:42pm
    Author:  aerdn

  ==============================================================================
*/

#include "OscComponent.h"
#include <juceHeader.h>

OSCComponent::OSCComponent(juce::AudioProcessorValueTreeState& apvts, juce::String oscID, juce::String gainID, juce::String pitchID) {
    juce::StringArray choices{ "Sine", "Square", "Triangle", "Sawtooth", "Noise" };
    oscSelector.addItemList(choices, 1);
    oscSelector.setSelectedItemIndex(0);
    addAndMakeVisible(oscSelector);

    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(gainSlider);

    pitchSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    pitchSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(pitchSlider);

    // These Three lines are very key to associating the GUI with the processor parameters
    oscSelAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, oscID, oscSelector);
    gainAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, gainID, gainSlider);
    pitchAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, pitchID, pitchSlider);
}

OSCComponent::~OSCComponent() {

}

void OSCComponent::paint(juce::Graphics &g) {
    g.fillAll(juce::Colours::darkgrey);
}

void OSCComponent::resized() {
    auto bounds = getLocalBounds();
    oscSelector.setBounds(bounds.removeFromLeft(getWidth() / 2));
    gainSlider.setBounds(bounds.removeFromLeft(getWidth() / 4));
    pitchSlider.setBounds(bounds);
}
