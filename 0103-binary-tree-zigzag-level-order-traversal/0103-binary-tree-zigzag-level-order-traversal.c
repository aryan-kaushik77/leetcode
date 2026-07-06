

int front = -1;
int rear = -1;
struct TreeNode *queue[2000];

// Check if queue is empty
int isEmpty()
{
    return (front == -1 || front > rear);
}

// Check if queue is full
int isFull()
{
    return rear == 1999;
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
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    front=-1;
    rear=-1;
    int depth=0;
    
    if(root==NULL){
        *returnSize=0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    int **ans=(int **)malloc(2000 * sizeof(int *));
    *returnColumnSizes=(int *)malloc(2000*sizeof(int));
    enqueue(root);
    while(!isEmpty()){
        int levelsize=rear-front+1;
        ans[depth]=(int *)malloc(levelsize*(sizeof(int)));
        (*returnColumnSizes)[depth]=levelsize;
        if(depth%2==0){
            for(int i=0;i<levelsize;i++){
                struct TreeNode *k=dequeue();
                ans[depth][i]=k->val;
                if(k->left){
                    enqueue(k->left);
                }
                if(k->right){
                    enqueue(k->right);
                }
            }
            depth++;
        }
        else{
            for(int i=0;i<levelsize;i++){
                struct TreeNode *k=dequeue();
                ans[depth][levelsize-1-i]=k->val;
                if(k->left){
                    enqueue(k->left);
                }
                if(k->right){
                    enqueue(k->right);
                }
            }
            depth++;
        }

    }
    *returnSize=depth;
    return ans;

}