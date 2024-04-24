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
        <div class="content">

            <div class="row">
                <div class="col six">
                    <h4>دما</h4>
                    <div class="flexbox row" style="align-items: center;">
                        <progress id="temperature_progress" name="temperature_progress" value="0" max="100">0%</progress>
                        <label id="temperature_label" for="temperature_progress" style="margin: 0 1rem -0.5rem 1rem;">0°C</label>
                    </div>
                </div>

                <div class="col six">
                    <h4>رطوبت</h4>
                    <div class="flexbox row" style="align-items: center;">
                        <progress id="humidity_progress" name="humidity_progress" value="0" max="100">0%</progress>
                        <label id="humidity_label" for="humidity_progress" style="margin: 0 1rem -0.5rem 1rem;">0%</label>
                    </div>
                </div>
            </div>


            <div class="row">
                <div class="col six">
                    <h4>فشار</h4>
                    <div class="flexbox row" style="align-items: center;">
                        <progress id="pressure_progress" name="pressure_progress" value="0" max="100">0%</progress>
                        <label id="pressure_label" for="pressure_progress" style="margin: 0 1rem -0.5rem 1rem;">0hPa</label>
                    </div>
                </div>

                <div class="col six">
                    <h4>ارتفاع</h4>
                    <div class="flexbox row" style="align-items: center;">
                        <progress id="altitude_progress" name="altitude_progress" value="0" max="100">0%</progress>
                        <label id="altitude_label" for="altitude_progress" style="margin: 0 1rem -0.5rem 1rem;">0m</label>
                    </div>
                </div>
            </div>

        </div>
    )=====", // body
};
