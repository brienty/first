#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//真正操作对象
#define ROW 9
#define COL 9

//用这个来防止越界问题
#define ROWS ROW+2
#define COLS COL+2

#define MINE_MAX 10

//初始化雷的信息
void Initboard(char arr[ROWS][COLS], int rows, int cols, char set);

//打印棋盘
void Displayboard(char arr[ROWS][COLS], int row, int col);

//布置雷的信息
void Setmine(char mine[ROWS][COLS], int row, int col);

//排雷
void  Finemine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);