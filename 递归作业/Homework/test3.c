#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//�ݹ鷽ʽ��ӡһ������ÿһλ�����磺6253
/*
* ˼·�������ÿһλ�����Կ���
*		625+3
*		62+5+3
*		6+2+5+3
*/

void Print(unsigned int num)
{
	if (num > 9)
	{
		Print(num / 10);
	}
	printf("%d ", num % 10);
}
int main()
{
	unsigned int n = 0;
	scanf("%d", &n);
	Print(n);
	return 0;
}