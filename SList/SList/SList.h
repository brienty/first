#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int SListDateType;//�����������任

typedef struct SListNode
{
	int date;//����
	struct SListNode* next;//�����һ�����ĵ�ַ
}SListNode;

//�����µĽ��
SListNode* BuySListNode(SListDateType x);

//��ӡ����
void PrintSList(SListNode* phead);

//β��
void SListPushBack(SListNode** pphead, SListDateType x);

//ͷ��
void SListPushFornt(SListNode** pphead, SListDateType x);