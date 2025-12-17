#include <iostream>

using namespace std;

int main() {
    int rows = 9;

    // Main loop for each row
    for (int z = 0; z < rows; ++z) {
        
        // Loop 1: Prints '#' (Decreasing)
        for (int x = 0; x < rows - z; ++x) {
            cout << '#';
        }

        // Loop 2: Prints '%' (Increasing)
        for (int y = 0; y <= z; ++y) {
            cout << '%';
        }

        // Loop 3: Prints '&' (Decreasing)
        for (int a = 0; a < rows - z; ++a) {
            cout << '&';
        }

        // Move to the next line after completing all loops for the current row
        cout << endl;
    }

    return 0;
}