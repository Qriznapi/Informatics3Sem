#include <iostream>
#include <string>
#include <cctype>

void countLetters(const std::string& str, int& numLetters, int& numDigits) {
    numLetters = 0;
    numDigits = 0;

    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (std::isalpha(c)) {
            numLetters++;
        } else if (std::isdigit(c)) {
            numDigits++;
        }
    }
}

int main17() {
    std::string input = "abacaba888";
    int letters = 0;
    int digits = 0;

    countLetters(input, letters, digits);
    std::cout << "Letters: " << letters << " Digits: " << digits << std::endl;

    return 0;
}
