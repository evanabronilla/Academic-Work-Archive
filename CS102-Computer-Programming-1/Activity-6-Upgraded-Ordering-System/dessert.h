#ifndef DESSERT_H
#define DESSERT_H

#include <iostream>
#include <string>
using namespace std;

void orderDessert(double &totalAmount, string &orderedDessert) {
    char dessertSelection;
    int quantity;

    cout << "\n-------- DESSERT LIST --------" << endl;
    cout << "[A] Ice Cream    P 10.00" << endl;
    cout << "[B] Cake         P 30.00" << endl;
    cout << "[C] Fruit Salad  P 50.00" << endl;
    cout << "Choose Order: ";
    cin >> dessertSelection;
    cout << "Enter quantity: ";
    cin >> quantity;

    if (dessertSelection == 'A' || dessertSelection == 'a') {
        totalAmount += 10.00 * quantity;
        orderedDessert = "Ice Cream";
    } else if (dessertSelection == 'B' || dessertSelection == 'b') {
        totalAmount += 30.00 * quantity;
        orderedDessert = "Cake";
    } else if (dessertSelection == 'C' || dessertSelection == 'c') {
        totalAmount += 50.00 * quantity;
        orderedDessert = "Fruit Salad";
    } else {
        cout << "Invalid dessert option.\n";
    }
}

#endif