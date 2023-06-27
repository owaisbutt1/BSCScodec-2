#include <iostream>

class MyClass {
private:
    int* ptr;

public:
    // Default constructor
    MyClass(int value) {
        ptr = new int(value);
    }

    // Copy constructor
    MyClass(const MyClass& other) {
        ptr = new int(*other.ptr);
    }

    // Destructor
    ~MyClass() {
        delete ptr;
    }
};

int main() {
    MyClass obj1(42);
    MyClass obj2(obj1);  // Copy constructor invoked for deep copy

    return 0;
}

