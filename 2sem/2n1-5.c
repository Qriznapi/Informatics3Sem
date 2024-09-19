#include <stdio.h>

int main215()
{
  int a[1000];
  int n;
  scanf("%i", &n);
  for (int i = 0; i < n; ++i)
    scanf("%i", &a[i]);

  int temp[n];
  int temp_size = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] >= 0) {
      temp[temp_size] = a[i];
      temp_size++;
    }
  }

  for (int i = 0; i < temp_size; i++) {
    a[i] = temp[i];
  }

  n = temp_size;
  for (int i = 0; i < n; ++i)
    printf("%i ", a[i]);

  printf("\n");
  return 0;
}
