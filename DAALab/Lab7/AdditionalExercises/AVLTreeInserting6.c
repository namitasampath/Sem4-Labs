/*Write a program to create the AVL tree by iterative insertion.
For the AVL tree created in exercise 1 above, insert an element 6
*/
#include <stdio.h>
#include <stdlib.h>
// Structure for AVL Tree Node
struct Node {
int key;
struct Node *left, *right;
int height;
};
// Function to get the height of the tree
int height(struct Node *N) {
if (N == NULL)
return 0;
return N->height;
}
// Function to create a new node
struct Node* createNode(int key) {
struct Node* node = (struct Node*)malloc(sizeof(struct Node));
node->key = key;
node->left = node->right = NULL;
node->height = 1;
return node;
}
// Function to get the balance factor of a node
int getBalance(struct Node *N) {
if (N == NULL)
return 0;
return height(N->left) - height(N->right);
}
// Right rotate function
struct Node *rightRotate(struct Node *y) {
struct Node *x = y->left;
struct Node *T2 = x->right;
x->right = y;
y->left = T2;
y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
return x;
}
// Left rotate function
struct Node *leftRotate(struct Node *x) {
struct Node *y = x->right;
struct Node *T2 = y->left;
y->left = x;
x->right = T2;
x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
return y;
}
// Iterative function to insert a node in AVL tree
struct Node* insert(struct Node *root, int key) {
struct Node *parent = NULL, *current = root;
struct Node *newNode = createNode(key);
if (root == NULL)
return newNode;
while (current != NULL) {
parent = current;
if (key < current->key)
current = current->left;
else
current = current->right;
}
if (key < parent->key)
parent->left = newNode;
else
parent->right = newNode;
// Rebalance the tree
int balance = getBalance(root);
// Left Heavy
if (balance > 1 && key < root->left->key)
return rightRotate(root);
// Right Heavy
if (balance < -1 && key > root->right->key)
return leftRotate(root);
// Left-Right Case
if (balance > 1 && key > root->left->key) {
root->left = leftRotate(root->left);
return rightRotate(root);
}
// Right-Left Case
if (balance < -1 && key < root->right->key) {
root->right = rightRotate(root->right);
return leftRotate(root);
}
return root;
}
// Function to print the tree in-order
void inOrder(struct Node *root) {
if (root != NULL) {
inOrder(root->left);
printf("%d ", root->key);
inOrder(root->right);
}
}
int main() {
struct Node *root = NULL;
int values[] = {10, 20, 30, 40, 50, 25, 6}; // Inserted element 6
int n = sizeof(values) / sizeof(values[0]);
for (int i = 0; i < n; i++) {
root = insert(root, values[i]);
}
printf("In-order traversal of AVL tree: ");
inOrder(root);
printf("\n");
return 0;}
