// int minValue(struct Node *root) {
//     // code here
//     if(root==NULL){
//         return NULL;
//     }
//     if(root->left==NULL){
//         return root->data;
//     }
//     return minValue(root->left);
// }

// See we knew we need to go right to find max value so we ll go right and that call will return that root
// now we ll think how to return that root to previous call 


//  ##1 (same value to all calls)when we need to return the a call value to previous calls


// int front = -1;
// int rear = -1;
// struct TreeNode *queue[10001];

// // Check if queue is empty
// int isEmpty()
// {
//     return (front == -1 || front > rear);
// }

// // Check if queue is full
// int isFull()
// {
//     return rear == 10000;
// }

// // Insert an element
// void enqueue(struct TreeNode *value)
// {
//     if (isFull())
//     {
//         return;
//     }

//     if (front == -1)
//     {
//         front = 0;
//     }

//     rear = rear + 1;
//     queue[rear] = value;
// }

// // Remove an element
// struct TreeNode *dequeue()
// {
//     if (isEmpty())
//     {
//         return NULL;
//     }

//     struct TreeNode *value = queue[front];
//     front = front + 1;

//     if (front > rear)
//     {
//         front = -1;
//         rear = -1;
//     }


//     return value;
// }
// int maxDepth(struct TreeNode* root) {
//     front = -1;
//     rear = -1;

//     int depth = 0;

//     if (root == NULL)
//     {
//         return 0;
//     }

//     int **ans = (int **)malloc(10000 * sizeof(int *));

//     enqueue(root);

//     while (!isEmpty())
//     {
//         int levelSize = rear - front + 1;

//         ans[depth] = (int *)malloc(levelSize * sizeof(int));

//         for (int i = 0; i < levelSize; i++)
//         {
//             struct TreeNode *k = dequeue();

//             ans[depth][i] = k->val;

//             if (k->left)
//             {
//                 enqueue(k->left);
//             }

//             if (k->right)
//             {
//                 enqueue(k->right);
//             }
//         }

//         depth++;
//     }
//     return depth;
// }
// bool isBalanced(struct TreeNode* root) {
//     if (root == NULL)
//         return true;
//     if(abs(maxDepth(root->left)-maxDepth(root->right))>1){
//         return false;
//     }
//     if(!isBalanced(root->left)){
//         return false;
//     }
//     if(!isBalanced(root->right)){
//         return false;
//     }
//     return true;
    
// }
//  ##2 (true and false condition for previous calls) if we need to check true and false condition for childs we just use a call and check is the false is true or false and return that way


// int height(struct TreeNode* root){
//     if(root==NULL){
//         return 0;
//     }
//     int left=height(root->left);
//     int right=height(root->right);
//     if(left>right){
//         return 1+left;
//     }
//     else{
//         return 1+right;
//     }
// }
// int maxDepth(struct TreeNode* root) {
//    return height(root);
// }

// ##3 (returning a value to previous calls) similar to true and false where we use the the subcalls to find the value

// int floorBST(struct Node* root, int key){

//     if(root==NULL){
//         return -1;
//     }
//     if(root->data==key){
//         return root->data;
//     }
//     if(root->data>key){
//         return floorBST(root->left,key);
//     }
//     else{
//         int floorValue=floorBST(root->right,key);
//         if(floorValue<=key && floorValue!=-1){
//             return floorValue;
//         }
//         else{
//             return root->data;
//         }
//     }   
// }

// ##4 (to store it somewhere and then traverse)store the value in a variable and return that variable to previous calls



// struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
//     if (root == NULL) {
//         struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//         newNode->val = val;
//         newNode->left = NULL;
//         newNode->right = NULL;
//         return newNode;
//     }

//     if (val < root->val) {
//         root->left = insertIntoBST(root->left, val);
//     } 
//     else {
//         root->right = insertIntoBST(root->right, val);
//     }
    
//     return root;
// }

// ##5 return nodes in base cases and then use them


// __________________________________________________________
// mainly 3 types of recursion
// 1. return at one point and that value is same for all calls(floor and ceiling are the these type but in this we further explore the right and left child tofind the value)
// 2.use child calls to check value and return that value to previous calls
// 3. return nodes in them and use that node to manage the previous call