#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // Ascending order
    // return (*(int*)b - *(int*)a); // Descending order
}

int main23()
{
    int n, m;
    scanf("%i %i", &n, &m);
    int a[100000] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            scanf("%i", &a[j]);
        qsort(a, m, sizeof(int), compare);
        for (int j = 0; j < m; ++j)
            printf("%i ", a[j]);
        printf("\n");
    }


    //printf("\n");
    return 0;
}
