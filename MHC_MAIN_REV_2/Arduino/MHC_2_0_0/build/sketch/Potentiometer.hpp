#line 1 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/Potentiometer.hpp"
#ifndef POTENTIOMETER_HPP
#define POTENTIOMETER_HPP

#include <Arduino.h>
#include <stdint.h>
#include "LinearMidiComponent.hpp"

namespace MHC 
{
    class Potentiometer: public LinearMidiComponent 
    {    
    public:
        Potentiometer();
        Potentiometer(uint8_t pin, MidiMessage_t value);

        virtual void Init();
        virtual uint32_t Read();

    private:
        uint8_t m_pin;
        uint32_t m_previousValue = 0;
        uint8_t m_prevMidiValue = 0;
    };

}

#endif // POTENTIOMETER_HPP
