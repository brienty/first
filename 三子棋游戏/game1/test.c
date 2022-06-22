#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void cls()
{
	printf("����������������Ժ��밴�س��������Ϸ\n");
	printf("��ȷ��һ��Ҫ��ס����\n");
	int i = 1;
	scanf("%d", &i);
	if (i == 1)
	{
		system("cls");
	}
}

void ruler()
{
	printf("            ��������Ϸ����\n");
	printf("1. ����Ϸ���е�������ں󰴻س�����Ч����\n");
	printf("\n");
	printf("���£�\n");
	printf("������뿪ʼ��Ϸ����Ӧ�������� 1 �Ժ�Ͱ��س���\n");
	printf("            1. play\n");
	printf("            0. exit\n");
	printf("\n");
	printf("2. *�����������\n");
	printf("   #�����������\n");
	printf("\n");
	printf("3. ����ѡ��������а��ո�\n");
	printf("\n");
	printf("���£�\n");
	printf("�������ѡ���һ�����꣬����Ӧ���������룺\n");
	printf("1 1\n");
	printf("ע������1���м����пո��Ŷ��\n");
	printf("\n");
	printf("\n");
	cls();
}

void menu()
{
	printf("��ѡ��\n");
	printf("1. play\n");
	printf("0. exit\n");
}

void game()
{
	char board[ROW][COL] = { 0 };
	//��ʼ������
	Initboard(board, ROW, COL);
	//��ӡ����
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
		printf("��ѡ���Ƿ�Ҫ������Ϸ��\n");
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