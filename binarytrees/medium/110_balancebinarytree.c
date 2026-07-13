/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int front = -1;
int rear = -1;
struct TreeNode *queue[10001];

// Check if queue is empty
int isEmpty()
{
    return (front == -1 || front > rear);
}

// Check if queue is full
int isFull()
{
    return rear == 10000;
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
int maxDepth(struct TreeNode* root) {
    front = -1;
    rear = -1;

    int depth = 0;

    if (root == NULL)
    {
        return 0;
    }

    int **ans = (int **)malloc(10000 * sizeof(int *));

    enqueue(root);

    while (!isEmpty())
    {
        int levelSize = rear - front + 1;

        ans[depth] = (int *)malloc(levelSize * sizeof(int));

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
    return depth;
}
bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
        return true;
    if(abs(maxDepth(root->left)-maxDepth(root->right))>1){
        return false;
    }
    if(!isBalanced(root->left)){
        return false;
    }
    if(!isBalanced(root->right)){
        return false;
    }
    return true;
    
}