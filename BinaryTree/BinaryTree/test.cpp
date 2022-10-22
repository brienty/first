#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std;

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BTDataType data;
}BTNode;

//获取结点
BTNode* BuyBTNode(BTDataType x)
{
	BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));//开的是结点的大小，而不是数据的大小
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	BTNode* newnode = tmp;
	newnode->data = x;
	newnode->left = newnode->right = NULL;

	return newnode;
}

//获取一颗二叉树
BTNode* CreateBinaryTree()
{
	BTNode* node1 = BuyBTNode(1);
	BTNode* node2 = BuyBTNode(2);
	BTNode* node3 = BuyBTNode(3);
	BTNode* node4 = BuyBTNode(4);
	BTNode* node5 = BuyBTNode(5);
	BTNode* node6 = BuyBTNode(6);

	node1->left = node2;
	node2->left = node3;
	node1->right = node4;
	node4->left = node5;
	node4->right = node6;
	
	return node1;
}

// 二叉树前序遍历
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
// 二叉树中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}
// 二叉树后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	InOrder(root->right);
	printf("%d ", root->data);
}

//二叉树的节点个数
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;
	
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

//二叉树的深度
int BinaryTreedepth(BTNode* root)
{
	if (root == NULL)
		return 0;


	int leftdepth = BinaryTreedepth(root->left);
	int rightdepth = BinaryTreedepth(root->right);

	return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k >= 1);

	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;
	
	BTNode* leftres = BinaryTreeFind(root->left, x);
	if (leftres != NULL)
		return leftres;

	BTNode* rightres = BinaryTreeFind(root->right, x);
	if (rightres != NULL)
		return rightres;

	return NULL;
}



int main()
{
	BTNode* root = CreateBinaryTree();
	//前中后序遍历
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	//计数
	/*int count = 0;
	BTreeSize(root, &count);*/
	cout << "size:" << BinaryTreeSize(root) << endl;
	cout << "LeafSize:" << BinaryTreeLeafSize(root) << endl;
	cout << "depth:" << BinaryTreedepth(root) << endl;
	cout << "LevelKSize:" << BinaryTreeLevelKSize(root, 3) << endl;
	for (int i = 0; i <= 7; ++i)
	{
		BinaryTreeFind(root, i);
		if (BinaryTreeFind(root, i))
			cout << BinaryTreeFind(root, i)->data << " ";
		cout << BinaryTreeFind(root, i) << endl;
	}
	return 0;
}