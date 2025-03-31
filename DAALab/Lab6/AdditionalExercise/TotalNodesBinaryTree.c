/*Find total number of nodes in a binary tree and analyze its efficiency. Obtain the
experimental result of order of growth and plot the result.*/
#include <stdio.h>
#include <stdlib.h>
// Global operation count
int opcount = 0;
// Structure for a binary tree node
typedef struct Node {
int data;
struct Node *left, *right;
} Node;
// Function to create a new node
Node* createNode(int value) {
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->data = value;
newNode->left = newNode->right = NULL;
return newNode;
}
// Function to count total nodes in a binary tree
int countNodes(Node* root) {
opcount++; // Counting the number of function calls
if (root == NULL)
return 0;
return 1 + countNodes(root->left) + countNodes(root->right);
}
// Driver code
int main() {
// Creating a sample binary tree
Node* root = createNode(1);
root->left = createNode(2);
root->right = createNode(3);
root->left->left = createNode(4);
root->left->right = createNode(5);
root->right->left = createNode(6);
root->right->right = createNode(7);
// Counting nodes
int totalNodes = countNodes(root);
// Printing results
printf("Total number of nodes in the binary tree: %d\n", totalNodes);
printf("Operation Count (opcount): %d\n", opcount);
return 0;
}
