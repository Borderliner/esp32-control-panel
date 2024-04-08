#pragma once

#include "config/serial.h"

#include <Arduino.h>

namespace application::serial {
void setup_serial() {
    Serial.begin(BAUD_SIZE);
}
}
