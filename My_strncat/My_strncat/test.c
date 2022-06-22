#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

char* My_strncat(char* dest, const char* src, size_t num)
{
	assert(dest && src);//判空

	char* temp = dest;//需要返回目的地起始位置

	//找结束标志
	while (*dest != '\0')
	{
		dest++;
	}
	
	//开始追加
	while (num--)
	{
		*dest = *src;
		dest++;
		src++;
		if (*src == '\0')
		{
			*dest = *src;
			break;
		}
	}
	if (*dest != '\0')
	{
		*dest = '\0';
	}

	return temp;
}


int main()
{
	char arr1[30] = "abcdefg";
	char arr2[] = "qwer";

	//输入要追加的长度
	int num = 0;
	scanf("%d", &num);

	//模拟实现strncat函数
	printf("%s\n", My_strncat(arr1, arr2, num));

	return 0;
}