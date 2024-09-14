#include <stdio.h>

int main() {
  int n, i;

  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    printf("%3i -> %3i -> %3i\n", i, i * i, i * i * i);
  }

  return 0;
}
