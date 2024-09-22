#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void transpose(float a[MAX][MAX], int n){
    float c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            c = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = c;
        }
    }
}
void print(float *a[MAX][MAX], int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%i ", a[i][j]);
        printf("\n");
    }
}

int main() {
  freopen("matA.txt", "r", stdin);

  freopen("result.txt", "w", stdout);

  int n, m;
  scanf("%i", &n);
  float a[20][20];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      scanf("%i", &a[i][j]);
  }
  transpose(a, n);
  print(a, n);

  fclose(stdin);
  fclose(stdout);

  return 0;
}
