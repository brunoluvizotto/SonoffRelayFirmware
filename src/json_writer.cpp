#include "json_writer.hpp"

Luvitronics::JsonWriter::JsonWriter(Luvitronics::HttpResponse& response)
    : _response(response), _empty(true), _initialized(false)
{
}

Luvitronics::JsonWriter::~JsonWriter()
{
    if (!_initialized)
        _response = 200;
    
    if (!_empty)
        _response << '}';
}
