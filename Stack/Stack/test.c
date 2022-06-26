#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

/*
	栈这里要注意：
	栈是必须从栈顶出入并且一定是后进先出
	由于使用动态数组的方式比使用链表更好，但是可以使用链表
	因为栈这里不用中间插入元素，而数组尾插效率高
	具体优势：
	使用的指针比双向链表少
	高速缓存的命中率比链表高 
*/

void Test()
{
	ST st;
	//要改变结构体，需要传地址
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPush(&st, 6);
	printf("%d\n", Stacksize(&st));

	//打印栈需要付出代价，因为栈是只能从栈顶入栈和出栈，所以打印完得删除掉
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");

	StackDestroy(&st);
}


int main()
{
	Test();
	return 0;
}