/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WaveshaperAudioProcessor::WaveshaperAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    UserParams[gain] = 1.0f;
    UserParams[kpos] = 1.0f;
    UserParams[kneg] = 1.0f;
    UserParams[cascade] = 1.0f;
    UserParams[invert] = 0.0f;

    UIUpdateFlag = true;
}

WaveshaperAudioProcessor::~WaveshaperAudioProcessor()
{
}

//==============================================================================
const juce::String WaveshaperAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool WaveshaperAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool WaveshaperAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool WaveshaperAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double WaveshaperAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int WaveshaperAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int WaveshaperAudioProcessor::getCurrentProgram()
{
    return 0;
}

void WaveshaperAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String WaveshaperAudioProcessor::getProgramName (int index)
{
    return {};
}

void WaveshaperAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void WaveshaperAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void WaveshaperAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool WaveshaperAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

float WaveshaperAudioProcessor::calculateWaveshaper(float input, float k) {
    if (k <= 0.0f)
        k = 1.0f;  // evitam k=0 pt a nu imparti la 0

    return (1.0f / std::atan(k)) * std::atan(k * input);

}


void WaveshaperAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
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

    float Gain = UserParams[gain];
    float Kpos = UserParams[kpos];
    float Kneg = UserParams[kneg];
    int Cascade = juce::jlimit(1, 10, (int)UserParams[cascade]);
    int Invert = (int)UserParams[invert];
 
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

        for (int j = 0; j < buffer.getNumSamples(); j++)
        {
            float output = channelData[j];
            for (int c = 0; c < Cascade; c++) {
                float kreal = (output >= 0.0f) ? Kpos : Kneg;

                output = calculateWaveshaper(output, kreal);

                if (Invert)
                    output = -output;

            }

            channelData[j] = output * Gain;

        }

    }
}

//==============================================================================
bool WaveshaperAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* WaveshaperAudioProcessor::createEditor()
{
    return new WaveshaperAudioProcessorEditor (this);
}

//==============================================================================
void WaveshaperAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

    XmlElement root("Root");
    XmlElement* el;

    el = root.createNewChildElement("Gain");
    el->addTextElement(String(UserParams[gain]));

    el = root.createNewChildElement("K_Pos");
    el->addTextElement(String(UserParams[kpos]));

    el = root.createNewChildElement("K_Neg");
    el->addTextElement(String(UserParams[kneg]));

    el = root.createNewChildElement("Cascades");
    el->addTextElement(String(UserParams[cascade]));

    el = root.createNewChildElement("Invert");
    el->addTextElement(String(UserParams[invert]));

    copyXmlToBinary(root, destData);

}

void WaveshaperAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.

    static std::unique_ptr< XmlElement > pRoot = getXmlFromBinary(data, sizeInBytes);
    if (pRoot != NULL)
    {
        forEachXmlChildElement((*pRoot), pChild)
        {
            if (pChild->hasTagName("Gain"))
            {
                String text = pChild->getAllSubText();
                setParameter(gain, text.getFloatValue());
            }

            if (pChild->hasTagName("K_Pos"))
            {
                String text = pChild->getAllSubText();
                setParameter(kpos, text.getFloatValue());
            }

            if (pChild->hasTagName("K_Neg"))
            {
                String text = pChild->getAllSubText();
                setParameter(kneg, text.getFloatValue());
            }

            if (pChild->hasTagName("Cascades"))
            {
                String text = pChild->getAllSubText();
                setParameter(cascade, text.getFloatValue());
            }

            if (pChild->hasTagName("Invert"))
            {
                String text = pChild->getAllSubText();
                setParameter(invert, text.getFloatValue());
            }

        }
        UIUpdateFlag = true; 
    }

}

int WaveshaperAudioProcessor::getNumParameters()
{
    return totalNumParam;
}

float WaveshaperAudioProcessor::getParameter(int index)
{
    switch (index)
    {
    case gain:
        return UserParams[gain];
    case kpos:
        return UserParams[kpos];
    case kneg:
        return UserParams[kneg];
    case cascade:
        return UserParams[cascade];
    case invert:
        return UserParams[invert];
    default: 
        return 0.0f;
    }
}

void WaveshaperAudioProcessor::setParameter(int index, float newValue)
{
    switch (index)
    {
    case gain:
        UserParams[gain] = newValue;
        break;
    case kpos:
        UserParams[kpos] = newValue;
        if (UserParams[kpos] <= 0.0f)
            UserParams[kpos] = 1.0f;
        break;
    case kneg:
        UserParams[kneg] = newValue;
        if (UserParams[kneg] <= 0.0f)
            UserParams[kneg] = 1.0f;
        break;
    case cascade:
        UserParams[cascade] = newValue;
        if (UserParams[cascade] < 1.0f)
            UserParams[cascade] = 1.0f;
        if (UserParams[cascade] > 10.0f)
            UserParams[cascade] = 10.0f;
        break;
    case invert:
        UserParams[invert] = newValue;
        break;
    default: return;
    }
    UIUpdateFlag = true;//Request UI update -- Some OSX hosts use alternate editors, this updates ours
}

const String WaveshaperAudioProcessor::getParameterName(int index)
{
    switch (index)
    {
    case gain: return "Output Gain";
    case kpos: return "K Positive";
    case kneg: return "K Negative";
    case cascade: return "Cascades/Stages";
    case invert: return "Output Invert";

    default:return String();
    }
}

const String WaveshaperAudioProcessor::getParameterText(int index)
{
    if (index >= 0 && index < totalNumParam)
        return String(UserParams[index]);
    else return String();
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new WaveshaperAudioProcessor();
}
