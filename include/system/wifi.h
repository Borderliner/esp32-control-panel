#pragma once

#include <WiFi.h>
#include "config/wifi.h"

namespace application::wifi {
    void setup_wifi() {
        // Connect to Wi-Fi
        WiFi.begin(wifi_ssid, wifi_pass);
        while (WiFi.waitForConnectResult() != WL_CONNECTED) {
            delay(1000);
            Serial.println("Connecting to WiFi...");
        }
        Serial.println("Connection Successful!");

        // Print the ESP32's IP address
        Serial.print("Web Server's IP Address: ");
        Serial.println(WiFi.localIP());
    }
}
