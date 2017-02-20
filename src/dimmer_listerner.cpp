#include "dimmer_listerner.hpp"
#include "http_request.hpp"

#include <string>

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
        if (line.indexOf('\r'))
            client.println("has \\r");
        else
            client.println("no \\r");
        
        client.println(line);
        auto request = HttpRequest::create(line);
        
        if (request.method() == "GET" && request.path() == "/info") {
            
        }
        
        break;
        
        client.println(request.valid() ? "Request valid!" : "Request invalid!");
        client.print("method: "); client.println(request.method());
        client.print("path: "); client.println(request.path());
        client.print("version: "); client.println(request.version());
        
        /*
        int pwm = atoi(line.c_str());
        if (0 < pwm && pwm < PWMRANGE) {
            client.print("read: ");
            client.println(pwm);
        }
        analogWrite(2, PWMRANGE - pwm);
        */
    }

    // close the connection:
    client.stop();
}
