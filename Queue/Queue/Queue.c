#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);//�ṹ��������

	pq->head = pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);//�ṹ��������

	while (pq->head)
	{
		//�洢��һ�����
		Queue* next = pq->head->next;
		//���ٽ��
		free(pq->head);
		pq->head = next;
	}
	pq->head = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//�������
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;

	//������Ϊ��
	if (pq->head == NULL && pq->tail == NULL)
	{
		pq->head = newnode;
		pq->tail = newnode;
	}
	//���в�Ϊ��
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}

}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head && pq->tail);//����Ϊ�ղ���ɾ��

	//����head��һ�����
	QNode* next =pq->head->next;

	//���ٽ��
	free(pq->head);
	pq->head = NULL;

	//������һ��
	if (next)
	{
		pq->head = next;
	}
	//ֻ��һ����㣬tailҲҪ�ÿգ���Ȼtail����Ұָ����
	else
	{
		pq->head = pq->tail = NULL;
	}

}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	//Ϊ�յĻ����ͷ���true������false
	return pq->head == NULL;
}

size_t QueueSize(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->head;
	size_t count = 0;

	while (cur)
	{
		++count;
		cur = cur->next;
	}

	return count;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	//��һ��Ԫ��Ϊ�յ����
	if (pq->head == NULL)
	{
		return NULL;
	}

	return pq->head->val;

}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	//��һ��Ԫ��Ϊ�յ����
	if (pq->tail == NULL)
	{
		return NULL;
	}

	return pq->tail->val;
}