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
        bool UpdateX(MidiMessage_t& midiMessage, bool& direction);
        bool UpdateY(MidiMessage_t& midiMessage, bool& direction);
        inline bool IsInitialized() { return m_initialized; };

    private:
        MidiMessage_t m_valueX;
        uint8_t m_pinX;
        uint8_t m_upCounterX = 0;
        uint8_t m_downCounterX = 0;
        uint8_t m_midiValueX = 0;
        uint8_t m_previousMidiValueX = 0;
        uint16_t m_previousValueX = 0;
        MidiMessage_t m_valueY;
        uint8_t m_pinY;
        uint8_t m_upCounterY = 0;
        uint8_t m_downCounterY = 0;
        uint8_t m_midiValueY = 0;
        uint8_t m_previousMidiValueY = 0;
        uint16_t m_previousValueY = 0;

        bool m_initialized = false;
    };

}

#endif // JOYSTICK_HPP
