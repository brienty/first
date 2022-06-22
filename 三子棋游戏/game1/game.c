#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void Initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void Displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void Player_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家请输入要占用的坐标:\n");
	printf("(*代表玩家坐标)\n");
	printf("(#代表电脑坐标)\n");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && y >= 1 && x <= row && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已被占用，请重新输入！\n");
				printf(">:\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\n");
			printf(">:\n");
			
		}
	}
}

void computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("棋盘占用情况：\n");
	while (1)
	{
		// 应该放到棋盘里，不然怎么更新坐标！
		x = rand() % row;//保证输入在棋盘的横向内
		y = rand() % col;//保证输入在棋盘的纵向内
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}

}

int Deuce(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < col; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;//通过返回真假值来判断平局
	
}

char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;

	//判断一行相等
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == '*' && board[i][1] == '*' && board[i][2] == '*' && board[i][1] != ' ')
		{
			return '*';
		}
		if (board[i][0] == '#' && board[i][1] == '#' && board[i][2] == '#' && board[i][1] != ' ')
		{
			return '#';
		}
	}

	//判断一列相等
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}

	//判断斜线上的相等
	if (board[0][0] == board[1][1] && board[1][1]== board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1]== board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}

	//平局，棋已占满棋盘
	if (Deuce(board, ROW, COL))
	{
		return 'q';
	}
	return 'c';
}
