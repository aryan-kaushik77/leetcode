int minValue(struct Node *root) {
    // code here
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL){
        return root->data;
    }
    return minValue(root->left);
}