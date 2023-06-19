#line 1 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/Potentiometer.cpp"
#include "Potentiometer.hpp"

using namespace MHC;

Potentiometer::Potentiometer()
: LinearMidiComponent()
{
}

Potentiometer::Potentiometer(uint8_t pin, MidiMessage_t value)
: LinearMidiComponent(value)
{
  m_pin = pin;
  Init();
}

void Potentiometer::Init() 
{
  // no need for initialization
}

uint32_t Potentiometer::Read() 
{
  return analogRead(m_pin);
}