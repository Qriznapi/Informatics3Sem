#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100];

    scanf("%s %s", a, b);

    int len1 = strlen(a);
    int len2 = strlen(b);

    int i = 0, j = 0;

    while (i < len1 || j < len2) {
        if (i < len1) {
            printf("%c", a[i]);
            i++;
        }
        if (j < len2) {
            printf("%c", b[j]);
            j++;
        }
    }

    printf("\n");

    return 0;
}
