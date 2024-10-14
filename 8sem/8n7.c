#include <stdio.h>
#include <math.h>

size_t count_if(int* arr, size_t n, int (*predicate)(int)) {
    size_t count = 0;
    for (size_t i = 0; i < n; ++i) {
        if (predicate(arr[i])) {
            count++;
        }
    }
    return count;
}

int is_negative(int num) {
    return num < 0;
}

int is_even(int num) {
    return num % 2 == 0;
}

int is_square(int num) {
    int sqrt_num = sqrt(num);
    return sqrt_num * sqrt_num == num;
}

int main() {
    int a[] = {89, 81, 28, 52, 44, 16, -64, 49, 52, -79};

    printf("%zu\n", count_if(a, 10, is_negative));  // Должен напечатать 2
    printf("%zu\n", count_if(a, 10, is_even));      // Должен напечатать 6
    printf("%zu\n", count_if(a, 10, is_square));    // Должен напечатать 3

    return 0;
}
