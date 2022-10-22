#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>
 //Definition for a binary tree node.
struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL && q != NULL || p != NULL && q == NULL)
        return false;
    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

/*
    让左边的每一颗子树（每一颗左子树和右子树都去对比）和subRoot都isSameTree，直到找不到或租找到为止
*/
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL)
        return false;
    return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}