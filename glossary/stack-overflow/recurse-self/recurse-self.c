// Created for COMP2521 sanitiser guide

#include <stdio.h>
#include <stdlib.h>

int fib(int n);

int main(void) {
    for (int i = 0; i < 10; i++) {
        printf("fib(%d): %d\n", i, fib(i));
    }
}

int fib(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib(n) + fib(n - 1);
    }
}
