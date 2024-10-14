#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char* title;
    int pages;
    float price;
};
typedef struct book Book;

void print_book(Book book) {
    printf("Name: %s\n", book.title);
    printf("Piggies: %d\n", book.pages);
    printf("Price: %.2f\n", book.price);
}

struct library {
    Book* books;
    int num;
};
typedef struct library Library;

Library library_create(int num) {
    Library library;
    library.books = (Book*)malloc(num * sizeof(Book));
    library.num = num;
    return library;
}

void library_set(Library* library, int i, char* title, int pages, float price) {

    library->books[i].title = (char*)malloc(50 + 1);
    strcpy(library->books[i].title, title);
    library->books[i].pages = pages;
    library->books[i].price = price;
}

Book* library_get(Library library, int i) {
    return &library.books[i];
}

void library_print(Library library) {
    for (int i = 0; i < library.num; i++) {
        printf("beek %d:\n", i + 1);
        print_book(library.books[i]);
    }
}

void library_destroy(Library* library) {
    for (int i = 0; i < library->num; i++) {
        free(library->books[i].title);
    }
    free(library->books);
    library->books = NULL;
    library->num = 0;
}

int main() {
    Book* book_ptr = (Book*)malloc(sizeof(Book));
    char* title = (char*)malloc(50 * sizeof(char));
    strcpy(title, "bablo");
    book_ptr->title = title;
    book_ptr->pages = 107;
    book_ptr->price = 228;
    print_book(*book_ptr);
    free(book_ptr->title);
    free(book_ptr);
    printf("\n");

    Book** books = (Book**)malloc(3 * sizeof(Book*));
    for (int i = 0; i < 3; i++) {
        books[i] = (Book*)malloc(sizeof(Book));
        books[i]->title = (char*)malloc(50 * sizeof(char));
    }
    strcpy(books[0]->title, "chopa");
    books[0]->pages = 108;
    books[0]->price = 228;
    strcpy(books[1]->title, "chapa");
    books[1]->pages = 109;
    books[1]->price = 228;
    strcpy(books[2]->title, "chipa");
    books[2]->pages = 110;
    books[2]->price = 228;
    for (int i = 0; i < 3; i++) {
        printf("num%d:\n", i + 1);
        print_book(*books[i]);
    }
    for (int i = 0; i < 3; i++) {
        free(books[i]->title);
        free(books[i]);
    }
    free(books);
    printf("\n");

    Library a = library_create(3);
    library_set(&a, 0, "rubi", 111, 228);
    library_set(&a, 1, "dubi", 112, 228);
    library_set(&a, 2, "daba", 113, 228);
    library_print(a);
    print_book(*library_get(a, 1));
    library_destroy(&a);
    printf("\n");
    return 0;
}
