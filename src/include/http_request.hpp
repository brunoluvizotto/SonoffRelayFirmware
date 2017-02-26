#ifndef HTTP_REQUEST_HPP
#define HTTP_REQUEST_HPP

#include <Arduino.h>

#include <map>
#include <memory>

namespace Luvitronics
{
    class HttpRequest
    {
    public:
        typedef std::map<std::string,std::string> QueryString;
        enum class Type { Get, Post, Put, Patch, Delete, Invalid };
        
        static std::unique_ptr<HttpRequest> create(const String& input);
        
        const Type type() const { return _type; };
        const String& path() const { return _path; }
        const String& object() const { return _object; }
        const String& version() const { return _version; }
        const QueryString queryString() const { return _queryString; }
        
    protected:
        HttpRequest(const Type type, const String& path = "", const String& object = "",
                    const String& version = "", const QueryString& queryString = QueryString());
        
    private:
        Type _type;
        const String _path;
        const String _object;
        const String _version;
        const QueryString _queryString;
    };
}

#endif //HTTP_REQUEST_HPP
