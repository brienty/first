#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// ʹ����Ŀ�������������ֵ����
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
//ʹ��if...else�������ֵ����
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









