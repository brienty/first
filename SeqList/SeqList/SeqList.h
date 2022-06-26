#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

//�ض������ͣ��������
typedef int SLDataType;

//��̬˳���Ķ��壬Ϊ�˷������ʹ�ã��ض���
typedef struct SeqList
{
	SLDataType* a;
	int sz;
	int capacity;
}SL, SeqList;

//��ʼ��˳���
void SeqListInit(SeqList* psl);

//˳���β��
void SeqListPushBack(SeqList* psl, SLDataType x);

//˳���βɾ
void SeqListPopBack(SeqList* psl);

//˳�������
void SeqListDestroy(SeqList* psl);

//��ӡ˳���
void SeqListPrint(SeqList* psl);

//��������
void SeqListCheckcapacity(SeqList* psl);

//˳���ͷ��
void SeqListPushFront(SeqList* psl, SLDataType x);

//˳���ͷɾ
void SeqListPopFront(SeqList* psl);

//�������
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);

//ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* psl, size_t pos);

//����posλ���ϵ�ֵ
int SeqListFind(SeqList* psl, SLDataType x);

//�޸�posλ���ϵ�ֵ
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);