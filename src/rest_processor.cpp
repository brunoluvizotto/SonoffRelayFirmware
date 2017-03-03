#include "rest_processor.hpp"
#include "json_writer.hpp"

Luvitronics::RestProcessor::~RestProcessor() {}

bool Luvitronics::RestProcessor::process(const Luvitronics::HttpRequest& request,
                                         Luvitronics::HttpResponse& response)
{
    if (!objectValidator(request.object())) {
        JsonWriter json(response);
        using std::make_pair;
        json = 404;
        json << make_pair("error", "request not found");
        json << make_pair("request", request.object());
        return true;
    }
    
    HttpResponse json(response);
    if (request.type() == HttpRequest::Type::Get)
        return processGet(request, json);
    else if (request.type() == HttpRequest::Type::Post)
        return processPost(request, json);
    else if (request.type() == HttpRequest::Type::Put)
        return processPut(request, json);
    else if (request.type() == HttpRequest::Type::Patch)
        return processPatch(request, json);
    else if (request.type() == HttpRequest::Type::Delete)
        return processDelete(request, json);
    
    return false;
}

bool Luvitronics::RestProcessor::objectValidator(const String&)
{
    return false;
}

bool Luvitronics::RestProcessor::defaultProcessHandler(const HttpRequest&, Luvitronics::HttpResponse& response)
{
    response = 405;
    return true;
}

bool Luvitronics::RestProcessor::processGet(const HttpRequest& request, Luvitronics::HttpResponse& response)
{
    defaultProcessHandler(request, response);
}

bool Luvitronics::RestProcessor::processPost(const HttpRequest& request, Luvitronics::HttpResponse& response)
{
    defaultProcessHandler(request, response);
}

bool Luvitronics::RestProcessor::processPut(const HttpRequest& request, Luvitronics::HttpResponse& response)
{
    defaultProcessHandler(request, response);
}

bool Luvitronics::RestProcessor::processPatch(const HttpRequest& request, Luvitronics::HttpResponse& response)
{
    defaultProcessHandler(request, response);
}

bool Luvitronics::RestProcessor::processDelete(const HttpRequest& request, Luvitronics::HttpResponse& response)
{
    defaultProcessHandler(request, response);
}
