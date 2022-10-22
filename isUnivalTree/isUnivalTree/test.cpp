#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>

 //Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isUnivalTree(struct TreeNode* root) {
    //����
    if (root == NULL)
        return true;
    //�������ڵ���������val�͸��ڵ�val����
    if (root->left && root->val != root->left->val)
        return false;
    //�������ڵ���������val�͸��ڵ�val����
    if (root->right && root->val != root->right->val)
        return false;
    //�ݹ���������
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}