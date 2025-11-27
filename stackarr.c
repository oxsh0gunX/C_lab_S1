#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void push() {
    int value;
    if (top == SIZE - 1) {
        printf("Stack Overflow! Cannot push more items.\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! Nothing to pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty. Nothing to peek.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom): ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    printf("Simple Stack Implementation using Array in C\n");

    while (1) {
        printf("\n------ MENU ------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (View Top Element)\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please enter 1-5.\n");
        }
    }

    return 0;
}
