#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *a = calloc(100, sizeof(int));
    free(a);
    printf("%d\n", a[5]);
}
