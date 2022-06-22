#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
	求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字
	例如：2+22+222+2222+22222
*/

int main()
{
	int a = 0;
	int j = 0;
	scanf("%d %d", &a, &j);
	int sum = 0;
	int i = 0;
	int Sn = 0;
	for (i = 0; i < j; i++)
	{
		sum = sum + a;
		a *= 10;
		Sn += sum;
	}
	printf("%d\n", Sn);
	return 0;
}