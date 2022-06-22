//多个字符从两端移动，向中间汇聚
//因为要改变字符，所以考虑使用数组下标来访问字符
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char arr[] = "hello bit!!!!!!!!";
	//字符串中包含隐藏的\0
	//[a b c \0]
	 //0 1 2  3
	char arr1[] = "hello bit!!!!!!!!";
	char arr2[] = "#################";
	int left = 0;
	int right = strlen(arr1) - 1;//需引用头文件
	//如果要使用sizeof()运算符则此处应该为sizeof(arr)-2，因为sizeof()计算隐藏的\0而strlen()函数不计算
	while (left <= right)
	{
		arr2[left] = arr1[left];//arr1赋值给arr2
		arr2[right] = arr1[right];//同理
		printf("%s\n", arr2);
		Sleep(1000);//睡眠函数-单位是毫秒，休息指定时间再打印，注意S为大写，需引用头文件
		system("cls");//该函数用来执行系统命令，需引用头文件，cls为清屏命令
		left++;
		right--;
	}
	printf("%s\n", arr2);//显示最后的结果

	return 0;
}