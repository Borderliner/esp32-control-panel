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

#define PAGE_404_TITLE "404 - Page Not Found"

const std::string page_404 =
    get_layout_header(PAGE_404_TITLE) +
    std::string(R"=====(
        <h1>404</h1>
        <p>Oops! The page you are looking for could not be found on Esp32 Web Server.</p>
        <p>Please check the URL or go back to the <a href="/">homepage</a>.</p>
        <p>Or check <a href="https://esp32io.com/tutorials/esp32-web-server-multiple-pages"> Esp32 Web Server</a> tutorial.</p>
    )=====") +
    get_layout_footer();
