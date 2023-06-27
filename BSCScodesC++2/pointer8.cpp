#include <iostream>

// Function that swaps the values of two integers using pointers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;

    // Pass the memory addresses of x and y to the swap function
    swap(&x, &y);

    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    return 0;
}
