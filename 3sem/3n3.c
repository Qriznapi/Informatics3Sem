#include <stdio.h>

void print_even(int a, int b)
{
    for (int i = a; i <= b; i++){
        if (i % 2 == 0)
            printf("%i\n", i);
    }
}

int main33() {

  int a, b;

  scanf("%i %i", &a, &b);
  print_even(a, b);

  return 0;
}