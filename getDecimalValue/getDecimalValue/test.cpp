#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* cur = head;
        int res = 0;
        while (cur != nullptr)
        {
            res = res * 2 + cur->val;//����*2�������������ģ�ֻ��Ҫ�����������ɣ������Ǵ�ǰ*2�����Ӻ���һ���Ľ����
            cur = cur->next;
        }
        return res;
    }
};
/*
    ������ = �� * ���� + ����
    ���̳���0
    5 / 2 = 2��1
    2 / 2 = 1��0
    1 / 2 = 0��1
*/