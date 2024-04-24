#pragma once
#include "config/pins.h"

namespace application::pins {
void setup_pins() {
    pinMode(LED_PIN, OUTPUT);
}
}