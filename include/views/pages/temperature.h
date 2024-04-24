/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit
 * https://esp32io.com/tutorials/esp32-web-server-multiple-pages
 */

#pragma once

#include "application/templating/page.h"
using application::templating::Page;

#define PAGE_TEMP_TITLE "سنسور دما/رطوبت/فشار/ارتفاع"

static Page page_temperature = Page {
    "fa", // language
    PAGE_TEMP_TITLE, // title
    R"====(
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
        </style>
    )====", // css
    R"====(
        <script>
            function take(str, end) {
                return str.slice(0, end);
            }

            $(document).ready(function() {
                setInterval(function() {
                    $.ajax({
                        url: "/bme280/get",
                        type: "GET",
                        cache: false,
                        success: function(data) {
                            console.log(data);
                            var temperature = take(data.temperature.toString(), 5);
                            var humidity = take(data.humidity.toString(), 5);
                            var pressure = take(data.pressure.toString(), 5);
                            var altitude = take(data.altitude.toString(), 4);

                            $("#temperature_label").text(temperature + "°C");
                            $("#temperature_progress").text(temperature + "%");
                            $("#temperature_progress").val(data.temperature);

                            $("#humidity_label").text(humidity + "%");
                            $("#humidity_progress").text(humidity + "%");
                            $("#humidity_progress").val(data.humidity);

                            $("#pressure_label").text(pressure + "hPa");
                            $("#pressure_progress").text(data.pressure_ratio + "%");
                            $("#pressure_progress").val(data.pressure_ratio);

                            $("#altitude_label").text(altitude + "m");
                            $("#altitude_progress").text(data.altitude_ratio + "%");
                            $("#altitude_progress").val(data.altitude_ratio);
                        }
                    });
                }, 1000);
            });
        </script>
    )====", // js
    R"=====(
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

                <div class="row">
                    <div class="col six">
                        <h4>دما</h4>
                        <div class="flexbox row" style="align-items: center;">
                            <label id="temperature_label" for="heap-progress" style="margin: 0 1rem -0.5rem 1rem;">0°C</label>
                            <progress id="temperature_progress" name="heap-progress" value="0" max="100">0%</progress>
                        </div>
                    </div>

                    <div class="col six">
                        <h4>رطوبت</h4>
                        <div class="flexbox row" style="align-items: center;">
                            <label id="humidity_label" for="heap-progress" style="margin: 0 1rem -0.5rem 1rem;">0%</label>
                            <progress id="humidity_progress" name="heap-progress" value="0" max="100">0%</progress>
                        </div>
                    </div>
                </div>
                

                <div class="row">
                    <div class="col six">
                        <h4>فشار</h4>
                        <div class="flexbox row" style="align-items: center;">
                            <label id="pressure_label" for="heap-progress" style="margin: 0 1rem -0.5rem 1rem;">0hPa</label>
                            <progress id="pressure_progress" name="heap-progress" value="0" max="100">0%</progress>
                        </div>
                    </div>

                    <div class="col six">
                        <h4>ارتفاع</h4>
                        <div class="flexbox row" style="align-items: center;">
                            <label id="altitude_label" for="heap-progress" style="margin: 0 1rem -0.5rem 1rem;">0m</label>
                            <progress id="altitude_progress" name="heap-progress" value="0" max="100">0%</progress>
                        </div>
                    </div>
                </div>

            </div>
        </div>
    )=====", // body
};
