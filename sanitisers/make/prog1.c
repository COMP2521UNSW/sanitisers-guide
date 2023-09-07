#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *a = malloc(100 * sizeof(int));
    if (a[5] != 0) {
        printf("%d\n", a[5]);
    }
}
