#pragma once
#include "templates/pages/error_404.h"
#include "templates/pages/error_405.h"

#include <ESPAsyncWebServer.h>

void not_found_page_handler(AsyncWebServerRequest *request) {
    if (request->method() == HTTP_GET) {
            // Handle 404 Not Found error
            Serial.println("Web Server: Not Found");
            String html = page_404.compile_template();  // Use the HTML content from the
                                             // error_404.h file
            request->send(404, "text/html", html);
        } else {
            // Handle 405 Method Not Allowed error
            Serial.println("Web Server: Method Not Allowed");
            String html = page_405.compile_template();  // Use the HTML content from the
                                             // error_405.h file
            request->send(405, "text/html", html);
        }
}
