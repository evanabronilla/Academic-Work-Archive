#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    // Variable declarations
    string fullName, email, mobileNumber, course;
    int age;

    cout << "========================================" << endl;
    cout << "      PERSONAL INFORMATION APP          " << endl;
    cout << "========================================" << endl;

    // Collecting User Input
    cout << "Enter Full Name: ";
    getline(cin, fullName);

    cout << "Enter Email Address: ";
    getline(cin, email);

    cout << "Enter Mobile Number: ";
    getline(cin, mobileNumber);

    cout << "Enter Course: ";
    getline(cin, course);

    cout << "Enter Age: ";
    cin >> age;

    // Displaying the collected information
    cout << "\n----------------------------------------" << endl;
    cout << "           USER SUMMARY                " << endl;
    cout << "----------------------------------------" << endl;
    cout << "Name:           " << fullName << endl;
    cout << "Age:            " << age << " years old" << endl;
    cout << "Email:          " << email << endl;
    cout << "Mobile:         " << mobileNumber << endl;
    cout << "Course:         " << course << endl;
    cout << "----------------------------------------" << endl;

    return 0;
}