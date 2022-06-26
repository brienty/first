#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int SListDateType;//方便类型灵活变换

typedef struct SListNode
{
	int date;//数据
	struct SListNode* next;//存放下一个结点的地址
}SListNode;

//创建新的结点
SListNode* BuySListNode(SListDateType x);

//打印链表
void PrintSList(SListNode* phead);

//尾插
void SListPushBack(SListNode** pphead, SListDateType x);

//头插
void SListPushFornt(SListNode** pphead, SListDateType x);