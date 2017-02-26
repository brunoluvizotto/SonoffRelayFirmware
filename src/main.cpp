#include <vector>
#include <memory>

#include "dimmer_pins.hpp"
#include "dimmer_wifi.hpp"
#include "dimmer_updater.hpp"
#include "http_listener.hpp"

#include "dimmer_info_http_processor.hpp"
#include "rest_processor_pin.hpp"

using namespace Luvitronics;
std::vector<Task*> tasks;

void setup() {
    auto listener = new HttpListener(80);
    listener->registerProcessor("/info", new DimmerInfoHttpProcessor());
    listener->registerProcessor("/pins", new RestProcessorPin());
    
    Luvitronics::Task* ts[] = {
        new DimmerPins(),
        new DimmerWifi(),
        new DimmerUpdater(),
        listener
    };
    for (auto t : ts) tasks.push_back(t);
}

void loop() {
    for (auto& task : tasks)
        task->process();
}
