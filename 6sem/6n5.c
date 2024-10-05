#include <stdio.h>
#include <math.h>

int solve_quadratic(double a, double b, double c, double* px1, double* px2) {
    double d = b * b - 4 * a * c;
    double eps = 1e-10;

    if (fabs(d) < eps) {
        *px1 = -b / (2 * a);
        return 1;
    } else if (d > eps) {
        *px1 = (-b + sqrt(d)) / (2 * a);
        *px2 = (-b - sqrt(d)) / (2 * a);
        return 2;
    }
    return 0;
}

int main65() {
    double a, b, c, x1, x2;
    scanf("%lf %lf %lf", &a, &b, &c);

    int num_roots = solve_quadratic(a, b, c, &x1, &x2);

    if (num_roots == 0) {
        printf("NO \n");
    } else if (num_roots == 1) {
        printf("1: %lf\n", x1);
    } else {
        printf("2: %lf %lf\n", x1, x2);
    }

    return 0;
}
