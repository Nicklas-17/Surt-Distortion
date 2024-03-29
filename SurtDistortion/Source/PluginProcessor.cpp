/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SurtDistortionAudioProcessor::SurtDistortionAudioProcessor() : juce::AudioProcessor(), apvts(*this, nullptr, "Parameters", createParameter()){}

/*#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ), apvts (*this, nullptr, "Parameters",);
 #endif
{
}
*/
SurtDistortionAudioProcessor::~SurtDistortionAudioProcessor()
{
}

//==============================================================================
const juce::String SurtDistortionAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SurtDistortionAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SurtDistortionAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SurtDistortionAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SurtDistortionAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SurtDistortionAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SurtDistortionAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SurtDistortionAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String SurtDistortionAudioProcessor::getProgramName (int index)
{
    return {};
}

void SurtDistortionAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void SurtDistortionAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void SurtDistortionAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SurtDistortionAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    // Check for supported mono or stereo output channel sets
    if (layouts.getMainOutputChannelSet() == juce::AudioChannelSet::mono() ||
        layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo()) {
        // Check for input/output matching
        return layouts.getMainInputChannelSet() == layouts.getMainOutputChannelSet();
    } else {
        // Unsupported layout
        return false;
    }
}

#endif

void SurtDistortionAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
}



//==============================================================================
bool SurtDistortionAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* SurtDistortionAudioProcessor::createEditor()
{
    return new SurtDistortionAudioProcessorEditor (*this);
}

//==============================================================================
void SurtDistortionAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SurtDistortionAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SurtDistortionAudioProcessor();
}

    juce::AudioProcessorValueTreeState::ParameterLayout SurtDistortionAudioProcessor::createParameter()

{
        std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;
        
        params.push_back(std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("DRIVE",1), "Drive", juce::NormalisableRange<float>(-10.0f,10.0f), 0.0f));
        
        
        return {params.begin(), params.end()} ;
 
}
 
