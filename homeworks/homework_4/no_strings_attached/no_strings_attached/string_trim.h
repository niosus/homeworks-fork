#pragma once

#include <no_strings_attached/side.h>

#include <limits>
#include <string>
#include <vector>

namespace no_strings_attached {

inline std::string Trim(const std::string& str, char what, Side side) {
  if (str.empty()) { return str; }
  auto left{0UL};
  auto right{str.size()};
  while (left < right) {
    const auto left_found = str[left] == what;
    const auto right_found = str[right - 1UL] == what;
    if (left_found) { left++; }
    if (right_found) { right--; }
    if (!left_found && !right_found) { break; }
  }

  switch (side) {
    case Side::kLeft: return str.substr(left, str.size() - left);
    case Side::kRight: return str.substr(0UL, right);
    case Side::kBoth: return str.substr(left, right - left);
  }
}

inline std::string Trim(const std::string& str) {
  return Trim(str, ' ', Side::kBoth);
}

}  // namespace no_strings_attached
