#include <stdio.h>

int count_even(int *a, int n) {
  int cnt = 0;

  for (int i = 0; i < n; i++)
    if (a[i] % 2 == 0)
      cnt++;
  printf("%i\n", cnt);
}

int main37() {

  int n, a[100];

  scanf("%i", &n);
  for (int i = 0; i < n; i++){
    scanf("%i", &a[i]);
  }
  count_even(a, n);

  return 0;
}
