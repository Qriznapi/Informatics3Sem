#include <stdio.h>

void print_binary(int a) {
    if (a <= 1){
        printf("%i", a);
        return;
    }
    print_binary(a / 2);
    printf("%i", a % 2);
}

int main35() {

  int a;

  scanf("%i", &a);
  print_binary(a);

  return 0;
}
