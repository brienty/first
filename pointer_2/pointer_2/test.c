#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("----------------------\n");
	printf("----1. Add 2. Sub-----\n");
	printf("--- 3. Mul 4. Div-----\n");
	printf("----0. exit      -----\n");
	printf("----------------------\n");
}

int main()
{
	//将写的程序是转移表
	int x = 0;
	int y = 0;
	int input = 0;
	int (*pfa[5]) (int, int) = { 0, Add, Sub, Mul, Div };
	//函数指针数组初始化，注意相应的括号不能省略，但是&可以省略
	do
	{
		printf("请选择要计算的方法\n");
		menu();
		scanf("%d", &input);
		if (input == 0)
		{
			printf("退出计算\n");
		}
		else if (input < 0 || input > 4)
		{
			printf("输入非法\n");
		}
		else
		{
			printf("请输入要计算的数字\n");
			scanf("%d %d", &x, &y);
			int result = pfa[input](x, y);
			//使用函数指针数组方式调用函数，需要注意(x, y)不能少，函数的本质
			printf("结果为\n");
			printf("%d\n", result);

		}
	} while (input);
	return 0;
}