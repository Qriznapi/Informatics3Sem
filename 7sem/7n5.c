#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* ptr;
};
typedef struct node Node;

int main() {
    Node node1 = {100, NULL};
    Node node2 = {200, NULL};

    node1.ptr = &node2;
    node2.ptr = &node1;

    printf("node1: %i\n", node1.value);
    printf("node2: %i\n", node2.value);
    printf("node1p: %p\n", node1.ptr);
    printf("node2p: %p\n", node2.ptr);
    printf("node1pval %i\n", node1.ptr -> value);
    printf("node2pval %i\n", node2.ptr -> value);
    return 0;
}
