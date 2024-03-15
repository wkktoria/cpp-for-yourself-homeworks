#include <iostream>
#include <random>

int main() {
  std::cout << "Welcome to the GUESSING GAME!\n"
               "I will generate a number and you will guess it!\n";

  std::cout << "Please provide the smallest number:\n";
  int smallest{};
  std::cin >> smallest;

  std::cout << "Please provide the largest number:\n";
  int largest{};
  std::cin >> largest;

  std::cout << "I've generated a number. Try to guess it!\n";

  std::random_device dev{};
  std::mt19937 rng{dev()};
  std::uniform_int_distribution dist{smallest, largest};
  int number_to_guess{dist(rng)};

  bool keep_guessing{true};
  int guess_count{0};

  while (keep_guessing) {
    ++guess_count;

    std::cout << "Please provide the next guess: ";
    int guess{};
    std::cin >> guess;

    if (guess < number_to_guess) {
      std::cout << "Your number is too small. Try again!\n";
    } else if (guess > number_to_guess) {
      std::cout << "Your number is too big. Try again!\n";
    } else {
      std::cout << "You've done it! You guessed the number " << number_to_guess
                << " in " << guess_count << " guesses!\n";
      keep_guessing = false;
    }
  }

  return 0;
}