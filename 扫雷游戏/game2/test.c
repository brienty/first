#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf(" ��Ϸ�˵�\n");
	printf("1. play\n");
	printf("2. exit\n");
}

void ruler()
{
	printf("\n");
	printf("           ɨ����Ϸ����\n");
	printf("\n");
	printf("����Ϸ���Լ���������Ҫ���׵�����\n");
	printf("����������ϸ�������Ҫ��\n");
	printf("1. �����м�ӿո�\n");
	printf("   ���磺�������׵�������ǵ����е�����\n");
	printf("   Ӧ������5 5���м��пո�\n");
	printf("   �������ٰ��»س�����\n");
	printf("2. ������ǵð��»س�������Ч����\n");
	printf("\n");
	printf("���������,�밴�س���ʼ��Ϸ\n");
	char i = 0;
	scanf("%c", &i);
	system("cls");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//����׵���Ϣ
	char show[ROWS][COLS] = { 0 };//����Ų���׵���Ϣ

	//��ʼ������
	Initboard(mine, ROWS, COLS, '0');//��ʼ��mine����
	Initboard(show, ROWS, COLS, '*');//��ʼ��show����

	//�����׵���Ϣ
	Setmine(mine, ROW, COL);
	
	//��ӡ����
	Displayboard(show, ROW, COL);
	//Displayboard(mine, ROW, COL);

	//����
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
		printf("   �Ƿ������Ϸ��\n");
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
