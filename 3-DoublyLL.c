#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void traverseForward() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void traverseBackward() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp->next != NULL) temp = temp->next;
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    if (head != NULL) head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(int value, int pos) {
    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }
    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    if (temp->next == NULL) {
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next != NULL) temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (pos == 1) {
        deleteAtBeginning();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++) temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    free(temp);
}

int main() {
    int choice, value, pos;

    do {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Traverse Forward\n2. Traverse Backward\n3. Insert at Beginning\n4. Insert at End\n");
        printf("5. Insert at Position\n6. Delete at Beginning\n7. Delete at End\n8. Delete at Position\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverseForward();
                break;
            case 2:
                traverseBackward();
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 5:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertAtPosition(value, pos);
                break;
            case 6:
                deleteAtBeginning();
                break;
            case 7:
                deleteAtEnd();
                break;
            case 8:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 9);

    return 0;
}