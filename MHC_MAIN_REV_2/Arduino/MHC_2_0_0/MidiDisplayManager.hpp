#ifndef MIDI_DISPLAY_MANAGER_HPP
#define MIDI_DISPLAY_MANAGER_HPP

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

namespace MHC 
{
    class MidiDisplayManager
    {    
    public:
        MidiDisplayManager();

        void Init();
        void Update(uint8_t inData1, uint8_t inData2, uint8_t inChannel);
        void UpdateBank(uint8_t bank);
    };

}

#endif // MIDI_DISPLAY_MANAGER_HPP
