// #include <limits.h>

long long prev;

bool inorder(struct TreeNode* root) {
    if (root == NULL)
        return true;

    if (!inorder(root->left))
        return false;

    if (root->val <= prev)
        return false;

    prev = root->val;

    if (!inorder(root->right))
        return false;

    return true;
}

bool isValidBST(struct TreeNode* root) {
    prev = LLONG_MIN;  
    return inorder(root);
}