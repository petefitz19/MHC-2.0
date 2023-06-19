#line 1 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/LinearMidiComponent.cpp"
#include "LinearMidiComponent.hpp"
#include <MIDI.h>

using namespace MHC;

LinearMidiComponent::LinearMidiComponent()
{
}

LinearMidiComponent::LinearMidiComponent(MidiMessage_t value)
{
  m_value = value;
  m_initialized = true;
}

void LinearMidiComponent::Init() 
{
    // To be implemented in child class
}

void LinearMidiComponent::SetValue(MidiMessage_t value)
{
    m_value = value;
    m_initialized = true;
}

MidiMessage_t LinearMidiComponent::GetValue()
{
    return m_value;
}

bool LinearMidiComponent::Update(uint8_t currentValue, MidiMessage_t& midiMessage) 
{
    bool retVal = false;
    if(currentValue != m_previousValue) 
    {
        m_value.inData2 = currentValue;
        midiMessage = m_value;
        m_previousValue = currentValue;
        retVal = true;
    }
    return retVal;
}
