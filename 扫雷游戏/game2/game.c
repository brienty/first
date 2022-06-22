#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void Initboard(char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{ 
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

void Displayboard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		int j = 0;
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

void Setmine(char mine[ROWS][COLS], int row, int col)
{
	int count = MINE_MAX;

	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//Ϊ�˲��������ط��õ��������
 static int Get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] - 8 * '0';
}

void  Finemine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - MINE_MAX)
	{
		printf("����������Ҫ���׵����꣺\n");
		printf("������������ֱ�ʾ��Χ�˸������м����ף�\n");
        scanf("%d %d", &x, &y);
		system("cls");
		printf("\n");
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("You are die!\n");
				Sleep(3000);
				system("cls");
				printf("\n");
				printf("�׵ķֲ����£�");
				printf("(0����ȫ��λ�ã�1�����׵�λ��)\n");
				Displayboard(mine, ROW, COL);
				Sleep(3000);
				break;
			}
			else
			{
				//���㸽���ж��ٸ���
				int n = Get_mine_count(mine, x, y);
				show[x][y] = n + '0';
				Displayboard(show, row, row);
				win++;
			}
		}
		else
		{
			printf("Plese input again!\n");
			printf("\n");
			Displayboard(show, row, row);
		}
	}
	if (win == row * col - MINE_MAX)
	{
		Sleep(2000);
		system("cls");
		printf("You are win!\n");
		Sleep(2000);
		system("cls");
	}
}