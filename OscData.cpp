/*
  ==============================================================================

    OscData.cpp
    Created: 20 Mar 2023 3:55:33pm
    Author:  aerdn

  ==============================================================================
*/

#include "OscData.h"

void OSCData::prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels) {
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = outputChannels;

    prepare(spec);
    gain.prepare(spec);

    gain.setGainLinear(0.3f);
}
void OSCData::setType(const int oscSelection) {
    switch (oscSelection) {
    case 0:
        // Sine Wave
        initialise([](float x) { return std::sin(x); });
        break;
    case 1:
        // Square Wave
        initialise([](float x) { return x < 0.0f ? -1.0f : 1.0f; });
        break;
    case 2:
        // Triangle Wave
        initialise([](float x) { return x; });
        break;
    case 3:
        // Sawtooth Wave
        initialise([](float x) { return x / juce::MathConstants<float>::pi; });
        break;
    case 4:
        // Noise
        initialise([](float x) { return static_cast<double>(rand()) / RAND_MAX; });
        break;
    default:
        // You shouldnt be here
        jassertfalse;
        break;
    }
}
void OSCData::setGain(const float levelInDecibels) {
    gain.setGainDecibels(levelInDecibels);
}
void OSCData::setPitchVal(const int pitch) {
    pitchVal = pitch;
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(lastMidiNote + pitchVal));
}
void OSCData::setFreq(const int midiNoteNumber) {
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber + pitchVal));
    lastMidiNote = midiNoteNumber;
}
void OSCData::renderNextBlock(juce::dsp::AudioBlock<float>& audioBlock) {
    jassert(audioBlock.getNumSamples() > 0);
    process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
    gain.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
}
