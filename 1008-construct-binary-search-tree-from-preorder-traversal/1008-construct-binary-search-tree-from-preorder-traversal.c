struct TreeNode* buildtree(int *A, int Asize, int *i, int bound) {

    if (*i >= Asize || A[*i] >= bound) {
        return NULL;
    }

    struct TreeNode *root = malloc(sizeof(struct TreeNode));

    root->val = A[(*i)++];
    root->left = buildtree(A, Asize, i, root->val);
    root->right = buildtree(A, Asize, i, bound);

    return root;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {

    int i = 0;
    return buildtree(preorder, preorderSize, &i, INT_MAX);

}