#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("----------------------\n");
	printf("----1. Add 2. Sub-----\n");
	printf("--- 3. Mul 4. Div-----\n");
	printf("----0. exit      -----\n");
	printf("----------------------\n");
}

int main()
{
	//��д�ĳ�����ת�Ʊ�
	int x = 0;
	int y = 0;
	int input = 0;
	int (*pfa[5]) (int, int) = { 0, Add, Sub, Mul, Div };
	//����ָ�������ʼ����ע����Ӧ�����Ų���ʡ�ԣ�����&����ʡ��
	do
	{
		printf("��ѡ��Ҫ����ķ���\n");
		menu();
		scanf("%d", &input);
		if (input == 0)
		{
			printf("�˳�����\n");
		}
		else if (input < 0 || input > 4)
		{
			printf("����Ƿ�\n");
		}
		else
		{
			printf("������Ҫ���������\n");
			scanf("%d %d", &x, &y);
			int result = pfa[input](x, y);
			//ʹ�ú���ָ�����鷽ʽ���ú�������Ҫע��(x, y)�����٣������ı���
			printf("���Ϊ\n");
			printf("%d\n", result);

		}
	} while (input);
	return 0;
}