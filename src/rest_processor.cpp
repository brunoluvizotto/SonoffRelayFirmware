#include "rest_processor.hpp"

Luvitronics::RestProcessor::~RestProcessor() {}

bool Luvitronics::RestProcessor::process(const Luvitronics::HttpRequest& request,
                                         Luvitronics::HttpResponse& response)
{
    if (!objectValidator(request.object())) {
        JsonWriter json(response);
        using std::make_pair;
        json = 404;
        json << make_pair("error", "object not found");
        json << make_pair("object", request.object());
        return true;
    }
    
    JsonWriter json(response);
    if (request.type() == HttpRequest::Type::Get)
        return processGet(request.object(), json);
    else if (request.type() == HttpRequest::Type::Post)
        return processPost(request.object(), json);
    else if (request.type() == HttpRequest::Type::Put)
        return processPut(request.object(), json);
    else if (request.type() == HttpRequest::Type::Patch)
        return processPatch(request.object(), json);
    else if (request.type() == HttpRequest::Type::Delete)
        return processDelete(request.object(), json);
    
    return false;
}

bool Luvitronics::RestProcessor::objectValidator(const String&)
{
    return false;
}

bool Luvitronics::RestProcessor::defaultProcessHandler(const String&, Luvitronics::JsonWriter& response)
{
    response = 405;
    return true;
}

bool Luvitronics::RestProcessor::processGet(const String& object, Luvitronics::JsonWriter& response)
{
    defaultProcessHandler(object, response);
}

bool Luvitronics::RestProcessor::processPost(const String& object, Luvitronics::JsonWriter& response)
{
    defaultProcessHandler(object, response);
}

bool Luvitronics::RestProcessor::processPut(const String& object, Luvitronics::JsonWriter& response)
{
    defaultProcessHandler(object, response);
}

bool Luvitronics::RestProcessor::processPatch(const String& object, Luvitronics::JsonWriter& response)
{
    defaultProcessHandler(object, response);
}

bool Luvitronics::RestProcessor::processDelete(const String& object, Luvitronics::JsonWriter& response)
{
    defaultProcessHandler(object, response);
}
