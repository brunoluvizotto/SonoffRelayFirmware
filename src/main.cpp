#include <vector>
#include <memory>

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>

#include "dimmer_updater.hpp"

WiFiServer server(80);

std::vector<std::unique_ptr<Luvitronics::Task>> tasks;

void setup() {
    tasks.emplace_back(new Luvitronics::DimmerUpdater());
    
  pinMode(0, INPUT);
  pinMode(2, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  analogWriteFreq(15000); //Hz
  
  static const char* ssid = "rayuela 2.4";
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, "encontraria");
}

void loop() {
  static bool connected = false;
  while (WiFi.status() != WL_CONNECTED) {
    static int flipflop = HIGH;
    connected = false;
    digitalWrite(LED_BUILTIN, flipflop);
    flipflop = !flipflop;
    delay(50);
  }

  if (!connected) {
    digitalWrite(LED_BUILTIN, HIGH);
    connected = true;
    
  }
  
    for (auto& task : tasks) {
        task->process();
    }

  server.begin();
  WiFiClient client = server.available();

  // wait for a client (web browser) to connect
  if (client) {
    while (client.connected()) {
      // read line by line what the client (web browser) is requesting
      if (client.available()) {
        String line = client.readStringUntil('\n');
        int pwm = atoi(line.c_str());
        if (pwm < 0 || pwm > PWMRANGE) {
          client.println("invalid value");
          client.print("free memory: ");
          client.println(ESP.getFreeSketchSpace());
          continue;
        }
        else {
          client.print("read: ");
          client.println(pwm);
        }

        analogWrite(2, PWMRANGE - pwm);
      }

      delay(10); // give the web browser time to receive the data
    }

    // close the connection:
    client.stop();
  }
}
