#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
实现一个函数，可以左旋字符串中的k个字符。
例如：
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB
*/


void Left1(char arr[], int sz, int k)
{
	int i = 0;
	for (i = 0; i < k; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1; j++)
		{
			//防止'\0'导致字符没了
			if (arr[j + 1] != '\0')
			{
				char temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void Left2(char* s, int sz, int k)
{
	int i = 0;
	for (i = 0; i < k; i++)
	{
		//旋转一次
		char temp = *s;
		int j = 0;
		for (j = 0; j < sz - 1; j++)
		{
			*(s + j) = *(s + j + 1);
		}
		*(s + sz - 1) = temp;
	}
}


void  reverse(char* left, char* right)
{
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}

//逆序函数
void Left3(char* s, int sz, int k)
{
	//防止越界，毕竟太大也是在进行重复操作
	k %= sz;

	reverse(s, s+k);
	reverse(s + k, s + sz - 1);
	reverse(s, s + sz - 1);
}

int main()
{
	char arr[] = "abcdefjhijk";
	int k = 0;
	scanf("%d", &k);
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	//第一种方法数组
	Left1(arr, sz, k);

	//第二种方法指针
	Left2(arr, sz, k);

	//第三种方法，分别旋转完后再总体旋转
	Left3(arr, sz, k);



	printf("%s\n", arr);
	return 0;
}