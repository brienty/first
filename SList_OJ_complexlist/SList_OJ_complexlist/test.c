#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//复制带随机指针的链表
//题目链接：https://leetcode-cn.com/problems/copy-list-with-random-pointer


/*
    思路：
    本质上是复制链表，但是里面random随机指针比较难处理
    
    先在原链表的后面创建和前一个一模一样结点并将其连接入原链表
    
    然后再来处理random随机指针，因为新创建的链表结点在原链表结点的后面
    所以新建链表结点的random指向就是原链表结点random的下一个，画图最好理解

    最后再将新建链表解下来并把原来的链表连接
*/



struct Node {
    int val;
    struct Node* next;
    struct Node* random;
    
};

struct Node* copyRandomList(struct Node* head) {
    //当链表尾空时，直接返回空
    if (head == NULL)
        return NULL;

    //使用cur遍历
    struct Node* cur = head;

    //将新建的链表和原链表连接
    while (cur)
    {
        struct Node* next = cur->next;
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));

        cur->next = newnode;
        newnode->next = next;
        newnode->val = cur->val;

        cur = next;
    }

    //更新遍历指针
    cur = head;

    //拷贝random
    while (cur)
    {
        struct Node* copy = cur->next;

        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            //新链表结点的random应该指向原链表结点后面
            copy->random = cur->random->next;
        }

        cur = cur->next->next;
    }

    //更新遍历指针
    cur = head;

    //返回头指针
    struct Node* copyhead = cur->next;

    //将新链表解下来，让原链表连接回去
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;

        cur->next = next;

        //这里要注意next为空的情况
        if (next)
            copy->next = next->next;
        else
            copy->next = NULL;

        cur = next;
    }

    //返回头结点
    return copyhead;
}