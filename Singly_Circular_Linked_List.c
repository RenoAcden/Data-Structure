#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Function prototypes
void createNode();
void insertFront();
void insertEnd();
void insertAtPosition();
void deleteFront();
void deleteEnd();
void deleteAtPosition();
void displayList();

// Main function
int main() {
    int choice;

    while (1) {
        // Display menu
        printf("\nCircular Linked List Menu:\n");
        printf("1. Create Node\n");
        printf("2. Insert at front\n");
        printf("3. Insert at end\n");
        printf("4. Insert at Position\n");
        printf("5. Delete Front\n");
        printf("6. Delete End\n");
        printf("7. Delete Middle\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createNode();
                break;
            case 2:
                insertFront();
                break;
            case 3:
                insertEnd();
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
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new node
void createNode() {
    int data;
    printf("Enter data for new node: ");
    scanf("%d", &data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = newNode;  // Points to itself

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to insert a node at the front of the list
void insertFront() {
    int data;
    printf("Enter data to insert at the front: ");
    scanf("%d", &data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

// Function to insert a node at the end of the list
void insertEnd() {
    int data;
    printf("Enter data to insert at the end: ");
    scanf("%d", &data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to insert a node at a specific position
void insertAtPosition() {
    int data, position;
    printf("Enter data to insert: ");
    scanf("%d", &data);
    printf("Enter position to insert at: ");
    scanf("%d", &position);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    if (head == NULL) {
        if (position == 1) {
            newNode->next = newNode;
            head = newNode;
        } else {
            printf("Invalid position.\n");
        }
        return;
    }

    if (position == 0) {
        insertFront();
        return;
    }

    struct Node* temp = head;
    for (int i = 0; i < position - 1; ++i) {
        temp = temp->next;
        if (temp == head) {
            printf("Position out of range.\n");
            free(newNode);
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete the node at the front of the list
void deleteFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    if (temp->next == head) {
        head = NULL;
        free(temp);
    } else {
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = head->next;
        head = head->next;
        free(temp);
    }
}

// Function to delete the node at the end of the list
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;
    if (temp->next == head) {
        free(temp);
        head = NULL;
    } else {
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
}

// Function to delete a node at a specific position
void deleteAtPosition() {
    int position;
    printf("Enter position to delete: ");
    scanf("%d", &position);

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;
    if (position == 0) {
        if (temp->next == head) {
            free(temp);
            head = NULL;
        } else {
            struct Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = head->next;
            head = head->next;
            free(temp);
        }
        return;
    }

    for (int i = 0; i < position; ++i) {
        prev = temp;
        temp = temp->next;
        if (temp == head) {
            printf("Position out of range.\n");
            return;
        }
    }

    prev->next = temp->next;
    free(temp);
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