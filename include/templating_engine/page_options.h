#pragma once
#include <WString.h>

namespace application::templating {
struct PageOptions {
    String lang;
    String title;
    String css;
    String js;
    String body;
    String header_template;
    String footer_template;
};
}