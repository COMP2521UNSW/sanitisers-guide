// Allocate insufficient memory for a struct
// Created for COMP2521 sanitiser guide

#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

int main(void) {
    struct node *n = malloc(sizeof(n));
    n->val = 0;
    n->next = NULL;

    free(n);
    return 0;
}
