#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void traverse() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = last->next;
    printf("Circular List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    if (last == NULL) {
        last = newNode;
        last->next = last;
        return;
    }
    newNode->next = last->next;
    last->next = newNode;
}

void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (last == NULL) {
        last = newNode;
        last->next = last;
        return;
    }
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
}

void deleteAtBeginning() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = last->next;
    if (last == temp) {
        free(temp);
        last = NULL;
        return;
    }
    last->next = temp->next;
    free(temp);
}

void deleteAtEnd() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = last->next;
    if (last == temp) {
        free(last);
        last = NULL;
        return;
    }
    while (temp->next != last) temp = temp->next;
    temp->next = last->next;
    free(last);
    last = temp;
}

int main() {
    int choice, value;

    do {
        printf("\n--- Circular Linked List ---\n");
        printf("1. Traverse\n2. Insert at Beginning\n3. Insert at End\n4. Delete at Beginning\n5. Delete at End\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse();
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}