// Written for COMP2521 sanitiser guide

#include <stdio.h>

#define N 8

void printPath(int pred[], int dest, int nV);

int main(void) {
    // Pred array like those output by DFS/BFS/Dijkstra's
    // Source vertex is 1
    int pred[N] = { 3, -1, 1, 4, 1, 2, 2, 2 };
    printPath(pred, 0, N);
}

// Prints the path (in reverse) from src to dest according to pred
void printPath(int pred[], int dest, int nV) {
    int v = dest;
    for (int i = 0; i < nV; i++) {
        printf("%d\n", v);
        v = pred[v];
    }
}
