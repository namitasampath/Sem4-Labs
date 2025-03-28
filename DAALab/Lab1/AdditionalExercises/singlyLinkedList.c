/*Operations to Implement in Singly Linked List
Create the list by adding nodes at the front.

Insert a new node to the left of a node whose key is given.

Delete all occurrences of a given key.

Search for a node based on a key value.

Display the contents of the list.*/



#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 1. Insert a node at the front
void insertFront(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// 2. Insert a node to the left of a node with a given key
void insertLeft(Node** head, int key, int data) {
    if (*head == NULL) {
        printf("List is empty. Insertion not possible.\n");
        return;
    }

    if ((*head)->data == key) {
        insertFront(head, data);
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Key %d not found.\n", key);
    } else {
        Node* newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// 3. Delete all occurrences of a given key
void deleteKey(Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Deleting from head if matches
    while (*head != NULL && (*head)->data == key) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    // Deleting occurrences in the list
    Node* temp = *head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == key) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            free(toDelete);
        } else {
            temp = temp->next;
        }
    }
}

// 4. Search for a node with a given key
void search(Node* head, int key) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == key) {
            printf("Key %d found at position %d.\n", key, pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("Key %d not found.\n", key);
}

// 5. Display the contents of the list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Driver function
int main() {
    Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert left of a key\n");
        printf("3. Delete key\n");
        printf("4. Search key\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertFront(&head, data);
                break;
            case 2:
                printf("Enter key to insert left of: ");
                scanf("%d", &key);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertLeft(&head, key, data);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(&head, key);
                break;
            case 4:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(head, key);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
