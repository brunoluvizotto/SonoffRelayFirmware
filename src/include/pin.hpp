#ifndef PIN_HPP
#define PIN_HPP

#include "Arduino.h"
#include "common.h"

namespace Luvitronics
{
    template<uint8_t i>
    class Pin
    {
    public: 
        template<uint8_t pin>
        static constexpr void check_bounds() {
            static_assert(pin < NUM_DIGITAL_PINS, "Pin out of bounds");
        }
            
        static constexpr void setMode(const uint8_t mode)
        {
            check_bounds<i>();
            _mode[i] = mode;
            pinMode(i, mode);
        }
        
        static uint8_t mode()
        {
            check_bounds<i>();
            return _mode[i];
        }
        
        static constexpr void digitalWrite(bool value)
        {
            check_bounds<i>();
            
            if (_mode[i] != OUTPUT)
                setMode(OUTPUT);
            
            _state[i] = value;
            ::digitalWrite(i, value);
        }
        
        static constexpr void digitalInvert()
        {
            Pin<i>::digitalWrite(!_state[i]);
        }
        
        static bool digitalState()
        {
            if (_mode[i] == OUTPUT) {
                check_bounds<i>();
                return _state[i];
            }
            
            return digitalRead(i);
        }
        
    private:
        Pin() = delete;
        static uint8_t _mode[NUM_DIGITAL_PINS];
        static bool _state[NUM_DIGITAL_PINS];
    };
    
    template<uint8_t pin>
    uint8_t Pin<pin>::_mode[NUM_DIGITAL_PINS];
    template<uint8_t pin>
    bool Pin<pin>::_state[NUM_DIGITAL_PINS];
}

#endif //PIN_HPP

