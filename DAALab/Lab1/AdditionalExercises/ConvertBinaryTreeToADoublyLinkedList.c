/*3) Write a program to convert a Binary tree to a Doubly linked list*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to convert a Binary Tree to a Doubly Linked List (DLL)
void convertToDLL(struct Node* root, struct Node** head, struct Node** prev) {
    if (root == NULL) return;
    
    // Recursively convert left subtree
    convertToDLL(root->left, head, prev);
    
    if (*prev == NULL) {
        // This is the leftmost node, which becomes the head of the DLL
        *head = root;
    } else {
        // Adjust pointers
        (*prev)->right = root;
        root->left = *prev;
    }
    
    // Mark this node as previous before moving to the right subtree
    *prev = root;
    
    // Recursively convert right subtree
    convertToDLL(root->right, head, prev);
}

// Function to print the doubly linked list
void printDLL(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->right;
    }
    printf("\n");
}

int main() {
    // Constructing the binary tree
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(25);
    
    struct Node* head = NULL;
    struct Node* prev = NULL;
    
    // Convert Binary Tree to DLL
    convertToDLL(root, &head, &prev);
    
    // Print the resulting DLL
    printf("Doubly Linked List: ");
    printDLL(head);
    
    return 0;
}
