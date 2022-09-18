#include <iostream>
#include <random>

using UniformDistribution = std::uniform_int_distribution<int>;

int main() {
  std::cout << "Welcome to the GUESSING GAME!" << std::endl;
  std::cout << "I will generate a number and you will guess it!" << std::endl;
  int smallest_number{};
  std::cout << "Please provide the smallest number: " << std::endl;
  std::cin >> smallest_number;
  int largest_number{};
  std::cout << "Please provide the largest number: " << std::endl;
  std::cin >> largest_number;

  std::random_device random_device{};
  std::mt19937 random_engine{random_device()};

  UniformDistribution distribution{smallest_number, largest_number};
  const auto magic_number = distribution(random_engine);
  std::cout << "I've generated a number. Try to guess it!" << std::endl;

  int guesses{};
  while (true) {
    int guessed_number{};
    std::cout << "Please provide the next guess: ";
    std::cin >> guessed_number;
    if (guessed_number == magic_number) {
      std::cout << "You've done it! You guessed the number " << magic_number
                << " in " << guesses + 1 << " guesses!" << std::endl;
      break;
    }
    if (guessed_number < magic_number) {
      std::cout << "Your number is too small. Try again!" << std::endl;
    } else {
      std::cout << "Your number is too big. Try again!" << std::endl;
    }
    guesses++;
  }
}