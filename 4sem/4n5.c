#include <stdio.h>
#include <math.h>

double circles(int a, int b, int x, int y)
{
    return pow((a-x)*(a-x)+(b-y)*(b-y), 0.5);
}

int main45()
{
    int a, b, c, x, y, z;
    scanf("%i %i %i", &x, &y, &z);
    scanf("%i %i %i", &a, &b, &c);
    if (circles(a, b, x, y) > c + z)
        printf("Do not intersect");
    if (circles(a, b, x, y) < c + z)
        printf("Intersect");
    if (circles(a, b, x, y) == c + z)
        printf("Touch");
}
