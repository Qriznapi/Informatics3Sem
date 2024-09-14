#include <stdio.h>

int main() {
  int n, length = 0, max = 0;
  scanf("%d", &n);
  printf("%d ", n);
  max = n;

  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }
    length++;
    printf("%d ", n);
    if (n > max) {
      max = n;
    }
  }

  printf("\nLength = %d, Max = %d\n", length + 1, max);

  return 0;
}
