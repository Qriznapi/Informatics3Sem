#include <stdio.h>
#include <stdlib.h>

struct book
{
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;


int main81() {
    size_t* number = (size_t*)malloc(sizeof(size_t));

    *number = 123;
    printf("%zu\n", *number);
    free(number);

    char* str = (char*)malloc(10 * sizeof(char));
    strcpy(str, "Elephant");
    printf("%s\n", str);

    char** ptr_to_str = (char**)malloc(sizeof(char*));
    *ptr_to_str = str;
    printf("%s\n", *ptr_to_str);
    free(str);
    free(ptr_to_str);

    Book* book_ptr = (Book*)malloc(sizeof(Book));
    strcpy(book_ptr->title, "abob");
    book_ptr->pages = 101;
    book_ptr->price = 228;
    printf("%i\n", book_ptr->pages);
    free(book_ptr);

    Book book;
    strcpy(book.title, "boba");
    book.pages = 102;
    book.price = 228;
    Book* book_ptr1 = &book;
    printf("%i\n", book_ptr1->pages);


    Book* book_ptr2 = (Book*)malloc(sizeof(Book));
    strcpy(book_ptr2->title, "doba");
    book_ptr2->pages = 103;
    book_ptr2->price = 228;
    printf("%i\n", book_ptr2->pages);
    free(book_ptr2);

    Book* books = (Book*)malloc(3 * sizeof(Book));
    strcpy(books[0].title, "dora");
    books[0].pages = 104;
    books[0].price = 228;
    strcpy(books[1].title, "dura");
    books[1].pages = 105;
    books[1].price = 228;
    strcpy(books[2].title, "daba");
    books[2].pages = 106;
    books[2].price = 228;
    for (int i = 0; i < 3; i++) {
        printf("%i\n", books[i].pages);
    }
    free(books);

    return 0;
}
