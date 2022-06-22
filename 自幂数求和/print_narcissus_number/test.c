#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

/*
	自幂数
	求出0～100000之间的所有“水仙花数”并输出。
	“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身。
	如:153＝1^3＋5^3＋3^3，则153是一个“水仙花数”。
*/


size_t Judge(int num)
{
	//判断是几位数
	int count = 1;
	//这里的num需要改变
	while (num /= 10)
	{
		count++;
	}
	return count;
}

void Print_Nar(int num, size_t n)
{
	int sum = 0;
	int temp = num;
	//%10取出当前位，/10除去当前位
	while (num)
	{
		sum += (int)pow(num % 10, n);
		num /= 10;
	}
	if (sum == temp)
	{
		printf("%d ", temp);
	}
}

int main()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		size_t n = Judge(i);
		Print_Nar(i, n);
	}
	return 0;
}