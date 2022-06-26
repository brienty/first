#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//���ƴ����ָ�������
//��Ŀ���ӣ�https://leetcode-cn.com/problems/copy-list-with-random-pointer


/*
    ˼·��
    �������Ǹ���������������random���ָ��Ƚ��Ѵ���
    
    ����ԭ����ĺ��洴����ǰһ��һģһ����㲢����������ԭ����
    
    Ȼ����������random���ָ�룬��Ϊ�´�������������ԭ������ĺ���
    �����½��������randomָ�����ԭ������random����һ������ͼ������

    ����ٽ��½��������������ԭ������������
*/



struct Node {
    int val;
    struct Node* next;
    struct Node* random;
    
};

struct Node* copyRandomList(struct Node* head) {
    //������β��ʱ��ֱ�ӷ��ؿ�
    if (head == NULL)
        return NULL;

    //ʹ��cur����
    struct Node* cur = head;

    //���½��������ԭ��������
    while (cur)
    {
        struct Node* next = cur->next;
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));

        cur->next = newnode;
        newnode->next = next;
        newnode->val = cur->val;

        cur = next;
    }

    //���±���ָ��
    cur = head;

    //����random
    while (cur)
    {
        struct Node* copy = cur->next;

        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            //���������randomӦ��ָ��ԭ���������
            copy->random = cur->random->next;
        }

        cur = cur->next->next;
    }

    //���±���ָ��
    cur = head;

    //����ͷָ��
    struct Node* copyhead = cur->next;

    //�����������������ԭ�������ӻ�ȥ
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;

        cur->next = next;

        //����Ҫע��nextΪ�յ����
        if (next)
            copy->next = next->next;
        else
            copy->next = NULL;

        cur = next;
    }

    //����ͷ���
    return copyhead;
}