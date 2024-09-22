#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *pre, *next;
};

struct node *head = NULL;

// Function prototypes
void createList();
void insertFront();
void insertEnd();
void insertMiddle();
void deleteFront();
void deleteEnd();
void deleteMiddle();
void display();


int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create List\n");
        printf("2. Insert at Front\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Middle\n");
        printf("5. Delete from Front\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Middle\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                insertFront();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                insertMiddle();
                break;
            case 5:
                deleteFront();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                deleteMiddle();
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0); // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
// Create a list with multiple nodes
void createList() {
    int n, element, i;
    struct node *newNode, *temp;

    // Clear the list before creating a new one
    while (head != NULL) {
        deleteFront();
    }
    
    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes\n");
        return;
    }

    for (i = 0; i < n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        newNode->data = element;
        newNode->next = NULL;
        newNode->pre = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->pre = temp;
        }
    }
}
// Insertion at the front
void insertFront() {
    int element;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);
    newNode->data = element;
    newNode->pre = NULL;
    newNode->next = head;
    if (head != NULL)
        head->pre = newNode;
    head = newNode;
}

// Insertion at the end
void insertEnd() {
    int element;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);
    newNode->data = element;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->pre = NULL;
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->pre = temp;
}

// Insertion at a specified position
void insertMiddle() {
    int element, position, i = 1;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);
    printf("Enter the position to insert: ");
    scanf("%d", &position);

    if (position == 1) {
        insertFront();
        return;
    }

    struct node *temp = head;
    for (i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->data = element;
    newNode->next = temp->next;
    newNode->pre = temp;
    if (temp->next != NULL)
        temp->next->pre = newNode;
    temp->next = newNode;
}

// Deletion from the front
void deleteFront() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    if (head != NULL)
        head->pre = NULL;
    free(temp);
}

// Deletion from the end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    if (head->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;
    temp->pre->next = NULL;
    free(temp);
}

// Deletion from the middle
void deleteMiddle() {
    int position, i = 1;
    printf("Enter the position to delete: ");
    scanf("%d", &position);

    if (position == 1) {
        deleteFront();
        return;
    }

    struct node *temp = head;
    for (i = 1; i < position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    if (temp->pre != NULL)
        temp->pre->next = temp->next;
    if (temp->next != NULL)
        temp->next->pre = temp->pre;
    if (temp == head) // If deleting the head node
        head = temp->next;
    free(temp);
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}