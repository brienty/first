#define _CRT_SECURE_NO_WARNINGS 1
//关机程序
#include <stdio.h>
int main()
{
	char input[] = { 0 };
	system("shutdown -s -t 60");
again:
	printf("Please enter ：我是猪！to stop the windows!\n");
	scanf("%s", &input);
	if (strcmp(input, "我是猪！") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}