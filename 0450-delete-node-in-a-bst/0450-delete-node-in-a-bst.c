/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *findLeftMax(struct TreeNode* root){
    if (root==NULL){
        return NULL;
    }
    if (root->right==NULL){
        return root;
    }
    return findLeftMax(root->right);
}
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    struct TreeNode* dummy=root;
    if(root==NULL){
        return NULL;

    }
    if (root->val>key){
        root->left=deleteNode(root->left,key);
    }
    else if(root->val<key){
        root->right=deleteNode(root->right,key);
    }
    else{
        if(root->right==NULL){
            return root->left;
        }
        else if(root->left==NULL){
            return root->right;
        }
        else{
            struct TreeNode* rightChild=root->right;
            struct TreeNode* rightinLeft=findLeftMax(root->left);
            rightinLeft->right=rightChild;
            return root->left;
        }
    }
    return dummy;
}