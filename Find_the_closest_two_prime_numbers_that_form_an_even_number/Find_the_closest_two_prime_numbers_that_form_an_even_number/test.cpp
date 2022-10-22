#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//�ж���������������������Բ���Ҫ�ж�2���µ���
bool isprime(int num)
{
    int s = sqrt(num);
    for (int i = 2; i <= s; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    //p1�洢��С���Ǹ�������p2�洢�ϴ���Ǹ�����
    int num = 0, p1 = 0, p2 = 0;
    cin >> num;
    //i��ż����һ������жϼ���
    for (int i = 2; i <= num / 2; ++i)
    {
        //d�洢��������ϴ���Ǹ���
        int d = num - i;
        //��һ�γ�ʼ��
        if (i == 2)
        {
            p1 = i;
            p2 = d;
        }
        //ֻ������������������d-i�Ĳ�Ҫ��p2-p1��ҪС��������Ҫ�ҵ���������
        if (isprime(i) && isprime(d) && ((d - i) < (p2 - p1)))
        {
            p1 = i;
            p2 = d;
        }
    }
    cout << p1 << endl << p2 << endl;
    return 0;
}