#include <stdio.h>

int main()
{
  int a[1000];
  int n;
  scanf("%i", &n);
  for (int i = 0; i < n; ++i)
    scanf("%i", &a[i]);

  int l, m;
  scanf("%i %i", &l, &m);

  for (int i = l; i < n; ++i)
    a[i] = a[i + m - l];
  n -= m - l;

  for (int i = 0; i < n; ++i)
    printf("%i ", a[i]);

  printf("\n");
  return 0;
}
