

#define MAX 100000

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

char* removeKdigits(char* num, int k) {
    top = -1;
    int temp = k;
    int n = strlen(num);

    if (n == k) {
        char *ans = (char *)malloc(2);
        ans[0] = '0';
        ans[1] = '\0';
        return ans;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = num[i] - '0';
    }

    push(arr[0]);

    for (int i = 1; i < n; i++) {

        while (!isEmpty() && k > 0 && peek() > arr[i]) {
            pop();
            k--;
        }

        push(arr[i]);
    }

    // Remove remaining digits from the end
    while (k > 0) {
        pop();
        k--;
    }

    int size = top + 1;

    // Skip leading zeros
    int index = 0;
    while (index < size && stack[index] == 0) {
        index++;
    }

    // If all digits are removed or all are zero
    if (index == size) {
        char *ans = (char *)malloc(2);
        ans[0] = '0';
        ans[1] = '\0';
        return ans;
    }

    char *str = (char *)malloc((size - index + 1) * sizeof(char));

    int j = 0;
    for (int i = index; i < size; i++) {
        str[j++] = stack[i] + '0';
    }
    str[j] = '\0';

    return str;
}