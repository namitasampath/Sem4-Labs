/*2. Write a program to implement Stack and Queue using circular doubly linked list in c*/


#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

Node* head = NULL;

Node* createNode(int data){
    Node* newNode = (Node*)malloc (sizeof(Node));
    newNode->data= data;
    newNode->next = newNode->prev= NULL;
    return newNode;
}

// insert at front used for stack push and queue dequeue
void insertFront(int data){
    Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        head->next = head->prev=head;
    }
    else{
        Node* last =head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

void insertRear(int data){
    Node* newNode = createNode(data);
    if (head==NULL){
        head = newNode;
        head->next = head->prev = head;
    }
    else{
        Node* last = head->prev;
        newNode->next= head;
        newNode->prev= last;
        last->next = newNode;
        head->prev=newNode;
        head=newNode;
    }
}

void deleteFront(){
    if(head == NULL){
        printf("Underflow. The list is empty");
        return;
    }
    Node* temp = head;
    if(head->next == head){
        head= NULL;
    }else{
        Node* last = head->prev;
        head = head->next;
        head->prev= last;
        last->next=head;
    }
    free(temp);
}
void deleteRear(){
    if (head==NULL){
        printf("Underflow. The list is empty");
        return;
    }
    Node* last = head->prev;
    if(head==last){
    free(head);
    head = NULL;
    }
    else{
        Node* secondLast = last->prev;
        secondLast->next = head;
        head->prev = secondLast;
        free(last);
    }
}

// Function to display the circular doubly linked list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    printf("Elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Stack operations
void push(int data) {
    insertFront(data);
    printf("Pushed %d onto Stack.\n", data);
}

void pop() {
    if (head == NULL) {
        printf("Stack Underflow! No elements to pop.\n");
    } else {
        printf("Popped %d from Stack.\n", head->data);
        deleteFront();
    }
}

// Queue operations
void enqueue(int data) {
    insertRear(data);
    printf("Enqueued %d into Queue.\n", data);
}

void dequeue() {
    if (head == NULL) {
        printf("Queue Underflow! No elements to dequeue.\n");
    } else {
        printf("Dequeued %d from Queue.\n", head->data);
        deleteFront();
    }
}

// Main function
int main() {
    int choice, data;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Enqueue (Queue)\n");
        printf("4. Dequeue (Queue)\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 4:
                dequeue();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
