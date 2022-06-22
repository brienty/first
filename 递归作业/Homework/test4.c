#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//strlen的模拟（递归实现），例如：abcd
/*
* 思路：可以看成
*		1+求bcd的长度
*		1+1求cd的长度
*		1+1+1求d的长度
*		1+1+1+1的长度
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
	//创建并初始化字符串数组
	char arr[] = "abc";
	//求字符串长度
	int len = My_strlen(arr);
	printf("%d\n", len);
	return 0;
}