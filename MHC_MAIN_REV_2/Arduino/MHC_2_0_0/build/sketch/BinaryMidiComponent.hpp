#line 1 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/BinaryMidiComponent.hpp"
#ifndef BINARY_MIDI_COMPONENT_HPP
#define BINARY_MIDI_COMPONENT_HPP

#include <Arduino.h>
#include <stdint.h>
#include <Adafruit_TinyUSB.h>
#include <MIDI.h>
#include "IMidiComponent.hpp"
#include "IReadableComponent.hpp"

namespace MHC 
{
    class BinaryMidiComponent: IMidiComponent, IReadableComponent
    {    
    public:
        BinaryMidiComponent();
        BinaryMidiComponent(MidiMessage_t value1, MidiMessage_t value2);
        void SetBinaryValues(MidiMessage_t value1, MidiMessage_t value2);
        MidiMessage_t GetFirstBinaryValue();
        MidiMessage_t GetSecondBinaryValue();
        virtual bool Update(uint8_t currentValue, MidiMessage_t& midiMessage);
        virtual void Init();
        virtual uint32_t Read() = 0;
        inline bool IsInitialized() { return m_initialized; };

    private:
        MidiMessage_t m_value1;
        MidiMessage_t m_value2;
        uint8_t m_previousValue = 0;
        bool m_initialized = false;
    };

}

#endif // BINARY_MIDI_COMPONENT_HPP
