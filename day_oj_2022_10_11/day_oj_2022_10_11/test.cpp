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
    //��֤s2�
    if (s1.size() > s2.size())
        swap(s1, s2);
    int max = -1;
    //�����ַ���
    for (int i = 0; i < s2.size(); ++i)
    {
        for (int j = 0; j < s1.size(); ++j)
        {
            //��ֱ��ʹ��i��j����Ϊ�п����Ǵ��Ѿ�ͳ���˵�λ�ÿ�ʼ����ͳ�Ƶ���������
            int l = i, k = j, len = 0;
            //��������ȵ��ַ�����û��Խ�磬��ʼͳ��
            while (s2[l] == s1[k] && l < s2.size() && k < s1.size())
            {
                ++len;
                ++l;
                ++k;
            }
            //ֻ��len����max��������Ҫ��
            max = len > max ? len : max;
        }
    }
    cout << max << endl;
    return 0;
}