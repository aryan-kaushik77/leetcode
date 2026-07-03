/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>


int stack[10000];
int top = -1;

// Check if stack is empty
int isEmpty()
{
    return top == -1;
}

// Check if stack is full
int isFull()
{
    return top == 9999;
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
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    top=-1;
    for (int i=0;i<asteroidsSize;i++){
        int alive=1;
        while(top>=0 && stack[top]>0 && asteroids[i]<0){
            if(stack[top]==-asteroids[i]){
                pop();
                alive=0;
                break;
            }
            else if(stack[top]>-asteroids[i]){
                alive=0;
                break;
            }
            else{
                pop();
            }
        }
        if (alive==1){
            push(asteroids[i]);
        }

    }
    *returnSize = top + 1;

    int *ans = (int *)malloc((*returnSize) * sizeof(int));

    for (int i = 0; i <= top; i++) {
        ans[i] = stack[i];
    }

    return ans;
}