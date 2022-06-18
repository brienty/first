#define _CRT_SECURE_NO_WARNINGS 1

#include "student_inf.h"

void menu()
{
	printf("请选择登录身份：>\n");

	printf("0. 退出\n");
	printf("1. 管理员\n");
	printf("2. 教师\n");
	printf("3. 学生\n");
}


int main()
{
	menu();
	int input = 1;
	Sy s;
	InitSystem(&s);
	while (input)
	{
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 0:
			printf("退出成功！\n");
			break;
		case 1:System(&s);
			goto here;
			break;
		case 2:Teacher(&s);
			goto here;
			break;
		case 3:Student(&s);
			printf("查询完毕，退出成功！\n");
			goto here;
			break;
		default:
			printf("非法输入，请重新输入！\n");
			break;
		}
	}
here:
	return 0;
}