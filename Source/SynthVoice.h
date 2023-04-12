/*
  ==============================================================================

    SynthVoice.h
    Created: 15 Mar 2023 3:09:00pm
    Author:  aerdn

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"
#include "ADSRData.h"
#include "OSCData.h"
#include "stdlib.h"

class SynthVoice : public juce::SynthesiserVoice {
public:
    bool canPlaySound(juce::SynthesiserSound* sound) override;
    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheerPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    void pitchWheelMoved(int newPitchWheelValue) override;
    void controllerMoved(int controllerNumber, int newControllerValue) override;
    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);
    void renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;

    OSCData& getOSC1() { return osc1; }
    OSCData& getOSC2() { return osc2; }
    ADSRData& getADSR() { return adsr; }


private:
    bool isPrepared{ false };

    OSCData osc1;
    OSCData osc2;
    ADSRData adsr;

    juce::dsp::Gain<float> gain;

    juce::AudioBuffer<float> synthBuffer;


    // return std::sin(x); // Sine Wave
    // return x / juce::MathConstants<float>::pi; // Saw Wave
    // return x < 0.0f ? -1.0f : 1.0f; // Square Wave
    // return x; // Triangle Wave
    // return static_cast<double>(rand(x)) / RAND_MAX; // Noise
};
