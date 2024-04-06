/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit
 * https://esp32io.com/tutorials/esp32-web-server-multiple-pages
 */

#include <ESPAsyncWebServer.h>
#include <WiFi.h>

#include "templates/pages/home.h"
#include "templates/pages/led.h"
#include "templates/pages/temperature.h"

#include "templates/pages/error_404.h"
#include "templates/pages/error_405.h"

#define LED_PIN 2  // ESP32 pin GPIO02 connected to LED

const char *ssid = "WiWi (Secure)";          // CHANGE IT
const char *password = "juikjuik";  // CHANGE IT

AsyncWebServer server(80);

int LED_state = LOW;

float getTemperature() {
    // YOUR SENSOR IMPLEMENTATION HERE
    // simulate the temperature value
    float temp_x100 = random(0, 10000);  // a ramdom value from 0 to 10000
    return temp_x100 / 100;  // return the simulated temperature value from 0 to
                             // 100 in float
}

void setup() {
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);

    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connecttion Successful!");

    // Print the ESP32's IP address
    Serial.print("Device Web Server's IP address: ");
    Serial.println(WiFi.localIP());

    // Serve the specified HTML pages
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        Serial.println("Web Server: home page");
        String html = page_home;  // Use the HTML content from the index.h file
        request->send(200, "text/html", html);
    });

    server.on(
        "/temperature", HTTP_GET, [](AsyncWebServerRequest *request) {
            Serial.println("Web Server: temperature page");
            String html = page_temperature;  // Use the HTML content from the
                                           // temperature.h file
            float temperature = getTemperature();
            html.replace("%TEMPERATURE_VALUE%",
                         String(temperature));  // update the temperature value
            request->send(200, "text/html", html);
        });

    server.on("/led", HTTP_GET, [](AsyncWebServerRequest *request) {
        Serial.print("Web Server: LED page");
        // Check for the 'state' parameter in the query string
        if (request->hasArg("state")) {
            String state = request->arg("state");
            if (state == "on") {
                LED_state = HIGH;
            } else if (state == "off") {
                LED_state = LOW;
            }

            // control LED here
            digitalWrite(LED_PIN, LED_state);
            Serial.print(" => turning LED to ");
            Serial.print(state);
        }
        Serial.println();

        String html = page_led;  // Use the HTML content from the led.h file
        html.replace("%LED_STATE%",
                     LED_state ? "ON" : "OFF");  // update the LED state
        request->send(200, "text/html", html);
    });

    // 404 and 405 error handler
    server.onNotFound([](AsyncWebServerRequest *request) {
        if (request->method() == HTTP_GET) {
            // Handle 404 Not Found error
            Serial.println("Web Server: Not Found");
            String html = page_404;  // Use the HTML content from the
                                             // error_404.h file
            request->send(404, "text/html", html);
        } else {
            // Handle 405 Method Not Allowed error
            Serial.println("Web Server: Method Not Allowed");
            String html = page_405;  // Use the HTML content from the
                                             // error_405.h file
            request->send(405, "text/html", html);
        }
    });

    server.begin();
    Serial.println("Web server started and running...");
}

void loop() {
    // Your code can go here or be empty; the server is handled asynchronously
}
