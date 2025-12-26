/*
 * =============================================================
 * C++ BASICS - LESSON 10: STRINGS
 * =============================================================
 * Two types: C-style strings and std::string
 * 
 * Key Concepts:
 * - C-style strings (char arrays)
 * - std::string class
 * - String operations
 * - String manipulation
 * - Common string algorithms
 * =============================================================
 */

#include <iostream>
#include <string>      // For std::string
#include <cstring>     // For C-style string functions
#include <algorithm>   // For transform, reverse
#include <cctype>      // For toupper, tolower
using namespace std;

int main() {
    // ==========================================
    // C-STYLE STRINGS (Character Arrays)
    // ==========================================
    cout << "=== C-STYLE STRINGS ===" << endl;
    
    // Declaration and initialization
    char str1[] = "Hello";              // Size 6 (includes '\0')
    char str2[10] = "World";            // Size 10, only 6 used
    char str3[] = {'H', 'i', '\0'};     // Manual initialization
    
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    
    // C-string functions (from <cstring>)
    char src[] = "Hello";
    char dest[50];
    
    cout << "strlen(src): " << strlen(src) << endl;     // Length: 5
    
    strcpy(dest, src);  // Copy src to dest
    cout << "After strcpy, dest: " << dest << endl;
    
    strcat(dest, " World");  // Concatenate
    cout << "After strcat, dest: " << dest << endl;
    
    char cmp1[] = "abc";
    char cmp2[] = "abd";
    cout << "strcmp(abc, abd): " << strcmp(cmp1, cmp2) << endl;  // Negative
    
    // ==========================================
    // STD::STRING (Preferred in C++)
    // ==========================================
    cout << "\n=== STD::STRING ===" << endl;
    
    // Declaration and initialization
    string s1;                      // Empty string
    string s2 = "Hello";            // Initialization
    string s3("World");             // Constructor
    string s4(5, 'x');              // "xxxxx" (5 x's)
    string s5 = s2;                 // Copy
    
    cout << "s1 (empty): '" << s1 << "'" << endl;
    cout << "s2: " << s2 << endl;
    cout << "s4 (5 x's): " << s4 << endl;
    
    // ==========================================
    // STRING PROPERTIES
    // ==========================================
    cout << "\n=== STRING PROPERTIES ===" << endl;
    
    string text = "Hello World";
    
    cout << "Length: " << text.length() << endl;        // 11
    cout << "Size: " << text.size() << endl;            // Same as length
    cout << "Empty: " << text.empty() << endl;          // false (0)
    cout << "Capacity: " << text.capacity() << endl;    // May be >= size
    
    cout << "First char: " << text.front() << endl;     // 'H'
    cout << "Last char: " << text.back() << endl;       // 'd'
    
    // ==========================================
    // ACCESSING CHARACTERS
    // ==========================================
    cout << "\n=== ACCESSING CHARACTERS ===" << endl;
    
    string str = "Hello";
    
    // Using index
    cout << "str[0]: " << str[0] << endl;       // 'H'
    cout << "str[4]: " << str[4] << endl;       // 'o'
    
    // Using at() - with bounds checking
    cout << "str.at(1): " << str.at(1) << endl; // 'e'
    
    // Modifying characters
    str[0] = 'J';
    cout << "After str[0]='J': " << str << endl;  // "Jello"
    
    // Iterating
    cout << "Characters: ";
    for (char c : str) {
        cout << c << " ";
    }
    cout << endl;
    
    // ==========================================
    // STRING OPERATIONS
    // ==========================================
    cout << "\n=== STRING OPERATIONS ===" << endl;
    
    string a = "Hello";
    string b = " World";
    
    // Concatenation
    string concat = a + b;
    cout << "a + b: " << concat << endl;
    
    // Append
    a += "!!!";
    cout << "a += '!!!': " << a << endl;
    
    a.append(" C++");
    cout << "a.append(' C++'): " << a << endl;
    
    // Compare
    string x = "apple";
    string y = "banana";
    cout << "apple < banana: " << (x < y) << endl;      // true (1)
    cout << "apple == apple: " << (x == "apple") << endl;  // true
    cout << "compare: " << x.compare(y) << endl;        // Negative
    
    // ==========================================
    // SUBSTRING & FIND
    // ==========================================
    cout << "\n=== SUBSTRING & FIND ===" << endl;
    
    string sentence = "The quick brown fox";
    
    // substr(start, length)
    cout << "substr(4, 5): " << sentence.substr(4, 5) << endl;  // "quick"
    cout << "substr(10): " << sentence.substr(10) << endl;       // "brown fox"
    
    // find - returns position or string::npos if not found
    size_t pos = sentence.find("quick");
    cout << "Position of 'quick': " << pos << endl;  // 4
    
    pos = sentence.find("slow");
    if (pos == string::npos) {
        cout << "'slow' not found" << endl;
    }
    
    // rfind - find from end
    string text2 = "hello hello hello";
    cout << "Last 'hello' at: " << text2.rfind("hello") << endl;  // 12
    
    // find_first_of / find_last_of
    string vowels = "aeiou";
    cout << "First vowel at: " << sentence.find_first_of(vowels) << endl;
    
    // ==========================================
    // INSERT, ERASE, REPLACE
    // ==========================================
    cout << "\n=== INSERT, ERASE, REPLACE ===" << endl;
    
    string modify = "Hello World";
    
    // Insert at position
    modify.insert(5, " Beautiful");
    cout << "After insert: " << modify << endl;  // "Hello Beautiful World"
    
    // Erase (position, length)
    modify.erase(5, 10);  // Remove " Beautiful"
    cout << "After erase: " << modify << endl;   // "Hello World"
    
    // Replace (position, length, new_string)
    modify.replace(6, 5, "C++");
    cout << "After replace: " << modify << endl;  // "Hello C++"
    
    // Clear
    string toClear = "Some text";
    toClear.clear();
    cout << "After clear, empty: " << toClear.empty() << endl;
    
    // ==========================================
    // STRING INPUT
    // ==========================================
    cout << "\n=== STRING INPUT ===" << endl;
    
    string word, line;
    
    // Note: cin >> reads until whitespace
    // getline(cin, line) reads entire line
    
    cout << "Demo strings for input:" << endl;
    cout << "Use 'cin >> word' for single words" << endl;
    cout << "Use 'getline(cin, line)' for full lines" << endl;
    
    // ==========================================
    // STRING CONVERSIONS
    // ==========================================
    cout << "\n=== STRING CONVERSIONS ===" << endl;
    
    // String to number
    string numStr = "123";
    int num = stoi(numStr);         // string to int
    cout << "stoi('123'): " << num << endl;
    
    long lng = stol("1234567890");  // string to long
    double dbl = stod("3.14159");   // string to double
    float flt = stof("2.5");        // string to float
    cout << "stod('3.14159'): " << dbl << endl;
    
    // Number to string
    int n = 42;
    string nStr = to_string(n);
    cout << "to_string(42): " << nStr << endl;
    
    double d = 3.14159;
    string dStr = to_string(d);
    cout << "to_string(3.14159): " << dStr << endl;
    
    // ==========================================
    // CASE CONVERSION
    // ==========================================
    cout << "\n=== CASE CONVERSION ===" << endl;
    
    string mixed = "HeLLo WoRLd";
    
    // To uppercase
    string upper = mixed;
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    cout << "Uppercase: " << upper << endl;
    
    // To lowercase
    string lower = mixed;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    cout << "Lowercase: " << lower << endl;
    
    // ==========================================
    // PRACTICAL EXAMPLES
    // ==========================================
    cout << "\n=== PRACTICAL EXAMPLES ===" << endl;
    
    // Example 1: Reverse a string
    string toReverse = "Hello";
    reverse(toReverse.begin(), toReverse.end());
    cout << "Reversed: " << toReverse << endl;
    
    // Example 2: Check palindrome
    string palindrome = "racecar";
    string reversed = palindrome;
    reverse(reversed.begin(), reversed.end());
    cout << palindrome << " is palindrome: " << (palindrome == reversed) << endl;
    
    // Example 3: Count occurrences of a character
    string countStr = "hello world";
    int count = 0;
    for (char c : countStr) {
        if (c == 'l') count++;
    }
    cout << "'l' appears " << count << " times" << endl;
    
    // Example 4: Split by character (simple)
    string toSplit = "apple,banana,cherry";
    size_t start = 0;
    size_t end = 0;
    cout << "Split by comma: ";
    while ((end = toSplit.find(',', start)) != string::npos) {
        cout << toSplit.substr(start, end - start) << " ";
        start = end + 1;
    }
    cout << toSplit.substr(start) << endl;  // Last part
    
    return 0;
}

/*
 * QUICK REFERENCE - STRINGS:
 * ==========================
 * 
 * DECLARATION:
 * string s = "hello";
 * string s(5, 'x');      // "xxxxx"
 * 
 * PROPERTIES:
 * s.length() / s.size()  // Length
 * s.empty()              // Check if empty
 * s[i] / s.at(i)        // Access character
 * s.front() / s.back()   // First/last char
 * 
 * OPERATIONS:
 * s1 + s2               // Concatenate
 * s += "text"           // Append
 * s.append("text")      // Append
 * s.substr(pos, len)    // Substring
 * s.find("text")        // Find (returns npos if not found)
 * s.replace(pos,len,new) // Replace
 * s.insert(pos, "text") // Insert
 * s.erase(pos, len)     // Erase
 * s.clear()             // Clear
 * 
 * CONVERSIONS:
 * stoi(s), stol(s), stod(s), stof(s)  // String to number
 * to_string(num)                       // Number to string
 * 
 * ALGORITHMS:
 * reverse(s.begin(), s.end())
 * sort(s.begin(), s.end())
 * transform(s.begin(), s.end(), s.begin(), ::toupper)
 * 
 * IMPORTANT FOR DSA:
 * - string::npos is the not-found value
 * - Strings are mutable in C++
 * - Use .at() for bounds checking
 * - substr returns a copy
 */
