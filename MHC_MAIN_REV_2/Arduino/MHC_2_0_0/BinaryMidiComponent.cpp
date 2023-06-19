#include "BinaryMidiComponent.hpp"
#include <MIDI.h>

using namespace MHC;

BinaryMidiComponent::BinaryMidiComponent()
{
}

BinaryMidiComponent::BinaryMidiComponent(MidiMessage_t value1, MidiMessage_t value2)
{
  m_value1 = value1;
  m_value2 = value2;
  m_initialized = true;
}

void BinaryMidiComponent::Init() 
{
    // To be implemented in child class
}

void BinaryMidiComponent::SetBinaryValues(MidiMessage_t value1, MidiMessage_t value2)
{
    m_value1 = value1;
    m_value2 = value2;
    m_initialized = true;
}

MidiMessage_t BinaryMidiComponent::GetFirstBinaryValue()
{
    return m_value1;
}

MidiMessage_t BinaryMidiComponent::GetSecondBinaryValue()
{
    return m_value2;
}


bool BinaryMidiComponent::Update(uint8_t currentValue, MidiMessage_t& midiMessage) 
{
    bool retVal = false;
    if(currentValue != m_previousValue) 
    {
        if(currentValue == 0)
        {
            midiMessage = m_value1;
        }
        else
        {
            midiMessage = m_value2;
        }
        m_previousValue = currentValue;
        retVal = true;
    }
    return retVal;
}
