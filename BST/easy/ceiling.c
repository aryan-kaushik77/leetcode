int ceilingBST(struct Node* root, int key){

    if(root==NULL){
        return -1;
    }
    if(root->data==key){
        return root->data;
    }
    if(root->data<key){
        return ceilingBST(root->right,key);
    }
    else{
        int ceilValue=ceilingBST(root->left,key);
        if(ceilValue>=key && ceilValue!=-1){
            return ceilValue;
        }
        else{
            return root->data;
        }
    }
    return -1;
    
}