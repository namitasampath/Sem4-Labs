/*Write a program to implement the following graph representations and display
them.
i.	Adjacency list
ii.	Adjacency matrix
*/


#include <stdio.h>
#include <stdlib.h>

// Structure for an adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Structure for an adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Structure for a graph
struct Graph {
    int V;
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* createNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head NULL
    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Function to add an edge to an undirected graph (Adjacency List)
void addEdgeAdjList(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct AdjListNode* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to display the adjacency list representation of a graph
void displayAdjList(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct AdjListNode* pCrawl = graph->array[i].head;
        printf("\nVertex %d: ", i);
        while (pCrawl) {
            printf("-> %d ", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Function to create and display an adjacency matrix
void createAndDisplayAdjMatrix(int V, int edges[][2], int E) {
    int matrix[V][V];

    // Initialize matrix with 0s
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            matrix[i][j] = 0;
        }
    }

    // Fill the adjacency matrix
    for (int i = 0; i < E; i++) {
        int src = edges[i][0];
        int dest = edges[i][1];
        matrix[src][dest] = 1;
        matrix[dest][src] = 1; // For undirected graph
    }

    // Display the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V = 5; // Number of vertices
    int edges[][2] = {
        {0, 1},
        {0, 4},
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 3},
        {3, 4}
    };
    int E = sizeof(edges) / sizeof(edges[0]); // Number of edges

    // Create a graph for adjacency list representation
    struct Graph* graph = createGraph(V);
    for (int i = 0; i < E; i++) {
        addEdgeAdjList(graph, edges[i][0], edges[i][1]);
    }

    // Display the adjacency list
    printf("Adjacency List Representation:\n");
    displayAdjList(graph);

    // Create and display the adjacency matrix
    createAndDisplayAdjMatrix(V, edges, E);

    return 0;
}
