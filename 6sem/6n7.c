#include <stdio.h>

int exchange(int* pa, int b)
{
    int var = *pa;
    *pa = b;
    return var;
}


int main67()
{
    int a = 10;
    printf("%i\n", exchange(&a, 20));  // ���������� 10
    printf("%i\n", a);                 // ���������� 20
}
