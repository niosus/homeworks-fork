#include <no_strings_attached/string_split.h>

#include <iostream>

int main() {
  std::cout << "Example program that splits strings." << std::endl;
  std::string query{};
  std::cout << "Please enter a string:" << std::endl;
  std::getline(std::cin, query);
  const auto split = no_strings_attached::Split(query, " ");
  std::cout << "Your split string:";
  for (const auto& part : split) { std::cout << " '" << part << "'"; }
  std::cout << std::endl;
  return 0;
}
