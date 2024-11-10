#include <iostream>
#include <string>

std::string repeat(int n) {
    if (n <= 0)
        return "";

    std::string result;
    for (int i = 0; i < n; ++i) {
        result += std::to_string(n);
    }
    return result;
}

int main() {
    std::cout << repeat(5) << std::endl;   // Äîëæíî íàïå÷àòàòü 55555
    std::cout << repeat(10) << std::endl;  // Äîëæíî íàïå÷àòàòü 10101010101010101010
    std::cout << repeat(-1) << std::endl;  // Íå äîëæíî íè÷åãî ïå÷àòàòü

    return 0;
}
