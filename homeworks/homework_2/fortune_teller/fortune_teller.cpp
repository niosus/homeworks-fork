#include <array>
#include <iostream>
#include <map>
#include <vector>

namespace {
static const std::map<std::string, std::string> kNoun{
    {"spring", "STL guru"},
    {"summer", "C++ expert"},
    {"autumn", "coding beast"},
    {"winter", "software design hero"},
};

static const std::array<std::string, 3UL> kEnding{
    "eats UB for breakfast", "finds errors quicker than the compiler",
    "is not afraid of C++ error messages"};

} // namespace

// This homework only makes sense before we learn if statements and for loops.
int main() {
  std::cout << "Welcome to the fortune teller program!" << std::endl;
  std::cout << "Please enter your name:" << std::endl;
  std::string name{};
  std::cin >> name;
  std::cout << "Please enter the time of year when you were born:" << std::endl;
  std::cout << "(pick from 'spring', 'summer', 'autumn', 'winter')"
            << std::endl;
  std::string time_of_year{};
  std::cin >> time_of_year;

  // Create adjectives.
  std::vector<std::string> adjectives{};
  std::string adjective{};
  std::cout << "Please enter an adjective:" << std::endl;
  std::cin >> adjective;
  adjectives.push_back(adjective);
  std::cout << "Please enter another adjective:" << std::endl;
  std::cin >> adjective;
  adjectives.push_back(adjective);

  std::cout << std::endl;
  std::cout << "Here is your description:" << std::endl;
  std::cout << name << ", the " << adjectives[name.size() % adjectives.size()]
            << " " << kNoun.at(time_of_year) << " that "
            << kEnding[name.size() % kEnding.size()] << std::endl;
  return 0;
}
