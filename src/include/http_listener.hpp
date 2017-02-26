#ifndef HTTP_LISTENER_HPP
#define HTTP_LISTENER_HPP

#include "task.hpp"
#include "request_processor.hpp"

#include <ESP8266WiFi.h>

#include <map>
#include <memory>

namespace Luvitronics
{
    class HttpListener : public Task
    {
        typedef std::map<String, std::unique_ptr<RequestProcessor>> Repository;
            
    public: 
        
        HttpListener(uint16_t port);
        
        virtual void process() override;
        
        void registerProcessor(String endpoint, std::unique_ptr<RequestProcessor>& processor);
        void registerProcessor(String endpoint, RequestProcessor* processor);
        
    private:
        WiFiServer _server;
        Repository _processorMap;
    };
}

#endif //HTTP_LISTENER_HPP
