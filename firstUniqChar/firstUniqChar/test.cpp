#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

int firstUniqChar(string s) {
    //��¼ÿ��Ԫ�س��ֵĴ���
    int arr[26] = { 0 };
    for (int i = 0; i < s.size(); ++i)
    {
        ++arr[s[i] - 'a'];
    }

    //��ԭ�ַ�����ʼ�������������ַ��������д��ֵΪ1ʱ�������±�
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