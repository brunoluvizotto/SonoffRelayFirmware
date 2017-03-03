#ifndef REST_PROCESSOR_HPP
#define REST_PROCESSOR_HPP

#include <Arduino.h>

#include "http_processor.hpp"
#include "http_response.hpp"

namespace Luvitronics
{
    class RestProcessor : public HttpProcessor
    {
    public:
        RestProcessor() : HttpProcessor() {}
        virtual ~RestProcessor() = 0;
        
        virtual bool process(const HttpRequest& request, HttpResponse& response) override;
        
    protected:
        virtual bool processGet(const HttpRequest& request, HttpResponse& response) override;
        virtual bool processPost(const HttpRequest& request, HttpResponse& response) override;
        virtual bool processPut(const HttpRequest& request, HttpResponse& response) override;
        virtual bool processPatch(const HttpRequest& request, HttpResponse& response) override;
        virtual bool processDelete(const HttpRequest& request, HttpResponse& response) override;
        
        virtual bool defaultProcessHandler(const HttpRequest& request, HttpResponse& response) override;
        
        virtual bool objectValidator(const String& request);
    };
}

#endif // REST_PROCESSOR_HPP
