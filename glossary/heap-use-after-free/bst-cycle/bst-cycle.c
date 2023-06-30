// Created for COMP2521 sanitiser guide

#include <stdio.h>
#include <stdlib.h>

typedef struct bst BST;
struct bst {
    int value;
    BST *left;
    BST *right;
};

BST *bstInsert(BST *t, int value);
BST *newNode(int value);
void bstFree(BST *t);
BST *rotateLeft(BST *t1);

int main(void) {
    // Create a tree like
    //   2
    //  / \
    // 1   4
    //    / \
    //   3   5
    BST *t = NULL;
    t = bstInsert(t, 2);
    t = bstInsert(t, 1);
    t = bstInsert(t, 4);
    t = bstInsert(t, 3);
    t = bstInsert(t, 5);

    // Rotate it left to be
    //     4
    //    / \
    //   2   5
    //  / \
    // 1   3
    t = rotateLeft(t);

    bstFree(t);
}

BST *bstInsert(BST *t, int value) {
    if (t == NULL) {
        return newNode(value);
    }

    if (value < t->value) {
        t->left = bstInsert(t->left, value);
    } else if (value > t->value) {
        t->right = bstInsert(t->right, value);
    }
    return t;
}

BST *newNode(int value) {
    BST *t = malloc(sizeof(*t));
    t->value = value;
    t->left = NULL;
    t->right = NULL;
    return t;
}

void bstFree(BST *t) {
    if (t != NULL) {
        printf("Freeing %d\n", t->value);
        bstFree(t->left);
        bstFree(t->right);
        free(t);
    }
}

BST *rotateLeft(BST *t1) {
    if (t1 == NULL || t1->right == NULL) return t1;
    BST *t2 = t1->right;
    t1->right = t2;
    t2->left = t1;
    return t2;
}
