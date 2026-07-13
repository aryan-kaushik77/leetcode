int height(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    if(left>right){
        return 1+left;
    }
    else{
        return 1+right;
    }
}
int maxDepth(struct TreeNode* root) {
   return height(root);
}



// could also be done using level order traversing but not optimal