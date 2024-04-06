/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-web-server-multiple-pages
 */

#pragma once
#include "templates/layout.h"
#include <string>

#define PAGE_LED_TITLE "LED"

const std::string page_led =
    get_layout_header(PAGE_LED_TITLE) +
    std::string(R"=====(
        <h1>LED Page</h1>
        <p>LED State: <span style="color: red;">%LED_STATE%</span></p>
        <a href='/led.html?state=on'>Turn ON</a>
        <br><br>
        <a href='/led.html?state=off'>Turn OFF</a>
    )=====") +
    get_layout_footer();
