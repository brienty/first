#pragma once

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define ROW 3
#define COL 3

//初始化棋盘
void Initboard(char board[ROW][COL], int row, int col);

//打印棋盘
void Displayboard(char board[ROW][COL], int row, int col);

//玩家移动
void Player_move(char board[ROW][COL], int row, int col);

//电脑移动
void computer_move(char board[ROW][COL], int row, int col);

//判断胜利
char is_win(char board[ROW][COL], int row, int col);



//'*'代表玩家
//'#'代表电脑
//'c'代表继续
//'q'代表停止