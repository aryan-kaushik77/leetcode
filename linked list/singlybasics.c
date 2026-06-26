#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at beginning
void insertBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Delete a node by value
void deleteNode(struct Node **head, int key) {
    struct Node *temp = *head;
    struct Node *prev = NULL;

    // If head node contains key
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Search a value
int search(struct Node *head, int key) {
    int position = 1;

    while (head != NULL) {
        if (head->data == key)
            return position;

        head = head->next;
        position++;
    }

    return -1;
}

// Display list
void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    // Creation (inserting elements)
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    printf("Linked List: ");
    display(head);

    // Insert at beginning
    insertBeginning(&head, 5);
    printf("After inserting 5 at beginning: ");
    display(head);

    // Search
    int key = 20;
    int pos = search(head, key);

    if (pos != -1)
        printf("%d found at position %d\n", key, pos);
    else
        printf("%d not found\n", key);

    // Delete
    deleteNode(&head, 20);
    printf("After deleting 20: ");
    display(head);

    return 0;
}