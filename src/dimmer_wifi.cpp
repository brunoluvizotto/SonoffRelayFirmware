#include "dimmer_wifi.hpp"

#include <ESP8266WiFi.h>

Luvitronics::DimmerWifi::DimmerWifi() : Luvitronics::Task()
{
  static const char* ssid = "rayuela 2.4";
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, "encontraria");
}

void Luvitronics::DimmerWifi::process()
{
    static bool connected = false;
    
    while (WiFi.status() != WL_CONNECTED) {
        static int flipflop = HIGH;
        digitalWrite(LED_BUILTIN, flipflop);
        flipflop = !flipflop;
        
        connected = false;
        delay(50);
    }

    if (!connected) {
        digitalWrite(LED_BUILTIN, HIGH);
        connected = true;
    }
}
