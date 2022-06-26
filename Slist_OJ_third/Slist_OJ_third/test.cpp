#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//��������
//��Ŀ���ӣ�https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking

/*
	˼·��
	������ָ��ǰ������ʹӺ���ǰ����һ�£�����
	��ͨ������ָ���ҵ��м��㣬�������м�������Ľ��
	��ʱ��ֻҪ�Ƚϵ�һ�������м��㿪ʼ����Ľ��Ƚϣ���ȼ�����
	��Ϊ����ǰ�м���֮ǰ�Ľ�������ú���ָ����м���
	������������ֶ�ָ��������ǰ���м��㣬Ҳ����˵�����ͱ����������ཻ
*/


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class PalindromeList {
public:

    //ʹ�ÿ���ָ������м���
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

    //�����м�����Ľ��
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

    //����Ƿ��ǻ�������
    bool chkPalindrome(ListNode* A) {
        
        //����Ѱ���м���ĺ���
        struct ListNode* mid = Mid(A);
        //�������ú���
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