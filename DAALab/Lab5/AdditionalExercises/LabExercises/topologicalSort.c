/*
Write a program to determine the Topological sort of a given graph using Depth First Technique
*/


#include <stdio.h>
#include <stdlib.h>

// A structure to represent an adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// A structure to represent an adjacency list
struct AdjList {
    struct AdjListNode *head;
};

// A structure to represent a graph. A graph is an array of adjacency lists.
struct Graph {
    int V;
    struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// A utility function to create a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
int i;
    for ( i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// A utility function to add an edge to a graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// A recursive function used by topologicalSort
void topologicalSortUtil(struct Graph* graph, int v, int visited[], int stack[], int* stackIndex) {
    visited[v] = 1;

    struct AdjListNode* node = graph->array[v].head;
    while (node != NULL) {
        if (!visited[node->dest])
            topologicalSortUtil(graph, node->dest, visited, stack, stackIndex);
        node = node->next;
    }

    stack[*stackIndex] = v;
    (*stackIndex)++;
}

// The function to do Topological Sort
void topologicalSort(struct Graph* graph) {
    int stack[graph->V];
    int stackIndex = 0;
    int visited[graph->V];
int i;
    for (i = 0; i < graph->V; i++)
        visited[i] = 0;

    for ( i = 0; i < graph->V; i++)
        if (!visited[i])
            topologicalSortUtil(graph, i, visited, stack, &stackIndex);

    printf("Topological Sort: ");
    for ( i = stackIndex - 1; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int V, E, u, v,i;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    struct Graph* graph = createGraph(V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (source destination) pairs:\n");
    for ( i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    topologicalSort(graph);

    return 0;
}
