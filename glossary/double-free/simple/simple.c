// Created for COMP2521 UNSW sanitisers guide
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *zeroes = calloc(10, sizeof(int));
    free(zeroes);
    free(zeroes);
}
