#define _CRT_SECURE_NO_WARNINGS 1
//�ж�����
//1.�ܱ�4���������ܱ�100����
//2.�ܱ�400����
#include <stdio.h>
int main()
{
	int a = 0;
	scanf("%d", &a);
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
	{
		printf("It is leap year!");
	}
	else
	{
		printf("It is not leap year!");
	}
	return 0;
}