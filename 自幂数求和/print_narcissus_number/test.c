#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

/*
	������
	���0��100000֮������С�ˮ�ɻ������������
	��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ�������
	��:153��1^3��5^3��3^3����153��һ����ˮ�ɻ�������
*/


size_t Judge(int num)
{
	//�ж��Ǽ�λ��
	int count = 1;
	//�����num��Ҫ�ı�
	while (num /= 10)
	{
		count++;
	}
	return count;
}

void Print_Nar(int num, size_t n)
{
	int sum = 0;
	int temp = num;
	//%10ȡ����ǰλ��/10��ȥ��ǰλ
	while (num)
	{
		sum += (int)pow(num % 10, n);
		num /= 10;
	}
	if (sum == temp)
	{
		printf("%d ", temp);
	}
}

int main()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		size_t n = Judge(i);
		Print_Nar(i, n);
	}
	return 0;
}