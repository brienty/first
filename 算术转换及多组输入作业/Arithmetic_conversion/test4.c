#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//�Ӽ�����������һ������������ж�������ż��
//�������룬ÿ���������һ������
//���ÿ�����룬���������������Odd������ż����Even��

int main()
{
    int num = 0;
    //scanf��ȡʧ��ʱ�᷵��EOF���������볣�ø÷������
    while (scanf("%d", &num) != EOF)
    {
        if (num % 2 == 1)
        {
            printf("Odd\n");
        }
        else
        {
            printf("Even\n");
        }
    }
    return 0;
}