#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
};
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    //两个都为空
    if (p == NULL && q == NULL)
        return true;
    //有一个不为空
    if (p == NULL && q != NULL || p != NULL && q == NULL)
        return false;
    //两个都不为空
    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}