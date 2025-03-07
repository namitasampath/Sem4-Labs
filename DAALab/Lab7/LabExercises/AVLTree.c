#include <stdio.h>
#include <stdlib.h>

// Structure of a node
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Function to get the height of the tree
int height(Node* n) {
    return n ? n->height : 0;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node
Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Right rotate
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get the balance factor of a node
int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Iterative insertion
Node* insert(Node* node, int key) {
    Node* stack[100];  // Stack to store the path
    int top = -1;
    Node* curr = node;
    Node* newNode = createNode(key);

    if (!node) return newNode;

    while (curr) {
        stack[++top] = curr;
        if (key < curr->key) {
            if (!curr->left) {
                curr->left = newNode;
                break;
            }
            curr = curr->left;
        } else if (key > curr->key) {
            if (!curr->right) {
                curr->right = newNode;
                break;
            }
            curr = curr->right;
        } else {
            return node;
        }
    }

    while (top >= 0) {
        Node* n = stack[top--];
        n->height = max(height(n->left), height(n->right)) + 1;
        int balance = getBalance(n);

        // Left Left Case
        if (balance > 1 && key < n->left->key) {
            if (top >= 0) {
                Node* parent = stack[top];
                if (parent->left == n) {
                    parent->left = rightRotate(n);
                } else {
                    parent->right = rightRotate(n);
                }
            } else {
                node = rightRotate(n);
            }
        }
        // Right Right Case
        else if (balance < -1 && key > n->right->key) {
            if (top >= 0) {
                Node* parent = stack[top];
                if (parent->left == n) {
                    parent->left = leftRotate(n);
                } else {
                    parent->right = leftRotate(n);
                }
            } else {
                node = leftRotate(n);
            }
        }
        // Left Right Case
        else if (balance > 1 && key > n->left->key) {
            n->left = leftRotate(n->left);
            if (top >= 0) {
                Node* parent = stack[top];
                if (parent->left == n) {
                    parent->left = rightRotate(n);
                } else {
                    parent->right = rightRotate(n);
                }
            } else {
                node = rightRotate(n);
            }
        }
        // Right Left Case
        else if (balance < -1 && key < n->right->key) {
            n->right = rightRotate(n->right);
            if (top >= 0) {
                Node* parent = stack[top];
                if (parent->left == n) {
                    parent->left = leftRotate(n);
                } else {
                    parent->right = leftRotate(n);
                }
            } else {
                node = leftRotate(n);
            }
        }
    }

    return node;
}

// Function to print the tree in inorder
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int keys[] = {10, 20, 30, 40, 50, 25};
int i;
    for ( i = 0; i < 6; i++) {
        root = insert(root, keys[i]);
    }

    printf("Inorder traversal of the constructed AVL tree is: ");
    inorder(root);

    return 0;
}
