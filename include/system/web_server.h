#pragma once

#include <ESPAsyncWebServer.h>

#include "config/web_server.h"
#include "config/routing.h"
#include "system/filesystem.h"

namespace application::server {
static bool is_initialized = false;
class WebServer {
private:
    AsyncWebServer *async_web_server;
    uint16_t port;

public:
    WebServer(uint16_t port) {
        async_web_server = new AsyncWebServer(port);
        initialize();
    };
    ~WebServer() {
        async_web_server->~AsyncWebServer();
        delete async_web_server;
    };
    const AsyncWebServer& get_async_server() const {
        return *async_web_server;
    }

    void initialize() {
        async_web_server->serveStatic("/assets", SPIFFS, "/")
            .setCacheControl(CACHE_CONTROL.c_str());
        async_web_server->serveStatic("/favicon.ico", SPIFFS, "/img/favicon.png")
            .setCacheControl(CACHE_CONTROL.c_str());
        is_initialized = true;
    }

    void register_routes() const {
        application::routing::register_routes(*async_web_server);
    }

    void start() const {
        async_web_server->begin();
    }
};

static const WebServer web_server(SERVER_PORT);
const WebServer& setup_server() {
    web_server.register_routes();
    return web_server;
};
}  // namespace application::server
