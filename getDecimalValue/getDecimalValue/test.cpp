#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* cur = head;
        int res = 0;
        while (cur != nullptr)
        {
            res = res * 2 + cur->val;//不断*2，不管余数在哪，只需要加上余数即可，无论是从前*2函数从后都是一样的结果！
            cur = cur->next;
        }
        return res;
    }
};
/*
    被除数 = 商 * 除数 + 余数
    将商除至0
    5 / 2 = 2余1
    2 / 2 = 1余0
    1 / 2 = 0余1
*/