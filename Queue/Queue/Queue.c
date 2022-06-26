#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);//结构体必须存在

	pq->head = pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);//结构体必须存在

	while (pq->head)
	{
		//存储下一个结点
		Queue* next = pq->head->next;
		//销毁结点
		free(pq->head);
		pq->head = next;
	}
	pq->head = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//创建结点
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;

	//当队列为空
	if (pq->head == NULL && pq->tail == NULL)
	{
		pq->head = newnode;
		pq->tail = newnode;
	}
	//队列不为空
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}

}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head && pq->tail);//队列为空不能删除

	//保存head后一个结点
	QNode* next =pq->head->next;

	//销毁结点
	free(pq->head);
	pq->head = NULL;

	//结点大于一个
	if (next)
	{
		pq->head = next;
	}
	//只有一个结点，tail也要置空，不然tail就是野指针了
	else
	{
		pq->head = pq->tail = NULL;
	}

}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	//为空的话，就返回true，否则false
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
	//第一个元素为空的情况
	if (pq->head == NULL)
	{
		return NULL;
	}

	return pq->head->val;

}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	//第一个元素为空的情况
	if (pq->tail == NULL)
	{
		return NULL;
	}

	return pq->tail->val;
}