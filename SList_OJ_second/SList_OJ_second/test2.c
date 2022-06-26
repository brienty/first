#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//合并两个有序链表
//题目链接：https://leetcode-cn.com/problems/merge-two-sorted-lists

/*
	思路：
	使用头尾两个指针，头指针保存第一个结点的位置，尾指针负责遍历
	但是，这里要注意当其中一个链表为空时，需要单独讨论，将另一个链表直接返回
	以及当其中一个链表长度长于另一个链表的时候，也要单独讨论
*/



struct ListNode {
	int val;
	struct ListNode* next;
};
//采用无头的做法，需要判断两个链表为空的情况
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    
    //当其中一个链表为空时
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    
    while (list1 && list2)
    {
        //list1小于list2
        if (list1->val < list2->val)
        {
            //当tail为空时，说明还在找第一个头结点
            if (tail == NULL)
            {
                head = tail = list1;
            }
            //移动链表
            else
            {
                tail->next = list1;
                tail = list1;
            }
            list1 = list1->next;
        }
        //list1大于等于list2
        else
        {
            //当tail为空时，说明还在找第一个头结点
            if (tail == NULL)
            {
                head = tail = list2;
            }
            //移动链表
            else
            {
                tail->next = list2;
                tail = list2;
            }
            list2 = list2->next;
        }
    }

    //当list1或者list2还有结点时
    while (list1)
    {
        tail->next = list1;
        tail = list1;
        list1 = list1->next;
    }
    while (list2)
    {
        tail->next = list2;
        tail = list2;
        list2 = list2->next;
    }

    //返回头结点
    return head;
}

//有哨兵卫的头，这里不需要判断两个链表为空的情况，画图即可知道
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
   
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    
    //创建哨兵卫的头结点
    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    tail->next = NULL;

    while (list1 && list2)
    {
        //list1的val小于list2的val
        if (list1->val < list2->val)
        {
            tail->next = list1;
            tail = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            tail = list2;
            list2 = list2->next;
        }
    }
    //当其中一个链表长度长于另一个链表长度时
    while (list1)
    {
        tail->next = list1;
        tail = list1;
        list1 = list1->next;
    }
    while (list2)
    {
        tail->next = list2;
        tail = list2;
        list2 = list2->next;
    }

    //应该返回next，因为head是不存数据的，但是开辟的空间要释放
    struct ListNode* temp = head->next;
    free(head);
    head = NULL;


    return temp;
}