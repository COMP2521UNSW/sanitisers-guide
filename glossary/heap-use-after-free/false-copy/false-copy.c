// Created for COMP2521 sanitiser guide

#include <stdio.h>
#include <stdlib.h>

typedef struct list List;
struct list {
    struct node *head;
};

typedef struct node Node;
struct node {
    int value;
    Node *next;
};

List *listNew();
void listAppend(List *l, int value);
Node *newNode(int value);
List *listCopy(List *l);
void listFree(List *l);

int main(void) {
    // Create a list
    List *l1 = listNew();

    // Create a copy and free the original
    List *l2 = listCopy(l1);
    listFree(l1);

    // Add nodes to the copy
    listAppend(l2, 1);
    listAppend(l2, 2);
    listAppend(l2, 3);

    listFree(l2);
}

// Create new empty list
List *listNew() {
    List *l = malloc(sizeof(*l));
    l->head = NULL;
    return l;
}

// Append a value to the end of a list
void listAppend(List *l, int value) {
    Node *n = newNode(value);
    if (l->head == NULL) {
        l->head = n;
    } else {
        Node *tail = l->head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = n;
    }
}

// Create new node containing value
Node *newNode(int value) {
    Node *n = malloc(sizeof(*n));
    n->value = value;
    n->next = NULL;
    return n;
}

// Create a copy of the given list
List *listCopy(List *l) {
    if (l->head == NULL) {
        // No copying to do
        return l;
    } else {
        List *cp = listNew();
        for (Node *curr = l->head; curr != NULL; curr = curr->next) {
            listAppend(cp, curr->value);
        }
        return cp;
    }
}

// Free the given list
void listFree(List *l) {
    Node *curr = l->head;
    while (curr != NULL) {
        Node *tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    free(l);
}
