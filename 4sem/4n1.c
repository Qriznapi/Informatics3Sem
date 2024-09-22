#include <stdio.h>
long long int fact(long int n)
{
    long long int result = 1;
    for (int i = 1; i <= n; ++i)
        result *= i;
    return result;
}

int main()
{
    int k;
    scanf("%lli", &k);
    printf("%lli\n", fact(k));
}
