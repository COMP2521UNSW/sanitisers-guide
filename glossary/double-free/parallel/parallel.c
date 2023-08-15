// Created for COMP2521 sanitiser guide
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

struct node {
    char *data;
    struct node *next;
};

struct node *listAppend(struct node *list, char *data);
struct node *listPrepend(struct node *list, char *data);
struct node *newNode(char *data);
int listFind(struct node *list, char *data);
void listFree(struct node *list);

int main(void) {
    // Create two lists for different orders
    struct node *alphabetical = NULL;
    struct node *reverse = NULL;

    // Insert the following strings into both
    char *strings[N] = {"a", "c", "g", "m", "t"};
    for (int i = 0; i < N; i++) {
        char *allocatedString = strdup(strings[i]);
        alphabetical = listAppend(alphabetical, allocatedString);
        reverse = listPrepend(reverse, allocatedString);
    }

    printf("# nodes scanned looking for \"a\" in alphabetical list: %d\n",
           listFind(alphabetical, "a"));
    printf("# nodes scanned looking for \"a\" in reverse alphabetical list: %d\n",
           listFind(reverse, "a"));
    printf("\n");

    printf("# nodes scanned looking for \"m\" in alphabetical list: %d\n",
           listFind(alphabetical, "m"));
    printf("# nodes scanned looking for \"m\" in reverse alphabetical list: %d\n",
           listFind(reverse, "m"));
    printf("\n");

    listFree(alphabetical);
    listFree(reverse);
}

struct node *listAppend(struct node *list, char *data) {
    if (list == NULL) {
        return newNode(data);
    } else {
        list->next = listAppend(list->next, data);
        return list;
    }
}

struct node *listPrepend(struct node *list, char *data) {
    struct node *n = newNode(data);
    n->next = list;
    return n;
}

struct node *newNode(char *data) {
    struct node *n = malloc(sizeof(*n));
    n->data = data;
    n->next = NULL;
    return n;
}

// Returns the number of nodes searched while looking for data
int listFind(struct node *list, char *data) {
    if (list == NULL) {
        return 0;
    } else if (strcmp(list->data, data) == 0) {
        return 1;
    } else {
        return listFind(list->next, data) + 1;
    }
}

void listFree(struct node *list) {
    if (list != NULL) {
        listFree(list->next);
        free(list->data);
        free(list);
    }
}
