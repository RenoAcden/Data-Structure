#include <stdio.h>
#include <stdlib.h>

// Define a node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a stack structure
typedef struct Stack {
    Node* top;
} Stack;

// Function prototypes
void push(Stack* stack);
void pop(Stack* stack);
void displayStack(Stack* stack);

int main() {
    Stack stack;
    stack.top = NULL; // Initialize the stack

    int choice;

    do {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(&stack);
                break;
            
            case 2:
                pop(&stack);
                break;

            case 3:
                displayStack(&stack);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. try again\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to push a value onto the stack
void push(Stack* stack) {
    int value;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter value to push: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a value from the stack
void pop(Stack* stack) {
    int dummy;
    printf("enter position to pop:");
    scanf("%d", &dummy); // Dummy input to pause and wait for the user to press Enter

    if (stack->top == NULL) {
        printf("Stack is empty! Cannot pop.\n");
        return;
    }
    Node* temp = stack->top;
    int value = temp->data;
    stack->top = stack->top->next;
    free(temp);
    printf("Popped %d from the stack.\n", value);
}

// Function to display the stack
void displayStack(Stack* stack) {
    Node* current = stack->top;
    if (current == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents:\n");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}