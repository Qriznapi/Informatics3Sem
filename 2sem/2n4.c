#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%i", &n);
    int a[100][100];
    int b[100][100];
    int c[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%i", &a[i][j]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%i", &b[i][j]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%i ", c[i][j]);
        printf("\n");
    }
    return 0;
}
