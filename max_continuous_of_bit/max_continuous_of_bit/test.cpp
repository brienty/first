#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    cin >> num;
    int count = 0;//�洢���1�ĸ��� 
    int tmp = 0;//�洢1�ĸ���
    for (int i = 0; i < 32; ++i)
    {
        //��1��++tmp
        if ((num & (1 << i)) != 0)
            ++tmp;
        //�����0
        else
            tmp = 0;
        //���tmp��count��˵��tmp��1����
        if (tmp > count)
            count = tmp;
    }
    cout << count;
    return 0;
}