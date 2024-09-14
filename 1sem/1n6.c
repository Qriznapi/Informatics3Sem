#include <stdio.h>

int get_length(int n) {
  int length = 1;
  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }
    length++;
  }
  return length;
}

int main() {
  int a, b, max_length = 0, n = 0;
  scanf("%d %d", &a, &b);

  for (int i = a; i <= b; i++) {
    int current_length = get_length(i);
    if (current_length > max_length) {
      max_length = current_length;
      n = i;
    }
  }
  printf("%d %d\n", n, max_length);
  return 0;
}
