#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edges;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Function to create a graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to find the root of an element with path compression
int find(struct Subset subsets[], int vertex) {
    if (subsets[vertex].parent != vertex)
        subsets[vertex].parent = find(subsets, subsets[vertex].parent);
    return subsets[vertex].parent;
}

// Function to perform union of two sets
void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Comparator function for sorting edges based on their weight
int compareEdges(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

// Function to find the MST using Kruskal's algorithm
void kruskalMST(struct Graph* graph) {
    struct Edge result[graph->V - 1];
    int resultIndex = 0;

    // Sort edges by weight
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    struct Subset* subsets = (struct Subset*)malloc(graph->V * sizeof(struct Subset));
int v;
    for ( v = 0; v < graph->V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int edgeIndex = 0;
    while (resultIndex < graph->V - 1 && edgeIndex < graph->E) {
        struct Edge nextEdge = graph->edges[edgeIndex++];

        int rootSrc = find(subsets, nextEdge.src);
        int rootDest = find(subsets, nextEdge.dest);

        if (rootSrc != rootDest) {
            result[resultIndex++] = nextEdge;
            unionSets(subsets, rootSrc, rootDest);
        }
    }

    printf("Edges in the Minimum Cost Spanning Tree:\n");
    int i;
    for ( i = 0; i < resultIndex; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(subsets);
}

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    struct Graph* graph = createGraph(V, E);

    graph->edges[0] = (struct Edge){0, 1, 10};
    graph->edges[1] = (struct Edge){0, 2, 6};
    graph->edges[2] = (struct Edge){0, 3, 5};
    graph->edges[3] = (struct Edge){1, 3, 15};
    graph->edges[4] = (struct Edge){2, 3, 4};

    kruskalMST(graph);

    free(graph->edges);
    free(graph);
    return 0;
}
