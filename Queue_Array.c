#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the queue

typedef struct {
    int front, rear, size;
    int array[MAX];
} Queue;

// Function prototypes
void enqueue(Queue *q);
void dequeue(Queue *q);
void displayQueue(Queue *q);

int main() {
    Queue q = {0, -1, 0};  // Initialize queue with default values

    int choice;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(&q);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void enqueue(Queue *q) {
    if (q->size == MAX) {  // Queue is full
        printf("Queue is full. Cannot enqueue\n");
        return;
    }

    int item;
    printf("Enter item to enqueue: ");
    scanf("%d", &item);

    q->rear = (q->rear + 1) % MAX;
    q->array[q->rear] = item;
    q->size++;
}

void dequeue(Queue *q) {
    if (q->size == 0) {  // Queue is empty
        printf("Queue is empty. Cannot dequeue\n");
        return;
    }

    int item = q->array[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;

    // Display the dequeued item and confirm
    printf("Deleted item: %d\n", item);
}

void displayQueue(Queue *q) {
    if (q->size == 0) {  // Queue is empty
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");
    for (int i = 0; i < q->size; i++) {
        printf("%d ", q->array[(q->front + i) % MAX]);
    }
    printf("\n");
}