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

#define PAGE_HOME_TITLE "خانه"

static Page page_home = Page {
    // language
    "fa",
    // title
    PAGE_HOME_TITLE,
    // css
    R"=====(
    )=====",
    // js
    R"=====(
        
    )=====", 
    // body
    R"=====(
            <div class="content">
                <h1>خوش آمدید!</h1>
                <ul>
                    <li><a href="/led">تنظیمات LED</a></li>
                    <li><a href="/temperature">نمایشگر دما</a></li>
                </ul>

                <div class="col">
                    <h4>حافظه داخلی (DRAM)</h4>
                    <div class="flexbox row" style="align-items: center;">
                        <label for="heap-progress" style="margin: 0 1rem -0.5rem 1rem;">{ HEAP_RATIO }%</label>
                        <progress name="heap-progress" value="{ HEAP_RATIO }" max="100">{ HEAP_RATIO }%</progress>
                    </div>
                    <ul>
                        <li>حافظه داخلی استفاده شده { HEAP_USED_SIZE } کیلوبایت</li>
                        <li>بیشترین حافظه‌ی استفاده شده از زمان اتصال: { HEAP_MAXIMUM_USED_SIZE } کیلوبایت</li>
                        <li>کل حافظه داخلی: { HEAP_TOTAL_SIZE } کیلوبایت</li>
                    </ul>
                </div>

                <div class="col">
                    <h4>حافظه فایل (SPIFFS)</h4>
                    <div class="flexbox row" style="align-items: center;">
                        <label for="spiffs-progress" style="margin: 0 1rem -0.5rem 1rem;">{ SPIFFS_RATIO }%</label>
                        <progress name="spiffs-progress" value="{ SPIFFS_RATIO }" max="100">{ SPIFFS_RATIO }%</progress>
                    </div>
                    <ul>
                        <li>حافظه فایل استفاده شده: { SPIFFS_USED_SIZE } کیلوبایت</li>
                        <li>کل حافظه فایل: { SPIFFS_TOTAL_SIZE } کیلوبایت</li>
                    </ul>
                </div>
            </div>
    )=====",
};
