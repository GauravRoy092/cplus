/*
 * =============================================================
 * C++ BASICS - LESSON 8: ARRAYS
 * =============================================================
 * Arrays store multiple values of the same type.
 * 
 * Key Concepts:
 * - Array declaration & initialization
 * - Accessing elements
 * - Multidimensional arrays
 * - Arrays with functions
 * - Common operations
 * =============================================================
 */

#include <iostream>
#include <algorithm>  // For sort, reverse, etc.
using namespace std;

// Function declarations
void printArray(int arr[], int size);
int findMax(int arr[], int size);
void reverseArray(int arr[], int size);

int main() {
    // ==========================================
    // ARRAY DECLARATION & INITIALIZATION
    // ==========================================
    cout << "=== ARRAY BASICS ===" << endl;
    
    // Method 1: Declare with size
    int numbers[5];  // Array of 5 integers (uninitialized - garbage values)
    
    // Method 2: Declare and initialize
    int scores[5] = {90, 85, 78, 92, 88};
    
    // Method 3: Partial initialization (rest become 0)
    int partial[5] = {1, 2};  // {1, 2, 0, 0, 0}
    
    // Method 4: Initialize all to zero
    int zeros[5] = {0};  // All elements are 0
    
    // Method 5: Let compiler determine size
    int autoSize[] = {1, 2, 3, 4, 5};  // Size is 5
    
    // ==========================================
    // ACCESSING ELEMENTS
    // ==========================================
    cout << "\n=== ACCESSING ELEMENTS ===" << endl;
    
    // Indices start from 0
    cout << "scores[0] = " << scores[0] << endl;  // First element
    cout << "scores[4] = " << scores[4] << endl;  // Last element
    
    // Modifying elements
    scores[0] = 95;  // Change first element
    cout << "After modification, scores[0] = " << scores[0] << endl;
    
    // ==========================================
    // ARRAY SIZE
    // ==========================================
    cout << "\n=== ARRAY SIZE ===" << endl;
    
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);  // Total bytes / bytes per element
    cout << "Array size: " << size << endl;
    
    // ==========================================
    // LOOPING THROUGH ARRAYS
    // ==========================================
    cout << "\n=== LOOPING THROUGH ARRAYS ===" << endl;
    
    // Method 1: Traditional for loop
    cout << "Using for loop: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Method 2: Range-based for loop (C++11)
    cout << "Using range-based for: ";
    for (int elem : arr) {
        cout << elem << " ";
    }
    cout << endl;
    
    // Method 3: While loop
    cout << "Using while loop: ";
    int i = 0;
    while (i < size) {
        cout << arr[i] << " ";
        i++;
    }
    cout << endl;
    
    // ==========================================
    // ARRAYS WITH FUNCTIONS
    // ==========================================
    cout << "\n=== ARRAYS WITH FUNCTIONS ===" << endl;
    
    int data[] = {5, 2, 8, 1, 9, 3, 7};
    int dataSize = sizeof(data) / sizeof(data[0]);
    
    cout << "Original array: ";
    printArray(data, dataSize);
    
    cout << "Maximum value: " << findMax(data, dataSize) << endl;
    
    reverseArray(data, dataSize);
    cout << "Reversed array: ";
    printArray(data, dataSize);
    
    // ==========================================
    // MULTIDIMENSIONAL ARRAYS
    // ==========================================
    cout << "\n=== 2D ARRAYS ===" << endl;
    
    // Declaration: type name[rows][cols]
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // Accessing elements
    cout << "matrix[0][0] = " << matrix[0][0] << endl;  // 1
    cout << "matrix[1][2] = " << matrix[1][2] << endl;  // 7
    cout << "matrix[2][3] = " << matrix[2][3] << endl;  // 12
    
    // Printing 2D array
    cout << "\nMatrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    // ==========================================
    // COMMON ARRAY OPERATIONS
    // ==========================================
    cout << "\n=== COMMON OPERATIONS ===" << endl;
    
    int arr2[] = {5, 2, 8, 1, 9};
    int n = 5;
    
    // Sum of elements
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr2[i];
    }
    cout << "Sum: " << sum << endl;
    
    // Find minimum
    int minVal = arr2[0];
    for (int i = 1; i < n; i++) {
        if (arr2[i] < minVal) minVal = arr2[i];
    }
    cout << "Minimum: " << minVal << endl;
    
    // Sorting (using STL)
    sort(arr2, arr2 + n);  // Sorts in ascending order
    cout << "Sorted: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
    
    // Reverse (using STL)
    reverse(arr2, arr2 + n);
    cout << "Reversed: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
    
    // Linear search
    int target = 5;
    int found = -1;
    int searchArr[] = {3, 7, 5, 2, 9};
    for (int i = 0; i < 5; i++) {
        if (searchArr[i] == target) {
            found = i;
            break;
        }
    }
    if (found != -1) {
        cout << target << " found at index " << found << endl;
    } else {
        cout << target << " not found" << endl;
    }
    
    // ==========================================
    // CHARACTER ARRAYS (C-Strings)
    // ==========================================
    cout << "\n=== CHARACTER ARRAYS ===" << endl;
    
    char name[] = "Hello";  // Automatically adds '\0' at end
    char name2[10] = {'H', 'i', '\0'};  // Manual null terminator
    
    cout << "name: " << name << endl;
    cout << "name2: " << name2 << endl;
    cout << "name[0]: " << name[0] << endl;
    
    // String length (C-style)
    int len = 0;
    while (name[len] != '\0') len++;
    cout << "Length of 'Hello': " << len << endl;
    
    return 0;
}

// ==========================================
// FUNCTION DEFINITIONS
// ==========================================

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void reverseArray(int arr[], int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        // Swap elements
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/*
 * QUICK REFERENCE - ARRAYS:
 * =========================
 * 
 * DECLARATION:
 * int arr[5];                    // Uninitialized
 * int arr[5] = {1, 2, 3, 4, 5};  // Initialized
 * int arr[] = {1, 2, 3};         // Size inferred
 * int arr[5] = {0};              // All zeros
 * 
 * 2D ARRAYS:
 * int matrix[3][4];              // 3 rows, 4 columns
 * int matrix[2][3] = {{1,2,3}, {4,5,6}};
 * 
 * SIZE:
 * int size = sizeof(arr) / sizeof(arr[0]);
 * 
 * PASSING TO FUNCTIONS:
 * void func(int arr[], int size);  // Size needed separately
 * 
 * STL ALGORITHMS:
 * sort(arr, arr + n);              // Sort ascending
 * sort(arr, arr + n, greater<int>()); // Sort descending
 * reverse(arr, arr + n);           // Reverse array
 * 
 * IMPORTANT FOR DSA:
 * - Arrays are passed by pointer (modifications affect original)
 * - No bounds checking - be careful!
 * - Use vectors for dynamic sizing
 * - arr[i] is equivalent to *(arr + i)
 */
