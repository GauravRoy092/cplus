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
    int localVar = 10; // Local variable

    cout << "Local variable: " << localVar << endl;
    cout << "Global variable: " << globalVar << endl;

    int age = 20;
    float temperature = 36.6f;
    double pi = 3.14159;
    char grade = 'A';
    bool isPassed = true;

    cout << "Age: " << age << endl;
    cout << "Temperature: " << temperature << endl;
    cout << "Value of pi: " << pi << endl;
    cout << "Grade: " << grade << endl;
    cout << "Passed? " << isPassed << endl;

    return 0;
}
