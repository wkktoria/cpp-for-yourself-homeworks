#pragma once

#include <algorithm>
#include <string>

namespace no_strings_attached {
enum class Side { kLeft, kRight, kBoth };

inline void LeftTrim(std::string &str, char char_to_trim) {
  str.erase(str.begin(),
            std::find_if(str.begin(), str.end(),
                         [&](unsigned char ch) { return ch != char_to_trim; }));
}

inline void RightTrim(std::string &str, char char_to_trim) {
  str.erase(std::find_if(str.rbegin(), str.rend(),
                         [&](unsigned char ch) { return ch != char_to_trim; })
                .base(),
            str.end());
}

std::string Trim(const std::string &str, char char_to_trim, Side side);

std::string Trim(const std::string &str);
} // namespace no_strings_attached