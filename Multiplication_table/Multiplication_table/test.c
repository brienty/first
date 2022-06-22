#define _CRT_SECURE_NO_WARNINGS 1
void Mul(int input)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= input; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d\t", j, i, j*i);
		}
		printf("\n");
	}
}
#include <stdio.h>
int main()
{
	int input = 0;
	scanf("%d", &input);
	Mul(input);
	return 0;
}