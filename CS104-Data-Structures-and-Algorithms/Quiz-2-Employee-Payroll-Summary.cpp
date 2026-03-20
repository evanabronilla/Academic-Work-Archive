#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_EMPLOYEES = 10;

struct Employee {
    string name;
    double hourlyRate = 0.0;
    double hoursWorked = 0.0;
    double grossSalary = 0.0;
    double netPay = 0.0;
};

double calculateNetPay(double gross) {
    return gross * 0.45;
}

int main() {
    Employee employees[NUM_EMPLOYEES];

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        cout << "Enter details for Employee #" << i + 1 << endl;
        cout << "Name: ";
        getline(cin, employees[i].name);

        cout << "Hourly Rate: ";
        cin >> employees[i].hourlyRate;

        cout << "Hours Worked: ";
        cin >> employees[i].hoursWorked;

        cin.ignore(); 

        employees[i].grossSalary = employees[i].hourlyRate * employees[i].hoursWorked;
        employees[i].netPay = calculateNetPay(employees[i].grossSalary);
        cout << endl;
    }

    double totalGross = 0;

    cout << "...... Employee Payslip Summary ......" << endl;
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        cout << fixed << setprecision(2);
        cout << "Name: " << employees[i].name << endl;
        cout << "Hourly Rate: " << employees[i].hourlyRate << endl;
        cout << "Hours Worked: " << employees[i].hoursWorked << endl;
        cout << "Gross Salary: " << employees[i].grossSalary << endl;
        cout << "Net Pay: " << employees[i].netPay << endl;
        cout << "..........................." << endl;

        totalGross += employees[i].grossSalary;
    }

    cout << "Total Payroll Gross: " << totalGross << endl;

    return 0;
}