#include "MidiBluetoothManager.hpp"
#include "MidiDisplayManager.hpp"

using namespace MHC;

BLEDis bledis;
BLEMidi blemidi;
MidiDisplayManager midiDisplayManager;
// Create a new instance of the Arduino MIDI Library,
// and attach BluefruitLE MIDI as the transport.
MIDI_CREATE_BLE_INSTANCE(blemidi);

MidiBluetoothManager::MidiBluetoothManager()
{
}

void MidiBluetoothManager::Init()
{
    midiDisplayManager.Init();

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
            break;
        }
    }
}

void MidiBluetoothManager::AddJoystick(Joystick& joystick)
{
    for(int i = 0; i < NUM_JOYSTICKS; i++)
    {
        if(!m_Joysticks[i].IsInitialized())
        {
            m_Joysticks[i] = joystick;
            break;
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
            break;
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
            break;
        }
    }
}

void MidiBluetoothManager::AddControlRotaryEncoder(RotaryEncoder& rotaryEncoder)
{
    m_controlRotaryEncoder = rotaryEncoder;
}

void MidiBluetoothManager::AddControlButton(Button& button)
{
    m_controlButton = button;
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

void MidiBluetoothManager::LoadPresets(uint8_t bank)
{
    uint8_t count = 0;
    uint8_t presets[NUM_CHARS];
    uint32_t addr = (uint32_t)bank * 64;
    byte b = i2c_eeprom_read_byte(0x50, addr);
    while (b!=0xFF && count < NUM_CHARS)
    {
        Serial.print((uint8_t)b); //print content to serial port
        presets[count] = (uint8_t)b;
        addr++;
        count++;
        b = i2c_eeprom_read_byte(0x50, addr); //access an address from the memory
    }

    uint8_t offset = 1;
    for(uint8_t i = 0; i < NUM_BUTTONS; i++)
    {
        struct MidiMessage_t midiMessage1 = {(MidiType)presets[offset++], (DataByte)presets[offset++], (DataByte)presets[offset++], (Channel)presets[offset++]};
        struct MidiMessage_t midiMessage2 = {(MidiType)presets[offset++], (DataByte)presets[offset++], (DataByte)presets[offset++], (Channel)presets[offset++]};
        m_Buttons[i].SetBinaryValues(midiMessage1, midiMessage2);
    }

    for(uint8_t i = 0; i < NUM_POTENTIOMETERS; i++)
    {
        struct MidiMessage_t midiMessage1 = {(MidiType)presets[offset++], (DataByte)presets[offset++], (DataByte)presets[offset++], (Channel)presets[offset++]};
        m_Potentiometers[i].SetValue(midiMessage1);
    }

    for(uint8_t i = 0; i < NUM_JOYSTICKS; i++)
    {
        struct MidiMessage_t midiMessage1 = {(MidiType)presets[offset++], (DataByte)presets[offset++], (DataByte)presets[offset++], (Channel)presets[offset++]};
        struct MidiMessage_t midiMessage2 = {(MidiType)presets[offset++], (DataByte)presets[offset++], (DataByte)presets[offset++], (Channel)presets[offset++]};
        m_Joysticks[i].SetValueX(midiMessage1);
        m_Joysticks[i].SetValueY(midiMessage2);
    }
}

void MidiBluetoothManager::Update() 
{
    // Don't continue if we aren't connected.
    // if (! Bluefruit.connected()) {
    //     return;
    // }

    // // Don't continue if the connected device isn't ready to receive messages.
    // if (! blemidi.notifyEnabled()) {
    //     return;
    // }
    
    // TODO: Just make this all one big for loop
    for(uint8_t i = 0; i < NUM_BUTTONS; i++)
    {
        MidiMessage_t midiMessage;
        if(m_Buttons[i].Update(m_Buttons[i].Read(), midiMessage))
        {
            MIDI.send(midiMessage.inType, midiMessage.inData1, midiMessage.inData2, midiMessage.inChannel);
            midiDisplayManager.Update(midiMessage.inData1, midiMessage.inData2, midiMessage.inChannel);
        }
    }

    for(uint8_t i = 0; i < NUM_JOYSTICKS; i++)
    {
        MidiMessage_t midiMessage;
        if(m_Joysticks[i].UpdateX(m_Joysticks[i].ReadX(), midiMessage))
        {
            MIDI.send(midiMessage.inType, midiMessage.inData1, midiMessage.inData2, midiMessage.inChannel);
            midiDisplayManager.Update(midiMessage.inData1, midiMessage.inData2, midiMessage.inChannel);

            // Serial.println((uint8_t)midiMessage.inData2); //print content to serial port
        }
        if(m_Joysticks[i].UpdateY(m_Joysticks[i].ReadY(), midiMessage))
        {
            MIDI.send(midiMessage.inType, midiMessage.inData1, midiMessage.inData2, midiMessage.inChannel);
            midiDisplayManager.Update(midiMessage.inData1, midiMessage.inData2, midiMessage.inChannel);
            
            // Serial.println((uint8_t)midiMessage.inData2); //print content to serial port
        }
    }

    for(uint8_t i = 0; i < NUM_POTENTIOMETERS; i++)
    {
        MidiMessage_t midiMessage;
        if(m_Potentiometers[i].Update(m_Potentiometers[i].Read(), midiMessage))
        {
            MIDI.send(midiMessage.inType, midiMessage.inData1, midiMessage.inData2, midiMessage.inChannel);
            midiDisplayManager.Update(midiMessage.inData1, midiMessage.inData2, midiMessage.inChannel);
        }
    }

    for(uint8_t i = 0; i < NUM_ENCODERS; i++)
    {
        MidiMessage_t midiMessage;
        if(m_Encoders[i].Update(m_Encoders[i].Read(), midiMessage))
        {
            MIDI.send(midiMessage.inType, midiMessage.inData1, midiMessage.inData2, midiMessage.inChannel);
            midiDisplayManager.Update(midiMessage.inData1, midiMessage.inData2, midiMessage.inChannel);
        }
    }
}

void MidiBluetoothManager::UpdateBank() 
{
    MidiMessage_t midiMessage;
    if(m_controlRotaryEncoder.Update(m_controlRotaryEncoder.Read(), midiMessage))
    {
        // TODO: Make control component shave their own base class
        // We are not using the Rotary Encoder as a MIDI component here. Instead it will be used as a way
        // to navigate the menu and turn on/off program mode
        midiDisplayManager.UpdateBank(midiMessage.inData2);

        if(midiMessage.inData2 == 0) {
            m_progMode = true;
        }
        else
        {
            m_progMode = false;
        }
    }

    if(m_controlButton.Update(m_controlButton.Read(), midiMessage))
    {
        LoadPresets(m_controlRotaryEncoder.GetValue().inData2 - 1);
    }

    while(m_progMode) 
    {
        HandleProgMode();
    }
}

void MidiBluetoothManager::HandleProgMode() 
{
    MidiMessage_t midiMessage;
    if(m_controlRotaryEncoder.Update(m_controlRotaryEncoder.Read(), midiMessage))
    {
        // We are not using the Rotary Encoder as a MIDI component here. Instead it will be used as a way
        // to navigate the menu and turn on/off program mode
        // MIDI.send(midiMessage.inType, midiMessage.inData1, midiMessage.inData2, midiMessage.inChannel);
        midiDisplayManager.UpdateBank(midiMessage.inData2);

        if(midiMessage.inData2 == 0) {
            m_progMode = true;
        }
        else
        {
            m_progMode = false;
        }
    }
    else {
        ReceiveData();
        SaveData();
    }
}

// TODO: Place in some sort of Memory Manager
void MidiBluetoothManager::ReceiveData()
{
    static byte ndx = 0;
    char endMarker = 0xFF;
    char rc;
    
    while (Serial.available() > 0 && newData == false) 
    {
        rc = Serial.read();

        if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= NUM_CHARS) {
            ndx = NUM_CHARS - 1;
        }
        }
        else {
        ndx = 0;
        newData = true;
        }
    }
}

void MidiBluetoothManager::SaveData()
{
    if (newData == true) {
    // Serial.println("Writing Data to EEPROM");
    i2c_eeprom_write_page(0x50, (uint32_t)receivedChars[0] * 64, (uint8_t *)receivedChars, sizeof(receivedChars)); // write to EEPROM
    delay(100);

    uint32_t addr = (uint32_t)receivedChars[0] * 64;
    byte b = i2c_eeprom_read_byte(0x50, addr);
    while (b!=0xFF)
    {
        Serial.print((uint8_t)b); //print content to serial port
        addr++;
        b = i2c_eeprom_read_byte(0x50, addr); //access an address from the memory
        Serial.print(" ");
    }
    Serial.println();
    newData = false;
  }
}

void MidiBluetoothManager::i2c_eeprom_write_byte( int deviceaddress, unsigned int eeaddress, byte data ) {
    int rdata = data;
    Wire.beginTransmission(deviceaddress);
    Wire.write((int)(eeaddress >> 8)); // MSB
    Wire.write((int)(eeaddress & 0xFF)); // LSB
    Wire.write(rdata);
    Wire.endTransmission();
}

// WARNING: address is a page address, 6-bit end will wrap around
// also, data can be maximum of about 30 bytes, because the Wire library has a buffer of 32 bytes
void MidiBluetoothManager::i2c_eeprom_write_page( int deviceaddress, unsigned int eeaddresspage, uint8_t* data, byte length ) {
    Wire.beginTransmission(deviceaddress);
    Wire.write((int)(eeaddresspage >> 8)); // MSB
    Wire.write((int)(eeaddresspage & 0xFF)); // LSB
    byte c;
    for ( c = 0; c < length; c++)
        Wire.write(data[c]);
    Wire.endTransmission();
}

byte MidiBluetoothManager::i2c_eeprom_read_byte( int deviceaddress, unsigned int eeaddress ) {
    byte rdata = 0xFF;
    Wire.beginTransmission(deviceaddress);
    Wire.write((int)(eeaddress >> 8)); // MSB
    Wire.write((int)(eeaddress & 0xFF)); // LSB
    Wire.endTransmission();
    Wire.requestFrom(deviceaddress,1);
    if (Wire.available()) rdata = Wire.read();
    return rdata;
}

// maybe let's not read more than 30 or 32 bytes at a time!
void MidiBluetoothManager::i2c_eeprom_read_buffer( int deviceaddress, unsigned int eeaddress, byte *buffer, int length ) {
    Wire.beginTransmission(deviceaddress);
    Wire.write((int)(eeaddress >> 8)); // MSB
    Wire.write((int)(eeaddress & 0xFF)); // LSB
    Wire.endTransmission();
    Wire.requestFrom(deviceaddress,length);
    int c = 0;
    for ( c = 0; c < length; c++ )
        if (Wire.available()) buffer[c] = Wire.read();
}
