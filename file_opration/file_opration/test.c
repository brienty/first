#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	//д���ļ�
	FILE* pw = fopen("data.txt", "w");
	if (pw == NULL)
	{
		printf("%s\n", strerror(errno));
	}

	char arr[] = "abcdefg";
	fprintf(pw, "%s", arr);
	
	fclose(pw);
	pw = NULL;



	//��ȡ�ļ���ָ��λ�õ��ַ�
	FILE* pr = fopen("data.txt", "r");
	if (pr == NULL)
	{
		printf("%s\n", strerror(errno));
	}

	fseek(pr, 3, SEEK_CUR);
	int ch = fgetc(pr);
	printf("%c\n", ch);

	//�鿴�ļ�ָ���������ʼλ�õ�ƫ����
	long size = 0;
	size = ftell(pr);
	printf("%d\n", size);

	//ʹ�ļ�ָ���λ�ûص���ʼλ��
	rewind(pr);

	//�鿴�ļ�ָ���������ʼλ�õ�ƫ����
	size = ftell(pr);
	printf("%d\n", size);

	fclose(pr);
	pr = NULL;

	return 0;
}