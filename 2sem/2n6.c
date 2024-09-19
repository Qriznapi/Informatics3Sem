#include <stdio.h>
#include <stdlib.h>


int main() {
  freopen("matAB.txt", "r", stdin);

  freopen("matC.txt", "w", stdout);

  int n, m;
    scanf("%i", &n);
    int a[11][11] = {0};
    int b[11][11] = {0};
    int c[11][11] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%i", &a[i][j]);
    }
    scanf("%i", &m);
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


  fclose(stdin);
  fclose(stdout);

  return 0;
}
