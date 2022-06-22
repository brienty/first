#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
//Prime(int input)
//{
//	int i = 0;
//	int k = sqrt(input);
//	for (i = 2; i <= k; i++)
//	{
//		if (input % k == 0)
//		{
//			return 0;
//		}
//	}
//
//}
int main()
{
	int input = 20;
	int* p = &input;
	int a = *p++;
	int b = *(p++);
	int c = (*p)++;
	//scanf("%d", &input);
	//Prime(input);
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	return 0;
}