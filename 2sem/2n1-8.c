#include <stdio.h>

int main218()
{
  int a[1000];
  int n;
  scanf("%i", &n);
  for (int i = 0; i < n; ++i)
    scanf("%i", &a[i]);

  int temp[n];
  int k;

  scanf("%i", &k);
  for (int i = 0; i < n; i++) {
    temp[(i + k) % n] = a[i];
  }

  for (int i = 0; i < n; i++) {
    a[i] = temp[i];
  }

  for (int i = 0; i < n; ++i)
    printf("%i ", a[i]);

  printf("\n");
  return 0;
}
