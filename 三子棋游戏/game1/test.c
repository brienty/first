#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void cls()
{
	printf("如果上述规则明白以后请按回车后进入游戏\n");
	printf("（确保一定要记住规则）\n");
	int i = 1;
	scanf("%d", &i);
	if (i == 1)
	{
		system("cls");
	}
}

void ruler()
{
	printf("            三子棋游戏规则\n");
	printf("1. 本游戏所有的输入均在后按回车才起效果！\n");
	printf("\n");
	printf("如下：\n");
	printf("如果我想开始游戏，我应该输入完 1 以后就按回车键\n");
	printf("            1. play\n");
	printf("            0. exit\n");
	printf("\n");
	printf("2. *代表玩家坐标\n");
	printf("   #代表电脑坐标\n");
	printf("\n");
	printf("3. 请在选择的坐标中按空格！\n");
	printf("\n");
	printf("如下：\n");
	printf("如果我想选择第一个坐标，那我应该这样输入：\n");
	printf("1 1\n");
	printf("注意两个1的中间是有空格的哦！\n");
	printf("\n");
	printf("\n");
	cls();
}

void menu()
{
	printf("请选择：\n");
	printf("1. play\n");
	printf("0. exit\n");
}

void game()
{
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	Initboard(board, ROW, COL);
	//打印棋盘
	Displayboard(board, ROW, COL);

	char temp = 0;

	while (1)
	{
		Player_move(board, ROW, COL);
		Displayboard(board, ROW, COL);
		system("cls");
		temp = is_win(board, ROW, COL);
		if (temp != 'c')
		{
			break;
		}
		computer_move(board, ROW, COL);
		Displayboard(board, ROW, COL);
		temp = is_win(board, ROW, COL);
		if (temp != 'c')
		{
			break;
		}
	}
	if (temp == '*')
	{
		printf("You are win!\n");
		Sleep(4000);
		system("cls");
	}
	else if (temp == '#')
	{
		Sleep(500);
		system("cls");
		printf("You are lost!\n");
		Sleep(5000);
		system("cls");
	}
	else
	{
		Sleep(500);
		system("cls");
		printf("A dead heat!\n");
		Sleep(5000);
		system("cls");
	}
}

void test()
{
	int input = 0;
	int n = 0;
	ruler();
	menu();
	scanf("%d", &input);
	system("cls");
	switch (input)
	{
	case 1:
there:	game();
		printf("请选择是否要继续游戏？\n");
		printf("1. Yes   2. NO\n");
		scanf("%d", &n);
		system("cls");
		if (n == 2)
		{
			goto here;
		}
		else
		{
			goto there;
		}
		break;
	case 0:
here:	printf("game over!\n");
		break;
	default:
		printf("Please input again\n");
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}