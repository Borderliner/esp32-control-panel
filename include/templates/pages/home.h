/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-web-server-multiple-pages
 */
#pragma once
#include "templates/layout.h"

#define PAGE_HOME_TITLE "Home"

static Page page_home = Page {
    PageOptions {
        "fa", // language
        PAGE_HOME_TITLE, // title
        "", // css
        "", // js
        R"=====(
            <h1>Welcome to the Home Page</h1>
            <ul>
                <li><a href="/led">LED Page</a></li>
                <li><a href="/temperature">Temperature Page</a></li>
            </ul>
        )=====", // body
        "", // header_template
        "" // footer_template
    }
};
