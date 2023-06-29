// Created for COMP2521 sanitiser guide

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *listAppend(struct node *list, int value);
struct node *listDelete(struct node *list, int value);
void listPrint(struct node *list);

int main(void) {
    // Create list 1 -> 2 -> 3 -> X
    struct node *list = NULL;
    list = listAppend(list, 1);
    list = listAppend(list, 2);
    list = listAppend(list, 3);
    listPrint(list);
    printf("\n");

    // Delete 3
    listDelete(list, 3);
    listPrint(list);
    printf("\n");

    // Delete 1
    listDelete(list, 1);
    listPrint(list);
}

// Append a value to the end of a list
struct node *listAppend(struct node *list, int value) {
    struct node *new = malloc(sizeof(*new));
    new->value = value;
    new->next = NULL;

    // List is empty
    if (list == NULL) {
        return new;
    }

    struct node *curr = list;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new;
    return list;
}

// Delete the first occurrence of a value from a list
struct node *listDelete(struct node *list, int value) {
    if (list == NULL) {
        // Empty list
        return NULL;
    } else if (list->value == value) {
        // Head contains value
        struct node *newHead = list->next;
        free(list);
        return newHead;
    } else {
        // Loop and find value
        struct node *curr = list;
        while (curr != NULL && curr->next != NULL) {
            if (curr->next->value == value) {
                // Next node contains value, free it
                free(curr->next);
                break;
            }
            curr = curr->next;
        }
        return list;
    }
}

// Print out a list
void listPrint(struct node *list) {
    for (struct node *curr = list; curr != NULL; curr = curr->next) {
        printf("%d\n", curr->value);
    }
}
