#include <stdio.h>

void mult2(int* p, size_t n) {
    for (int i = 0; i < n; i++) {
        *(p + i) *= 2;
    }
}
void mult2b(int* p, size_t n) {
    for (int i = 0; i < n; i++) {
        p[i + 1] *= 2;
    }
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5};
    mult2(&a, 5);
    mult2b(&a, 5);
    printf("%i\n", a[4]);
}
