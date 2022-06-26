#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//回文链表
//题目连接：https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking

/*
	思路：
	回文是指从前往后读和从后往前读都一致，所以
	先通过快慢指针找到中间结点，再逆置中间结点往后的结点
	此时便只要比较第一个结点和中间结点开始往后的结点比较，相等即回文
	因为逆置前中间结点之前的结点在逆置后仍指向该中间结点
	所以最后两部分都指向了逆置前的中间结点，也就是说，最后就变成了链表的相交
*/


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class PalindromeList {
public:

    //使用快慢指针查找中间结点
    struct ListNode* Mid(struct ListNode* A)
    {
        struct ListNode* fast = A;
        struct ListNode* slow = A;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    //逆置中间往后的结点
    struct ListNode* Reverse(struct ListNode* mid)
    {
        struct ListNode* cur, * next, * prev;
        prev = NULL;
        cur = mid;
        next = cur->next;
        while (cur)
        {
            cur->next = prev;
            prev = cur;
            cur = next;
            if (next)
            {
                next = next->next;
            }
        }
        return prev;
    }

    //检查是否是回文链表
    bool chkPalindrome(ListNode* A) {
        
        //调用寻找中间结点的函数
        struct ListNode* mid = Mid(A);
        //调用逆置函数
        struct ListNode* prev = Reverse(mid);
        while (A && prev)
        {
            if (A->val == prev->val)
            {
                A = A->next;
                prev = prev->next;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};