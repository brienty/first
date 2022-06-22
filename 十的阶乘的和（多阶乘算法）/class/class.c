#define _CRT_SECURE_NO_WARNINGS 1
 //10的阶乘的和第一种低效做法
/*#include <stdio.h>
int main()
{
	int i = 0;
	int j = 1;
	int a = 0;
	int sum = 0;
	for (a = 1; a <= 10; a++)
	{
		j = 1;//j如果不初始化为1则j会把上次一次循环完毕的结果作为下一次的初始化值
		for (i = 1; i <= a; i++)
		{
			j = j * i;
		}
		sum = sum + j;
	}
	printf("%d", sum);
	return 0;
}*/
 //10的阶乘的和第二种更高效的做法
#include <stdio.h>
int main()
{
	int i = 0;
	int j = 1;
	int sum = 0;
	for (i = 1; i <= 10; i++)
	{
		j = j * i;
		sum += j;
	}
	printf("%d", sum);
	return 0;
}