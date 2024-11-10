#include <iostream>
#include <string>

void addBrackets(std::string& str) {
    str = "[" + str + "]";
}

int main18() {
    std::string a = "Cat";
    addBrackets(a);
    std::cout << a << std::endl; // Должно напечатать [Cat]
    addBrackets(a);
    std::cout << a << std::endl; // Должно напечатать [[Cat]]

    return 0;
}
