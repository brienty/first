#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

//��״����
//�ж������Ƿ��л�
//��Ŀ���ӣ�https://leetcode-cn.com/problems/linked-list-cycle

/*
	˼·��
	���ÿ���ָ����������fast��������slow��һ��
	�����и�ϸ�ڣ�����������л����ͻ����һ�������
	fast����slow����Ϊfast�ߵ�·����slow������������л�����һ��������ȵ�ʱ��
	ֻ�ǻ��߼�Ȧ�����⣬��Ϊ����֮ǰ�ľ��������ѭ���𲽼�һ��
*/


struct ListNode 
{
    int val;
    struct ListNode* next;
    
};

bool hasCycle(struct ListNode* head) {
    //���ÿ���ָ������
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    //����ָ�����NULL����next->next����NULL��˵��û�л�
    while (fast && fast->next)
    {
        //fast��slow������·��
        slow = slow->next;
        fast = fast->next->next;

        /*������fast����slow��˵���л�����׷����
          ��Ϊ������ڻ�������fast���ߵ�slow������·�̣�һ����׷��
        */
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}