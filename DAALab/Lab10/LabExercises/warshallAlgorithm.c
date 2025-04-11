#include <stdio.h>

// Function to compute the transitive closure using Warshall's Algorithm
void warshallAlgorithm(int n, int graph[n][n]) {
    int i, j, k; // Loop variables declared outside the loops
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
}

// Function to print the adjacency matrix
void printGraph(int n, int graph[n][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 4; // Size of the graph
    int graph[4][4] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}
    };

    printf("Original Graph:\n");
    printGraph(n, graph);

    warshallAlgorithm(n, graph);

    printf("\nTransitive Closure:\n");
    printGraph(n, graph);
    printf("n    OpCount\n");
    return 0;
}
