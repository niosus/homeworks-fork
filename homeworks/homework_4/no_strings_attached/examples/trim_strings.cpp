#include <no_strings_attached/string_trim.h>

#include <iostream>

int main() {
  std::cout << "Example program that trims strings." << std::endl;
  std::string query{};
  std::cout << "Please enter a string:" << std::endl;
  std::getline(std::cin, query);
  const auto trimmed_string = no_strings_attached::Trim(query);
  std::cout << "Your trimmed string: '" << trimmed_string << "'" << std::endl;
  return 0;
}
