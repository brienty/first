#define _CRT_SECURE_NO_WARNINGS 1
//判断素数
//一个数无法被2~根号本身整除
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
	if (a <= 1)//素数 >= 1
	{
		printf("This is not prime number!");
	}
	else if (i < a)//在 2~sqrt(a) 中的数不是素数
	{
		printf("This is not prime number!\n");

	}
	else
	{
		printf("This is prime number!\n");
	}
	return 0;
}
//打印100~200的素数
/*#include <stdio.h>
#include <math.h>
int main()
{
	int i = 0;
	int j = 0;
	int count = 0;//统计个数
	for (i = 101; i <= 200; i+=2)//偶数一定不是素数
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