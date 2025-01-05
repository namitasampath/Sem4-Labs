/*Write a program to construct a binary tree to support the following operations.
Assume no duplicate elements while constructing the tree.
1. Given a key, perform a search in the binary search tree. If the key is found then display "key found" else insert the key in the binary search tree.
2. Display using inorder, preorder, postorder traversal methods. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *lchild, *rchild;
};

struct Node* createNode(int key) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return createNode(key);
    if (key < root->key) {
        root->lchild = insert(root->lchild, key);
    } else if (key > root->key) {
        root->rchild = insert(root->rchild, key);
    }
    return root;
}

int search(struct Node* root, int key) {
    if (root == NULL) {
        return 0;
    }
    if (key == root->key) {
        return 1;
    }
    if (key < root->key) {
        return search(root->lchild, key);
    } else {
        return search(root->rchild, key);
    }
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->lchild);
        printf("%d ", root->key);
        inOrder(root->rchild);
    }
}

void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->lchild);
        postOrder(root->rchild);
        printf("%d ", root->key);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, key;

    while (1) {
        printf("\n1. Search key \n2. Insert key \n3. Display BST (InOrder) \n4. Display BST (PreOrder) \n5. Display BST (PostOrder) \n6. Exit \nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(root, key)) {
                    printf("Key found\n");
                } else {
                    printf("Key not found\n");
                }
                break;

            case 2:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                if (search(root, key)) {
                    printf("Key already exists.\n");
                } else {
                    root = insert(root, key);
                    printf("Key inserted.\n");
                }
                break;

            case 3:
                printf("BST (InOrder): ");
                inOrder(root);
                printf("\n");
                break;

            case 4:
                printf("BST (PreOrder): ");
                preOrder(root);
                printf("\n");
                break;

            case 5:
                printf("BST (PostOrder): ");
                postOrder(root);
                printf("\n");
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
