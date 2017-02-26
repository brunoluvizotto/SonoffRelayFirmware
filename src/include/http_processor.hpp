#ifndef HTTP_PROCESSOR_HPP
#define HTTP_PROCESSOR_HPP

#include <Arduino.h>

#include "request_processor.hpp"

namespace Luvitronics
{
    class HttpProcessor : public RequestProcessor
    {
    public:
        HttpProcessor() : RequestProcessor() {}
        virtual ~HttpProcessor() = 0;
        
        virtual bool process(const HttpRequest& request, HttpResponse& response) override;
        
    protected:
        virtual bool processGet(const HttpRequest& request, HttpResponse& response);
        virtual bool processPost(const HttpRequest& request, HttpResponse& response);
        virtual bool processPut(const HttpRequest& request, HttpResponse& response);
        virtual bool processPatch(const HttpRequest& request, HttpResponse& response);
        virtual bool processDelete(const HttpRequest& request, HttpResponse& response);
        
        virtual bool defaultProcessHandler(const HttpRequest& request, HttpResponse& response);
    };
}

#endif //HTTP_PROCESSOR_HPP
