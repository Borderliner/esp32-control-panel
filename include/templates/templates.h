#pragma once

#define MAX_STRING_LENGTH 12

/**
 * Find and replace string
*/
static String replace_string(const char* template_string, const char* find, const char* replace) {
  //return std::regex_replace(template_string, std::regex(std::string(find)), replace);
  String s(template_string);
  s.replace(find, replace);
  return s;
}
