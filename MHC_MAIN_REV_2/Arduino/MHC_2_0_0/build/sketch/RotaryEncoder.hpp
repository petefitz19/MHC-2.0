#line 1 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/RotaryEncoder.hpp"
#ifndef ROTARY_ENCODER_HPP
#define ROTARY_ENCODER_HPP

#include <Arduino.h>
#include <stdint.h>
#include "LinearMidiComponent.hpp"

namespace MHC 
{
    // Enable this to emit codes twice per step.
    // #define HALF_STEP

    // Values returned by 'process'
    // No complete step yet.
    #define DIR_NONE 0x0
    // Clockwise step.
    #define DIR_CW 0x10
    // Counter-clockwise step.
    #define DIR_CCW 0x20

    class RotaryEncoder: public LinearMidiComponent 
    {    
    public:
        RotaryEncoder();
        RotaryEncoder(uint8_t pinA, uint8_t pinB, MidiMessage_t value);

        virtual void Init();
        virtual uint32_t Read();
        unsigned char process();

    private:
        uint8_t m_pinA;
        uint8_t m_pinB;
        uint32_t m_counter = 0;
        int m_aState = 0;
        int m_aLastState = 0;

        unsigned char state;
        unsigned char inverter;
    };
}

#endif // ROTARY_ENCODER_HPP



/*
 * Rotary encoder library for Arduino.
 */

#ifndef Rotary_h
#define Rotary_h

#include "Arduino.h"

// Enable this to emit codes twice per step.
// #define HALF_STEP

// Values returned by 'process'
// No complete step yet.
#define DIR_NONE 0x0
// Clockwise step.
#define DIR_CW 0x10
// Counter-clockwise step.
#define DIR_CCW 0x20

class Rotary
{
  public:
    Rotary(char, char);
    unsigned char process();
    void begin(bool internalPullup=true, bool flipLogicForPulldown=false);
  
    inline unsigned char pin_1() const { return pin1; }
    inline unsigned char pin_2() const { return pin2; }
  private:
    unsigned char state;
    unsigned char pin1;
    unsigned char pin2;
    unsigned char inverter;
};

#endif
 
