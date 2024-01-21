#line 1 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/Joystick.hpp"
#ifndef JOYSTICK_HPP
#define JOYSTICK_HPP

#include <Arduino.h>
#include <stdint.h>
#include "IMidiComponent.hpp"

namespace MHC 
{
    class Joystick
    {    
    public:
        Joystick();
        Joystick(uint8_t pinX, MidiMessage_t valueX, uint8_t pinY, MidiMessage_t valueY);

        void Init();
        uint32_t ReadX();
        uint32_t ReadY();
        void SetValueX(MidiMessage_t value);
        void SetValueY(MidiMessage_t value);
        MidiMessage_t GetValueX();
        MidiMessage_t GetValueY();
        bool UpdateX(uint32_t currentValue, MidiMessage_t& midiMessage);
        bool UpdateY(uint8_t currentValue, MidiMessage_t& midiMessage);
        inline bool IsInitialized() { return m_initialized; };

    private:
        MidiMessage_t m_valueX;
        uint8_t m_pinX;
        uint8_t m_upCounterX = 0;
        uint8_t m_downCounterX = 0;
        uint8_t m_midiValueX = 0;
        uint8_t m_previousMidiValueX = 0;
        MidiMessage_t m_valueY;
        uint8_t m_pinY;
        uint8_t m_upCounterY = 0;
        uint8_t m_downCounterY = 0;
        uint8_t m_midiValueY = 0;
        uint8_t m_previousMidiValueY = 0;

        bool m_initialized = false;
    };

}

#endif // JOYSTICK_HPP
