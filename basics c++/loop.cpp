#include <iostream>
using namespace std;

int main() {
    // For loop example
    cout << "For loop from 1 to 5:" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;
// my own example
    cout << "For loop from 1 to 100:" << endl;
    for (int a =1; a <=100; a++) {
        cout << a << " ";
    }
    cout << endl;

    // While loop example
    cout << "While loop from 1 to 5:" << endl;
    int j = 1;
    while (j <= 5) {
        cout << j << " ";
        j++;
    }
    cout << endl;

    // Do-while loop example
    cout << "Do-while loop from 1 to 5:" << endl;
    int k = 1;
    do {
        cout << k << " ";
        k++;
    } while (k <= 5);
    cout << endl;

    return 0;
}