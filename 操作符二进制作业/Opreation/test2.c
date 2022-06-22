#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//写一个函数返回参数在内存里补码二进制中 1 的个数,比如：15 00001111  4 个 1



/*
* 思路：用数字中的二进制位一个一个 & 1，将三十二个二进制位一个一个判断
* 再使用 >> 将已经判断了的二进制位给去除掉
*/
int Count_num1(int n)
{
	int count = 0;
	int i = 0;
	//右移虽然高位补1，但是只移动了32次！
	for (i = 0; i < 32; i++)
	{
		//==的优先级高于&
		if ((n & 1) == 1)
		{
			count++;
			//num2 >> 1 未改变num2，需要重新赋值
			n = n >> 1;
		}
		else
		{
			n = n >> 1;
		}
	}
	return count;
}

/*
* 思路：类似于十进制中 n % 10 取最后一位， n / 10 除去最后一位
*		n % 2 == 1 拿到最后一个二进制位，n / 2 即除去最后一个二进制位
*/
//注意要加unsigned，防止 -1 这种负数
//加上unsigned内存中的 -1 仍然是32个1
int Count_num2(unsigned int n)
{
	int count = 0;
	while (n)
	{
		if (n % 2 == 1)
		{
			count++;
		}
		n /= 2;
	}
	return count;
}

/*
* 思路：当 n & (n - 1) 时，n的二进制位的最右边一位 1 被去除
*	   优于以上算法，有几个 1 循环几次
* PS： 也可以用于判断2的k次方
*/
int Count_num3(int n)
{
	int count = 0;
	//n最后会等于0
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
}

int main()
{
	int num1 = 0;
	scanf("%d", &num1);
	int num2 = Count_num1(num1);
	int num3 = Count_num2(num1);
	int num4 = Count_num3(num1);
	printf("%d %d %d\n", num2, num3, num4);
	return 0;
}