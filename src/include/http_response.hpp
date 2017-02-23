#ifndef HTTP_RESPONSE_HPP
#define HTTP_RESPONSE_HPP

#include <Arduino.h>
#include <WiFiClient.h>

#include <map>

namespace Luvitronics
{
    class HttpResponse
    {
    public:
        HttpResponse(WiFiClient& printer);
        ~HttpResponse();
        
        template<typename T>
        HttpResponse& operator<<(T data)
        {
            if (!_header_printed)
                *this = 500;
                
            _printer.print(data);
            return *this;
        }
        
        HttpResponse& operator=(int http_status)
        {
            _header_printed = true;
            auto header = _status_headers.find(http_status);
            *this << "HTTP/1.1 ";
            *this << (header != _status_headers.end() ? header->second : _status_headers[500]);
            *this << "\r\n\r\n";
            return *this;
        }
        
    private:
        std::map<uint, String> _status_headers;
        WiFiClient& _printer;
        bool _header_printed;
    };
}

#endif //HTTP_RESPONSE_HPP
