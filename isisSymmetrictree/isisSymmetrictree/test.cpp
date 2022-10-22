#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
};

 //判断相等的变形
bool isisSymmetrictree(struct TreeNode* p, struct TreeNode* q)
{
    //两个都为空
    if (p == NULL && q == NULL)
        return true;
    //一个为空
    if (p == NULL && q != NULL || p != NULL && q == NULL)
        return false;
    //两个都不为空
    if (p->val != q->val)
        return false;
    //递归处理p的左子树，q的右子树和p的右子树，q的左子树
    return isisSymmetrictree(p->left, q->right) && isisSymmetrictree(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
    //空树是对称的
    if (root == NULL)
        return true;
    //递归处理左右子树
    return isisSymmetrictree(root->left, root->right);
}