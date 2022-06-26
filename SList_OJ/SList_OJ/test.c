#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//�Ƴ�����Ԫ��
//��Ŀ���ӣ�https://leetcode-cn.com/problems/remove-linked-list-elements

/*
    ˼·��
    ʹ��˫ָ�룬����val��ɾ��������Ҫע���һ������ȫ��Ϊval�����
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
        //����valʱ��ɾ��
        if (cur->val == val)
        {
            //��prev��ΪNULLʱ
            if (prev)
            {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
            //��prevΪ��ʱ��˵����һ������val����ʱ��Ҫhead��������prev
            else
            {
                head = cur->next;
                free(cur);
                cur = head;
            }

        }
        //������valʱ������
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    //����ͷ���
    return head;
}