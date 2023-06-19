#include "RotaryEncoder.hpp"

using namespace MHC;

RotaryEncoder::RotaryEncoder()
: LinearMidiComponent()
{
}

RotaryEncoder::RotaryEncoder(uint8_t pinA, uint8_t pinB, MidiMessage_t value)
: LinearMidiComponent(value)
{
  m_pinA = pinA;
  m_pinB = pinB;

  Init();
}

void RotaryEncoder::Init() 
{
    pinMode(m_pinA, INPUT_PULLUP);
    pinMode(m_pinB, INPUT_PULLUP);

    m_aLastState = digitalRead(m_pinA);   
}

// TODO: Implement Switch
uint32_t RotaryEncoder::Read() 
{
  m_aState = digitalRead(m_pinA); // Reads the "current" state of the pinA
    // If the previous and the current state of the pinA are different, that means a Pulse has occured
    if (m_aState != m_aLastState){     
        // If the pinB state is different to the pinA state, that means the encoder is rotating clockwise
        if (digitalRead(m_pinB) != m_aState) { 
            m_counter++;
        } else {
            m_counter--;
        }
    } 
    m_aLastState = m_aState; // Updates the previous state of the outputA with the current state

    return m_counter;
}
