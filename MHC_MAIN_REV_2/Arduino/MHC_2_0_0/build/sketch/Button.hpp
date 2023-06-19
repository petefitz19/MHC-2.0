#line 1 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/Button.hpp"
#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <Arduino.h>
#include <stdint.h>
#include <Adafruit_TinyUSB.h>
#include <MIDI.h>
#include "IMidiComponent.hpp"
#include "BinaryMidiComponent.hpp"

namespace MHC 
{
    class Button: public BinaryMidiComponent
    {    
    public:
        Button();
        Button(uint8_t pin, MidiMessage_t value1, MidiMessage_t value2);

        virtual void Init();
        virtual uint32_t Read();

    private:
        uint8_t m_pin;
        MidiMessage_t m_midiMessage1;
        MidiMessage_t m_midiMessage2;

    };

}

#endif // BUTTON_HPP
