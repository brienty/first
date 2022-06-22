#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

/*
	现在得到了一个数，想把每位的数变成0或1。
	如果某一位是奇数，就把它变成1，如果是偶数，那么就把它变成0。
	请问最后得到的数是多少。
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