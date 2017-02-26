#ifndef PIN_HPP
#define PIN_HPP

#include <Arduino.h>
#include <common.h>

namespace Luvitronics
{
    class Pin
    {
    public: 
        Pin(const uint8_t number);
        
        unsigned mode();
        void setMode(const unsigned mode);
        
        bool state();
        void digitalWrite(bool value);
        void digitalInvert();
        
    private:
        uint8_t _number;
        static unsigned _mode[NUM_DIGITAL_PINS];
        static bool _state[NUM_DIGITAL_PINS];
        static bool _staticInitialized;
    };
}

#endif //PIN_HPP

