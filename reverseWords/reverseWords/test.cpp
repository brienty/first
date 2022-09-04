#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

string reverseWords(string s) {
    size_t n = 0;
    int begin = 0;
    int end = 0;
    while ((n = s.find(' ', n)) != string::npos)
    {
        end = n;
        while (begin <= end - 1)
        {
            char temp = s[begin];
            s[begin] = s[end - 1];
            s[end - 1] = temp;
            ++begin;
            --end;
        }
        ++n;
        begin = n;
    }
    //处理只有一个单词和最后一个
    if (n == string::npos)
    {
        end = s.size() - 1;
        while (begin <= end)
        {
            char temp = s[begin];
            s[begin] = s[end];
            s[end] = temp;
            ++begin;
            --end;
        }
    }
    return s;
}

int main()
{
    string s("Let's take LeetCode contest");
    cout << reverseWords(s);
	return 0;
}