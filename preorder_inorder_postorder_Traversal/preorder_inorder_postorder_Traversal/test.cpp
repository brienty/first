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


//先确定元素个数
int BTsize(struct TreeNode* root)
{
    return root == NULL ? 0 : BTsize(root->left) + BTsize(root->right) + 1;
}

//进行递归遍历，将值存储进数组中
void _preorder(struct TreeNode* root, int* a, int* pcount)
{
    if (root == NULL)
        return;
    a[(*pcount)++] = root->val;
    _preorder(root->left, a, pcount);
    _preorder(root->right, a, pcount);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    //确定元素个数，根据元素个数来开空间
    int size = BTsize(root);
    int* a = (int*)malloc(sizeof(int) * size);
    //这里选择传指针是因为pcount是每一个堆栈改变的都要统计下来，a是需要将树里的元素存储下来
    int count = 0;
    int* pcount = &count;
    _preorder(root, a, pcount);
    //把树中的元素个数给统计下来
    *returnSize = size;//注意不是给地址，不然returnSize就这个指针就变了
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