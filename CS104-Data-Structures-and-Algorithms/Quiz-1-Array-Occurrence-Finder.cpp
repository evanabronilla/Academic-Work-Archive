#include <iostream>
using namespace std;

int main() {
    int numbers[10];
    int firstIndex = -1;
    int lastIndex = -2;

    cout << "Input 10 integers:  \n";
    for (int i = 0; i < 10; i++) {
        cout << "index[" << i << "]: ";
        cin >> numbers[i];

        if (numbers[i] == 8) {
            if (firstIndex == -1)
                firstIndex = i;
                lastIndex = i;
        }
    }

    if (firstIndex == -1) {
        cout << "Number 8 is NOT in the array!" << endl;
    } else if (firstIndex == lastIndex) {
        cout << "The first and last occurrence of number 8 is in index [" << firstIndex << "]" << endl;
    } else {
        cout << "First occurrence of no. 8 is in index [" << firstIndex << "]" << endl;
        cout << "Last occurrence of no. 8 is in index [" << lastIndex << "]" << endl;
    }

    return 0;
}

