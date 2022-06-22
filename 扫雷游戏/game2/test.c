#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf(" 游戏菜单\n");
	printf("1. play\n");
	printf("2. exit\n");
}

void ruler()
{
	printf("\n");
	printf("           扫雷游戏规则\n");
	printf("\n");
	printf("该游戏是以键盘输入想要排雷的坐标\n");
	printf("坐标的输入严格按照以下要求：\n");
	printf("1. 坐标中间加空格！\n");
	printf("   例如：你想排雷的坐标的是第五行第五列\n");
	printf("   应该输入5 5（中间有空格）\n");
	printf("   输入完再按下回车即可\n");
	printf("2. 输入完记得按下回车键才起效果！\n");
	printf("\n");
	printf("如果明白了,请按回车开始游戏\n");
	char i = 0;
	scanf("%c", &i);
	system("cls");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//存放雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查好雷的信息

	//初始化函数
	Initboard(mine, ROWS, COLS, '0');//初始化mine数组
	Initboard(show, ROWS, COLS, '*');//初始化show数组

	//布置雷的信息
	Setmine(mine, ROW, COL);
	
	//打印棋盘
	Displayboard(show, ROW, COL);
	//Displayboard(mine, ROW, COL);

	//排雷
	Finemine(mine, show, ROW, COL);
}


void test()
{
	int input = 0;
	int i = 0;
	ruler();
	menu();
	scanf("%d", &input);
here:
	system("cls");
	switch (input)
	{
	case 1:
		game();
		printf("   是否继续游戏？\n");
		printf("1. continue    2. exit \n");
		int i = 0;
		scanf("%d", &i);
		system("cls");
		if (i == 1)
		{
			goto here;
		}
		else
		{
			goto there;
		}
		break;
	case 2:
	there:
		printf("game over!\n");
		break;
	default:
		printf("please input again!\n");
		break;
	}
}


int main()
{	
	srand((unsigned int)time(NULL));
	test();
	return 0;
}
