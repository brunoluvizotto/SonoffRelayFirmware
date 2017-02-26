#include "rest_processor_pin.hpp"
#include "pin.hpp"
#include "utils.hpp"

bool Luvitronics::RestProcessorPin::objectValidator(const String& object)
{
    return Utils::isInt(object);
}

bool Luvitronics::RestProcessorPin::processGet(const String& object,
                                               Luvitronics::JsonWriter& response)
{
    const auto i = object.toInt();
    
    using std::make_pair;
    if (i >= NUM_DIGITAL_PINS) {
        response = 404;
        response << make_pair("error", "Pin out of range");
        response << make_pair("pin", i);
        response << make_pair("max_pin_value", NUM_DIGITAL_PINS);
        return true;
    }
    
    Pin pin(i);
    
    response = 200;
    response << make_pair("mode", pin.mode() == INPUT ? "input" : "output");
    response << make_pair("state", pin.state() == HIGH ? "high" : "low");
    
    return true;
}

bool Luvitronics::RestProcessorPin::processPut(const String& object,
                                               Luvitronics::JsonWriter& response)
{
    response = 501;
    return false;
    
    const auto i = object.toInt();
    
    using std::make_pair;
    if (i >= NUM_DIGITAL_PINS) {
        response = 404;
        response << make_pair("error", "Pin out of range");
        response << make_pair("pin", i);
        response << make_pair("max_pin_value", NUM_DIGITAL_PINS -1);
        return true;
    }
    
    Pin pin(i);
    
    response = 200;
    response << make_pair("mode", pin.mode() == INPUT ? "input" : "output");
    response << make_pair("state", pin.state() == HIGH ? "high" : "low");
    
    return true;
}
