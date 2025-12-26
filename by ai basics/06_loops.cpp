/*
 * =============================================================
 * C++ BASICS - LESSON 6: LOOPS
 * =============================================================
 * Loops execute code repeatedly.
 * 
 * Key Concepts:
 * - for loop
 * - while loop
 * - do-while loop
 * - Range-based for (C++11)
 * - break, continue, goto
 * - Nested loops
 * =============================================================
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // ==========================================
    // FOR LOOP
    // ==========================================
    cout << "=== FOR LOOP ===" << endl;
    
    // Syntax: for (initialization; condition; update)
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    // Counting down
    cout << "Countdown: ";
    for (int i = 5; i >= 1; i--) {
        cout << i << " ";
    }
    cout << endl;
    
    // Step by 2
    cout << "Even numbers: ";
    for (int i = 0; i <= 10; i += 2) {
        cout << i << " ";
    }
    cout << endl;
    
    // Multiple variables in for loop
    cout << "Multiple variables: ";
    for (int i = 0, j = 10; i < j; i++, j--) {
        cout << "(" << i << "," << j << ") ";
    }
    cout << endl;
    
    // ==========================================
    // WHILE LOOP
    // ==========================================
    cout << "\n=== WHILE LOOP ===" << endl;
    
    // Syntax: while (condition) { ... }
    int count = 1;
    while (count <= 5) {
        cout << count << " ";
        count++;
    }
    cout << endl;
    
    // Sum of digits example
    int num = 12345;
    int sum = 0;
    int temp = num;
    while (temp > 0) {
        sum += temp % 10;  // Add last digit
        temp /= 10;        // Remove last digit
    }
    cout << "Sum of digits of " << num << " = " << sum << endl;
    
    // ==========================================
    // DO-WHILE LOOP
    // ==========================================
    cout << "\n=== DO-WHILE LOOP ===" << endl;
    
    // Executes at least once, checks condition after
    int n = 0;
    do {
        cout << "n = " << n << endl;
        n++;
    } while (n < 3);
    
    // Even if condition is false initially, runs once
    int x = 10;
    do {
        cout << "This runs at least once! x = " << x << endl;
    } while (x < 5);  // Condition is false, but body ran once
    
    // ==========================================
    // RANGE-BASED FOR LOOP (C++11)
    // ==========================================
    cout << "\n=== RANGE-BASED FOR ===" << endl;
    
    // Works with arrays, vectors, strings, etc.
    int arr[] = {10, 20, 30, 40, 50};
    
    cout << "Array elements: ";
    for (int elem : arr) {  // For each element in array
        cout << elem << " ";
    }
    cout << endl;
    
    // With vectors
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << "Vector elements: ";
    for (int v : vec) {
        cout << v << " ";
    }
    cout << endl;
    
    // With strings
    string str = "Hello";
    cout << "Characters: ";
    for (char c : str) {
        cout << c << " ";
    }
    cout << endl;
    
    // Using reference to modify elements
    cout << "Doubling vector: ";
    for (int& v : vec) {  // & makes it a reference
        v *= 2;
    }
    for (int v : vec) {
        cout << v << " ";
    }
    cout << endl;
    
    // Using auto keyword
    cout << "Using auto: ";
    for (auto v : vec) {
        cout << v << " ";
    }
    cout << endl;
    
    // ==========================================
    // BREAK AND CONTINUE
    // ==========================================
    cout << "\n=== BREAK AND CONTINUE ===" << endl;
    
    // break - exits the loop immediately
    cout << "Break at 5: ";
    for (int i = 1; i <= 10; i++) {
        if (i == 5) break;  // Exit loop when i is 5
        cout << i << " ";
    }
    cout << endl;
    
    // continue - skips current iteration
    cout << "Skip 5: ";
    for (int i = 1; i <= 10; i++) {
        if (i == 5) continue;  // Skip when i is 5
        cout << i << " ";
    }
    cout << endl;
    
    // ==========================================
    // NESTED LOOPS
    // ==========================================
    cout << "\n=== NESTED LOOPS ===" << endl;
    
    // Multiplication table snippet
    cout << "Multiplication table (1-3):" << endl;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cout << i << "x" << j << "=" << (i*j) << "\t";
        }
        cout << endl;
    }
    
    // Pattern example (right triangle)
    cout << "\nRight triangle pattern:" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    
    // Breaking out of nested loops using flag
    cout << "\nBreaking nested loops:" << endl;
    bool found = false;
    for (int i = 1; i <= 3 && !found; i++) {
        for (int j = 1; j <= 3; j++) {
            cout << "(" << i << "," << j << ") ";
            if (i == 2 && j == 2) {
                found = true;
                break;  // Only breaks inner loop
            }
        }
    }
    cout << endl;
    
    // ==========================================
    // INFINITE LOOPS
    // ==========================================
    cout << "\n=== INFINITE LOOPS ===" << endl;
    
    // These run forever until break
    // while (true) { ... }
    // for (;;) { ... }
    
    // Example with controlled exit
    int counter = 0;
    while (true) {
        counter++;
        if (counter > 3) break;
        cout << "Iteration " << counter << endl;
    }
    
    // ==========================================
    // PRACTICAL EXAMPLES
    // ==========================================
    cout << "\n=== PRACTICAL EXAMPLES ===" << endl;
    
    // Example 1: Factorial
    int factorial = 1;
    int number = 5;
    for (int i = 1; i <= number; i++) {
        factorial *= i;
    }
    cout << number << "! = " << factorial << endl;
    
    // Example 2: Fibonacci (first 10 numbers)
    cout << "Fibonacci: ";
    int fib1 = 0, fib2 = 1;
    cout << fib1 << " " << fib2 << " ";
    for (int i = 2; i < 10; i++) {
        int next = fib1 + fib2;
        cout << next << " ";
        fib1 = fib2;
        fib2 = next;
    }
    cout << endl;
    
    // Example 3: Prime check
    int checkNum = 17;
    bool isPrime = true;
    if (checkNum < 2) isPrime = false;
    for (int i = 2; i * i <= checkNum; i++) {
        if (checkNum % i == 0) {
            isPrime = false;
            break;
        }
    }
    cout << checkNum << " is " << (isPrime ? "PRIME" : "NOT PRIME") << endl;
    
    // Example 4: Reverse a number
    int original = 12345;
    int reversed = 0;
    temp = original;
    while (temp > 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }
    cout << "Reverse of " << original << " = " << reversed << endl;
    
    return 0;
}

/*
 * QUICK REFERENCE - LOOPS:
 * ========================
 * 
 * FOR LOOP:
 * for (init; condition; update) { ... }
 * 
 * WHILE LOOP:
 * while (condition) { ... }
 * 
 * DO-WHILE LOOP:
 * do { ... } while (condition);
 * 
 * RANGE-BASED FOR (C++11):
 * for (type var : container) { ... }
 * for (auto& var : container) { ... }  // With reference
 * 
 * CONTROL:
 * break;     // Exit loop
 * continue;  // Skip to next iteration
 * 
 * COMMON PATTERNS:
 * - for (int i = 0; i < n; i++)         // 0 to n-1
 * - for (int i = n-1; i >= 0; i--)      // n-1 to 0
 * - for (int i = 0; i < n; i += 2)      // Skip by 2
 * - while (n > 0) { n /= 10; }          // Digit processing
 * - for (int i = 2; i*i <= n; i++)      // Prime check
 */
