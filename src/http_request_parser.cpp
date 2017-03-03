#include "http_request.hpp"
#include "utils.hpp"

namespace {
    inline void go_to_next_line(const String& input, size_t& i)
    {
        for (;input[i] != '\n' && i < input.length(); ++i);
        ++i;
    }
    
    inline int find(char c, const String& input, size_t from = 0, size_t limit = 0)
    {
        auto& i = from;
        
        if (limit == 0)
            limit = input.length() -1;
        
        for (; input[i] != c && i < limit; ++i);
        return i;
    }
    
    inline size_t end_of_line(const String& input, size_t from = 0, size_t limit = 0)
    {
        auto& i = from;
        
        i = find ('\n', input, from, limit);
             
        if (i == 0)
            return 0;
        
        if (input[i -1] == '\r')
            return i -1;
        
        return i;
    }
}

void Luvitronics::HttpRequest::parseRequestLine(const String& input, Type& method,
                                                String& path, String& object, String& version)
{
    unsigned separator_count = 0;
    size_t last_separator;
    bool in_separator = false;
    size_t i = 0;
    
    for (i = 0; i < input.length(); ++i) {
        if (in_separator && input[i] != ' ')
            in_separator = false;
        
        if (!in_separator && (input[i] == ' ' || input[i] == '\r')) {
            in_separator = true;
            
            if (++separator_count == 1) {
                String data = input.substring((size_t)0, i);
                
                if (data.equalsIgnoreCase("Get"))
                    method = Type::Get;
                else if (data.equalsIgnoreCase("Post"))
                    method = Type::Post;
                else if (data.equalsIgnoreCase("Put"))
                    method = Type::Put;
                else if (data.equalsIgnoreCase("Patch"))
                    method = Type::Patch;
                else if (data.equalsIgnoreCase("Delete"))
                    method = Type::Delete;
                else {
                    method = Type::Invalid;
                    return;
                }
            }
            else if (separator_count == 2) {
                path = input.substring(last_separator +1, i);
                object = Utils::processFullPath(path);
            }
            else if (separator_count == 3) {
                version = input.substring(last_separator +1, i);
                go_to_next_line(input, i);
                break;
            }
        }
        
        if (in_separator)
            last_separator = i;
    }
}

void Luvitronics::HttpRequest::parseOption(const String& input, Options& options)
{
    size_t i = 0;
    
    auto separatorIndex = find(':', input);
    if (separatorIndex == input.length() -1)
        return;
    
    size_t eol;
    for (eol = input.length() -1; eol > 0 && (input[eol] == '\r' || input[eol] == '\n'); --eol);
    
    auto key(input.substring(i, separatorIndex));
    auto value(input.substring(separatorIndex +1, eol +1));
    options.emplace(key, value);
}

void Luvitronics::HttpRequest::parseBody(const String& input, String& body)
{
    body = input;
}
