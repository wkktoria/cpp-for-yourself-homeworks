#include <no_strings_attached/string_trim.h>

namespace no_strings_attached {
std::string Trim(const std::string &str, char char_to_trim, Side side) {
  std::string trimmed_string{str};

  switch (side) {
  case Side::kLeft:
    LeftTrim(trimmed_string, char_to_trim);
    break;
  case Side::kRight:
    RightTrim(trimmed_string, char_to_trim);
    break;
  case Side::kBoth:
    LeftTrim(trimmed_string, char_to_trim);
    RightTrim(trimmed_string, char_to_trim);
    break;
  }

  return trimmed_string;
}

std::string Trim(const std::string &str) { return Trim(str, ' ', Side::kBoth); }
} // namespace no_strings_attached