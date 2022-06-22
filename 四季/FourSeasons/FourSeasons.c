#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int month;
	printf("ÇëÊäÈëÔÂ·İ£º");
	scanf("%d", &month);
	switch (month)
	{
	case 1:
		printf("¶¬¼¾");
		break;
	case 2:
		printf("¶¬¼¾");
		break;
	case 3:
		printf("´º¼¾");
		break;
	case 4:
		printf("´º¼¾");
		break;
	case 5:
		printf("´º¼¾");
		break;
	case 6:
		printf("ÏÄ¼¾");
		break;
	case 7:
		printf("ÏÄ¼¾");
		break;
	case 8:
		printf("ÏÄ¼¾");
		break;
	case 9:
		printf("Çï¼¾");
		break;
	case 10:
		printf("Çï¼¾");
		break;
	case 11:
		printf("Çï¼¾");
		break;
	case 12:
		printf("¶¬¼¾");
		break;
	default :
		printf("ÄãÊäÈëµÄÔÂ·İÓĞÎó£¬ÇëÖØĞÂÊäÈë£¡");
		break;
	}
	return 0;
}
