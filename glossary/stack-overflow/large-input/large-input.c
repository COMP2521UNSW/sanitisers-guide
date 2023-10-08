// Created for COMP2521 sanitiser guide

#include <stdio.h>

#define MOD 1000000000
#define N 1000000

int main(void) {
    int fib[N + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= N; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    printf("The last 9 digits of the millionth Fibonacci number: %d\n", fib[N]);
}
