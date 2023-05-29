// Accesses an array out of bounds
// Written for COMP2521 sanitiser guide

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

bool isSorted(int *arr, int size);

int main(void) {
    int *zeroes = calloc(N, sizeof(int));
    printf("Is sorted: %s", isSorted(zeroes, N) ? "yes" : "no");
}

bool isSorted(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}
