/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-web-server-multiple-pages
 */

#pragma once
#include "application/templating/page.h"
using application::templating::Page;

#define PAGE_405_TITLE "405 - Method Not Allowed"

static Page page_405 = Page {
    "fa", // language
    PAGE_405_TITLE, // title
    "", // css
    "", // js
    R"=====(
        <h1>405 - Method Not Allowed</h1>
        <p>Oops! The requested method is not allowed for this resource.</p>
        <p>Please check your request or go back to the <a href="/">homepage</a>.</p>
        <p>Or check <a href="https://esp32io.com/tutorials/esp32-web-server-multiple-pages"> Esp32 Web Server</a> tutorial.</p>
    )=====", // body
};
