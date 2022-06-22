#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	int sum = m ^ (n + 1);
	int sub = n & (m + 1);
	printf("%d %d", sum, sub);
	return 0;
}