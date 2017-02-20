#ifndef HTTP_REQUEST_HPP
#define HTTP_REQUEST_HPP

#include <Arduino.h>

namespace Luvitronics
{
    class HttpRequest
    {
    public:
        static Luvitronics::HttpRequest create(const String& input);
        
        const String method() { return _method; }
        const String path() { return _path; }
        const String version() { return _version; }
        const bool& valid() { return _valid; }
        
    private:
        HttpRequest(const String& method, const String& path,
                    const String& version, const bool& valid = true);
        
        String _method;
        String _path;
        String _version;
        bool _valid;
    };
}

#endif //HTTP_REQUEST_HPP
