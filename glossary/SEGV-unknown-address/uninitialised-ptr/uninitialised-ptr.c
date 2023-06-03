// Created for COMP2521 sanitiser guide

#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

int main(void) {
    struct node *n = malloc(sizeof(*n));
    n->value = 0;
    n->next->value = 1;
}
