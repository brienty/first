#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//反转链表
//题目链接：https://leetcode-cn.com/problems/reverse-linked-list

/*
    思路：
    采用三指针做法，直接让后面的指针往前指
    需要注意空链表和next为空的情况
*/



struct ListNode 
{
    int val;
    struct ListNode* next;
};
struct ListNode* reverseList(struct ListNode* head) {
    //空链表直接返回空
    if (head == NULL)
        return NULL;
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    //这里next被赋值为cur->next比head->next好，后面链接需要
    struct ListNode* next = cur->next;
    while (cur)
    {
        cur->next = prev;
        prev = cur;
        cur = next;
        //当next为空的时候
        if (next)
            next = next->next;
    }
    //返回头结点
    return prev;
}