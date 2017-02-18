#include "ota_updater.hpp"

#include <ESP8266mDNS.h>
#include <WiFiUdp.h>

Luvitronics::OTAUpdater::OTAUpdater() : ArduinoOTAClass(), Task()
{
    begin();
}

Luvitronics::OTAUpdater::~OTAUpdater() {}

void Luvitronics::OTAUpdater::process()
{
    handle();
}
