#pragma once

#include <limits>
#include <string>
#include <vector>

namespace no_strings_attached {

inline std::vector<std::string> Split(const std::string& str,
                                      const std::string& delimeter) {
  return Split(str, delimeter, std::numeric_limits<int>::max());
}

inline std::vector<std::string> Split(const std::string& str,
                                      const std::string& delimeter,
                                      int max_chunks) {
  std::vector<std::string> result;
  auto start = 0U;
  auto end = str.find(delimeter);
  int chunk_count{};
  while (end != std::string::npos) {
    if (++chunk_count > max_count) { return result; }
    result.emplace_back(str.substr(start, end - start));
    start = end + delimeter.length();
    end = str.find(delimeter, start);
  }
  result.emplace_back(str.substr(start, end));
  return result;
}

}  // namespace no_strings_attached
