#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure for the queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function prototypes
void enqueue(Queue* q);
void dequeue(Queue* q);
void display(Queue* q);

// Main function with menu-driven interface
int main() {
    Queue q; 
    q.front = q.rear = NULL;
    int choice;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");

        // Validate user input
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                enqueue(&q);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to add an element to the queue
void enqueue(Queue* q) {
    int data;
    printf("Enter value to enqueue: ");
    if (scanf("%d", &data) != 1) {
        printf("Invalid input. Enqueue operation failed.\n");
        // Clear input buffer
        while (getchar() != '\n');
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d enqueued to the queue.\n", data);
}

// Function to remove an element from the queue
void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    printf("%d dequeued from the queue.\n", data);
}

// Function to display the elements of the queue
void display(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}