#ifndef DRINK_H
#define DRINK_H

#include <iostream>
#include <string>
using namespace std;

void orderDrink(double &totalAmount, string &orderedDrink) {
    char drinkSelection;
    int quantity;

    cout << "\n--------- DRINKS LIST --------" << endl;
    cout << "[A] Soft drink   P 10.00" << endl;
    cout << "[B] Juice        P 10.00" << endl;
    cout << "[C] Coffee       P 25.00" << endl;
    cout << "Choose Order: ";
    cin >> drinkSelection;
    cout << "Enter quantity: ";
    cin >> quantity;

    if (drinkSelection == 'A' || drinkSelection == 'a') {
        totalAmount += 10.00 * quantity;
        orderedDrink = "Soft drink";
    } else if (drinkSelection == 'B' || drinkSelection == 'b') {
        totalAmount += 10.00 * quantity;
        orderedDrink = "Juice";
    } else if (drinkSelection == 'C' || drinkSelection == 'c') {
        totalAmount += 25.00 * quantity;
        orderedDrink = "Coffee";
    } else {
        cout << "Invalid drink option.\n";
    }
}

#endif