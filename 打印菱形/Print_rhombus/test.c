#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
	用C语言在屏幕上输出一个菱形
*/

//思路：可以分为上下两个部分打印，以及空格和*的打印，然后就是构建模型

int main()
{
	int line = 0;
	scanf("%d", &line);

	int i = 0;
	
	//上部分打印
	for (i = 0; i < line; i++)
	{
		int j = 0;
		
		//打印空格
		for (j = 0; j < line - 1 -i; j++)
		{
			printf(" ");
		}

		//打印*
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//下半部分打印
	for (i = 0; i < line - 1; i++)
	{
		int j = 0;

		//打印空格
		for (j = 0; j < i+1; j++)
		{
			printf(" ");
		}

		//打印*
		for (j = 0; j < (line-1-i)*2-1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}