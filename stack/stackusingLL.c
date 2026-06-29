#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push
void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;

    top = newNode;
}

// Pop
int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node *temp = top;
    int value = temp->data;

    top = top->next;

    free(temp);

    return value;
}

// Peek
int peek()
{
    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return -1;
    }

    return top->data;
}

// Display
void display()
{
    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    struct Node *current = top;

    printf("Stack elements are:\n");

    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    printf("\nTop element: %d\n", peek());

    printf("Popped element: %d\n", pop());

    printf("\nAfter popping:\n");
    display();

    return 0;
}