#include <iostream>

using namespace std;

int main() {
    // Variable Declarations
    int choice;
    float length, width, side, base, height, radius, area, perimeter;
    const float PI = 3.14159;

    // Display Menu
    cout << "===============================================" << endl;
    cout << " Choose a shape to calculate area and perimeter" << endl;
    cout << "===============================================" << endl;
    cout << "1. Rectangle" << endl;
    cout << "2. Square" << endl;
    cout << "3. Triangle" << endl;
    cout << "4. Circle" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;
    cout << "-----------------------------------------------" << endl;

    // Calculation Logic
    switch (choice) {
        case 1:
            // Rectangle Logic
            cout << "Enter length of the rectangle: ";
            cin >> length;
            cout << "Enter width of the rectangle: ";
            cin >> width;
            area = length * width;
            perimeter = 2 * (length + width);
            
            cout << "\nArea of Rectangle: " << area << endl;
            cout << "Perimeter of Rectangle: " << perimeter << endl;
            break;

        case 2:
            // Square Logic
            cout << "Enter side of the square: ";
            cin >> side;
            area = side * side;
            perimeter = 4 * side;
            
            cout << "\nArea of Square: " << area << endl;
            cout << "Perimeter of Square: " << perimeter << endl;
            break;

        case 3:
            // Triangle Logic
            cout << "Enter base of the triangle: ";
            cin >> base;
            cout << "Enter height of the triangle: ";
            cin >> height;
            area = 0.5 * base * height;
            perimeter = 3 * base; // Note: This assumes an equilateral triangle
            
            cout << "\nArea of Triangle: " << area << endl;
            cout << "Perimeter of Triangle: " << perimeter << endl;
            break;

        case 4:
            // Circle Logic
            cout << "Enter radius of the circle: ";
            cin >> radius;
            area = PI * radius * radius;
            perimeter = 2 * PI * radius;
            
            cout << "\nArea of Circle: " << area << endl;
            cout << "Perimeter (Circumference) of Circle: " << perimeter << endl;
            break;

        default:
            // Handling invalid input
            cout << "Invalid choice! Please run the program again and select 1-4." << endl;
            break;
    }       

    cout << "===============================================" << endl;
    return 0;
}