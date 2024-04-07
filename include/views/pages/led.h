/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-web-server-multiple-pages
 */

#pragma once
#include "templating_engine/page.h"
using application::templating::Page;

#define PAGE_LED_TITLE "LED"

static Page page_led = Page {
    "fa", // language
    PAGE_LED_TITLE, // title
    "", // css
    "", // js
    R"=====(
        <h1>LED Page</h1>
        <p>LED State: <span style="color: red;">{LED_STATE}</span></p>
        <a href='/led?state=on'>Turn ON</a>
        <br><br>
        <a href='/led?state=off'>Turn OFF</a>
    )=====", // body
};
