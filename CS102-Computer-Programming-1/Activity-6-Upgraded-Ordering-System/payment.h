#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <string>
using namespace std;

void processPayment(double totalAmount, const string &meal, const string &drink, const string &dessert) {
    double paymentAmount;

    cout << "\n============================" << endl;
    cout << "       ORDER SUMMARY" << endl;
    cout << "============================" << endl;
    cout << "Meal    : " << meal << endl;
    cout << "Drink   : " << drink << endl;
    cout << "Dessert : " << dessert << endl;
    cout << "----------------------------" << endl;
    cout << "TOTAL AMOUNT: P" << totalAmount << endl;

    cout << "Enter Payment: P";
    cin >> paymentAmount;

    if (paymentAmount >= totalAmount) {
        cout << "Change       : P" << (paymentAmount - totalAmount) << endl;
        cout << "----------------------------" << endl;
        cout << "PAYMENT SUCCESSFUL!" << endl;
    } else {
        cout << "\n[!] Insufficient payment." << endl;
    }
    cout << "============================" << endl;
}

#endif