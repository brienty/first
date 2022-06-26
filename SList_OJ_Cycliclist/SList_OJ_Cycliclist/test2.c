#define _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>

//��״����
//��Ҫ�����뻷����ڵ�
//��Ŀ���ӣ�https://leetcode-cn.com/problems/linked-list-cycle-ii


/*
	˼·��
    ʹ�ÿ���ָ��
	��������������
	һ���ǲ��ù�ʽ�����������ַ�����Ҫ֪�������ܹ��ƶϳ���ʽ
	��һ���ǽ���ת�����󽻵�����
*/
/*
    ��չ׷�ʣ�������ָ���ڵ��򲻴�ͷ��ѭ�������е�Ӧ�ã�
    ��slowһ����һ����fastһ����������һ����׷����
    ��һ���ܣ���slow�����뻷�ڣ�����fast�ڻ������˼�Ȧ����ʲôλ��
    slow�����Ժ�fast��ʼ׷��slow���������ǵľ�������һ���ľ����𽥼�С
    ������֮��ľ�����ٵ�����0��ʱ�򣬾���׷���ϣ���Ϊfast����slow�������ٶ�׷��slow
    ����һȦ֮�ڵľ������׷��

    ��slowһ����һ����fastһ�������������Ĳ�����n���أ�
    �𣺲�һ��
    ��slow��������ڴ�����fast����slow�ľ���ΪN���軷�ĳ���ΪC

    �ڵ�һ��׷�������У����N��ż��������׷���ϵģ���Ϊ���ߵľ����Բ�ֵΪ2�ڲ��ϼ�С������ֵΪ0��׷����
    �ڵ�һ��׷�����̣����N��������fast�ͻᳬ��slow�������п��ܳ���һ��Ҳ�п��ܳ�������
    
    ������һ�������еڶ���׷��ʱ�����ߵľ���N�ͱ����C-1
    ��C-1Ϊ����ʱ����Ϊfast��slow�ľ����Բ�ֵΪ2���ϼ��٣����Ǻ����ڶ���׷���ֻ���fast����slowһ��
    ֱ��n��Ҳ����ˣ�������������ǲ�����׷�ϵ�
    ��C-1Ϊż��ʱ����Ϊfast��slow�ľ����Բ�ֵΪ2���ϼ��٣�������׷��
    
    ���������������еڶ���׷��ʱ�����ߵľ���N�ͱ��C-2
    ��C-2Ϊż������Ϊfast��slow�ľ����Բ�ֵΪ2���ϼ��٣�������׷��
    ��C-2Ϊ����ʱ����Ϊfast��slow�ľ����Բ�ֵΪ2���ϼ��٣�����fast�ͻᳬ��slowһ��
    ��ͻ���е����ε�׷���������ֱ����C-1�������

    ����ͬ��n��Ҳ������
*/


struct ListNode 
{
    int val;
    struct ListNode* next;
    
};

//��ʽ��
struct ListNode* detectCycle(struct ListNode* head) {
   
    //�ȴ�����������ָ��
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    //������ע���������Ƿ�ż������
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        //������ʱ���ж�
        if (fast == slow)
        {
            /*
                ���ù�ʽ��
                L + X = N*C
                head��ʼ��ΪL+X��fast��ʼ��ΪN*C
                �����������ʱ����������ѭ��������ע�⣬һ�������
            */
            while (head != fast)
            {
                head = head->next;
                fast = fast->next;
            }
            //�����뻷�ĵ�һ�����
            return head;
        }
    }

    //û�л��Ż��ߵ���
    return NULL;
}

//�ҽ��㷨
struct ListNode* detectCycle(struct ListNode* head) {

    struct ListNode* fast = head;
    struct ListNode* slow = head;

    //������ע���������Ƿ�ż������
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        //������ʱ���ҽ���
        if (fast == slow)
        {
            //��fast��fast->next�Ͽ�
            struct ListNode* headtemp = fast->next;
            fast->next = NULL;

            //��¼����
            int lenA = 0;
            int lenB = 0;

            //��������ָ��
            struct ListNode* headA = head;
            struct ListNode* headB = headtemp;

            //�����������ĳ���
            while (headA)
            {
                headA = headA->next;
                lenA++;
            }
            while (headB)
            {
                headB = headB->next;
                lenB++;
            }

            //�������ȵĲ�ֵ
            int gap = abs(lenA - lenB);

            //�ó������߲�ֵ��
            if (lenA > lenB)
            {
                while (gap--)
                {
                    head = head->next;
                }
            }
            else
            {
                while (gap--)
                {
                    headtemp = headtemp->next;
                }
            }

            //�ҽ���
            while (head != headtemp)
            {
                headtemp = headtemp->next;
                head = head->next;
            }

            //�ҵ����㲢����
            return head;
        }
    }

    //�Ҳ�������˵��û�л�
    return NULL;

}
