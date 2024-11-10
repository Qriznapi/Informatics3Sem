#include <iostream>
#include <vector>

void doubling(std::vector<int>& v) {
    size_t s = v.size();
    v.resize(s * 2);

    for (std::size_t i = 0; i < s; ++i) {
        v[i + s] = v[i];
    }
}

void print(const std::vector<int>& v) {
    for (std::size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main111() {
    std::vector<int> v(3);
    v[0] = 10;
    v[1] = 20;
    v[2] = 30;
    doubling(v);
    print(v); // Должно напечатать 10 20 30 10 20 30

    return 0;
}
