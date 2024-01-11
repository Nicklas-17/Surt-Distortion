/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include <memory>

//==============================================================================
/**
*/
class SurtDistortionAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SurtDistortionAudioProcessorEditor (SurtDistortionAudioProcessor&);
    ~SurtDistortionAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    // creation of Address for Sliders and creation of slider Objects
    
    std::unique_ptr<juce::Slider> Driveknob = std::make_unique<juce::Slider> ();
    std::unique_ptr<juce::Slider> RangeKnob = std::make_unique<juce::Slider> ();
    std::unique_ptr<juce::Slider> BlendKnob = std::make_unique<juce::Slider> ();
    std::unique_ptr<juce::Slider> VolKnob   = std::make_unique<juce::Slider>  ();
    
    // creation of pointers of slider attachements to ValueTreeState
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> driveAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> rangeAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> BlendAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> VolAttachment;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SurtDistortionAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SurtDistortionAudioProcessorEditor)
};
