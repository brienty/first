#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

//�ö���ʵ��ջ
//��Ŀ���ӣ�https://leetcode-cn.com/problems/implement-stack-using-queues

/*
	˼·��
	�����������������ƶ����ı߿����ı��ƶ�
*/



//�������͸���
typedef int QDataType;
//������ṹ��
typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;
//����ͷβָ��ṹ��
typedef struct Queue
{
	QNode* head;//�����ͷ
	QNode* tail;//�����β
}Queue;
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
		QNode* next = pq->head->next;
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
	QNode* next = pq->head->next;

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
	assert(pq->head);

	return pq->head->val;

}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	//��һ��Ԫ��Ϊ�յ����
	assert(pq->tail);

	return pq->tail->val;
}



typedef struct {
	//�����������еĽṹ�壬������ָ��
	Queue q1;//����һ�ṹ��
	Queue q2;//���ж��ṹ��
} MyStack;


MyStack* myStackCreate() {
	//���ٶ��нṹ��ռ䲢�ҳ�ʼ��
	MyStack* newstack = (MyStack*)malloc(sizeof(MyStack));
	assert(newstack);
	
	//��ʼ����������
	QueueInit(&newstack->q1);
	QueueInit(&newstack->q2);

	return newstack;
}

void myStackPush(MyStack* obj, QDataType x) {
	assert(obj);

	//����Ϊ�յĶ��з�������
	if (!QueueEmpty(&obj->q1))
		QueuePush(&obj->q1, x);
	else
		QueuePush(&obj->q2, x);
}

int myStackPop(MyStack* obj) {
	assert(obj);

	//�����һ���ǿն��У��ڶ������ǿն���
	Queue* empty = &obj->q1;
	Queue* nonempty = &obj->q2;
	//��������򽻻���������Ϊ��˵��q1��Ϊ��
	if (!QueueEmpty(&obj->q1))
	{
		empty = &obj->q2;
		nonempty = &obj->q1;
	}

	//�ǿն����ϵ�Ԫ�ش���һʱ����Ԫ�شӷǿն����Ƶ��ն�����
	while (QueueSize(nonempty) > 1)
	{
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}

	//�洢ջ��Ԫ�أ����ǿն��е����һ��Ԫ��
	QDataType temp = QueueFront(nonempty);

	//�����һ��Ԫ��ɾ��
	QueuePop(nonempty);

	return temp;

}

int myStackTop(MyStack* obj) {
	assert(obj);

	//����ջ��Ԫ��
	QDataType top;

	//�ǿն��е����һ��Ԫ�ؼ�ջ��Ԫ��
	if (!QueueEmpty(&obj->q1))
	{
		top = QueueBack(&obj->q1);
	}
	else
	{
		top = QueueBack(&obj->q2);
	}

	return top;
}

bool myStackEmpty(MyStack* obj) {
	assert(obj);

	//�������ж�Ϊ�գ�ջ��Ϊ��
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	assert(obj);

	//ע�������Ľ��Ҳ��Ҫ����
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	
	//��ջ����
	free(obj);
	obj = NULL;
}
