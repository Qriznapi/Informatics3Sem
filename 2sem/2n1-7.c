#include <stdio.h>

int main()
{
  int a[1000];
  int n;
  scanf("%i", &n);
  for (int i = 0; i < n; ++i)
    scanf("%i", &a[i]);

  for (int i = 2*n-1; i >= 0; i--) {
    a[i] = a[i / 2];
  }
  n *= 2;

  for (int i = 0; i < n; ++i)
    printf("%i ", a[i]);

  printf("\n");
  return 0;
}
