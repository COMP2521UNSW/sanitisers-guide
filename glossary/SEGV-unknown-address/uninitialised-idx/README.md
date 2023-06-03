[Back to SEGV on unknown address](..)

# Uninitialised Index

## The Code

Here is the code for this example ([source](uninitialised-idx.c)):

```c
// Created for COMP2521 sanitiser guide

#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(void) {
    int array[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *printOrder = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        int printIdx = printOrder[0];
        printf("%d\n", array[printIdx]);
    }
    free(printOrder);
}

```

This code creates `array` containing 0..9, then mallocs an array `printOrder` of indexes that stores the order to print out `array`.

## The Error

Here is the error message:

![error message](error.png)

- We got a runtime error telling us that we tried to access index `-1094795586`
- The error occurs on line 13 - `printf("%d\n", array[printIdx]);`

## The Problem

A large negative number is usually a sign that we have an uninitialised value. In this case, when we allocated memory for the `printOrder` array we didn't initialise it.

When we use one of these uninitialised values as an index to `array`, we try access a large negative index, or in other words a memory address 4 million bytes before the start of `array`. This address is unknown to AddressSanitizer, so we get this error.

## The Fix

Make sure that the `printOrder` array is initialised. If we don't know what to put in there yet, we can initialise it to a default like `0` or invalid value  like `-1`.