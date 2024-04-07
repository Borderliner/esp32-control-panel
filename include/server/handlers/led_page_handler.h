#pragma once
#include "templates/pages/led.h"
#include "config/pins.h"

#include <ESPAsyncWebServer.h>

int led_state = LOW;

void led_page_handler(AsyncWebServerRequest *request) {
    Serial.print("Web Server: LED page");
        // Check for the 'state' parameter in the query string
        if (request->hasArg("state")) {
            String state = request->arg("state");
            if (state == "on") {
                led_state = HIGH;
            } else if (state == "off") {
                led_state = LOW;
            }

            // control LED here
            digitalWrite(LED_PIN, led_state);
            Serial.print(" => turning LED to ");
            Serial.print(state);
        }
        Serial.println();

        String html = page_led.compile_template_and_replace(
            String("{LED_STATE}"), led_state ? "ON" : "OFF");
        request->send(200, "text/html", html);
}
