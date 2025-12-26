/*
 * =============================================================
 * C++ BASICS - LESSON 16: STL MAPS & SETS
 * =============================================================
 * Essential containers for DSA - fast lookups!
 * 
 * Key Concepts:
 * - map (ordered key-value pairs)
 * - unordered_map (hash map - faster!)
 * - set (unique ordered elements)
 * - unordered_set (hash set)
 * - multimap/multiset
 * =============================================================
 */

#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    // ==========================================
    // MAP (Ordered, Red-Black Tree)
    // ==========================================
    cout << "=== MAP ===" << endl;
    
    // Declaration
    map<string, int> ages;
    
    // Insert elements
    ages["Alice"] = 25;
    ages["Bob"] = 30;
    ages.insert({"Charlie", 28});
    ages.insert(make_pair("David", 22));
    
    // Access elements
    cout << "Alice's age: " << ages["Alice"] << endl;
    cout << "Bob's age: " << ages.at("Bob") << endl;
    
    // Check if key exists
    if (ages.find("Eve") != ages.end()) {
        cout << "Eve found" << endl;
    } else {
        cout << "Eve not found" << endl;
    }
    
    // count() returns 0 or 1 for map
    cout << "Count of 'Alice': " << ages.count("Alice") << endl;
    
    // Iterate (ordered by key!)
    cout << "All entries (sorted by key):" << endl;
    for (auto& pair : ages) {
        cout << "  " << pair.first << ": " << pair.second << endl;
    }
    
    // Using structured bindings (C++17)
    cout << "Using structured bindings:" << endl;
    for (auto& [name, age] : ages) {
        cout << "  " << name << " is " << age << " years old" << endl;
    }
    
    // Size and empty
    cout << "Size: " << ages.size() << endl;
    cout << "Empty: " << ages.empty() << endl;
    
    // Erase
    ages.erase("David");
    cout << "After erasing David, size: " << ages.size() << endl;
    
    // Clear
    // ages.clear();  // Removes all elements
    
    // ==========================================
    // UNORDERED_MAP (Hash Map - FASTER!)
    // ==========================================
    cout << "\n=== UNORDERED_MAP ===" << endl;
    
    unordered_map<string, int> scores;
    
    scores["Math"] = 95;
    scores["Science"] = 88;
    scores["English"] = 92;
    scores["History"] = 85;
    
    // Same operations as map
    cout << "Math score: " << scores["Math"] << endl;
    
    // Iterate (NOT ordered!)
    cout << "All scores (unordered):" << endl;
    for (auto& [subject, score] : scores) {
        cout << "  " << subject << ": " << score << endl;
    }
    
    // Check and insert
    if (scores.find("Art") == scores.end()) {
        scores["Art"] = 90;
    }
    
    // Frequency counter - COMMON DSA PATTERN!
    cout << "\n--- Frequency Counter Example ---" << endl;
    string text = "hello world";
    unordered_map<char, int> freq;
    
    for (char c : text) {
        freq[c]++;  // Auto-initializes to 0 if not exists
    }
    
    cout << "Character frequencies in '" << text << "':" << endl;
    for (auto& [ch, count] : freq) {
        cout << "  '" << ch << "': " << count << endl;
    }
    
    // ==========================================
    // SET (Ordered, Unique Elements)
    // ==========================================
    cout << "\n=== SET ===" << endl;
    
    set<int> numbers;
    
    // Insert
    numbers.insert(5);
    numbers.insert(2);
    numbers.insert(8);
    numbers.insert(1);
    numbers.insert(5);  // Duplicate - won't be added!
    
    // Iterate (sorted!)
    cout << "Set elements (sorted): ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;
    
    // Check if exists
    if (numbers.count(5)) {
        cout << "5 is in the set" << endl;
    }
    
    // Find
    auto it = numbers.find(8);
    if (it != numbers.end()) {
        cout << "Found: " << *it << endl;
    }
    
    // Erase
    numbers.erase(2);
    cout << "After erasing 2: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;
    
    // Lower/upper bound (useful for DSA!)
    numbers.insert(3);
    numbers.insert(7);
    numbers.insert(10);
    
    cout << "Set: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;
    
    auto lb = numbers.lower_bound(6);  // First element >= 6
    auto ub = numbers.upper_bound(6);  // First element > 6
    cout << "lower_bound(6): " << *lb << endl;  // 7
    cout << "upper_bound(6): " << *ub << endl;  // 7
    
    lb = numbers.lower_bound(7);  // First >= 7
    ub = numbers.upper_bound(7);  // First > 7
    cout << "lower_bound(7): " << *lb << endl;  // 7
    cout << "upper_bound(7): " << *ub << endl;  // 8
    
    // ==========================================
    // UNORDERED_SET (Hash Set - FASTER!)
    // ==========================================
    cout << "\n=== UNORDERED_SET ===" << endl;
    
    unordered_set<string> words;
    
    words.insert("apple");
    words.insert("banana");
    words.insert("cherry");
    words.insert("apple");  // Duplicate - ignored
    
    cout << "Words: ";
    for (const string& w : words) {
        cout << w << " ";
    }
    cout << endl;
    
    // Check membership - O(1) average!
    if (words.count("banana")) {
        cout << "banana is in the set" << endl;
    }
    
    // Remove duplicates from vector - COMMON PATTERN!
    cout << "\n--- Remove Duplicates Example ---" << endl;
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 5};
    unordered_set<int> unique(nums.begin(), nums.end());
    
    cout << "Original: ";
    for (int n : nums) cout << n << " ";
    cout << endl;
    
    cout << "Unique: ";
    for (int n : unique) cout << n << " ";
    cout << endl;
    
    // ==========================================
    // MULTIMAP & MULTISET (Allow Duplicates)
    // ==========================================
    cout << "\n=== MULTISET ===" << endl;
    
    multiset<int> ms;
    ms.insert(5);
    ms.insert(2);
    ms.insert(5);  // Duplicate allowed!
    ms.insert(5);
    ms.insert(3);
    
    cout << "Multiset: ";
    for (int n : ms) cout << n << " ";
    cout << endl;
    
    cout << "Count of 5: " << ms.count(5) << endl;  // 3
    
    // Erase one occurrence
    auto iter = ms.find(5);
    if (iter != ms.end()) {
        ms.erase(iter);  // Erases only one 5
    }
    
    cout << "After erasing one 5: ";
    for (int n : ms) cout << n << " ";
    cout << endl;
    
    // ==========================================
    // PRACTICAL DSA EXAMPLES
    // ==========================================
    cout << "\n=== PRACTICAL EXAMPLES ===" << endl;
    
    // Example 1: Two Sum using hash map
    cout << "--- Two Sum ---" << endl;
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    unordered_map<int, int> numMap;  // value -> index
    
    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        if (numMap.count(complement)) {
            cout << "Indices: " << numMap[complement] << ", " << i << endl;
            break;
        }
        numMap[arr[i]] = i;
    }
    
    // Example 2: First non-repeating character
    cout << "\n--- First Non-Repeating Character ---" << endl;
    string s = "leetcode";
    unordered_map<char, int> charCount;
    
    for (char c : s) charCount[c]++;
    
    for (int i = 0; i < s.length(); i++) {
        if (charCount[s[i]] == 1) {
            cout << "First non-repeating: '" << s[i] << "' at index " << i << endl;
            break;
        }
    }
    
    // Example 3: Group anagrams (storing in map)
    cout << "\n--- Anagram Check ---" << endl;
    string s1 = "listen";
    string s2 = "silent";
    
    map<char, int> count1, count2;
    for (char c : s1) count1[c]++;
    for (char c : s2) count2[c]++;
    
    cout << "'" << s1 << "' and '" << s2 << "' are anagrams: " 
         << (count1 == count2 ? "Yes" : "No") << endl;
    
    return 0;
}

/*
 * QUICK REFERENCE - MAPS & SETS:
 * ==============================
 * 
 * MAP:
 * map<K, V> m;                      // Ordered (RB-Tree)
 * unordered_map<K, V> m;            // Unordered (Hash)
 * 
 * Operations:
 * m[key] = value                    // Insert/update
 * m.at(key)                         // Access with bounds check
 * m.insert({key, value})
 * m.find(key)                       // Returns iterator
 * m.count(key)                      // 0 or 1
 * m.erase(key)
 * m.size(), m.empty(), m.clear()
 * 
 * SET:
 * set<T> s;                         // Ordered (RB-Tree)
 * unordered_set<T> s;               // Unordered (Hash)
 * 
 * Operations:
 * s.insert(val)
 * s.find(val)
 * s.count(val)                      // 0 or 1
 * s.erase(val)
 * s.lower_bound(val)                // First >= val (ordered only)
 * s.upper_bound(val)                // First > val (ordered only)
 * 
 * MULTIMAP/MULTISET:
 * multiset<T> ms;                   // Allows duplicates
 * multimap<K, V> mm;                // Allows duplicate keys
 * 
 * TIME COMPLEXITY:
 * ----------------
 * | Operation    | map/set   | unordered_map/set |
 * |--------------|-----------|-------------------|
 * | Insert       | O(log n)  | O(1) average      |
 * | Find         | O(log n)  | O(1) average      |
 * | Erase        | O(log n)  | O(1) average      |
 * | Iterate      | O(n)      | O(n)              |
 * 
 * WHEN TO USE:
 * - Need ordering → map/set
 * - Need fast lookups → unordered_map/unordered_set
 * - Allow duplicates → multiset/multimap
 * - Frequency counting → unordered_map
 * - Unique elements → set/unordered_set
 */
