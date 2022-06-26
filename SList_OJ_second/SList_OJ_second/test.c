#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//链表中倒数第k个结点
//题目链接：https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking




/*
    思路：
    采用快慢指针做法，先让快指针先走k步，然后两个一起走
    当快指针为空时，慢指针此时所在位置即是倒数第k个结点
    需要注意链表为空的时候和k的值大于链表长度的时候
    即快指针为空的情况
*/



 /**
  *
  * @param pListHead ListNode类
  * @param k int整型
  * @return ListNode类
  */
struct ListNode
{
    int val;
    struct ListNode* next;
};
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    //定义两个快指针
    struct ListNode* slow = pListHead;
    struct ListNode* fast = pListHead;
    //先让快指针走k步
    while (k--)
    {
        //当链表为空的时候或者k的值大于链表长度的时候
        if (fast == NULL)
        {
            return NULL;
        }

        fast = fast->next;
    }
    //两个同步走
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    //返回倒数第k个结点
    return slow;
}