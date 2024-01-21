#line 1 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/Joystick.cpp"
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

uint32_t Joystick::ReadX()  
{
  const uint16_t margin = 10 ;   //  +/- 10
  const uint16_t numberOfLevelsOutput = 127 ;  // 0..9
  const uint16_t endPointInput[ numberOfLevelsOutput + 1 ] = { 160, 170, 175, 179, 184, 189, 194, 198, 203, 208, 213, 217, 222, 227, 232, 236, 241, 246, 251, 255, 260, 265, 270, 275, 279, 284, 289, 294, 298, 303, 308, 313, 317, 322, 327, 332, 336, 341, 346, 351, 355, 360, 365, 370, 375, 379, 384, 389, 394, 398, 403, 408, 413, 417, 422, 427, 432, 436, 441, 446, 451, 455, 460, 465, 470, 475, 479, 484, 489, 494, 498, 503, 508, 513, 517, 522, 527, 532, 536, 541, 546, 551, 555, 560, 565, 570, 575, 579, 584, 589, 594, 598, 603, 608, 613, 617, 622, 627, 632, 636, 641, 646, 651, 655, 660, 665, 670, 675, 679, 684, 689, 694, 698, 703, 708, 713, 717, 722, 727, 732, 736, 741, 746, 751, 755, 760, 765 } ;
  const  uint16_t initialOutputLevel = 0 ;
  static uint16_t currentOutputLevel = initialOutputLevel ;

  uint16_t inputLevel = analogRead(m_pinX);

  // get lower and upper bounds for currentOutputLevel
  uint16_t lb = endPointInput[ currentOutputLevel ] ;
  if ( currentOutputLevel > 0 ) lb -= margin  ;   // subtract margin

  uint16_t ub = endPointInput[ currentOutputLevel + 1 ] ;
  if ( currentOutputLevel < numberOfLevelsOutput ) ub +=  margin  ;  // add margin

  // now test if input is between the outer margins for current output value
  if ( inputLevel < lb || inputLevel > ub ) {
    // determine new output level by scanning endPointInput array
    uint16_t i;
    for ( i = 0 ; i < numberOfLevelsOutput ; i++ ) {
      if ( inputLevel >= endPointInput[ i ] && inputLevel <= endPointInput[ i + 1 ] ) break ;
    }
    currentOutputLevel = i ;
  }
  return currentOutputLevel ;
}

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

uint32_t Joystick::ReadY()  
{
  const uint16_t margin = 10 ;   //  +/- 10
  const uint16_t numberOfLevelsOutput = 127 ;  // 0..9
  const uint16_t endPointInput[ numberOfLevelsOutput + 1 ] = { 160, 170, 175, 179, 184, 189, 194, 198, 203, 208, 213, 217, 222, 227, 232, 236, 241, 246, 251, 255, 260, 265, 270, 275, 279, 284, 289, 294, 298, 303, 308, 313, 317, 322, 327, 332, 336, 341, 346, 351, 355, 360, 365, 370, 375, 379, 384, 389, 394, 398, 403, 408, 413, 417, 422, 427, 432, 436, 441, 446, 451, 455, 460, 465, 470, 475, 479, 484, 489, 494, 498, 503, 508, 513, 517, 522, 527, 532, 536, 541, 546, 551, 555, 560, 565, 570, 575, 579, 584, 589, 594, 598, 603, 608, 613, 617, 622, 627, 632, 636, 641, 646, 651, 655, 660, 665, 670, 675, 679, 684, 689, 694, 698, 703, 708, 713, 717, 722, 727, 732, 736, 741, 746, 751, 755, 760, 765 } ;
  const  uint16_t initialOutputLevel = 0 ;
  static uint16_t currentOutputLevel = initialOutputLevel ;

  uint16_t inputLevel = analogRead(m_pinY);

  // get lower and upper bounds for currentOutputLevel
  uint16_t lb = endPointInput[ currentOutputLevel ] ;
  if ( currentOutputLevel > 0 ) lb -= margin  ;   // subtract margin

  uint16_t ub = endPointInput[ currentOutputLevel + 1 ] ;
  if ( currentOutputLevel < numberOfLevelsOutput ) ub +=  margin  ;  // add margin

  // now test if input is between the outer margins for current output value
  if ( inputLevel < lb || inputLevel > ub ) {
    // determine new output level by scanning endPointInput array
    uint16_t i;
    for ( i = 0 ; i < numberOfLevelsOutput ; i++ ) {
      if ( inputLevel >= endPointInput[ i ] && inputLevel <= endPointInput[ i + 1 ] ) break ;
    }
    currentOutputLevel = i ;
  }
  return currentOutputLevel ;
}

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

bool Joystick::UpdateX(uint32_t currentValue, MidiMessage_t& midiMessage) 
{
    bool retVal = false;
    if(currentValue != m_previousMidiValueX)
    {
        m_valueX.inData2 = currentValue;
        midiMessage = m_valueX;
        m_previousMidiValueX = currentValue;
        retVal = true;
    }
    return retVal;
}

bool Joystick::UpdateY(uint8_t currentValue, MidiMessage_t& midiMessage) 
{
    bool retVal = false;
    if(currentValue != m_previousMidiValueY) 
    {
        m_valueY.inData2 = currentValue;
        midiMessage = m_valueY;
        m_previousMidiValueY = currentValue;
        retVal = true;
    }
    return retVal;
}