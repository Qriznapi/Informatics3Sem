#include <iostream>
#include <string>

using std::cout;
using std::endl;

struct Book {
    std::string title;
    int pages;
    float price;
};

bool isExpensive(const Book& book) {
    return book.price > 1000;
}

int main15() {
    Book book1{"Expensive", 300, 1500};
    Book book2{"Cheap", 200, 500};

    cout << isExpensive(book1) << endl;
    cout << isExpensive(book2) << endl;

    return 0;
}
