#include "http_response.hpp"

Luvitronics::HttpResponse::HttpResponse(WiFiClient& printer)
    : _printer(printer), _header_printed(false)
{
    _status_headers[200] = "200 OK";
    _status_headers[404] = "404 Not Found";
    _status_headers[405] = "405 Method Not Allowed";
    _status_headers[500] = "500 Internal Server Error";
    _status_headers[501] = "501 Not Implemented";
    _status_headers[503] = "503 Service Unavailable";
}

Luvitronics::HttpResponse::~HttpResponse()
{
    _printer.flush();
    _printer.stop();
}
