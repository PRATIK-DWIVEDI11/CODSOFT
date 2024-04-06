#include <iostream>
#include <cstdlib>   
#include <ctime>     
using namespace std;

int main() {
    srand(time(0)); 

    int secretNumber = rand() % 100 + 1; 
    int guess;
    int attempts = 0;

    std::cout << "Number guessing mainia!\n";
    std::cout << "I have chosen a number between 1 and 100. Come on guess it!\n\n";

    do {
        std::cout << "What's your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        } else if (guess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "\nCongratulations! You've guessed the correct number in " << attempts << " attempts.\n";
        }

    } while (guess != secretNumber);

    return 0;
}
