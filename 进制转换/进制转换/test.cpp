#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    string s;
    //����ʮ������
    int in = 0;
    cin >> in;
    //����ת���Ľ���
    int base = 0;
    cin >> base;
    //�Ȳ�ȥ��ע����
    int div = abs(in);
    //��ȡ�ַ�
    char n = 0;
    //����ת��
    while (div > 0)
    {
        //�洢����
        int remainder = div % base;
        //�������ھ�����ĸ��ʾ
        if (remainder > 9)
        {
            n = remainder - 10 + 'A';
        }
        //����С�ھ������ֱ�ʾ
        else
        {
            n = remainder + '0';
        }
        //���ַ�ͷ���s��
        s.insert(0, 1, n);
        //��ȥ��ת���Ĳ���
        div /= base;
    }
    //in����0ֱ�ӷ���0
    if (in == 0)
    {
        cout << 0;
    }
    else
    {
        //��inС��0ʱͷ��һ�����ţ������
        if (in < 0)
        {
            s.insert(0, 1, '-');
            cout << s;
        }
        //����ֱ�����
        else
        {
            cout << s;
        }
    }
    return 0;
}