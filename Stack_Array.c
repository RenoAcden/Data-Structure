#include<stdio.h>
int top = -1, MAX;

void Push();
void Pop();
void Peek();
void Display();

int main() {
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &MAX);
    int stack[MAX],choice;
    do{
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                Push(stack);
                break;
            case 2:
                Pop(stack);
                break;
            case 3:
                Peek(stack);
                break;
            case 4:
                Display(stack);
                break;
            case 0:
                printf("\nExiting...\n\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 0);
}


void Push(int stack[]){
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter an integer to push: ");
        scanf("%d", &stack[++top]);
    }
}

void Pop(int stack[]){
    if (top == -1) {
        printf("Stack Underflow! Cannot pop an element.\n");
    } else {
        printf("Popped element: %d\n", stack[top--]);
    }
}

void Peek(int stack[]){
    if (top == -1) {
        printf("Stack is empty. Nothing to peek.\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

void Display(int stack[]){
    if (top == -1) {
        printf("Stack is empty. Nothing to display.\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
