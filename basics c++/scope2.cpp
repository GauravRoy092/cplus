#include <iostream>
using namespace std;

int globalVar = 5; // Global variable

void sum(){
    int a = 15; // Local variable
    int b = 25; // Local variable
    int result = a + b;
    cout << "Sum inside function: " << result << endl;
}

int main()
{
    // int num;
    // cout << "Enter a number: ";
    // cin >> num;                         // take input
    // cout << "You entered: " << num;     // show output

    int localVar = 10; // Local variable
    cout << "Global variable: " << globalVar << endl;
    cout << "Local variable: " << localVar << endl;
    sum();
    sum();
    return 0;
}
