#include <stdio.h>
float yearfrac(int n, int k)
{
    float result = 0;
    if (n % 4 == 0){
        result = k / 366.0;
    }
    else {
        result = k / 365.0;
    }
    return result;
}

int main43()
{
    int n, k;
    scanf("%i %i", &n, &k);
    printf("%f\n", yearfrac(n, k));
}
