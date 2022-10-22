#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//�жϻ�������
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
    //�����ַ���
    string s;
    cin >> s;
    //���������ַ���
    string s2;
    cin >> s2;
    //ͳ�Ʒ�����
    int count = 0;
    //�����ַ���
    for (int i = 0; i < s.size() + 1; ++i)
    {
        //��s������s2����ÿ��λ�ò���ch�ж�
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