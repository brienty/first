#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int begin = 0, end = s.size() - 1;
    while (begin < end)
    {
        char tmp = s[begin];
        s[begin] = s[end];
        s[end] = tmp;
        ++begin;
        --end;
    }
    cout << s << endl;
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    //保证s2最长
    if (s1.size() > s2.size())
        swap(s1, s2);
    int max = -1;
    //遍历字符串
    for (int i = 0; i < s2.size(); ++i)
    {
        for (int j = 0; j < s1.size(); ++j)
        {
            //不直接使用i，j是因为有可能是从已经统计了的位置开始往后统计的数是最大的
            int l = i, k = j, len = 0;
            //当遇到相等的字符并且没有越界，开始统计
            while (s2[l] == s1[k] && l < s2.size() && k < s1.size())
            {
                ++len;
                ++l;
                ++k;
            }
            //只有len大于max才是我们要的
            max = len > max ? len : max;
        }
    }
    cout << max << endl;
    return 0;
}