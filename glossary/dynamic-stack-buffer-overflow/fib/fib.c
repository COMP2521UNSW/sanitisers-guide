// Written for COMP2521 sanitisers guide

#include <stdio.h>

int fib(int n);

int main(void) {
    for (int i = 0; i < 10; i++) {
        printf("%d\n", fib(i));
    }
}

// Calculates the nth Fibonacci number iteratively
int fib(int n) {
    // fib(0) = 0, fib(1) = 1
    if (n <= 1) return n;

    int results[n];
    results[0] = 0;
    results[1] = 1;

    for (int i = 2; i <= n; i++) {
        results[i] = results[i - 2] + results[i - 1];
    }

    return results[n];
}
