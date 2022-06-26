#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//移除链表元素
//题目链接：https://leetcode-cn.com/problems/remove-linked-list-elements

/*
    思路：
    使用双指针，将是val的删除，但是要注意第一个或者全部为val的情况
*/



struct ListNode 
{
    int val;
    struct ListNode* next;
};
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        //等于val时，删除
        if (cur->val == val)
        {
            //当prev不为NULL时
            if (prev)
            {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
            //当prev为空时，说明第一个就是val，此时需要head动而不是prev
            else
            {
                head = cur->next;
                free(cur);
                cur = head;
            }

        }
        //不等于val时往下走
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    //返回头结点
    return head;
}