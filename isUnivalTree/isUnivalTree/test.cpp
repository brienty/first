#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>

 //Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isUnivalTree(struct TreeNode* root) {
    //空树
    if (root == NULL)
        return true;
    //左树存在但是左树的val和根节点val不等
    if (root->left && root->val != root->left->val)
        return false;
    //右数存在但是右树的val和根节点val不等
    if (root->right && root->val != root->right->val)
        return false;
    //递归左右子树
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}