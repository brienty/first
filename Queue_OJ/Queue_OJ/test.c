#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

//用队列实现栈
//题目链接：https://leetcode-cn.com/problems/implement-stack-using-queues

/*
	思路：
	将数据在两个队列移动，哪边空往哪边移动
*/



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
		QNode* next = pq->head->next;
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
	QNode* next = pq->head->next;

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
	assert(pq->head);

	return pq->head->val;

}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	//第一个元素为空的情况
	assert(pq->tail);

	return pq->tail->val;
}



typedef struct {
	//定义两个队列的结构体，而不是指针
	Queue q1;//队列一结构体
	Queue q2;//队列二结构体
} MyStack;


MyStack* myStackCreate() {
	//开辟队列结构体空间并且初始化
	MyStack* newstack = (MyStack*)malloc(sizeof(MyStack));
	assert(newstack);
	
	//初始化两个队列
	QueueInit(&newstack->q1);
	QueueInit(&newstack->q2);

	return newstack;
}

void myStackPush(MyStack* obj, QDataType x) {
	assert(obj);

	//往不为空的队列放入数据
	if (!QueueEmpty(&obj->q1))
		QueuePush(&obj->q1, x);
	else
		QueuePush(&obj->q2, x);
}

int myStackPop(MyStack* obj) {
	assert(obj);

	//假设第一个是空队列，第二个不是空队列
	Queue* empty = &obj->q1;
	Queue* nonempty = &obj->q2;
	//如果不是则交换，当这里为真说明q1不为空
	if (!QueueEmpty(&obj->q1))
	{
		empty = &obj->q2;
		nonempty = &obj->q1;
	}

	//非空队列上的元素大于一时，将元素从非空队列移到空队列上
	while (QueueSize(nonempty) > 1)
	{
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}

	//存储栈顶元素，即非空队列的最后一个元素
	QDataType temp = QueueFront(nonempty);

	//将最后一个元素删除
	QueuePop(nonempty);

	return temp;

}

int myStackTop(MyStack* obj) {
	assert(obj);

	//保存栈顶元素
	QDataType top;

	//非空队列的最后一个元素即栈顶元素
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

	//两个队列都为空，栈才为空
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	assert(obj);

	//注意队列里的结点也需要销毁
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	
	//将栈销毁
	free(obj);
	obj = NULL;
}
