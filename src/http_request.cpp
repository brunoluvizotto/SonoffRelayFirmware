#include "http_request.hpp"

Luvitronics::HttpRequest::HttpRequest(const String& method, const String& path,
                                      const String& version, const bool& valid)
    : _method(method), _path(path), _version(version), _valid(valid) {}

Luvitronics::HttpRequest Luvitronics::HttpRequest::create(const String& input)
{
    unsigned separator_count = 0;
    size_t last_separator;
    bool in_separator = false;
    String method, path, version;
    
    for (size_t i = 0; i < input.length(); ++i) {
        if (in_separator && input[i] != ' ') {
            in_separator = false;
            continue;
        }
        
        if (!in_separator && (input[i] == ' ' || input[i] == '\r')) {
            in_separator = true;
            
            switch (++separator_count) {
                case 1:
                    method = input.substring(0, i);
                    break;
                case 2:
                    path = input.substring(last_separator +1, i);
                    break;
                case 3:
                    version = input.substring(last_separator +1, i);
                    break;
                default:
                    return HttpRequest(method, path, version, false);
                    break;
            }
            last_separator = i;
        }
    }
    
    return HttpRequest(method, path, version);
}

