#include "dimmer_updater.hpp"

Luvitronics::DimmerUpdater::DimmerUpdater() : OTAUpdater()
{
    onProgress(DimmerUpdater::progressFunction);
    onEnd(DimmerUpdater::endFunction);
}

void Luvitronics::DimmerUpdater::progressFunction(unsigned int, unsigned int)
{
    static bool flipflop = false;
    digitalWrite(LED_BUILTIN, flipflop);
    flipflop = !flipflop;
}

void Luvitronics::DimmerUpdater::endFunction()
{
    digitalWrite(LED_BUILTIN, HIGH);
}
