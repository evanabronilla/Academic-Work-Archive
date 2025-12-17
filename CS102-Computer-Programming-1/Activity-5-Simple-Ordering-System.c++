#include <iostream>
#include <iomanip>

using namespace std;

// Global Variable
double totalAmount = 0;

// Function Prototypes
void displayMenu();
void orderMeal();
void orderDrink();
void orderDessert();
void processPayment();

int main() {
    char mainChoice;

    // Set decimal output to 2 places (P50.00)
    cout << fixed << setprecision(2);

    while (true) {
        displayMenu();
        cin >> mainChoice;

        switch (mainChoice) {
            case 'A': case 'a':
                orderMeal();
                break;
            case 'B': case 'b':
                orderDrink();
                break;
            case 'C': case 'c':
                orderDessert();
                break;
            case 'D': case 'd':
                processPayment();
                return 0;  
                
            default:
                cout << "\n[!] Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

// --- Function Definitions ---

void displayMenu() {
    cout << "\n===============================" << endl;
    cout << "       MAIN ORDER MENU" << endl;
    cout << "===============================" << endl;
    cout << "[A] Meals" << endl;
    cout << "[B] Drinks" << endl;
    cout << "[C] Desserts" << endl;
    cout << "[D] Proceed to Payment" << endl;
    cout << "-------------------------------" << endl;
    cout << "Current Total: P" << totalAmount << endl;
    cout << "Choose an option: ";
}

void orderMeal() {
    char itemChoice;
    int quantity;

    cout << "\n--------- MEAL LIST ---------" << endl;
    cout << "[A] Meal #1    - P50.00" << endl;
    cout << "[B] Meal #2    - P80.00" << endl;
    cout << "[C] Meal #3    - P110.00" << endl;
    cout << "Choose a meal: ";
    cin >> itemChoice;
    cout << "Enter quantity: ";
    cin >> quantity;

    switch (itemChoice) {
        case 'A': case 'a': totalAmount += 50.00 * quantity; break;
        case 'B': case 'b': totalAmount += 80.00 * quantity; break;
        case 'C': case 'c': totalAmount += 110.00 * quantity; break;
        default: cout << "Invalid meal choice.\n";
    }
}

void orderDrink() {
    char itemChoice;
    int quantity;

    cout << "\n--------- DRINKS LIST --------" << endl;
    cout << "[A] Soft Drink - P10.00" << endl;
    cout << "[B] Juice      - P10.00" << endl;
    cout << "[C] Coffee     - P25.00" << endl;
    cout << "Choose a drink: ";
    cin >> itemChoice;
    cout << "Enter quantity: ";
    cin >> quantity;

    switch (itemChoice) {
        case 'A': case 'a': totalAmount += 10.00 * quantity; break;
        case 'B': case 'b': totalAmount += 10.00 * quantity; break;
        case 'C': case 'c': totalAmount += 25.00 * quantity; break;
        default: cout << "Invalid drink choice.\n";
    }
}

void orderDessert() {
    char itemChoice;
    int quantity;

    cout << "\n-------- DESSERT LIST --------" << endl;
    cout << "[A] Ice Cream  - P10.00" << endl;
    cout << "[B] Cake       - P30.00" << endl;
    cout << "[C] Fruit Salad- P50.00" << endl;
    cout << "Choose a dessert: ";
    cin >> itemChoice;
    cout << "Enter quantity: ";
    cin >> quantity;

    switch (itemChoice) {
        case 'A': case 'a': totalAmount += 10.00 * quantity; break;
        case 'B': case 'b': totalAmount += 30.00 * quantity; break;
        case 'C': case 'c': totalAmount += 50.00 * quantity; break;
        default: cout << "Invalid dessert choice.\n";
    }
}

void processPayment() {
    double paymentAmount, change;

    cout << "\n===============================" << endl;
    cout << "           PAYMENT" << endl;
    cout << "===============================" << endl;
    cout << "Total Amount to Pay: P" << totalAmount << endl;
    cout << "Enter Cash Amount  : P";
    cin >> paymentAmount;

    if (paymentAmount >= totalAmount) {
        change = paymentAmount - totalAmount;
        cout << "-------------------------------" << endl;
        cout << "Payment Successful!" << endl;
        cout << "Change: P" << change << endl;
        cout << "Thank you for ordering!" << endl;
    } else {
        cout << "\n[!] Insufficient payment. Order cancelled." << endl;
    }
    cout << "===============================" << endl;
}