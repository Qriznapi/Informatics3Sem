#include <stdio.h>

int main51() {
    char s;
    scanf(" %c", &s);

    if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z')) {
        printf("Letter\n");
    } else if (s >= '0' && s <= '9') {
        printf("Digit\n");
    } else {
        printf("Other\n");
    }

    return 0;
}
