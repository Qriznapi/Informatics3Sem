#include <iostream>
#include <string>

bool isDomainName(const std::string& str) {
    if ((str.rfind("www.", 0) == 0) && (str.substr(str.size() - 4) == ".com"))
        return 1;
    return 0;
}

int main110() {
    std::cout << isDomainName("www.google.com") << std::endl; // ���������� 1
    std::cout << isDomainName("abc") << std::endl;            // ���������� 0
    std::cout << isDomainName("hello.com") << std::endl;      // ���������� 0

    return 0;
}
