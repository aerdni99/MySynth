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
