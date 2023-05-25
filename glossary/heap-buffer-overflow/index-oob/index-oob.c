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
