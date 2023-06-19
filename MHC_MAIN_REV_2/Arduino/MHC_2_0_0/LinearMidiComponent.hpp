#ifndef LINEAR_MIDI_COMPONENT_HPP
#define LINEAR_MIDI_COMPONENT_HPP

#include <Arduino.h>
#include <stdint.h>
#include <Adafruit_TinyUSB.h>
#include <MIDI.h>
#include "IMidiComponent.hpp"
#include "IReadableComponent.hpp"

namespace MHC 
{
    class LinearMidiComponent: IMidiComponent, IReadableComponent
    {    
    public:
        LinearMidiComponent();
        LinearMidiComponent(MidiMessage_t value);

        // IReadableComponent
        virtual void Init();
        virtual uint32_t Read() = 0;

        // IMidiComponent
        virtual bool Update(uint8_t currentValue, MidiMessage_t& midiMessage);

        void SetValue(MidiMessage_t value);
        MidiMessage_t GetValue();
        inline bool IsInitialized() { return m_initialized; };

    private:
        MidiMessage_t m_value;
        uint8_t m_previousValue = 0;
        bool m_initialized = false;
    };

}

#endif // LINEAR_MIDI_COMPONENT_HPP
