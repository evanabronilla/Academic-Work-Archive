#include <iostream>

using namespace std;

int main() {
    int angle1, angle2, angle3;

    // Input Section
    cout << "Enter angle 1: ";
    cin >> angle1;
    cout << "Enter angle 2: ";
    cin >> angle2;
    cout << "Enter angle 3: ";
    cin >> angle3;

    // Validation Section
    if (angle1 <= 0 || angle2 <= 0 || angle3 <= 0) {
        cout << "\n[!] There is an Invalid angle value (Angles must be greater than 0)." << endl;
    } 
    else if (angle1 + angle2 + angle3 != 180) {
        cout << "\n[!] There is an Invalid angle value (Total must be exactly 180 degrees)." << endl;
    } 
    else {
        // Classification Section
        cout << "\nResult: ";
        if (angle1 == 90 || angle2 == 90 || angle3 == 90) {
            cout << "This is a Right triangle." << endl;
        } 
        else if (angle1 > 90 || angle2 > 90 || angle3 > 90) {
            cout << "This is an Obtuse triangle." << endl;
        } 
        else {
            cout << "This is an Acute triangle." << endl;
        }
    }

    return 0;
}