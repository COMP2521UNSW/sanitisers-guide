// Written for COMP2521 sanitiser guide

#include <stdbool.h>
#include <stdio.h>

bool isSorted(int arr[], int size);

int main(void) {
    char *result;
    int N = 10;

    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    result = isSorted(array, N) ? "yes" : "no";
    printf("Is sorted: %s\n", result);

    int random[] = { 4, 3, 1, 7, 5, 6, 10, 9, 8, 2 };
    result = isSorted(random, N) ? "yes" : "no";
    printf("Is sorted: %s\n", result);
}

bool isSorted(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}
