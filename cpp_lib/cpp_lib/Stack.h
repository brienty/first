#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//Ϊ�˷������͸���
typedef int STDataType;
//����ջ�Ľṹ�壬������ö�̬����ջ
typedef struct Stack
{
	STDataType* a;
	int capacity;
	int top;
}ST;


//ʹ���������룬����ͬ����֮��ĵ��ù�ϵ
#ifdef __cplusplus
extern "C"
{
#endif
	//��ʼ��ջ
	void StackInit(ST* ps);
	//����ջ
	void StackDestroy(ST* ps);
	//����ջ
	void StackPush(ST* ps, STDataType x);
	//ɾ��ջ
	void StackPop(ST* ps);
	//�ж�ջ�Ƿ�Ϊ��
	bool StackEmpty(ST* ps);
	//ջ���Ԫ�ظ���
	int Stacksize(ST* ps);
	//ջ����Ԫ��
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
////��ʼ��ջ
//EXTERN void StackInit(ST* ps);
////����ջ
//EXTERN void StackDestroy(ST* ps);
////����ջ
//EXTERN void StackPush(ST* ps, STDataType x);
////ɾ��ջ
//EXTERN void StackPop(ST* ps);
////�ж�ջ�Ƿ�Ϊ��
//EXTERN bool StackEmpty(ST* ps);
////ջ���Ԫ�ظ���
//EXTERN int Stacksize(ST* ps);
////ջ����Ԫ��
//EXTERN STDataType StackTop(ST* ps);