#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//����������ʱ������������������������,���磺3��5
/*
* ����˼���ǣ�����ͬ�����ʱ��Ϊ0��0���������ʱΪ�������
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