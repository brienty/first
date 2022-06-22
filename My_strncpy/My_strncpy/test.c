#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

char* My_strncpy(char* dest, const char* src, size_t num)
{
	char* temp = dest;

	assert(dest && src);//日常判空环节

	//如果目的地字符串是空字符串直接返回
	if (*dest == '\0')
	{
		return temp;
	}
	
	//复制
	while (num--)
	{
		*dest = *src;
		dest++;
		src++;

		//当src到'\0'说明长度小于等于num
		if (*src == '\0')
		{
			break;
		}
	}

	//当被复制字符串长度小于num时，用'\0'顶替剩下的数量
	if (*src == '\0')
	{
		while (num--)
		{
			*dest = '\0';
		}
	}

	return temp;

}

int main()
{
	char arr1[30] = "abcdefg";
	char arr2[] = "123456789";

	//输入要复制的个数
	int num = 0;
	scanf("%d", &num);

	//模拟实现strncpy
	printf("%s\n", My_strncpy(arr1, arr2, num));

	return 0;
}