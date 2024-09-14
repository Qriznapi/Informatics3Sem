#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%i", &n);
    int min = INT_MAX;  // Инициализируем min максимальным значением int
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%i", &a);
        if (a < min)
            min = a;
    }
    printf("Min = %i\n", min);
    return 0;
}
