#ifndef DIMMER_PINS_HPP
#define DIMMER_PINS_HPP

#include "task.hpp"

#include <ESP8266WiFi.h>

namespace Luvitronics
{
    class DimmerPins : public Task
    {
    public: 
        DimmerPins();
        
        virtual void process() override;
    };
}

#endif //DIMMER_PINS_HPP
