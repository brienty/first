#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//strlen��ģ�⣨�ݹ�ʵ�֣������磺abcd
/*
* ˼·�����Կ���
*		1+��bcd�ĳ���
*		1+1��cd�ĳ���
*		1+1+1��d�ĳ���
*		1+1+1+1�ĳ���
*/

int My_strlen(char* s)
{
	if (*s != '\0')
	{
		return 1 + My_strlen(s + 1);
	}
	else
	{
		return 0;
	}
}
int main()
{
	//��������ʼ���ַ�������
	char arr[] = "abc";
	//���ַ�������
	int len = My_strlen(arr);
	printf("%d\n", len);
	return 0;
}