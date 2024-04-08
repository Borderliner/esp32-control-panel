#pragma once
#include <ESPAsyncWebServer.h>

#include "handlers/home_page_handler.h"
#include "handlers/temperature_page_handler.h"
#include "handlers/led_page_handler.h"
#include "handlers/not_found_page_handler.h"

namespace application::routing {
void register_routes(AsyncWebServer &server) {
    // Serve the specified HTML pages
    server.on("/", HTTP_GET, home_page_handler);
    server.on("/temperature", HTTP_GET, temperature_page_handler);
    server.on("/led", HTTP_GET, led_page_handler);
    server.on("/restart", HTTP_GET, [](AsyncWebServerRequest *request) {
        esp_restart();
    });
    server.on("/turn_off", HTTP_GET, [](AsyncWebServerRequest *request) {
        esp_deep_sleep_start();
    });
    // 404 and 405 error handler
    server.onNotFound(not_found_page_handler);
}
}  // namespace server::router
