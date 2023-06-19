#ifndef MIDI_BLUETOOTH_MANAGER_HPP
#define MIDI_BLUETOOTH_MANAGER_HPP

#include <Arduino.h>
#include <stdint.h>
#include "Button.hpp"
#include "Potentiometer.hpp"
#include "RotaryEncoder.hpp"
#include <bluefruit.h>
#include <MIDI.h>

#define NUM_BUTTONS 1
#define NUM_POTENTIOMETERS 1
#define NUM_ENCODERS 1

namespace MHC 
{
    class MidiBluetoothManager
    {    
    public:
        MidiBluetoothManager();
        void AddButton(Button& button);
        void AddPotentiometer(Potentiometer& potentiometer);
        void AddRotaryEncoder(RotaryEncoder& rotaryEncoder);
        void Update();
        void Init();

    private:
        void StartAdvertising();

        Button m_Buttons[NUM_BUTTONS];
        Potentiometer m_Potentiometers[NUM_POTENTIOMETERS];
        RotaryEncoder m_Encoders[NUM_ENCODERS];
    };

}

#endif // MIDI_BLUETOOTH_MANAGER_HPP
