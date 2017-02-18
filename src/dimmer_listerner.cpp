#include "dimmer_listerner.hpp"

Luvitronics::DimmerListener::DimmerListener(uint16_t port)
    : Task(), _server(port)
{
    _server.begin();
}

void Luvitronics::DimmerListener::process() {
    auto client = _server.available();

    for (; client && client.connected(); delay(10)) {
        if (!client.available())
            continue;
            
        String line = client.readStringUntil('\n');
        int pwm = atoi(line.c_str());
        if (0 < pwm && pwm < PWMRANGE) {
            client.print("read: ");
            client.println(pwm);
        }
        else {
            client.println("invalid value");
            client.print("free memory: ");
            client.println(ESP.getFreeSketchSpace());
        }

        analogWrite(2, PWMRANGE - pwm);
    }

    // close the connection:
    client.stop();
}
