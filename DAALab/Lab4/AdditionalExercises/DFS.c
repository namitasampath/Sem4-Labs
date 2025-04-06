//DFS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Maximum number of vertices
// Structure to represent a node in the adjacency list
typedef struct Node {
 int vertex;
 struct Node* next;
} Node;
// Structure to represent the graph
typedef struct Graph {
 int numVertices;
 Node* adjList[MAX];
 int visited[MAX]; // Array to track visited vertices
} Graph;
// Stack structure for DFS traversal
typedef struct Stack {
 int data[MAX];
 int top;
} Stack;
// Function to create a new node
Node* createNode(int v) {
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->vertex = v;
 newNode->next = NULL;
 return newNode;
}
// Function to create a graph
Graph* createGraph(int vertices) {
 Graph* graph = (Graph*)malloc(sizeof(Graph));
 graph->numVertices = vertices;
 for (int i = 0; i < vertices; i++) {
 graph->adjList[i] = NULL;
 graph->visited[i] = 0;
 }
 return graph;
}
// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
 Node* newNode = createNode(dest);
 newNode->next = graph->adjList[src];
 graph->adjList[src] = newNode;
 // Uncomment for undirected graph
 // newNode = createNode(src);
 // newNode->next = graph->adjList[dest];
 // graph->adjList[dest] = newNode;
}
// Function to initialize a stack
void initStack(Stack* stack) {
 stack->top = -1;
}
// Function to check if the stack is empty
int isEmpty(Stack* stack) {
 return stack->top == -1;
}
// Function to push an element onto the stack
void push(Stack* stack, int value) {
 stack->data[++stack->top] = value;
}
// Function to pop an element from the stack
int pop(Stack* stack) {
 return stack->data[stack->top--];
}
// Depth-First Search (DFS) Function
void DFS(Graph* graph, int startVertex) {
 Stack stack;
 initStack(&stack);
 printf("Push Order: ");
 push(&stack, startVertex);
 graph->visited[startVertex] = 1;
 while (!isEmpty(&stack)) {
 int vertex = pop(&stack);
 printf("%d ", vertex);
 Node* temp = graph->adjList[vertex];
 while (temp) {
 int adjVertex = temp->vertex;
 if (!graph->visited[adjVertex]) {
 push(&stack, adjVertex);
 graph->visited[adjVertex] = 1;
 }
 temp = temp->next;
 }
 }
}
// Function to reset visited array for multiple DFS calls
void resetVisited(Graph* graph) {
 for (int i = 0; i < graph->numVertices; i++) {
 graph->visited[i] = 0;
 }
}
// Main function
int main() {
 int vertices, edges, src, dest, startVertex;
 printf("Enter number of vertices: ");
 scanf("%d", &vertices);
 Graph* graph = createGraph(vertices);
 printf("Enter number of edges: ");
 scanf("%d", &edges);
 printf("Enter edges (source destination):\n");
 for (int i = 0; i < edges; i++) {
 scanf("%d %d", &src, &dest);
 addEdge(graph, src, dest); }
 printf("Enter start vertex for DFS: ");
 scanf("%d", &startVertex);
 printf("\nDepth-First Search (DFS) Traversal:\n");
 DFS(graph, startVertex);
 printf("\n");
 return 0;
}
