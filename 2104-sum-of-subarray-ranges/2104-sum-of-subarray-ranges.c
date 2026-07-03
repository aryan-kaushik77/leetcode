#include <stdio.h>



int stack[1000];
int top = -1;

// Check if stack is empty
int isEmpty()
{
    return top == -1;
}

// Check if stack is full
int isFull()
{
    return top == 999;
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
long long subArrayRanges(int* nums, int numsSize) {
    int *prevGreater = (int *)malloc(numsSize * sizeof(int));
    int *nextGreater = (int *)malloc(numsSize * sizeof(int));
    int *prevSmaller = (int *)malloc(numsSize * sizeof(int));
    int *nextSmaller = (int *)malloc(numsSize * sizeof(int));

    //previous greatest
    top=-1;
    for(int i=0;i<numsSize;i++){
        while(top>=0 && nums[stack[top]]<=nums[i]){
            pop();
        }
        if(top==-1){
            prevGreater[i]=-1;
        }
        else{
            prevGreater[i]=stack[top];
        }
        push(i);
    }
    // next greatest
    top=-1;
    for(int i=numsSize-1;i>=0;i--){
        while(top>=0 && nums[stack[top]]<nums[i]){
            pop();
        }
        if(top==-1){
            nextGreater[i]=numsSize;
        }
        else{
            nextGreater[i]=stack[top];
        }
        push(i);
    }
    // next smallest
    top=-1;
    for(int i=numsSize-1;i>=0;i--){
        while(top>=0 && nums[stack[top]]>nums[i]){
            pop();
        }
        if(top==-1){
            nextSmaller[i]=numsSize;
        }
        else{
            nextSmaller[i]=stack[top];
        }
        push(i);
    }
    // prev smallest
    top=-1;
    for(int i=0;i<numsSize;i++){
        while(top>=0 && nums[stack[top]]>=nums[i]){
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
    long long ans = 0;

    for (int i = 0; i < numsSize; i++) {

        long long leftMax = i - prevGreater[i];
        long long rightMax = nextGreater[i] - i;

        long long leftMin = i - prevSmaller[i];
        long long rightMin = nextSmaller[i] - i;

        ans += (long long)nums[i] * leftMax * rightMax;
        ans -= (long long)nums[i] * leftMin * rightMin;
    }
    for(int i=0;i<numsSize;i++){
        printf("%d",prevSmaller[i]);
    }
    for(int i=0;i<numsSize;i++){
        printf("%d",nextSmaller[i]);
    }
    for(int i=0;i<numsSize;i++){
        printf("%d",prevGreater[i]);
    }
    for(int i=0;i<numsSize;i++){
        printf("%d",nextGreater[i]);
    }

    free(prevGreater);
    free(nextGreater);
    free(prevSmaller);
    free(nextSmaller);
    

    return ans;
}