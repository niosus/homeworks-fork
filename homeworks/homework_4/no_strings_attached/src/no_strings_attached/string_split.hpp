#pragma once

#include <string>
#include <vector>

namespace no_strings_attached {

inline std::vector<std::string> Split(const std::string& str,
                                      const std::string& delimeter) {
  std::vector<std::string> result;
  auto start = 0U;
  auto end = str.find(delimeter);
  while (end != std::string::npos) {
    result.emplace_back(str.substr(start, end - start));
    start = end + delimeter.length();
    end = str.find(delimeter, start);
  }
  result.emplace_back(str.substr(start, end));
  return result;
}

inline std::vector<std::string> Split(const std::string& str, char delimeter) {
  return Split(str, std::string{delimeter});
}

}  // namespace no_strings_attached
