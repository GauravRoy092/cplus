/*
 * =============================================================
 * C++ BASICS - LESSON 5: CONDITIONAL STATEMENTS
 * =============================================================
 * Control flow based on conditions.
 * 
 * Key Concepts:
 * - if, else, else if
 * - switch-case
 * - Ternary operator
 * - Nested conditions
 * =============================================================
 */

#include <iostream>
using namespace std;

int main() {
    // ==========================================
    // BASIC IF STATEMENT
    // ==========================================
    cout << "=== BASIC IF ===" << endl;
    
    int age = 20;
    
    if (age >= 18) {
        cout << "You are an adult." << endl;
    }
    
    // Single-line if (no braces needed for single statement)
    if (age >= 18) cout << "Can vote!" << endl;
    
    // ==========================================
    // IF-ELSE STATEMENT
    // ==========================================
    cout << "\n=== IF-ELSE ===" << endl;
    
    int number = 7;
    
    if (number % 2 == 0) {
        cout << number << " is EVEN" << endl;
    } else {
        cout << number << " is ODD" << endl;
    }
    
    // ==========================================
    // IF-ELSE IF-ELSE (LADDER)
    // ==========================================
    cout << "\n=== IF-ELSE IF-ELSE ===" << endl;
    
    int score = 75;
    char grade;
    
    if (score >= 90) {
        grade = 'A';
    } else if (score >= 80) {
        grade = 'B';
    } else if (score >= 70) {
        grade = 'C';
    } else if (score >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }
    
    cout << "Score: " << score << ", Grade: " << grade << endl;
    
    // ==========================================
    // NESTED IF
    // ==========================================
    cout << "\n=== NESTED IF ===" << endl;
    
    int x = 10, y = 20;
    
    if (x > 0) {
        if (y > 0) {
            cout << "Both x and y are positive" << endl;
        } else {
            cout << "x is positive, y is not" << endl;
        }
    } else {
        cout << "x is not positive" << endl;
    }
    
    // Better with logical operators:
    if (x > 0 && y > 0) {
        cout << "(Using &&) Both are positive" << endl;
    }
    
    // ==========================================
    // SWITCH STATEMENT
    // ==========================================
    cout << "\n=== SWITCH STATEMENT ===" << endl;
    
    int day = 3;
    
    switch (day) {
        case 1:
            cout << "Monday" << endl;
            break;  // IMPORTANT! Without break, falls through
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
        case 7:  // Multiple cases, same action
            cout << "Weekend!" << endl;
            break;
        default:  // If no case matches
            cout << "Invalid day" << endl;
    }
    
    // Switch with characters
    char operation = '+';
    int a = 10, b = 5;
    
    switch (operation) {
        case '+':
            cout << a << " + " << b << " = " << (a + b) << endl;
            break;
        case '-':
            cout << a << " - " << b << " = " << (a - b) << endl;
            break;
        case '*':
            cout << a << " * " << b << " = " << (a * b) << endl;
            break;
        case '/':
            cout << a << " / " << b << " = " << (a / b) << endl;
            break;
        default:
            cout << "Unknown operation" << endl;
    }
    
    // ==========================================
    // TERNARY OPERATOR (Conditional Expression)
    // ==========================================
    cout << "\n=== TERNARY OPERATOR ===" << endl;
    
    int num = 15;
    
    // Syntax: condition ? value_if_true : value_if_false
    string parity = (num % 2 == 0) ? "Even" : "Odd";
    cout << num << " is " << parity << endl;
    
    // Find maximum of two numbers
    int m = 25, n = 30;
    int maxVal = (m > n) ? m : n;
    cout << "Max of " << m << " and " << n << " is: " << maxVal << endl;
    
    // Nested ternary (use sparingly!)
    int val = 0;
    string result = (val > 0) ? "Positive" : (val < 0) ? "Negative" : "Zero";
    cout << val << " is " << result << endl;
    
    // ==========================================
    // PRACTICAL EXAMPLES
    // ==========================================
    cout << "\n=== PRACTICAL EXAMPLES ===" << endl;
    
    // Example 1: Check if year is leap year
    int year = 2024;
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    cout << year << " is " << (isLeap ? "a leap year" : "not a leap year") << endl;
    
    // Example 2: Find largest of three numbers
    int p = 15, q = 22, r = 18;
    int largest;
    
    if (p >= q && p >= r) {
        largest = p;
    } else if (q >= p && q >= r) {
        largest = q;
    } else {
        largest = r;
    }
    cout << "Largest of " << p << ", " << q << ", " << r << " is: " << largest << endl;
    
    // Using ternary:
    largest = (p > q) ? ((p > r) ? p : r) : ((q > r) ? q : r);
    cout << "Using ternary, largest is: " << largest << endl;
    
    // Example 3: Absolute value
    int negative = -42;
    int absolute = (negative < 0) ? -negative : negative;
    cout << "Absolute value of " << negative << " is: " << absolute << endl;
    
    return 0;
}

/*
 * QUICK REFERENCE - CONDITIONALS:
 * ================================
 * 
 * IF-ELSE:
 * --------
 * if (condition) {
 *     // code
 * } else if (another_condition) {
 *     // code
 * } else {
 *     // code
 * }
 * 
 * SWITCH:
 * -------
 * switch (variable) {
 *     case value1:
 *         // code
 *         break;
 *     case value2:
 *         // code
 *         break;
 *     default:
 *         // code
 * }
 * 
 * TERNARY:
 * --------
 * result = (condition) ? value_if_true : value_if_false;
 * 
 * TIPS:
 * - Always use braces {} for clarity
 * - Don't forget break in switch!
 * - Use logical operators to simplify nested ifs
 * - Ternary is great for simple assignments
 */
