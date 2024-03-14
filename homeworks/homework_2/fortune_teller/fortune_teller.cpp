#include <array>
#include <iostream>
#include <map>
#include <string>
#include <string_view>

namespace {
const std::map<std::string_view, std::string_view> kNounsMap{
    {"spring", "STL guru"},
    {"summer", "C++ expert"},
    {"autumn", "coding beast"},
    {"winter", "software design hero"}};

const std::array<std::string_view, 3> kEndings{
    "eats UB for breakfast", "finds errors quicker than the compiler",
    "is not afraid of C++ error messages"};
} // namespace

int main() {
  std::cout << "Welcome to the fortune teller program!\n";
  std::cout << "Please enter your name:\n";

  std::string name{};
  std::cin >> name;

  std::cout << "Please enter the time of year when you were born:\n";
  std::cout << "(pick from 'spring', 'summer', 'autumn', 'winter')\n";

  std::string time_of_year{};
  std::cin >> time_of_year;

  std::cout << "Please enter an adjective:\n";

  std::string first_adjective{};
  std::cin >> first_adjective;

  std::cout << "Please enter another adjective:\n";

  std::string second_adjective{};
  std::cin >> second_adjective;

  const std::array<std::string_view, 2> kAdjectives{first_adjective,
                                                    second_adjective};

  std::string_view adjective{
      kAdjectives.at(name.length() % kAdjectives.size())};
  std::string_view noun{kNounsMap.at(time_of_year)};
  std::string_view ending{kEndings.at(name.length() % kEndings.size())};

  std::cout << "\nHere is your description:\n";
  std::cout << name << ", " << adjective << ' ' << noun << " that " << ending
            << '\n';

  return 0;
}