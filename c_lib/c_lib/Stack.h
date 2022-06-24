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