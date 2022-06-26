#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

//环状链表
//判断链表是否有环
//题目链接：https://leetcode-cn.com/problems/linked-list-cycle

/*
	思路：
	采用快慢指针做法，让fast走两步，slow走一步
	这里有个细节，如果链表里有环，就会出现一种情况，
	fast等于slow，因为fast走的路程是slow的两倍，如果有环，就一定会有相等的时候
	只是会走几圈的问题，因为他们之前的距离会随着循环逐步减一！
*/


struct ListNode 
{
    int val;
    struct ListNode* next;
    
};

bool hasCycle(struct ListNode* head) {
    //采用快慢指针做法
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    //当快指针等于NULL或者next->next等于NULL，说明没有环
    while (fast && fast->next)
    {
        //fast走slow的两倍路程
        slow = slow->next;
        fast = fast->next->next;

        /*当出现fast等于slow，说明有环，且追上了
          因为如果存在环，由于fast是走的slow的两倍路程，一定能追上
        */
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}