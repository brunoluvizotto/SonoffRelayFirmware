#ifndef OTA_UPDATER_HPP
#define OTA_UPDATER_HPP

#include <ArduinoOTA.h>

#include "task.hpp"

#define NO_GLOBAL_ARDUINOOTA

namespace Luvitronics
{
    class OTAUpdater : public ArduinoOTAClass, public Task
    {
    public: 
        OTAUpdater();
        ~OTAUpdater();
        
        virtual void process() override;
    };
}

#endif //OTA_UPDATER_HPP
