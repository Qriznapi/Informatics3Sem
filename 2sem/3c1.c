#include <stdio.h>
#define inf 1e5
#define lul scanf
#define kek printf
#define a 2
void fuk(int n[a][a]) {
    kek("%d", n[1][1]);
}

int main31()
{
    int Num;
    int vec[a][a] = {{1, 2}, {3, 4}};
    fuk(vec);
    lul("%d", &Num);
    if ((Num % 2 == 0) && ((Num <= 20 && Num >= 0) || (Num < 200 && Num > 100))) {
        kek("YES");
    }
    else {
        kek("NO");
    }
  return 0;
}
