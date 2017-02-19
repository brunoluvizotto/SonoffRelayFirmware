#include "dimmer_updater.hpp"
#include "pin.hpp"

Luvitronics::DimmerUpdater::DimmerUpdater() : OTAUpdater()
{
    onProgress(DimmerUpdater::progressFunction);
    onEnd(DimmerUpdater::endFunction);
}

void Luvitronics::DimmerUpdater::progressFunction(unsigned int, unsigned int)
{
    Pin<LED_BUILTIN>::digitalInvert();
}

void Luvitronics::DimmerUpdater::endFunction()
{
    digitalWrite(LED_BUILTIN, HIGH);
}
