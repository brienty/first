#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef int LTDateType;//�����Ժ����͸��ģ��ض���

typedef struct ListNode
{
	LTDateType val;//��ֵ
	struct ListNode* next;//����һ�����ĵ�ַ
	struct ListNode* prev;//��ǰһ�����ĵ�ַ
}LTNode;

//�������
LTNode* BuyListNode(LTDateType x);

//��ʼ��
LTNode* ListInit();

//β��
void ListPushBack(LTNode* phead, LTDateType x);

//βɾ
void ListPopBack(LTNode* phead);

//��ӡ
void ListPrint(LTNode* phead);

//ͷ��
void ListPushFront(LTNode* phead, LTDateType x);

//ͷɾ
void ListPopFront(LTNode* phead);

//����
LTNode* ListFind(LTNode* phead, LTDateType x);

//��posλ�ò���
void ListInsert(LTNode* pos, LTDateType x);

//ɾ��posλ��
void ListErase(LTNode* pos);

//��������
void ListDestroy(LTNode* phead);