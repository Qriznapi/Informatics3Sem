#include <stdio.h>

int exchange(int* pa, int b)
{
    int var = *pa;
    *pa = b;
    return var;
}


int main()
{
    int a = 10;
    printf("%i\n", exchange(&a, 20));  // Íàïå÷àòàåò 10
    printf("%i\n", a);                 // Íàïå÷àòàåò 20
}
