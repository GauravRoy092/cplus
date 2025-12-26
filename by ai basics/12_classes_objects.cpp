/*
 * =============================================================
 * C++ BASICS - LESSON 12: CLASSES & OBJECTS (OOP Basics)
 * =============================================================
 * Classes are blueprints for creating objects.
 * Core of Object-Oriented Programming.
 * 
 * Key Concepts:
 * - Class declaration
 * - Access specifiers (public, private, protected)
 * - Constructors and destructors
 * - Member functions
 * - this pointer
 * - Static members
 * =============================================================
 */

#include <iostream>
#include <string>
using namespace std;

// ==========================================
// BASIC CLASS DECLARATION
// ==========================================
class Student {
private:  // Not accessible outside class
    string name;
    int age;
    double gpa;
    
public:   // Accessible from anywhere
    // Default constructor
    Student() {
        name = "Unknown";
        age = 0;
        gpa = 0.0;
        cout << "Default constructor called" << endl;
    }
    
    // Parameterized constructor
    Student(string n, int a, double g) {
        name = n;
        age = a;
        gpa = g;
        cout << "Parameterized constructor called" << endl;
    }
    
    // Constructor with initializer list (preferred)
    Student(string n, int a) : name(n), age(a), gpa(0.0) {
        cout << "Initializer list constructor called" << endl;
    }
    
    // Destructor
    ~Student() {
        cout << "Destructor called for " << name << endl;
    }
    
    // Getter methods
    string getName() { return name; }
    int getAge() { return age; }
    double getGpa() { return gpa; }
    
    // Setter methods
    void setName(string n) { name = n; }
    void setAge(int a) { 
        if (a > 0) age = a;  // Validation
    }
    void setGpa(double g) {
        if (g >= 0.0 && g <= 4.0) gpa = g;
    }
    
    // Member function
    void display() {
        cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << endl;
    }
    
    // Using 'this' pointer
    void setAll(string name, int age, double gpa) {
        this->name = name;    // this-> distinguishes member from parameter
        this->age = age;
        this->gpa = gpa;
    }
};

// ==========================================
// CLASS WITH STATIC MEMBERS
// ==========================================
class Counter {
private:
    static int count;  // Shared by all objects
    int id;
    
public:
    Counter() {
        count++;
        id = count;
    }
    
    static int getCount() {  // Static function
        return count;
    }
    
    int getId() { return id; }
};

// Initialize static member outside class
int Counter::count = 0;

// ==========================================
// CLASS WITH CONST MEMBERS
// ==========================================
class Circle {
private:
    double radius;
    
public:
    static const double PI;  // Static constant
    
    Circle(double r) : radius(r) {}
    
    // Const member function - doesn't modify object
    double getArea() const {
        return PI * radius * radius;
    }
    
    double getCircumference() const {
        return 2 * PI * radius;
    }
    
    void setRadius(double r) { radius = r; }  // Non-const, modifies
};

// Initialize static const
const double Circle::PI = 3.14159;

// ==========================================
// DEMONSTRATING COMPOSITION
// ==========================================
class Engine {
private:
    int horsepower;
    
public:
    Engine(int hp = 100) : horsepower(hp) {}
    
    void start() { cout << "Engine starting..." << endl; }
    void stop() { cout << "Engine stopping..." << endl; }
    int getHP() { return horsepower; }
};

class Car {
private:
    string brand;
    Engine engine;  // Composition - Car HAS-A Engine
    
public:
    Car(string b, int hp) : brand(b), engine(hp) {}
    
    void startCar() {
        cout << brand << ": ";
        engine.start();
    }
    
    void stopCar() {
        cout << brand << ": ";
        engine.stop();
    }
    
    void display() {
        cout << brand << " with " << engine.getHP() << " HP" << endl;
    }
};

int main() {
    // ==========================================
    // CREATING OBJECTS
    // ==========================================
    cout << "=== CREATING OBJECTS ===" << endl;
    
    // Using default constructor
    Student s1;
    
    // Using parameterized constructor
    Student s2("Alice", 20, 3.8);
    
    // Using initializer list constructor
    Student s3("Bob", 22);
    
    cout << endl;
    
    // ==========================================
    // ACCESSING MEMBERS
    // ==========================================
    cout << "=== ACCESSING MEMBERS ===" << endl;
    
    // Using getters
    cout << "s2 name: " << s2.getName() << endl;
    cout << "s2 age: " << s2.getAge() << endl;
    cout << "s2 GPA: " << s2.getGpa() << endl;
    
    // Using setters
    s1.setName("Charlie");
    s1.setAge(19);
    s1.setGpa(3.5);
    
    // Using member function
    s1.display();
    s2.display();
    
    cout << endl;
    
    // ==========================================
    // OBJECTS ON HEAP
    // ==========================================
    cout << "=== OBJECTS ON HEAP ===" << endl;
    
    // Dynamic allocation
    Student* sPtr = new Student("David", 21, 3.9);
    
    // Access using arrow operator
    cout << "Pointer access: " << sPtr->getName() << endl;
    sPtr->display();
    
    // Always delete when done
    delete sPtr;
    
    cout << endl;
    
    // ==========================================
    // STATIC MEMBERS
    // ==========================================
    cout << "=== STATIC MEMBERS ===" << endl;
    
    cout << "Initial count: " << Counter::getCount() << endl;
    
    Counter c1;
    Counter c2;
    Counter c3;
    
    cout << "After creating 3 objects: " << Counter::getCount() << endl;
    cout << "c1 ID: " << c1.getId() << ", c2 ID: " << c2.getId() << endl;
    
    cout << endl;
    
    // ==========================================
    // CONST MEMBERS
    // ==========================================
    cout << "=== CONST MEMBERS ===" << endl;
    
    Circle circle(5.0);
    cout << "Circle PI: " << Circle::PI << endl;
    cout << "Area: " << circle.getArea() << endl;
    cout << "Circumference: " << circle.getCircumference() << endl;
    
    // Const object - can only call const methods
    const Circle constCircle(3.0);
    cout << "Const circle area: " << constCircle.getArea() << endl;
    // constCircle.setRadius(4.0);  // ERROR! Can't call non-const on const obj
    
    cout << endl;
    
    // ==========================================
    // COMPOSITION
    // ==========================================
    cout << "=== COMPOSITION ===" << endl;
    
    Car myCar("Toyota", 150);
    myCar.display();
    myCar.startCar();
    myCar.stopCar();
    
    cout << endl;
    
    // ==========================================
    // ARRAY OF OBJECTS
    // ==========================================
    cout << "=== ARRAY OF OBJECTS ===" << endl;
    
    Student students[3] = {
        Student("Alice", 20, 3.8),
        Student("Bob", 21, 3.5),
        Student("Charlie", 19, 3.9)
    };
    
    cout << "\nAll students:" << endl;
    for (int i = 0; i < 3; i++) {
        students[i].display();
    }
    
    cout << "\n=== PROGRAM END ===" << endl;
    
    return 0;
}

/*
 * QUICK REFERENCE - CLASSES:
 * ==========================
 * 
 * CLASS STRUCTURE:
 * class ClassName {
 * private:
 *     // Hidden members
 * public:
 *     // Accessible members
 * protected:
 *     // For inheritance
 * };
 * 
 * CONSTRUCTOR:
 * ClassName() { }                     // Default
 * ClassName(params) { }               // Parameterized
 * ClassName(params) : member(val) { } // Initializer list
 * 
 * DESTRUCTOR:
 * ~ClassName() { }                    // Called when object destroyed
 * 
 * STATIC MEMBERS:
 * static int count;                   // Declaration
 * int ClassName::count = 0;           // Definition (outside class)
 * static int getCount() { }           // Static method
 * 
 * CONST:
 * int getValue() const { }            // Const method
 * const ClassName obj;                // Const object
 * 
 * ACCESS:
 * obj.member                          // Stack object
 * ptr->member                         // Heap object (pointer)
 * 
 * IMPORTANT:
 * - Use private for data members
 * - Use public for interface
 * - Initialize with initializer list when possible
 * - Delete what you new!
 * - Use const for methods that don't modify
 */
