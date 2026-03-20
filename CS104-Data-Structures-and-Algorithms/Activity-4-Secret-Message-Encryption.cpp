#include <iostream>
#include <fstream>
#include <string>

#define key 3

using namespace std;

string encryptMessage(const string &message) {
    string encrypted = "";
    for (char c : message) {
        encrypted += c + key;
    }
    return encrypted;
}

string decryptMessage(const string &message) {
    string decrypted = "";
    for (char c : message) {
        decrypted += c - key;
    }
    return decrypted;
}

int main() {
    string message;
    string encryptedMessage;
    string decryptedMessage;

    ifstream inputFile("myTopSecretMessage.txt");
    if (!inputFile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }
    getline(inputFile, message);
    inputFile.close();

    encryptedMessage = encryptMessage(message);

    ofstream outputFile("youCantReadThis.txt");
    if (!outputFile) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }
    outputFile << encryptedMessage;
    outputFile.close();

    ifstream encryptedFile("youCantReadThis.txt");
    if (!encryptedFile) {
        cerr << "Error opening encrypted file!" << endl;
        return 1;
    }
    getline(encryptedFile, encryptedMessage);
    encryptedFile.close();

    decryptedMessage = decryptMessage(encryptedMessage);
    cout << "Decrypted Message: " << decryptedMessage << endl;

    return 0;
}