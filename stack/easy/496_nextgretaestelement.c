/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int stack[10000];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == 9999;
}

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

int pop()
{
    if (isEmpty())
    {
        return -1;
    }
    int value = stack[top];
    top = top - 1;
    return value;
}
#define TABLE_SIZE 101

// Node structure
struct Node
{
    int key;
    int value;
    struct Node *next;
};
struct Node *table[TABLE_SIZE];

// Initialize hash table
void initialize()
{
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = NULL;
}

int hash(int key)
{
    if (key < 0)
        key = -key;

    return key % TABLE_SIZE;
}
void insert(int key, int value)
{
    int index = hash(key);

    struct Node *temp = table[index];

    // Update if key already exists
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            temp->value = value;
            return;
        }
        temp = temp->next;
    }

    // Create new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->key = key;
    newNode->value = value;
    newNode->next = table[index];

    table[index] = newNode;
}

// Search
struct Node *search(int key)
{
    int index = hash(key);

    struct Node *temp = table[index];

    while (temp != NULL)
    {
        if (temp->key == key)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {   
    top=-1;
    *returnSize=nums1Size;
    int *arr=(int *)malloc(nums1Size * sizeof(int));
    push(nums2[nums2Size-1]);
    insert(nums2[nums2Size-1],-1);
    for (int i=nums2Size-2;i>=0;i--){
        while(top!=-1 && nums2[i]>stack[top]){
            pop();
        }
        if(top==-1){
            insert(nums2[i],-1);
        }
        else{
            insert(nums2[i],stack[top]);
        }
        push(nums2[i]);
    }

    for(int i=0;i<nums1Size;i++){
        struct Node *temp=search(nums1[i]);
        arr[i]=temp->value;
    }
    return arr;
}