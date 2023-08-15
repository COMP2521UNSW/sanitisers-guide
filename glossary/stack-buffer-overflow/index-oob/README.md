[Back to stack-buffer-overflow](..)

# Index Out of Bounds (Overflow)

## The Code

Here is the code for this example ([source](index-oob.c)):

```c
// Written for COMP2521 sanitiser guide

#include <stdbool.h>
#include <stdio.h>

bool isSorted(int arr[], int size);

int main(void) {
    char *result;
    int N = 10;
    
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    result = isSorted(array, N) ? "yes" : "no";
    printf("Is sorted: %s\n", result);
    
    int random[] = { 4, 3, 1, 7, 5, 6, 10, 9, 8, 2 };
    result = isSorted(random, N) ? "yes" : "no";
    printf("Is sorted: %s\n", result);
}

bool isSorted(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

```

This program checks if two arrays are sorted using the `isSorted()` function.

`isSorted()` loops through every pair in the array and checks if there is a pair where the first number is greater than the second number. If so, then the array is not sorted, but if no pairs meet that condition then the array is sorted.

## The Error

Here is the error message:

![error message](error.png)

- The first thing we notice is that the error occurs on line 23 in `isSorted()`, which is the line `if (arr[i] > arr[i + 1]) {`. This means one of these accesses of `arr` is incorrect.
- `isSorted()` was called on line 13 of `main()`, which is where we call it on `array`.
- The memory address we tried to access overflows the memory for `array` - specifically, it overflows by 0 bytes

## The Problem

For some reason, either `arr[i]` or `arr[i + 1]` is trying to access index 10. Since `i` loops until `i < size`, we know that `i` can be at most 9. So `arr[i]` will always be fine, but if `i = 9` then `arr[i + 1]` will access `arr[10]` which is out of bounds.

At a higher level, remember the function considers each pair in the array (i.e. `arr[0]` and `arr[1]`, `arr[1]` and `arr[2]` etc). The loop counter `i` represents the index of the first item in the pair, but there is no pair starting at `size - 1`.

## The Fix

We need to fix our loop condition so that `i < size - 1`. This makes sure that `i + 1 < size` so `arr[i + 1]` will not cause issues.
