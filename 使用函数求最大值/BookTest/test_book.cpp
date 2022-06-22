#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 使用三目操作符构造最大值函数
int MAX(int x , int y)
{
	int z =((x > y) ? x : y);
	return z;
}
int main()
{
	
	int a;
	int b;
	int c;
	scanf("%d %d", &a, &b);
	c = MAX(a, b);
	printf("%d", c);

	return 0;
}
//使用if...else构造最大值函数
//int MAX(int x, int y)
//{	
//	if (x > y)
//	{
//		printf("%d", x);
//	}
//	else
//	{
//		printf("%d", y);
//	}
//	return 0;
//}
//int main()
//{
//	int a, b, c;
//	scanf("%d %d", &a, &b);
//	c = MAX(a, b);
//	return 0;
//}









