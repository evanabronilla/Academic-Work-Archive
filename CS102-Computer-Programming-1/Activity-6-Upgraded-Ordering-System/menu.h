#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;

void displayMenu() {
    cout << "\n============================" << endl;
    cout << "       MAIN SELECTION" << endl;
    cout << "============================" << endl;
    cout << "[A] Meal" << endl;
    cout << "[B] Drinks" << endl;
    cout << "[C] Dessert" << endl;
    cout << "[D] Payment" << endl;
    cout << "----------------------------" << endl;
    cout << "Choose Order: ";
}

#endif