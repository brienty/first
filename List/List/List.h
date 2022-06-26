#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef int LTDateType;//方便以后类型更改，重定义

typedef struct ListNode
{
	LTDateType val;//存值
	struct ListNode* next;//存下一个结点的地址
	struct ListNode* prev;//存前一个结点的地址
}LTNode;

//创建结点
LTNode* BuyListNode(LTDateType x);

//初始化
LTNode* ListInit();

//尾插
void ListPushBack(LTNode* phead, LTDateType x);

//尾删
void ListPopBack(LTNode* phead);

//打印
void ListPrint(LTNode* phead);

//头插
void ListPushFront(LTNode* phead, LTDateType x);

//头删
void ListPopFront(LTNode* phead);

//查找
LTNode* ListFind(LTNode* phead, LTDateType x);

//在pos位置插入
void ListInsert(LTNode* pos, LTDateType x);

//删除pos位置
void ListErase(LTNode* pos);

//销毁链表
void ListDestroy(LTNode* phead);