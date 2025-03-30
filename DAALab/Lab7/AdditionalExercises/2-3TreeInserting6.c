/*3) For the 2-3 tree created in exercise 2 above, insert an element 6.

*/

#include <stdio.h>

#include <stdlib.h>

// Structure for a 2-3 Tree Node

typedef struct Node {

 int keys[2]; // Stores up to 2 keys

 struct Node *child[3]; // Pointers to child nodes

 int numKeys; // Number of keys currently in the node

} Node;

// Function to create a new node

Node* createNode(int key) {

 Node* newNode = (Node*)malloc(sizeof(Node));

 newNode->keys[0] = key;

 newNode->keys[1] = -1; // Empty initially

 newNode->child[0] = newNode->child[1] = newNode->child[2] = NULL;

 newNode->numKeys = 1;

 return newNode;

}

// Function to insert into a 2-3 tree

Node* insert(Node* root, int key, Node** newChild, int* newKey) {

 if (root == NULL) {

 *newChild = NULL;

 *newKey = key;

 return NULL;

 }

 int pos;

 if (key < root->keys[0]) pos = 0;

 else if (root->numKeys == 1 || key < root->keys[1]) pos = 1;

else pos = 2;

 Node* splitChild;

 int splitKey;

 Node* temp = insert(root->child[pos], key, &splitChild, &splitKey);

 if (temp == NULL) {

 if (splitChild == NULL) return root;

 if (root->numKeys == 1) {

 if (pos == 0) {

 root->keys[1] = root->keys[0];

 root->keys[0] = splitKey;

 root->child[2] = root->child[1];

 root->child[1] = splitChild;

 } else {

 root->keys[1] = splitKey;

 root->child[2] = splitChild;

 }

 root->numKeys = 2;

 return root;

 }

 Node* newRoot = createNode(root->keys[1]);

 if (pos == 0) {

 newRoot->keys[0] = root->keys[0];

 newRoot->child[0] = createNode(root->keys[0]);

 newRoot->child[1] = createNode(root->keys[1]);

 } else if (pos == 1) {

 newRoot->keys[0] = splitKey;

 newRoot->child[0] = createNode(root->keys[0]);

 newRoot->child[1] = createNode(root->keys[1]);

 } else {

 newRoot->keys[0] = root->keys[1];

 newRoot->child[0] = createNode(root->keys[0]);

 newRoot->child[1] = createNode(splitKey);

 }

 return newRoot;

 }

return root;

}

// Function to insert and update root

Node* insertElement(Node* root, int key) {

 Node* newChild;

 int newKey;

 Node* newRoot = insert(root, key, &newChild, &newKey);

 if (newChild != NULL) {

 Node* finalRoot = createNode(newKey);

 finalRoot->child[0] = newRoot;

 finalRoot->child[1] = newChild;

 return finalRoot;

 }

 return newRoot;

}

// Function to print the tree (Inorder)

void inorder(Node* root) {

 if (root == NULL) return;

 inorder(root->child[0]);

 printf("%d ", root->keys[0]);

 inorder(root->child[1]);

 if (root->numKeys == 2) {

 printf("%d ", root->keys[1]);

 inorder(root->child[2]);

 }

}

// Driver function

int main() {

 Node* root = NULL;

 // Insert elements into the 2-3 tree

 root = insertElement(root, 10);

 root = insertElement(root, 20);

 root = insertElement(root, 30);

 root = insertElement(root, 40);

root = insertElement(root, 50);

 printf("Tree before inserting 6:\n");

 inorder(root);

 printf("\n");

 // Insert the required element (6)

 root = insertElement(root, 6);

 printf("Tree after inserting 6:\n");

 inorder(root);

 printf("\n");

 return 0;

}
