#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

/*
дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
���磺����s1 = AABCD��s2 = BCDAA������1
����s1=abcd��s2=ACBD������0.
AABCD����һ���ַ��õ�ABCDA
AABCD���������ַ��õ�BCDAA
AABCD����һ���ַ��õ�DAABC
*/


void reverse(char* s, int n)
{
	//��õ�һ���ַ�
	char* temp = *s;

	//���㳤��
	int len = strlen(s);

	int i = 0;

	//��ת����
	for (i = 0; i < n; i++)
	{
		int j = 0;
		
		//��תһ��
		for (j = 0; j < len - 1; j++)
		{
			*(s + j) = *(s + 1 + j);
		}

		//�����ַ������һ��λ��
		*(s + 1 + i) = temp;
	}
}

int left_move1(char* s1, char* s2)
{
	int len = strlen(s1);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		//��ת�ַ�
		reverse(s1, 1);

		//���Ƚ�
		if (strcmp(s1, s2) == 0)
		{
			return 1;
		}
	}
	return 0;
}



int left_move2(char* s1, char* s2)
{
	//�������ַ������ȣ����Ȳ�ͬ�ز�ͬ
	int len = 0;
	len = strlen(s1);
	int len2 = 0;
	len2 = strlen(s2);
	if (len2 < len)
	{
		return 0;
	}

	//���Լ�׷�Ӹ��Լ�����ʱ���ַ���������������/�������Ӵ�
	strncat(s1, s1, len);

	//�ж�s2�Ƿ���s1���Ӵ�������֪���Ƿ���ͬһ���ַ���
	if (strstr(s1, s2))
	{
		return 1;
	}
	return 0;
}


int main()
{
	//��ֹ׷���Ժ�ռ䲻����
	char arr1[30] = "abcdef";

	char arr2[10] = "abcdef";

	//�ַ����û�����һ
	//int n = left_move1(arr1, arr2);

	//�ַ����û�������
	int n = left_move2(arr1, arr2);

	if (n == 1)
	{
		printf("arr1 == arr2\n");
	}
	else
	{
		printf("arr1 != arr2\n");
	}
	
	
	return 0;
}