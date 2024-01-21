#line 1 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/Button.cpp"
#include "Button.hpp"

using namespace MHC;

Button::Button()
: BinaryMidiComponent()
{
}

Button::Button(uint8_t pin, MidiMessage_t value1, MidiMessage_t value2)
: BinaryMidiComponent(value1, value2)
{
  m_pin = pin;
  Init();
}

void Button::Init() 
{
  pinMode(m_pin, INPUT_PULLUP);
}

uint32_t Button::Read() 
{
  return !digitalRead(m_pin);
}