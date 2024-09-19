#include <stdio.h>

int main216()
{
  int a[1000];
  int n;
  scanf("%i", &n);
  for (int i = 0; i < n; ++i)
    scanf("%i", &a[i]);

  int temp[n];
  int temp_size = 0;
  int temp1[n];
  int temp_size1 = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] % 2 != 0) {
      temp[temp_size] = a[i];
      temp_size++;
    }
    else {
      temp1[temp_size1] = a[i];
      temp_size1++;
    }
  }

  for (int i = 0; i < temp_size; i++) {
    a[i] = temp[i];
  }
  for (int i = 0; i < temp_size1; i++) {
    a[i + temp_size] = temp1[i];
  }
  n = temp_size + temp_size1;


  for (int i = 0; i < n; ++i)
    printf("%i ", a[i]);

  printf("\n");
  return 0;
}
