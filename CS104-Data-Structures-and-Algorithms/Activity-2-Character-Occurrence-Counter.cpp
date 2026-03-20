#include <iostream>
#include <iomanip>   // For std::setw
#include <cstring>   // For strlen
using namespace std;

// Maximum size of input string
const int MAX_SIZE = 100;

// Function to count and display character occurrences
void countCharacterOccurrences(const char input[]) {
    // Array to track if a character has been counted
    bool counted[MAX_SIZE] = { false };

    cout << "\nCharacter Occurrences:\n";

    // Loop through each character in the string
    for (int i = 0; input[i] != '\0'; ++i) {
        if (!counted[i]) {
            int count = 1;

            // Compare with the rest of the string
            for (int j = i + 1; input[j] != '\0'; ++j) {
                if (input[i] == input[j]) {
                    ++count;
                    counted[j] = true; // Mark as counted
                }
            }

            // Display the character and its count
            cout << setw(12) << input[i] << "  -  " << setw(5) << count << endl;
        }
    }
}

// Entry point of the program
int main() {
    char input[MAX_SIZE + 1]; // +1 for null terminator

    // Prompt user for input
    cout << "Enter String Value: ";
    cin.getline(input, MAX_SIZE + 1);

    // Validate input length
    if (strlen(input) == 0) {
        cout << "Error: Input string is empty." << endl;
        return 1;
    }

    // Count and display character occurrences
    countCharacterOccurrences(input);

    return 0;
}