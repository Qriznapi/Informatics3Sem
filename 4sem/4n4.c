#include <stdio.h>
#include <math.h>

double fpi(int n)
{
    double res = 0.0;
    for (int i = 1; i <= n; i++) {
        res += pow(-1, i + 1) / (2 * i - 1.0);
    }
    return res * 4.0;

}

int main()
{
    int n, k;
    scanf("%i", &n);
    printf("%lf\n", fpi(n));
}
