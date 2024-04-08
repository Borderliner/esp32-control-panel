#pragma once
#include "views/pages/home.h"

#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

using application::templating::PageDataJson;

const float MAXIMUM_DRAM_SIZE = 160.00f;

float round_float_to_two(float value) {
    return ((int)(value * 100 + .5) / 100.0);
}

void home_page_handler(AsyncWebServerRequest *request) {
    Serial.println("Web Server: home page");
    float heap_used_size = MAXIMUM_DRAM_SIZE - (float(esp_get_free_heap_size()) / 1000.0f);
    float heap_maximum_used_size = MAXIMUM_DRAM_SIZE - (float(esp_get_minimum_free_heap_size()) / 1000.0f);
    float heap_ratio = heap_used_size / MAXIMUM_DRAM_SIZE * 100;

    PageDataJson data;
    data["HEAP_TOTAL_SIZE"] = String(MAXIMUM_DRAM_SIZE, 2).c_str();
    data["HEAP_USED_SIZE"] = String(heap_used_size, 2).c_str();
    data["HEAP_MAXIMUM_USED_SIZE"] = String(heap_maximum_used_size, 2).c_str();
    data["HEAP_RATIO"] = int(heap_ratio);

    float spiffs_total_size_kbytes = SPIFFS.totalBytes() / 1000;
    float spiffs_used_size_kbytes = SPIFFS.usedBytes() / 1000;
    float spiffs_ratio = spiffs_used_size_kbytes / spiffs_total_size_kbytes * 100;

    data["SPIFFS_TOTAL_SIZE"] = String(String(int(spiffs_total_size_kbytes / 1000)) + String(",") + String(static_cast<int>(spiffs_total_size_kbytes) % 1000) + String(".00")).c_str();
    data["SPIFFS_USED_SIZE"] = String(spiffs_used_size_kbytes, 2).c_str();
    data["SPIFFS_RATIO"] = int(spiffs_ratio);
    String html = page_home.render_with_json(data);
    request->send(200, "text/html", html);
}
