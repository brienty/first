#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

/*
����ˮ�ɻ��� - Lily Number������������֣����м��ֳ���������
����1461 ���Բ�ֳɣ�1��461��,��14��61��,��146��1)
������в�ֺ�ĳ˻�֮�͵�������������һ��Lily Number��
���磺
655 = 6 * 55 + 65 * 5
1461 = 1*461 + 14*61 + 146*1
��� 5λ���е����� Lily Number��
����������
��
���������
һ�У�5λ���е����� Lily Number��ÿ������֮����һ���ո�
*/

int main()
{
    int i = 0;
    int j = 0;
    for (i = 10000; i < 99999; i++)
    {
        int sum = 0;
        for (j = 10; j <= 10000; j = 10 * j)
        {
            sum += (i / j) * (i % j);
        }
        if (sum == i)
            printf("%d ", i);
    }
    return 0;
}