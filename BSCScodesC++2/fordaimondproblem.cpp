#include<iostream>
class Base {
public:
    virtual void display() {
        std::cout << "Base class" << std::endl;
    }
};

class Derived1 : virtual public Base {
public:
    void display() override {
        std::cout << "Derived1 class" << std::endl;
    }
};

class Derived2 : virtual public Base {
public:
    void display() override {
        std::cout << "Derived2 class" << std::endl;
    }
};

class Diamond : public Derived1, public Derived2 {
public:
    void display() override {
        std::cout << "Diamond class" << std::endl;
    }
};


int main() {
    Diamond d;
    d.Derived1::display();  // Call display() from Derived1
    d.Derived2::display();  // Call display() from Derived2

    return 0;
}

