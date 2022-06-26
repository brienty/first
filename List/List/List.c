#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

//�������
LTNode* BuyListNode(LTDateType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	//ʧ�ܼ���ֹ����
	if (newnode == NULL)
	{
		printf("error\n");
		exit(-1);
	}

	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->val = x;

	return newnode;
}

//��ʼ��������������ڱ�λ��ͷ��㣬���뷵�أ���Ȼû�ı�ʵ�ʵ��ڱ�λ
LTNode* ListInit()
{
	LTNode* phead = BuyListNode(0);//��������ֵ���ڱ�λ��ͷ��㲻������

	//һ��ʼnext��prev��ָ���Լ�
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

//β�壬����Ҫ���أ������ڱ�λ���󣬴�ֵ
void ListPushBack(LTNode* phead, LTDateType x)
{
	//�����ڱ�λ����Ϊ��
	assert(phead);

	////�������
	//LTNode* newnode = BuyListNode(x);

	////ʹ��tail����
	//LTNode* tail = phead->prev;

	////���һ����㽻��
	//tail->next = newnode;
	//newnode->prev = tail;

	////�����һ��������ڱ�λ����ѭ��
	//phead->prev = newnode;
	//newnode->next = phead;


	//����Insert�������룬phead����pso
	ListInsert(phead, x);
}

//βɾ
void ListPopBack(LTNode* phead)
{
	assert(phead);//�ڱ�λ����Ϊ��

	////�ڱ�λ����ɾ
	////assert(phead->next != phead);
	//if (phead->next == NULL)
	//{
	//	return;
	//}

	////��������
	//LTNode* tail = phead->prev;
	//LTNode* tailprev = tail->prev;

	////�����һ������ǰһ�����Ͽ�
	//tailprev->next = phead;
	////��ǰһ�������ڱ�λ����ѭ��
	//phead->prev = tailprev;

	////�ͷ�
	//free(tail);
	////�ÿ� 
	//tail = NULL;



	//ʹ��Erase������ɾ��β��㣬����ɾ���ڱ�λ
	ListErase(phead->prev);
}

//��ӡ����
void ListPrint(LTNode* phead)
{
	assert(phead);//�ڱ�λ����Ϊ��

	//����ָ�룬phead���ڱ�λ�����洢����
	LTNode* cur = phead->next;

	while (cur != phead)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

//ͷ��
void ListPushFront(LTNode* phead, LTDateType x)
{
	assert(phead);//�ڱ�λ����Ϊ��

	////�������
	//LTNode* newnode = BuyListNode(x);

	//LTNode* next = phead->next;

	////����phead��newnode
	//phead->next = newnode;
	//newnode->prev = phead;

	////��next��newnode����
	//next->prev = newnode;
	//newnode->next = next;



	//����Insert�������룬phead->next����pos
	ListInsert(phead->next, x);
}

//ͷɾ
void ListPopFront(LTNode* phead)
{
	assert(phead);//�ڱ�λ����Ϊ��
	////�ڱ�λ����ɾ
	//if (phead->next == phead)
	//{
	//	return;
	//}

	//LTNode* next = phead->next;

	//phead->next = next->next;
	//next->next->prev = phead;

	//free(next);
	//next = NULL;



	//ʹ��Erase������ɾ��ͷ���������ڱ�λ
	ListErase(phead->next);

}

//����
LTNode* ListFind(LTNode* phead, LTDateType x)
{
	assert(phead);//����Ϊ�ղ��ܲ���

	//pheadΪ�ڱ�λ��Ӧ������һ����㿪ʼ����
	LTNode* cur = phead->next;

	while (cur != phead)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}

	//�Ҳ���
	return NULL;
}

//��posλ��ǰ����,���ù��ڱ�λ��ͷ���
void ListInsert(LTNode* pos, LTDateType x)
{
	assert(pos);//������λ�ò���Ϊ��

	//�������
	LTNode* newnode = BuyListNode(x);

	LTNode* prev = pos->prev;
	
	newnode->prev = prev;
	prev->next = newnode;

	newnode->next = pos;
	pos->prev = newnode;
}

//ɾ��posλ��
void ListErase(LTNode* pos)
{
	assert(pos);//��ɾλ�ò���Ϊ��

	LTNode* posprev = pos->prev;
	LTNode* posnext = pos->next;
	
	//��posǰ������
	posprev->next = posnext;
	posnext->prev = posprev;

	//�ͷ�pos
	free(pos);
	//�����ÿղ��ÿն�������ô������Ϊ����ֻ��ʵ�εĿ����������Ҫ�������ÿ�
	pos = NULL;
}

//��������
void ListDestroy(LTNode* phead)
{
	assert(phead);//���������ڣ���������

	LTNode* cur = phead->next;

	while (cur != phead)
	{
		//��ѭ���ﴴ�������ƶ�
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(cur);
	//�����ÿղ��ÿն�������ô������Ϊ����ֻ��ʵ�εĿ����������Ҫ�������ÿ�
	cur = NULL;
}