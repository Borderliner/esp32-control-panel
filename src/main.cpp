/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit
 * https://esp32io.com/tutorials/esp32-web-server-multiple-pages
 */

#include <WiFi.h>
#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>

#include "routing.h"
#include "config/pins.h"

#define CACHE_CONTROL_MAX_AGE 600

const char* WIFI_SSID = "WiWi (Secure)"; // CHANGE IT
const char* WIFI_PASSWORD= "juikjuik"; // CHANGE IT

AsyncWebServer web_server(80);

void setup() {
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);

    // Connect to Wi-Fi
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connection Successful!");

    // Print the ESP32's IP address
    Serial.print("Web Server's IP Address: ");
    Serial.println(WiFi.localIP());

    Serial.flush();
    !SPIFFS.begin(true) ? Serial.println("Filesystem mount failed") : Serial.println("Filesystem mount successful");
    String cache_control_max_age = "max-age=" + String(CACHE_CONTROL_MAX_AGE);
    web_server.serveStatic("/assets", SPIFFS, "/")
        .setCacheControl(cache_control_max_age.c_str());
    web_server.serveStatic("/favicon.ico", SPIFFS, "/img/favicon.png")
        .setCacheControl(cache_control_max_age.c_str());

    application::routing::register_routes(web_server);

    web_server.begin();
    Serial.println("Web server started and running...");
}

void loop() {
    // Your code can go here or be empty; the server is handled asynchronously
}
