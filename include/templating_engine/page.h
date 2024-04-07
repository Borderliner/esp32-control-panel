/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit
 * https://esp32io.com/tutorials/esp32-web-server-multiple-pages
 */

#pragma once
#include "templating_engine/page_data.h"
#include "templating_engine/page_options.h"
#include "config/script_imports.h"

#include <WString.h>

namespace application::templating {
class Page {
public:
    Page(String lang, String title, String css, String js, String body) {
        setup_default_templates();
        lang.isEmpty() ? this->m_page_options.lang = "fa" : this->m_page_options.lang = lang;
        this->m_page_options.title = title;
        this->m_page_options.css = css;
        this->m_page_options.js = js;
        this->m_page_options.body = body;
    }

    Page(PageOptions page_options) {
        if (page_options.header_template.isEmpty() || page_options.footer_template.isEmpty()) {
            setup_default_templates();
        }
        this->m_page_options.lang = page_options.lang;
        this->m_page_options.title = page_options.title;
        this->m_page_options.css = page_options.css;
        this->m_page_options.js = page_options.js;
        this->m_page_options.body = page_options.body;
    }

    Page() {
        setup_default_templates();
        this->m_page_options.lang = "fa";
    }

    String render(boolean cache = true) { return compile_template(cache); }

    String render_with_json(PageDataJson data, boolean cache = true) {
        String rendered_template = compile_template(cache);
        if (data.is_null()) return rendered_template;

        for (auto& el : data.items()) {
            String key(el.key().c_str());
            String value(el.value().dump().c_str());
            rendered_template.replace(String("{ " + key + " }"), value);
            rendered_template.replace(String("{" + key + "}"), value);
        }
        return rendered_template;
    }

private:
    PageOptions m_page_options;
    String template_cache;

    void setup_default_templates() {
        this->m_page_options.header_template = R"=====(
            <!DOCTYPE html>
            <html lang="{LANG}">
            <head>
                <title>{TITLE}</title>            
                <meta charset="UTF-8">
                <meta name="viewport" content="width=device-width, initial-scale=1.0">
                <link rel="icon" type="image/x-icon" href="/favicon.ico">
                {GLOBAL_CSS}
                {CSS}
            </head>
            <body>
            )=====";
        this->m_page_options.footer_template = R"=====(
            </body>
            {GLOBAL_JAVASCRIPT}
            {JAVASCRIPT}
            </html>
            )=====";
    }

    String compile_template(boolean cache = true) {
        String header_template = this->m_page_options.header_template;
        header_template.replace("{LANG}", this->m_page_options.lang);
        header_template.replace("{TITLE}", this->m_page_options.title);
        header_template.replace("{GLOBAL_CSS}", GLOBAL_CSS);
        header_template.replace("{CSS}", this->m_page_options.css);

        String footer_template = this->m_page_options.footer_template;
        footer_template.replace("{GLOBAL_JAVASCRIPT}", GLOBAL_JAVASCRIPT);
        footer_template.replace("{JAVASCRIPT}", this->m_page_options.js);

        String result = header_template + this->m_page_options.body + footer_template;
        if (cache) {
            template_cache = result;
        }
        return result;
    }
};
}