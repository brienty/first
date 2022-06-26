#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>



//用栈实现队列
//题目链接：https://leetcode-cn.com/problems/implement-queue-using-stacks



/*
    思路：
    由于栈是先进后出，队列是先进先处，所以可以这样
    指定一个栈只处数据，一个栈只入数据
*/



//为了方便类型更改
typedef int STDataType;
//定义栈的结构体，这里采用动态数组栈
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
    //这里初始化为0，则top记录的当前元素的下一个元素
    ps->capacity = ps->top = 0;
}

//因为这里接受的是结构体的地址，所以这里的参数改变会影响到实参
void StackDestroy(ST* ps)
{
    assert(ps);

    free(ps->a);
    //这里置空是有效的
    ps->a = NULL;

    ps->capacity = ps->top = 0;
}

void StackPush(ST* ps, STDataType x)
{
    assert(ps);

    //判断是否需要扩容
    if (ps->top == ps->capacity)
    {
        //这里需要处理capacity为0时的情况
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

    //不需要扩容或者扩容完，将数据放入
    ps->a[ps->top] = x;
    ++ps->top;
}

void StackPop(ST* ps)
{
    assert(ps);

    //当栈里没有数据时不能删除
    assert(ps->top > 0);

    //因为数组使用数据覆盖没意义，所以直接将栈顶向下移动
    --ps->top;
}

bool StackEmpty(ST* ps)
{
    assert(ps);

    //当top为0时则为空，否则不为空
    return ps->top == 0;
}

int Stacksize(ST* ps)
{
    assert(ps);

    //因为top是下一个元素的下标，所以它即为元素个数
    return ps->top;
}

STDataType StackTop(ST* ps)
{
    assert(ps);

    //当top为空时不能返回
    assert(ps->top > 0);

    return (ps->a[ps->top - 1]);
}

typedef struct {
    ST q1;
    ST q2;
} MyQueue;

MyQueue* myQueueCreate() {
    //开辟空间给存两个栈的结构体
    MyQueue* ps = (MyQueue*)malloc(sizeof(MyQueue));
    assert(ps);
    //初始化两个栈
    StackInit(&ps->q1);
    StackInit(&ps->q2);
    //将两个栈返回
    return ps;
}

void myQueuePush(MyQueue* obj, int x) {
    assert(obj);
    //q1负责插入
    StackPush(&obj->q1, x);
}

int myQueuePop(MyQueue* obj) {
    assert(obj);
    //当q2为空时，把数据导入q2
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
    //当q2里还有数据则直接删除
    STDataType temp = StackTop(&obj->q2);
    StackPop(&obj->q2);

    return temp;
}

int myQueuePeek(MyQueue* obj) {
    assert(obj);
    //当q2为空时，把数据导入q2
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
    //当q2里还有数据则直接删除
    return StackTop(&obj->q2);
}

bool myQueueEmpty(MyQueue* obj) {
    assert(obj);
    //两个栈都为空则为空
    return (StackEmpty(&obj->q1) && StackEmpty(&obj->q2));
}

void myQueueFree(MyQueue* obj) {
    assert(obj);
    //先把栈销毁
    StackDestroy(&obj->q1);
    StackDestroy(&obj->q2);
    //再把存栈的结构体销毁
    free(obj);
    obj = NULL;
}
