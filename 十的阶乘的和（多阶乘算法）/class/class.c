#define _CRT_SECURE_NO_WARNINGS 1
 //10�Ľ׳˵ĺ͵�һ�ֵ�Ч����
/*#include <stdio.h>
int main()
{
	int i = 0;
	int j = 1;
	int a = 0;
	int sum = 0;
	for (a = 1; a <= 10; a++)
	{
		j = 1;//j�������ʼ��Ϊ1��j����ϴ�һ��ѭ����ϵĽ����Ϊ��һ�εĳ�ʼ��ֵ
		for (i = 1; i <= a; i++)
		{
			j = j * i;
		}
		sum = sum + j;
	}
	printf("%d", sum);
	return 0;
}*/
 //10�Ľ׳˵ĺ͵ڶ��ָ���Ч������
#include <stdio.h>
int main()
{
	int i = 0;
	int j = 1;
	int sum = 0;
	for (i = 1; i <= 10; i++)
	{
		j = j * i;
		sum += j;
	}
	printf("%d", sum);
	return 0;
}