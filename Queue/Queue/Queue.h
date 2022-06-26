#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>



//方便类型更改
typedef int QDataType;
//定义结点结构体
typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;
//定义头尾指针结构体
typedef struct Queue
{
	QNode* head;//存结点的头
	QNode* tail;//存结点的尾
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
bool QueueEmpty(Queue* pq);
size_t QueueSize(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);