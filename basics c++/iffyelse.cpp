#include<iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter an integer: ";
    cin >> number;

    if (number > 0) {
        cout << "positive." << endl;
    }
    else if (number < 0) {
        cout << "negative." << endl;
    }
    else {
        cout << "zero." << endl;
    }

    // switch case alternative for the same logic
    switch ((number > 0) - (number < 0)) {
        case 1:
            cout << "The number is positive." << endl;
            break;
        case -1:
            cout << "The number is negative." << endl;
            break;
        case 0:
            cout << "The number is zero." << endl;
            break;
    }

    return 0;
}