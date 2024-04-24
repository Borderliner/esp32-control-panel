#pragma once
#include "views/pages/temperature.h"
#include "sensors/temp_humid_bme280.h"

#include <ESPAsyncWebServer.h>
#include <application/templating/page_data.h>

using application::templating::PageDataJson;

void temperature_page_handler(AsyncWebServerRequest *request) {
    Serial.println("Web Server: temperature page");
    
    PageDataJson data;
    /* float temp = application::sensor::bme280->read_temperature();
    float humidity = application::sensor::bme280->read_humidity();
    float pressure = application::sensor::bme280->read_pressure();
    float altitude = application::sensor::bme280->read_altitude();

    float pressure_ratio = pressure * 100.0 / 1100.0;
    float altitude_ratio = altitude * 100.0 / 8850.0;

    data["TEMPERATURE_VALUE"] = temp;

    data["HUMIDITY_VALUE"] = humidity;

    data["PRESSURE_VALUE"] = pressure;
    data["PRESSURE_RATIO"] = pressure_ratio;

    data["ALTITUDE_VALUE"] = altitude;
    data["ALTITUDE_RATIO"] = altitude_ratio; */

    String html = page_temperature.render_with_json(data);
    request->send(200, "text/html", html);
}

void bme280_get_handler(AsyncWebServerRequest *request) {
    float temp = application::sensor::bme280->read_temperature();
    float humidity = application::sensor::bme280->read_humidity();
    float pressure = application::sensor::bme280->read_pressure() / 100;
    float altitude = application::sensor::bme280->read_altitude();

    float pressure_ratio = pressure * 100.0 / 1100.0;
    float altitude_ratio = altitude * 100.0 / 8850.0;

    nlohmann::json data = {
        { "temperature", temp },
        { "humidity", humidity },
        { "pressure", pressure },
        { "altitude", altitude },
        { "pressure_ratio", pressure_ratio },
        { "altitude_ratio", altitude_ratio },
    };

    request->send(200, "application/json", data.dump().c_str());
}
