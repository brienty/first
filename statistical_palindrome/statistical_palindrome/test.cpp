#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//判断回文序列
bool ispalindrome(const string& s)
{
    int begin = 0;
    int end = s.size() - 1;
    while (begin < end)
    {
        if (s[begin] == s[end])
        {
            ++begin;
            --end;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    //读入字符串
    string s;
    cin >> s;
    //读入插入的字符串
    string s2;
    cin >> s2;
    //统计方法数
    int count = 0;
    //遍历字符串
    for (int i = 0; i < s.size() + 1; ++i)
    {
        //将s拷贝给s2并在每个位置插入ch判断
        string s3 = s;
        s3.insert(i, s2);
        if (ispalindrome(s3))
        {
            ++count;
        }
    }
    cout << count;
    return 0;
}