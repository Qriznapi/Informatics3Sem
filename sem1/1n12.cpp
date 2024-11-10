#include <iostream>
#include <string>
#include <vector>

std::string concatenate(const std::vector<std::string>& v) {
    std::string result;
    for (int i = 0; i < v.size(); i++) {
        std::string str = v[i];
        result += str;
    }
    return result;
}

int main112() {
    std::vector<std::string> v(5);
    v[0] = "Cat", v[1] = "Dog", v[2] = "Mouse", v[3] = "Tiger", v[4] = "Elk";
    std::cout << concatenate(v) << std::endl; // ������ ���������� CatDogMouseTigerElk

    return 0;
}
