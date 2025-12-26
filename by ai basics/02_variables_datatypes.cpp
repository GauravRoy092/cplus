/*
 * =============================================================
 * C++ BASICS - LESSON 2: VARIABLES & DATA TYPES
 * =============================================================
 * Variables store data. Each has a specific type.
 * 
 * Key Concepts:
 * - Primitive data types
 * - Variable declaration & initialization
 * - Type sizes and limits
 * - Constants
 * =============================================================
 */

#include <iostream>
#include <climits>  // For INT_MAX, INT_MIN etc.
#include <cfloat>   // For FLT_MAX, DBL_MAX etc.
using namespace std;

int main() {
    // ==========================================
    // INTEGER TYPES
    // ==========================================
    int age = 25;                    // 4 bytes, -2B to +2B
    short small = 100;               // 2 bytes, -32K to +32K
    long big = 100000L;              // 4/8 bytes
    long long veryBig = 9999999999LL;// 8 bytes
    
    unsigned int positive = 50;      // Only positive values (0 to 4B)
    
    cout << "=== INTEGER TYPES ===" << endl;
    cout << "int age = " << age << " (size: " << sizeof(int) << " bytes)" << endl;
    cout << "short small = " << small << " (size: " << sizeof(short) << " bytes)" << endl;
    cout << "long big = " << big << " (size: " << sizeof(long) << " bytes)" << endl;
    cout << "long long veryBig = " << veryBig << " (size: " << sizeof(long long) << " bytes)" << endl;
    
    // Integer limits (IMPORTANT for DSA!)
    cout << "\nInteger Limits:" << endl;
    cout << "INT_MAX = " << INT_MAX << endl;   // 2,147,483,647
    cout << "INT_MIN = " << INT_MIN << endl;   // -2,147,483,648
    
    // ==========================================
    // FLOATING POINT TYPES
    // ==========================================
    float pi = 3.14159f;             // 4 bytes, ~7 decimal precision
    double precise = 3.14159265359;  // 8 bytes, ~15 decimal precision
    long double morePrecise = 3.14159265358979323846L; // 8-16 bytes
    
    cout << "\n=== FLOATING POINT TYPES ===" << endl;
    cout << "float pi = " << pi << " (size: " << sizeof(float) << " bytes)" << endl;
    cout << "double precise = " << precise << " (size: " << sizeof(double) << " bytes)" << endl;
    
    // ==========================================
    // CHARACTER TYPE
    // ==========================================
    char letter = 'A';               // 1 byte, single character
    char digit = '5';                // Characters in single quotes
    char newline = '\n';             // Escape sequences
    
    cout << "\n=== CHARACTER TYPE ===" << endl;
    cout << "char letter = " << letter << " (ASCII: " << (int)letter << ")" << endl;
    cout << "char digit = " << digit << " (ASCII: " << (int)digit << ")" << endl;
    
    // ==========================================
    // BOOLEAN TYPE
    // ==========================================
    bool isTrue = true;              // 1 byte, true(1) or false(0)
    bool isFalse = false;
    bool comparison = (5 > 3);       // Evaluates to true
    
    cout << "\n=== BOOLEAN TYPE ===" << endl;
    cout << "bool isTrue = " << isTrue << endl;     // Prints 1
    cout << "bool isFalse = " << isFalse << endl;   // Prints 0
    cout << "bool (5 > 3) = " << comparison << endl;
    cout << boolalpha;  // Makes bool print as true/false
    cout << "With boolalpha: " << isTrue << ", " << isFalse << endl;
    
    // ==========================================
    // AUTO KEYWORD (C++11)
    // ==========================================
    auto x = 10;         // Compiler infers: int
    auto y = 3.14;       // Compiler infers: double
    auto z = 'c';        // Compiler infers: char
    
    cout << "\n=== AUTO KEYWORD ===" << endl;
    cout << "auto x = 10 (type deduced as int)" << endl;
    cout << "auto y = 3.14 (type deduced as double)" << endl;
    
    // ==========================================
    // CONSTANTS
    // ==========================================
    const int MAX_SIZE = 100;        // Cannot be changed
    const double PI = 3.14159;
    // MAX_SIZE = 200;  // ERROR! Cannot modify const
    
    // Using #define (old style, avoid in modern C++)
    #define MOD 1000000007  // Common in competitive programming
    
    cout << "\n=== CONSTANTS ===" << endl;
    cout << "const int MAX_SIZE = " << MAX_SIZE << endl;
    cout << "const double PI = " << PI << endl;
    cout << "#define MOD = " << MOD << endl;
    
    // ==========================================
    // TYPE CASTING
    // ==========================================
    double d = 3.7;
    int i = (int)d;              // C-style cast: 3 (truncates)
    int j = static_cast<int>(d); // C++ style cast: 3
    
    cout << "\n=== TYPE CASTING ===" << endl;
    cout << "double d = " << d << endl;
    cout << "int i = (int)d = " << i << endl;
    
    // Integer to character
    int ascii = 65;
    char c = (char)ascii;        // 'A'
    cout << "int 65 as char = " << c << endl;
    
    return 0;
}

/*
 * QUICK REFERENCE - DATA TYPES:
 * ============================
 * TYPE         SIZE        RANGE
 * ----         ----        -----
 * bool         1 byte      true/false
 * char         1 byte      -128 to 127 or 0-255
 * short        2 bytes     -32,768 to 32,767
 * int          4 bytes     -2.1B to 2.1B
 * long         4/8 bytes   varies
 * long long    8 bytes     -9.2e18 to 9.2e18
 * float        4 bytes     ~7 decimal digits
 * double       8 bytes     ~15 decimal digits
 * 
 * IMPORTANT FOR DSA:
 * - Use long long for large numbers
 * - INT_MAX = 2,147,483,647 (roughly 2 * 10^9)
 * - LLONG_MAX = 9,223,372,036,854,775,807 (roughly 9 * 10^18)
 */
