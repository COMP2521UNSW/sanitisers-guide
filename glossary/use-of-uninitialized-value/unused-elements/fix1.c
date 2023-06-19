// Created for COMP2521 sanitiser guide

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUTS 10

int readInput(int *array);

int main(void) {
    int *inputs = malloc(MAX_INPUTS * sizeof(int));
    int numInputs = readInput(array);

    int evens = 0;
    for (int i = 0; i < numInputs; i++) {
        if (inputs[i] % 2 == 0) {
            evens++;
        }
    }
    printf("%d\n", evens);

    free(inputs);
}

int readInput(int *array) {
    // Read until MAX_INPUTS read or EOF
    int input;
    int count = 0;
    while (count < MAX_INPUTS && scanf("%d", &input) != EOF) {
        array[count++] = input;
    }

    return count;
}
