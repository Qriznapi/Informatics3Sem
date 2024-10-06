#include <stdio.h>

struct cat {
    char x;
    size_t y;
};

struct dog {
    size_t y;
    char x;
};

struct mouse {
    char x;
    char y;
    size_t z;
};

struct rat {
    char x;
    size_t z;
    char y;
};

struct fox {
    char x;
    struct mouse y;
};

int main74() {
    printf("char %zu %zu\n", sizeof(char), _Alignof(char));
    printf("int %zu %zu\n", sizeof(int), _Alignof(int));
    printf("size_t %zu %zu\n", sizeof(size_t), _Alignof(size_t));
    printf("int[10] %zu %zu\n", sizeof(int[10]), _Alignof(int[10]));
    printf("int* %zu %zu\n", sizeof(int*), _Alignof(int*));
    printf("structCat %zu %zu\n", sizeof(struct cat), _Alignof(struct cat));
    printf("structDog %zu %zu\n", sizeof(struct dog), _Alignof(struct dog));
    printf("structMouse %zu %zu\n", sizeof(struct mouse), _Alignof(struct mouse));
    printf("structRat %zu %zu\n", sizeof(struct rat), _Alignof(struct rat));
    printf("structFox %zu %zu\n", sizeof(struct fox), _Alignof(struct fox));
    return 0;
}
