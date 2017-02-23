#ifndef DIMMER_INFO_HTTP_PROCESSOR_HPP
#define DIMMER_INFO_HTTP_PROCESSOR_HPP

#include "http_processor.hpp"
#include "http_response.hpp"

namespace Luvitronics
{
    class DimmerInfoHttpProcessor : public HttpProcessor
    {
    public:
        DimmerInfoHttpProcessor();
        virtual ~DimmerInfoHttpProcessor() {}
        
    protected:
        bool processGet(const Luvitronics::HttpRequest&, HttpResponse& response) override;
    };
}

#endif // DIMMER_INFO_HTTP_PROCESSOR_HPP
