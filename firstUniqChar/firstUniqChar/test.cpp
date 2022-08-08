#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

int firstUniqChar(string s) {
    //记录每个元素出现的次数
    int arr[26] = { 0 };
    for (int i = 0; i < s.size(); ++i)
    {
        ++arr[s[i] - 'a'];
    }

    //从原字符串开始遍历，当遇到字符在数组中存的值为1时即返回下标
    for (int i = 0; i < s.size(); ++i)
    {
        if (arr[s[i] - 'a'] == 1)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    string s("loveleetcode");
    cout << firstUniqChar(s);
    return 0;
}