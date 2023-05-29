// Allocate insufficient memory for an array
// Created for COMP2521 sanitiser guide

#include <stdlib.h>

#define N 10

int main(void) {
    int *array = malloc(N);
    for (int i = 0; i < N; i++) {
        array[i] = i;
    }

    free(array);
    return 0;
}
