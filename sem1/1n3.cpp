#include <iostream>

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main13() {
    int a = 10;
    int b = 20;
    std::cout << a << " " << b << std::endl; // Должно напечатать 10 20
    swap(a, b);
    std::cout << a << " " << b << std::endl; // Должно напечатать 20 10
    return 0;
}
