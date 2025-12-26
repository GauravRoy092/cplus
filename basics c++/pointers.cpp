#include <iostream>
using namespace std;

int main()
{
    // pointer example
    int a = 3;
    int *b = &a; // pointer to integer a pointer b points to address of a
    cout << "Value of a: " << a << endl;          // Output the value of a
    cout << "Address of a: " << &a << endl;       // Output the address of a
    cout << "Value of b (address of a): " << b << endl; // Output the value of b (address of a)
    cout << "Value pointed to by b: " << *b << endl; // Output the value pointed to by b
    return 0;
}