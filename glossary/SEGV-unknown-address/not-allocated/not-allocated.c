// Created for COMP2521 sanitisers guide
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *string;
    string = "Hello world!";
    printf("%s\n", string);
    free(string);
}
