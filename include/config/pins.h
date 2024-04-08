#pragma once

#include <Arduino.h>

namespace application::pins {
const uint8_t LED_PIN = 2;

void setup_pins() {
    pinMode(LED_PIN, OUTPUT);
}
}
