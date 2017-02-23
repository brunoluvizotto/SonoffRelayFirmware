#ifndef HTTP_PROCESSOR_HPP
#define HTTP_PROCESSOR_HPP

#include <Arduino.h>

#include "http_response.hpp"
#include "http_request.hpp"

namespace Luvitronics
{
    class HttpProcessor
    {
    public:
        HttpProcessor();
        virtual ~HttpProcessor() = 0;
        
        bool process(const HttpRequest& request, HttpResponse& response);
        
    protected:
        virtual bool processGet(const HttpRequest& request, HttpResponse& response);
        virtual bool processPost(const HttpRequest& request, HttpResponse& response);
        virtual bool processPut(const HttpRequest& request, HttpResponse& response);
        virtual bool processPatch(const HttpRequest& request, HttpResponse& response);
        virtual bool processDelete(const HttpRequest& request, HttpResponse& response);
        
    private:
        bool defaultProcessHandler(const HttpRequest& request, HttpResponse& response);
    };
}

#endif //HTTP_PROCESSOR_HPP
