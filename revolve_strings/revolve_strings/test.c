#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

/*
写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 = AABCD和s2 = BCDAA，返回1
给定s1=abcd和s2=ACBD，返回0.
AABCD左旋一个字符得到ABCDA
AABCD左旋两个字符得到BCDAA
AABCD右旋一个字符得到DAABC
*/


void reverse(char* s, int n)
{
	//存好第一个字符
	char* temp = *s;

	//计算长度
	int len = strlen(s);

	int i = 0;

	//旋转次数
	for (i = 0; i < n; i++)
	{
		int j = 0;
		
		//旋转一次
		for (j = 0; j < len - 1; j++)
		{
			*(s + j) = *(s + 1 + j);
		}

		//将首字符给最后一个位置
		*(s + 1 + i) = temp;
	}
}

int left_move1(char* s1, char* s2)
{
	int len = strlen(s1);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		//旋转字符
		reverse(s1, 1);

		//作比较
		if (strcmp(s1, s2) == 0)
		{
			return 1;
		}
	}
	return 0;
}



int left_move2(char* s1, char* s2)
{
	//求两个字符串长度，长度不同必不同
	int len = 0;
	len = strlen(s1);
	int len2 = 0;
	len2 = strlen(s2);
	if (len2 < len)
	{
		return 0;
	}

	//把自己追加给自己，此时的字符串必有所有左旋/右旋的子串
	strncat(s1, s1, len);

	//判断s2是否是s1的子串，即可知道是否是同一个字符串
	if (strstr(s1, s2))
	{
		return 1;
	}
	return 0;
}


int main()
{
	//防止追加以后空间不够大
	char arr1[30] = "abcdef";

	char arr2[10] = "abcdef";

	//字符串置换方法一
	//int n = left_move1(arr1, arr2);

	//字符串置换方法二
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