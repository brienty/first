#pragma once

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define ROW 3
#define COL 3

//��ʼ������
void Initboard(char board[ROW][COL], int row, int col);

//��ӡ����
void Displayboard(char board[ROW][COL], int row, int col);

//����ƶ�
void Player_move(char board[ROW][COL], int row, int col);

//�����ƶ�
void computer_move(char board[ROW][COL], int row, int col);

//�ж�ʤ��
char is_win(char board[ROW][COL], int row, int col);



//'*'�������
//'#'�������
//'c'�������
//'q'����ֹͣ