#pragma once
#include "templates/pages/temperature.h"

#include <ESPAsyncWebServer.h>

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
    String html = page_temperature.compile_template_and_replace(
        String("{TEMPERATURE_VALUE}"),
        String(temperature));  // Use the HTML content from the
                                // temperature.h file

    request->send(200, "text/html", html);
}

