#include "http_listener.hpp"
#include "http_request.hpp"
#include "http_response.hpp"

#include <string>

Luvitronics::HttpListener::HttpListener(uint16_t port)
    : Task(), _server(port), _processorMap()
{
    _server.begin();
}

void Luvitronics::HttpListener::registerProcessor(String endpoint, HttpProcessor* processor)
{
    _processorMap.emplace(std::make_pair(endpoint, std::unique_ptr<HttpProcessor>(processor)));
}

void Luvitronics::HttpListener::registerProcessor(String endpoint,
                                                    std::unique_ptr<HttpProcessor>& processor)
{
    _processorMap.emplace(endpoint, std::move(processor));
}

void Luvitronics::HttpListener::process() {
    auto client = _server.available();
    
    if (!client)
        return;

    while (!client.available())
        delay(1);
    
    auto line = client.readStringUntil('\n');
    auto request = HttpRequest::create(line);
    auto response = HttpResponse(client);
    
    auto processor = _processorMap.find(request->path());
    if (processor != _processorMap.end())
        processor->second->process(*request, response);
    else
        response = 404;
    
    return;
    
    /*
    int pwm = atoi(line.c_str());
    if (0 < pwm && pwm < PWMRANGE) {
        client.print("read: ");
        client.println(pwm);
    }
    analogWrite(2, PWMRANGE - pwm);
    */
}
