#define _CRT_SECURE_NO_WARNINGS 1
//猜数字游戏
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void menu()
{
	printf("***********************************************************************************************************************\n");
	printf("**********************************************	   1.Play        ******************************************************\n");
	printf("**********************************************	   2.Exit        ******************************************************\n");
	printf("***********************************************************************************************************************\n");
}



void game()
{
here:
	printf("请输入你猜的数字:>\n(该数字应是1~100之间的数字)\n");
	int guess = 0;
	int r = rand() % 100 + 1;
	while (1)
	{
		scanf("%d", &guess);
		if (r > guess && guess >= 1)
		{
			printf("猜小了！请重新输入！\n");
		}
		else if (r < guess && guess <= 100)
		{
			printf("猜大了！请重新输入！\n");
		}
		else if (guess < 1 || guess > 100)
		{
			printf("请不要调皮！\n请重新输入！\n");
		}
		else
		{
			printf("                                                    猜对了！\n");
			printf("\n");
			printf("                                                 是否继续游戏？\n");
			printf("\n");
			printf("                                              (PS:请输入是或者否)\n");
			printf("\n");
			char arr[] = { 0 };
there:
			scanf("%s", arr);
			if (strcmp(arr, "是") == 0)
			{
				printf("                                                   游戏继续：\n");
				printf("\n");
				goto here;
			}
			else if (strcmp(arr, "否") == 0)
			{
				break;
			}
			else
			{
				printf("请不要调皮！\n请重新输入！\n");
				goto there;
			}
			
		}
		
		
	}
	
}



void choice(int input)
{
	    printf("游戏菜单：\n");
		menu();
		printf("请选择:\n");
		scanf("%d", &input);
		while (input != 1 && input != 2)
		{
			printf("输入错误，请重新输入！\n");
			printf("请选择:\n");
			scanf("%d", &input);
		}
		if (input == 1)
		{
			game();
		}
		input = 2;
		if (input == 2)
		{
			printf("                                                   游戏结束！\n");
			printf("\n");
		}
}



int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	printf("                                                   猜数字游戏\n");
	choice(input);
	return 0;
}