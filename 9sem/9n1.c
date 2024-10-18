#include <stdio.h>
#include <stdlib.h>
#include "dynarray.h"

int main() {
    Dynarray myArray;

    init(&myArray, 3);

    for (int i = 0; i < 5; i++)
    {
        //int poppedValue = pop_back(&myArray);
        push_back(&myArray, i * 10);
    }


    print(&myArray);

    resize(&myArray, 3);

    print(&myArray);

    int poppedValue = pop_back(&myArray);
    printf("Popped value: %d\n", poppedValue);
    print(&myArray);

    shrink_to_fit(&myArray);
    print(&myArray);

    Dynarray copiedArray = shallow_copy(&myArray);
    copiedArray.data[0] = 100;
    print(&myArray);
    print(&copiedArray);

    Dynarray deepcopiedArray = deep_copy(&myArray);
    deepcopiedArray.data[0] = 300;
    print(&myArray);
    print(&deepcopiedArray);

    destroy(&myArray);
    return 0;
}
