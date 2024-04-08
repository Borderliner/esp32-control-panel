#pragma once
#include "views/pages/led.h"
#include "config/pins.h"

#include <ESPAsyncWebServer.h>

using application::templating::PageDataJson;

int led_state = LOW;

void led_page_handler(AsyncWebServerRequest *request) {
    Serial.print("Web Server: LED Page");
        // Check for the 'state' parameter in the query string
        if (request->hasArg("state")) {
            String state = request->arg("state");
            if (state == "on") {
                led_state = HIGH;
            } else if (state == "off") {
                led_state = LOW;
            }

            // control LED here
            digitalWrite(application::pins::LED_PIN, led_state);
            Serial.print(" => Turning LED to ");
            Serial.print(state);
        }
        Serial.println();

        PageDataJson data;
        data["LED_STATE"] = led_state ? "ON" : "OFF";

        String html = page_led.render_with_json(data);
        request->send(200, "text/html", html);
}
