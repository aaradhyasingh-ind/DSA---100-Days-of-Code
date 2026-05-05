//write a program using singly linked list for insertion and deletion. 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at end
void insert(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Delete by value
void deleteNode(int value) {
    struct Node *temp = head, *prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
}

// Display
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// MAIN FUNCTION (You were missing this)
int main() {
    insert(10);
    insert(20);
    insert(30);

    printf("List: ");
    display();

    deleteNode(20);

    printf("After Deletion: ");
    display();

    return 0;
}