#include <no_strings_attached/string_trim.h>

#include <iostream>
#include <string>

int main() {
  std::cout << "Example program that trims strings.\n";
  std::cout << "Please enter a string: ";

  std::string string_to_trim{};
  std::getline(std::cin >> std::ws, string_to_trim);
  auto trimmed_string{no_strings_attached::Trim(string_to_trim)};

  std::cout << "\nYour trimmed string: '" << trimmed_string << '\'';

  return 0;
}