[Back to heap-buffer-overflow](..)

# Insufficient Memory for Struct

## The Code

Here is the code for this example ([source](insufficient-allocation.c)):

```c
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

```

## The Error

Here is the error message:

![error message](error.png)

- The first thing we notice is that the error occurs on line 14, which is the line `n->next = NULL;`.
- The memory being incorrectly accessed was allocated on line 12, which is `struct node *n = malloc(sizeof(n));`.
- The memory allocated to `n` was only 8 bytes.

## The Problem

Here we've defined a linked list node struct `struct node`. In the main function, we've allocated memory for a new node, however we only allocated `sizeof(n)` bytes. But `n` is of type `struct node *`, so this is equivalent to `sizeof(struct node *)`. All pointers are 8 bytes in size.

In this case our struct contains an integer (4 bytes) and a pointer to the next node (8 bytes), so we would need 12 bytes of memory for this struct. But since we only allocate enough space for a pointer (8 bytes), we haven't allocated enough memory.

## The Fix

Rather than `sizeof(n)`, we should use `sizeof(*n)` (i.e. the size of the memory that `n` points to) or equivalently `sizeof(struct node)`.
