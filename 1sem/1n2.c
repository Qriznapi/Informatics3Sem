#include <stdio.h>

int main() {
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);

  if (a == b && b == c) {
    printf("Equal\n");
  } else if (a + 1 == b && b + 1 == c) {
    printf("Consecutive Increasing\n");
  } else if (a - 1 == b && b - 1 == c) {
    printf("Consecutive Decreasing\n");
  } else if (a < b && b < c) {
    printf("Increasing\n");
  } else if (a > b && b > c) {
    printf("Decreasing\n");
  } else {
    printf("None\n");
  }
  return 0;
}
