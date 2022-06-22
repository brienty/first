#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
以下为4个嫌疑犯的供词:
A说：不是我。
B说：是C。
C说：是D。
D说：C在胡说
已知3个人说了真话，1个人说的是假话。
现在请根据这些信息，写一个程序来确定到底谁是凶手。
*/

int main()
{
	int killer = 0;
	//利用字符的ASCII码值来控制循环
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		//把三个人的话翻译成代码，当有一个人是假，三个人是真的时候三个值就是3，即此时的字母就是killer！
		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
		{
			printf("凶手是：%c\n", killer);
			break;
		}
	}
	return 0;
}