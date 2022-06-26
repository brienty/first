#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//��ת����
//��Ŀ���ӣ�https://leetcode-cn.com/problems/reverse-linked-list

/*
    ˼·��
    ������ָ��������ֱ���ú����ָ����ǰָ
    ��Ҫע��������nextΪ�յ����
*/



struct ListNode 
{
    int val;
    struct ListNode* next;
};
struct ListNode* reverseList(struct ListNode* head) {
    //������ֱ�ӷ��ؿ�
    if (head == NULL)
        return NULL;
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    //����next����ֵΪcur->next��head->next�ã�����������Ҫ
    struct ListNode* next = cur->next;
    while (cur)
    {
        cur->next = prev;
        prev = cur;
        cur = next;
        //��nextΪ�յ�ʱ��
        if (next)
            next = next->next;
    }
    //����ͷ���
    return prev;
}