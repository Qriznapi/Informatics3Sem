#include <stdio.h>

int trib(int a)
{
    int t[100] = {0};
    t[2] = 1;
    for (int i = 3; i <= a; i++) {
        t[i] = t[i - 1] + t[i - 2] + t[i - 3];
    }
    return t[a];
}

int main36() {

  int a;

  scanf("%i", &a);
  printf("%i\n", trib(a));

  return 0;
}
