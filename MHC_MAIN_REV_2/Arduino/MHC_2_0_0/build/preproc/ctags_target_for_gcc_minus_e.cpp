# 1 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/MHC_2_0_0.ino"
# 2 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/MHC_2_0_0.ino" 2
# 3 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/MHC_2_0_0.ino" 2
# 4 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/MHC_2_0_0.ino" 2
# 5 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/MHC_2_0_0.ino" 2
# 6 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/MHC_2_0_0.ino" 2
# 7 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/MHC_2_0_0.ino" 2
# 8 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/MHC_2_0_0.ino" 2

using namespace MHC;

// // Built-In Button
// struct MidiMessage_t button0Message0 = { NoteOff, 100, 0, 1 }; // Note On, Note Number, Velocity, Channel
// struct MidiMessage_t button0Message1 = { NoteOn, 100, 127, 1 }; // Note Off, Note Number, Velocity, Channel
// Button button0(13, button0Message0, button0Message1);

// Regular Button
struct MidiMessage_t button1Message0 = { NoteOff, 100, 0, 1 }; // Note On, Note Number, Velocity, Channel
struct MidiMessage_t button1Message1 = { NoteOn, 100, 127, 1 }; // Note Off, Note Number, Velocity, Channel
Button button1(13, button1Message0, button1Message1); // TODO: Switch back to 4

// Five Way Switch
struct MidiMessage_t buttonFiveWayUpMessage1 = { NoteOn, 101, 127, 1 };
struct MidiMessage_t buttonFiveWayUpMessage0 = { NoteOff, 101, 0, 1 };
struct MidiMessage_t buttonFiveWayDownMessage1 = { NoteOn, 102, 127, 1 };
struct MidiMessage_t buttonFiveWayDownMessage0 = { NoteOff, 102, 0, 1 };
struct MidiMessage_t buttonFiveWayLeftMessage1 = { NoteOn, 103, 127, 1 };
struct MidiMessage_t buttonFiveWayLeftMessage0 = { NoteOff, 103, 0, 1 };
struct MidiMessage_t buttonFiveWayRightMessage1 = { NoteOn, 104, 127, 1 };
struct MidiMessage_t buttonFiveWayRightMessage0 = { NoteOff, 104, 0, 1 };
struct MidiMessage_t buttonFiveWayClickMessage1 = { NoteOn, 105, 127, 1 };
struct MidiMessage_t buttonFiveWayClickMessage0 = { NoteOff, 105, 0, 1 };
Button buttonFiveWayUp(5, buttonFiveWayUpMessage0, buttonFiveWayUpMessage1); // Up
Button buttonFiveWayDown((20), buttonFiveWayDownMessage0, buttonFiveWayDownMessage1); // Down
Button buttonFiveWayLeft(6, buttonFiveWayLeftMessage0, buttonFiveWayLeftMessage1); // Left
Button buttonFiveWayRight(28, buttonFiveWayRightMessage0, buttonFiveWayRightMessage1); // Right
Button buttonFiveWayClick(30, buttonFiveWayClickMessage0, buttonFiveWayClickMessage1); // Click

// Regular Slider
struct MidiMessage_t potentiometerMessage0 = { ControlChange, 106, 127, 1 }; // ControlChange, inControlNumber, inControlValue, channel
Potentiometer potentiometer0(2, potentiometerMessage0);

// Joystick
// struct MidiMessage_t buttonJoystickClickMessage0 = { NoteOn, 107, 127, 1 };
// struct MidiMessage_t buttonJoystickClickMessage1 = { NoteOff, 107, 0, 1 };
struct MidiMessage_t potentiometerJoystickXMessage = { ControlChange, 108, 0, 1 };
struct MidiMessage_t potentiometerJoystickYMessage = { ControlChange, 109, 0, 1 };
Joystick joystick0(29, potentiometerJoystickXMessage, 3, potentiometerJoystickYMessage);
// Button buttonJoystickClick(23, buttonJoystickClickMessage0, buttonJoystickClickMessage1);

// Rotary Encoder
struct MidiMessage_t rotaryEncoderMessage = { ControlChange, 110, 0, 1 };
RotaryEncoder rotaryEncoder0(15, 17, rotaryEncoderMessage);

// Rotary Encoder Button
struct MidiMessage_t buttonRotaryEncoderMessage1 = { NoteOn, 110, 1, 1 };
struct MidiMessage_t buttonRotaryEncoderMessage0 = { NoteOff, 110, 0, 1 };
Button buttonRotaryEncoder(31, buttonRotaryEncoderMessage0, buttonRotaryEncoderMessage1);


MidiBluetoothManager midiBleManager;
CAT24C256 eeprom;

void setup()
{
    // midiBleManager.AddButton(button0);
    midiBleManager.AddButton(button1);
    midiBleManager.AddButton(buttonFiveWayUp);
    midiBleManager.AddButton(buttonFiveWayDown);
    midiBleManager.AddButton(buttonFiveWayLeft);
    midiBleManager.AddButton(buttonFiveWayRight);
    midiBleManager.AddButton(buttonFiveWayClick);
    // midiBleManager.AddButton(buttonJoystickClick);
    midiBleManager.AddPotentiometer(potentiometer0);

    midiBleManager.AddJoystick(joystick0);

    midiBleManager.AddControlRotaryEncoder(rotaryEncoder0);
    midiBleManager.AddControlButton(buttonRotaryEncoder);

    midiBleManager.Init();

    eeprom.Init();

    Serial.begin(115200);

    pinMode(20, (0x1));
    digitalWrite(20, (0x1));

    Serial.println("Starting application");

    // char somedata[] = "Pete Message from EEPROM"; // data to write
    // eeprom.WritePage(0x50, 0, (byte *)somedata, sizeof(somedata)); // write to EEPROM
    // delay(100); //add a small delay

    // Serial.println("Memory written");
}

void loop()
{
    midiBleManager.Update();
    midiBleManager.UpdateBank();
}
