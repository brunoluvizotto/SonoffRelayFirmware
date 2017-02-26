#ifndef JSON_RESPONSE_HPP
#define JSON_RESPONSE_HPP

#include "http_response.hpp"

namespace Luvitronics
{
    class JsonWriter
    {
    public:
        JsonWriter(HttpResponse& response);
        ~JsonWriter();
        
        template<typename T>
        JsonWriter& operator=(const T status)
        {
            _response = status;
            _initialized = true;
        }
        
        template<typename T, typename U>
        JsonWriter& operator<<(const std::pair<T, U>& pair)
        {
            if (!_initialized)
                _response = 500;
                
            _response << (_empty ? '{' : ',');
            
            _response << '"' << (valid_key(pair.first) ? pair.first : "INVALID_KEY")
                << "\":\"" << pair.second << '"';
            _empty = false;
        }
        
    private:
        HttpResponse& _response;
        bool _empty;
        bool _initialized;
        
        bool valid_key(const String& key)
        {
            for (size_t i = 0; i < key.length(); ++i) {
                if ('0' <= key[i] || key[i] <= '9')
                    return true;
                if ('A' <= key[i] || key[i] <= 'z')
                    return true;
                
                return false;
            }
        }
    };
}

#endif
