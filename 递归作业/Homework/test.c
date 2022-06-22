#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//��дһ������ reverse_string(char * string)���ݹ�ʵ�֣������磺abcdefg
/*
* ˼·���Ȱ�a��g��������bcdef���Դ�����
*/

//���ַ�������
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
//ָ�����ַ�������
void reverse_string(char* s)
{
	char* end = s + My_strlen(s) - 1;
	char* begin = s;
	while (begin < end)
	{
		char temp = *begin;
		*begin = *end;
		*end = temp;
		begin++;
		end--;
	}
}
//�ݹ����ַ�������
void reverse_string2(char* s)
{
	char temp = *s;
	int len = My_strlen(s);
	*s = *(s + len - 1);
 //��'\0'��Ϊ��My_strlen�������㳤��
	*(s + len - 1) = '\0';
	if (My_strlen(s + 1) > 1)
	{
		reverse_string(s + 1);
	}
	*(s + len - 1) = temp;
}
int main()
{
	char arr[] = "abcdefg";
	reverse_string(arr);
	reverse_string2(arr);
	printf("%s\n", arr);
	return 0;
}