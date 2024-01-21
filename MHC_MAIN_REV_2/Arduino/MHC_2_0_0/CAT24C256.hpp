#ifndef CAT24C256_HPP
#define CAT24C256_HPP

#include <Arduino.h>
#include <Wire.h>

namespace MHC 
{
    class CAT24C256 
    {    
    public:
        CAT24C256();

        void Init();
        void WriteByte(int deviceAddress, unsigned int eeAddress, byte data);
        void WritePage(int deviceAddress, unsigned int eeAddresspage, byte* data, int length);
        byte ReadByte(int deviceAddress, unsigned int eeAddress);
        void ReadBuffer(int deviceAddress, unsigned int eeAddress, byte *buffer, int length);
    };

}

#endif // CAT24C256_HPP
