#include <stdio.h>
#include <stdlib.h>

int sum_digits(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

int compare_by_sum(const void *a, const void *b) {
  return sum_digits(*(int *)a) - sum_digits(*(int *)b);
}

int main() {
  freopen("numbers.txt", "r", stdin);

  freopen("sorted.txt", "w", stdout);

  int numbers[10000];
  for (int i = 0; i < 10000; i++) {
    scanf("%d", &numbers[i]);
  }

  qsort(numbers, 10000, sizeof(int), compare_by_sum);

  for (int i = 0; i < 10000; i++) {
    printf("%d\n", numbers[i]);
  }

  fclose(stdin);
  fclose(stdout);

  return 0;
}
