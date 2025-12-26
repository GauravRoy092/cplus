/*
 * =============================================================
 * C++ BASICS - LESSON 17: STL ALGORITHMS
 * =============================================================
 * Ready-to-use algorithms for DSA problems!
 * 
 * Key Concepts:
 * - Sorting algorithms
 * - Searching algorithms
 * - Numeric algorithms
 * - Utility algorithms
 * =============================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>    // For accumulate, iota, etc.
#include <functional> // For greater, less, etc.
using namespace std;

// Custom comparator function
bool compareDesc(int a, int b) {
    return a > b;  // Descending order
}

// Custom comparator for pairs
bool comparePairs(pair<int,int> a, pair<int,int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    // ==========================================
    // SORTING ALGORITHMS
    // ==========================================
    cout << "=== SORTING ===" << endl;
    
    vector<int> arr = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    
    // Sort ascending
    sort(arr.begin(), arr.end());
    cout << "Ascending: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    // Sort descending (3 ways)
    sort(arr.begin(), arr.end(), greater<int>());
    cout << "Descending (greater<>): ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    sort(arr.begin(), arr.end(), compareDesc);
    cout << "Descending (custom func): ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    sort(arr.begin(), arr.end(), [](int a, int b) { return a > b; });
    cout << "Descending (lambda): ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    // Partial sort (first k elements)
    arr = {5, 2, 8, 1, 9, 3, 7};
    partial_sort(arr.begin(), arr.begin() + 3, arr.end());
    cout << "Partial sort (first 3): ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    // Nth element (partition around nth)
    arr = {5, 2, 8, 1, 9, 3, 7};
    nth_element(arr.begin(), arr.begin() + 3, arr.end());
    cout << "nth_element (3rd): " << arr[3] << " | Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    // Stable sort (preserves relative order of equal elements)
    vector<pair<int,int>> pairs = {{1,2}, {1,1}, {2,1}, {1,3}};
    stable_sort(pairs.begin(), pairs.end(), [](auto& a, auto& b) {
        return a.first < b.first;
    });
    cout << "Stable sort pairs: ";
    for (auto& p : pairs) cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;
    
    // Is sorted check
    vector<int> sorted = {1, 2, 3, 4, 5};
    cout << "Is sorted: " << is_sorted(sorted.begin(), sorted.end()) << endl;
    
    // ==========================================
    // SEARCHING ALGORITHMS
    // ==========================================
    cout << "\n=== SEARCHING ===" << endl;
    
    arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    // Find
    auto it = find(arr.begin(), arr.end(), 5);
    if (it != arr.end()) {
        cout << "Found 5 at index: " << (it - arr.begin()) << endl;
    }
    
    // Find if (with predicate)
    it = find_if(arr.begin(), arr.end(), [](int x) { return x > 6; });
    cout << "First element > 6: " << *it << endl;
    
    // Binary search (requires sorted array!)
    bool found = binary_search(arr.begin(), arr.end(), 7);
    cout << "Binary search for 7: " << (found ? "Found" : "Not found") << endl;
    
    // Lower bound (first element >= value)
    auto lb = lower_bound(arr.begin(), arr.end(), 5);
    cout << "lower_bound(5): index " << (lb - arr.begin()) << ", value " << *lb << endl;
    
    // Upper bound (first element > value)
    auto ub = upper_bound(arr.begin(), arr.end(), 5);
    cout << "upper_bound(5): index " << (ub - arr.begin()) << ", value " << *ub << endl;
    
    // Equal range (pair of lower_bound and upper_bound)
    vector<int> dup = {1, 2, 2, 2, 3, 4};
    auto range = equal_range(dup.begin(), dup.end(), 2);
    cout << "Count of 2s: " << (range.second - range.first) << endl;
    
    // ==========================================
    // MIN/MAX ALGORITHMS
    // ==========================================
    cout << "\n=== MIN/MAX ===" << endl;
    
    arr = {5, 2, 8, 1, 9, 3, 7};
    
    cout << "min(3, 7): " << min(3, 7) << endl;
    cout << "max(3, 7): " << max(3, 7) << endl;
    cout << "min({5, 2, 8, 1}): " << min({5, 2, 8, 1}) << endl;
    
    auto minIt = min_element(arr.begin(), arr.end());
    auto maxIt = max_element(arr.begin(), arr.end());
    cout << "Min element: " << *minIt << " at index " << (minIt - arr.begin()) << endl;
    cout << "Max element: " << *maxIt << " at index " << (maxIt - arr.begin()) << endl;
    
    // minmax returns pair
    auto mm = minmax({5, 2, 8, 1, 9});
    cout << "minmax: min=" << mm.first << ", max=" << mm.second << endl;
    
    auto mmIt = minmax_element(arr.begin(), arr.end());
    cout << "minmax_element: min=" << *mmIt.first << ", max=" << *mmIt.second << endl;
    
    // Clamp (C++17)
    // cout << "clamp(10, 1, 5): " << clamp(10, 1, 5) << endl;  // Returns 5
    
    // ==========================================
    // NUMERIC ALGORITHMS
    // ==========================================
    cout << "\n=== NUMERIC ===" << endl;
    
    arr = {1, 2, 3, 4, 5};
    
    // Accumulate (sum)
    int sum = accumulate(arr.begin(), arr.end(), 0);
    cout << "Sum: " << sum << endl;
    
    // Accumulate with custom operation (product)
    int product = accumulate(arr.begin(), arr.end(), 1, multiplies<int>());
    cout << "Product: " << product << endl;
    
    // Partial sum
    vector<int> prefixSum(arr.size());
    partial_sum(arr.begin(), arr.end(), prefixSum.begin());
    cout << "Prefix sum: ";
    for (int x : prefixSum) cout << x << " ";
    cout << endl;
    
    // Iota (fill with incrementing values)
    vector<int> seq(10);
    iota(seq.begin(), seq.end(), 1);  // 1, 2, 3, ..., 10
    cout << "Iota 1-10: ";
    for (int x : seq) cout << x << " ";
    cout << endl;
    
    // GCD and LCM
    cout << "__gcd(12, 8): " << __gcd(12, 8) << endl;  // 4
    // cout << "lcm(4, 6): " << lcm(4, 6) << endl;      // C++17
    
    // ==========================================
    // TRANSFORMATION ALGORITHMS
    // ==========================================
    cout << "\n=== TRANSFORMATIONS ===" << endl;
    
    arr = {1, 2, 3, 4, 5};
    
    // Reverse
    reverse(arr.begin(), arr.end());
    cout << "Reversed: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    // Rotate
    arr = {1, 2, 3, 4, 5};
    rotate(arr.begin(), arr.begin() + 2, arr.end());  // Move first 2 to end
    cout << "Rotated left by 2: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    // Unique (removes consecutive duplicates, must be sorted first for all dups)
    arr = {1, 1, 2, 2, 2, 3, 3, 4};
    auto newEnd = unique(arr.begin(), arr.end());
    arr.erase(newEnd, arr.end());  // Actually remove them
    cout << "After unique: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    // Remove elements
    arr = {1, 2, 3, 2, 4, 2, 5};
    newEnd = remove(arr.begin(), arr.end(), 2);
    arr.erase(newEnd, arr.end());
    cout << "After removing 2s: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    // Fill
    vector<int> filled(5);
    fill(filled.begin(), filled.end(), 7);
    cout << "Filled with 7: ";
    for (int x : filled) cout << x << " ";
    cout << endl;
    
    // Replace
    arr = {1, 2, 3, 2, 4};
    replace(arr.begin(), arr.end(), 2, 99);
    cout << "Replace 2 with 99: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    // Transform (apply function to each element)
    arr = {1, 2, 3, 4, 5};
    transform(arr.begin(), arr.end(), arr.begin(), [](int x) { return x * x; });
    cout << "Squared: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    // ==========================================
    // PERMUTATIONS
    // ==========================================
    cout << "\n=== PERMUTATIONS ===" << endl;
    
    arr = {1, 2, 3};
    cout << "All permutations:" << endl;
    do {
        for (int x : arr) cout << x << " ";
        cout << endl;
    } while (next_permutation(arr.begin(), arr.end()));
    
    // Previous permutation
    arr = {3, 2, 1};
    prev_permutation(arr.begin(), arr.end());
    cout << "Previous of {3,2,1}: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    // ==========================================
    // COUNTING & CHECKING
    // ==========================================
    cout << "\n=== COUNTING & CHECKING ===" << endl;
    
    arr = {1, 2, 2, 3, 2, 4, 2};
    
    cout << "Count of 2: " << count(arr.begin(), arr.end(), 2) << endl;
    cout << "Count > 2: " << count_if(arr.begin(), arr.end(), [](int x) { return x > 2; }) << endl;
    
    // All/any/none of
    arr = {2, 4, 6, 8};
    cout << "All even: " << all_of(arr.begin(), arr.end(), [](int x) { return x % 2 == 0; }) << endl;
    cout << "Any > 5: " << any_of(arr.begin(), arr.end(), [](int x) { return x > 5; }) << endl;
    cout << "None > 10: " << none_of(arr.begin(), arr.end(), [](int x) { return x > 10; }) << endl;
    
    return 0;
}

/*
 * QUICK REFERENCE - STL ALGORITHMS:
 * ==================================
 * 
 * SORTING:
 * sort(begin, end)                    // O(n log n)
 * sort(begin, end, comp)              // Custom comparator
 * stable_sort(begin, end)             // Preserves equal order
 * partial_sort(begin, mid, end)       // Sort first k elements
 * nth_element(begin, nth, end)        // Partition around nth
 * 
 * SEARCHING:
 * find(begin, end, val)               // O(n)
 * find_if(begin, end, pred)           // With predicate
 * binary_search(begin, end, val)      // O(log n), sorted only
 * lower_bound(begin, end, val)        // First >= val
 * upper_bound(begin, end, val)        // First > val
 * 
 * MIN/MAX:
 * min(a, b), max(a, b)
 * min_element(begin, end)
 * max_element(begin, end)
 * minmax_element(begin, end)
 * 
 * NUMERIC:
 * accumulate(begin, end, init)        // Sum
 * partial_sum(begin, end, out)        // Prefix sum
 * iota(begin, end, start)             // Fill with sequence
 * __gcd(a, b)                         // GCD
 * 
 * TRANSFORM:
 * reverse(begin, end)
 * rotate(begin, mid, end)
 * unique(begin, end)                  // Remove consecutive dups
 * remove(begin, end, val)             // Remove value
 * fill(begin, end, val)
 * replace(begin, end, old, new)
 * transform(begin, end, out, func)
 * 
 * PERMUTATIONS:
 * next_permutation(begin, end)
 * prev_permutation(begin, end)
 * 
 * COUNTING:
 * count(begin, end, val)
 * count_if(begin, end, pred)
 * all_of(begin, end, pred)
 * any_of(begin, end, pred)
 * none_of(begin, end, pred)
 */
