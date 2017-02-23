#include "http_request.hpp"

Luvitronics::HttpRequest::HttpRequest(const Luvitronics::HttpRequest::Type type,
                                      const String& path,
                                      const String& version,
                                      const Luvitronics::HttpRequest::QueryString& queryString)
    : _type(type), _path(path), _version(version), _queryString(queryString)
{
}

std::unique_ptr<Luvitronics::HttpRequest> Luvitronics::HttpRequest::create(const String& input)
{
    unsigned separator_count = 0;
    size_t last_separator;
    bool in_separator = false;
    String method, path, version;
    
    for (size_t i = 0; i < input.length(); ++i) {
        if (in_separator && input[i] != ' ')
            in_separator = false;
        
        if (!in_separator && (input[i] == ' ' || input[i] == '\r')) {
            in_separator = true;
            
            if (++separator_count == 1)
                method = input.substring(0, i);
            else if (separator_count == 2)
                path = input.substring(last_separator +1, i);
            else if (separator_count == 3)
                version = input.substring(last_separator +1, i);
            else
                break;
        }
        
        if (in_separator)
            last_separator = i;
    }
    
    Type type;
    if (method.equalsIgnoreCase("Get"))
        type = Type::Get;
    else if (method.equalsIgnoreCase("Post"))
        type = Type::Post;
    else if (method.equalsIgnoreCase("Put"))
        type = Type::Put;
    else if (method.equalsIgnoreCase("Patch"))
        type = Type::Patch;
    else if (method.equalsIgnoreCase("Delete"))
        type = Type::Delete;
    else
        type = Type::Invalid;
    
    return std::unique_ptr<HttpRequest>(new HttpRequest(type, path, version));
}

