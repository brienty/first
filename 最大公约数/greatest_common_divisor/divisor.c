#define _CRT_SECURE_NO_WARNINGS 1
//�����Լ��ֱ�ӷ�
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	//����������
	scanf("%d %d", &a, &b);
	//���������������Լ��
	//1.������С���Ǹ���Ϊ���Լ��
	if (a > b)
	{
		c = b;
	}
	else
	{
		c = a;
	}
	//2.��С���Ǹ������ǹ�Լ�������
	while (1)
	{
		if (a % c == 0 && b % c == 0)
		{
			break;
		}
		c--;
	}
	printf("%d", c);
	return 0;
}
//շת���������Ч��
//���������ȡ��������
/*#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int c = 0;
	while (c = a % b)
	{
		a = b;
		b = c;
		c = a % b;
	}
	printf("%d", b);
	return 0;
}*/