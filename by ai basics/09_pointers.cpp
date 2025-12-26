/*
 * =============================================================
 * C++ BASICS - LESSON 9: POINTERS & REFERENCES
 * =============================================================
 * Pointers store memory addresses. References are aliases.
 * CRITICAL for understanding DSA implementations!
 * 
 * Key Concepts:
 * - Pointer declaration & operators
 * - Pointer arithmetic
 * - References
 * - Pointers vs References
 * - Pointers with arrays
 * - Dynamic memory (new/delete)
 * =============================================================
 */

#include <iostream>
using namespace std;

int main() {
    // ==========================================
    // POINTER BASICS
    // ==========================================
    cout << "=== POINTER BASICS ===" << endl;
    
    int num = 42;
    int* ptr = &num;  // ptr stores ADDRESS of num
    
    // & - Address-of operator (gets memory address)
    // * - Dereference operator (gets value at address)
    
    cout << "num = " << num << endl;           // Value: 42
    cout << "&num = " << &num << endl;         // Address of num
    cout << "ptr = " << ptr << endl;           // Same as &num
    cout << "*ptr = " << *ptr << endl;         // Value at address: 42
    
    // Modifying value through pointer
    *ptr = 100;
    cout << "After *ptr = 100, num = " << num << endl;
    
    // ==========================================
    // POINTER DECLARATION STYLES
    // ==========================================
    cout << "\n=== POINTER STYLES ===" << endl;
    
    // All three are equivalent:
    int* p1;   // Style 1 (preferred in C++)
    int *p2;   // Style 2 (C style)
    int * p3;  // Style 3
    
    // Be careful with multiple declarations:
    int* a, b;   // a is pointer, b is NOT!
    int *c, *d;  // Both are pointers
    
    // ==========================================
    // NULL POINTERS
    // ==========================================
    cout << "\n=== NULL POINTERS ===" << endl;
    
    int* nullPtr1 = nullptr;   // C++11 way (preferred)
    int* nullPtr2 = NULL;      // Old way
    int* nullPtr3 = 0;         // Also works
    
    cout << "nullptr value: " << nullPtr1 << endl;
    
    // Always check before dereferencing!
    if (nullPtr1 != nullptr) {
        cout << *nullPtr1 << endl;  // Safe
    } else {
        cout << "Pointer is null, can't dereference!" << endl;
    }
    
    // ==========================================
    // POINTER ARITHMETIC
    // ==========================================
    cout << "\n=== POINTER ARITHMETIC ===" << endl;
    
    int arr[] = {10, 20, 30, 40, 50};
    int* arrPtr = arr;  // Points to first element
    
    cout << "arr[0] = " << *arrPtr << endl;          // 10
    cout << "arr[1] = " << *(arrPtr + 1) << endl;    // 20
    cout << "arr[2] = " << *(arrPtr + 2) << endl;    // 30
    
    // Increment pointer (moves by sizeof(int) bytes)
    arrPtr++;
    cout << "After ptr++, *arrPtr = " << *arrPtr << endl;  // 20
    
    // Difference between pointers
    int* start = arr;
    int* end = arr + 4;
    cout << "Difference: " << (end - start) << " elements" << endl;
    
    // ==========================================
    // POINTERS AND ARRAYS
    // ==========================================
    cout << "\n=== POINTERS AND ARRAYS ===" << endl;
    
    int arr2[] = {1, 2, 3, 4, 5};
    int* p = arr2;  // Array name is pointer to first element
    
    // These are equivalent:
    cout << "arr2[2] = " << arr2[2] << endl;
    cout << "*(arr2 + 2) = " << *(arr2 + 2) << endl;
    cout << "*(p + 2) = " << *(p + 2) << endl;
    cout << "p[2] = " << p[2] << endl;
    
    // Iterating with pointers
    cout << "Array via pointers: ";
    for (int* it = arr2; it != arr2 + 5; it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    // ==========================================
    // REFERENCES
    // ==========================================
    cout << "\n=== REFERENCES ===" << endl;
    
    int original = 100;
    int& ref = original;  // ref is an ALIAS for original
    
    cout << "original = " << original << endl;
    cout << "ref = " << ref << endl;
    
    // Modifying through reference
    ref = 200;
    cout << "After ref = 200:" << endl;
    cout << "original = " << original << endl;  // Also 200!
    cout << "ref = " << ref << endl;
    
    // Both have the same address
    cout << "&original = " << &original << endl;
    cout << "&ref = " << &ref << endl;  // Same address!
    
    // ==========================================
    // REFERENCES VS POINTERS
    // ==========================================
    cout << "\n=== REFERENCES VS POINTERS ===" << endl;
    
    /*
     * REFERENCES:
     * - Must be initialized when declared
     * - Cannot be NULL
     * - Cannot be reassigned to another variable
     * - No pointer arithmetic
     * - Cleaner syntax (no *, &)
     * 
     * POINTERS:
     * - Can be uninitialized
     * - Can be NULL
     * - Can be reassigned
     * - Pointer arithmetic allowed
     * - More flexible, but more dangerous
     */
    
    int x = 10, y = 20;
    
    // Pointer can be reassigned
    int* ptrXY = &x;
    cout << "*ptrXY = " << *ptrXY << endl;  // 10
    ptrXY = &y;  // Now points to y
    cout << "*ptrXY = " << *ptrXY << endl;  // 20
    
    // Reference cannot be reassigned
    int& refX = x;
    // refX = y;  // This assigns y's VALUE to x, doesn't rebind!
    
    // ==========================================
    // PASS BY VALUE, POINTER, REFERENCE
    // ==========================================
    cout << "\n=== PASSING TO FUNCTIONS ===" << endl;
    
    // Demonstrating with lambda functions
    int val = 10;
    
    // Pass by value - no change to original
    auto byValue = [](int n) { n = 100; };
    byValue(val);
    cout << "After byValue: val = " << val << endl;  // Still 10
    
    // Pass by pointer - modifies original
    auto byPointer = [](int* n) { *n = 100; };
    byPointer(&val);
    cout << "After byPointer: val = " << val << endl;  // Now 100
    
    val = 10;  // Reset
    
    // Pass by reference - modifies original
    auto byReference = [](int& n) { n = 100; };
    byReference(val);
    cout << "After byReference: val = " << val << endl;  // Now 100
    
    // ==========================================
    // DYNAMIC MEMORY (new/delete)
    // ==========================================
    cout << "\n=== DYNAMIC MEMORY ===" << endl;
    
    // Allocate single variable
    int* dynInt = new int;      // Allocate memory
    *dynInt = 42;
    cout << "Dynamic int: " << *dynInt << endl;
    delete dynInt;               // Free memory (IMPORTANT!)
    dynInt = nullptr;            // Good practice
    
    // Allocate with initialization
    int* dynInt2 = new int(100);
    cout << "Initialized dynamic int: " << *dynInt2 << endl;
    delete dynInt2;
    
    // Allocate array
    int n = 5;
    int* dynArr = new int[n];   // Dynamic array of size 5
    
    // Initialize and use
    for (int i = 0; i < n; i++) {
        dynArr[i] = i * 10;
    }
    
    cout << "Dynamic array: ";
    for (int i = 0; i < n; i++) {
        cout << dynArr[i] << " ";
    }
    cout << endl;
    
    delete[] dynArr;             // Use delete[] for arrays!
    dynArr = nullptr;
    
    // ==========================================
    // POINTER TO POINTER
    // ==========================================
    cout << "\n=== POINTER TO POINTER ===" << endl;
    
    int value = 42;
    int* ptr1 = &value;
    int** ptr2ptr = &ptr1;  // Pointer to pointer
    
    cout << "value = " << value << endl;
    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "**ptr2ptr = " << **ptr2ptr << endl;
    
    // ==========================================
    // CONST WITH POINTERS
    // ==========================================
    cout << "\n=== CONST WITH POINTERS ===" << endl;
    
    int number = 10;
    int another = 20;
    
    // Pointer to const int - can't modify value through pointer
    const int* ptrToConst = &number;
    // *ptrToConst = 50;  // ERROR!
    ptrToConst = &another;  // OK - can change what it points to
    
    // Const pointer - can't change where it points
    int* const constPtr = &number;
    *constPtr = 50;  // OK - can modify value
    // constPtr = &another;  // ERROR!
    
    // Const pointer to const int - can't change either
    const int* const constPtrToConst = &number;
    // *constPtrToConst = 50;  // ERROR!
    // constPtrToConst = &another;  // ERROR!
    
    cout << "Const examples work correctly!" << endl;
    
    return 0;
}

/*
 * QUICK REFERENCE - POINTERS & REFERENCES:
 * ========================================
 * 
 * POINTERS:
 * int* ptr;         // Declare pointer
 * ptr = &var;       // Get address of var
 * *ptr              // Dereference (get value)
 * ptr++             // Move to next element
 * ptr = nullptr;    // Null pointer
 * 
 * REFERENCES:
 * int& ref = var;   // Must initialize
 * ref               // Use like normal variable
 * 
 * DYNAMIC MEMORY:
 * int* p = new int;         // Allocate
 * int* arr = new int[n];    // Allocate array
 * delete p;                 // Free single
 * delete[] arr;             // Free array
 * 
 * CONST WITH POINTERS:
 * const int* p;     // Pointer to const (can't change value)
 * int* const p;     // Const pointer (can't change address)
 * const int* const p; // Both const
 * 
 * IMPORTANT FOR DSA:
 * - Linked lists use pointers for node connections
 * - Trees/graphs use pointers extensively
 * - Dynamic arrays need new/delete
 * - Always delete what you new!
 * - Use nullptr instead of NULL
 * - Prefer references for function parameters when possible
 */
