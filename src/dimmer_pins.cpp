#include "dimmer_pins.hpp"
#include "pin.hpp"

Luvitronics::DimmerPins::DimmerPins() : Task()
{
    analogWriteFreq(15000); //Hz
    
    Pin<0>::setMode(INPUT);
    Pin<2>::setMode(OUTPUT);
    Pin<LED_BUILTIN>::setMode(OUTPUT);
}

void Luvitronics::DimmerPins::process()
{
}
