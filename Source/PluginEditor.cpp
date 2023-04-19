/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MySynthAudioProcessorEditor::MySynthAudioProcessorEditor (MySynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), adsr(audioProcessor.apvts), osc1(audioProcessor.apvts, "OSC1", "OSC1GAIN", "OSC1PITCH"), osc2(audioProcessor.apvts, "OSC2", "OSC2GAIN", "OSC2PITCH"), arp(audioProcessor.apvts)
{
    setSize (800, 300);

    addAndMakeVisible(osc1);
    addAndMakeVisible(osc2);
    addAndMakeVisible(adsr);
    addAndMakeVisible(arp);
}

MySynthAudioProcessorEditor::~MySynthAudioProcessorEditor()
{
}

//==============================================================================
void MySynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void MySynthAudioProcessorEditor::resized()
{
    adsr.setBounds(10, getHeight() / 2 + 5, getWidth() - 220, getHeight() / 2 - 15);
    osc1.setBounds(10, 10, (getWidth() - 200) / 2 - 15, getHeight() / 2 - 15);
    osc2.setBounds((getWidth() - 200) / 2 + 5, 10, (getWidth() - 200) / 2 - 15, getHeight() / 2 - 15);
    arp.setBounds(605, 10, 180, getHeight() - 20);
}