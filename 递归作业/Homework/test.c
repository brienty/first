#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//编写一个函数 reverse_string(char * string)（递归实现），例如：abcdefg
/*
* 思路：先把a和g交换加上bcdef，以此类推
*/

//求字符串长度
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
//指针求字符串倒叙
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
//递归求字符串倒叙
void reverse_string2(char* s)
{
	char temp = *s;
	int len = My_strlen(s);
	*s = *(s + len - 1);
 //加'\0'是为了My_strlen函数计算长度
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