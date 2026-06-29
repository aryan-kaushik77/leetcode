#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Check if stack is empty
int isEmpty()
{
    return top == -1;
}

// Check if stack is full
int isFull()
{
    return top == MAX - 1;
}

// Push an element
void push(int value)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        return;
    }

    top = top + 1;
    stack[top] = value;
}

// Pop an element
int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return -1;
    }

    int value = stack[top];
    top = top - 1;
    return value;
}

// Peek at the top element
int peek()
{
    if (isEmpty())
    {
        printf("Stack is Empty\n");
        return -1;
    }

    return stack[top];
}

// Display the stack
void display()
{
    if (isEmpty())
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements are:\n");

    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
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

    push(40);

    printf("\nAfter pushing 40:\n");
    display();

    return 0;
}