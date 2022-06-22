#define _CRT_SECURE_NO_WARNINGS 1
//最小公倍数
//直接法
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int z = 0;
	if (a > b)
	{
		z = a;
	}
	else
	{
		z = b;
	}
	while (1)
	{
		if (z % a == 0 && z % b == 0)//z与a，z与b不能交换,否则死循环
		{
			break;
		}
		z++;
	}
	printf("%d", z);
	return 0;
}
//辗转相除法求最大公倍数（高效）
/*#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int c = 0;
	int min = a * b; //两个数相乘
	while (c = a % b)
	{
		a = b;
		b = c;
		c = a % b;
	}
	printf("%d", min / b); //最大公倍数等于两个数相乘除以最大公因数
	return 0;
}*/