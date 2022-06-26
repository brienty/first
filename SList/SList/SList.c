#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//创建新结点
SListNode* BuySListNode(SListDateType x)
{
	//开辟一块动态内存
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	//开辟失败终止程序
	if (newnode == NULL)
	{
		printf("Fail\n");
		exit(-1);
	}
	else
	{
		newnode->date = x;//将x放入新开辟date
		newnode->next = NULL;//开辟空间后不知道指向哪，先置空
	}
	//将开辟空间返回
	return newnode;
}

//尾插，注意传的是一级指针，需要二级指针接收
void SListPushBack(SListNode** pphead, SListDateType x)
{
	//传x并接收创建的结点
	SListNode* newnode = BuySListNode(x);
	//如果传的是NULL，说明是空链表，将开辟的空间直接赋给空的链表
	if (*pphead == NULL)
	{
		//当链表尾空，将第一次新开的结点赋值，则*pphead存放的则始终是第一个结点
		*pphead = newnode;
	}
	//如果传的不是NULL，说明不是空链表，原来的链表有结点
	else
	{
		//找尾巴，将头结点给找尾结点
		SListNode* tail = *pphead;
		//当tail中的next等于NULL，说明其就是结尾的结点
		while (tail->next != NULL)
		{
			//找尾结点，不断的将下一个结点的地址给tail，直到下一个结点的地址是NULL
			tail = tail->next;
		}
		//当tail->next==NULL，将新开的结点赋值，替换NULL
		tail->next = newnode;
	}
}

//打印链表
void PrintSList(SListNode* phead)
{
	SListNode* cur = phead;//将头结点赋值给现结点
	//使用现结点遍历，cur->next==NULL是链表结束的标志
	while (cur != NULL)
	{
		printf("%d->", cur->date);
		cur = cur->next;
	}
	printf("NULL\n");
}

//头插
void SListPushFornt(SListNode** pphead, SListDateType x)
{
	//接收创建的新结点
	SListNode* newnode = BuySListNode(x);
	//将首结点地址给新建结点的next
	newnode->next = *pphead;
	//将新建结点的地址放首结点
	*pphead = newnode;