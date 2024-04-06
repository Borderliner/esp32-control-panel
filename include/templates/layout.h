/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit
 * https://esp32io.com/tutorials/esp32-web-server-multiple-pages
 */

#pragma once

#include "templates/templates.h"

static String get_layout_header(const char* title) {
    return replace_string(R"=====(
        <!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="icon" href="data:,">
            <title>{title}</title>
        </head>
        <body>
        )=====", "{title}", title).c_str();
}

static String get_layout_footer() {
    return R"=====(
        </body>
        </html>
        )=====";
}
