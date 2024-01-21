#include "CAT24C256.hpp"

using namespace MHC;

CAT24C256::CAT24C256()
{
}

void CAT24C256::Init()
{
    Wire.begin(); // initialise the connection
}

void CAT24C256::WriteByte(int deviceAddress, unsigned int eeAddress, byte data)
{
    int rdata = data;

    Wire.beginTransmission(deviceAddress);
    Wire.write((int)(eeAddress >> 8)); // MSB
    Wire.write((int)(eeAddress & 0xFF)); // LSB
    Wire.write(rdata);
    Wire.endTransmission();
}

void CAT24C256::WritePage(int deviceAddress, unsigned int eeAddresspage, byte* data, int length)
{
    Wire.beginTransmission(deviceAddress);

    Wire.write((int)(eeAddresspage >> 8)); // MSB
    Wire.write((int)(eeAddresspage & 0xFF)); // LSB
    for (int c = 0; c < length; c++)
    {
        Wire.write(data[c]);
    }

    Wire.endTransmission();
}

byte CAT24C256::ReadByte(int deviceAddress, unsigned int eeAddress)
{
    byte rdata = 0xFF;
    Wire.beginTransmission(deviceAddress);
    Wire.write((int)(eeAddress >> 8)); // MSB
    Wire.write((int)(eeAddress & 0xFF)); // LSB
    Wire.endTransmission();
    Wire.requestFrom(deviceAddress,1);
    if (Wire.available()) rdata = Wire.read();
    return rdata;
}

void CAT24C256::ReadBuffer(int deviceAddress, unsigned int eeAddress, byte *buffer, int length)
{
    Wire.beginTransmission(deviceAddress);

    Wire.write((int)(eeAddress >> 8)); // MSB
    Wire.write((int)(eeAddress & 0xFF)); // LSB
    Wire.endTransmission();
    Wire.requestFrom(deviceAddress,length);
    for (int c = 0; c < length; c++ )
    {
        if (Wire.available()) buffer[c] = Wire.read();
    }
}
