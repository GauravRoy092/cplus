/*
 * =============================================================
 * C++ BASICS - LESSON 11: STRUCTURES
 * =============================================================
 * Structures group related data together.
 * Foundation for understanding classes.
 * 
 * Key Concepts:
 * - Struct declaration
 * - Accessing members
 * - Structs with functions
 * - Nested structs
 * - Arrays of structs
 * =============================================================
 */

#include <iostream>
#include <string>
using namespace std;

// ==========================================
// BASIC STRUCT DECLARATION
// ==========================================

// Define a struct
struct Person {
    string name;
    int age;
    double height;
    bool isStudent;
};

// Struct with default values (C++11)
struct Point {
    double x = 0.0;
    double y = 0.0;
};

// Struct with methods (functions inside struct)
struct Rectangle {
    double width;
    double height;
    
    // Method to calculate area
    double area() {
        return width * height;
    }
    
    // Method to calculate perimeter
    double perimeter() {
        return 2 * (width + height);
    }
};

// Nested struct
struct Address {
    string street;
    string city;
    int zipCode;
};

struct Employee {
    string name;
    int id;
    double salary;
    Address address;  // Nested struct
};

// Struct for linked list node (IMPORTANT for DSA!)
struct ListNode {
    int data;
    ListNode* next;  // Pointer to next node
    
    // Constructor
    ListNode(int val) : data(val), next(nullptr) {}
};

// Struct for binary tree node (IMPORTANT for DSA!)
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function declarations
void printPerson(Person p);
void modifyPerson(Person& p);  // Pass by reference
double distance(Point p1, Point p2);

int main() {
    // ==========================================
    // CREATING STRUCT OBJECTS
    // ==========================================
    cout << "=== CREATING STRUCTS ===" << endl;
    
    // Method 1: Declare and initialize separately
    Person person1;
    person1.name = "Alice";
    person1.age = 25;
    person1.height = 5.6;
    person1.isStudent = true;
    
    // Method 2: Aggregate initialization
    Person person2 = {"Bob", 30, 6.0, false};
    
    // Method 3: Designated initializers (C++20)
    // Person person3 = {.name = "Charlie", .age = 28};
    
    // Using struct with default values
    Point origin;  // x=0.0, y=0.0
    Point p1 = {3.0, 4.0};
    
    cout << "Person1: " << person1.name << ", Age: " << person1.age << endl;
    cout << "Person2: " << person2.name << ", Age: " << person2.age << endl;
    cout << "Origin: (" << origin.x << ", " << origin.y << ")" << endl;
    cout << "P1: (" << p1.x << ", " << p1.y << ")" << endl;
    
    // ==========================================
    // ACCESSING & MODIFYING MEMBERS
    // ==========================================
    cout << "\n=== ACCESSING MEMBERS ===" << endl;
    
    // Using dot operator (.)
    cout << "Name: " << person1.name << endl;
    cout << "Is Student: " << (person1.isStudent ? "Yes" : "No") << endl;
    
    // Modifying members
    person1.age = 26;
    cout << "Updated age: " << person1.age << endl;
    
    // ==========================================
    // STRUCT WITH METHODS
    // ==========================================
    cout << "\n=== STRUCT WITH METHODS ===" << endl;
    
    Rectangle rect = {5.0, 3.0};
    cout << "Rectangle " << rect.width << " x " << rect.height << endl;
    cout << "Area: " << rect.area() << endl;
    cout << "Perimeter: " << rect.perimeter() << endl;
    
    // ==========================================
    // NESTED STRUCTS
    // ==========================================
    cout << "\n=== NESTED STRUCTS ===" << endl;
    
    Employee emp;
    emp.name = "John Doe";
    emp.id = 12345;
    emp.salary = 50000.0;
    emp.address.street = "123 Main St";
    emp.address.city = "New York";
    emp.address.zipCode = 10001;
    
    cout << "Employee: " << emp.name << endl;
    cout << "Address: " << emp.address.street << ", " 
         << emp.address.city << " " << emp.address.zipCode << endl;
    
    // ==========================================
    // ARRAY OF STRUCTS
    // ==========================================
    cout << "\n=== ARRAY OF STRUCTS ===" << endl;
    
    Person people[3] = {
        {"Alice", 25, 5.5, true},
        {"Bob", 30, 6.0, false},
        {"Charlie", 28, 5.8, true}
    };
    
    cout << "People:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  " << people[i].name << ", Age: " << people[i].age << endl;
    }
    
    // Range-based for
    for (const Person& p : people) {
        cout << "  " << p.name << " is " << (p.isStudent ? "" : "not ") 
             << "a student" << endl;
    }
    
    // ==========================================
    // POINTERS TO STRUCTS
    // ==========================================
    cout << "\n=== POINTERS TO STRUCTS ===" << endl;
    
    Person* personPtr = &person1;
    
    // Two ways to access members:
    // 1. Dereference then dot
    cout << "Using (*ptr).member: " << (*personPtr).name << endl;
    
    // 2. Arrow operator (preferred)
    cout << "Using ptr->member: " << personPtr->name << endl;
    personPtr->age = 27;
    cout << "Updated age via pointer: " << person1.age << endl;
    
    // ==========================================
    // STRUCTS WITH FUNCTIONS
    // ==========================================
    cout << "\n=== STRUCTS WITH FUNCTIONS ===" << endl;
    
    Person testPerson = {"Test", 20, 5.5, true};
    
    printPerson(testPerson);  // Pass by value (copy)
    
    modifyPerson(testPerson);  // Pass by reference
    cout << "After modification: " << testPerson.name << ", " << testPerson.age << endl;
    
    // Calculate distance between points
    Point a = {0, 0};
    Point b = {3, 4};
    cout << "Distance from (0,0) to (3,4): " << distance(a, b) << endl;
    
    // ==========================================
    // DSA: LINKED LIST NODE EXAMPLE
    // ==========================================
    cout << "\n=== LINKED LIST EXAMPLE ===" << endl;
    
    // Create nodes
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    
    // Traverse and print
    cout << "Linked List: ";
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << " -> ";
        current = current->next;
    }
    cout << endl;
    
    // Clean up (delete nodes)
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    // ==========================================
    // DSA: BINARY TREE NODE EXAMPLE
    // ==========================================
    cout << "\n=== BINARY TREE EXAMPLE ===" << endl;
    
    /*
     *       1
     *      / \
     *     2   3
     */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    cout << "Root: " << root->val << endl;
    cout << "Left child: " << root->left->val << endl;
    cout << "Right child: " << root->right->val << endl;
    
    // Clean up
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}

// ==========================================
// FUNCTION DEFINITIONS
// ==========================================

void printPerson(Person p) {
    cout << "Name: " << p.name << ", Age: " << p.age;
    cout << ", Height: " << p.height;
    cout << ", Student: " << (p.isStudent ? "Yes" : "No") << endl;
}

void modifyPerson(Person& p) {  // Reference allows modification
    p.name = "Modified";
    p.age = 99;
}

double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);  // Pythagorean theorem
}

/*
 * QUICK REFERENCE - STRUCTURES:
 * =============================
 * 
 * DECLARATION:
 * struct Name {
 *     type member1;
 *     type member2;
 * };
 * 
 * CREATION:
 * Name obj;
 * Name obj = {val1, val2};
 * 
 * ACCESS:
 * obj.member          // Dot notation
 * ptr->member         // Arrow notation (for pointers)
 * (*ptr).member       // Same as above
 * 
 * IMPORTANT FOR DSA:
 * 
 * Linked List Node:
 * struct ListNode {
 *     int val;
 *     ListNode* next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 * 
 * Binary Tree Node:
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 * 
 * Graph Edge:
 * struct Edge {
 *     int from, to, weight;
 * };
 * 
 * TIPS:
 * - Pass large structs by reference (const& for read-only)
 * - Use -> for pointer access
 * - Struct members are public by default
 * - Classes are essentially structs with private default
 */
