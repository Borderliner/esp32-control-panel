/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-web-server-multiple-pages
 */

#pragma once
#include "templates/layout.h"

#define PAGE_405_TITLE "405 - Method Not Allowed"

static String page_405 = get_layout_header(PAGE_405_TITLE) +
    R"=====(
        <h1>405 - Method Not Allowed</h1>
        <p>Oops! The requested method is not allowed for this resource.</p>
        <p>Please check your request or go back to the <a href="/">homepage</a>.</p>
        <p>Or check <a href="https://esp32io.com/tutorials/esp32-web-server-multiple-pages"> Esp32 Web Server</a> tutorial.</p>

    )=====" +
    get_layout_footer();
