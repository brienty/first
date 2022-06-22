#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>

/*
	模拟实现atoi，将字符串里的数字字符转换成整数
	1. 判断空指针
	2. 空字符串直接返回0
	3. 当整个字符串前出现空白字符则跳过
	   当整个字符串中出现空白字符则不再遍历
	   直接返回空白字符之前组成的数字，没有数字返回0
	4. 当整个字符串最前面有正负号时（不包含空字符），需要返回正负数 
	5. 非数字字符如果在数字前且在非数字前无数字则返回0
	   如果非数字字符在数字后，则返回遍历到该非数字之前的数字组合
	6. 当数字大于整形时，直接返回整形的最大值
*/

int My_atoi(const char* s)
{
	//判断空指针
	assert(s);

	//空字符串处理
	if (*s == '\0')
	{
		return 0;
	}

	//空白字符处理
	while (isspace(*s))
	{
		s++;
	}

	//正负号处理,处理完遍历下一个
	int flag = 1;
	if (*s == '+')
	{
		flag = 1;
		s++;
	}
	if(*s == '-')
	{
		flag = -1;
		s++;
	}

	long long n = 0;//必须定义更长类型，不然无法判断整形越界问题
	//isdigit判断数字，并且返回对应的值，如果不是数字则返回0
	while (isdigit(*s))
	{
		//组合数字并加上正负号
		n = n * 10 + flag * (*s - '0');
		
		//判断越界问题
		if (n >= INT_MAX)
		{
			return INT_MAX;
		}
		if (n <= INT_MIN)
		{
			return INT_MIN;
		}
		s++;
	}
	
	//数字判断完，剩下的不管，直接返回
	return (int)n;


}


int main()
{
	int z = My_atoi("    -123dad1");
	printf("%d\n", z);
	return 0;
}