#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //�洢�ַ���
    string _digits[10] = { " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
    void Combine(string digits, int i, string combine_str, vector<string>& ret)
    {
        //��i���������ַ���Ԫ�ظ���ʱ�򷵻�
        if (i == digits.size())
        {
            ret.push_back(combine_str);
            return;
        }

        //ȡ�������ַ��������ֲ�ת��Ϊ����
        int num = digits[i] - '0';
        //��������ӳ����ַ����洢
        string ret_str = _digits[num];

        //����������ӳ����ַ���
        for (auto ch : ret_str)
        {
            //���������������ַ��������ֵ���һ�����֣���ʹ�üӵ��ǲ��ı�combine_str����ֹcombine_str���ϼӳ�
            Combine(digits, i + 1, combine_str + ch, ret);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        //���ַ�����ֱ�ӷ���
        if (digits.empty())
        {
            return ret;
        }
        int i = 0;
        string combine_str;
        //�ݹ�
        Combine(digits, i, combine_str, ret);
        return ret;
    }
};