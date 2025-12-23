#include<stdio.h>

#include<stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
    struct TreeNode *right;
};
 
int BinaryTreeSize(struct TreeNode* root)
{
    if (!root)
        return 0;
    return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

int* POT(struct TreeNode* root, int* a, int* pi)
{
    if (!root)
        return NULL;
    a[(*pi)++] = root->val;
    POT(root->left, a, pi);
    POT(root->right, a, pi);
    return a;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int result = BinaryTreeSize(root);
    int* a = (int*)calloc(result, sizeof(int));
    int pi = 0;
    int* ret = POT(root, a, &pi);
    *returnSize = pi;
    return ret;
}

int main()
{
    struct TreeNode a;
    struct TreeNode b;
    struct TreeNode c;
    a.val = 1;
    b.val = 2;
    c.val = 3;
    a.left = &b;
    a.right = &c;
    b.left = b.right = c.left = c.right = NULL;
    int size = 0;
    preorderTraversal(&a, &size);
    return 0;
}