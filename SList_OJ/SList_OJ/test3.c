#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//������м���
//��Ŀ���ӣ�https://leetcode-cn.com/problems/middle-of-the-linked-list



/*
     ˼·�����ÿ���ָ������
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
      ������Ҫע�⣺
      �����������жϣ���Ϊ������Ϊ������ʱ��
      fastָֻ�����һ�����
      ������Ϊż����ʱ��fastָ�����Ӧ�ý���next
      fast������fast->next֮ǰ
      ��Ϊ��fastΪ��ʱ���������ж�fast->next
      ����fast�Ѿ�Ϊ�գ������ǷǷ�����
      ��fast��ǰ���ж�fast������û��ϵ
    */
    while (fast && fast->next)
    {
        //slowһ���ƶ�һ��
        slow = slow->next;
        //fastһ���ƶ�����
        fast = fast->next->next;
    }
    return slow;
}
