/* 
. A student management system should be developed by a software company. There
are certain dependent and independent modules that must be developed by K teams. The
unit testing and integration testing is done before the deployment of the product. Design
an algorithm using decrease and conquer technique such that it gives a schedule of tasks
in the order in which it must be executed.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adj[MAX][MAX]; // Adjacency matrix for dependencies
int inDegree[MAX]; // Stores in-degree of each module
int n; // Number of modules
// Function to perform topological sorting using Decrease and Conquer
void topologicalSort() {
 int stack[MAX], top = -1;
 int schedule[MAX], index = 0;
 // Push all independent modules (in-degree = 0) onto stack
 for (int i = 0; i < n; i++) {
 if (inDegree[i] == 0) {
 stack[++top] = i;
 }
 }
 while (top != -1) {
 int module = stack[top--];
 schedule[index++] = module;
 // Reduce in-degree of dependent modules
 for (int i = 0; i < n; i++) {
 if (adj[module][i] == 1) {
inDegree[i]--;
 if (inDegree[i] == 0) {
 stack[++top] = i;
 }
 }
 }
 }
 // Check for cycles (if all modules are not scheduled)
 if (index != n) {
 printf("Error: Cyclic dependency detected!\n");
 return;
 }
 // Print the execution schedule
 printf("Task Execution Order: ");
 for (int i = 0; i < index; i++) {
 printf("Module %d ", schedule[i]);
 }
 printf("\n");
}
int main() {
 int edges, u, v;
 printf("Enter number of modules: ");
 scanf("%d", &n);
 printf("Enter number of dependencies: ");
 scanf("%d", &edges);
 // Initialize adjacency matrix and in-degree array
 for (int i = 0; i < n; i++) {
 inDegree[i] = 0;
 for (int j = 0; j < n; j++) {
 adj[i][j] = 0;
 }
 }
 printf("Enter the dependencies (u v) where u -> v:\n");
 for (int i = 0; i < edges; i++) {
 scanf("%d %d", &u, &v);
 adj[u][v] = 1;
 inDegree[v]++;
 }
 topologicalSort();
 return 0;
}
