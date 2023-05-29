[Back to heap-buffer-overflow](/glossary/heap-buffer-overflow)

# Index Out of Bounds

## The Code

Here is the code for this example ([source](index-oob.c)):

```C
// Accesses array out of bounds
// Created for COMP2521 sanitiser guide

#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(void) {
    int *array = malloc(N * sizeof(int));
    printf("%d\n", array[N]);

    free(array);
    return 0;
}

```

## The Error

Here is the error message:

![error message](error.png)

- The first thing we notice is that the error occurs on line 11, which is the line `printf("%d\n", array[N]);`.
- This is a READ error, so it is likely that the error comes from reading from `array`.
- The second stack trace confirms this, since it says the incorrectly accessed memory was allocated on line 10, which is `int *array = malloc(N * sizeof(int));`.
- We've tried to access 0 bytes to the right of `array`, so the index we've used is too large.

## The Problem

This code allocates an array of size 10, and then accesses index 10 of this array. This index is out of bounds for the array, since the valid indexes for an array of size 10 are 0..9, and so we get a `heap-buffer-overflow`.

## The Fix

The most simple fix is to put an if statement around the error line to check if the index we are using is out of bounds or not, and prevent the line from running if it is.

However, sometimes an index out of bounds suggests there is some logic error somewhere else in determining what index to use. Putting an if statement will prevent the error, but doesn't fix the root of the problem.
