#include <stdio.h>

int main() {
    char s;
    scanf(" %c", &s);

    if (isalpha(s)) {
        printf("Letter\n");
    } else if (isdigit(s)) {
        printf("Digit\n");
    } else {
        printf("Other\n");
    }

    return 0;
}