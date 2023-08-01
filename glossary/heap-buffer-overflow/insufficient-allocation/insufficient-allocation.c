// Allocate insufficient memory for a struct
// Created for COMP2521 sanitiser guide

#include <stdlib.h>

typedef struct node *Node;
struct node {
    int val;
    Node next;
};

int main(void) {
    Node n = malloc(sizeof(Node));
    n->val = 0;
    n->next = NULL;

    free(n);
    return 0;
}
