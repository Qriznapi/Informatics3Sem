#include <stdio.h>

int sum_of_digits(int a)
{
    int sum = 0;
    while (a > 0){
        sum += a % 10;
        a /= 10;
    }
    return sum;
}
int sum_of_digits_rec(int a, int sum)
{
    if (a != 0)
    {
        sum = sum_of_digits_rec(a / 10, sum) + a % 10;
    }
    return sum;

}


int main() {

  int a;

  scanf("%i", &a);
  printf("%i\n", sum_of_digits_rec(a, 0));
  printf("%i\n", sum_of_digits(a));
  return 0;
}
