#include <iostream>
#include <string>
#include "menu.h"
#include "meal.h"
#include "drink.h"
#include "dessert.h"
#include "payment.h"

using namespace std;

// Global variables to track orders
double totalAmount = 0;
string orderedMeal = "None", orderedDrink = "None", orderedDessert = "None";

int main() {
    char selection;

    while (true) {
        displayMenu();
        cin >> selection;

        if (selection == 'A' || selection == 'a') {
            orderMeal(totalAmount, orderedMeal);
        } else if (selection == 'B' || selection == 'b') {
            orderDrink(totalAmount, orderedDrink);
        } else if (selection == 'C' || selection == 'c') {
            orderDessert(totalAmount, orderedDessert);
        } else if (selection == 'D' || selection == 'd') {
            processPayment(totalAmount, orderedMeal, orderedDrink, orderedDessert);
            break; // Exit loop after payment
        } else {
            cout << "\n[!] Invalid input. Please select again.\n";
        }
    }

    return 0;
}