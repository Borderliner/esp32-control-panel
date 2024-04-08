/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit
 * https://esp32io.com/tutorials/esp32-web-server-multiple-pages
 */

#include "config/pins.h"

#include "system/serial.h"
#include "system/web_server.h"
#include "system/filesystem.h"
#include "system/wifi.h"

void setup() {
    application::serial::setup_serial();
    application::pins::setup_pins();
    application::fs::setup_filesystem();
    application::wifi::setup_wifi();
    application::server::setup_server().start();
    Serial.println("Web server started and running...");
}

void loop() {
    // Your code can go here or be empty; the server is handled asynchronously
}
