#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Game {
    char title[50];
    float avg;
};

int cmpg(const void *a, const void *b) {
    const struct Game *game_a = (const struct Game *)a;
    const struct Game *game_b = (const struct Game *)b;

    if (game_a->avg > game_b->avg) {
        return -1;
    } else if (game_a->avg < game_b->avg)
        return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d\n", &n);

    struct Game games[50];

    for (int i = 0; i < n; i++) {
        char title[50];
        char temp;
        int k;
        float sum = 0;

        scanf("%[^:]", title);
        scanf("%c", &temp);
        scanf("%i", &k);

        for (int j = 0; j < k; j++) {
            int rating;
            scanf("%d", &rating);
            sum += rating;
        }

        scanf("%c", &temp);

        strcpy(games[i].title, title);
        games[i].avg = sum / k;
    }

    qsort(games, n, sizeof(struct Game), cmpg);

    for (int i = 0; i < n; i++) {
        printf("%s, %.3f\n", games[i].title, games[i].avg);
    }

    return 0;
}
