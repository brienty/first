#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

/*
	请问该程序的输出是多少？
	A 2
	B 死循环
	C 173
	D 172
*/
// 7, 4, 1, 254...2, 255... 6, 3, 0
// 1  2  3   1    85  1     84 85
//3+85+85=173
void test1()
{
	unsigned char i = 7;
	int j = 0;
	for (; i > 0; i -= 3)
	{
		++j;
	}
	printf("%d\n", j);
}



/*
【Fibonacci数列】Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i-1] + F[i-2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，
在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，每一步你可
以把当前数字X变为X-1或者X+1，现在给你1一个数N求最少需要多少步可以变为Fibonacci数。
输入描述：
输入为一个正整数N(1 ≤ N ≤ 1,000,000)
输出描述：
输出一个最小的步数变为Fibonacci数
示例1：
输入
15
输出
2
*/
void test2()
{
	int n = 0;
	int a = 0;
	int b = 1;
	int c = a + b;
	int r = scanf("%d", &n);
	while (1)//使用b比使用a更方便
	{
		//n等于b即返回0步
		if (n == b)
		{
			printf("%d\n", 0);
			break;
		}
		//n小于b，则判断与a近还是与b近
		else if(n < b)
		{
			//使用n与最近两个斐波那契数差的绝对值来作为所需步数
			if (abs(a - n) < abs(b - n))
			{
				printf("%d\n", abs(a - n));
				break;
			}
			else
			{
				printf("%d\n", abs(b - n));;
				break;
			}

		}
		//n大于b时，则遍历后面的斐波那契数
		a = b;
		b = c;
		c = a + b;
	}
}



/*
	请实现一个函数，将一个字符串中的每个空格替换成“%20”。
	例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy
*/
void test3(char* str, int length)
{
	//统计空格字符
	int count = 0;
	char* temp = str;
	while (*temp != '\0')
	{
		if (*temp == ' ')
		{
			count++;
		}
		temp++;
	}

	//使用指针循环条件不好控制
	int newlen = length + count * 2;
	int end1 = length - 1;
	int end2 = newlen - 1;

	//用%20替换空格正好end2追得上end1
	while (end1 != end2)
	{
		//遇到空格使用%20替换
		if (str[end1] == ' ')
		{
			str[end2--] = '0';
			str[end2--] = '2';
			str[end2--] = '%';
			end1--;
		}
		//否则继续往后推
		else
		{
			str[end2--] = str[end1--];
		}
	}
}




int main()
{
	test1();
	test2();
	
	char str[20] = "We Are Happy";                       
	test3(str, 13);
	printf("%s\n", str);
	return 0;
}
