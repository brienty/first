#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>



//���ѭ������
//��Ŀ���ӣ�https://leetcode-cn.com/problems/design-circular-queue



/*
    ˼·��
    ������Բ������ַ��������һ�ֹ���������У�һ���ǹ�����ʽ����
    ��������������ƣ�����������У�������ʽ�ṹҲ��ʵ��
    �࿪��һ��λ�ô�С�Ŀռ䣬���������пպ���������������ͷβָ��
    ��ͷβ���ӣ�ע�⼸�ּ��˵����
*/



//��������ķ�ʽʵ��
typedef struct {
    int* arr;//ָ������
    int head;//ͷ��λ��
    int tail;//β��λ��
    int k;//�����С
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    //���ٿռ�
    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    assert(q);
    int* a = (int*)malloc(sizeof(int) * (k + 1));//����࿪һ��λ�õĿռ�
    assert(a);
    //��ʼ��
    q->arr = a;
    q->k = k;
    q->tail = q->head = 0;
    return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);
    //Ϊ���򷵻�false
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }

    obj->arr[obj->tail] = value;

    //��tail����k�Ժ���Ҫ�ص�ͷ��
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
    //Ϊ�շ���false
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }

    //��headΪkʱ������ͷ��
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
    //Ϊ�շ���-1
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

    //��tail��0λ�ô�ʱ
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
    //������ȼ���
    return (obj->head == obj->tail);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);

    //��head��0λ�ô���tail��kλ�ô�
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







//��������ʵ��
//������ṹ��
typedef struct QueueNode
{
    int val;
    struct QueueNode* next;
}QNode;
//����ͷβָ��ṹ��
typedef struct {
    QNode* head;
    QNode* tail;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    //ʹ�������ȿ�һ��ռ�����ָ��Ľṹ��
    MyCircularQueue* pq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    assert(pq);
    //��head��tail��ʼ��ΪNULL�������ʼ������Ȼ����û�취����
    pq->head = pq->tail = NULL;
    //����k+1���ռ�Ľ��
    int num = k + 1;
    while (num--)
    {
        QNode* newnode = (QNode*)malloc(sizeof(QNode));
        assert(newnode);
        newnode->next = NULL;
        //��head��tail��ָ���һ�����
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

    //�����һ��λ�õ�nextָ���һ����ѭ��
    pq->tail->next = pq->head;

    //��βָ���ûص�һ��λ��
    pq->tail = pq->head;

    return pq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);
    //���˾Ͳ����ٲ���
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
    //�յĲ���ɾ��
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }

    obj->head = obj->head->next;

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    assert(obj);
    //�յķ���-1
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }

    return obj->head->val;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    assert(obj);
    //�յķ���-1
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }

    //tailָ�����һ�����ݵĺ����λ�ã�����Ҫ����һ������ҵ����һ������
    QNode* cur = obj->head;
    while (cur->next != obj->tail)
    {
        cur = cur->next;
    }

    return cur->val;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);
    //������Ⱦ�˵��Ϊ��
    return obj->head == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);
    //��tail��next����head˵������
    return obj->head == obj->tail->next;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    assert(obj);
    //�Ƚ��������
    QNode* cur = obj->head;
    while (cur->next != obj->head)
    {
        QNode* next = cur->next;
        free(cur);
        cur = next;
    }
    free(cur);
    cur = obj->tail = NULL;
    //�ٽ���ͷβָ��Ľṹ������
    free(obj);
    obj = NULL;
}