/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL)
        return false;

    if (p->val != q->val)
        return false;

    if (!isSameTree(p->left, q->right))
        return false;

    if (!isSameTree(p->right, q->left))
        return false;

    return true;
}
bool isSymmetric(struct TreeNode* root) {
    return isSameTree(root->left,root->right);
}