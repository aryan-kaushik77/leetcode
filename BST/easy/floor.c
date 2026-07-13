int floorBST(struct Node* root, int key){

    if(root==NULL){
        return -1;
    }
    if(root->data==key){
        return root->data;
    }
    if(root->data>key){
        return floorBST(root->left,key);
    }
    else{
        int floorValue=floorBST(root->right,key);
        if(floorValue<=key && floorValue!=-1){
            return floorValue;
        }
        else{
            return root->data;
        }
    }

    
}