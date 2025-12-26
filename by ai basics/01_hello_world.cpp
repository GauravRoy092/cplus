/*
 * =============================================================
 * C++ BASICS - LESSON 1: HELLO WORLD
 * =============================================================
 * Your first C++ program!
 * 
 * Key Concepts:
 * - #include directive (imports)
 * - main() function (entry point)
 * - cout for output
 * - Semicolons and basic syntax
 * =============================================================
 */

#include <iostream>  // Standard Input/Output library
using namespace std; // Allows us to use cout without std::

// main() - Entry point of every C++ program
int main() {
    // cout - Character output (prints to console)
    // << - Insertion operator (sends data to cout)
    // endl - Ends line and flushes buffer
    
    cout << "Hello, World!" << endl;
    cout << "Welcome to C++ Programming!" << endl;
    
    // Multiple outputs on same line
    cout << "Name: " << "Gaurav" << ", Learning: " << "C++" << endl;
    
    // Using \n instead of endl (faster, no buffer flush)
    cout << "Line 1\nLine 2\nLine 3\n";
    
    // return 0 indicates successful execution
    return 0;
}

/*
 * QUICK REFERENCE:
 * ----------------
 * #include <iostream>  -> Import I/O library
 * using namespace std; -> Use standard namespace
 * cout << "text";      -> Print text
 * endl or \n           -> New line
 * return 0;            -> Program ended successfully
 * 
 * COMPILE: g++ 01_hello_world.cpp -o hello
 * RUN:     ./hello
 */
