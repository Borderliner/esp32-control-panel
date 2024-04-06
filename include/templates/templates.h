#pragma once

#include <string>
#include <regex>

#define MAX_STRING_LENGTH 12

/**
 * Find and replace string
*/
std::string replace_string(const char* template_string, const char* find, const char* replace) {

  return std::regex_replace(template_string, std::regex(std::string(find)), replace);
}
