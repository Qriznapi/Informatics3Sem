#include <stdio.h>
#include <string.h>

char* strmax(char** strings, size_t n)
{
    int maxi = 0;
    for (int i = 0; i < n; i++){
        if (strcmp(strings[maxi], strings[i]) < 0)
            maxi = i;
    }
    return strings[maxi];
}

int main()
{
    char a[] = "Wplf";
    char b[] = "Mouse";
    char c[] = "Wolf";
    char d[] = "Kangaroo";
    char e[] = "Elephant";

    char* animals[5] = {&a[0], &b[0], &c[0], &d[0], &e[0]};
    char* x = strmax(animals, 5);
    printf("%s\n", x);
}
