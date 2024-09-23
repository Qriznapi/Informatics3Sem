#include <stdio.h>

int main() {
    char s;
    scanf(" %c", &s);

    if ((s >= 65 && s <= 90) || (s >= 97 && s <= 122)) {
        printf("Letter\n");
    } else if (s >= 48 && s <= 57) {
        printf("Digit\n");
    } else {
        printf("Other\n");
    }

    return 0;
}
