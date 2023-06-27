#include <iostream>

class MyClass {
private:
    int* sharedData;
    int* counter;

public:
    // Default constructor
    MyClass(int value) {
        sharedData = new int(value);
        counter = new int(1);
    }

    // Copy constructor
    MyClass(const MyClass& other) {
        sharedData = other.sharedData;
        counter = other.counter;
        (*counter)++;
    }

    // Destructor
    ~MyClass() {
        (*counter)--;
        if (*counter == 0) {
            delete sharedData;
            delete counter;
        }
    }
};

int main() {
    MyClass obj1(42);
    MyClass obj2(obj1);  // Copy constructor invoked for sharing resource

    return 0;
}

