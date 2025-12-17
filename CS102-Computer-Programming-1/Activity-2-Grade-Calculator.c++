#include <iostream>
#include <string>

using namespace std;

int main() {
    // Variable Declarations
    double quiz1_gr, quiz2_gr, quiz3_gr;
    double class_standing_gr, exam_gr;
    double quiz_total, avg_grade, equivalent_grade;

    // Input Section
    cout << "Enter Quiz #1 Grade: ";
    cin >> quiz1_gr;

    cout << "Enter Quiz #2 Grade: ";
    cin >> quiz2_gr;

    cout << "Enter Quiz #3 Grade: ";
    cin >> quiz3_gr;

    cout << "Enter Class Standing Grade: ";
    cin >> class_standing_gr;

    cout << "Enter Exam Grade: ";
    cin >> exam_gr;

    // Calculations
    // Formula: 30% Quizzes, 20% Class Standing, 50% Exam
    quiz_total = (quiz1_gr + quiz2_gr + quiz3_gr) / 3;
    avg_grade = (quiz_total * 0.30) + (class_standing_gr * 0.20) + (exam_gr * 0.50);

    cout << "\nAverage Grade: " << avg_grade << endl;

    // Grading Scale Logic
    if (avg_grade >= 97.02 && avg_grade <= 100) {
        equivalent_grade = 4.00;
    } else if (avg_grade >= 93.02 && avg_grade < 97.02) {
        equivalent_grade = 3.75;
    } else if (avg_grade >= 89.02 && avg_grade < 93.02) {
        equivalent_grade = 3.50;
    } else if (avg_grade >= 85.02 && avg_grade < 89.02) {
        equivalent_grade = 3.25;
    } else if (avg_grade >= 81.02 && avg_grade < 85.02) {
        equivalent_grade = 3.00;
    } else if (avg_grade >= 77.02 && avg_grade < 81.02) {
        equivalent_grade = 2.75;
    } else if (avg_grade >= 73.02 && avg_grade < 77.02) {
        equivalent_grade = 2.50;
    } else if (avg_grade >= 69.02 && avg_grade < 73.02) {
        equivalent_grade = 2.25;
    } else if (avg_grade >= 65.02 && avg_grade < 69.02) {
        equivalent_grade = 2.00;
    } else if (avg_grade >= 61.02 && avg_grade < 65.02) {
        equivalent_grade = 1.75;
    } else if (avg_grade >= 57.02 && avg_grade < 61.02) {
        equivalent_grade = 1.50;
    } else if (avg_grade >= 53.02 && avg_grade < 57.02) {
        equivalent_grade = 1.25;
    } else if (avg_grade >= 49.02 && avg_grade < 53.02) {
        equivalent_grade = 1.00;
    } else {
        equivalent_grade = 0.00;
    }

    // Determine Status
    string status;
    if (equivalent_grade > 0.00) {
        status = "PASSED";
    } else {
        status = "FAILED";
    }

    // Final Output
    cout << "Equivalent Grade: " << equivalent_grade << endl;
    cout << "Status: " << status << endl;

    return 0;
}