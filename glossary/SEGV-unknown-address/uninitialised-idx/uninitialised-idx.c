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
