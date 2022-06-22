#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//编写一个函数实现n的k次方，使用递归实现，例如：3的3次方，4的-2次方
/*
* 思路：num * num 的 n-1 次方
*/

double Mul(int num, int n)
{
	if (n > 0)
	{
		//注意别写成num*num，不然每次递归num都在变化
		return Mul(num, n - 1) * num;
	}
	else if (n < 0)
	{
		//用-n代替n转正数，1.0除以整体即负数
		//不可1.0/num的原因是Mul的参数都为int型
		return 1.0 / (Mul(num, -n) * num);
	}
	else
	{
		//当n=0时需要返回1，例如：1*3*3*3
		return 1;
	}
}
int main()
{
	int n = 0;
	int num = 0;
	scanf("%d %d", &n, &num);
	double sum = Mul(num, n);
	printf("%lf\n", sum);
	return 0;
}