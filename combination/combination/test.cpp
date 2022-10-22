#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//题目链接：https://leetcode.cn/problems/letter-combinations-of-a-phone-number

//存储英文字母
string _digits[10] = { " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
void combination(string digits, string tempcombine, int num, vector<string>& combine)
{
    //当数字字符遍历完毕则递归结束
    if (num == digits.size())
    {
        //将加起来的字符放入combine
        combine.push_back(tempcombine);
        return;
    }
    //根据num下标来取出数字字符
    int n = digits[num] - '0';
    //取出数字字符所对应的字符串
    string letterstring = _digits[n];
    //遍历数字字符所对应的字符串
    for (auto e : letterstring)
    {
        //直接使用加号将字符录入tempcombine，注意更新num
        combination(digits, tempcombine + e, num + 1, combine);
    }
}

vector<string> letterCombinations(string digits) {
    //存储加起来的字符
    string tempcombine;
    //存储全部的组合结果
    vector<string> combine;
    //当主子字符串为空时，直接返回combine
    if (digits.empty())
    {
        return combine;
    }
    //num用于遍历所有字符数字
    int num = 0;
    //采用递归的方式解题
    combination(digits, tempcombine, num, combine);
    return combine;
}

int main()
{
    vector<string> s = letterCombinations("23");
    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;
	return 0;
}