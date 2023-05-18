// Accesses index out of bounds of string
// Written for COMP2521 Sanitiser Guide

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

void foo(void) {
	char *s = malloc(N);
	strcpy(s, "012345678");
	for (int i = 0; i <= N; i++) {
		printf("%c", s[i]);
	}
	printf("\n");
}

int main(void) {
	// Call foo
	foo();
    return 0;
}
