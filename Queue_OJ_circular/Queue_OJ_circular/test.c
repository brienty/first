#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>



//设计循环队列
//题目链接：https://leetcode-cn.com/problems/design-circular-queue



/*
    思路：
    此题可以采用两种方法解决，一种构建数组队列，一种是构建链式队列
    由于数组更有优势，采用数组队列，但是链式结构也会实现
    多开辟一个位置大小的空间，用来区分判空和判满，创建两个头尾指针
    将头尾链接，注意几种极端的情况
*/



//采用数组的方式实现
typedef struct {
    int* arr;//指向数组
    int head;//头的位置
    int tail;//尾的位置
    int k;//数组大小
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    //开辟空间
    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    assert(q);
    int* a = (int*)malloc(sizeof(int) * (k + 1));//必须多开一个位置的空间
    assert(a);
    //初始化
    q->arr = a;
    q->k = k;
    q->tail = q->head = 0;
    return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);
    //为空则返回false
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }

    obj->arr[obj->tail] = value;

    //当tail等于k以后需要回到头部
    if (obj->tail == obj->k)
    {
        obj->tail = 0;
    }
    else
    {
        obj->tail++;
    }
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);
    //为空返回false
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }

    //当head为k时，返回头部
    if (obj->head == obj->k)
    {
        obj->head = 0;
    }
    else
    {
        obj->head++;
    }

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    assert(obj);
    //为空返回-1
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }

    return obj->arr[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }

    //当tail在0位置处时
    if (obj->tail == 0)
    {
        return obj->arr[obj->k];
    }
    else
    {
        return obj->arr[obj->tail - 1];
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);
    //两个相等即空
    return (obj->head == obj->tail);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);

    //当head在0位置处，tail在k位置处
    if (obj->head == 0 && obj->tail == obj->k)
    {
        return true;
    }

    return (obj->tail + 1 == obj->head);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    assert(obj);
    free(obj->arr);
    free(obj);
    obj = NULL;
}







//采用链表实现
//定义结点结构体
typedef struct QueueNode
{
    int val;
    struct QueueNode* next;
}QNode;
//定义头尾指针结构体
typedef struct {
    QNode* head;
    QNode* tail;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    //使用链表，先开一块空间给存放指针的结构体
    MyCircularQueue* pq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    assert(pq);
    //给head和tail初始化为NULL，必须初始化，不然下面没办法进行
    pq->head = pq->tail = NULL;
    //开辟k+1个空间的结点
    int num = k + 1;
    while (num--)
    {
        QNode* newnode = (QNode*)malloc(sizeof(QNode));
        assert(newnode);
        newnode->next = NULL;
        //让head和tail都指向第一个结点
        if (pq->head == NULL)
        {
            pq->head = pq->tail = newnode;
        }
        else
        {
            pq->tail->next = newnode;
            pq->tail = newnode;
        }
    }

    //将最后一个位置的next指向第一个，循环
    pq->tail->next = pq->head;

    //将尾指针置回第一个位置
    pq->tail = pq->head;

    return pq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);
    //满了就不能再插入
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }

    obj->tail->val = value;
    obj->tail = obj->tail->next;

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);
    //空的不能删除
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }

    obj->head = obj->head->next;

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    assert(obj);
    //空的返回-1
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }

    return obj->head->val;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    assert(obj);
    //空的返回-1
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }

    //tail指向最后一个数据的后面的位置，所以要遍历一遍才能找到最后一个数据
    QNode* cur = obj->head;
    while (cur->next != obj->tail)
    {
        cur = cur->next;
    }

    return cur->val;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);
    //两个相等就说明为空
    return obj->head == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);
    //当tail的next等于head说明满了
    return obj->head == obj->tail->next;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    assert(obj);
    //先将结点销毁
    QNode* cur = obj->head;
    while (cur->next != obj->head)
    {
        QNode* next = cur->next;
        free(cur);
        cur = next;
    }
    free(cur);
    cur = obj->tail = NULL;
    //再将存头尾指针的结构体销毁
    free(obj);
    obj = NULL;
}