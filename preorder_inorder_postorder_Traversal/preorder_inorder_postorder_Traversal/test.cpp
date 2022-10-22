#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>
#include <cstdlib>



//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


//��ȷ��Ԫ�ظ���
int BTsize(struct TreeNode* root)
{
    return root == NULL ? 0 : BTsize(root->left) + BTsize(root->right) + 1;
}

//���еݹ��������ֵ�洢��������
void _preorder(struct TreeNode* root, int* a, int* pcount)
{
    if (root == NULL)
        return;
    a[(*pcount)++] = root->val;
    _preorder(root->left, a, pcount);
    _preorder(root->right, a, pcount);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    //ȷ��Ԫ�ظ���������Ԫ�ظ��������ռ�
    int size = BTsize(root);
    int* a = (int*)malloc(sizeof(int) * size);
    //����ѡ��ָ������Ϊpcount��ÿһ����ջ�ı�Ķ�Ҫͳ��������a����Ҫ�������Ԫ�ش洢����
    int count = 0;
    int* pcount = &count;
    _preorder(root, a, pcount);
    //�����е�Ԫ�ظ�����ͳ������
    *returnSize = size;//ע�ⲻ�Ǹ���ַ����ȻreturnSize�����ָ��ͱ���
    return a;
}



void _inorder(struct TreeNode* root, int* a, int* pcount)
{
    if (root == NULL)
        return;
    _inorder(root->left, a, pcount);
    a[(*pcount)++] = root->val;
    _inorder(root->right, a, pcount);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = BTsize(root);
    int* a = (int*)malloc(sizeof(int) * size);
    *returnSize = size;
    int count = 0;
    int* pcount = &count;
    _inorder(root, a, pcount);
    return a;
}


void _postorder(struct TreeNode* root, int* a, int* pcount)
{
    if (root == NULL)
        return;
    _postorder(root->left, a, pcount);
    _postorder(root->right, a, pcount);
    a[(*pcount)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = BTsize(root);
    int* a = (int*)malloc(sizeof(int) * size);
    *returnSize = size;
    int count = 0;
    int* pcount = &count;
    _postorder(root, a, pcount);
    return a;
}