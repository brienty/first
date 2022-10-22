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
    //当链表为空时和L等于R时不需要翻转
    if (head == nullptr || L == R)
        return head;
    //分别记录头，当前，尾的位置
    list_node* prev = nullptr;
    list_node* cur = head;
    list_node* next = cur->next;
    //用来记录L的位置
    list_node* first = head;
    //L大于1时
    if (L > 1)
    {
        //走到L的前一个位置
        for (int i = 0; i < L - 2; ++i)
        {
            cur = cur->next;
        }
        //记录L的前一个位置
        list_node* ffirst = cur;
        //继续往后走一个位置到L
        cur = cur->next;
        //记录下L的位置
        first = cur;
        //从L位置开始翻转，让prev走到L的位置上
        prev = cur;
        //cur走到L的下一个位置
        cur = cur->next;
        //进入循环，只需要R-L次
        for (int i = 0; i < R - L; ++i)
        {
            //逆置当前结点
            next = cur->next;
            cur->next = prev;
            prev = cur;
            //注意可能会走到链表结尾
            if (cur != nullptr)
                cur = next;
        }
        //把L的位置next指到R的下一个位置
        first->next = cur;
        //把L上一个位置的next指向R处
        ffirst->next = prev;
    }
    //当L==1时
    else
    {
        //记录下L的位置
        first = cur;
        //从L位置开始翻转，让prev走到L的位置上
        prev = cur;
        //cur走到L的下一个位置
        cur = cur->next;
        //进入循环，只需要R-L次
        for (int i = 0; i < R - L; ++i)
        {
            //逆置当前结点
            next = cur->next;
            cur->next = prev;
            prev = cur;
            //注意可能会走到链表结尾
            if (cur != nullptr)
                cur = next;
        }
        //把L的位置next指到R的下一个位置
        first->next = cur;
        //当L等于1时需要更新head
        head = prev;
    }
    //返回头结点
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