#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct MenuItem {
    char name[25];
    double price;
};

void getData(MenuItem menu[], int size) {
    strcpy(menu[0].name, "Plain Egg");
    menu[0].price = 20.00;
    strcpy(menu[1].name, "Bacon and Egg");
    menu[1].price = 80.00;
    strcpy(menu[2].name, "Muffin");
    menu[2].price = 65.00;
    strcpy(menu[3].name, "French Toast");
    menu[3].price = 70.00;
    strcpy(menu[4].name, "Pancake");
    menu[4].price = 100.00;
    strcpy(menu[5].name, "Cereal");
    menu[5].price = 80.00;
    strcpy(menu[6].name, "Coffee");
    menu[6].price = 50.00;
    strcpy(menu[7].name, "Tea");
    menu[7].price = 45.00;
    strcpy(menu[8].name, "Juice");
    menu[8].price = 50.00;
}

void showMenu(const MenuItem menu[], int size) {
    cout << "Welcome to Johnny's Restaurant" << endl;
    cout << "Menu:" << endl;
    cout << left << setw(3) << "#" << setw(20) << "Item" << "Price" << endl;
    
    for (int i = 0; i < size; i++) {
        cout << left << setw(3) << (i + 1)
             << setw(20) << menu[i].name
             << "Php " << fixed << setprecision(2) << menu[i].price << endl;
    }
    
    cout << "\nEnter the item number and quantity (e.g., 2 3 for 3 Bacon and Egg)." << endl;
    cout << "Enter 0 to finish your order." << endl;
}

void printCheck(const MenuItem menu[], const int quantities[], int size) {
    double subtotal = 0.0;
    
    cout << "\n\nWelcome to Johnny's Restaurant" << endl;
    
    for (int i = 0; i < size; i++) {
        if (quantities[i] > 0) {
            double itemTotal = quantities[i] * menu[i].price;
            cout << left << setw(2) << quantities[i]
                 << setw(20) << menu[i].name
                 << "Php " << setw(8) << right << fixed << setprecision(2) << itemTotal << endl;
            subtotal += itemTotal;
        }
    }
    
    double tax = subtotal * 0.10;
    double total = subtotal + tax;
    
    cout << left << setw(23) << "     Tax"
         << "Php " << setw(8) << right << fixed << setprecision(2) << tax << endl;
    cout << left << setw(23) << "     Amount Due"
         << "Php " << setw(8) << right << fixed << setprecision(2) << total << endl;
}

int main() {
    const int MENU_SIZE = 9;
    MenuItem menu[MENU_SIZE];
    int quantities[MENU_SIZE] = {0};
    
    getData(menu, MENU_SIZE);
    showMenu(menu, MENU_SIZE);

    int itemNum, qty;
    while (true) {
        cout << "\nEnter item number (1-9) and quantity, or 0 to finish: ";
        cin >> itemNum;
        
        if (itemNum == 0) {
            break;
        }
        
        if (itemNum < 1 || itemNum > MENU_SIZE) {
            cout << "Invalid item number. Please try again.";
            continue;
        }
        
        cin >> qty;
        
        if (qty < 1) {
            cout << "Quantity must be at least 1. Please try again.";
            continue;
        }
        
        quantities[itemNum - 1] += qty;
    }

    printCheck(menu, quantities, MENU_SIZE);

    return 0;
}