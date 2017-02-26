#include "dimmer_info_http_processor.hpp";
#include "json_writer.hpp"

Luvitronics::DimmerInfoHttpProcessor::DimmerInfoHttpProcessor()
    : Luvitronics::HttpProcessor() {}

bool Luvitronics::DimmerInfoHttpProcessor::processGet(const Luvitronics::HttpRequest&, HttpResponse& response)
{
    JsonWriter json(response);
    
    using std::make_pair;
    json << make_pair("core_version:", ESP.getCoreVersion());
    json << make_pair("chip_id:", ESP.getChipId());
    json << make_pair("flash_size:", ESP.getFlashChipSize());
    json << make_pair("flash_speed:", ESP.getFlashChipSpeed());
    json << make_pair("cpu_frequency:", ESP.getCpuFreqMHz());
    json << make_pair("free_memory:", ESP.getFreeSketchSpace());
    json << make_pair("free_heap:", ESP.getFreeHeap());
    
    return true;
}
