#pragma once

#include <SPIFFS.h>

namespace application::fs {
static bool is_initialized = false;
void setup_filesystem() {
    Serial.flush();
    if (!SPIFFS.begin(true)) {
        Serial.println("ERROR: Filesystem mount failed");
        is_initialized = false;
    } else {
        Serial.println("Filesystem mount was successful");
        is_initialized = true;
    }
}
}  // namespace application::fs
