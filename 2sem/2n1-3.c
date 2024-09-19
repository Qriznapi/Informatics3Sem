#include <stdio.h>

int main213()
{
  int a[1000];
  int n;
  scanf("%i", &n);
  for (int i = 0; i < n; ++i)
    scanf("%i", &a[i]);
  int l;
  scanf("%i", &l);
  for (int i = l; i < n; ++i)
    a[i] = a[i + 1];
  n -= 1;

  for (int i = 0; i < n; ++i)
    printf("%i ", a[i]);

  printf("\n");
  return 0;
}
