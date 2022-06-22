#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//递归方式打印一个数的每一位，例如：6253
/*
* 思路：剥离出每一位，可以看成
*		625+3
*		62+5+3
*		6+2+5+3
*/

void Print(unsigned int num)
{
	if (num > 9)
	{
		Print(num / 10);
	}
	printf("%d ", num % 10);
}
int main()
{
	unsigned int n = 0;
	scanf("%d", &n);
	Print(n);
	return 0;
}