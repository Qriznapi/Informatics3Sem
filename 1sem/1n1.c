#include <stdio.h>
int main()
{
    int Num;
    scanf("%d", &Num);
    if ((Num % 2 == 0) && ((Num <= 20 && Num >= 0) || (Num < 200 && Num > 100))) {
        printf("YES");
    }
    else {
        printf("NO");
    }
  return 0;
}
