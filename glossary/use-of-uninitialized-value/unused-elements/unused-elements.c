// Created for COMP2521 sanitiser guide

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUTS 10

int *readInput(void);

int main(void) {
    int *inputs = readInput();

    int sum = 0;
    for (int i = 0; i < MAX_INPUTS; i++) {
        sum += inputs[i];
    }
    printf("%d\n", sum);

    free(inputs);
}

int *readInput(void) {
    int *inputs = malloc(MAX_INPUTS * sizeof(int));

    // Read until MAX_INPUTS read or EOF
    int input;
    int count = 0;
    while (count < MAX_INPUTS && scanf("%d", &input) != EOF) {
        inputs[count++] = input;
    }

    return inputs;
}