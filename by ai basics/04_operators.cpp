/*
 * =============================================================
 * C++ BASICS - LESSON 4: OPERATORS
 * =============================================================
 * Operators perform operations on variables and values.
 * 
 * Key Concepts:
 * - Arithmetic operators
 * - Relational/Comparison operators
 * - Logical operators
 * - Assignment operators
 * - Bitwise operators (IMPORTANT for DSA!)
 * =============================================================
 */

#include <iostream>
using namespace std;

int main() {
    // ==========================================
    // ARITHMETIC OPERATORS
    // ==========================================
    cout << "=== ARITHMETIC OPERATORS ===" << endl;
    
    int a = 17, b = 5;
    
    cout << "a = " << a << ", b = " << b << endl;
    cout << "a + b = " << (a + b) << endl;   // Addition: 22
    cout << "a - b = " << (a - b) << endl;   // Subtraction: 12
    cout << "a * b = " << (a * b) << endl;   // Multiplication: 85
    cout << "a / b = " << (a / b) << endl;   // Integer Division: 3
    cout << "a % b = " << (a % b) << endl;   // Modulo (remainder): 2
    
    // Division with decimals
    double x = 17.0, y = 5.0;
    cout << "17.0 / 5.0 = " << (x / y) << endl;  // 3.4
    
    // Increment and Decrement
    int n = 5;
    cout << "\nIncrement/Decrement:" << endl;
    cout << "n = " << n << endl;
    cout << "++n = " << (++n) << endl;  // Pre-increment: 6 (increment then use)
    cout << "n++ = " << (n++) << endl;  // Post-increment: 6 (use then increment)
    cout << "n is now: " << n << endl;   // 7
    cout << "--n = " << (--n) << endl;  // Pre-decrement: 6
    
    // ==========================================
    // RELATIONAL (COMPARISON) OPERATORS
    // ==========================================
    cout << "\n=== RELATIONAL OPERATORS ===" << endl;
    
    int p = 10, q = 20;
    cout << "p = " << p << ", q = " << q << endl;
    cout << boolalpha;  // Print true/false instead of 1/0
    
    cout << "p == q: " << (p == q) << endl;  // Equal to: false
    cout << "p != q: " << (p != q) << endl;  // Not equal: true
    cout << "p > q:  " << (p > q) << endl;   // Greater than: false
    cout << "p < q:  " << (p < q) << endl;   // Less than: true
    cout << "p >= q: " << (p >= q) << endl;  // Greater or equal: false
    cout << "p <= q: " << (p <= q) << endl;  // Less or equal: true
    
    // ==========================================
    // LOGICAL OPERATORS
    // ==========================================
    cout << "\n=== LOGICAL OPERATORS ===" << endl;
    
    bool t = true, f = false;
    
    cout << "true && true:  " << (t && t) << endl;   // AND: true
    cout << "true && false: " << (t && f) << endl;   // AND: false
    cout << "true || false: " << (t || f) << endl;   // OR: true
    cout << "false || false:" << (f || f) << endl;   // OR: false
    cout << "!true:         " << (!t) << endl;       // NOT: false
    cout << "!false:        " << (!f) << endl;       // NOT: true
    
    // Practical example
    int age = 25;
    bool hasLicense = true;
    bool canDrive = (age >= 18) && hasLicense;
    cout << "\nCan drive (age >= 18 && hasLicense): " << canDrive << endl;
    
    // ==========================================
    // ASSIGNMENT OPERATORS
    // ==========================================
    cout << "\n=== ASSIGNMENT OPERATORS ===" << endl;
    
    int num = 10;
    cout << "num = " << num << endl;
    
    num += 5;  // num = num + 5
    cout << "num += 5: " << num << endl;  // 15
    
    num -= 3;  // num = num - 3
    cout << "num -= 3: " << num << endl;  // 12
    
    num *= 2;  // num = num * 2
    cout << "num *= 2: " << num << endl;  // 24
    
    num /= 4;  // num = num / 4
    cout << "num /= 4: " << num << endl;  // 6
    
    num %= 4;  // num = num % 4
    cout << "num %= 4: " << num << endl;  // 2
    
    // ==========================================
    // BITWISE OPERATORS (VERY IMPORTANT FOR DSA!)
    // ==========================================
    cout << "\n=== BITWISE OPERATORS ===" << endl;
    
    int m = 5;   // Binary: 0101
    int k = 3;   // Binary: 0011
    
    cout << "m = 5 (0101), k = 3 (0011)" << endl;
    
    cout << "m & k  = " << (m & k) << endl;   // AND: 1 (0001)
    cout << "m | k  = " << (m | k) << endl;   // OR: 7 (0111)
    cout << "m ^ k  = " << (m ^ k) << endl;   // XOR: 6 (0110)
    cout << "~m     = " << (~m) << endl;      // NOT: -6 (inverts all bits)
    cout << "m << 1 = " << (m << 1) << endl;  // Left shift: 10 (1010) = 5*2
    cout << "m >> 1 = " << (m >> 1) << endl;  // Right shift: 2 (0010) = 5/2
    
    // Bitwise tricks for DSA
    cout << "\n=== BITWISE TRICKS ===" << endl;
    
    // Check if number is even or odd
    int num1 = 7;
    if (num1 & 1) cout << num1 << " is ODD" << endl;
    else cout << num1 << " is EVEN" << endl;
    
    // Multiply by 2
    cout << "5 << 1 = " << (5 << 1) << " (5 * 2)" << endl;
    cout << "5 << 2 = " << (5 << 2) << " (5 * 4)" << endl;
    
    // Divide by 2
    cout << "10 >> 1 = " << (10 >> 1) << " (10 / 2)" << endl;
    
    // Swap without temp variable
    int s1 = 10, s2 = 20;
    cout << "Before swap: s1=" << s1 << ", s2=" << s2 << endl;
    s1 = s1 ^ s2;
    s2 = s1 ^ s2;
    s1 = s1 ^ s2;
    cout << "After XOR swap: s1=" << s1 << ", s2=" << s2 << endl;
    
    // Check if i-th bit is set
    int num2 = 5;  // 0101
    int i = 2;     // Check 2nd bit (0-indexed from right)
    if (num2 & (1 << i)) cout << "Bit " << i << " of " << num2 << " is SET" << endl;
    else cout << "Bit " << i << " of " << num2 << " is NOT SET" << endl;
    
    // ==========================================
    // TERNARY OPERATOR
    // ==========================================
    cout << "\n=== TERNARY OPERATOR ===" << endl;
    
    int score = 75;
    // condition ? value_if_true : value_if_false
    string result = (score >= 60) ? "PASS" : "FAIL";
    cout << "Score: " << score << ", Result: " << result << endl;
    
    // Find maximum
    int v1 = 10, v2 = 25;
    int maximum = (v1 > v2) ? v1 : v2;
    cout << "Max of " << v1 << " and " << v2 << " is: " << maximum << endl;
    
    // ==========================================
    // OPERATOR PRECEDENCE (IMPORTANT!)
    // ==========================================
    cout << "\n=== OPERATOR PRECEDENCE ===" << endl;
    
    // Higher precedence operators execute first
    // Use parentheses to be explicit!
    
    int expr = 5 + 3 * 2;      // 11, not 16 (* before +)
    cout << "5 + 3 * 2 = " << expr << endl;
    
    expr = (5 + 3) * 2;        // 16 (parentheses first)
    cout << "(5 + 3) * 2 = " << expr << endl;
    
    return 0;
}

/*
 * QUICK REFERENCE - OPERATORS:
 * ============================
 * 
 * ARITHMETIC: + - * / % ++ --
 * RELATIONAL: == != > < >= <=
 * LOGICAL:    && || !
 * ASSIGNMENT: = += -= *= /= %=
 * BITWISE:    & | ^ ~ << >>
 * TERNARY:    condition ? true_val : false_val
 * 
 * OPERATOR PRECEDENCE (high to low):
 * 1. () [] -> .
 * 2. ! ~ ++ -- (unary)
 * 3. * / %
 * 4. + -
 * 5. << >>
 * 6. < <= > >=
 * 7. == !=
 * 8. &
 * 9. ^
 * 10. |
 * 11. &&
 * 12. ||
 * 13. ?:
 * 14. = += -= etc.
 * 
 * BITWISE TIPS FOR DSA:
 * - n & 1        -> Check if odd
 * - n << 1       -> Multiply by 2
 * - n >> 1       -> Divide by 2
 * - n & (1 << i) -> Check if i-th bit is set
 * - n | (1 << i) -> Set i-th bit
 * - n ^ (1 << i) -> Toggle i-th bit
 */
