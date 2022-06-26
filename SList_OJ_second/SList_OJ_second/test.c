#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//�����е�����k�����
//��Ŀ���ӣ�https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking




/*
    ˼·��
    ���ÿ���ָ�����������ÿ�ָ������k����Ȼ������һ����
    ����ָ��Ϊ��ʱ����ָ���ʱ����λ�ü��ǵ�����k�����
    ��Ҫע������Ϊ�յ�ʱ���k��ֵ���������ȵ�ʱ��
    ����ָ��Ϊ�յ����
*/



 /**
  *
  * @param pListHead ListNode��
  * @param k int����
  * @return ListNode��
  */
struct ListNode
{
    int val;
    struct ListNode* next;
};
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    //����������ָ��
    struct ListNode* slow = pListHead;
    struct ListNode* fast = pListHead;
    //���ÿ�ָ����k��
    while (k--)
    {
        //������Ϊ�յ�ʱ�����k��ֵ���������ȵ�ʱ��
        if (fast == NULL)
        {
            return NULL;
        }

        fast = fast->next;
    }
    //����ͬ����
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    //���ص�����k�����
    return slow;
}