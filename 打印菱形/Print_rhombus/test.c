#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
	��C��������Ļ�����һ������
*/

//˼·�����Է�Ϊ�����������ִ�ӡ���Լ��ո��*�Ĵ�ӡ��Ȼ����ǹ���ģ��

int main()
{
	int line = 0;
	scanf("%d", &line);

	int i = 0;
	
	//�ϲ��ִ�ӡ
	for (i = 0; i < line; i++)
	{
		int j = 0;
		
		//��ӡ�ո�
		for (j = 0; j < line - 1 -i; j++)
		{
			printf(" ");
		}

		//��ӡ*
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//�°벿�ִ�ӡ
	for (i = 0; i < line - 1; i++)
	{
		int j = 0;

		//��ӡ�ո�
		for (j = 0; j < i+1; j++)
		{
			printf(" ");
		}

		//��ӡ*
		for (j = 0; j < (line-1-i)*2-1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}