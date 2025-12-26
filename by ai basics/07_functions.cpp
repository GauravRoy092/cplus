/*
 * =============================================================
 * C++ BASICS - LESSON 7: FUNCTIONS
 * =============================================================
 * Functions are reusable blocks of code.
 * 
 * Key Concepts:
 * - Function declaration & definition
 * - Parameters & return values
 * - Pass by value vs reference
 * - Function overloading
 * - Default parameters
 * - Inline functions
 * - Recursion
 * =============================================================
 */

#include <iostream>
using namespace std;

// ==========================================
// FUNCTION DECLARATIONS (Prototypes)
// ==========================================
// Declare functions before main so they can be called
void greet();                           // No parameters, no return
int add(int a, int b);                  // With parameters and return
void printMessage(string msg);          // With parameter, no return
double divide(double a, double b);      // Floating point return
int multiply(int a, int b = 1);         // Default parameter
void swap(int& a, int& b);              // Pass by reference
int factorial(int n);                   // Recursive function

// Function overloading (same name, different parameters)
int sum(int a, int b);
int sum(int a, int b, int c);
double sum(double a, double b);

// ==========================================
// MAIN FUNCTION
// ==========================================
int main() {
    cout << "=== BASIC FUNCTIONS ===" << endl;
    
    // Calling a simple function
    greet();
    
    // Function with return value
    int result = add(5, 3);
    cout << "add(5, 3) = " << result << endl;
    
    // Function with parameter
    printMessage("Hello from function!");
    
    // Floating point function
    cout << "divide(10, 3) = " << divide(10, 3) << endl;
    
    // ==========================================
    // DEFAULT PARAMETERS
    // ==========================================
    cout << "\n=== DEFAULT PARAMETERS ===" << endl;
    
    cout << "multiply(5, 3) = " << multiply(5, 3) << endl;  // Uses 3
    cout << "multiply(5) = " << multiply(5) << endl;        // Uses default 1
    
    // ==========================================
    // PASS BY VALUE VS REFERENCE
    // ==========================================
    cout << "\n=== PASS BY VALUE VS REFERENCE ===" << endl;
    
    int x = 10, y = 20;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swap(x, y);  // Pass by reference - modifies original
    cout << "After swap: x = " << x << ", y = " << y << endl;
    
    // ==========================================
    // FUNCTION OVERLOADING
    // ==========================================
    cout << "\n=== FUNCTION OVERLOADING ===" << endl;
    
    cout << "sum(1, 2) = " << sum(1, 2) << endl;           // Calls int version
    cout << "sum(1, 2, 3) = " << sum(1, 2, 3) << endl;     // Calls 3-arg version
    cout << "sum(1.5, 2.5) = " << sum(1.5, 2.5) << endl;   // Calls double version
    
    // ==========================================
    // RECURSION
    // ==========================================
    cout << "\n=== RECURSION ===" << endl;
    
    cout << "5! = " << factorial(5) << endl;
    
    // ==========================================
    // LAMBDA FUNCTIONS (C++11)
    // ==========================================
    cout << "\n=== LAMBDA FUNCTIONS ===" << endl;
    
    // Syntax: [capture](parameters) -> return_type { body }
    
    // Simple lambda
    auto hello = []() {
        cout << "Hello from lambda!" << endl;
    };
    hello();  // Call the lambda
    
    // Lambda with parameters
    auto addLambda = [](int a, int b) {
        return a + b;
    };
    cout << "Lambda add(3, 4) = " << addLambda(3, 4) << endl;
    
    // Lambda capturing variables
    int factor = 10;
    auto multiplyByFactor = [factor](int x) {  // Capture factor by value
        return x * factor;
    };
    cout << "5 * factor(10) = " << multiplyByFactor(5) << endl;
    
    // Capture by reference
    int counter = 0;
    auto increment = [&counter]() {  // & = capture by reference
        counter++;
    };
    increment();
    increment();
    cout << "Counter after 2 increments: " << counter << endl;
    
    // Capture all by value [=] or by reference [&]
    auto captureAll = [=]() {  // Captures all local variables by value
        return factor + counter;
    };
    cout << "Factor + Counter = " << captureAll() << endl;
    
    return 0;
}

// ==========================================
// FUNCTION DEFINITIONS
// ==========================================

// Simple function - no parameters, no return
void greet() {
    cout << "Hello! Welcome to C++ Functions!" << endl;
}

// Function with parameters and return value
int add(int a, int b) {
    return a + b;
}

// Function with parameter, no return
void printMessage(string msg) {
    cout << msg << endl;
}

// Function returning double
double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return a / b;
}

// Function with default parameter
// NOTE: Default value is in declaration, not definition!
int multiply(int a, int b) {
    return a * b;
}

// Pass by reference - modifies original variables
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Recursive function - calls itself
int factorial(int n) {
    // Base case - stops recursion
    if (n <= 1) return 1;
    
    // Recursive case
    return n * factorial(n - 1);
}

// Overloaded functions - same name, different signatures
int sum(int a, int b) {
    return a + b;
}

int sum(int a, int b, int c) {
    return a + b + c;
}

double sum(double a, double b) {
    return a + b;
}

/*
 * QUICK REFERENCE - FUNCTIONS:
 * ============================
 * 
 * SYNTAX:
 * return_type function_name(parameters) {
 *     // body
 *     return value;
 * }
 * 
 * PASS BY VALUE vs REFERENCE:
 * void func(int x);      // By value - copy made
 * void func(int& x);     // By reference - modifies original
 * void func(const int& x); // By const ref - efficient, no modification
 * 
 * FUNCTION OVERLOADING:
 * - Same name, different parameter types or count
 * - Return type alone doesn't distinguish overloads
 * 
 * DEFAULT PARAMETERS:
 * - Must be rightmost parameters
 * - Define default in declaration, not definition
 * 
 * LAMBDA (C++11):
 * [capture](params) -> return_type { body }
 * 
 * Captures:
 * []       - Nothing
 * [=]      - All by value
 * [&]      - All by reference
 * [x]      - x by value
 * [&x]     - x by reference
 * [=, &x]  - All by value, x by reference
 * 
 * INLINE FUNCTIONS:
 * inline int square(int x) { return x * x; }
 * - Suggests compiler to expand at call site
 * - Good for small, frequently called functions
 */
