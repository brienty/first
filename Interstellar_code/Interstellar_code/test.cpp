#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 10010;//10000������
int f[N] = { 1, 1, 2 };//���㷢����쳲���������

int main()
{
    //��ǰһ���쳲��������д���������ֻȡ������λ
    for (int i = 3; i < N; ++i)
    {
        f[i] = (f[i - 1] + f[i - 2]) % 10000;
    }
    //���벢�ж�
    int n = 0;
    while (cin >> n)
    {
        int x = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            //��%04d����������������Ȳ�����4λ��������0b���
            printf("%04d", f[x]);
        }
        cout << endl;
    }
    return 0;
}