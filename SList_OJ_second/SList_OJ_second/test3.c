#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


// ����ָ�
//��Ŀ���ӣ�https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking



/*
    ˼·��
    ��С��x�ķ���һ���������У�������x�ķ�����һ���µ�������
    Ȼ���������������������������ֵ��ע�����
    һ���ǳɻ��������һ��������Ϊ�յ����
*/


struct ListNode 
{
	int val;
	struct ListNode* next;
};

//�����ڱ�����ͷ���
struct ListNode* test(struct ListNode* pHead, int x)
{
    //�����ĸ�ָ�룬���������µ���������
    struct ListNode* head1, * head2, * tail1, * tail2;
    //��ʼ��Ϊ��
    head1 = head2 = tail1 = tail2 = NULL;
    while (pHead)
    {
        if (pHead->val < x)
        {
            //һ��ʼû�н�㣬�ȸ����
            if (tail1 == NULL)
            {
                head1 = tail1 = pHead;
            }
            //�н���Ժ�������
            else
            {
                tail1->next = pHead;
                tail1 = tail1->next;
            }
        }
        //������ͬ��
        else
        {
            if (tail2 == NULL)
            {
                head2 = tail2 = pHead;
            }
            else
            {
                tail2->next = pHead;
                tail2 = tail2->next;
            }
        }
        //pHead�����ƶ�
        pHead = pHead->next;
    }

    //������һ������Ϊ�յ�ʱ��ֱ�ӷ�����һ��������Ȼ�ˣ������������ǿգ���㷵����һ����һ��
    if (tail1 == NULL)
    {
        return head2;
    }
    if (tail2 == NULL)
    {
        return head1;
    }

    //������������Ϊ�յ�ʱ�����Ҫ����
    tail1->next = head2;
    /*
        ������Ҫע��һ��Ҫ�ÿգ����򣬵����һ�����С��x�������ڶ���������xʱ���ͻ�ɻ�
        ��Ϊ�����һ�����С��x����ǰһ��������x���ͻ����
        ǰһ�������tail2�����һ�������tail1���������ڶ�������next��ָ�����һ�����
        ������ÿգ��ͳɻ��ˣ���ͼ������
    */
    tail2->next = NULL;

    return head1;
}


//���ڱ�����ͷ���
struct ListNode* partition(struct ListNode* pHead, int x) {
    // write code here
    
    //�����ĸ�ָ�����������µ���������ʹ�������ͷ���
    struct ListNode* lesstail, * lesshead, * greatertail, * greaterhead;

    //�����ڱ�����ͷ���
    lesstail = lesshead = (struct ListNode*)malloc(sizeof(struct ListNode));
    greatertail = greaterhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    //��next�ÿ�
    lesstail->next = greatertail->next = NULL;
    
    //����һ��ָ����������ԭ����
    struct ListNode* cur = pHead;
    
    //����ԭ����
    while (cur)
    {
        if (cur->val < x)
        {
            lesstail->next = cur;
            lesstail = lesstail->next;
        }
        else
        {
            greatertail->next = cur;
            greatertail = greatertail->next;
        }
        cur = cur->next;
    }

    //������������
    lesstail->next = greaterhead->next;
    
    /*
        ������Ҫע��һ��Ҫ�ÿգ����򣬵����һ�����С��x�������ڶ���������xʱ���ͻ�ɻ�
        ��Ϊ�����һ�����С��x����ǰһ��������x���ͻ����
        ǰһ�������tail2�����һ�������tail1���������ڶ�������next��ָ�����һ�����
        ������ÿգ��ͳɻ��ˣ���ͼ������
    */
    greatertail->next = NULL;
    
    //��Ž�Ҫ�����صĽ��
    struct ListNode* temp = lesshead->next;
    
    //����̬���ٵĿռ��ͷ�
    free(lesshead);
    free(greaterhead);

    return temp;
}