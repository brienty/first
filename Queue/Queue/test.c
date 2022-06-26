#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

/*
	由于队列是先进先出，使用数组由于头部删除没有链表方便
	所以使用链表实现，采用链式结构体
*/


void Test()
{
	Queue n;
	QueueInit(&n);
	QueuePush(&n, 1);
	QueuePush(&n, 2);
	QueuePush(&n, 3);
	QueuePush(&n, 4);
	printf("%d\n", QueueSize(&n));
	printf("%d ", QueueBack(&n));
	while (!QueueEmpty(&n))
	{
		printf("%d ", QueueFront(&n));
		QueuePop(&n);
	}
	printf("\n");
	printf("%d\n", QueueSize(&n));
	QueueDestroy(&n);
}


int main()
{
	Test();
	return 0;
}