#include <stdio.h>
#include <stdlib.h>

// Define node
struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Insert at position
struct Node* insert(struct Node* head, int data, int position) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // Insert at beginning
    if(position == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    for(int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Delete at position
struct Node* delete(struct Node* head, int position) {

    if(head == NULL) return head;

    struct Node* temp = head;

    // Delete first node
    if(position == 1) {
        head = temp->next;
        free(temp);
        return head;
    }

    for(int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);

    return head;
}

int main() {

    struct Node* head = NULL;

    // Manually creating initial list: 5 → 10 → 15
    head = insert(head, 5, 1);
    head = insert(head, 10, 2);
    head = insert(head, 15, 3);

    printf("Initial List: ");
    printList(head);

    int position, value;

    // Insert
    printf("Enter position to insert: ");
    scanf("%d", &position);

    printf("Enter value: ");
    scanf("%d", &value);

    head = insert(head, value, position);

    printf("After Insertion: ");
    printList(head);

    // Delete
    printf("Enter position to delete: ");
    scanf("%d", &position);

    head = delete(head, position);

    printf("Final List: ");
    printList(head);

    return 0;
}