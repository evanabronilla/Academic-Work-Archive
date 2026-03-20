#include <iostream>
#include <fstream>

using namespace std;

bool isvowel(char chr) {
    chr = tolower(chr); 
    return (chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u');
}

int main() {
    ifstream inputFile("input.txt");
    ofstream oddFile("oddNumbers.txt");
    ofstream evenFile("evenNumbers.txt");
    ofstream vowelFile("vowels.txt");
    ofstream consonantFile("consonants.txt");
    ofstream symbolFile("symbols.txt");

    if (!inputFile.is_open()) {
        cerr << "Error! Cannot open input.txt. Try again." << endl;
        return 1;
    }

    char chr;
    while (inputFile.get(chr)) {
        if (chr == '\n' || chr == ' ')
            continue;

        if (isdigit(chr)) {
            int digit = chr - '0'; 
            if (digit % 2 == 0) {
                evenFile << chr << endl;
            } else {
                oddFile << chr << endl;
            }
        } else if (isalpha(chr)) {
            if (isvowel(chr)) {
                vowelFile << chr << endl;
            } else {
                consonantFile << chr << endl;
            }
        } else {
            symbolFile << chr << endl;
        }
    }

    inputFile.close();
    oddFile.close();
    evenFile.close();
    vowelFile.close();
    consonantFile.close();
    symbolFile.close();

    cout << "All characters are dispersed to their respective text files. Thank you!" << endl;

    return 0;
}