#include <vector>
#include <memory>

#include "dimmer_pins.hpp"
#include "dimmer_wifi.hpp"
#include "dimmer_updater.hpp"
#include "dimmer_listerner.hpp"

using namespace Luvitronics;
std::vector<std::unique_ptr<Task>> tasks;

void setup() {
    Luvitronics::Task* ts[] = {
        new DimmerPins(),
        new DimmerWifi(),
        new DimmerUpdater(),
        new DimmerListener(80)
    };
    for (auto t : ts) tasks.emplace_back(t);
}

void loop() {
    for (auto& task : tasks)
        task->process();
}
