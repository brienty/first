#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//use_recursion
/*long long Mul(int input)
{
	if (input <= 1)
	{
		return 1;
	}
	return input * Mul(input - 1);
}
int main()
{
	int input = 0;
	scanf("%d", &input);
	long long z = Mul(input);
	printf("%lld\n", z);
	return 0;
}*/



//use_circulation
long long Cir(int input)
{
	int i = 0;
	long long z = 1;
	if (input <= 1)
	{
		return 1;
	}
		for (i = 1; i <= input; i++)
		{
			z *= i;
		}
	return z;
}
int main()
{
	int input = 0;
	scanf("%d", &input);
	long long z = Cir(input);
	printf("%lld\n", z);
	return 0;
}
