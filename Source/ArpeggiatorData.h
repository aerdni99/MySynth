/*
  ==============================================================================

    ArpeggiatorData.h
    Created: 5 Apr 2023 1:17:42am
    Author:  aerdn

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class ArpeggiatorData {
  public:
      ArpeggiatorData();
      ~ArpeggiatorData();
      void setSampleRate(double sampleRate);
      void clearNotes();
      float getRate();

      // Intercepts incoming Midi messages of type noteOn or noteOff and records the notes that are held down currently.
      void handleMidi(juce::MidiBuffer& midiMessages, float arpBPM, int numSamples, int arpSel);

  private:
      int currentNote, lastNote, time;
      float rate; 
      juce::SortedSet<int> notes;
};
