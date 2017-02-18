#ifndef DIMMER_LISTENER_HPP
#define DIMMER_LISTENER_HPP

#include "task.hpp"

#include <ESP8266WiFi.h>

namespace Luvitronics
{
    class DimmerListener : public Task
    {
    public: 
        DimmerListener(uint16_t port);
        
        virtual void process() override;
        
    private:
        WiFiServer _server;
    };
}

#endif //DIMMER_LISTENER_HPP
