#ifndef DIMMER_UPDATER_HPP
#define DIMMER_UPDATER_HPP

#include "ota_updater.hpp"

namespace Luvitronics
{
    class DimmerUpdater : public OTAUpdater
    {
    public: 
        DimmerUpdater();
        
        static void progressFunction(unsigned, unsigned);
        static void endFunction();
    };
}

#endif //DIMMER_UPDATER_HPP
