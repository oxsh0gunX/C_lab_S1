#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL; 

void insertNode();
void deleteNode();
void searchNode();
void displayList();

int main() {
    int choice;

    printf("\n=== Singly Linked List Program ===\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertNode(); break;
            case 2: deleteNode(); break;
            case 3: searchNode(); break;
            case 4: displayList(); break;
            case 5: printf("\nThank you! Exiting...\n"); exit(0);
            default: printf("\nInvalid choice! Please try again.\n");
        }
    }
}


void insertNode() {
    int value;
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("\nMemory not available!\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    (*newNode).data = value;
    (*newNode).next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while ((*temp).next != NULL)
            temp = (*temp).next;
        (*temp).next = newNode;
    }

    printf("%d added to the list.\n", value);
}


void deleteNode() {
    int value;
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("\nList is empty! Nothing to delete.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    while (temp != NULL && (*temp).data != value) {
        prev = temp;
        temp = (*temp).next;
    }

    if (temp == NULL) {
        printf("%d not found in the list.\n", value);
        return;
    }

    if (prev == NULL)
        head = (*head).next;   // deleting first node
    else
        (*prev).next = (*temp).next;

    free(temp);
    printf("%d deleted from the list.\n", value);
}


void searchNode() {
    int value, pos = 1;
    struct Node *temp = head;

    if (head == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &value);

    while (temp != NULL) {
        if ((*temp).data == value) {
            printf("%d found at position %d.\n", value, pos);
            return;
        }
        temp = (*temp).next;
        pos++;
    }

    printf("%d not found in the list.\n", value);
}


void displayList() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    printf("\nCurrent List: ");
    while (temp != NULL) {
        printf("%d ", (*temp).data);
        temp = (*temp).next;
    }
    printf("\n");
}
