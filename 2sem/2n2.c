#include <stdio.h>

int main()
{
    int n, m;
    scanf("%i %i", &n, &m);
    int a[100000] = {0};
    int b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            scanf("%i", &b);
            a[j] += b;
        }
    }

    for (int i = 0; i < m; ++i)
        printf("%i ", a[i]);

    printf("\n");
    return 0;
}
