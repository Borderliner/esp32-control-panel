#include "application/bootstrap.h"

#include "application/pins.h"

#include "application/serial.h"
#include "application/web_server.h"
#include "application/filesystem.h"
#include "application/wifi.h"

#include "sensors/temp_humid_bme280.h"

bool application::bootstrap() {
    application::serial::setup_serial();
    application::pins::setup_pins();
    application::fs::setup_filesystem();
    // application::sensor::bme280::setup();
    application::wifi::setup_wifi();
    application::server::setup_server().start();

    return
        application::serial::is_initialized &&
        application::fs::is_initialized && 
        application::wifi::is_initialized &&
        application::server::is_initialized;
}
