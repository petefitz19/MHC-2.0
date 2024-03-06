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
  uint32_t currentValue = analogRead(m_pin);
  uint8_t returnValue = m_prevMidiValue;
  if(abs(m_previousValue - currentValue) > 10)
  {
    returnValue = map(currentValue, 0, 940, 0, 127);
    if(returnValue > 127) {
      returnValue = 127;
    }
    else if(returnValue < 0) {
      returnValue = 0;
    }
    m_prevMidiValue = returnValue;
    m_previousValue = currentValue;
  }
  return returnValue;
}