#include "dimmer_info_http_processor.hpp";

Luvitronics::DimmerInfoHttpProcessor::DimmerInfoHttpProcessor()
    : Luvitronics::HttpProcessor() {}

bool Luvitronics::DimmerInfoHttpProcessor::processGet(const Luvitronics::HttpRequest&, HttpResponse& response)
{
    response = 200;
    
    response << "Core version: ";
    response << ESP.getCoreVersion() << "\r\n";
    response << "Chip id: ";
    response << ESP.getChipId() << "\r\n";
    response << "Flash size: ";
    response << ESP.getFlashChipSize() << "\r\n";
    response << "Flash speed: ";
    response << ESP.getFlashChipSpeed() << "\r\n";
    response << "CPU frequency (MHz): ";
    response << ESP.getCpuFreqMHz() << "\r\n";
    response << "free memory: ";
    response << ESP.getFreeSketchSpace() << "\r\n";
    response << "Free heap: ";
    response << ESP.getFreeHeap() << "\r\n";
}
