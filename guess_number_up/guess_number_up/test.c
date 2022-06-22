#define _CRT_SECURE_NO_WARNINGS 1
/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
void menu()
{
	printf("---------------------------------\n");
	printf("---          1. Play       ------\n");
	printf("---          2. Exit       ------\n");
	printf("---------------------------------\n");
}
void down()
{
	system("shutdown -s -t 3600");
}
void choice2()
{
	char arr[7] = { 0 };
	printf("Please enter Ibeat to go to next game!\n");
	scanf("%s", arr);
	while (1)
	{
		if (strcmp(arr, "Ibeat") == 0)
		{
			system("shutdown -a");
			break;
		}
		else

		{
			printf("Please enter the key world!\n");
			printf("请不要尝试通过关闭游戏来阻止程序运行，即使游戏已停止程序仍然会继续运行！\n");
			scanf("%s", arr);
		}
	}
	printf("Please play the game finally!\n");
}
void game()
{
	int r = rand() % 100 + 1;
	printf("Please enter the number of 1~100! \n");
	int guess = 0;
	scanf("%d", &guess);
	int i = 0;
	int j = 0;
	printf("你将有七次猜的机会>");
	for (i = 1; i < 7; i++)
	{
		if (guess > r)
		{
			printf("Your number is larger than computer's number!\n");
			scanf("%d", &guess);
			j = 1;
		}
		else if (guess < r)
		{
			printf("Your number is smaller than computer's number!\n");
			scanf("%d", &guess);
			j = 1;
		}
		else
		{
			j = 2;
			if (j == 2)
			{
				system("shutdown -a");
			}
			printf("Your are right!\ngame over!\n");
			break;
		}
	}
	if (j == 1)
	{
		down();
		choice2();
		Sleep(3000);
		down();
		game();
	}
}
void choice()
{
	printf("Please enter the number that you will guess!\n");
	int input = 0;
	scanf("%d", &input);
	while (input != 1 && input != 2)
	{
		printf("Eorro! Please enter again!\n");
		scanf("%d", &input);
	}
	if (input == 1)
	{
		game();
	}
	if (input == 2)
	{
		printf("Exit guess number game!\n");
	}
}

int main()
{
	menu();
	srand((unsigned int)time(NULL));
	choice();
	return 0;
}*/