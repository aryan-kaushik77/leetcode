#include <stdio.h>
int stack[30000];
int top = -1;

// Check if stack is empty
int isEmpty()
{
    return top == -1;
}

// Check if stack is full
int isFull()
{
    return top == 29999;
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
int sumSubarrayMins(int* arr, int arrSize) {
    int *prevSmaller = (int *)malloc(arrSize * sizeof(int));
    int *nextSmaller = (int *)malloc(arrSize * sizeof(int));
    // prev smaller
    top=-1;
    for(int i=0;i<arrSize;i++){
        while(top>=0 && arr[stack[top]]>=arr[i]){
            pop();
        }
        if(top==-1){
            prevSmaller[i]=-1;
        }
        else{
            prevSmaller[i]=stack[top];
        }
        push(i);
    }
    // next smaller
    top=-1;
    for(int i=arrSize-1;i>=0;i--){
        while(top>=0 && arr[stack[top]]>arr[i]){
            pop();
        }
        if(top==-1){
            nextSmaller[i]=arrSize;
        }
        else{
            nextSmaller[i]=stack[top];
        }
        push(i);
    }
    long long ans=0;
    for(int i=0;i<arrSize;i++){
        int leftMin=i-prevSmaller[i];
        int rightMin=nextSmaller[i]-i;
        ans=ans+(long long)arr[i]*leftMin*rightMin;
        // printf("%d->%d,%d\n",ans,leftMin,rightMin);
    }
    long long MOD = 1000000007;
    return ans%MOD;
}