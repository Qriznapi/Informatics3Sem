#include <stdio.h>

void reverse(int *a, int n) {
  int c = 0;

  for (int i = 0; i < n / 2; i++) {
      c = a[i];
      a[i] = a[n - i - 1];
      a[n - i - 1] = c;
  }
}

int main() {

  int n, a[100];

  scanf("%i", &n);
  for (int i = 0; i < n; i++){
    scanf("%i", &a[i]);
  }
  reverse(a, n);

  for (int i = 0; i < n; i++){
    printf("%i ", a[i]);
  }
  printf("\n");
  return 0;
}
