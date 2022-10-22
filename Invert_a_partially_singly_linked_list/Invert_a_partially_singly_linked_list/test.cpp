#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
using namespace std;

struct list_node {
    int val;
    struct list_node* next;
};

list_node* input_list(void)
{
    int n, val;
    list_node* phead = new list_node();
    list_node* cur_pnode = phead;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node* new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}


list_node* reverse_list(list_node* head, int L, int R)
{
    //������Ϊ��ʱ��L����Rʱ����Ҫ��ת
    if (head == nullptr || L == R)
        return head;
    //�ֱ��¼ͷ����ǰ��β��λ��
    list_node* prev = nullptr;
    list_node* cur = head;
    list_node* next = cur->next;
    //������¼L��λ��
    list_node* first = head;
    //L����1ʱ
    if (L > 1)
    {
        //�ߵ�L��ǰһ��λ��
        for (int i = 0; i < L - 2; ++i)
        {
            cur = cur->next;
        }
        //��¼L��ǰһ��λ��
        list_node* ffirst = cur;
        //����������һ��λ�õ�L
        cur = cur->next;
        //��¼��L��λ��
        first = cur;
        //��Lλ�ÿ�ʼ��ת����prev�ߵ�L��λ����
        prev = cur;
        //cur�ߵ�L����һ��λ��
        cur = cur->next;
        //����ѭ����ֻ��ҪR-L��
        for (int i = 0; i < R - L; ++i)
        {
            //���õ�ǰ���
            next = cur->next;
            cur->next = prev;
            prev = cur;
            //ע����ܻ��ߵ������β
            if (cur != nullptr)
                cur = next;
        }
        //��L��λ��nextָ��R����һ��λ��
        first->next = cur;
        //��L��һ��λ�õ�nextָ��R��
        ffirst->next = prev;
    }
    //��L==1ʱ
    else
    {
        //��¼��L��λ��
        first = cur;
        //��Lλ�ÿ�ʼ��ת����prev�ߵ�L��λ����
        prev = cur;
        //cur�ߵ�L����һ��λ��
        cur = cur->next;
        //����ѭ����ֻ��ҪR-L��
        for (int i = 0; i < R - L; ++i)
        {
            //���õ�ǰ���
            next = cur->next;
            cur->next = prev;
            prev = cur;
            //ע����ܻ��ߵ������β
            if (cur != nullptr)
                cur = next;
        }
        //��L��λ��nextָ��R����һ��λ��
        first->next = cur;
        //��L����1ʱ��Ҫ����head
        head = prev;
    }
    //����ͷ���
    return head;
}

void print_list(list_node* head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}


int main()
{
    int L, R;
    list_node* head = input_list();
    scanf("%d%d", &L, &R);
    list_node* new_head = reverse_list(head, L, R);
    print_list(new_head);
    return 0;
}