#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int month;
	printf("�������·ݣ�");
	scanf("%d", &month);
	switch (month)
	{
	case 1:
		printf("����");
		break;
	case 2:
		printf("����");
		break;
	case 3:
		printf("����");
		break;
	case 4:
		printf("����");
		break;
	case 5:
		printf("����");
		break;
	case 6:
		printf("�ļ�");
		break;
	case 7:
		printf("�ļ�");
		break;
	case 8:
		printf("�ļ�");
		break;
	case 9:
		printf("�＾");
		break;
	case 10:
		printf("�＾");
		break;
	case 11:
		printf("�＾");
		break;
	case 12:
		printf("����");
		break;
	default :
		printf("��������·��������������룡");
		break;
	}
	return 0;
}
