#pragma once

#include <SPIFFS.h>

namespace application::fs {
    void setup_filesystem() {
        Serial.flush();
        !SPIFFS.begin(true) ? Serial.println("ERROR: Filesystem mount failed") : Serial.println("Filesystem mount was successful");
    }
}
