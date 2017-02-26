#ifndef HTTP_PROCESSOR_PIN
#define HTTP_PROCESSOR_PIN

#include "rest_processor.hpp"

namespace Luvitronics
{
    class RestProcessorPin : public RestProcessor
    {
    public:
        RestProcessorPin() {};
        
    protected:
        bool processGet(const String& object, JsonWriter& response) override;
        bool processPut(const String& object, JsonWriter& response) override;
        bool objectValidator(const String& object) override;
    };
}

#endif //HTTP_PROCESSOR_PIN