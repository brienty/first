#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
};
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    //������Ϊ��
    if (p == NULL && q == NULL)
        return true;
    //��һ����Ϊ��
    if (p == NULL && q != NULL || p != NULL && q == NULL)
        return false;
    //��������Ϊ��
    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}