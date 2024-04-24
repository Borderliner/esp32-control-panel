#pragma once

#include "config/serial.h"

#include <Arduino.h>

namespace application::serial {
static bool is_initialized = false;
void setup_serial() {
    Serial.begin(BAUD_SIZE);
    is_initialized = true;
}
}
