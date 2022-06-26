#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//�����½��
SListNode* BuySListNode(SListDateType x)
{
	//����һ�鶯̬�ڴ�
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	//����ʧ����ֹ����
	if (newnode == NULL)
	{
		printf("Fail\n");
		exit(-1);
	}
	else
	{
		newnode->date = x;//��x�����¿���date
		newnode->next = NULL;//���ٿռ��֪��ָ���ģ����ÿ�
	}
	//�����ٿռ䷵��
	return newnode;
}

//β�壬ע�⴫����һ��ָ�룬��Ҫ����ָ�����
void SListPushBack(SListNode** pphead, SListDateType x)
{
	//��x�����մ����Ľ��
	SListNode* newnode = BuySListNode(x);
	//���������NULL��˵���ǿ����������ٵĿռ�ֱ�Ӹ����յ�����
	if (*pphead == NULL)
	{
		//������β�գ�����һ���¿��Ľ�㸳ֵ����*pphead��ŵ���ʼ���ǵ�һ�����
		*pphead = newnode;
	}
	//������Ĳ���NULL��˵�����ǿ�����ԭ���������н��
	else
	{
		//��β�ͣ���ͷ������β���
		SListNode* tail = *pphead;
		//��tail�е�next����NULL��˵������ǽ�β�Ľ��
		while (tail->next != NULL)
		{
			//��β��㣬���ϵĽ���һ�����ĵ�ַ��tail��ֱ����һ�����ĵ�ַ��NULL
			tail = tail->next;
		}
		//��tail->next==NULL�����¿��Ľ�㸳ֵ���滻NULL
		tail->next = newnode;
	}
}

//��ӡ����
void PrintSList(SListNode* phead)
{
	SListNode* cur = phead;//��ͷ��㸳ֵ���ֽ��
	//ʹ���ֽ�������cur->next==NULL����������ı�־
	while (cur != NULL)
	{
		printf("%d->", cur->date);
		cur = cur->next;
	}
	printf("NULL\n");
}

//ͷ��
void SListPushFornt(SListNode** pphead, SListDateType x)
{
	//���մ������½��
	SListNode* newnode = BuySListNode(x);
	//���׽���ַ���½�����next
	newnode->next = *pphead;
	//���½����ĵ�ַ���׽��
	*pphead = newnode;