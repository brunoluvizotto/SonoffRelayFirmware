#include "pin.hpp"

unsigned Luvitronics::Pin::_mode[NUM_DIGITAL_PINS];
bool Luvitronics::Pin::_state[NUM_DIGITAL_PINS];
bool Luvitronics::Pin::_staticInitialized = false;

Luvitronics::Pin::Pin(uint8_t number) : _number(number)
{
    if (!_staticInitialized) {
        memset(_mode, INPUT, sizeof(_mode));
        for (size_t i = 0; i < NUM_DIGITAL_PINS; ++i) 
            _state[i] = state();
        
        _staticInitialized = true;
    }
}

unsigned Luvitronics::Pin::mode()
{
    return _mode[_number];
}

void Luvitronics::Pin::setMode(const unsigned mode)
{
    _mode[_number] = mode;
    pinMode(_number, mode);
}

bool Luvitronics::Pin::state()
{
    if (_mode[_number] == OUTPUT) {
        return _state[_number];
    }
    
    return digitalRead(_number);
}

void Luvitronics::Pin::digitalWrite(bool value)
{
    
    if (_mode[_number] != OUTPUT)
        setMode(OUTPUT);
    
    _state[_number] = value;
    ::digitalWrite(_number, value);
}

void Luvitronics::Pin::digitalInvert()
{
    digitalWrite(!_state[_number]);
}
