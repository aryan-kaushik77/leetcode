/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildtree(int *A,int left,int right){
    if(left>right){
        return NULL;
    }
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    int mid=left+(right-left)/2;
    root->val = A[mid];
    root->left=buildtree(A,left,mid-1);
    root->right=buildtree(A,mid+1,right);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    
    return buildtree(nums,0,numsSize-1);
}