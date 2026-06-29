#include <stdio.h>
#include <stdlib.h>
char s;
struct Node
{
    char data;
    struct Node *next;
};

struct Node *top = NULL;
void push(char value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;

    top = newNode;
}

// Pop
char pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return s;
    }

    struct Node *temp = top;
    char value = temp->data;

    top = top->next;

    free(temp);

    return value;
}

// Peek
char peek()
{
    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return s;
    }

    return top->data;
}
bool isValid(char* s) {
    top=NULL;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {

        if ((s[i] == ')' && peek() == '(') ||
            (s[i] == ']' && peek() == '[') ||
            (s[i] == '}' && peek() == '{')) {

            pop();
            printf("popped");
        }
        else {
            push(s[i]);
            printf("pushed");
        }
    }


    if (top == NULL)
        return true;

    return false;
}