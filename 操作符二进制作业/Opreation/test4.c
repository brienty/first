#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列

/*
* 思路：移动位数来打印
*	    移动位数不赋回本身，则其本身就未改变
*	   但是要注意移动了多少位即到了移动位数的下一位
*/
void Print(int n)
{
	int i = 0;
	//打印奇数位
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
	//打印偶数位
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	Print(num);
	return 0;
}