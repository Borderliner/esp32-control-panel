/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-web-server-multiple-pages
 */
#pragma once
#include "templating_engine/page.h"
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
            .content {
                min-height: 50vh;
                height: calc(100vh - 52px - 125px);
                margin-top: 52px;
            }
            @media (min-width: 544px) {
                .content {
                    height: calc(100vh - 52px - 100px);
                }
            }

            @media (min-width: 910px) {
                .content {
                    height: calc(100vh - 52px - 76px);
                }
            }
            .content {
                height: fit-content;
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
            <a href="https://github.com/Borderliner/Meshki/issues">Issues</a>
            <a href="https://github.com/Borderliner/Meshki/pulls">Pull Requests</a>
            <a href="https://github.com/Borderliner/Meshki/releases">Releases</a>
            <a href="rtl/">RTL Mode (Eastern)</a>
            <a href="https://github.com/Borderliner/Meshki/blob/master/CHANGELOG.md">Changelog</a>
            <a href="https://github.com/Borderliner/Meshki/blob/master/LICENSE">License</a>
            <a href="https://plisio.net/donate/VXKr4hHx" target="_blank">Donate</a>
            <a href="https://github.com/Borderliner/Meshki/blob/master/README.md">About Meshki</a>
            <hr class="hide-on-non-mobile">
            <div class="hide-on-non-mobile">
                <a href="#buttons-doc" onclick="meshki.closeSidenav()">Buttons</a>
                <a href="#sidenav-doc" onclick="meshki.closeSidenav()">Sidenav</a>
                <a href="#navbar-doc" onclick="meshki.closeSidenav()">Navbar</a>
                <a href="#layout-doc" onclick="meshki.closeSidenav()">Layout System</a>
                <a href="#form-doc" onclick="meshki.closeSidenav()">Forms</a>
                <a href="#typography-doc" onclick="meshki.closeSidenav()">Typography</a>
                <a href="#tables-doc" onclick="meshki.closeSidenav()">Tables</a>
                <a href="#footer-doc" onclick="meshki.closeSidenav()">Footer</a>
            </div>
            <hr>
            <button class="button blue medium extern-twitter" onclick="location.href='https://twitter.com/Meshki_UI'"><i class="fa-brands fa-x-twitter" aria-hidden="true"></i></button>
            <button class="button red medium extern-npm" onclick="location.href='https://www.npmjs.com/package/meshki'"><i class="fab fa-npm" aria-hidden="true"></i></button>
            <button class="button medium extern-github" onclick="location.href='https://github.com/Borderliner/Meshki'"><i class="fab fa-github" aria-hidden="true"></i></button>
            <a href="javascript:void(0)" disabled="" style="font-size: 1.5rem">Share on:</a>
            <div class="share-links">
                <a class="fb-share" href="https://www.facebook.com/sharer/sharer.php?u=https://borderliner.github.io/Meshki/" target="_blank"><i class="fab fa-facebook-square" aria-hidden="true"></i></a>
                <a class="tw-share" href="https://twitter.com/home?status=https://borderliner.github.io/Meshki/" target="_blank"><i class="fa-brands fa-square-x-twitter" aria-hidden="true"></i></a>
                <a class="gp-share" href="https://plus.google.com/share?url=https://borderliner.github.io/Meshki/" target="_blank"><i class="fab fa-google-plus-square" aria-hidden="true"></i></a>
            </div>
        </div>
        <div class="container">
            <div class="nav fixed">
                <ul>
                    <li><a class="logo" href="javascript:void(0);" onclick="meshki.openSidenav()"><i class="fas fa-bars" aria-hidden="true"></i>منوی اصلی</a></li>
                    <li class="nav-dropdown hide-on-mobile">
                    <a href="javascript:void(0)" class="nav-dropdown-button">ابزار</a>
                    <div class="nav-dropdown-content">
                        <a href="rtl/">یک</a>
                        <a href="#extra-button-colors">دو</a>
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
