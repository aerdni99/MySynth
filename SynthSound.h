/*
  ==============================================================================

    SynthSound.h
    Created: 15 Mar 2023 3:09:06pm
    Author:  aerdn

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound {
public:
    bool appliesToNote(int midiNoteNumber) override { return true; }
    bool appliesToChannel(int midiChannel) override { return true; }
};
