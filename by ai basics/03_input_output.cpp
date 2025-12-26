/*
 * =============================================================
 * C++ BASICS - LESSON 3: INPUT & OUTPUT
 * =============================================================
 * How to read from keyboard and display to screen.
 * 
 * Key Concepts:
 * - cin for input
 * - cout for output
 * - getline() for strings with spaces
 * - printf/scanf (C-style, still used in competitive programming)
 * =============================================================
 */

#include <iostream>
#include <string>
#include <iomanip>  // For setprecision, setw
using namespace std;

int main() {
    // ==========================================
    // BASIC OUTPUT - cout
    // ==========================================
    cout << "=== BASIC OUTPUT ===" << endl;
    
    int num = 42;
    double pi = 3.14159;
    char grade = 'A';
    string name = "Gaurav";
    
    // Multiple values in one statement
    cout << "Num: " << num << ", Pi: " << pi << ", Grade: " << grade << endl;
    
    // ==========================================
    // BASIC INPUT - cin
    // ==========================================
    cout << "\n=== BASIC INPUT ===" << endl;
    
    int age;
    cout << "Enter your age: ";
    cin >> age;  // >> is extraction operator
    cout << "Your age is: " << age << endl;
    
    // Multiple inputs
    int a, b, c;
    cout << "Enter 3 numbers (space-separated): ";
    cin >> a >> b >> c;  // Reads 3 integers
    cout << "You entered: " << a << ", " << b << ", " << c << endl;
    cout << "Sum: " << (a + b + c) << endl;
    
    // ==========================================
    // STRING INPUT - IMPORTANT!
    // ==========================================
    cout << "\n=== STRING INPUT ===" << endl;
    
    // cin >> stops at whitespace
    string word;
    cout << "Enter a word: ";
    cin >> word;  // Only reads until space
    cout << "Word: " << word << endl;
    
    // Clear the input buffer before getline
    cin.ignore();  // IMPORTANT! Ignores leftover newline
    
    // getline() reads entire line including spaces
    string fullName;
    cout << "Enter your full name: ";
    getline(cin, fullName);  // Reads entire line
    cout << "Full name: " << fullName << endl;
    
    // ==========================================
    // FORMATTED OUTPUT
    // ==========================================
    cout << "\n=== FORMATTED OUTPUT ===" << endl;
    
    double value = 3.14159265359;
    
    // Default precision
    cout << "Default: " << value << endl;
    
    // Fixed decimal places
    cout << fixed << setprecision(2) << "2 decimals: " << value << endl;
    cout << setprecision(4) << "4 decimals: " << value << endl;
    
    // Reset to default
    cout.unsetf(ios::fixed);
    
    // Field width with setw
    cout << "\nFormatted table:" << endl;
    cout << setw(10) << "Name" << setw(10) << "Score" << endl;
    cout << setw(10) << "Alice" << setw(10) << 95 << endl;
    cout << setw(10) << "Bob" << setw(10) << 87 << endl;
    
    // Left/Right alignment
    cout << left << setw(10) << "Left" << "aligned" << endl;
    cout << right << setw(10) << "Right" << "aligned" << endl;
    
    // ==========================================
    // C-STYLE I/O - printf & scanf
    // (Common in competitive programming - FASTER!)
    // ==========================================
    cout << "\n=== C-STYLE I/O (printf/scanf) ===" << endl;
    
    int x = 42;
    double d = 3.14159;
    char ch = 'X';
    
    // printf - formatted output
    printf("Integer: %d\n", x);          // %d for int
    printf("Double: %f\n", d);           // %f for float/double
    printf("2 decimals: %.2f\n", d);     // %.2f for 2 decimal places
    printf("Character: %c\n", ch);       // %c for char
    printf("String: %s\n", "Hello");     // %s for string
    
    // scanf - formatted input (FAST!)
    int p, q;
    printf("Enter two integers: ");
    scanf("%d %d", &p, &q);  // Note the & (address-of)
    printf("Sum: %d\n", p + q);
    
    // ==========================================
    // FAST I/O FOR COMPETITIVE PROGRAMMING
    // ==========================================
    cout << "\n=== FAST I/O ===" << endl;
    
    // Add these at the start of main() for speed:
    ios_base::sync_with_stdio(false);  // Disable sync with C I/O
    cin.tie(NULL);                      // Untie cin from cout
    
    // Now cin/cout are much faster!
    cout << "Fast I/O is now enabled!" << endl;
    
    // Alternative: Use '\n' instead of endl (faster)
    cout << "Using newline character is faster\n";
    
    return 0;
}

/*
 * QUICK REFERENCE - I/O:
 * ======================
 * 
 * INPUT:
 * ------
 * cin >> variable;              // Read single value
 * cin >> a >> b >> c;           // Read multiple values
 * getline(cin, stringVar);      // Read entire line
 * cin.ignore();                 // Clear buffer (use before getline)
 * scanf("%d", &var);            // C-style (fast)
 * 
 * OUTPUT:
 * -------
 * cout << value << endl;        // Print with newline
 * cout << value << '\n';        // Faster newline
 * printf("%d\n", intVar);       // C-style (fast)
 * 
 * FORMAT SPECIFIERS (printf/scanf):
 * ---------------------------------
 * %d    -> int
 * %ld   -> long
 * %lld  -> long long
 * %f    -> float
 * %lf   -> double
 * %c    -> char
 * %s    -> string (char array)
 * %.2f  -> 2 decimal places
 * 
 * FAST I/O TEMPLATE:
 * ------------------
 * ios_base::sync_with_stdio(false);
 * cin.tie(NULL);
 */
