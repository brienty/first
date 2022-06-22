#define _CRT_SECURE_NO_WARNINGS 1
//求最大公约数直接法
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	//输入两个数
	scanf("%d %d", &a, &b);
	//计算两个数的最大公约数
	//1.假设最小的那个数为最大公约数
	if (a > b)
	{
		c = b;
	}
	else
	{
		c = a;
	}
	//2.最小的那个数不是公约数的情况
	while (1)
	{
		if (a % c == 0 && b % c == 0)
		{
			break;
		}
		c--;
	}
	printf("%d", c);
	return 0;
}
//辗转相除法（高效）
//两个数相除取数继续除
/*#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int c = 0;
	while (c = a % b)
	{
		a = b;
		b = c;
		c = a % b;
	}
	printf("%d", b);
	return 0;
}*/