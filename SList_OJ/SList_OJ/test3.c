#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//链表的中间结点
//题目链接：https://leetcode-cn.com/problems/middle-of-the-linked-list



/*
     思路：采用快慢指针做法
*/

struct ListNode 
{
     int val;
     struct ListNode *next;
};
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    /*
      这里需要注意：
      必须有两个判断，因为结点个数为奇数的时候
      fast只指向最后一个结点
      结点个数为偶数的时候，fast指向最后应该结点的next
      fast必须在fast->next之前
      因为当fast为空时，由于先判断fast->next
      但是fast已经为空，所以是非法访问
      而fast在前先判断fast，所以没关系
    */
    while (fast && fast->next)
    {
        //slow一次移动一步
        slow = slow->next;
        //fast一次移动两步
        fast = fast->next->next;
    }
    return slow;
}
