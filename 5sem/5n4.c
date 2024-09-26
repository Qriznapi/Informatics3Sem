#include <stdio.h>
#include <string.h>

void encrypt(char str[100], int k) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'A' + (str[i] - 'A' + k) % 26;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + (str[i] - 'a' + k) % 26;
        }
    }
}

int main() {
    char str[100];
    int k;

    scanf("%d %[^\n]", &k, str);

    encrypt(str, k);

    printf("%s\n", str);

    return 0;
}
