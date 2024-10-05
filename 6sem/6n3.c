#include <stdio.h>

void cube(float* px){
    float dx = (*px) * (*px);
    *px *= dx;
}


int main63()
{
    float a = 10;
    cube(&a);
    printf("%f\n", a);
}
