#define _CRT_SECURE_NO_WARNINGS 1
//��������Ϸ
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
	printf("��������µ�����:>\n(������Ӧ��1~100֮�������)\n");
	int guess = 0;
	int r = rand() % 100 + 1;
	while (1)
	{
		scanf("%d", &guess);
		if (r > guess && guess >= 1)
		{
			printf("��С�ˣ����������룡\n");
		}
		else if (r < guess && guess <= 100)
		{
			printf("�´��ˣ����������룡\n");
		}
		else if (guess < 1 || guess > 100)
		{
			printf("�벻Ҫ��Ƥ��\n���������룡\n");
		}
		else
		{
			printf("                                                    �¶��ˣ�\n");
			printf("\n");
			printf("                                                 �Ƿ������Ϸ��\n");
			printf("\n");
			printf("                                              (PS:�������ǻ��߷�)\n");
			printf("\n");
			char arr[] = { 0 };
there:
			scanf("%s", arr);
			if (strcmp(arr, "��") == 0)
			{
				printf("                                                   ��Ϸ������\n");
				printf("\n");
				goto here;
			}
			else if (strcmp(arr, "��") == 0)
			{
				break;
			}
			else
			{
				printf("�벻Ҫ��Ƥ��\n���������룡\n");
				goto there;
			}
			
		}
		
		
	}
	
}



void choice(int input)
{
	    printf("��Ϸ�˵���\n");
		menu();
		printf("��ѡ��:\n");
		scanf("%d", &input);
		while (input != 1 && input != 2)
		{
			printf("����������������룡\n");
			printf("��ѡ��:\n");
			scanf("%d", &input);
		}
		if (input == 1)
		{
			game();
		}
		input = 2;
		if (input == 2)
		{
			printf("                                                   ��Ϸ������\n");
			printf("\n");
		}
}



int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	printf("                                                   ��������Ϸ\n");
	choice(input);
	return 0;
}