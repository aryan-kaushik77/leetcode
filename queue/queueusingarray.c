#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

// Check if queue is empty
int isEmpty()
{
    return (front == -1 || front > rear);
}

// Check if queue is full
int isFull()
{
    return rear == MAX - 1;
}

// Insert an element
void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear = rear + 1;
    queue[rear] = value;
}

// Remove an element
int dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int value = queue[front];
    front = front + 1;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }

    return value;
}

// Get front element
int peek()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return -1;
    }

    return queue[front];
}

// Display queue
void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements are:\n");

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
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