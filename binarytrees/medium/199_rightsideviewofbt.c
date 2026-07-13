/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

#define MAX 100

int front = -1;
int rear = -1;
struct TreeNode *queue[100];

int isEmpty()
{
    return (front == -1 || front > rear);
}

int isFull()
{
    return rear == 99;
}

void enqueue(struct TreeNode *value)
{
    if (isFull())
        return;

    if (front == -1)
        front = 0;

    queue[++rear] = value;
}

struct TreeNode *dequeue()
{
    if (isEmpty())
        return NULL;

    struct TreeNode *value = queue[front++];

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }

    return value;
}

int *rightSideView(struct TreeNode *root, int *returnSize)
{
    front = rear = -1;

    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    int *ans = (int *)malloc(2000 * sizeof(int));
    int depth = 0;

    enqueue(root);

    while (!isEmpty())
    {
        int levelSize = rear - front + 1;

        for (int i = 0; i < levelSize; i++)
        {
            struct TreeNode *k = dequeue();

            // Store the rightmost node of this level
            if (i == levelSize - 1)
                ans[depth++] = k->val;

            if (k->left)
                enqueue(k->left);

            if (k->right)
                enqueue(k->right);
        }
    }

    *returnSize = depth;
    return ans;
}