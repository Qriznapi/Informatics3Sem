#include <iostream>

void cube(int& n) {
    n = n * n * n;
}

int main12() {
    int a = 5;
    cube(a);
    std::cout << a << std::endl; // ������ ���������� 125
    return 0;
}
