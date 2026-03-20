//Bronilla, Evana Isabella 
//Julian, Mariah Judea 
//CS104 - 2

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <unordered_set>

using namespace std;

bool isValidCode(const string& code) {
    if (code.length() != 4 || !all_of(code.begin(), code.end(), ::isdigit))
        return false;
    for (int i = 0; i < 4; ++i)
        for (int j = i + 1; j < 4; ++j)
            if (code[i] == code[j])
                return false;
    return true;
}

string generateRandomCode() {
    string digits = "0123456789";
    random_device rd;
    mt19937 g(rd());
    shuffle(digits.begin(), digits.end(), g);
    return digits.substr(0, 4);
}

pair<int, int> countBullsAndCows(const string& secret, const string& guess) {
    int bulls = 0, cows = 0;
    for (int i = 0; i < 4; ++i) {
        if (guess[i] == secret[i])
            bulls++;
        else if (secret.find(guess[i]) != string::npos)
            cows++;
    }
    return make_pair(bulls, cows);
}

int main() {
    srand(time(0));

    string computerCode = generateRandomCode();
    string playerCode;
    string difficulty;

    cout << "Welcome to Bulls and Cows!\n";

    while (true) {
        cout << "Choose AI difficulty (easy / medium): ";
        cin >> difficulty;
        transform(difficulty.begin(), difficulty.end(), difficulty.begin(), ::tolower);
        if (difficulty == "easy" || difficulty == "medium")
            break;
        cout << "Invalid input. Please enter 'easy' or 'medium'.\n";
    }

    while (true) {
        cout << "Enter your 4-digit secret code (digits must be unique): ";
        cin >> playerCode;
        if (isValidCode(playerCode))
            break;
        cout << "Invalid code. Please try again.\n";
    }

    cout << "\nBulls & Cows game start!\n";
    cout << "Your code is set. The game begins!\n";

    bool playerWon = false, computerWon = false;
    unordered_set<string> previousComputerGuesses;
    unordered_set<string> previousPlayerGuesses;

    for (int turn = 1; turn <= 7; ++turn) {
        string playerGuess;

        while (true) {
            cout << "Turn " << turn << ":\nEnter your guess: ";
            cin >> playerGuess;

            if (!isValidCode(playerGuess)) {
                cout << "Invalid guess. Try again.\n";
                continue;
            }

            if (previousPlayerGuesses.count(playerGuess)) {
                cout << "You've already guessed that. Try a different guess.\n";
                continue;
            }

            previousPlayerGuesses.insert(playerGuess);
            break;
        }

        pair<int,int> playerResult = countBullsAndCows(computerCode, playerGuess);
        int playerBulls = playerResult.first;
        int playerCows = playerResult.second;

        string computerGuess;
        if (difficulty == "easy") {
            computerGuess = generateRandomCode();
        } else {
            do {
                computerGuess = generateRandomCode();
            } while (previousComputerGuesses.count(computerGuess));
            previousComputerGuesses.insert(computerGuess);
        }

        pair<int,int> computerResult = countBullsAndCows(playerCode, computerGuess);
        int computerBulls = computerResult.first;
        int computerCows = computerResult.second;

        cout << "Computer guessed " << computerGuess << ", scoring "
             << computerBulls << " bull" << (computerBulls != 1 ? "s" : "")
             << " and " << computerCows << " cow" << (computerCows != 1 ? "s" : "") << "." << endl;

        cout << "You guessed " << playerGuess << ", scoring "
             << playerBulls << " bull" << (playerBulls != 1 ? "s" : "")
             << " and " << playerCows << " cow" << (playerCows != 1 ? "s" : "") << "." << endl;

        cout << "---\n";

        if (playerBulls == 4) {
            cout << "You win! :)\n";
            playerWon = true;
            break;
        }

        if (computerBulls == 4) {
            cout << "Computer wins! :(\n";
            computerWon = true;
            break;
        }
    }

    if (!playerWon && !computerWon) {
        cout << "It's a draw! Neither guessed the code in 7 turns.\n";
    }

    cout << "Your code was: " << playerCode << endl;
    cout << "Computer's code was: " << computerCode << endl;

    return 0;
}