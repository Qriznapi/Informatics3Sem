#include <stdio.h>

void cube(float* px){
    float dx = (*px) * (*px);
    *px *= dx;
}


int main()
{
    float a = 10;
    cube(&a);
    printf("%f\n", a);
}
