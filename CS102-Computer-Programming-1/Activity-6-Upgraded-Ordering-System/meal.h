#ifndef MEAL_H
#define MEAL_H

#include <iostream>
#include <string>
using namespace std;

void orderMeal(double &totalAmount, string &orderedMeal) {
    char mealSelection;
    int quantity;

    cout << "\n--------- MEAL LIST ---------" << endl;
    cout << "[A] Meal 1      P 50.00" << endl;
    cout << "[B] Meal 2      P 80.00" << endl;
    cout << "[C] Meal 3      P 110.00" << endl;
    cout << "Choose Order: ";
    cin >> mealSelection;
    cout << "Enter quantity: ";
    cin >> quantity;

    if (mealSelection == 'A' || mealSelection == 'a') {
        totalAmount += 50.00 * quantity;
        orderedMeal = "Meal 1";
    } else if (mealSelection == 'B' || mealSelection == 'b') {
        totalAmount += 80.00 * quantity;
        orderedMeal = "Meal 2";
    } else if (mealSelection == 'C' || mealSelection == 'c') {
        totalAmount += 110.00 * quantity;
        orderedMeal = "Meal 3";
    } else {
        cout << "Invalid meal option.\n";
    }
}

#endif