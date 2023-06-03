// Created for COMP2521 sanitiser guide

#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

int main(void) {
    struct node *n = NULL;
    n->value = 69;
    n->next = NULL;
}
