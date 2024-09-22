#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly circular linked list
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Declare the head pointer globally
struct Node *head = NULL;

// Function prototypes
void createNode();
void insertAtFront();
void insertAtEnd();
void insertAtPosition();
void deleteFront();
void deleteEnd();
void deleteAtPosition();
void displayList();

int main() {
    int choice;

    while (1) {
        printf("\nDoubly Circular Linked List Menu\n");
        printf("1. Create list\n");
        printf("2. Insert at front\n");
        printf("3. Insert at end\n");
        printf("4. Insert at a specific position\n");
        printf("5. Delete the front node\n");
        printf("6. Delete the end node\n");
        printf("7. Delete a node at a specific position\n");
        printf("8. Display list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createNode();
                break;
            case 2:
                insertAtFront();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                insertAtPosition();
                break;
            case 5:
                deleteFront();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                deleteAtPosition();
                break;
            case 8:
                displayList();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    }
}

// Function to create a new node (initialize list with one node)
void createNode() {
    int data;
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Set the node's data and initialize pointers
    printf("Enter the data for the node: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;

    // Set head to point to the new node
    head = newNode;
}

// Function to insert a node at the front (1st position) of the doubly circular linked list
void insertAtFront() {
    if (head == NULL) {
        printf("List is empty. Create the list first.\n");
        return;
    }

    int data;
    printf("Enter data to insert at front: ");
    scanf("%d", &data);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;

    if (head->next == head) { // Only one node in the list
        newNode->next = head;
        newNode->prev = head;
        head->next = newNode;
        head->prev = newNode;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }

    head = newNode;
}

// Function to insert a node at the end of the doubly circular linked list
void insertAtEnd() {
    if (head == NULL) {
        printf("List is empty. Create the list first.\n");
        return;
    }

    int data;
    printf("Enter data to insert at end: ");
    scanf("%d", &data);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;

    if (head->next == head) { // Only one node in the list
        newNode->next = head;
        newNode->prev = head;
        head->next = newNode;
        head->prev = newNode;
    } else {
        struct Node *last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }
}

// Function to insert a node at a specific position in the doubly circular linked list
void insertAtPosition() {
    if (head == NULL) {
        printf("List is empty. Create the list first.\n");
        return;
    }

    int data, position;
    printf("Enter data to insert: ");
    scanf("%d", &data);
    printf("Enter the position to insert: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Position should be 1 or greater.\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;

    if (position == 1) {
        insertAtFront();
        return;
    }

    struct Node *temp = head;
    int count = 1;

    while (count < position - 1) {
        temp = temp->next;
        if (temp == head) {
            printf("Position out of range.\n");
            free(newNode);
            return;
        }
        count++;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    if (temp == head->prev) {
        head->prev = newNode;
    }
}

// Function to delete the node at the front of the doubly circular linked list
void deleteFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    if (temp->next == temp) { // Only one node in the list
        free(temp);
        head = NULL;
    } else {
        struct Node *last = temp->prev;
        head = temp->next;
        head->prev = last;
        last->next = head;
        free(temp);
    }
}

// Function to delete the node at the end of the doubly circular linked list
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *last = head->prev;

    if (last == head) { // Only one node in the list
        free(last);
        head = NULL;
    } else {
        struct Node *secondLast = last->prev;
        secondLast->next = head;
        head->prev = secondLast;
        free(last);
    }
}

// Function to delete the node at a specific position in the doubly circular linked list
void deleteAtPosition() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    int position;
    printf("Enter position to delete: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Position should be 1 or greater.\n");
        return;
    }

    struct Node *temp = head;
    int count = 1;

    if (position == 1) {
        deleteFront();
        return;
    }

    while (count < position) {
        temp = temp->next;
        if (temp == head) {
            printf("Position out of range.\n");
            return;
        }
        count++;
    }

    if (temp->next == temp) { // Only one node in the list
        free(temp);
        head = NULL;
    } else {
        struct Node *prevNode = temp->prev;
        struct Node *nextNode = temp->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        if (temp == head) {
            head = nextNode;
        }
        free(temp);
    }
}

// Function to display the list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}