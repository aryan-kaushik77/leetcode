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
void inorder(struct TreeNode* root,int *ans,int *index){
    if (root==NULL){
        return;
    }
    
    inorder(root->left,ans,index);
    ans[*index] = root->val;
    (*index)++;
    inorder(root->right,ans,index);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    if (root==NULL){
        *returnSize=0;
        return NULL;
    }
    
    int *ans=(int *)malloc(100 * sizeof(int));
    int index=0;
    inorder(root,ans,&index);
    *returnSize=index;
    return ans;
}