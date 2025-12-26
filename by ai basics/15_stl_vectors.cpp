/*
 * =============================================================
 * C++ BASICS - LESSON 15: STL VECTORS
 * =============================================================
 * Vectors are dynamic arrays - THE most used container for DSA!
 * 
 * Key Concepts:
 * - Vector declaration
 * - Common operations
 * - Iterators
 * - 2D vectors
 * =============================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>  // For sort, find, etc.
using namespace std;

int main() {
    // ==========================================
    // VECTOR DECLARATION & INITIALIZATION
    // ==========================================
    cout << "=== VECTOR BASICS ===" << endl;
    
    // Empty vector
    vector<int> v1;
    
    // Vector with initial size (all elements = 0)
    vector<int> v2(5);
    
    // Vector with size and initial value
    vector<int> v3(5, 10);  // 5 elements, all = 10
    
    // Initialize with values
    vector<int> v4 = {1, 2, 3, 4, 5};
    
    // Copy constructor
    vector<int> v5(v4);
    
    // From array
    int arr[] = {10, 20, 30};
    vector<int> v6(arr, arr + 3);
    
    // Print v3
    cout << "v3 (5 elements of 10): ";
    for (int x : v3) cout << x << " ";
    cout << endl;
    
    // Print v4
    cout << "v4: ";
    for (int x : v4) cout << x << " ";
    cout << endl;
    
    // ==========================================
    // BASIC OPERATIONS
    // ==========================================
    cout << "\n=== BASIC OPERATIONS ===" << endl;
    
    vector<int> nums = {10, 20, 30};
    
    // Add elements
    nums.push_back(40);  // Add at end
    nums.push_back(50);
    cout << "After push_back: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    
    // Remove last element
    nums.pop_back();
    cout << "After pop_back: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    
    // Access elements
    cout << "First element (front): " << nums.front() << endl;
    cout << "Last element (back): " << nums.back() << endl;
    cout << "Element at index 2: " << nums[2] << endl;
    cout << "Using at(2): " << nums.at(2) << endl;  // With bounds checking
    
    // Size and capacity
    cout << "Size: " << nums.size() << endl;
    cout << "Capacity: " << nums.capacity() << endl;
    cout << "Empty: " << (nums.empty() ? "Yes" : "No") << endl;
    
    // ==========================================
    // MODIFYING ELEMENTS
    // ==========================================
    cout << "\n=== MODIFYING ELEMENTS ===" << endl;
    
    vector<int> data = {1, 2, 3, 4, 5};
    
    // Modify using index
    data[0] = 100;
    cout << "After data[0] = 100: ";
    for (int x : data) cout << x << " ";
    cout << endl;
    
    // Insert at position
    data.insert(data.begin() + 2, 999);  // Insert 999 at index 2
    cout << "After insert at index 2: ";
    for (int x : data) cout << x << " ";
    cout << endl;
    
    // Erase element
    data.erase(data.begin() + 2);  // Remove element at index 2
    cout << "After erase at index 2: ";
    for (int x : data) cout << x << " ";
    cout << endl;
    
    // Erase range
    data.erase(data.begin() + 1, data.begin() + 3);  // Remove index 1 and 2
    cout << "After erase range [1,3): ";
    for (int x : data) cout << x << " ";
    cout << endl;
    
    // Clear all elements
    vector<int> toClear = {1, 2, 3};
    toClear.clear();
    cout << "After clear, size: " << toClear.size() << endl;
    
    // ==========================================
    // ITERATORS
    // ==========================================
    cout << "\n=== ITERATORS ===" << endl;
    
    vector<int> vec = {10, 20, 30, 40, 50};
    
    // Using iterator
    cout << "Using iterator: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Using auto (preferred)
    cout << "Using auto iterator: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Reverse iterator
    cout << "Reverse: ";
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Const iterator (for read-only)
    cout << "Const iterator: ";
    for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
        cout << *it << " ";
        // *it = 100;  // ERROR! const iterator
    }
    cout << endl;
    
    // ==========================================
    // ALGORITHMS WITH VECTORS
    // ==========================================
    cout << "\n=== ALGORITHMS ===" << endl;
    
    vector<int> arr1 = {5, 2, 8, 1, 9, 3, 7};
    
    // Sort ascending
    sort(arr1.begin(), arr1.end());
    cout << "Sorted ascending: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    
    // Sort descending
    sort(arr1.begin(), arr1.end(), greater<int>());
    cout << "Sorted descending: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    
    // Reverse
    reverse(arr1.begin(), arr1.end());
    cout << "Reversed: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    
    // Find element
    auto it = find(arr1.begin(), arr1.end(), 5);
    if (it != arr1.end()) {
        cout << "Found 5 at index: " << (it - arr1.begin()) << endl;
    }
    
    // Binary search (requires sorted array)
    sort(arr1.begin(), arr1.end());
    bool found = binary_search(arr1.begin(), arr1.end(), 7);
    cout << "Binary search for 7: " << (found ? "Found" : "Not found") << endl;
    
    // Min and max
    cout << "Min: " << *min_element(arr1.begin(), arr1.end()) << endl;
    cout << "Max: " << *max_element(arr1.begin(), arr1.end()) << endl;
    
    // Count occurrences
    vector<int> freq = {1, 2, 2, 3, 2, 4, 2};
    cout << "Count of 2: " << count(freq.begin(), freq.end(), 2) << endl;
    
    // Accumulate (sum)
    #include <numeric>  // For accumulate
    // int sum = accumulate(arr1.begin(), arr1.end(), 0);  // Needs <numeric>
    
    // ==========================================
    // 2D VECTORS (VERY IMPORTANT FOR DSA!)
    // ==========================================
    cout << "\n=== 2D VECTORS ===" << endl;
    
    // Declaration methods
    vector<vector<int>> matrix1;  // Empty 2D vector
    
    // Fixed size 2D vector
    int rows = 3, cols = 4;
    vector<vector<int>> matrix2(rows, vector<int>(cols, 0));  // 3x4, all 0
    
    // Initialize with values
    vector<vector<int>> matrix3 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Access elements
    cout << "matrix3[1][2] = " << matrix3[1][2] << endl;  // 6
    
    // Print 2D vector
    cout << "Matrix:" << endl;
    for (int i = 0; i < matrix3.size(); i++) {
        for (int j = 0; j < matrix3[i].size(); j++) {
            cout << matrix3[i][j] << " ";
        }
        cout << endl;
    }
    
    // Using range-based for
    cout << "Using range-based for:" << endl;
    for (auto& row : matrix3) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    // Adding rows
    matrix3.push_back({10, 11, 12});
    cout << "After adding row, rows: " << matrix3.size() << endl;
    
    // Jagged array (rows with different sizes)
    vector<vector<int>> jagged;
    jagged.push_back({1, 2});
    jagged.push_back({3, 4, 5, 6});
    jagged.push_back({7});
    
    cout << "Jagged array:" << endl;
    for (auto& row : jagged) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    
    // ==========================================
    // IMPORTANT TIPS FOR DSA
    // ==========================================
    cout << "\n=== DSA TIPS ===" << endl;
    
    // Pre-allocate for efficiency
    vector<int> efficient;
    efficient.reserve(1000);  // Allocates space for 1000 elements
    cout << "Reserved capacity: " << efficient.capacity() << endl;
    
    // Resize
    vector<int> resizable(5, 1);
    resizable.resize(10, 2);  // Now size 10, new elements = 2
    cout << "After resize: ";
    for (int x : resizable) cout << x << " ";
    cout << endl;
    
    // Swap (O(1))
    vector<int> a = {1, 2, 3};
    vector<int> b = {4, 5, 6};
    a.swap(b);  // Efficiently swaps
    cout << "After swap, a: ";
    for (int x : a) cout << x << " ";
    cout << endl;
    
    // Assign
    vector<int> assigned;
    assigned.assign(5, 100);  // 5 elements of 100
    cout << "Assigned: ";
    for (int x : assigned) cout << x << " ";
    cout << endl;
    
    return 0;
}

/*
 * QUICK REFERENCE - VECTORS:
 * ==========================
 * 
 * DECLARATION:
 * vector<int> v;                    // Empty
 * vector<int> v(n);                 // Size n, default values
 * vector<int> v(n, val);            // Size n, all = val
 * vector<int> v = {1, 2, 3};        // Initialize with values
 * vector<vector<int>> v(r, vector<int>(c)); // 2D
 * 
 * ACCESS:
 * v[i], v.at(i), v.front(), v.back()
 * 
 * ADD/REMOVE:
 * v.push_back(x)                    // Add at end O(1)
 * v.pop_back()                      // Remove from end O(1)
 * v.insert(pos, val)                // Insert at position O(n)
 * v.erase(pos)                      // Erase at position O(n)
 * v.clear()                         // Remove all
 * 
 * SIZE:
 * v.size(), v.capacity(), v.empty()
 * v.resize(n), v.reserve(n)
 * 
 * ALGORITHMS:
 * sort(v.begin(), v.end())
 * sort(v.begin(), v.end(), greater<int>())  // Descending
 * reverse(v.begin(), v.end())
 * find(v.begin(), v.end(), val)
 * binary_search(v.begin(), v.end(), val)
 * *min_element(v.begin(), v.end())
 * *max_element(v.begin(), v.end())
 * count(v.begin(), v.end(), val)
 * 
 * TIME COMPLEXITY:
 * - push_back/pop_back: O(1) amortized
 * - Access by index: O(1)
 * - Insert/erase: O(n)
 * - Find: O(n), Binary search: O(log n)
 * - Sort: O(n log n)
 */
