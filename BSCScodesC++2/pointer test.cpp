#include <iostream>


class Shape {
public:
    virtual int calculateArea() = 0;
};
class Rectangle :public Shape{
private:
    int width;
    int height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    int calculateArea() {
        return width * height;
    }
};

class Square : public Shape {
private:
    int side;

public:
    Square(int s) : side(s) {}

    int calculateArea() override {
        return side * side;
    }
};

int main() {
    Rectangle rectangle(4, 6);
    Square square(5);

    Shape* shape1 =&rectangle;
    Shape& shape3=rectangle;
    std::cout<<"Rectangle Area: " << shape3.calculateArea() << std::endl;
//    Shape* shape2 = &square;

    std::cout << "Rectangle Area: " << shape1->calculateArea() << std::endl;
//    std::cout << "Square Area: " << shape2->calculateArea() << std::endl;

    return 0;
}

