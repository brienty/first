#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//为了方便类型更改
typedef int STDataType;
//定义栈的结构体，这里采用动态数组栈
typedef struct Stack
{
	STDataType* a;
	int capacity;
	int top;
}ST;

//初始化栈
void StackInit(ST* ps);
//销毁栈
void StackDestroy(ST* ps);
//插入栈
void StackPush(ST* ps, STDataType x);
//删除栈
void StackPop(ST* ps);
//判断栈是否为空
bool StackEmpty(ST* ps);
//栈里的元素个数
int Stacksize(ST* ps);
//栈顶的元素
STDataType StackTop(ST* ps);