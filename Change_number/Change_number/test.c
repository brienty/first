#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

/*
	���ڵõ���һ���������ÿλ�������0��1��
	���ĳһλ���������Ͱ������1�������ż������ô�Ͱ������0��
	�������õ������Ƕ��١�
*/

int main()
{
	int input = 0;
	int i = 0;
	int sum = 0;
	scanf("%d", &input);
	while (input)
	{
		int temp = input % 10;
		if (temp % 2 == 1)
		{
			temp = 1;
			sum = sum + temp * pow(10, i++);
		}
		else
		{
			temp = 0;
			sum = sum + temp * pow(10, i++);
		}
		input /= 10;
	}
	printf("%d\n", sum);
	return 0;
}