#ifndef UTILS_HPP
#define UTILS_HPP

#include <Arduino.h>
#include <map>

namespace Luvitronics
{
    namespace Utils
    {
        inline String processFullPath(String& path) 
        {
            auto objectIndex = path.lastIndexOf('/');
            String object = path.substring(objectIndex +1);
            path = path.substring(0, objectIndex);
            return object;
        }
        
        inline bool isInt(String s)
        {
            for (size_t i = 0; i < s.length(); ++i) {
                if (s[i] < '0' || s[i] > '9')
                    return false;
            }
            
            return true;
        }
    }
}

#endif
