/*
 * =============================================================
 * C++ BASICS - LESSON 13: INHERITANCE
 * =============================================================
 * Inheritance allows creating new classes based on existing ones.
 * 
 * Key Concepts:
 * - Base and derived classes
 * - Access specifiers with inheritance
 * - Constructor/destructor order
 * - Multiple inheritance
 * - Types of inheritance
 * =============================================================
 */

#include <iostream>
#include <string>
using namespace std;

// ==========================================
// BASE CLASS (Parent/Superclass)
// ==========================================
class Animal {
protected:  // Accessible in derived classes
    string name;
    int age;
    
public:
    Animal() : name("Unknown"), age(0) {
        cout << "Animal default constructor" << endl;
    }
    
    Animal(string n, int a) : name(n), age(a) {
        cout << "Animal parameterized constructor" << endl;
    }
    
    ~Animal() {
        cout << "Animal destructor for " << name << endl;
    }
    
    void eat() {
        cout << name << " is eating" << endl;
    }
    
    void sleep() {
        cout << name << " is sleeping" << endl;
    }
    
    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
    
    string getName() { return name; }
    int getAge() { return age; }
};

// ==========================================
// DERIVED CLASS (Child/Subclass)
// ==========================================

// Public inheritance: public -> public, protected -> protected
class Dog : public Animal {
private:
    string breed;
    
public:
    // Call base class constructor
    Dog() : Animal(), breed("Unknown") {
        cout << "Dog default constructor" << endl;
    }
    
    Dog(string n, int a, string b) : Animal(n, a), breed(b) {
        cout << "Dog parameterized constructor" << endl;
    }
    
    ~Dog() {
        cout << "Dog destructor for " << name << endl;
    }
    
    // New method specific to Dog
    void bark() {
        cout << name << " says: Woof! Woof!" << endl;
    }
    
    // Override base class method
    void displayInfo() {
        cout << "Dog - Name: " << name << ", Age: " << age 
             << ", Breed: " << breed << endl;
    }
    
    string getBreed() { return breed; }
};

class Cat : public Animal {
private:
    bool isIndoor;
    
public:
    Cat(string n, int a, bool indoor) : Animal(n, a), isIndoor(indoor) {
        cout << "Cat constructor" << endl;
    }
    
    ~Cat() {
        cout << "Cat destructor" << endl;
    }
    
    void meow() {
        cout << name << " says: Meow!" << endl;
    }
    
    void displayInfo() {
        cout << "Cat - Name: " << name << ", Age: " << age
             << ", Indoor: " << (isIndoor ? "Yes" : "No") << endl;
    }
};

// ==========================================
// MULTILEVEL INHERITANCE
// ==========================================
class Puppy : public Dog {
private:
    bool isVaccinated;
    
public:
    Puppy(string n, string b, bool v) : Dog(n, 0, b), isVaccinated(v) {
        cout << "Puppy constructor" << endl;
    }
    
    void play() {
        cout << getName() << " is playing!" << endl;
    }
    
    void displayInfo() {
        cout << "Puppy - Name: " << getName() << ", Breed: " << getBreed()
             << ", Vaccinated: " << (isVaccinated ? "Yes" : "No") << endl;
    }
};

// ==========================================
// MULTIPLE INHERITANCE
// ==========================================
class Flyable {
public:
    void fly() {
        cout << "Flying in the sky!" << endl;
    }
};

class Swimmable {
public:
    void swim() {
        cout << "Swimming in water!" << endl;
    }
};

// Duck inherits from both Flyable and Swimmable
class Duck : public Flyable, public Swimmable {
private:
    string name;
    
public:
    Duck(string n) : name(n) {}
    
    void quack() {
        cout << name << " says: Quack!" << endl;
    }
    
    void display() {
        cout << "Duck: " << name << endl;
    }
};

// ==========================================
// DEMONSTRATING ACCESS SPECIFIERS
// ==========================================

class Base {
public:
    int publicVar = 1;
protected:
    int protectedVar = 2;
private:
    int privateVar = 3;
};

// Public inheritance
class DerivedPublic : public Base {
public:
    void show() {
        cout << "Public var: " << publicVar << endl;      // OK
        cout << "Protected var: " << protectedVar << endl; // OK
        // cout << privateVar;  // ERROR! Not accessible
    }
};

// Protected inheritance - public becomes protected
class DerivedProtected : protected Base {
public:
    void show() {
        cout << "Public var: " << publicVar << endl;       // OK (now protected)
        cout << "Protected var: " << protectedVar << endl;  // OK
    }
};

// Private inheritance - all become private
class DerivedPrivate : private Base {
public:
    void show() {
        cout << "Public var: " << publicVar << endl;       // OK (now private)
        cout << "Protected var: " << protectedVar << endl;  // OK (now private)
    }
};

int main() {
    // ==========================================
    // BASIC INHERITANCE
    // ==========================================
    cout << "=== BASIC INHERITANCE ===" << endl;
    
    Dog myDog("Buddy", 3, "Labrador");
    cout << endl;
    
    // Using inherited methods
    myDog.eat();           // From Animal
    myDog.sleep();         // From Animal
    myDog.bark();          // From Dog
    myDog.displayInfo();   // Overridden in Dog
    
    cout << endl;
    
    // ==========================================
    // CONSTRUCTOR/DESTRUCTOR ORDER
    // ==========================================
    cout << "=== CONSTRUCTOR/DESTRUCTOR ORDER ===" << endl;
    {
        Dog tempDog("Rex", 2, "German Shepherd");
        cout << "Dog object created" << endl;
    }  // Destructor called here (reverse order)
    
    cout << endl;
    
    // ==========================================
    // ANOTHER DERIVED CLASS
    // ==========================================
    cout << "=== ANOTHER DERIVED CLASS ===" << endl;
    
    Cat myCat("Whiskers", 5, true);
    myCat.eat();
    myCat.meow();
    myCat.displayInfo();
    
    cout << endl;
    
    // ==========================================
    // MULTILEVEL INHERITANCE
    // ==========================================
    cout << "=== MULTILEVEL INHERITANCE ===" << endl;
    
    Puppy myPuppy("Max", "Beagle", true);
    myPuppy.eat();      // From Animal
    myPuppy.bark();     // From Dog
    myPuppy.play();     // From Puppy
    myPuppy.displayInfo();
    
    cout << endl;
    
    // ==========================================
    // MULTIPLE INHERITANCE
    // ==========================================
    cout << "=== MULTIPLE INHERITANCE ===" << endl;
    
    Duck donald("Donald");
    donald.display();
    donald.quack();
    donald.fly();    // From Flyable
    donald.swim();   // From Swimmable
    
    cout << endl;
    
    // ==========================================
    // POINTERS AND INHERITANCE
    // ==========================================
    cout << "=== POINTERS AND INHERITANCE ===" << endl;
    
    // Base class pointer can point to derived class object
    Animal* animalPtr = new Dog("Spot", 4, "Dalmatian");
    animalPtr->eat();       // Works - from Animal
    animalPtr->sleep();     // Works - from Animal
    // animalPtr->bark();   // ERROR! Animal doesn't have bark()
    
    // To use Dog-specific methods, need to cast
    Dog* dogPtr = dynamic_cast<Dog*>(animalPtr);
    if (dogPtr) {
        dogPtr->bark();     // Now works!
    }
    
    delete animalPtr;
    
    cout << endl;
    
    // ==========================================
    // ARRAY OF DIFFERENT DERIVED TYPES
    // ==========================================
    cout << "=== POLYMORPHIC ARRAY ===" << endl;
    
    Animal* animals[3];
    animals[0] = new Dog("Buddy", 3, "Poodle");
    animals[1] = new Cat("Luna", 2, false);
    animals[2] = new Dog("Charlie", 5, "Bulldog");
    
    cout << "\nAll animals eating:" << endl;
    for (int i = 0; i < 3; i++) {
        animals[i]->eat();
    }
    
    // Clean up
    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }
    
    return 0;
}

/*
 * QUICK REFERENCE - INHERITANCE:
 * ==============================
 * 
 * SYNTAX:
 * class Derived : public Base { };
 * class Derived : protected Base { };
 * class Derived : private Base { };
 * 
 * ACCESS IN DERIVED CLASS:
 * - public members: Always accessible
 * - protected members: Accessible in derived
 * - private members: Never accessible
 * 
 * AFTER INHERITANCE:
 * public inheritance:    public->public, protected->protected
 * protected inheritance: public->protected, protected->protected
 * private inheritance:   public->private, protected->private
 * 
 * CONSTRUCTOR CALL:
 * Derived() : Base(args) { }
 * 
 * ORDER:
 * Construction: Base first, then Derived
 * Destruction: Derived first, then Base
 * 
 * MULTIPLE INHERITANCE:
 * class D : public A, public B { };
 * 
 * TYPES:
 * - Single: One parent
 * - Multiple: Multiple parents
 * - Multilevel: A -> B -> C
 * - Hierarchical: One parent, multiple children
 * - Hybrid: Combination
 * 
 * IMPORTANT:
 * - Use public inheritance for IS-A relationship
 * - Use protected for members needed by derived
 * - Base pointer can hold derived object
 * - Use virtual for polymorphic behavior (next lesson)
 */
