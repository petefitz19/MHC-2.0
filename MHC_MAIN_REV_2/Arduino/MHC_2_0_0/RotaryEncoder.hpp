#ifndef ROTARY_ENCODER_HPP
#define ROTARY_ENCODER_HPP

#include <Arduino.h>
#include <stdint.h>
#include "LinearMidiComponent.hpp"

namespace MHC 
{
    class RotaryEncoder: public LinearMidiComponent 
    {    
    public:
        RotaryEncoder();
        RotaryEncoder(uint8_t pinA, uint8_t pinB, MidiMessage_t value);

        virtual void Init();
        virtual uint32_t Read();

    private:
        uint8_t m_pinA;
        uint8_t m_pinB;
        uint32_t m_counter = 0;
        int m_aState = 0;
        int m_aLastState = 0;
    };
}

#endif // ROTARY_ENCODER_HPP
