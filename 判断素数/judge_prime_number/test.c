#define _CRT_SECURE_NO_WARNINGS 1
//�ж�����
//һ�����޷���2~���ű�������
#include <stdio.h>
#include <math.h>
int main()
{
	int a = 0;
	int i = 0;
	scanf("%d", &a);
	for (i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
		{
			break;
		}
	}
	if (a <= 1)//���� >= 1
	{
		printf("This is not prime number!");
	}
	else if (i < a)//�� 2~sqrt(a) �е�����������
	{
		printf("This is not prime number!\n");

	}
	else
	{
		printf("This is prime number!\n");
	}
	return 0;
}
//��ӡ100~200������
/*#include <stdio.h>
#include <math.h>
int main()
{
	int i = 0;
	int j = 0;
	int count = 0;//ͳ�Ƹ���
	for (i = 101; i <= 200; i+=2)//ż��һ����������
	{
		int z = 0;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				z = 1;
				break;
			}
		}
		if (z == 0)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}*/