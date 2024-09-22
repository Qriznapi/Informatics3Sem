#include <stdio.h>

int is_even(int a)
{
    return 1 - a % 2;
}

int main32() {

  int a, b, max_length = 0, n = 0;

  printf("%i\n", is_even(90));
  printf("%i\n", is_even(91));
  return 0;
}
