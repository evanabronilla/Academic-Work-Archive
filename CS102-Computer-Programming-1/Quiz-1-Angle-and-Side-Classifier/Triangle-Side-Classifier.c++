#include <iostream>

using namespace std;

int main() {
    int side1, side2, side3;

    // Input Section
    cout << "Enter side 1: ";
    cin >> side1;
    cout << "Enter side 2: ";
    cin >> side2;
    cout << "Enter side 3: ";
    cin >> side3;

    // Validation Section
    // A triangle is invalid if a side is 0/negative or 
    // if the sum of two sides is not greater than the third side.
    if (side1 <= 0 || side2 <= 0 || side3 <= 0 || 
       (side1 + side2 <= side3) || 
       (side1 + side3 <= side2) || 
       (side2 + side3 <= side1)) {
        
        cout << "\n[!] Invalid triangle based on side lengths." << endl;
    } 
    else {
        // Classification Section
        cout << "\nResult: ";
        if (side1 == side2 && side2 == side3) {
            cout << "This is an Equilateral triangle." << endl;
        } 
        else if (side1 == side2 || side2 == side3 || side1 == side3) {
            cout << "This is an Isosceles triangle." << endl;
        } 
        else {
            cout << "This is a Scalene triangle." << endl;
        }
    }

    return 0;
}