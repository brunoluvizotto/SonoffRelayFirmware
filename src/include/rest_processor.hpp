#ifndef REST_PROCESSOR_HPP
#define REST_PROCESSOR_HPP

#include <Arduino.h>

#include "request_processor.hpp"
#include "json_writer.hpp"

namespace Luvitronics
{
    class RestProcessor : public RequestProcessor
    {
    public:
        RestProcessor() : RequestProcessor() {}
        virtual ~RestProcessor() = 0;
        
        virtual bool process(const HttpRequest& request, HttpResponse& response) override;
        
    protected:
        virtual bool processGet(const String& object, JsonWriter& response);
        virtual bool processPost(const String& object, JsonWriter& response);
        virtual bool processPut(const String& object, JsonWriter& response);
        virtual bool processPatch(const String& object, JsonWriter& response);
        virtual bool processDelete(const String& object, JsonWriter& response);
        
        virtual bool objectValidator(const String& object);
        
        virtual bool defaultProcessHandler(const String& object, JsonWriter& response);
    };
}

#endif // REST_PROCESSOR_HPP
