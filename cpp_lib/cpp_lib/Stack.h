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


//使用条件编译，处理不同语言之间的调用关系
#ifdef __cplusplus
extern "C"
{
#endif
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
#ifdef __cplusplus
	}
#endif


//#ifdef __cplusplus
//#define EXTERN extern "C"
//#else
//#define EXTERN
//#endif
//
////初始化栈
//EXTERN void StackInit(ST* ps);
////销毁栈
//EXTERN void StackDestroy(ST* ps);
////插入栈
//EXTERN void StackPush(ST* ps, STDataType x);
////删除栈
//EXTERN void StackPop(ST* ps);
////判断栈是否为空
//EXTERN bool StackEmpty(ST* ps);
////栈里的元素个数
//EXTERN int Stacksize(ST* ps);
////栈顶的元素
//EXTERN STDataType StackTop(ST* ps);