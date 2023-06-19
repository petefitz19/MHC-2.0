#ifndef IMIDI_COMPONENT_HPP
#define IMIDI_COMPONENT_HPP

#include <Midi.h>
using namespace MIDI_NAMESPACE;

namespace MHC 
{

    struct MidiMessage_t{
        MidiType inType;
        DataByte inData1;
        DataByte inData2;
        Channel inChannel;
    };

    class IMidiComponent 
    {    
    public:
        virtual bool Update(uint8_t currentValue, MidiMessage_t& midiMessage)  = 0;
    };
}

#endif // IMIDI_COMPONENT_HPP
