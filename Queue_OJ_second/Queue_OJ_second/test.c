#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>



//��ջʵ�ֶ���
//��Ŀ���ӣ�https://leetcode-cn.com/problems/implement-queue-using-stacks



/*
    ˼·��
    ����ջ���Ƚ�������������Ƚ��ȴ������Կ�������
    ָ��һ��ջֻ�����ݣ�һ��ջֻ������
*/



//Ϊ�˷������͸���
typedef int STDataType;
//����ջ�Ľṹ�壬������ö�̬����ջ
typedef struct Stack
{
    STDataType* a;
    int capacity;
    int top;
}ST;
void StackInit(ST* ps)
{
    assert(ps);

    ps->a = NULL;
    //�����ʼ��Ϊ0����top��¼�ĵ�ǰԪ�ص���һ��Ԫ��
    ps->capacity = ps->top = 0;
}

//��Ϊ������ܵ��ǽṹ��ĵ�ַ����������Ĳ����ı��Ӱ�쵽ʵ��
void StackDestroy(ST* ps)
{
    assert(ps);

    free(ps->a);
    //�����ÿ�����Ч��
    ps->a = NULL;

    ps->capacity = ps->top = 0;
}

void StackPush(ST* ps, STDataType x)
{
    assert(ps);

    //�ж��Ƿ���Ҫ����
    if (ps->top == ps->capacity)
    {
        //������Ҫ����capacityΪ0ʱ�����
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        STDataType* temp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
        if (temp == NULL)
        {
            printf("realloc fail!\n");
            exit(-1);
        }
        ps->a = temp;
        ps->capacity = newcapacity;
    }

    //����Ҫ���ݻ��������꣬�����ݷ���
    ps->a[ps->top] = x;
    ++ps->top;
}

void StackPop(ST* ps)
{
    assert(ps);

    //��ջ��û������ʱ����ɾ��
    assert(ps->top > 0);

    //��Ϊ����ʹ�����ݸ���û���壬����ֱ�ӽ�ջ�������ƶ�
    --ps->top;
}

bool StackEmpty(ST* ps)
{
    assert(ps);

    //��topΪ0ʱ��Ϊ�գ�����Ϊ��
    return ps->top == 0;
}

int Stacksize(ST* ps)
{
    assert(ps);

    //��Ϊtop����һ��Ԫ�ص��±꣬��������ΪԪ�ظ���
    return ps->top;
}

STDataType StackTop(ST* ps)
{
    assert(ps);

    //��topΪ��ʱ���ܷ���
    assert(ps->top > 0);

    return (ps->a[ps->top - 1]);
}

typedef struct {
    ST q1;
    ST q2;
} MyQueue;

MyQueue* myQueueCreate() {
    //���ٿռ��������ջ�Ľṹ��
    MyQueue* ps = (MyQueue*)malloc(sizeof(MyQueue));
    assert(ps);
    //��ʼ������ջ
    StackInit(&ps->q1);
    StackInit(&ps->q2);
    //������ջ����
    return ps;
}

void myQueuePush(MyQueue* obj, int x) {
    assert(obj);
    //q1�������
    StackPush(&obj->q1, x);
}

int myQueuePop(MyQueue* obj) {
    assert(obj);
    //��q2Ϊ��ʱ�������ݵ���q2
    if (StackEmpty(&obj->q2))
    {
        STDataType num = Stacksize(&obj->q1);
        while (num--)
        {
            STDataType tmp = StackTop(&obj->q1);
            StackPop(&obj->q1);
            StackPush(&obj->q2, tmp);
        }
        STDataType temp = StackTop(&obj->q2);
        StackPop(&obj->q2);
        return temp;
    }
    //��q2�ﻹ��������ֱ��ɾ��
    STDataType temp = StackTop(&obj->q2);
    StackPop(&obj->q2);

    return temp;
}

int myQueuePeek(MyQueue* obj) {
    assert(obj);
    //��q2Ϊ��ʱ�������ݵ���q2
    if (StackEmpty(&obj->q2))
    {
        STDataType num = Stacksize(&obj->q1);
        while (num--)
        {
            STDataType tmp = StackTop(&obj->q1);
            StackPop(&obj->q1);
            StackPush(&obj->q2, tmp);
        }
        STDataType temp = StackTop(&obj->q2);
        return temp;
    }
    //��q2�ﻹ��������ֱ��ɾ��
    return StackTop(&obj->q2);
}

bool myQueueEmpty(MyQueue* obj) {
    assert(obj);
    //����ջ��Ϊ����Ϊ��
    return (StackEmpty(&obj->q1) && StackEmpty(&obj->q2));
}

void myQueueFree(MyQueue* obj) {
    assert(obj);
    //�Ȱ�ջ����
    StackDestroy(&obj->q1);
    StackDestroy(&obj->q2);
    //�ٰѴ�ջ�Ľṹ������
    free(obj);
    obj = NULL;
}
