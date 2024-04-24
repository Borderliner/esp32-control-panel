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
        <style>
            .container {
                display: flex;
                flex-direction: column;
                height: 100%;
                position: unset;
            }
            .content {
                flex-grow: 1;
                margin-top: 52px;
            }
            .footer {
                position: unset;
            }

            .power-button,
            .restart-button {
                position: absolute;
                padding-bottom: unset !important;
                height: 55px;
            }
            .power-button {
                bottom: 65px;
            }
            .restart-button {
                bottom: 135px;
            }
            .power-button span.label,
            .restart-button span.label {
                position: relative;
                bottom: 9px;
            }
            .power-button span.label {
                margin: auto 13px;
            }
            .restart-button span.label {
                margin: auto 5px;
            }
        </style>
    )=====",
    // js
    R"=====(
        
    )=====", 
    // body
    R"=====(
        <div class="sidenav push">
            <a href="javascript:void(0);" class="sidenav-close-button" onclick="meshki.closeSidenav()">×</a>
            <a href="/">خانه</a>
            <a href="/sensors">سنسورها</a>
            <a href="/tools">ابزار</a>
            <a href="/settings">تنظیمات</a>
            <a href="/about">درباره‌ی ما</a>
            <hr>
            <button class="button green medium restart-button" onclick="location.href='/restart'">
                <span class="label">ری استارت</span>
                <span><svg xmlns="http://www.w3.org/2000/svg" width="1.8em" height="1.8em" viewBox="0 0 24 24"><path fill="currentColor" fill-rule="evenodd" d="M12 22c5.523 0 10-4.477 10-10S17.523 2 12 2S2 6.477 2 12s4.477 10 10 10m3.935-16.408a.75.75 0 0 1 .467.694v2.715a.75.75 0 0 1-.75.75H13a.75.75 0 0 1-.537-1.274l.762-.78a4.17 4.17 0 0 0-4.224 1.089c-1.668 1.707-1.668 4.483 0 6.19a4.169 4.169 0 0 0 5.998 0a4.394 4.394 0 0 0 1.208-2.472c.058-.418.39-.77.812-.77c.406 0 .742.325.703.729a5.897 5.897 0 0 1-1.65 3.562a5.669 5.669 0 0 1-8.144 0c-2.237-2.29-2.237-5.997 0-8.287a5.666 5.666 0 0 1 6.437-1.208l.75-.768a.75.75 0 0 1 .82-.17" clip-rule="evenodd"/></svg></span>
            </button>
            <button class="button red medium power-button" onclick="location.href='/turn_off'">
                <span class="label">خاموش</span>
                <span><svg xmlns="http://www.w3.org/2000/svg" width="1.7em" height="1.7em" viewBox="0 0 36 36"><path fill="currentColor" d="M18 2a16 16 0 1 0 16 16A16 16 0 0 0 18 2m.06 17.68a1.28 1.28 0 0 1-1.29-1.28V8.65a1.29 1.29 0 0 1 2.58 0v9.75a1.28 1.28 0 0 1-1.29 1.28M18 27.79a9.88 9.88 0 0 1-5.83-17.94a1.4 1.4 0 0 1 1.94.31a1.37 1.37 0 0 1-.31 1.92a7.18 7.18 0 1 0 11.43 5.8a7.07 7.07 0 0 0-3-5.76A1.37 1.37 0 0 1 22 10.2a1.4 1.4 0 0 1 1.94-.29A9.88 9.88 0 0 1 18 27.79" class="clr-i-solid clr-i-solid-path-1"/><path fill="none" d="M0 0h36v36H0z"/></svg></span>
            </button>
        </div>
        <div class="container">
            <div class="nav fixed">
                <ul>
                    <li><a class="logo" href="javascript:void(0);" onclick="meshki.openSidenav()"><i class="fas fa-bars" aria-hidden="true"></i>منوی اصلی</a></li>
                    <li class="nav-dropdown">
                        <a href="javascript:void(0)" class="nav-dropdown-button">ابزار</a>
                        <div class="nav-dropdown-content">
                            <a href="/temperature">دما</a>
                            <a href="/humidity">رطوبت</a>
                            <a href="/light">نور</a>
                            <a href="/sound">صدا</a>
                            <a href="/camera">دوربین</a>
                        </div>
                    </li>
                    <li><a href="https://github.com/Borderliner/Meshki">پیوندها</a></li>
                    <li class="nav-dropdown hide-on-mobile">
                        <a href="javascript:void(0)" class="nav-dropdown-button">مدیریت</a>
                        <div class="nav-dropdown-content">
                            <a href="#buttons-doc">Buttons</a>
                            <a href="#sidenav-doc">Sidenav</a>
                            <a href="#navbar-doc">Navbar</a>
                            <a href="#layout-doc">Layout System</a>
                            <a href="#form-doc">Forms</a>
                            <a href="#typography-doc">Typography</a>
                            <a href="#tables-doc">Tables</a>
                            <a href="#footer-doc">Footer</a>
                        </div>
                    </li>
                </ul>
            </div>
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

            <div class="footer">
                <div class="row">
                    <div class="six col">
                        <p>ساخته شده توسط محمدرضا حاجیانپور (<a href="https://github.com/Borderliner">Borderliner</a>)</p>
                    </div>
                    <div class="six col text-center">
                        <p>تمامی حقوق این نرم افزار طبق قانون برای ناشر محفوظ می‌باشد.</p>
                    </div>
                </div>
            </div>
        </div>
    )=====",
};
