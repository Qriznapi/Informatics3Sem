#include <stdio.h>
#include <string.h>

int is_palindrom(char *a)
{
    int len = strlen(a);
    int flag = 0;

    for (int i = 0; i < len; i ++) {
        if (a[i] != a[len - i - 1])
            flag = 1;
    }
    return 1 - flag;
}

int main() {
    char a[100];

    scanf("%s", a);
    int flag = is_palindrom(a);
    if (flag)
        printf("YES");
    else
        printf("NO");
    printf("\n");

    return 0;
}
