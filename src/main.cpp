/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit
 * https://esp32io.com/tutorials/esp32-web-server-multiple-pages
 */

#include "application/bootstrap.h"

void setup() {
    bool status = application::bootstrap();
    if (status) {
        Serial.println("Application has been initiated and is running...");
    } else {
        Serial.println("Error occured during bootstraping.");
    }
}

void loop() {
    // Your code can go here or be empty; the server is handled asynchronously
}
