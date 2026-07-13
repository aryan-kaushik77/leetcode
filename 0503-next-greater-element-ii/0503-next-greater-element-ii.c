/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int stack[20000];
int top = -1;

int isEmpty()
{
    return top == -1;
}

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int* nextGreaterElements(int* nums, int numsSize, int* returnSize)
{
    top = -1;
    *returnSize = numsSize;

    int *arr = (int *)malloc(numsSize * sizeof(int));

    // Create doubled array
    int doubleSize = 2 * numsSize;
    int *newNums = (int *)malloc(doubleSize * sizeof(int));

    for (int i = 0; i < doubleSize; i++)
    {
        newNums[i] = nums[i % numsSize];
    }

    // Initialize answer array
    for (int i = 0; i < numsSize; i++)
    {
        arr[i] = -1;
    }

    // Push index of last element
    push(doubleSize - 1);

    for (int i = doubleSize - 2; i >= 0; i--)
    {
        while (!isEmpty() && newNums[i] >= newNums[stack[top]])
        {
            pop();
        }

        // Store answer only for first half
        if (i < numsSize)
        {
            if (!isEmpty())
            {
                arr[i] = newNums[stack[top]];
            }
            else
            {
                arr[i] = -1;
            }
        }

        push(i);
    }

    free(newNums);

    return arr;
}