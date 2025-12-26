#include <iostream>
using namespace std;

int main()
{
    int a = 15;
    int &b = a; // b is a reference to a
    const int c = 1391; // constant variable

    // c = 20; // This will cause a compilation error
    cout << "Value of a: " << a << endl; // Output: 15
    cout << "Value of b: " << b << endl; // Output: 15
    cout << "Value of c: " << c << endl; // Output: 1391

    b = 20;                                               // Change through reference
    cout << "Value of a after changing b: " << a << endl; // Output: 20
    cout << "Value of b after changing b: " << b << endl; // Output: 20

    return 0;
}