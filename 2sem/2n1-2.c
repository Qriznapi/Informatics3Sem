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
  for (int i = m + 1; i < n; ++i)
    a[i + 1] = a[i];
  a[m + 1] = l;
  n += 1;

  for (int i = 0; i < n; ++i)
    printf("%i ", a[i]);

  printf("\n");
  return 0;
}
