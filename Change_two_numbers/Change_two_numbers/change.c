#define _CRT_SECURE_NO_WARNINGS 1
//change_two_numbers
Change(int * a, int * b)
{
	int z = 0;
	z = *a;
	*a = *b;
	*b = z;
}
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("befor change:a=%d b=%d\n", a, b);
	Change(&a,&b);
	printf("after cahnge:a=%d b=%d\n", a, b);
	return 0;
}