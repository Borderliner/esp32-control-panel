#pragma once
#include "views/pages/home.h"

#include <ESPAsyncWebServer.h>

void home_page_handler(AsyncWebServerRequest *request) {
    Serial.println("Web Server: home page");
        String html = page_home.render();  // Use the HTML content
                                                     // from the index.h file
        request->send(200, "text/html", html);
}
