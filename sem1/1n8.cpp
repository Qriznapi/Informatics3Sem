#include <iostream>
#include <string>

void addBrackets(std::string& str) {
    str = "[" + str + "]";
}

int main18() {
    std::string a = "Cat";
    addBrackets(a);
    std::cout << a << std::endl; // ������ ���������� [Cat]
    addBrackets(a);
    std::cout << a << std::endl; // ������ ���������� [[Cat]]

    return 0;
}
