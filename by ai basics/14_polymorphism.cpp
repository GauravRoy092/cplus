/*
 * =============================================================
 * C++ BASICS - LESSON 14: POLYMORPHISM
 * =============================================================
 * Polymorphism = "Many forms" - same interface, different behavior.
 * 
 * Key Concepts:
 * - Virtual functions
 * - Function overriding
 * - Pure virtual functions & abstract classes
 * - Virtual destructors
 * - Runtime polymorphism
 * =============================================================
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ==========================================
// VIRTUAL FUNCTIONS AND POLYMORPHISM
// ==========================================

class Shape {
protected:
    string name;
    
public:
    Shape(string n = "Shape") : name(n) {}
    
    // Virtual function - can be overridden
    virtual void draw() {
        cout << "Drawing a " << name << endl;
    }
    
    // Virtual function for area
    virtual double area() {
        return 0.0;
    }
    
    // Virtual destructor - IMPORTANT for polymorphic classes!
    virtual ~Shape() {
        cout << "Shape destructor: " << name << endl;
    }
    
    string getName() { return name; }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : Shape("Circle"), radius(r) {}
    
    // Override - replaces base class virtual function
    void draw() override {  // 'override' keyword (C++11) helps catch errors
        cout << "Drawing Circle with radius " << radius << endl;
    }
    
    double area() override {
        return 3.14159 * radius * radius;
    }
    
    ~Circle() {
        cout << "Circle destructor" << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(double w, double h) : Shape("Rectangle"), width(w), height(h) {}
    
    void draw() override {
        cout << "Drawing Rectangle " << width << " x " << height << endl;
    }
    
    double area() override {
        return width * height;
    }
    
    ~Rectangle() {
        cout << "Rectangle destructor" << endl;
    }
};

class Triangle : public Shape {
private:
    double base, height;
    
public:
    Triangle(double b, double h) : Shape("Triangle"), base(b), height(h) {}
    
    void draw() override {
        cout << "Drawing Triangle with base " << base << " and height " << height << endl;
    }
    
    double area() override {
        return 0.5 * base * height;
    }
};

// ==========================================
// PURE VIRTUAL FUNCTIONS & ABSTRACT CLASSES
// ==========================================

// Abstract class - cannot be instantiated
class Animal {
protected:
    string name;
    
public:
    Animal(string n) : name(n) {}
    
    // Pure virtual function - MUST be overridden
    virtual void makeSound() = 0;  // = 0 makes it pure virtual
    
    // Regular virtual function
    virtual void eat() {
        cout << name << " is eating" << endl;
    }
    
    virtual ~Animal() {}
    
    string getName() { return name; }
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}
    
    // MUST implement pure virtual function
    void makeSound() override {
        cout << name << " says: Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}
    
    void makeSound() override {
        cout << name << " says: Meow!" << endl;
    }
};

class Cow : public Animal {
public:
    Cow(string n) : Animal(n) {}
    
    void makeSound() override {
        cout << name << " says: Moo!" << endl;
    }
};

// ==========================================
// INTERFACE (All pure virtual)
// ==========================================

// Pure interface - all methods are pure virtual
class Drawable {
public:
    virtual void draw() = 0;
    virtual void setColor(string color) = 0;
    virtual ~Drawable() {}
};

class Resizable {
public:
    virtual void resize(double factor) = 0;
    virtual ~Resizable() {}
};

// Implementing multiple interfaces
class Square : public Drawable, public Resizable {
private:
    double side;
    string color;
    
public:
    Square(double s) : side(s), color("black") {}
    
    void draw() override {
        cout << "Drawing " << color << " square with side " << side << endl;
    }
    
    void setColor(string c) override {
        color = c;
    }
    
    void resize(double factor) override {
        side *= factor;
        cout << "Resized square to side " << side << endl;
    }
};

// ==========================================
// DEMONSTRATING DYNAMIC BINDING
// ==========================================

void processShape(Shape* shape) {
    // This function works with ANY shape!
    shape->draw();
    cout << "Area: " << shape->area() << endl;
}

void makeAnimalSound(Animal* animal) {
    // Works with any animal!
    animal->makeSound();
}

int main() {
    // ==========================================
    // VIRTUAL FUNCTIONS
    // ==========================================
    cout << "=== VIRTUAL FUNCTIONS ===" << endl;
    
    Circle circle(5.0);
    Rectangle rect(4.0, 3.0);
    Triangle tri(6.0, 4.0);
    
    circle.draw();
    rect.draw();
    tri.draw();
    
    cout << endl;
    
    // ==========================================
    // POLYMORPHISM WITH BASE POINTER
    // ==========================================
    cout << "=== POLYMORPHISM WITH POINTERS ===" << endl;
    
    // Base pointer pointing to derived objects
    Shape* shapes[3];
    shapes[0] = new Circle(3.0);
    shapes[1] = new Rectangle(5.0, 2.0);
    shapes[2] = new Triangle(4.0, 3.0);
    
    // Same function call, different behavior!
    for (int i = 0; i < 3; i++) {
        cout << "Shape " << (i+1) << ": ";
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->area() << endl;
    }
    
    // Clean up
    for (int i = 0; i < 3; i++) {
        delete shapes[i];  // Virtual destructor ensures proper cleanup
    }
    
    cout << endl;
    
    // ==========================================
    // USING FUNCTION WITH BASE POINTER PARAM
    // ==========================================
    cout << "=== FUNCTION WITH BASE POINTER ===" << endl;
    
    Circle c(2.0);
    Rectangle r(3.0, 4.0);
    
    processShape(&c);
    cout << endl;
    processShape(&r);
    
    cout << endl;
    
    // ==========================================
    // ABSTRACT CLASSES
    // ==========================================
    cout << "=== ABSTRACT CLASSES ===" << endl;
    
    // Animal a("test");  // ERROR! Can't instantiate abstract class
    
    Dog dog("Buddy");
    Cat cat("Whiskers");
    Cow cow("Bessie");
    
    dog.makeSound();
    cat.makeSound();
    cow.makeSound();
    
    cout << endl;
    
    // ==========================================
    // POLYMORPHISM WITH ABSTRACT CLASS
    // ==========================================
    cout << "=== POLYMORPHIC ANIMAL ARRAY ===" << endl;
    
    vector<Animal*> animals;
    animals.push_back(new Dog("Rex"));
    animals.push_back(new Cat("Luna"));
    animals.push_back(new Cow("Daisy"));
    animals.push_back(new Dog("Max"));
    
    cout << "All animals making sounds:" << endl;
    for (Animal* a : animals) {
        a->makeSound();  // Dynamic binding - correct method called
    }
    
    cout << "\nUsing function:" << endl;
    for (Animal* a : animals) {
        makeAnimalSound(a);
    }
    
    // Clean up
    for (Animal* a : animals) {
        delete a;
    }
    
    cout << endl;
    
    // ==========================================
    // INTERFACES
    // ==========================================
    cout << "=== INTERFACES ===" << endl;
    
    Square sq(5.0);
    
    // Use as Drawable
    Drawable* drawable = &sq;
    drawable->setColor("red");
    drawable->draw();
    
    // Use as Resizable  
    Resizable* resizable = &sq;
    resizable->resize(2.0);
    
    drawable->draw();  // Shows updated size
    
    cout << endl;
    
    // ==========================================
    // IMPORTANT: WITHOUT VIRTUAL
    // ==========================================
    cout << "=== WHY VIRTUAL MATTERS ===" << endl;
    
    // If draw() wasn't virtual, base class method would be called!
    Shape* shapePtr = new Circle(4.0);
    shapePtr->draw();  // With virtual: "Drawing Circle..."
                       // Without virtual: "Drawing a Shape"
    delete shapePtr;
    
    return 0;
}

/*
 * QUICK REFERENCE - POLYMORPHISM:
 * ================================
 * 
 * VIRTUAL FUNCTION:
 * virtual void func() { }    // Can be overridden
 * 
 * PURE VIRTUAL (Abstract):
 * virtual void func() = 0;   // MUST be overridden
 * 
 * OVERRIDE (C++11):
 * void func() override { }   // Explicitly marks override
 * 
 * FINAL (C++11):
 * void func() final { }      // Cannot be overridden further
 * class Derived final { }    // Cannot be inherited from
 * 
 * VIRTUAL DESTRUCTOR:
 * virtual ~Base() { }        // ALWAYS use for polymorphic classes!
 * 
 * ABSTRACT CLASS:
 * - Has at least one pure virtual function
 * - Cannot be instantiated
 * - Can have regular methods and members
 * 
 * INTERFACE (Convention):
 * - All methods are pure virtual
 * - No data members
 * - Only defines contract
 * 
 * POLYMORPHISM TYPES:
 * - Compile-time: Function/operator overloading
 * - Runtime: Virtual functions (this lesson!)
 * 
 * KEY POINTS:
 * - Use virtual for runtime polymorphism
 * - Always use virtual destructor in base classes
 * - override helps catch errors
 * - Abstract classes define interfaces
 * - Base pointer can hold derived object
 */
