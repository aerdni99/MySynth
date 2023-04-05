/*
  ==============================================================================

    OscData.h
    Created: 20 Mar 2023 3:55:33pm
    Author:  aerdn

  ==============================================================================
*/

#pragma once

#include <juceHeader.h>

class OSCData : public juce::dsp::Oscillator<float> {
public:
    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);
    void setType(const int oscSelection);
    void setGain(const float levelInDecibels);
    void setPitchVal(const int pitch);
    void setFreq(const int midiNoteNumber);
    void renderNextBlock(juce::dsp::AudioBlock<float>& audioBlock);
private:
    juce::dsp::Gain<float> gain;
    int pitchVal { 0 };
    int lastMidiNote { 0 };
};

// return std::sin(x); // Sine Wave
// return x / juce::MathConstants<float>::pi; // Saw Wave
// return x < 0.0f ? -1.0f : 1.0f; // Square Wave
// return x; // Triangle Wave
// return static_cast<double>(rand(x)) / RAND_MAX; // Noise
