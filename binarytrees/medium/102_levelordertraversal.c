/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

#define MAX 2000

int front = -1;
int rear = -1;
struct TreeNode *queue[MAX];

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
void enqueue(struct TreeNode *value)
{
    if (isFull())
    {
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
struct TreeNode *dequeue()
{
    if (isEmpty())
    {
        return NULL;
    }

    struct TreeNode *value = queue[front];
    front = front + 1;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }

    return value;
}

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    front = -1;
    rear = -1;

    int depth = 0;

    if (root == NULL)
    {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int **ans = (int **)malloc(2000 * sizeof(int *));
    *returnColumnSizes = (int *)malloc(2000 * sizeof(int));

    enqueue(root);

    while (!isEmpty())
    {
        int levelSize = rear - front + 1;

        ans[depth] = (int *)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[depth] = levelSize;

        for (int i = 0; i < levelSize; i++)
        {
            struct TreeNode *k = dequeue();

            ans[depth][i] = k->val;

            if (k->left)
            {
                enqueue(k->left);
            }

            if (k->right)
            {
                enqueue(k->right);
            }
        }

        depth++;
    }

    *returnSize = depth;
    return ans;
}