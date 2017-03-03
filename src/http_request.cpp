#include "http_request.hpp"

Luvitronics::HttpRequest::HttpRequest(const Luvitronics::HttpRequest::Type type,
                                      const String& path,
                                      const String& object,
                                      const String& version,
                                      const Luvitronics::HttpRequest::QueryString& queryString,
                                      const Luvitronics::HttpRequest::Options& options,
                                      const String& body)
    : _type(type), _path(path), _object(object), _version(version),
      _queryString(queryString), _options(options), _body(body) {}
      
std::unique_ptr<Luvitronics::HttpRequest> Luvitronics::HttpRequest::create(Stream& input)
{
    String path, object, version;
    Type method;
    auto data(input.readStringUntil('\n'));
    parseRequestLine(data, method, path, object, version);
    
    if (method == HttpRequest::Type::Invalid)
        return std::unique_ptr<HttpRequest>(new HttpRequest(method));
    
    Options options;
    for (data = input.readStringUntil('\n'); data != "\r"; data = input.readStringUntil('\n'))
        parseOption(data, options);
    
    String body;
    data = input.readString();
    parseBody(data, body);
    
    return std::unique_ptr<HttpRequest>(new HttpRequest(method, path, object, version,
                                                        QueryString(), options, body));
}

