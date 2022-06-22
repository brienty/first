#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，例如：1729
/*
*  思路：172+9	剥离出9+172的每一位
*		17+2+9	剥离出9+2+17的每一位
*		1+7+2+9	剥离出9+2+7+1
*/

int DigitSum(int n)
{
	//当n小于10不递归
	if (n <= 9)
	{
		return n;
	}
	else
	{
		return DigitSum(n / 10) + n % 10;
	}
}
int main()
{
	unsigned num = 0;
	scanf("%u", &num);
	int sum = DigitSum(num);
	printf("%u\n", sum);
	return 0;
}