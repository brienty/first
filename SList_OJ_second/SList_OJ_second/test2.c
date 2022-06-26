#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//�ϲ�������������
//��Ŀ���ӣ�https://leetcode-cn.com/problems/merge-two-sorted-lists

/*
	˼·��
	ʹ��ͷβ����ָ�룬ͷָ�뱣���һ������λ�ã�βָ�븺�����
	���ǣ�����Ҫע�⵱����һ������Ϊ��ʱ����Ҫ�������ۣ�����һ������ֱ�ӷ���
	�Լ�������һ�������ȳ�����һ�������ʱ��ҲҪ��������
*/



struct ListNode {
	int val;
	struct ListNode* next;
};
//������ͷ����������Ҫ�ж���������Ϊ�յ����
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    
    //������һ������Ϊ��ʱ
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    
    while (list1 && list2)
    {
        //list1С��list2
        if (list1->val < list2->val)
        {
            //��tailΪ��ʱ��˵�������ҵ�һ��ͷ���
            if (tail == NULL)
            {
                head = tail = list1;
            }
            //�ƶ�����
            else
            {
                tail->next = list1;
                tail = list1;
            }
            list1 = list1->next;
        }
        //list1���ڵ���list2
        else
        {
            //��tailΪ��ʱ��˵�������ҵ�һ��ͷ���
            if (tail == NULL)
            {
                head = tail = list2;
            }
            //�ƶ�����
            else
            {
                tail->next = list2;
                tail = list2;
            }
            list2 = list2->next;
        }
    }

    //��list1����list2���н��ʱ
    while (list1)
    {
        tail->next = list1;
        tail = list1;
        list1 = list1->next;
    }
    while (list2)
    {
        tail->next = list2;
        tail = list2;
        list2 = list2->next;
    }

    //����ͷ���
    return head;
}

//���ڱ�����ͷ�����ﲻ��Ҫ�ж���������Ϊ�յ��������ͼ����֪��
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
   
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    
    //�����ڱ�����ͷ���
    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    tail->next = NULL;

    while (list1 && list2)
    {
        //list1��valС��list2��val
        if (list1->val < list2->val)
        {
            tail->next = list1;
            tail = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            tail = list2;
            list2 = list2->next;
        }
    }
    //������һ�������ȳ�����һ��������ʱ
    while (list1)
    {
        tail->next = list1;
        tail = list1;
        list1 = list1->next;
    }
    while (list2)
    {
        tail->next = list2;
        tail = list2;
        list2 = list2->next;
    }

    //Ӧ�÷���next����Ϊhead�ǲ������ݵģ����ǿ��ٵĿռ�Ҫ�ͷ�
    struct ListNode* temp = head->next;
    free(head);
    head = NULL;


    return temp;
}