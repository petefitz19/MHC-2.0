#include <Arduino.h>
#line 1 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/MHC_2_0_0.ino"
#include "Button.hpp"
#include "IMidiComponent.hpp"
#include "MidiBluetoothManager.hpp"
#include "Potentiometer.hpp"
#include "RotaryEncoder.hpp"

using namespace MHC;

// Regular Button
struct MidiMessage_t buttonMessage0 = { NoteOn, 100, 127, 1 }; // Note On, Note Number, Velocity, Channel
struct MidiMessage_t buttonMessage1 = { NoteOff, 100, 0, 1 }; // Note Off, Note Number, Velocity, Channel
Button button0(13, buttonMessage0, buttonMessage1); // TODO: Switch back to 4

// Five Way Switch
struct MidiMessage_t buttonFiveWayUpMessage0 = { NoteOn, 101, 127, 1 };
struct MidiMessage_t buttonFiveWayUpMessage1 = { NoteOff, 101, 0, 1 };
struct MidiMessage_t buttonFiveWayDownMessage0 = { NoteOn, 102, 127, 1 };
struct MidiMessage_t buttonFiveWayDownMessage1 = { NoteOff, 102, 0, 1 };
struct MidiMessage_t buttonFiveWayLeftMessage0 = { NoteOn, 103, 127, 1 };
struct MidiMessage_t buttonFiveWayLeftMessage1 = { NoteOff, 103, 0, 1 };
struct MidiMessage_t buttonFiveWayRightMessage0 = { NoteOn, 104, 127, 1 };
struct MidiMessage_t buttonFiveWayRightMessage1 = { NoteOff, 104, 0, 1 };
struct MidiMessage_t buttonFiveWayClickMessage0 = { NoteOn, 105, 127, 1 };
struct MidiMessage_t buttonFiveWayClickMessage1 = { NoteOff, 105, 0, 1 };
Button buttonFiveWayUp(5, buttonFiveWayUpMessage0, buttonFiveWayUpMessage1);  // Up
Button buttonFiveWayDown(7, buttonFiveWayDownMessage0, buttonFiveWayDownMessage1);  // Down
Button buttonFiveWayLeft(2, buttonFiveWayLeftMessage0, buttonFiveWayLeftMessage1);  // Left
Button buttonFiveWayRight(28, buttonFiveWayRightMessage0, buttonFiveWayRightMessage1); // Right
Button buttonFiveWayClick(30, buttonFiveWayClickMessage0, buttonFiveWayClickMessage1); // Click

// Regular Slider
struct MidiMessage_t potentiometerMessage0 = { ControlChange, 106, 127, 1 }; // ControlChange, inControlNumber, inControlValue, channel
Potentiometer potentiometer0(2, potentiometerMessage0);

// Joystick
struct MidiMessage_t buttonJoystickClickMessage0 = { NoteOn, 107, 127, 1 };
struct MidiMessage_t buttonJoystickClickMessage1 = { NoteOff, 107, 0, 1 };
struct MidiMessage_t potentiometerJoystickXMessage = { ControlChange, 108, 0, 1 };
struct MidiMessage_t potentiometerJoystickYMessage = { ControlChange, 109, 0, 1 };
Potentiometer potentiometerJoystickX(29, potentiometerJoystickXMessage);
Potentiometer potentiometerJoystickY(3, potentiometerJoystickYMessage);
Button buttonJoystickClick(23, buttonJoystickClickMessage0, buttonJoystickClickMessage1);

// Rotary Encoder
struct MidiMessage_t rotaryEncoderMessage = { ControlChange, 110, 0, 1 };
RotaryEncoder rotaryEncoder0(15, 17, rotaryEncoderMessage);

MidiBluetoothManager midiBleManager;


#line 51 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/MHC_2_0_0.ino"
void setup();
#line 71 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/MHC_2_0_0.ino"
void loop();
#line 51 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/MHC_2_0_0.ino"
void setup()
{
    midiBleManager.AddButton(button0);
    midiBleManager.AddButton(buttonFiveWayUp);
    midiBleManager.AddButton(buttonFiveWayDown);
    midiBleManager.AddButton(buttonFiveWayLeft);
    midiBleManager.AddButton(buttonFiveWayRight);
    midiBleManager.AddButton(buttonFiveWayRight);
    midiBleManager.AddButton(buttonFiveWayClick);
    midiBleManager.AddButton(buttonJoystickClick);
    midiBleManager.AddPotentiometer(potentiometer0);

    midiBleManager.AddPotentiometer(potentiometerJoystickX);
    midiBleManager.AddPotentiometer(potentiometerJoystickY);

    midiBleManager.AddRotaryEncoder(rotaryEncoder0);

    midiBleManager.Init();
}

void loop()
{
    midiBleManager.Update();
    delay(100);
}

