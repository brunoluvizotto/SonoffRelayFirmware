#include <vector>
#include <memory>

#include "dimmer_wifi.hpp"
#include "dimmer_updater.hpp"
#include "dimmer_listerner.hpp"

std::vector<std::unique_ptr<Luvitronics::Task>> tasks;

void setup() {
    tasks.emplace_back(new Luvitronics::DimmerWifi());
    tasks.emplace_back(new Luvitronics::DimmerUpdater());
    tasks.emplace_back(new Luvitronics::DimmerListener(80));
    
    pinMode(0, INPUT);
    pinMode(2, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);

    analogWriteFreq(15000); //Hz
}

void loop() {
    for (auto& task : tasks)
        task->process();
}
