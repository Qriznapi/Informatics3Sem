#include <stdio.h>

void bob(int n) {
    while(n % 2 == 0){
        n /= 2;
        printf("%i\n", n);
    }
    if (n == 1)
        return;
    alice(n);
}
void alice(int n) {
    n *= 3;
    n++;
    printf("%i\n", n);
    bob(n);
}

int main39() {

  int n, a[100];

  scanf("%i", &n);
  alice(n);
  printf("\n");
  return 0;
}
