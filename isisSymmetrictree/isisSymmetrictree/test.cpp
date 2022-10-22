#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
};

 //�ж���ȵı���
bool isisSymmetrictree(struct TreeNode* p, struct TreeNode* q)
{
    //������Ϊ��
    if (p == NULL && q == NULL)
        return true;
    //һ��Ϊ��
    if (p == NULL && q != NULL || p != NULL && q == NULL)
        return false;
    //��������Ϊ��
    if (p->val != q->val)
        return false;
    //�ݹ鴦��p����������q����������p����������q��������
    return isisSymmetrictree(p->left, q->right) && isisSymmetrictree(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
    //�����ǶԳƵ�
    if (root == NULL)
        return true;
    //�ݹ鴦����������
    return isisSymmetrictree(root->left, root->right);
}