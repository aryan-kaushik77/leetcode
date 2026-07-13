#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Check if node is a leaf
int isLeaf(struct Node *node) {
    return node->left == NULL && node->right == NULL;
}

// Collect left boundary
void collectLeft(struct Node *root, int *res, int *index) {
    if (root == NULL || isLeaf(root))
        return;

    res[(*index)++] = root->data;

    if (root->left)
        collectLeft(root->left, res, index);
    else if (root->right)
        collectLeft(root->right, res, index);
}

// Collect leaf nodes
void collectLeaves(struct Node *root, int *res, int *index) {
    if (root == NULL)
        return;

    if (isLeaf(root)) {
        res[(*index)++] = root->data;
        return;
    }

    collectLeaves(root->left, res, index);
    collectLeaves(root->right, res, index);
}

// Collect right boundary (bottom-up)
void collectRight(struct Node *root, int *res, int *index) {
    if (root == NULL || isLeaf(root))
        return;

    if (root->right)
        collectRight(root->right, res, index);
    else if (root->left)
        collectRight(root->left, res, index);

    res[(*index)++] = root->data;
}

// Boundary Traversal
int* boundaryTraversal(struct Node *root, int *returnSize) {

    int *res = (int *)malloc(sizeof(int) * 1000); // assume max 1000 nodes
    *returnSize = 0;

    if (root == NULL)
        return res;

    if (!isLeaf(root))
        res[(*returnSize)++] = root->data;

    collectLeft(root->left, res, returnSize);

    collectLeaves(root, res, returnSize);

    collectRight(root->right, res, returnSize);

    return res;
}
