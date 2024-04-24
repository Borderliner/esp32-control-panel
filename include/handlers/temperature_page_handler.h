#pragma once
#include "views/pages/temperature.h"

#include <ESPAsyncWebServer.h>
#include <application/templating/page_data.h>

using application::templating::PageDataJson;

float getTemperature() {
    // YOUR SENSOR IMPLEMENTATION HERE
    // simulate the temperature value
    float temp_x100 = random(0, 10000);  // a ramdom value from 0 to 10000
    return temp_x100 / 100;  // return the simulated temperature value from 0 to
                             // 100 in float
}

void temperature_page_handler(AsyncWebServerRequest *request) {
    Serial.println("Web Server: temperature page");
    float temperature = getTemperature();
    
    PageDataJson data;
    data["TEMPERATURE_VALUE"] = String(temperature);

    String html = page_temperature.render_with_json(data);
    request->send(200, "text/html", html);
}
