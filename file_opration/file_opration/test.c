#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	//写入文件
	FILE* pw = fopen("data.txt", "w");
	if (pw == NULL)
	{
		printf("%s\n", strerror(errno));
	}

	char arr[] = "abcdefg";
	fprintf(pw, "%s", arr);
	
	fclose(pw);
	pw = NULL;



	//读取文件中指定位置的字符
	FILE* pr = fopen("data.txt", "r");
	if (pr == NULL)
	{
		printf("%s\n", strerror(errno));
	}

	fseek(pr, 3, SEEK_CUR);
	int ch = fgetc(pr);
	printf("%c\n", ch);

	//查看文件指针相对于起始位置的偏移量
	long size = 0;
	size = ftell(pr);
	printf("%d\n", size);

	//使文件指针的位置回到初始位置
	rewind(pr);

	//查看文件指着相对于起始位置的偏移量
	size = ftell(pr);
	printf("%d\n", size);

	fclose(pr);
	pr = NULL;

	return 0;
}