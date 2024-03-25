#include <no_strings_attached/string_split.h>

#include <iostream>
#include <string>

namespace {
const std::string kDelimiter{" "};
}

int main() {
  std::cout << "Example program that splits strings.\n";
  std::cout << "Please enter a string:";

  std::string string_to_split{};
  std::getline(std::cin >> std::ws, string_to_split);
  auto parts{no_strings_attached::Split(string_to_split, kDelimiter)};

  std::cout << "\nYour split string: ";
  for (const std::string &part : parts) {
    std::cout << '\'' << part << "' ";
  }

  return 0;
}