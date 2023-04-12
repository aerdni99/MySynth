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

  private:
      juce::AudioParameterFloat* speed;
      int currentNote, lastNote, time;
      float rate; 
      juce::SortedSet<int> notes;
};
