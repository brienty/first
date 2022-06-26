#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


// 链表分割
//题目链接：https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking



/*
    思路：
    将小于x的放在一个新链表中，将大于x的放在另一个新的链表中
    然后最后将两个链表连接起来，但是值得注意的是
    一个是成环的情况，一个是链表为空的情况
*/


struct ListNode 
{
	int val;
	struct ListNode* next;
};

//不带哨兵卫的头结点
struct ListNode* test(struct ListNode* pHead, int x)
{
    //创建四个指针，用来操作新的两个链表
    struct ListNode* head1, * head2, * tail1, * tail2;
    //初始化为空
    head1 = head2 = tail1 = tail2 = NULL;
    while (pHead)
    {
        if (pHead->val < x)
        {
            //一开始没有结点，先赋结点
            if (tail1 == NULL)
            {
                head1 = tail1 = pHead;
            }
            //有结点以后才往后放
            else
            {
                tail1->next = pHead;
                tail1 = tail1->next;
            }
        }
        //与上面同理
        else
        {
            if (tail2 == NULL)
            {
                head2 = tail2 = pHead;
            }
            else
            {
                tail2->next = pHead;
                tail2 = tail2->next;
            }
        }
        //pHead往后移动
        pHead = pHead->next;
    }

    //当其中一个链表为空的时候，直接返回另一个链表，当然了，哪怕两个都是空，随便返回哪一个都一样
    if (tail1 == NULL)
    {
        return head2;
    }
    if (tail2 == NULL)
    {
        return head1;
    }

    //当两个链表都不为空的时候就需要连接
    tail1->next = head2;
    /*
        这里需要注意一定要置空，否则，当最后一个结点小于x而倒数第二个结点大于x时，就会成环
        因为当最后一个结点小于x，而前一个结点大于x，就会出现
        前一个结点在tail2，最后一个结点在tail1，而倒数第二个结点的next还指着最后一个结点
        如果不置空，就成环了，画图最好理解
    */
    tail2->next = NULL;

    return head1;
}


//带哨兵卫的头结点
struct ListNode* partition(struct ListNode* pHead, int x) {
    // write code here
    
    //定义四个指针用来遍历新的两个链表和存放链表的头结点
    struct ListNode* lesstail, * lesshead, * greatertail, * greaterhead;

    //创建哨兵卫的头结点
    lesstail = lesshead = (struct ListNode*)malloc(sizeof(struct ListNode));
    greatertail = greaterhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    //将next置空
    lesstail->next = greatertail->next = NULL;
    
    //创建一个指针用来遍历原链表
    struct ListNode* cur = pHead;
    
    //遍历原链表
    while (cur)
    {
        if (cur->val < x)
        {
            lesstail->next = cur;
            lesstail = lesstail->next;
        }
        else
        {
            greatertail->next = cur;
            greatertail = greatertail->next;
        }
        cur = cur->next;
    }

    //连接两个链表
    lesstail->next = greaterhead->next;
    
    /*
        这里需要注意一定要置空，否则，当最后一个结点小于x而倒数第二个结点大于x时，就会成环
        因为当最后一个结点小于x，而前一个结点大于x，就会出现
        前一个结点在tail2，最后一个结点在tail1，而倒数第二个结点的next还指着最后一个结点
        如果不置空，就成环了，画图最好理解
    */
    greatertail->next = NULL;
    
    //存放将要被返回的结点
    struct ListNode* temp = lesshead->next;
    
    //将动态开辟的空间释放
    free(lesshead);
    free(greaterhead);

    return temp;
}