/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root, int *k, int *ans) {
    if (root == NULL || *k == 0)
        return;

    inorder(root->left, k, ans);

    (*k)--;

    if (*k == 0) {
        *ans = root->val;
        return;
    }

    inorder(root->right, k, ans);
}

int kthSmallest(struct TreeNode* root, int k) {
    int ans = -1;
    inorder(root, &k, &ans);
    return ans;
}