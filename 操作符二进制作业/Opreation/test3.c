#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
//输入例子:1999 2299
//输出例子 : 7
//PS：与test2的题目有关，先解决test2的题目再来

/*
* 思路：按照按位与1以后值看是否相等
*/
int Count_diff_num1(int n, int m)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		//注意优先级
		if ((n & 1) != (m & 1))
		{
			count++;
		}
		n >>= 1;
		m >>= 1;
	}
	return count;
}

/*
* 思路：利用好异或操作符，相同为0，相异为1
*		将两个值异或的值存起来
*		再继续进行对 1 检测即可
*/
int Count_diff_num2(int n, int m)
{
	int count = 0;
	int temp = n ^ m;
	while (temp)
	{
		//注意优先级
		temp = temp & (temp - 1);
		count++;
	}
	return count;
}
int main()
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	int num3 = Count_diff_num1(num1, num2);
	int num4 = Count_diff_num2(num1, num2);
	printf("%d %d\n", num3, num4);
	return 0;
}