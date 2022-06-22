#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//不允许创建临时变量，交换两个整数的内容,例如：3和5
/*
* 核心思想是：当相同的异或时，为0；0异或别的整数时为别的整数
*/
 
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	b = a ^ b;
	a = a ^ b;
	b = a ^ b;
	printf("%d %d\n", a, b);
	return 0;
}