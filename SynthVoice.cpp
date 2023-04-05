/*
  ==============================================================================

    SynthVoice.cpp
    Created: 15 Mar 2023 3:09:00pm
    Author:  aerdn

  ==============================================================================
*/

#include "SynthVoice.h"

bool SynthVoice::canPlaySound(juce::SynthesiserSound* sound) {
    return dynamic_cast<juce::SynthesiserSound*>(sound) != nullptr;
}
void SynthVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheerPosition) {
    osc1.setFreq(midiNoteNumber);
    osc2.setFreq(midiNoteNumber);
    adsr.noteOn();
    DBG("Midi Note Number: " + midiNoteNumber);
}
void SynthVoice::stopNote(float velocity, bool allowTailOff) {
    adsr.noteOff();

    if (!allowTailOff || !adsr.isActive())
        clearCurrentNote();
}
void SynthVoice::pitchWheelMoved(int newPitchWheelValue) {

}
void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue) {

}
void SynthVoice::prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels) {
    
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = outputChannels;

    adsr.setSampleRate(sampleRate);

    osc1.prepareToPlay(sampleRate, samplesPerBlock, outputChannels);
    osc2.prepareToPlay(sampleRate, samplesPerBlock, outputChannels);

    gain.prepare(spec);
    gain.setGainLinear(0.07f);

    isPrepared = true;
}
void SynthVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) {
    jassert(isPrepared);

    if (!isVoiceActive())
        return;

    synthBuffer.setSize(outputBuffer.getNumChannels(), numSamples, false, false, true);
    synthBuffer.clear();

    juce::dsp::AudioBlock<float> audioBlock{ synthBuffer };

    osc1.renderNextBlock(audioBlock);
    osc2.renderNextBlock(audioBlock);

    gain.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));

    adsr.applyEnvelopeToBuffer(synthBuffer, 0, synthBuffer.getNumSamples());

    for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
    {
        outputBuffer.addFrom(channel, startSample, synthBuffer, channel, 0, numSamples);

        if (!adsr.isActive())
            clearCurrentNote();
    }

}