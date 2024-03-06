#include "Joystick.hpp"

using namespace MHC;

Joystick::Joystick()
{
}

Joystick::Joystick(uint8_t pinX, MidiMessage_t valueX, uint8_t pinY, MidiMessage_t valueY)
{
  m_pinX = pinX;
  m_pinY = pinY;
  m_valueX = valueX;
  m_valueY = valueY;
  Init();
}

void Joystick::Init() 
{
  m_previousValueX = analogRead(m_pinX);
  m_previousValueY = analogRead(m_pinY);
  m_initialized = true;
}

// uint32_t Joystick::ReadX() 
// {
//   uint32_t currentValueX = analogRead(m_pinX);
//   if(currentValueX >= 700)
//   {
//     m_upCounterX++;
//     m_downCounterX = 0;
//     if(m_upCounterX >= 50)
//     {
//         m_midiValueX++;
//         m_upCounterX = 0;

//         if(m_midiValueX >= 127)
//         {
//             m_midiValueX = 127;
//         }
//     }
//   }
//   else if(currentValueX <= 200)
//   {
//     m_downCounterX++;
//     m_upCounterX = 0;
//     if(m_downCounterX >= 50)
//     {
//         m_midiValueX--;
//         m_downCounterX = 0;

//         if(m_midiValueX >= 128 && m_midiValueX <= 255)
//         {
//             m_midiValueX = 0;
//         }
//     }
//   }
//   else{
//     m_upCounterX = 0;
//     m_downCounterX = 0;
//   }
//   return m_midiValueX;
// }

// uint32_t Joystick::ReadY() 
// {
//   uint32_t currentValueY = analogRead(m_pinY);
//   if(currentValueY >= 700)
//   {
//     m_upCounterY++;
//     m_downCounterY = 0;
//     if(m_upCounterY >= 50)
//     {
//         m_midiValueY++;
//         m_upCounterY = 0;

//         if(m_midiValueY >= 127)
//         {
//             m_midiValueY = 127;
//         }
//     }
//   }
//   else if(currentValueY <= 200)
//   {
//     m_downCounterY++;
//     m_upCounterY = 0;
//     if(m_downCounterY >= 50)
//     {
//         m_midiValueY--;
//         m_downCounterY = 0;

//         if(m_midiValueY >= 128 && m_midiValueY <= 255)
//         {
//             m_midiValueY = 0;
//         }
//     }
//   }
//   else{
//     m_upCounterY = 0;
//     m_downCounterY = 0;
//   }
//   return m_midiValueY;
// }

void Joystick::SetValueX(MidiMessage_t value)
{
    m_valueX = value;
    m_initialized = true;
}

void Joystick::SetValueY(MidiMessage_t value)
{
    m_valueY = value;
    m_initialized = true;
}

MidiMessage_t Joystick::GetValueX()
{
    return m_valueX;
}

MidiMessage_t Joystick::GetValueY()
{
    return m_valueY;
}

bool Joystick::UpdateX(MidiMessage_t& midiMessage, bool& direction) 
{
    uint16_t halfValue = 448;
    uint16_t minValue = 150;
    uint16_t maxValue = 740;
    uint16_t currentValue = analogRead(m_pinX);
    Serial.println(currentValue); // Uncomment to get middle value

    bool retVal = false;
    if((currentValue > m_previousValueX + 10) || (currentValue < m_previousValueX - 10))
    {
        int mappedToMidiVal = 0;
        if((currentValue < (halfValue - 10))) {
          direction = false;
          mappedToMidiVal = map(currentValue, minValue, halfValue - 10, 127, 0);
        }
        else if(currentValue > (halfValue + 10)) {
          direction = true;
          mappedToMidiVal = map(currentValue, halfValue + 10, maxValue, 0, 127);
        }
        
        m_valueX.inData2 = mappedToMidiVal;
        if(mappedToMidiVal > 127) {
          m_valueX.inData2 = 127;
        }

        if(mappedToMidiVal < 0) {
          m_valueX.inData2 = 0;
        }
        midiMessage = m_valueX;
        m_previousValueX = currentValue;
        retVal = true;
    }
    return retVal;
}

bool Joystick::UpdateY(MidiMessage_t& midiMessage, bool& direction) 
{
    uint16_t halfValue = 480;
    int16_t minValue = 180;
    uint16_t maxValue = 760;
    uint16_t currentValue = analogRead(m_pinY);
    //Serial.println(currentValue); // Uncomment to get middle value

    bool retVal = false;
    if((currentValue > m_previousValueY + 10) || (currentValue < m_previousValueY - 10))
    {
        int mappedToMidiVal = 0;
        if((currentValue < (halfValue - 10))) {
          direction = false;
          mappedToMidiVal = map(currentValue, minValue, halfValue - 10, 127, 0);
        }
        else if(currentValue > (halfValue + 10)) {
          direction = true;
          mappedToMidiVal = map(currentValue, halfValue + 10, maxValue, 0, 127);
        }
        
        m_valueY.inData2 = mappedToMidiVal;
        if(mappedToMidiVal > 127) {
          m_valueY.inData2 = 127;
        }

        if(mappedToMidiVal < 0) {
          m_valueY.inData2 = 0;
        }
        midiMessage = m_valueY;
        m_previousValueY = currentValue;
        retVal = true;
    }
    return retVal;
}