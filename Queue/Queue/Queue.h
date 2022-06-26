#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>



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

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
bool QueueEmpty(Queue* pq);
size_t QueueSize(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);