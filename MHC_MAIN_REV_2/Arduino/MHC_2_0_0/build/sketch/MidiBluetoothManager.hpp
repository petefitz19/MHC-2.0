#line 1 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/MidiBluetoothManager.hpp"
#ifndef MIDI_BLUETOOTH_MANAGER_HPP
#define MIDI_BLUETOOTH_MANAGER_HPP

#include <Arduino.h>
#include <stdint.h>
#include "Button.hpp"
#include "Joystick.hpp"
#include "Potentiometer.hpp"
#include "RotaryEncoder.hpp"
#include <bluefruit.h>
#include <MIDI.h>

#define NUM_BUTTONS 1 // 6
#define NUM_JOYSTICKS 1  // 1
#define NUM_POTENTIOMETERS 0 // 1
#define NUM_ENCODERS 0

#define NUM_CHARS 62

namespace MHC 
{
    class MidiBluetoothManager
    {    
    public:
        MidiBluetoothManager();
        void AddButton(Button& button);
        void AddPotentiometer(Potentiometer& potentiometer);
        void AddRotaryEncoder(RotaryEncoder& rotaryEncoder);
        void AddJoystick(Joystick& joystick);
        void AddControlRotaryEncoder(RotaryEncoder& rotaryEncoder);
        void AddControlButton(Button& button);
        void Update();
        void UpdateBank();
        void LoadPresets(uint8_t bank);
        void HandleProgMode();
        void ReceiveData();
        void SaveData();
        void Init();

        void i2c_eeprom_write_byte( int deviceaddress, unsigned int eeaddress, byte data );
        void i2c_eeprom_write_page( int deviceaddress, unsigned int eeaddresspage, uint8_t* data, byte length );
        byte i2c_eeprom_read_byte( int deviceaddress, unsigned int eeaddress );
        void i2c_eeprom_read_buffer( int deviceaddress, unsigned int eeaddress, byte *buffer, int length );



    private:
        void StartAdvertising();

        Button m_Buttons[NUM_BUTTONS];
        Joystick m_Joysticks[NUM_JOYSTICKS];
        Potentiometer m_Potentiometers[NUM_POTENTIOMETERS];
        RotaryEncoder m_Encoders[NUM_ENCODERS];

        Button m_controlButton;
        RotaryEncoder m_controlRotaryEncoder;

        bool m_progMode = false;

        uint8_t receivedChars[NUM_CHARS]; // an array to store the received data
        boolean newData = false;
    };

}

#endif // MIDI_BLUETOOTH_MANAGER_HPP
