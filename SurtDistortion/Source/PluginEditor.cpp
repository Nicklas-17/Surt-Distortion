/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
 

//==============================================================================
SurtDistortionAudioProcessorEditor::SurtDistortionAudioProcessorEditor (SurtDistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 200);
    
     Driveknob = std::make_unique<juce::Slider> ();
     RangeKnob = std::make_unique<juce::Slider> ();
     BlendKnob = std::make_unique<juce::Slider> ();
     VolKnob   = std::make_unique<juce::Slider>  ();
    
    addAndMakeVisible(*Driveknob);
    Driveknob->juce::Slider::setSliderStyle(juce::Slider::RotaryHorizontalDrag);
    Driveknob->setTextBoxStyle(juce::Slider::NoTextBox, false, 100, 100);
    
    addAndMakeVisible(*RangeKnob);
    RangeKnob->juce::Slider::setSliderStyle(juce::Slider::RotaryHorizontalDrag);
    RangeKnob->setTextBoxStyle(juce::Slider::NoTextBox, false, 100, 100);
    
    addAndMakeVisible(*BlendKnob);
    BlendKnob->juce::Slider::setSliderStyle(juce::Slider::RotaryHorizontalDrag);
    BlendKnob->setTextBoxStyle(juce::Slider::NoTextBox, false, 100, 100);
    
    
    addAndMakeVisible(*VolKnob);
    VolKnob->juce::Slider::setSliderStyle(juce::Slider::RotaryHorizontalDrag);
    VolKnob->setTextBoxStyle(juce::Slider::NoTextBox, false, 100, 100);
    
    

   

    // create the actual Slider attachment
    
    driveAttachment = std::make_unique <juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts,"DRIVE" ,*Driveknob);
    rangeAttachment = std::make_unique <juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts,"RANGE" ,*RangeKnob);
    BlendAttachment = std::make_unique <juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts,"BLEND" ,*BlendKnob);
    VolAttachment   = std::make_unique <juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts,"Vol" ,*VolKnob);
}

SurtDistortionAudioProcessorEditor::~SurtDistortionAudioProcessorEditor()
{
}

//==============================================================================
void SurtDistortionAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

  

    
    
}

void SurtDistortionAudioProcessorEditor::resized()
{
    juce::Rectangle<int> Bounds = getLocalBounds();
    
    juce::FlexBox flexbox;
    
    flexbox.flexDirection = juce::FlexBox::Direction::row;
    // This means that whenever you access the flexWrap property, it will return the value wrap
    flexbox.flexWrap = juce::FlexBox::Wrap::wrap;
    flexbox.alignContent = juce::FlexBox::AlignContent::stretch;
    
    juce::Array<juce::FlexItem> items;
   items.add(juce::FlexItem(50, 10, *RangeKnob));
    items.add(juce::FlexItem(50, 10, *RangeKnob));
    items.add(juce::FlexItem(50, 10, *BlendKnob));
    items.add(juce::FlexItem(50, 10, *VolKnob));
    
    flexbox.items = items;
    
    flexbox.performLayout(Bounds);
    
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
