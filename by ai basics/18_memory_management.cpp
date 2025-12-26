/*
 * =============================================================
 * C++ BASICS - LESSON 18: MEMORY MANAGEMENT
 * =============================================================
 * Understanding memory for DSA implementations.
 * 
 * Key Concepts:
 * - Stack vs Heap
 * - new and delete
 * - Smart pointers (C++11)
 * - Memory leaks prevention
 * =============================================================
 */

#include <iostream>
#include <memory>  // For smart pointers
using namespace std;

// Simple class for demonstration
class Resource {
private:
    string name;
    int* data;
    
public:
    Resource(string n) : name(n) {
        data = new int[100];
        cout << "Resource '" << name << "' created" << endl;
    }
    
    ~Resource() {
        delete[] data;
        cout << "Resource '" << name << "' destroyed" << endl;
    }
    
    void use() {
        cout << "Using resource: " << name << endl;
    }
    
    string getName() { return name; }
};

// Class for shared_ptr demo
class Node {
public:
    int value;
    shared_ptr<Node> next;
    
    Node(int v) : value(v), next(nullptr) {
        cout << "Node " << value << " created" << endl;
    }
    
    ~Node() {
        cout << "Node " << value << " destroyed" << endl;
    }
};

int main() {
    // ==========================================
    // STACK VS HEAP MEMORY
    // ==========================================
    cout << "=== STACK VS HEAP ===" << endl;
    
    // Stack allocation - automatic, fast, limited size
    int stackVar = 10;
    int stackArray[5] = {1, 2, 3, 4, 5};
    
    cout << "Stack variable: " << stackVar << endl;
    cout << "Stack array: ";
    for (int i = 0; i < 5; i++) cout << stackArray[i] << " ";
    cout << endl;
    
    // Heap allocation - manual, more memory, slower
    int* heapVar = new int(20);
    int* heapArray = new int[5];
    
    for (int i = 0; i < 5; i++) heapArray[i] = (i + 1) * 10;
    
    cout << "Heap variable: " << *heapVar << endl;
    cout << "Heap array: ";
    for (int i = 0; i < 5; i++) cout << heapArray[i] << " ";
    cout << endl;
    
    // MUST delete heap memory!
    delete heapVar;
    delete[] heapArray;  // Use delete[] for arrays
    
    // ==========================================
    // NEW AND DELETE
    // ==========================================
    cout << "\n=== NEW AND DELETE ===" << endl;
    
    // Single variable
    int* ptr1 = new int;        // Uninitialized
    int* ptr2 = new int(100);   // Initialized to 100
    int* ptr3 = new int{200};   // C++11 brace initialization
    
    cout << "*ptr2 = " << *ptr2 << endl;
    cout << "*ptr3 = " << *ptr3 << endl;
    
    delete ptr1;
    delete ptr2;
    delete ptr3;
    
    // Array
    int n = 5;
    int* arr = new int[n];
    
    for (int i = 0; i < n; i++) {
        arr[i] = i * i;
    }
    
    cout << "Dynamic array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    
    delete[] arr;  // IMPORTANT: Use delete[] for arrays!
    arr = nullptr; // Good practice: set to null after delete
    
    // 2D array on heap
    int rows = 3, cols = 4;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    
    // Use it
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;
        }
    }
    
    cout << "\n2D dynamic array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // Delete 2D array (reverse order!)
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    // ==========================================
    // OBJECTS ON HEAP
    // ==========================================
    cout << "\n=== OBJECTS ON HEAP ===" << endl;
    
    Resource* res = new Resource("HeapResource");
    res->use();
    delete res;  // Destructor called here
    
    // ==========================================
    // SMART POINTERS (C++11) - RECOMMENDED!
    // ==========================================
    cout << "\n=== SMART POINTERS ===" << endl;
    
    // ================
    // unique_ptr - Exclusive ownership
    // ================
    cout << "\n--- unique_ptr ---" << endl;
    
    {
        // Create unique_ptr
        unique_ptr<Resource> uptr1 = make_unique<Resource>("Unique1");
        uptr1->use();
        
        // Transfer ownership (move)
        unique_ptr<Resource> uptr2 = move(uptr1);
        // uptr1 is now null!
        
        if (uptr1 == nullptr) {
            cout << "uptr1 is now null after move" << endl;
        }
        
        uptr2->use();
        
        // Release ownership (returns raw pointer)
        // Resource* raw = uptr2.release();
        // delete raw;  // Would need manual delete
        
        // Reset (delete and optionally assign new)
        uptr2.reset();  // Deletes the resource
        cout << "After reset, uptr2 is null: " << (uptr2 == nullptr) << endl;
        
    }  // uptr2 automatically deleted here if not reset
    
    // unique_ptr with array
    unique_ptr<int[]> uarr(new int[5]);
    for (int i = 0; i < 5; i++) uarr[i] = i * 10;
    cout << "unique_ptr array: ";
    for (int i = 0; i < 5; i++) cout << uarr[i] << " ";
    cout << endl;
    
    // ================
    // shared_ptr - Shared ownership (reference counting)
    // ================
    cout << "\n--- shared_ptr ---" << endl;
    
    {
        shared_ptr<Resource> sptr1 = make_shared<Resource>("Shared1");
        cout << "Reference count: " << sptr1.use_count() << endl;
        
        {
            shared_ptr<Resource> sptr2 = sptr1;  // Share ownership
            cout << "Reference count after share: " << sptr1.use_count() << endl;
            
            shared_ptr<Resource> sptr3 = sptr1;  // Share again
            cout << "Reference count after another share: " << sptr1.use_count() << endl;
            
        }  // sptr2 and sptr3 go out of scope
        
        cout << "Reference count after scope: " << sptr1.use_count() << endl;
        
    }  // sptr1 goes out of scope, resource destroyed
    
    // shared_ptr with nodes (like linked list)
    cout << "\n--- shared_ptr with Nodes ---" << endl;
    {
        shared_ptr<Node> head = make_shared<Node>(1);
        head->next = make_shared<Node>(2);
        head->next->next = make_shared<Node>(3);
        
        // Traverse
        cout << "Linked list: ";
        shared_ptr<Node> current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
        
    }  // All nodes automatically destroyed
    
    // ================
    // weak_ptr - Non-owning reference (breaks cycles)
    // ================
    cout << "\n--- weak_ptr ---" << endl;
    
    weak_ptr<Resource> wptr;
    
    {
        shared_ptr<Resource> sptr = make_shared<Resource>("WeakTest");
        wptr = sptr;  // weak_ptr doesn't increase count
        
        cout << "Inside scope - expired: " << wptr.expired() << endl;
        
        // Convert to shared_ptr to use
        if (auto locked = wptr.lock()) {
            locked->use();
        }
    }
    
    cout << "Outside scope - expired: " << wptr.expired() << endl;
    
    // ==========================================
    // MEMORY LEAK PREVENTION TIPS
    // ==========================================
    cout << "\n=== MEMORY TIPS ===" << endl;
    
    /*
     * 1. Always match new with delete, new[] with delete[]
     * 2. Use smart pointers when possible
     * 3. Set pointers to nullptr after delete
     * 4. Use RAII (Resource Acquisition Is Initialization)
     * 5. Use valgrind to detect leaks
     * 6. Prefer stack allocation when possible
     * 7. Use containers (vector, etc.) instead of raw arrays
     */
    
    // Example: Using vector instead of dynamic array
    cout << "Prefer vector over raw arrays:" << endl;
    vector<int> safeArray(5);  // No manual memory management!
    for (int i = 0; i < 5; i++) safeArray[i] = i;
    // No delete needed!
    
    cout << "\nAll memory properly managed!" << endl;
    
    return 0;
}

/*
 * QUICK REFERENCE - MEMORY MANAGEMENT:
 * =====================================
 * 
 * RAW POINTERS:
 * int* p = new int(5);       // Allocate
 * delete p;                   // Deallocate
 * int* arr = new int[n];     // Allocate array
 * delete[] arr;               // Deallocate array
 * 
 * SMART POINTERS:
 * unique_ptr<T> - Exclusive ownership
 *   auto p = make_unique<T>(args);
 *   p.release()              // Release ownership
 *   p.reset()                // Delete and set null
 *   p.get()                  // Get raw pointer
 *   move(p)                  // Transfer ownership
 * 
 * shared_ptr<T> - Shared ownership
 *   auto p = make_shared<T>(args);
 *   p.use_count()            // Reference count
 *   p.reset()                // Decrease count
 *   p.get()                  // Get raw pointer
 * 
 * weak_ptr<T> - Non-owning reference
 *   weak_ptr<T> w = shared;
 *   w.expired()              // Check if valid
 *   w.lock()                 // Get shared_ptr
 * 
 * TIPS:
 * - Prefer smart pointers over raw
 * - Use unique_ptr by default
 * - Use shared_ptr when sharing is needed
 * - Use weak_ptr to break cycles
 * - Use vector instead of dynamic arrays
 * 
 * COMMON MISTAKES:
 * - Forgetting delete
 * - Using delete instead of delete[]
 * - Double delete
 * - Using pointer after delete
 * - Memory leaks in exceptions
 */
