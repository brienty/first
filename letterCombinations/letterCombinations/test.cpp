#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //存储字符串
    string _digits[10] = { " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
    void Combine(string digits, int i, string combine_str, vector<string>& ret)
    {
        //当i等于数字字符串元素个数时则返回
        if (i == digits.size())
        {
            ret.push_back(combine_str);
            return;
        }

        //取出数字字符串中数字并转化为数字
        int num = digits[i] - '0';
        //将数字所映射的字符串存储
        string ret_str = _digits[num];

        //遍历数字所映射的字符串
        for (auto ch : ret_str)
        {
            //传的数字是数字字符串里数字的下一个数字，不使用加等是不改变combine_str，防止combine_str不断加长
            Combine(digits, i + 1, combine_str + ch, ret);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        //空字符串则直接返回
        if (digits.empty())
        {
            return ret;
        }
        int i = 0;
        string combine_str;
        //递归
        Combine(digits, i, combine_str, ret);
        return ret;
    }
};