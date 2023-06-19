#include "MidiBluetoothManager.hpp"

using namespace MHC;

BLEDis bledis;
BLEMidi blemidi;
// Create a new instance of the Arduino MIDI Library,
// and attach BluefruitLE MIDI as the transport.
MIDI_CREATE_BLE_INSTANCE(blemidi);

MidiBluetoothManager::MidiBluetoothManager()
{
}

void MidiBluetoothManager::Init()
{
    // Config the peripheral connection with maximum bandwidth 
    // more SRAM required by SoftDevice
    // Note: All config***() function must be called before begin()
    Bluefruit.configPrphBandwidth(BANDWIDTH_MAX);  

    Bluefruit.begin();
    Bluefruit.setTxPower(4);    // Check bluefruit.h for supported values

    // Setup the on board blue LED to be enabled on CONNECT
    Bluefruit.autoConnLed(true);

    // Configure and Start Device Information Service
    bledis.setManufacturer("Adafruit Industries");
    bledis.setModel("Bluefruit Feather52");
    bledis.begin();

    // Initialize MIDI, and listen to all MIDI channels
    // This will also call blemidi service's begin()
    MIDI.begin(MIDI_CHANNEL_OMNI);

    // Set up and start advertising
    StartAdvertising();
}

void MidiBluetoothManager::AddButton(Button& button)
{
    for(int i = 0; i < NUM_BUTTONS; i++)
    {
        if(!m_Buttons[i].IsInitialized())
        {
            m_Buttons[i] = button;
        }
    }
}

void MidiBluetoothManager::AddPotentiometer(Potentiometer& potentiometer)
{
    for(int i = 0; i < NUM_POTENTIOMETERS; i++)
    {
        if(!m_Potentiometers[i].IsInitialized())
        {
            m_Potentiometers[i] = potentiometer;
        }
    }
}

void MidiBluetoothManager::AddRotaryEncoder(RotaryEncoder& rotaryEncoder)
{
    for(int i = 0; i < NUM_ENCODERS; i++)
    {
        if(!m_Encoders[i].IsInitialized())
        {
            m_Encoders[i] = rotaryEncoder;
        }
    }
}

void MidiBluetoothManager::StartAdvertising()
{
    // Set General Discoverable Mode flag
    Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);

    // Advertise TX Power
    Bluefruit.Advertising.addTxPower();

    // Advertise BLE MIDI Service
    Bluefruit.Advertising.addService(blemidi);

    // Secondary Scan Response packet (optional)
    // Since there is no room for 'Name' in Advertising packet
    Bluefruit.ScanResponse.addName();

    /* Start Advertising
    * - Enable auto advertising if disconnected
    * - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
    * - Timeout for fast mode is 30 seconds
    * - Start(timeout) with timeout = 0 will advertise forever (until connected)
    *
    * For recommended advertising interval
    * https://developer.apple.com/library/content/qa/qa1931/_index.html   
    */
    Bluefruit.Advertising.restartOnDisconnect(true);
    Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
    Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
    Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds  
}


void MidiBluetoothManager::Update() 
{
    // Don't continue if we aren't connected.
    if (! Bluefruit.connected()) {
        return;
    }

    // Don't continue if the connected device isn't ready to receive messages.
    if (! blemidi.notifyEnabled()) {
        return;
    }
    
    // TODO: Just make this all one big for loop
    for(uint8_t i = 0; i < NUM_BUTTONS; i++)
    {
        MidiMessage_t midiMessage;
        if(m_Buttons[i].Update(m_Buttons[i].Read(), midiMessage))
        {
            MIDI.send(midiMessage.inType, midiMessage.inData1, midiMessage.inData2, midiMessage.inChannel);
        }
    }

    for(uint8_t i = 0; i < NUM_POTENTIOMETERS; i++)
    {
        MidiMessage_t midiMessage;
        if(m_Potentiometers[i].Update(m_Potentiometers[i].Read(), midiMessage))
        {
            MIDI.send(midiMessage.inType, midiMessage.inData1, midiMessage.inData2, midiMessage.inChannel);
        }
    }
}
