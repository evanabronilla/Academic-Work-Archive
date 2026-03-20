// Bronilla, Evana Isabella B. & CS104 - 2
#include <iostream>
using namespace std;

int recursive_factorial(int number) {
    if (number <= 1) return 1;
    return number * recursive_factorial(number - 1);
}

int main() {
    int number;
    char choice;

    do {
        cout << "Enter a number: ";
        cin >> number;

        if (number < 0) {
            cout << "Please input positive integers only!" << endl;
        } else {
            cout << "Factorial of " << number << " is " << recursive_factorial(number) << "." << endl;
        }

        cout << "\nTry again? [y/n]: ";
        cin >> choice;

        while (!(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')) {
            cout << "No, no, no! Choose (y) or (n).\nTry again? [y/n]: ";
            cin >> choice;
        }

    } while (choice == 'y' || choice == 'Y');

    cout << "\nThank you for using the program! :) ♡" << endl;
    return 0;
}

