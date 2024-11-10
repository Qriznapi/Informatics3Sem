#include <iostream>

int& getRefToMax(int& a, int& b) {
    if (a > b)
        return a;
    return b;
}

int main14() {
    int a = 10;
    int b = 20;
    getRefToMax(a, b) += 1;
    std::cout << a << " " << b << std::endl; // Должно напечатать 10 21
    return 0;
}
