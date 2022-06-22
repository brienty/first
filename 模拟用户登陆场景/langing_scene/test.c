#define _CRT_SECURE_NO_WARNINGS 1
//strcmp -> string compare
//返回0，说明两给字符串相等
//返回大于零的数字，前面的字符串大于后面的字符串
//返回小于零的数字，前面的字符串小于后面的字符串
/*比较大小的方式是两个字符串自左向右逐个字符相比
（按照ASCII值大小相比较），直到出现不同的字符或遇'\0'为止*/
#include <stdio.h>
#include <string.h>
int main()
{
	int i = 0;
	//假设密码为“123456”
	char passworld[10] = "";
	//必须写字符个数，否则""里只有 \0 ，且只有一个字符个数，后续输入字符串会导致数组越级
	for (i = 0; i < 3; i++)
	{
		printf("Please enter passworld:");
		scanf("%s", passworld);
		//passworld是数组名，数组本来就是地址，不要取地址
		if (strcmp(passworld, "123456") == 0)
		//字符串比较不能使用==，strcmp是比较两个字符串是否相等的函数，需要引用头文件
		{
			printf("passworld is correct!\nLogin successful!\n");
			break;
		}
		else
		{
			printf("passworld is fault!\n");
		}
	}
	if (i == 3)
	//当 i 等于3时，已经没有机会再次输入
	{
		printf("Maximum number of inputs!\nQuit the program!\n");
	}
	return 0;
}