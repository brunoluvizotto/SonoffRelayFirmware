#ifndef DIMMER_WIFI_HPP
#define DIMMER_WIFI_HPP

#include "task.hpp"

namespace Luvitronics
{
    class DimmerWifi : public Task
    {
    public: 
        DimmerWifi();
        
        virtual void process() override;
    };
}

#endif //DIMMER_WIFI_HPP
