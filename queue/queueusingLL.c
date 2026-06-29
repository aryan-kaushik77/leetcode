#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue
void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = newNode;
        rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Dequeue
int dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    struct Node *temp = front;
    int value = temp->data;

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);

    return value;
}

// Peek
int peek()
{
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return -1;
    }

    return front->data;
}

// Display
void display()
{
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *current = front;

    printf("Queue elements are:\n");

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    printf("Front element: %d\n", peek());

    printf("Dequeued element: %d\n", dequeue());

    display();

    enqueue(40);

    display();

    return 0;
}