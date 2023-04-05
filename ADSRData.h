/*
  ==============================================================================

    ADSR.h
    Created: 19 Mar 2023 10:39:23pm
    Author:  aerdn

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class ADSRData : public juce::ADSR
{
public:
    void update(const float attack, const float decay, const float sustain, const float release);

private:
    juce::ADSR::Parameters adsrParams;
};
