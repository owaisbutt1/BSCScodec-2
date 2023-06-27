#include <iostream>

class Shape {
public:
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Square" << std::endl;
    }
};

int main() {
    Circle circle;
    Square square;

    Shape& shapeRef = circle;
    shapeRef.draw();   // Calls Circle's draw() function

    shapeRef = square;
    shapeRef.draw();   // Calls Square's draw() function

    return 0;
}

