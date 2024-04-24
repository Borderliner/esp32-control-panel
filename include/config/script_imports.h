#pragma once

namespace application::scripts {
const char* GLOBAL_JAVASCRIPT = R"====(
    <script src="/assets/js/lib/alpinejs.min.js"></script>
    <script src="/assets/js/lib/jquery.min.js"></script>
    <script src="/assets/js/lib/meshki.min.js"></script>
    <script src="/assets/js/main.js"></script>
)====";

const char* GLOBAL_CSS = R"====(
    <link rel="stylesheet" href="/assets/css/style.css">
)====";
}