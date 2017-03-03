#include "rest_processor_pin.hpp"
#include "pin.hpp"
#include "utils.hpp"
#include "json_writer.hpp"

bool Luvitronics::RestProcessorPin::objectValidator(const String& object)
{
    return Utils::isInt(object);
}

bool Luvitronics::RestProcessorPin::processGet(const HttpRequest& request,
                                               Luvitronics::HttpResponse& response)
{
    const auto& object = request.object();
    const auto i = object.toInt();
    JsonWriter json(response);
    
    using std::make_pair;
    if (i >= NUM_DIGITAL_PINS) {
        json = 404;
        json << make_pair("error", "Pin out of range");
        json << make_pair("pin", i);
        json << make_pair("max_pin_value", NUM_DIGITAL_PINS -1);
        return true;
    }
    
    Pin pin(i);
    
    json = 200;
    json << make_pair("mode", pin.mode() == INPUT ? "input" : "output");
    json << make_pair("state", pin.state() == HIGH ? "high" : "low");
    
    return true;
}

bool Luvitronics::RestProcessorPin::processPut(const HttpRequest& request,
                                               Luvitronics::HttpResponse& response)
{
    const auto& object = request.object();
    const auto i = object.toInt();
    JsonWriter json(response);
    
    using std::make_pair;
    if (i >= NUM_DIGITAL_PINS) {
        json = 404;
        json << make_pair("error", "Pin out of range");
        json << make_pair("pin", i);
        json << make_pair("max_pin_value", NUM_DIGITAL_PINS -1);
        return true;
    }
    
    Pin pin(i);
    
    // Ugly incorrect innacurate parse
    // TODO: create a decent parser
    auto modeIndex = object.indexOf("mode");
    auto modeValueIndex = object.indexOf(':', modeIndex);
    auto modeValueEndIndex = object.indexOf('}', modeValueIndex);
    auto modeValue = object.substring(modeValueIndex +1, modeValueEndIndex);
    json = 501;
    json << make_pair("read:", modeValue);
    return true;
    
    json = 200;
    json << make_pair("mode", pin.mode() == INPUT ? "input" : "output");
    json << make_pair("state", pin.state() == HIGH ? "high" : "low");
    
    return true;
}
