/*2) Write a program to create a 2-3 tree for a set of integers.

*/

#include <stdio.h>

#include <stdlib.h>

// Structure to define a 2-3 Tree Node

struct Node {

 int keys[2]; // Stores up to 2 keys

 struct Node* children[3]; // Stores up to 3 children

 int numKeys; // Number of keys in the node

 int isLeaf; // Flag to check if node is a leaf

};

// Function to create a new node

struct Node* createNode(int key) {

 struct Node* node = (struct Node*)malloc(sizeof(struct Node));

 node->keys[0] = key;

 node->numKeys = 1;

 node->isLeaf = 1;

 for (int i = 0; i < 3; i++)

 node->children[i] = NULL;

 return node;

}

// Function to insert a key into a 2-3 tree (basic insertion without splitting)

struct Node* insert(struct Node* root, int key) {

 if (root == NULL) {

 return createNode(key);

 }

 if (root->numKeys < 2) {

 root->keys[root->numKeys] = key;

 root->numKeys++;

 } else {

 printf("Node splitting required (not implemented in this basic version)\n");

 }

 return root;

}

// Function to print the 2-3 tree (in-order traversal)

void printTree(struct Node* root) {

 if (root == NULL)

 return;

 if (root->numKeys > 0)

 printTree(root->children[0]);

 printf("%d ", root->keys[0]);

 if (root->numKeys > 1)

 printTree(root->children[1]);

 if (root->numKeys > 1)

 printf("%d ", root->keys[1]);

 printTree(root->children[2]);

}

int main() {

 struct Node* root = NULL;

 int values[] = {10, 20, 30, 40, 50};

 int n = sizeof(values) / sizeof(values[0]);

 for (int i = 0; i < n; i++) {

 root = insert(root, values[i]);

 }

 printf("2-3 Tree (in-order traversal): ");

printTree(root);

 printf("\n");

 return 0;

}
