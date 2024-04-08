/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-web-server-multiple-pages
 */

#pragma once
#include "system/templating/page.h"
using application::templating::Page;

#define PAGE_404_TITLE "404 - صفحه پیدا نشد"

static Page page_404 = Page {
    "fa", // language
    PAGE_404_TITLE, // title
    "", // css
    "", // js
    R"=====(
        <h1>404</h1>
        <p>Oops! The page you are looking for could not be found on Esp32 Web Server.</p>
        <p>Please check the URL or go back to the <a href="/">homepage</a>.</p>
        <p>Or check <a href="https://esp32io.com/tutorials/esp32-web-server-multiple-pages"> Esp32 Web Server</a> tutorial.</p>
    )=====", // body
};
