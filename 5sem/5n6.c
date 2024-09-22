#include <stdio.h>
#include <string.h>

int main() {
    int x = 0, y = 0;
    int n;
    scanf("%d", &n);

    char direction[100];
    int distance;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", direction, &distance);

        if (strcmp(direction, "North") == 0) {
            y += distance;
        } else if (strcmp(direction, "South") == 0) {
            y -= distance;
        } else if (strcmp(direction, "East") == 0) {
            x += distance;
        } else if (strcmp(direction, "West") == 0) {
            x -= distance;
        }
    }

    printf("%d %d\n", x, y);

    return 0;
}
