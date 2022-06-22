#define _CRT_SECURE_NO_WARNINGS 1
//判断闰年
//1.能被4整除但不能被100整除
//2.能被400整除
#include <stdio.h>
int main()
{
	int a = 0;
	scanf("%d", &a);
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
	{
		printf("It is leap year!");
	}
	else
	{
		printf("It is not leap year!");
	}
	return 0;
}