#define _CRT_SECURE_NO_WARNINGS 1
//��С������
//ֱ�ӷ�
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int z = 0;
	if (a > b)
	{
		z = a;
	}
	else
	{
		z = b;
	}
	while (1)
	{
		if (z % a == 0 && z % b == 0)//z��a��z��b���ܽ���,������ѭ��
		{
			break;
		}
		z++;
	}
	printf("%d", z);
	return 0;
}
//շת���������󹫱�������Ч��
/*#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int c = 0;
	int min = a * b; //���������
	while (c = a % b)
	{
		a = b;
		b = c;
		c = a % b;
	}
	printf("%d", min / b); //��󹫱���������������˳����������
	return 0;
}*/