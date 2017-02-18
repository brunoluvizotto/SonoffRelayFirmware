#include <vector>
#include <memory>

#include "dimmer_wifi.hpp"
#include "dimmer_updater.hpp"
#include "dimmer_listerner.hpp"

using namespace Luvitronics;
std::vector<std::unique_ptr<Task>> tasks;

void setup() {
    Luvitronics::Task* ts[] = {
        new DimmerWifi(),
        new DimmerUpdater(),
        new DimmerListener(80)
    };
    for (auto t : ts) tasks.emplace_back(t);
    
    pinMode(0, INPUT);
    pinMode(2, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);

    analogWriteFreq(15000); //Hz
}

void loop() {
    for (auto& task : tasks)
        task->process();
}
