#ifndef REQUEST_PROCESSOR_HPP
#define REQUEST_PROCESSOR_HPP

#include "http_request.hpp"
#include "http_response.hpp"

namespace Luvitronics
{
    class RequestProcessor
    {
        public:
            virtual bool process(const HttpRequest& request, HttpResponse& response) = 0;
    };
}

#endif
