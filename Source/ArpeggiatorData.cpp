/*
  ==============================================================================

    ArpeggiatorData.cpp
    Created: 5 Apr 2023 1:17:42am
    Author:  aerdn

  ==============================================================================
*/

#include "ArpeggiatorData.h"

ArpeggiatorData::ArpeggiatorData() : notes() {
    currentNote = 0;
    lastNote = -1;
    time = 0;
    notes.clear();
    rate = 0;
}

ArpeggiatorData::~ArpeggiatorData() {
}

void ArpeggiatorData::setSampleRate(double sampleRate) {
    rate = static_cast<float>(sampleRate);
}

void ArpeggiatorData::clearNotes() {
    notes.clear();
}

float ArpeggiatorData::getRate() {
    return rate;
}

void ArpeggiatorData::handleMidi(juce::MidiBuffer& midiMessages, float arpBPM, int numSamples) {
    auto noteDuration = static_cast<int>(std::ceil(rate * 0.25f * (0.1f + (1.0f - arpBPM))));
    for (const auto metaData : midiMessages) {
        auto msg = metaData.getMessage();
        if (msg.isNoteOn()) {
            notes.add(msg.getNoteNumber());
        }
        else if (msg.isNoteOff()) {
            notes.removeValue(msg.getNoteNumber());
        }
    }
    midiMessages.clear();
    if (time + numSamples >= noteDuration) {
        auto offset = juce::jmax(0, juce::jmin((int)(noteDuration - time), numSamples - 1));
        if (lastNote > 0) {
            midiMessages.addEvent(juce::MidiMessage::noteOff(1, lastNote), offset);
            lastNote = -1;
        }
        if (notes.size() > 0) {
            currentNote = (currentNote + 1) % notes.size();
            lastNote = notes[currentNote];
            midiMessages.addEvent(juce::MidiMessage::noteOn(1, lastNote, (juce::uint8)127), offset);
        }
    }
    time = (time + numSamples) % noteDuration;
}

