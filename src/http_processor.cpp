#include "http_processor.hpp"

Luvitronics::HttpProcessor::~HttpProcessor() {}

bool Luvitronics::HttpProcessor::process(const Luvitronics::HttpRequest& request, HttpResponse& response)
{
    if (request.type() == HttpRequest::Type::Get)
        return processGet(request, response);
    else if (request.type() == HttpRequest::Type::Post)
        return processPost(request, response);
    else if (request.type() == HttpRequest::Type::Put)
        return processPut(request, response);
    else if (request.type() == HttpRequest::Type::Patch)
        return processPatch(request, response);
    else if (request.type() == HttpRequest::Type::Delete)
        return processDelete(request, response);
    
    return false;
}

bool Luvitronics::HttpProcessor::defaultProcessHandler(const Luvitronics::HttpRequest& request, HttpResponse& response)
{
    response = 405;
    return true;
}

bool Luvitronics::HttpProcessor::processGet(const Luvitronics::HttpRequest& request, HttpResponse& response)
{
    return defaultProcessHandler(request, response);
}

bool Luvitronics::HttpProcessor::processPost(const Luvitronics::HttpRequest& request, HttpResponse& response)
{
    return defaultProcessHandler(request, response);
}

bool Luvitronics::HttpProcessor::processPut(const Luvitronics::HttpRequest& request, HttpResponse& response)
{
    return defaultProcessHandler(request, response);
}

bool Luvitronics::HttpProcessor::processPatch(const Luvitronics::HttpRequest& request, HttpResponse& response)
{
    return defaultProcessHandler(request, response);
}

bool Luvitronics::HttpProcessor::processDelete(const Luvitronics::HttpRequest& request, HttpResponse& response)
{
    return defaultProcessHandler(request, response);
}
