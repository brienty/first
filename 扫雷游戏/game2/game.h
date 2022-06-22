#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//������������
#define ROW 9
#define COL 9

//���������ֹԽ������
#define ROWS ROW+2
#define COLS COL+2

#define MINE_MAX 10

//��ʼ���׵���Ϣ
void Initboard(char arr[ROWS][COLS], int rows, int cols, char set);

//��ӡ����
void Displayboard(char arr[ROWS][COLS], int row, int col);

//�����׵���Ϣ
void Setmine(char mine[ROWS][COLS], int row, int col);

//����
void  Finemine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);