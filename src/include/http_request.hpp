#ifndef HTTP_REQUEST_HPP
#define HTTP_REQUEST_HPP

#include <Arduino.h>
#include <Stream.h>

#include <memory>
#include <map>

namespace Luvitronics
{
    class HttpRequest
    {
    public:
        using QueryString = std::map<String, String>;
        using Options = std::map<String, String>;
        enum class Type { Get, Post, Put, Patch, Delete, Invalid };
        
        static std::unique_ptr<HttpRequest> create(Stream& input);
        
        const Type type() const { return _type; };
        const String& path() const { return _path; }
        const String& object() const { return _object; }
        const String& version() const { return _version; }
        const Options& options() const { return _options; }
        const QueryString& queryString() const { return _queryString; }
        const String& body() const { return _body; }
        
    protected:
        HttpRequest(const Type type, const String& path = "", const String& object = "",
                    const String& version = "", const QueryString& queryString = QueryString(),
                    const Options& options = Options(), const String& body = "");
        
    private:
        Type _type;
        const String _path;
        const String _object;
        const String _version;
        const QueryString _queryString;
        const Options _options;
        const String _body;
        
        static void parseRequestLine(const String& input, Type& method,
                              String& path, String& object, String& version);
        static void parseOption(const String& input, Options& options);
        static void parseBody(const String& input, String& body);
    };
}

#endif //HTTP_REQUEST_HPP
