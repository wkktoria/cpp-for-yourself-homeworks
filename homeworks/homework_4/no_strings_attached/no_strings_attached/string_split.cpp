#include <no_strings_attached/string_split.h>

#include <cstddef>
#include <string>
#include <vector>

namespace no_strings_attached {
std::vector<std::string> Split(const std::string &str,
                               const std::string &delimiter) {
  std::vector<std::string> parts{};
  std::string part{};

  std::size_t pos_start{0};
  std::size_t pos_end{0};
  std::size_t delimiter_length{delimiter.length()};

  while ((pos_end = str.find(delimiter, pos_start)) != std::string::npos) {
    part = str.substr(pos_start, pos_end - pos_start);
    parts.push_back(part);

    pos_start = pos_end + delimiter_length;
  }

  parts.push_back(str.substr(pos_start));

  return parts;
}

std::vector<std::string> Split(const std::string &str,
                               const std::string &delimiter,
                               int number_of_chunks_to_keep) {
  auto parts{Split(str, delimiter)};
  parts.resize(number_of_chunks_to_keep);

  return parts;
}
} // namespace no_strings_attached